/*
 * zone_connection.h
 *
 *  Created on: 2012-4-1
 *      Author: lixingyi
 */

#ifndef ZONE_CONNECTION_H_
#define ZONE_CONNECTION_H_

#include "tcp_data_handler.h"
using kingnet::packet_info ;
using kingnet::tcp_data_handler ;

class ZoneConnection : public tcp_data_handler
{
public:
    ZoneConnection();
    virtual ~ZoneConnection();

protected:
    virtual void on_event(int type) ;
    virtual int get_packet_info(const char* data,int size,packet_info* pi);
    virtual int process_packet(const packet_info* pi) ;

    int do_broadcast(const packet_info* pi)  ;
    int do_game_response(const packet_info* pi) ;
    int do_player_login_response(const packet_info* pi)  ;
    int do_acc_login_response(const packet_info* pi) ;
	int do_random_name_response(const packet_info* pi) ;
    int do_create_player_response(const packet_info* pi);
    int do_kick_player_notify(const packet_info* pi);
	int do_debug_fight_data_response(const packet_info* pi);
	int do_server_status_response(const packet_info* pi);
};

#endif /* ZONE_CONNECTION_H_ */
