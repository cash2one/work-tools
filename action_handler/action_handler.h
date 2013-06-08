
#ifndef action_handler_h_
#define action_handler_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class packet
{
public:
    virtual ~packet() {} ;
    virtual int get_id() = 0 ;

} ;

template <int msgid,typename body_type>
class ss_packet : public packet
{
public:
    int get_id() { return msgid ; } ;
    
    int encode(char* data,int size) { return 0 ; } ;   
    int decode(char* data,int size) { return 0 ; } ;   

public:
    body_type body ;
} ;

struct packet_info
{
    int size ;
    char* data;
} ;

class base_action_handler
{
public:
    virtual ~base_action_handler() { } ;
    virtual void do_action(packet_info* pi) = 0 ;
} ;

class action_handler_manager
{
public:
    enum { MAX_ACTION_COUNT = 256 , } ;
public:
    static action_handler_manager& instance()
    {
        static action_handler_manager handler_manager ;
        return handler_manager ;
    }
    
    int register_handler(int action_id,base_action_handler* handler)
    {
        printf("register handler %d\n",action_id) ;

        if( action_id <0 || action_id >= MAX_ACTION_COUNT || m_handler_table[action_id]!=NULL) return -1 ;
    
        m_handler_table[action_id] = handler ;
        return 0 ;  
    }

    base_action_handler* get_handler(int action_id)
    {
        if( action_id <0 || action_id >= MAX_ACTION_COUNT ) return NULL ;
        return m_handler_table[action_id] ;
    }

private:
    action_handler_manager()
    {
        memset(m_handler_table,0,sizeof(m_handler_table)) ;
    }



private:
    base_action_handler* m_handler_table[MAX_ACTION_COUNT] ;

} ;


template<int action_id,typename request_body,typename response_body>
class template_action_handler : private base_action_handler
{
public:
    typedef request_body request_body_type ;
    typedef response_body response_body_type ;
    typedef ss_packet<action_id*2,request_body> request_packet_type ;
    typedef ss_packet<action_id*2+1,response_body> response_packet_type ;
public:
    template_action_handler()
    {
        if(action_handler_manager::instance().register_handler(action_id,this) !=0 ) abort() ;
    }

    virtual void process(request_body_type& request,response_body_type& response) = 0 ;

private:
    void do_action(packet_info* pi)
    {
        request_packet_type request ;
        response_packet_type response ;
        request.decode(pi->data,pi->size) ;
        process(request.body,response.body) ;

    }



} ;

#endif



