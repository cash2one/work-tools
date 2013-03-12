/*
 * GateApplication.cpp
 *
 *  Created on: 2012-4-1
 *      Author: lixingyi
 */

#include <string>
#include "gate_application.h"
#include "version.h"
#include "unix_config.h"
#include "system_util.h"
#include "third_party/pugixml.hpp"
#include "message.h"
#include "common_util.h"

using namespace std;
using namespace kingnet ;
using namespace protocols::common;

int ClientAcceptor::on_connection(int fd,sa_in_t* addr)
{
    if(!get_app().zone_conn.connected() ) return -1 ;
    if(get_app().is_online_threshold() ) return -1 ;
    ClientConnection* conn = get_app().alloc_connection() ;
    if(conn == NULL) return -1 ;
    if( conn->init(m_reactor,fd,10240)!=0)
    {
        get_app().free_connection(conn) ;
        return -1 ;
    }
    set_socket_nodelay(fd) ;
    conn->set_readall_flag(false) ;
    
    char remote_addr[32] = {0} ;
    inet_ntop(AF_INET,&addr->sin_addr,remote_addr,sizeof(remote_addr)) ;
    debug_log_format(get_app().logger,"client %s connected fd:%d",remote_addr,fd) ;

	conn->set_login_ip(std::string(remote_addr, strlen(remote_addr)));
    conn->on_connect();
    return 0 ;
}

int ZoneAcceptor::on_connection(int fd,sa_in_t* addr)
{
    if( get_app().zone_conn.connected()) return -1 ;
    set_socket_buffer(fd,8388608);
    if( get_app().zone_conn.init(m_reactor,fd)!=0) return -1 ;
    char remote_addr[32] = {0} ;
    inet_ntop(AF_INET,&addr->sin_addr,remote_addr,sizeof(remote_addr)) ;
    info_log_format(get_app().logger,"zone_server %s connected fd:%d",remote_addr,fd) ;
    return 0 ;
}

void LogConnection::on_event(int type)
{
	fini();
}

void NameConnection::on_event(int type)
{
	info_log_format(get_app().logger,"on_event type=%d errno:%d",type,get_errno()) ;
    fini() ;
}

int NameConnection::get_packet_info(const char* data,int size,packet_info* pi)
{
	if(size < (int)sizeof(ss_head) )
    {
        pi->size = sizeof(ss_head);
    }
    else
    {

        ss_head* head = (ss_head*)data ;
        pi->type = ntoh_int16(head->msgid) ;
        pi->size = ntoh_int16(head->length) ;
        pi->data = data ;
    }
    //debug_log_format(get_app().logger,"recv type:%d size:%d\n",pi->type,pi->size) ;
    return 0;
}

int NameConnection::process_packet(const packet_info* pi)
{
	switch(pi->type)
    {
    case ss_acc_login_response::packet_type:
        return do_acc_login_response(pi);
    case ss_create_player_request::packet_type:
        return do_create_player_request(pi) ;
    case ss_create_player_response::packet_type:
        return do_create_player_response(pi) ;
	case ss_random_name_response::packet_type:
		return do_random_name_response(pi);
	case ss_find_player_response::packet_type:
		return do_find_player_response(pi);
	default:
		error_log_format(get_app().logger,"unhandled name packet type:%d size:%d\n",pi->type,pi->size) ;
		break;

	}
	return 0;
}

int NameConnection::do_acc_login_response(const packet_info* pi)
{
	ss_acc_login_response response;
	if(response.decode(pi->data,pi->size) != pi->size)
		return -1 ;

	int uid = response.key;
	int server_id = response.body.server_id();

	ClientConnection* conn = get_app().get_user_connection(uid, server_id) ;
	if (!conn)
		return -1;

	if (response.body.error_code())
	{
		get_app().forward_ss_packet(conn,pi) ;
		conn->close();
	}
	else
	{
		if (response.body.role_id() != 0 && response.body.role_status() > ::protocols::common::AccountStatus_FIRST_LOGINED)
		{
		    // tell logic to load player
			ss_acc_login_request request;
			request.key = response.key;
			request.seq = response.seq;
			request.tick = response.tick;
			request.body.set_uid(response.body.role_id());
			request.body.set_token("");
			request.body.set_server_id(conn->server_id());
			get_app().zone_conn.send(&request, 0);
		}
		else
		{
		    // tell client to create player
			conn->set_status(ClientConnection::STATUS_PLAYER_LOGIN);
			get_app().forward_ss_packet(conn,pi) ;
		}

	}

	return 0;
}

int NameConnection::do_create_player_request(const packet_info* pi)
{
	get_app().zone_conn.send(pi->data, pi->size, 0);
	return 0;
}

int NameConnection::do_create_player_response(const packet_info* pi)
{
	ss_create_player_response response;
	if(response.decode(pi->data,pi->size) != pi->size)
		return -1 ;
	int uid = response.key;
	int server_id = response.body.server_id();
	ClientConnection* conn = get_app().get_user_connection(uid, server_id) ;
	if(conn)
	{
		conn->on_acc_login(PLAYER_ROLE_ID(response.body.player().guid())) ;
		get_app().forward_ss_packet(conn, pi);
	}
	return 0;
}

int NameConnection::do_random_name_response(const packet_info* pi)
{
	ss_random_name_response response;
	if(response.decode(pi->data,pi->size) != pi->size)
		return -1 ;
	int uid = response.key;
	int server_id = response.body.server_id();
	ClientConnection* conn = get_app().get_user_connection(uid, server_id) ;
	if(conn)
	{
		get_app().forward_ss_packet(conn, pi);
	}
	return 0;
}

int NameConnection::do_find_player_response(const packet_info* pi)
{
	ss_find_player_response response;
	if(response.decode(pi->data,pi->size) != pi->size)
		return -1;
	int role_id = response.key;
	ClientConnection* conn = get_app().get_role_connection(role_id) ;
	if(conn)
	{
		get_app().forward_ss_packet(conn, pi);
	}
	return 0;
}

GateApplication::GateApplication()
//    : verifying_index_(1)
	: check_token(false)
	, check_type(0)
	, m_shut_down_delay_sec(0)
	, m_is_shuting_down(false)

{
    // TODO Auto-generated constructor stub
    
    role_id2conn.set_empty_key(0);
    role_id2conn.set_deleted_key(-1);
}

GateApplication::~GateApplication()
{
    // TODO Auto-generated destructor stub
}

const char* GateApplication::version()
{
    return VERSION ;
}

int GateApplication::on_init()
{

    pugi::xml_document xml_config ;
    if(!xml_config.load_file(config_file))
    {
        error_return(-1,"load config failed") ;
    }
    pugi::xml_node root = xml_config.child("root") ;
    if(!root) error_return(-1,"missing <root> node") ;

    pugi::xml_node node = root.child("log") ;
    if(logger.init(node.attribute("prefix").value(),
            node.attribute("level").as_int() ) !=0 )
    {
        error_return(-1,"init logger failed") ;
    }

    node = root.child("client_acceptor") ;
    if(m_client_acceptor.init(&event_engine,
            node.attribute("listen_ip").value(),
            node.attribute("listen_port").as_int() )!=0)
    {
        error_return(-1,"init client acceptor failed") ;
    }
    set_defer_accept(m_client_acceptor.fd(),10 ) ;

    m_online_threshold = node.attribute("online_threshold").as_int() ;

    node = root.child("server_acceptor") ;
    if(m_zone_acceptor.init(&event_engine,
            node.attribute("listen_ip").value(),
            node.attribute("listen_port").as_int() )!=0)
    {
        error_return(-1,"init server acceptor failed") ;
    }

	node = root.child("log_server");
	log_server_endpoint.ip.assign(node.attribute("ip").value());
	log_server_endpoint.port = node.attribute("port").as_int();
	if(log_conn.init(&event_engine,
		log_server_endpoint.ip.c_str(),
		log_server_endpoint.port ) != 0 )
	{
		error_return(-1, "init log server connector failed") ;
	}
	info_log_format(get_app().logger, "init udp connection to %s port %d.", log_server_endpoint.ip.c_str(), log_server_endpoint.port);

	node = root.child("name_server");
	m_name_server_endpoint.ip.assign(node.attribute("ip").value());
	m_name_server_endpoint.port = node.attribute("port").as_int();
	if(m_name_conn.init(&event_engine,
		m_name_server_endpoint.ip.c_str(),
		m_name_server_endpoint.port ) != 0 )
	{
		error_return(-1, "init name server connector failed") ;
	}

	node = root.child("message_check");
	check_threshold = node.attribute("threshold").as_bool();
	check_seq = node.attribute("seq").as_bool();
	check_heartbeat = node.attribute("heartbeat").as_bool();
	/// init token check
	node = root.child("token_check");
	check_token = node.attribute("check").as_bool();
	check_type = node.attribute("type").as_int();
	key1.assign(node.attribute("key1").value());
	key2.assign(node.attribute("key2").value());

	m_shut_down_delay_sec = root.child("shutdown").attribute("delay_sec").as_int();
	if (m_shut_down_delay_sec < 1 )
	{
		error_return(-1, "shutdown delay sec init failed") ;
	}

	node = root.child("server_id_list");
	for (pugi::xml_node input = node.first_child(); input;
		input = input.next_sibling())
	{
		int server_id = input.attribute("id").as_int();
		m_server_id_list.insert(server_id);
	}
	if (m_server_id_list.size() == 0)
	{
		error_return(-1, "m_server_id_list init failed") ;
	}


    set_timer(60000);

	//stats_.Start();

	set_delay_stop(m_shut_down_delay_sec * 1000);

    srand(time(0));
    return 0 ;
}

int GateApplication::on_reload()
{
    m_client_acceptor.fini() ;
    m_zone_acceptor.fini() ;
    log_conn.fini() ;
    m_name_conn.fini() ;
    logger.fini() ;

    return on_init() ;
}

void GateApplication::on_delay_stop()
{
	if (m_is_shuting_down)
	{
		return;
	}
	m_is_shuting_down = true;

	cs_server_shut_down_notify ntf;
	ntf.body.set_count_down_sec(m_shut_down_delay_sec);

    char buf[512] = {0} ;
    int buf_size = ntf.encode(buf, sizeof(buf) );
    if(buf_size>0) broadcast_all(buf, buf_size);

	m_client_acceptor.fini() ;
}

void GateApplication::on_fini()
{

    m_zone_acceptor.fini() ;
    int counter = 0 ;
    for(ClientUIdIndexContainer::iterator it=uid2conn.begin();it!=uid2conn.end();it=uid2conn.begin())
    {
        if( (++counter) % 100 == 0 )  sleep(1) ;
		it->second->close();
    }

	for(int i = m_conn_pool.size() -1 ; i >= 0 ; --i)
    {
        delete m_conn_pool[i] ;
    }

    info_log_string(logger,"system stopped") ;
}
void GateApplication::on_timer()
{
    //#define LOG_DEBUG(fmt, args...) debug_log_format(get_app().logger, fmt, ##args)
    //LOG_DEBUG("Online players: %d\n", uid2conn.size());

	send_online_log();

	if (!log_conn.connected())
	{
		debug_log_format(get_app().logger, "lose log server connection, try to reconnect %d:%d ...", log_server_endpoint.ip.c_str(), log_server_endpoint.port);
		if(log_conn.init(&event_engine,
			log_server_endpoint.ip.c_str(),
			log_server_endpoint.port ) != 0 )
		{
			error_log_format(get_app().logger, "reconnect to log server connector failed") ;
		}
	}

	if (!m_name_conn.connected())
	{
		debug_log_format(get_app().logger, "lose name server connection, try to reconnect %s:%d ...",
			m_name_server_endpoint.ip.c_str(), m_name_server_endpoint.port);
		if(m_name_conn.init(&event_engine,
			m_name_server_endpoint.ip.c_str(),
			m_name_server_endpoint.port ) != 0 )
		{
			error_log_format(get_app().logger, "reconnect to name server failed") ;
		}
	}

    info_log_format(logger,"process max_time:%d max_action:%d avg_time:%d online:%d",
            m_counter.get_max().value,m_counter.get_max().key,
            m_counter.get_avg_value(),uid2conn.size() ) ;
    m_counter.clear() ;

    info_log_format(logger,"zone_connection count:%d total:%ld",zone_counter.get_count(),zone_counter.get_total() ) ;
    zone_counter.clear() ;
    
}

ClientConnection* GateApplication::alloc_connection()
{
    ClientConnection* conn = NULL ;
    if(m_conn_pool.size() == 0)
    {
        conn = new ClientConnection() ;
    }
    else
    {
        conn = m_conn_pool.back() ;
        m_conn_pool.pop_back() ;
    }

    return conn ;

}
void GateApplication::free_connection(ClientConnection* conn)
{
    if(m_conn_pool.size() > 100 ) delete (conn) ;
    else m_conn_pool.push_back(conn) ;

}

ClientConnection* GateApplication::get_user_connection(int32_t uid, int32_t server_id)
{
    ClientUIdIndexContainer::iterator it = uid2conn.find(std::make_pair(uid, server_id)) ;
    if( it != get_app().uid2conn.end() ) return it->second ;

    return NULL ;
}

ClientConnection* GateApplication::get_role_connection(int32_t role_id)
{
    ClientIndexContainer::iterator it = role_id2conn.find(role_id) ;
    if( it != get_app().role_id2conn.end() ) return it->second ;

    return NULL ;
}


int GateApplication::set_user_connection(int32_t uid, int32_t server_id, ClientConnection* conn)
{
    if( conn == NULL) uid2conn.erase(std::make_pair(uid, server_id)) ;
    else uid2conn.insert(std::make_pair(std::make_pair(uid, server_id), conn));
    return 0 ;
}

int GateApplication::set_role_connection(int32_t role_id,ClientConnection* conn)
{
    if( conn == NULL) role_id2conn.erase(role_id) ;
    else role_id2conn[role_id] = conn ;
    return 0 ;
}



void GateApplication::broadcast_all(const char* data,int size)
{
    for(ClientIndexContainer::iterator it=role_id2conn.begin();it!=role_id2conn.end();++it)
    {
		//get_app().stats_.AddWanTraffic(size, true);
        if(it->second->get_status() == ClientConnection::STATUS_IN_GAME) it->second->send(data,size,0) ;
    }

}

void GateApplication::stat_process_time(int32_t begin_tick,int msg_type)
{

    int process_time = (kingnet::time_ms() & 0x0fffffff) - begin_tick ;
    if( begin_tick !=0 && process_time > 0 )
    {
        //debug_log_format(logger,"action:%d time:%d",msg_type,process_time) ;
        m_counter.add(msg_type,process_time) ;
    }
    


}

int GateApplication::forward_ss_packet(ClientConnection* conn,const packet_info* pi)
{
    ss_head* sshead = (ss_head*)pi->data ;
    int32_t begin_tick = ntoh_int32(sshead->tick) ;
    if( pi->type & 0x1 ) stat_process_time( begin_tick ,pi->type >> 2)  ;
    
    cs_head_plus head = {0};
    head.msgid = sshead->msgid ;
    head.seq = sshead->seq ;
    head.length = hton_int16(pi->size + cs_head_size(pi->type) - sizeof(ss_head) ) ;
    
    conn->send((const char*)&head,cs_head_size(pi->type),0) ;
    conn->send(pi->data + sizeof(ss_head),pi->size - sizeof(ss_head), 0) ;
    return 0 ;

}

int GateApplication::forward_cs_packet(const packet_info* pi,int32_t key)
{
    ss_head head = {0};
    head.key = hton_int32(key) ;
    head.seq = ((cs_head_plus*)(pi->data))->seq ;
    head.msgid = hton_int16(pi->type) ;
    head.length = hton_int16(pi->size - cs_head_size(pi->type) + sizeof(head) ) ;
    int32_t begin_tick = kingnet::time_ms() & 0x0fffffff ;
    head.tick = hton_int32(begin_tick);
    zone_conn.send((const char*)&head,sizeof(head),0) ;
    zone_conn.send(pi->data + cs_head_size(pi->type),pi->size - cs_head_size(pi->type),0) ;

    return 0 ;
}

int GateApplication::forward_cs_packet_to_name(const packet_info* pi,int32_t key)
{
	ss_head head = {0};
    head.key = hton_int32(key) ;
    head.seq = ((cs_head_plus*)(pi->data))->seq ;
    head.msgid = hton_int16(pi->type) ;
    head.length = hton_int16(pi->size - cs_head_size(pi->type) + sizeof(head) ) ;
    int32_t begin_tick = kingnet::time_ms() & 0x0fffffff ;
    head.tick = hton_int32(begin_tick);
    name_conn().send((const char*)&head,sizeof(head),0) ;
    name_conn().send(pi->data + cs_head_size(pi->type),pi->size - cs_head_size(pi->type),0) ;

	return 0;
}

void GateApplication::send_online_log()
{
	static int i = 1;

	ss_send_log_notify  notify;
	notify.key = notify.seq = 0;
	notify.body.set_seq(i++);
	notify.body.set_log_src_type(SRC_GATE_SERVER);
	int64_t  log_time = kingnet::time_ms() ;
	notify.body.set_time_stamp(log_time);
	notify.body.set_action_type(LOG_ACTION_SERVER_DATA);

	// 此log不关注个人信息，为全局log，此处设置仅仅是因为pb需要
	LogPlayerData*  lplayer = notify.body.mutable_player_info();	
	lplayer->set_ouid("0");
	lplayer->set_iuid(0);
	lplayer->set_role_id(0);
	lplayer->set_gender(0);
	lplayer->set_game_friend(0);
	lplayer->set_platform_friend(0);
	lplayer->set_user_level(0);
	lplayer->set_user_exp(0);
	lplayer->set_diamond(0);
	lplayer->set_gold_coin(0);
	lplayer->set_vip_level(0);
	lplayer->set_first_in_time(0);

	LogOptionalParams*  params = notify.body.mutable_optional_paras();
	params->set_para1(get_app().uid2conn.size()); // online member

	char log_buff[1024] = {0};
	sprintf(log_buff, "online person: %d", params->para1());
	notify.body.set_log_data(string(log_buff, strlen(log_buff)));

	get_app().log_conn.send(&notify, 0);
}


IMPLEMENT_APPLICATION_INSTANCE(GateApplication) ;
IMPLEMENT_MAIN() ;
