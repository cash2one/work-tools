#include "guild_member.h" 

guild_member::guild_member()
{
    guild_id = 0;
    role_id = 0;
    role_tid = 0;
    devote = 0;
    create_time = 0;
    server_id = 0;
    job_type = 0;
    job_level = 0;
    vip_level = 0;
    status = 0;
    title = 0;
    login_time = 0;
    gender = 0;
    total_donate = 0;
    recent_donate = 0;
    last_donate_time = 0;
    memset(dirty,1,sizeof(dirty));
}
void guild_member::load(const char** data)
{
    guild_id = (int32_t)atoi(data[0]);
    role_id = (int32_t)atoi(data[1]);
    role_tid = (int32_t)atoi(data[2]);
    devote = (int32_t)atoi(data[3]);
    create_time = (int32_t)atoi(data[4]);
    server_id = (int32_t)atoi(data[5]);
    job_type = (int8_t)atoi(data[6]);
    job_level = (int8_t)atoi(data[7]);
    vip_level = (int8_t)atoi(data[8]);
    status = (int8_t)atoi(data[9]);
    title = (int8_t)atoi(data[10]);
    role_name.assign(data[11]);
    login_time = (int32_t)atoi(data[12]);
    gender = (int8_t)atoi(data[13]);
    total_donate = (int32_t)atoi(data[14]);
    recent_donate = (int32_t)atoi(data[15]);
    last_donate_time = (int32_t)atoi(data[16]);
    memset(dirty,0,sizeof(dirty));
}
void guild_member::load(const vector<string>& data)
{
    guild_id = (int32_t)atoi(data[0].c_str());
    role_id = (int32_t)atoi(data[1].c_str());
    role_tid = (int32_t)atoi(data[2].c_str());
    devote = (int32_t)atoi(data[3].c_str());
    create_time = (int32_t)atoi(data[4].c_str());
    server_id = (int32_t)atoi(data[5].c_str());
    job_type = (int8_t)atoi(data[6].c_str());
    job_level = (int8_t)atoi(data[7].c_str());
    vip_level = (int8_t)atoi(data[8].c_str());
    status = (int8_t)atoi(data[9].c_str());
    title = (int8_t)atoi(data[10].c_str());
    role_name.assign(data[11].c_str());
    login_time = (int32_t)atoi(data[12].c_str());
    gender = (int8_t)atoi(data[13].c_str());
    total_donate = (int32_t)atoi(data[14].c_str());
    recent_donate = (int32_t)atoi(data[15].c_str());
    last_donate_time = (int32_t)atoi(data[16].c_str());
    memset(dirty,0,sizeof(dirty));
}
int guild_member::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_guild_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_member::sql_data(char* buf,int size) const
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
        len =sql_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_devote(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_job_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_job_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_vip_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_title(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_login_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_gender(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[14])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_total_donate(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[15])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_recent_donate(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[16])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_donate_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int guild_member::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from guild_member where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_member::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into guild_member set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_member::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update guild_member set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_member::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from guild_member where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
