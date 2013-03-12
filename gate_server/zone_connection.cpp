/*
 * zone_connection.cpp
 *
 *  Created on: 2012-4-1
 *      Author: lixingyi
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include "zone_connection.h"
#include "message.h"
#include "gate_application.h"
#include "../public/game_client.pb.h"
#include "../public/game_client.pb.h"
#include "common_util.h"

using namespace std;
using namespace kingnet;

ZoneConnection::ZoneConnection()
{
    // TODO Auto-generated constructor stub

}

ZoneConnection::~ZoneConnection()
{
    // TODO Auto-generated destructor stub
}

void ZoneConnection::on_event(int type)
{
    info_log_format(get_app().logger,"zone_connection on_event type=%d errno=%d",type,get_errno()) ;
    fini() ;
}
int ZoneConnection::get_packet_info(const char* data,int size,packet_info* pi)
{
    if(size < (int)sizeof(ss_head) )
    {
        pi->size =  (int)sizeof(ss_head) ;
    }
    else
    {
        ss_head* head = (ss_head*)data ;
        pi->type = ntoh_int16(head->msgid) ;
        pi->size = ntoh_int16(head->length) ;
        pi->data = data ;
    }

	if( pi->size < (int)sizeof(ss_head) || pi->size > 4194304 )
	{
		error_log_format(get_app().logger, "invalid head: type:%d size:%d",pi->type, pi->size);
        return -4 ;
	}
    return 0;

}
int ZoneConnection::process_packet(const packet_info* pi)
{
    get_app().zone_counter.add(0,pi->size) ;
	//get_app().stats_.AddWanTraffic(pi->size, true);
    //debug_log_format(get_app().logger,"zone msgid:%d size:%d",(pi->type >> 2) & 0x3ff ,pi->size) ;
    switch(pi->type)
    {
    case ss_acc_login_response::packet_type:
        return do_acc_login_response(pi) ;
    case ss_broadcast::packet_type:
        return do_broadcast(pi) ;
    case ss_create_player_response::packet_type:
        return do_create_player_response(pi);
    case ss_player_login_response::packet_type:
        return do_player_login_response(pi) ;
//	case ss_random_name_response::packet_type:
//		return do_random_name_response(pi);
    case ss_kick_player_notify::packet_type:
        return do_kick_player_notify(pi);
    case ss_server_status_response::packet_type:
        return do_server_status_response(pi) ;
		/*case ss_get_fight_data_response::packet_type:
		return do_debug_fight_data_response(pi);*/

    default:
        return do_game_response(pi) ;
    }
    return 0 ;
}

int ZoneConnection::do_debug_fight_data_response(const packet_info* pi)
{
	ss_get_fight_data_response  resp;
	if(resp.decode(pi->data,pi->size)!=pi->size) return -1 ;

	int32_t role_id = ntoh_int32(((ss_head*)pi->data)->key) ;
	

	// write response to file
	char filename[30] = {0} ;
	snprintf(filename,sizeof(filename),"fight-%d-%d.data", role_id, pi->size) ;

	int fd = open(filename,O_APPEND|O_WRONLY|O_CREAT,0755) ;
	if ( fd > 0 )
	{
		cs_head_plus head = {0};
		head.msgid = hton_int16(pi->type) ;
		head.length = hton_int16(pi->size + cs_head_size(pi->type) - sizeof(ss_head) ) ;
		head.seq = ((ss_head*)pi->data)->seq ;

		debug_log_format(get_app().logger, "send to role %d fight data size: %d,type: %d seq: %d body_size %d", 
			role_id, pi->size, pi->type, ntoh_int32(head.seq), resp.body.ByteSize());

	    write(fd, (const char*)&head, cs_head_size(pi->type)) ;
		write(fd, pi->data + sizeof(ss_head), pi->size - sizeof(ss_head)) ;
	}

	const FightMonsterResponse&  fight_resp = resp.body.fight_data();

	string  tmp_string;
	resp.body.SerializeToString(&tmp_string);
	GetFightDataResponse  debug_fight_data_resp;
	debug_fight_data_resp.ParseFromString(tmp_string);

	FightMonsterResponse  debug_fight_resp;
	debug_fight_resp.CopyFrom(debug_fight_data_resp.fight_data());

	assert(fight_resp.ByteSize() == debug_fight_resp.ByteSize());
	debug_log_format(get_app().logger, "string size: %d, fight_data_resp size: %d, fight monster resp size: %d", 
		tmp_string.size(), debug_fight_data_resp.ByteSize(), debug_fight_resp.ByteSize());

	ClientConnection* conn = get_app().get_role_connection(role_id) ;

	if(conn) get_app().forward_ss_packet(conn,pi) ;

	return 0;
}

int ZoneConnection::do_broadcast(const packet_info* pi)
{
    ss_broadcast broadcast ;
    if(broadcast.decode(pi->data,pi->size)!=pi->size) return -1 ;

    if(broadcast.body.all_flag())
    {
        get_app().broadcast_all(broadcast.body.data().data(),broadcast.body.data().size()) ;
    }
    else
    {
		//get_app().stats_.AddWanTraffic(broadcast.body.data().size() * broadcast.body.uids_size(), true);
        for(int i = broadcast.body.uids_size()-1; i>=0 ;--i)
        {
            //debug_log_format(get_app().logger,"broadcast size:%d role_id:%d",broadcast.body.data().size(),broadcast.body.uids(i)) ;
            ClientConnection* conn = get_app().get_role_connection(broadcast.body.uids(i)) ;
            if(conn ) conn->send(broadcast.body.data().data(),broadcast.body.data().size(),0) ;
        }
    }

    return 0 ;
}

int ZoneConnection::do_game_response(const packet_info* pi)
{

    int32_t role_id = ntoh_int32(((ss_head*)pi->data)->key) ;
    ClientConnection* conn = get_app().get_role_connection(role_id) ;
    if(conn) get_app().forward_ss_packet(conn,pi) ;

    //msgid_type mt ;
    //mt.value = pi->type ;
    //debug_log_format(get_app().logger,"response action:%d  role_id:%d",mt.action_id,role_id); 

    return 0 ;
}

int ZoneConnection::do_player_login_response(const packet_info* pi)
{
    ss_player_login_response response ;
    if(response.decode(pi->data,pi->size)!=pi->size) return -1 ;
    int role_id = response.key ;
    ClientConnection* conn = get_app().get_role_connection(role_id) ;
    if(conn)
    {
        get_app().forward_ss_packet(conn,pi) ;
        if(response.body.error_code() == EC_SUCCESS)
        {
            conn->on_player_login() ;
        }

    }

    return 0 ;
}


int ZoneConnection::do_create_player_response(const packet_info* pi)
{
    ss_create_player_response response ;
    if(response.decode(pi->data,pi->size)!=pi->size) return -1 ;
//    int32_t uid = response.key ;

	get_app().name_conn().send(&response,0) ;
	return 0;

}


int ZoneConnection::do_acc_login_response(const packet_info* pi)
{
    ss_acc_login_response response ;
    if(response.decode(pi->data,pi->size)!=pi->size) return -1 ;

    int role_id = 0 ;
    if(response.body.roles_size() > 0) role_id = PLAYER_ROLE_ID(response.body.roles(0).guid());

	int uid = response.key;
	int server_id =	response.body.server_id();

	response.body.set_server_time(kingnet::time_ms());
	
    ClientConnection* conn = get_app().get_user_connection(uid, server_id) ;
    if(conn && conn->get_status() == ClientConnection::STATUS_ACC_LOGIN )
    {
        get_app().forward_ss_packet(conn,pi) ;
        if(response.body.error_code()==EC_SUCCESS)
        {
            conn->on_acc_login(role_id) ;
        }
    }

    return 0 ;

}

int ZoneConnection::do_server_status_response( const packet_info* pi)
{
    ss_server_status_response response ;
    if(response.decode(pi->data,pi->size)!=pi->size) return 0 ;
    //tcp_data_handler::connection_id conn_id ;
	//conn_id.fd = ntoh_int32(((ss_head*)pi->data)->key) ;
	//conn_id.timestamp = ntoh_int32(((ss_head*)pi->data)->seq) ;
    ClientConnection* conn = (ClientConnection*)get_app().event_engine.get_handler(response.key);
    if(conn && response.seq == conn->get_id().timestamp )
    {
        //get_app().forward_ss_packet(conn,pi) ;
        cs_server_status_response cs_response ;
        cs_response.body.set_online(get_app().uid2conn.size());
        cs_response.body.set_avg_delay(get_app().get_counter().get_avg_value());
        conn->send(&cs_response,0) ;
        conn->close() ;
    }
    return 0 ;
}


int ZoneConnection::do_kick_player_notify(const packet_info* pi)
{
    int32_t role_id = ntoh_int32(((ss_head*)pi->data)->key) ;

    ClientConnection* conn = get_app().get_role_connection(role_id) ;
    if(conn)
    {
        get_app().forward_ss_packet(conn,pi) ;
        //use on_connect as delay kick
        conn->on_connect() ;
    }

    return 0 ;
}


