#include "role_title.h" 

role_title::role_title()
{
    title_id = 0;
    role_id = 0;
    guild_id = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_title::load(const char** data)
{
    title_id = (int32_t)atoi(data[0]);
    role_id = (int32_t)atoi(data[1]);
    guild_id = (int32_t)atoi(data[2]);
    memset(dirty,0,sizeof(dirty));
}
void role_title::load(const vector<string>& data)
{
    title_id = (int32_t)atoi(data[0].c_str());
    role_id = (int32_t)atoi(data[1].c_str());
    guild_id = (int32_t)atoi(data[2].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_title::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_title_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_title::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_title_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_title::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_title where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_title::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_title set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_title::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_title set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_title::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_title where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
