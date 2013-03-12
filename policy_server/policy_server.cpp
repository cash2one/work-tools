#include <stdio.h>
#include "tcp_data_handler.h"
#include "tcp_acceptor.h"
#include "application.h"
#include "system_util.h"
#include "unix_config.h"

using namespace kingnet ;

class policy_app ;
DECLARE_APPLICATION_INSTANCE(policy_app) ;

class policy_connection : public tcp_data_handler
{
public:
    int get_packet_info(const char* data,int size,packet_info* pi)
    {
        pi->size =size ;
        pi->data = data ;
        return 0 ;
    }
    
    int process_packet(const packet_info* pi) ;
    
    void on_event(int type)
    {
        fini() ;
    }



} ; 

class policy_acceptor : public tcp_acceptor
{
public:
    int on_connection(int fd,sa_in_t* addr) ;

private:


};

class policy_app : public application
{
public:
    int on_init()
    {
        unix_config config ;
        if(config.load(config_file)!=0 ) error_return(-1,"load config failed") ;

        if(m_acceptor.init(&event_engine,
            config.get("listen_ip","0.0.0.0"),
            config.get("listen_port",843))!=0) error_return(-1,"listen failed") ;

        conn_table = new policy_connection[max_open_fd] ;
        if(conn_table == 0 ) error_return(-1,"init conn table failed") ;
        static const char policy[] = "<cross-domain-policy>"
            "<allow-access-from domain='*' to-ports='*'/>"
            "</cross-domain-policy>" ;
        policy_data = strdup(config.get("policy_data",policy)) ;
        if(policy_data == NULL ) error_return(-1,"get policy data failed") ;
        policy_size = strlen(policy_data) + 1  ;

        return 0 ;
    }

    void on_fini()
    {
        m_acceptor.fini() ;
        delete[] conn_table ;
        free(policy_data) ;
    }

    void on_timer()
    {

    }

public:
    policy_connection* conn_table ;
    char* policy_data ;
    int policy_size ;
private:
    policy_acceptor m_acceptor ;

} ;

int policy_acceptor::on_connection(int fd,sa_in_t* addr)
{
    //policy_connection* conn = new policy_connection() ;
    if( get_app().conn_table[fd].init(m_reactor,fd)!=0) return -1 ;

    return 0 ;
}

int policy_connection::process_packet(const packet_info* pi)
{
    static char buf[512] ;
    int buf_size = pi->size > 500 ? 500:pi->size ;
    memcpy(buf,pi->data,buf_size) ;
    buf[buf_size] = '\0' ;
    if(strstr(buf,"<policy-file-request/>"))
    {
        send(get_app().policy_data,get_app().policy_size,0) ;
    }

    return -1 ;
}


IMPLEMENT_APPLICATION_INSTANCE(policy_app) ;
IMPLEMENT_MAIN() ;
