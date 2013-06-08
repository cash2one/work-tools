#include "role_blacklist.h" 

role_blacklist::role_blacklist()
{
    role_id = 0;
    dst_role_id = 0;
    dst_tid = 0;
    dst_server_id = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_blacklist::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    dst_role_id = (int32_t)atoi(data[1]);
    dst_tid = (int32_t)atoi(data[2]);
    dst_server_id = (int32_t)atoi(data[3]);
    dst_name.assign(data[4]);
    memset(dirty,0,sizeof(dirty));
}
void role_blacklist::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    dst_role_id = (int32_t)atoi(data[1].c_str());
    dst_tid = (int32_t)atoi(data[2].c_str());
    dst_server_id = (int32_t)atoi(data[3].c_str());
    dst_name.assign(data[4].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_blacklist::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_dst_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_blacklist::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_blacklist::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_blacklist where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_blacklist::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_blacklist set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_blacklist::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_blacklist set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_blacklist::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_blacklist where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
