#include "guild_info.h" 

guild_info::guild_info()
{
    guild_id = 0;
    leader_id = 0;
    leader_tid = 0;
    money = 0;
    exp = 0;
    create_time = 0;
    status = 0;
    grade = 0;
    leader_server_id = 0;
    total_member = 0;
    max_member = 0;
    memset(dirty,1,sizeof(dirty));
}
void guild_info::load(const char** data)
{
    guild_id = (int32_t)atoi(data[0]);
    leader_id = (int32_t)atoi(data[1]);
    leader_tid = (int32_t)atoi(data[2]);
    money = (int32_t)atoi(data[3]);
    exp = (int32_t)atoi(data[4]);
    create_time = (int32_t)atoi(data[5]);
    status = (int8_t)atoi(data[6]);
    grade = (int8_t)atoi(data[7]);
    leader_server_id = (int32_t)atoi(data[8]);
    total_member = (int16_t)atoi(data[9]);
    max_member = (int16_t)atoi(data[10]);
    leader_name.assign(data[11]);
    guild_name.assign(data[12]);
    notice.assign(data[13]);
    memset(dirty,0,sizeof(dirty));
}
void guild_info::load(const vector<string>& data)
{
    guild_id = (int32_t)atoi(data[0].c_str());
    leader_id = (int32_t)atoi(data[1].c_str());
    leader_tid = (int32_t)atoi(data[2].c_str());
    money = (int32_t)atoi(data[3].c_str());
    exp = (int32_t)atoi(data[4].c_str());
    create_time = (int32_t)atoi(data[5].c_str());
    status = (int8_t)atoi(data[6].c_str());
    grade = (int8_t)atoi(data[7].c_str());
    leader_server_id = (int32_t)atoi(data[8].c_str());
    total_member = (int16_t)atoi(data[9].c_str());
    max_member = (int16_t)atoi(data[10].c_str());
    leader_name.assign(data[11].c_str());
    guild_name.assign(data[12].c_str());
    notice.assign(data[13].c_str());
    memset(dirty,0,sizeof(dirty));
}
int guild_info::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_guild_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_info::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_leader_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_leader_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_money(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_exp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_grade(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_leader_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_total_member(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_max_member(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_leader_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_notice(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int guild_info::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from guild_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_info::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into guild_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_info::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update guild_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_info::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from guild_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
