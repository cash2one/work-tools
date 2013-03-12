#include "used_userid.h" 

used_userid::used_userid()
{
    uid = 0;
    server_id = 0;
    role_id = 0;
    status = 0;
    memset(dirty,1,sizeof(dirty));
}
void used_userid::load(const char** data)
{
    uid = (int32_t)atoi(data[0]);
    server_id = (int32_t)atoi(data[1]);
    role_id = (int32_t)atoi(data[2]);
    status = (int32_t)atoi(data[3]);
    name.assign(data[4]);
    memset(dirty,0,sizeof(dirty));
}
void used_userid::load(const vector<string>& data)
{
    uid = (int32_t)atoi(data[0].c_str());
    server_id = (int32_t)atoi(data[1].c_str());
    role_id = (int32_t)atoi(data[2].c_str());
    status = (int32_t)atoi(data[3].c_str());
    name.assign(data[4].c_str());
    memset(dirty,0,sizeof(dirty));
}
int used_userid::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_uid(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_server_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int used_userid::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_uid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int used_userid::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from used_userid where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int used_userid::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into used_userid set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int used_userid::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update used_userid set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int used_userid::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from used_userid where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
