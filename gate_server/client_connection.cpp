/*
 * client_connection.cpp
 *
 *  Created on: 2012-4-1
 *      Author: lixingyi
 */

#include "client_connection.h"
#include "message.h"
#include "gate_application.h"
#include "gate_fsm.h"
#include "gate_application.h"
#include "common_util.h"
#include "../public/str_util.h"
#include "../public/md5.h"

using namespace std;

ClientConnection::ClientConnection()
	: m_seq_counter(0), m_uid(0), m_role_id(0)
	, m_server_id(0)
	, m_status(STATUS_DEFAULT)
	, m_last_time(0)
	, m_last_ip("")
	,m_client_seq(0)
{
    m_idle_timer.set_owner(this);

}

ClientConnection::~ClientConnection()
{
    // TODO Auto-generated destructor stub
}


void ClientConnection::on_event(int type)
{

    debug_log_format(get_app().logger,"close client ip:%s fd:%d uid:%d role_id:%d type:%d",
        m_last_ip.c_str(),get_id().fd,m_uid,m_role_id,type);

    if(m_uid > 0)
    {
		get_app().set_user_connection(m_uid,m_server_id, 0) ;
		if( m_role_id > 0)
		{

			ss_player_logout_notify logout ;
			logout.key = m_role_id ;
			logout.body.set_guid(m_role_id) ;
			get_app().zone_conn.send(&logout,0) ;
			info_log_format(get_app().logger,"logout role_id:%d\n",m_role_id) ;

			//send_login_log(false);
            get_app().set_role_connection(m_role_id,0) ;
		}

		m_uid = 0 ;
		m_role_id = 0 ;
		m_status = STATUS_DEFAULT ;

    }

    get_app().timer_engine.del_timer(&m_idle_timer);

    fini() ;
    get_app().free_connection(this) ;
}
int ClientConnection::get_packet_info(const char* data,int size,packet_info* pi)
{

    if(size < (int)sizeof(cs_head) )
    {
        pi->size = (int)sizeof(cs_head) ;
    }
    else
    {
        cs_head* head = (cs_head*)data ;
        pi->type = ntoh_int16(head->msgid) ;
        pi->size = ntoh_int16(head->length) ;
        pi->data = data ;
    }

    if(pi->size < (int)sizeof(cs_head) || pi->size > 8192 ) return -4 ;

    return 0 ;
}

//void ClientConnection::send_login_log(bool online)
//{
//	char buff[1024] = {0};
//
//	ss_send_log_notify  notify;
//	notify.key = notify.seq = 0;
//	notify.body.set_seq(get_next_seq());
//	notify.body.set_log_src_type(SRC_GATE_SERVER);
//
//	int64_t now = kingnet::time_ms() ;
//	notify.body.set_time_stamp(now);
//
//	LogPlayerData*  lplayer = notify.body.mutable_player_info();
//	char uid[20] = {0};
//	sprintf(uid, "%d", m_uid);
//	lplayer->set_ouid(uid);
//
//	if (m_role_id > 0)
//	{
//		lplayer->set_iuid(m_role_id);
//		lplayer->set_role_id(m_role_id);
//	}
//	else
//	{
//		lplayer->set_iuid(0);
//		lplayer->set_role_id(0);
//	}
//
//	lplayer->set_client_ip(m_last_ip);
//
//	if (online)
//	{
//		notify.body.set_action_type(LOG_ACTION_LOGON);
//		sprintf(buff, "player %d login from %s on GateServer at time %ld", m_uid, m_last_ip.c_str(), now);
//		m_last_time = now;
//	}
//	else
//	{
//		notify.body.set_action_type(LOG_ACTION_LOGOFF);
//		int32_t  online_time = (int32_t)(now - m_last_time) / 1000 ;
//		sprintf(buff, "player %d offline from %s on GateServer at time %ld, total online time %d seconds", m_uid, m_last_ip.c_str(), now, online_time);
//	}
//
//	notify.body.set_log_data( string(buff, strlen(buff)) );
//
//	get_app().log_conn.send(&notify, 0);
//}

int ClientConnection::process_packet(const packet_info* pi)
{
    
    if(get_app().check_threshold && (!check_threshold(pi->type)) )
    {
        debug_log_format(get_app().logger,"threshold limit uid:%d role_id:%d action:%d",
            m_uid,m_role_id,pi->type >>2) ;
        return 0 ;
    }

    if(get_app().check_seq && 
        (!check_seq(ntoh_int32(((cs_head_plus*)(pi->data))->seq))) ) return -1 ;
    if(get_app().check_heartbeat && 
        (!check_heart(ntoh_int16(((cs_head_plus*)(pi->data))->reserved))) ) return -2 ;

    switch(pi->type)
    {
    // 随机名字请求 在进入游戏之前 可以发  pi->type == 768
    case cs_acc_login_request::packet_type:
        if(m_status == STATUS_DEFAULT) return process_acc_login(pi) ;
        break ;
    case cs_player_login_request::packet_type:
        if(m_status == STATUS_PLAYER_LOGIN) return process_player_login(pi) ;
        break ;
    case cs_create_player_request::packet_type:
        if(m_status == STATUS_PLAYER_LOGIN) return process_create_player(pi) ;
        break ;
    case ss_random_name_request::packet_type:
        if(m_status == STATUS_PLAYER_LOGIN) return process_random_name(pi);//get_app().forward_cs_packet_to_name(pi,m_uid) ;
        break;
	case ss_find_player_request::packet_type:
		if(m_status == STATUS_IN_GAME) return process_find_player(pi);
        break;
    case cs_heartbeat_request::packet_type:
        return process_heartbeat(pi) ;
        break ;
    case cs_init_connection_request::packet_type:
        return process_init_connection(pi) ;
        break ;
    case ss_server_status_request::packet_type:
        return process_server_status(pi) ;
    default:
        if(m_status == STATUS_IN_GAME)
            return process_game_packet(pi) ;
    }

    return -3 ;
}


void ClientConnection::on_idle_timeout(timer_manager* manager)
{
    if(m_status <= STATUS_ACC_LOGIN)
    {
        warn_log_format(get_app().logger,"close idle connection uid:%d role_id:%d",m_uid,m_role_id);
        on_event(0);
    }
    else
    {
        if(time(0) - m_heart_time > 180 )
        {
            warn_log_format(get_app().logger,"close idle connection uid:%d role_id:%d",m_uid,m_role_id);
            on_event(0);
        }
        else
        {

            m_idle_timer.set_expired(get_app().get_run_ms() + 60000 ) ;
            if(get_app().timer_engine.add_timer(&m_idle_timer)!=0) return ;
        }
    }

}

void ClientConnection::on_connect()
{
    m_client_seq = 0 ;
    m_cur_heart = m_last_heart = 0 ;
    m_heart_time = time(0) ;
    m_status = STATUS_DEFAULT ;

    for(int i = 0 ; i < MAX_ACTION_SIZE ; ++i)
    {
        m_threshold[i].init(1,50) ;
    }

    m_idle_timer.set_expired(get_app().get_run_ms() + 20000 ) ;
    if(get_app().timer_engine.add_timer(&m_idle_timer)!=0) return ;

}

void ClientConnection::on_player_login()
{
    m_status = STATUS_IN_GAME ;

}

void ClientConnection::on_acc_login(int role_id)
{
    m_role_id = role_id ;
    m_status = STATUS_PLAYER_LOGIN;
}

int ClientConnection::process_acc_login(const packet_info* pi)
{
    cs_acc_login_request request ;
    if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;
	int uid = request.body.uid() ;
    if(uid <= 0 )
	{
        error_log_format(get_app().logger, "acc login request uid %d invalid, close fd", uid);
        return -1 ;
    }

	debug_log_format(get_app().logger,"login uid:%d fd:%d\n",request.body.uid(),get_id().fd) ;

	if (get_app().check_token)
	{
		char buff[64];
		snprintf(buff, sizeof(buff), "%d", uid);
		std::string id_str(buff);
		std::string pre_md5_str = get_app().key1 + id_str;

		std::string md5_str	= md5(pre_md5_str);

		std::string base64_str;
		CBase64::Encode((const unsigned char*)md5_str.c_str(), md5_str.size(), base64_str);

        //printf("%s\n%s\n%s\n", pre_md5_str.c_str(), base64_str.c_str(), request.body.token().c_str());
		if (base64_str != request.body.token())
		{
			return -1;
			error_log_format(get_app().logger, "token check failed. close connection of %d", uid);
		}

		// 验证通过

	}

	int server_id = request.body.server_id();
	if (!get_app().is_server_id_valid(server_id))
	{
		return -1;
	}

    ClientConnection* oconn = get_app().get_user_connection(uid, server_id) ;
    if(oconn)
    {
        info_log_format(get_app().logger,"already login, kick old , uid:%d sid:%d",uid, server_id);
        cs_notify_error_notify notify ;
        notify.body.set_error_code(EC_DISCONNECT_BY_ANOTHER_LOGIN);
        oconn->send(&notify, 0);
        oconn->on_event(0);

    }

    //init
    m_uid = uid ;

	m_server_id = server_id;
	m_status = STATUS_ACC_LOGIN;

    get_app().forward_cs_packet_to_name(pi,m_uid) ;
    //send_login_log(true);
    get_app().set_user_connection(uid, m_server_id, this) ;

    return 0 ;
}

int ClientConnection::process_create_player(const packet_info* pi)
{
	cs_create_player_request request;
	if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;
	request.body.set_server_id(m_server_id);

	ss_create_player_request ss_req;
	ss_req.body.CopyFrom(request.body);
	ss_req.key = m_uid;
    ss_req.seq = request.seq;
	ss_req.tick = kingnet::time_ms();

	ss_req.body.set_login_ip(m_last_ip);

	return get_app().name_conn().send(&ss_req,0) ;
}


int ClientConnection::process_random_name( const packet_info* pi )
{
	cs_random_name_request request;
	if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;
	request.body.set_server_id(m_server_id);

	ss_random_name_request ss_req;
	ss_req.body.CopyFrom(request.body);
	ss_req.key = m_uid;
    ss_req.seq = request.seq;
	ss_req.tick = kingnet::time_ms();
	return get_app().name_conn().send(&ss_req,0) ;
}


int ClientConnection::process_heartbeat(const packet_info* pi)
{
    cs_heartbeat_request request ;
    if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;

    int64_t server_ms = kingnet::time_ms() ;
    cs_heartbeat_response response ;
    response.seq = request.seq ;
    response.body.set_value(request.body.value()) ;
	response.body.set_server_time(server_ms);
    send(&response,0) ;

    m_last_heart = m_cur_heart ;
    m_cur_heart = (server_ms/1000) & 0xffff ;
    m_heart_time = time(0) ;

    return 0 ;

}
int ClientConnection::process_find_player(const packet_info* pi)
{
	return get_app().forward_cs_packet_to_name(pi,get_role_id()) ;
}

int ClientConnection::process_player_login(const packet_info* pi)
{
    cs_player_login_request request ;
    if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;
    int role_id = PLAYER_ROLE_ID(request.body.guid()) ;
    if(m_role_id == 0 || role_id != m_role_id ) return -1 ;
    info_log_format(get_app().logger,"player_login uid:%d role_id:%d\n",m_uid,role_id) ;

    get_app().set_role_connection(m_role_id,this);

	request.body.set_login_ip(m_last_ip);
	debug_log_format(get_app().logger, "player from %s login", m_last_ip.c_str());

	ss_player_login_request  ss_request;
	ss_request.key = m_role_id;
	ss_request.seq = ntoh_int32(((cs_head_plus*)(pi->data))->seq) ;
	uint32_t begin_tick = kingnet::time_ms() & 0xffffffff ;
	ss_request.tick = (begin_tick);

	ss_request.body.CopyFrom(request.body);

	return get_app().zone_conn.send(&ss_request, 0);
    //return get_app().forward_cs_packet(pi,m_role_id) ;

}

int ClientConnection::process_game_packet(const packet_info* pi)
{
    return get_app().forward_cs_packet(pi,m_role_id) ;

}

int ClientConnection::forward_packet(const packet_info* pi,int32_t key)
{
    ss_head head = {0};
    head.key = hton_int32(key) ;
    head.seq = ((cs_head_plus*)(pi->data))->seq ;
    head.msgid = hton_int16(pi->type) ;
    head.length = hton_int16(pi->size - cs_head_size(pi->type) + sizeof(head) ) ;
	head.tick = kingnet::time_ms();
    get_app().zone_conn.send((const char*)&head,sizeof(head),0) ;
    get_app().zone_conn.send(pi->data + cs_head_size(pi->type),pi->size - cs_head_size(pi->type),0) ;

    return 0 ;


}

int ClientConnection::process_init_connection(const packet_info* pi)
{
    cs_init_connection_request request ;
    if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;

    int begin_seq = (rand() % 10000 ) + 1000 ;
    int64_t server_ms = kingnet::time_ms() ;

    cs_init_connection_response response ;
    response.seq = request.seq ;
    response.body.set_error_code(0) ;
    response.body.set_begin_seq(begin_seq) ;
	response.body.set_server_time(server_ms);
    send(&response,0) ;

    m_client_seq = begin_seq ; 

    m_last_heart = m_cur_heart = (server_ms/1000) & 0xffff ;
    m_heart_time = time(0) ;

    return 0 ;

}

int ClientConnection::process_server_status(const packet_info* pi)
{
    cs_server_status_request request ;
    if(request.decode(pi->data,pi->size)!=pi->size) return -1 ;
    ss_server_status_request ss_request ;
    ss_request.key = get_id().fd ;
    ss_request.seq = get_id().timestamp ;
    ss_request.tick = kingnet::time_ms() & 0x0fffffff ;
    ss_request.body = request.body ;
    get_app().zone_conn.send(&ss_request,0) ;
    //debug_log_format(get_app().logger,"begin_server_status:%ld",kingnet::time_ms()) ;

    return 0 ;

}



bool ClientConnection::check_seq(int seq)
{
    if(m_client_seq >= seq)
    {
        warn_log_format(get_app().logger,"invalid seq role_id:%d seq:%d",m_role_id,seq) ;
        return false ;
    }

    m_client_seq = seq ;
    return true ;
}


bool ClientConnection::check_heart(int value)
{
    if(value == m_cur_heart || value == m_last_heart) return true ;
    warn_log_format(get_app().logger,"invalid heart code uid:%d role_id:%d heart:%d",m_uid,m_role_id,value) ;
    return false ;
}

bool ClientConnection::check_threshold(int msg_id)
{
    msgid_type mt ;
    mt.value = msg_id ;

    Threshold* th = m_threshold + mt.action_id % MAX_ACTION_SIZE ;
    th->inc() ;
    return th->is_limit() == false ;

}

