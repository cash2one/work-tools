#include "role_skill.h" 

role_skill::role_skill()
{
    role_id = 0;
    buddy_id = 0;
    skill_id = 0;
    sk_type = 0;
    status = 0;
    sk_level = 0;
    equiped_slot = 0;
    practice_state = 0;
    skill_exp = 0;
    last_add_exp_time = 0;
    delta_time = 0;
    expire_count_left = 0;
    delta_exp = 0;
    create_time = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_skill::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    buddy_id = (int32_t)atoi(data[1]);
    skill_id = (int32_t)atoi(data[2]);
    sk_type = (int8_t)atoi(data[3]);
    status = (int8_t)atoi(data[4]);
    sk_level = (int8_t)atoi(data[5]);
    equiped_slot = (int8_t)atoi(data[6]);
    practice_state = (int8_t)atoi(data[7]);
    skill_exp = (int32_t)atoi(data[8]);
    last_add_exp_time = (int64_t)atol(data[9]);
    delta_time = (int32_t)atoi(data[10]);
    expire_count_left = (int32_t)atoi(data[11]);
    delta_exp = (int32_t)atoi(data[12]);
    create_time = (int32_t)atoi(data[13]);
    memset(dirty,0,sizeof(dirty));
}
void role_skill::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    buddy_id = (int32_t)atoi(data[1].c_str());
    skill_id = (int32_t)atoi(data[2].c_str());
    sk_type = (int8_t)atoi(data[3].c_str());
    status = (int8_t)atoi(data[4].c_str());
    sk_level = (int8_t)atoi(data[5].c_str());
    equiped_slot = (int8_t)atoi(data[6].c_str());
    practice_state = (int8_t)atoi(data[7].c_str());
    skill_exp = (int32_t)atoi(data[8].c_str());
    last_add_exp_time = (int64_t)atol(data[9].c_str());
    delta_time = (int32_t)atoi(data[10].c_str());
    expire_count_left = (int32_t)atoi(data[11].c_str());
    delta_exp = (int32_t)atoi(data[12].c_str());
    create_time = (int32_t)atoi(data[13].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_skill::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_buddy_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_skill_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_skill::sql_data(char* buf,int size) const
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
        len =sql_buddy_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_skill_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_sk_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_sk_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_equiped_slot(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_practice_state(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_skill_exp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_add_exp_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_delta_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_expire_count_left(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_delta_exp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_skill::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_skill where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_skill::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_skill set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_skill::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_skill set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_skill::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_skill where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
