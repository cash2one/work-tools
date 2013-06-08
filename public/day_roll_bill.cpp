/*
 * day_roll_bill.cpp
 *
 *  Created on: 2011-10-19
 *      Author: lxyfirst@yahoo.com.cn
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "const_strings.h"
#include "day_roll_bill.h"


using namespace protocols::common;

day_roll_bill::day_roll_bill():m_fd(-1),m_filedate(0),m_buf(NULL)
{
    memset(m_prefix,0,sizeof(m_prefix)) ;

}

day_roll_bill::~day_roll_bill()
{
   fini() ;
}

int day_roll_bill::init(const char* prefix,int buf_size)
{
    if ( prefix == NULL || m_fd >= 0 ) return -1 ;

    strncpy(m_prefix,prefix,sizeof(m_prefix)-1) ;

    m_delay = 1 ;
    if(buf_size < MIN_IOBUF_SIZE )
    {
        m_delay = 0 ;
        buf_size = MIN_IOBUF_SIZE ;
    }
    else if ( buf_size > MAX_IOBUF_SIZE )
    {
        buf_size = MAX_IOBUF_SIZE ;
    }

    m_buf = (memory_buffer*)realloc(m_buf,buf_size) ;
    if ( m_buf == NULL ) return -2 ;
    m_buf->size = buf_size - sizeof(memory_buffer) ;
    m_buf->pos = 0 ;

    //tzset() ;
    return prepare() ;

}
void day_roll_bill::fini()
{


    if ( m_fd >= 0 )
    {
        flush() ;
        close(m_fd) ;
        m_fd = -1 ;
        m_filedate = 0 ;
        m_prefix[0] = '\0' ;

    }

    if(m_buf != NULL)
    {
        free(m_buf) ;
        m_buf = NULL ;
    }
}
int day_roll_bill::prepare()
{
    time_t t = time(NULL);
    if ( localtime_r(&t, &m_now) == NULL ) return -1 ;
    m_now.tm_year += 1900 ;
    m_now.tm_mon += 1 ;

    int curdate = ( m_now.tm_mon << 8 ) | m_now.tm_mday ;
    if (m_filedate != curdate )
    {
        if(strcmp(m_prefix,"/dev/null")==0)  return 0 ;
        char filename[MAX_PREFIX_SIZE*2] = {0} ;
        snprintf(filename,sizeof(filename),"%s-%04d-%02d-%02d.log",m_prefix
                ,m_now.tm_year,m_now.tm_mon,m_now.tm_mday) ;
        int fd = open(filename,O_APPEND|O_WRONLY|O_CREAT,0755) ;
        if ( fd < 0 ) return -1 ;
        if ( m_fd >= 0 )
        {
            flush() ;
            close(m_fd) ;
        }
        m_fd = fd ;
        m_filedate = curdate ;
    }

    return 0 ;
}


int day_roll_bill::write_sql(int seq,int result,const char* sql)
{
    return write_format("%d#%d#%s;#",seq,result,sql) ;
}

int day_roll_bill::write_money(int seq, int role_id, int action_type, int change_money_type, int money_type, int money_value, int result_money_value)
{
	return write_format("%d|%d|%s|%d|%s|%s|%d|%d|", seq, role_id, 
		get_log_action_name(action_type),
		change_money_type,
		get_money_change_type_info(change_money_type), 
		get_money_type_info(money_type), 
		money_value,
		result_money_value);
}

int day_roll_bill::write_trade(int seq, int role_id, int action_type, int trans_type, int money_type, int cost_value)
{
	return write_format("%d|%d|%s|%d|%s|%d|", seq, role_id, 
		get_log_action_name(action_type),
		trans_type,
		get_money_type_info(money_type),
		cost_value);
}

int day_roll_bill::write_item(int seq, int role_id, int action_type, int item_change_type, int64_t item_id, int count)
{
	return write_format("%d|%d|%s|%s|%ld|%d|", seq, role_id, 
		get_log_action_name(action_type), 
		get_props_change_type_info(item_change_type),
		item_id, count);
}

int day_roll_bill::write_transaction(SendLogNotify*  notify) 
{
	if (notify == 0) return -1;

	const LogPlayerData&  lplayer = notify->player_info();
	const LogOptionalParams&  params = notify->optional_paras();

	return write_format("%d|%d|%s|%d|%d|%d|%d|%d|%d|%d|%d|%d", 
		notify->seq(), lplayer.role_id(),
		lplayer.name().c_str(), lplayer.user_level(), lplayer.job(),
		params.para1(), params.para2(), 
		params.para3(), params.para4(),
		params.para5(), 
		params.para11() & 0xffffffff,
		params.para12() & 0xffffffff
		);
}

int day_roll_bill::write_format(const char* fmt,...)
{

    if ( m_fd < 0 ) return -1 ;

    if ( prepare() != 0 ) return -1 ;

    char *buf_data = m_buf->data + m_buf->pos ;
    int length = sprintf(buf_data ,"%04d-%02d-%02d %02d:%02d:%02d|" ,
            m_now.tm_year,m_now.tm_mon,m_now.tm_mday,m_now.tm_hour,m_now.tm_min,m_now.tm_sec) ;

    if(length < 0 ) return -2 ;
    buf_data += length ;

    static int MAX_LINE_CONTENT = MAX_LINE_SIZE - 64;
    va_list ap ;
    va_start(ap, fmt);
    length = vsnprintf(buf_data,MAX_LINE_CONTENT,fmt,ap) ;
    va_end(ap);

    if(length < 0 ) return -2 ;
    else if ( length >MAX_LINE_CONTENT) length =MAX_LINE_CONTENT ;
    buf_data += length ;

    if ( *(buf_data -1) !='\n')
    {
        *buf_data = '\n' ;
        *(++buf_data) = '\0' ;
    }
    
    

    m_buf->pos = buf_data - m_buf->data ;

    if( (m_buf->size - m_buf->pos < MAX_LINE_SIZE) && (flush() !=0) ) return -3 ;

    return 0 ;

}


int day_roll_bill::flush()
{
    if(m_fd < 0 || m_buf->pos < 1 ) return -1 ;

    int len = write(m_fd,m_buf->data,m_buf->pos) ;
    if(len == m_buf->pos)
    {
        m_buf->pos = 0 ;
    }
    else if(len < m_buf->pos)
    {
        memmove(m_buf->data,m_buf->data + len , m_buf->pos - len) ;
        m_buf->pos -= len ;
    }
    else if ( len < 0 )
    {
        return -1 ;
    }

    return 0 ;

}

