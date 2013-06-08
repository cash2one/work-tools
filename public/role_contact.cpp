#include "role_contact.h" 

role_contact::role_contact()
{
    role_id = 0;
    dst_role_id = 0;
    dst_tid = 0;
    update_time = 0;
    dst_server_id = 0;
    dst_job_type = 0;
    dst_role_level = 0;
    dst_vip_level = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_contact::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    dst_role_id = (int32_t)atoi(data[1]);
    dst_tid = (int32_t)atoi(data[2]);
    update_time = (int32_t)atoi(data[3]);
    dst_name.assign(data[4]);
    dst_server_id = (int32_t)atoi(data[5]);
    dst_job_type = (int8_t)atoi(data[6]);
    dst_role_level = (int8_t)atoi(data[7]);
    dst_vip_level = (int8_t)atoi(data[8]);
    memset(dirty,0,sizeof(dirty));
}
void role_contact::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    dst_role_id = (int32_t)atoi(data[1].c_str());
    dst_tid = (int32_t)atoi(data[2].c_str());
    update_time = (int32_t)atoi(data[3].c_str());
    dst_name.assign(data[4].c_str());
    dst_server_id = (int32_t)atoi(data[5].c_str());
    dst_job_type = (int8_t)atoi(data[6].c_str());
    dst_role_level = (int8_t)atoi(data[7].c_str());
    dst_vip_level = (int8_t)atoi(data[8].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_contact::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_dst_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_contact::sql_data(char* buf,int size) const
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
        len =sql_update_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_job_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_role_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_dst_vip_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_contact::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_contact where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_contact::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_contact set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_contact::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_contact set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_contact::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_contact where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
