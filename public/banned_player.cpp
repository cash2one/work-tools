#include "banned_player.h" 

banned_player::banned_player()
{
    role_id = 0;
    ban_until_ts = 0;
    by_gm = 0;
    memset(dirty,1,sizeof(dirty));
}
void banned_player::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    ban_until_ts = (int32_t)atoi(data[1]);
    by_gm = (int32_t)atoi(data[2]);
    by_reason.assign(data[3]);
    memset(dirty,0,sizeof(dirty));
}
void banned_player::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    ban_until_ts = (int32_t)atoi(data[1].c_str());
    by_gm = (int32_t)atoi(data[2].c_str());
    by_reason.assign(data[3].c_str());
    memset(dirty,0,sizeof(dirty));
}
int banned_player::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int banned_player::sql_data(char* buf,int size) const
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
        len =sql_ban_until_ts(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_by_gm(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_by_reason(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int banned_player::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from banned_player where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int banned_player::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into banned_player set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int banned_player::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update banned_player set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int banned_player::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from banned_player where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
