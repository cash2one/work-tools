#include "role_buddy.h" 

role_buddy::role_buddy()
{
    role_id = 0;
    buddy_id = 0;
    buddy_type = 0;
    tid = 0;
    max_soul = 0;
    cur_soul = 0;
    cur_spacetime_level = 0;
    bonus_item = 0;
    gender = 0;
    job_type = 0;
    prof_level = 0;
    quality = 0;
    status = 0;
    server_id = 0;
    default_normal_attack = 0;
    default_skill = 0;
    skill_pool_exp = 0;
    create_time = 0;
    fight_capacity = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_buddy::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    buddy_id = (int32_t)atoi(data[1]);
    buddy_type = (int32_t)atoi(data[2]);
    buddy_name.assign(data[3]);
    tid = (int32_t)atoi(data[4]);
    max_soul = (int16_t)atoi(data[5]);
    cur_soul = (int16_t)atoi(data[6]);
    cur_spacetime_level = (int16_t)atoi(data[7]);
    bonus_item = (int16_t)atoi(data[8]);
    gender = (int8_t)atoi(data[9]);
    job_type = (int8_t)atoi(data[10]);
    prof_level = (int8_t)atoi(data[11]);
    quality = (int8_t)atoi(data[12]);
    status = (int8_t)atoi(data[13]);
    server_id = (int32_t)atoi(data[14]);
    default_normal_attack = (int32_t)atoi(data[15]);
    default_skill = (int32_t)atoi(data[16]);
    skill_pool_exp = (int32_t)atoi(data[17]);
    equip_data.assign(data[18]);
    equip_skill_data.assign(data[19]);
    create_time = (int32_t)atoi(data[20]);
    fight_capacity = (int32_t)atoi(data[21]);
    memset(dirty,0,sizeof(dirty));
}
void role_buddy::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    buddy_id = (int32_t)atoi(data[1].c_str());
    buddy_type = (int32_t)atoi(data[2].c_str());
    buddy_name.assign(data[3].c_str());
    tid = (int32_t)atoi(data[4].c_str());
    max_soul = (int16_t)atoi(data[5].c_str());
    cur_soul = (int16_t)atoi(data[6].c_str());
    cur_spacetime_level = (int16_t)atoi(data[7].c_str());
    bonus_item = (int16_t)atoi(data[8].c_str());
    gender = (int8_t)atoi(data[9].c_str());
    job_type = (int8_t)atoi(data[10].c_str());
    prof_level = (int8_t)atoi(data[11].c_str());
    quality = (int8_t)atoi(data[12].c_str());
    status = (int8_t)atoi(data[13].c_str());
    server_id = (int32_t)atoi(data[14].c_str());
    default_normal_attack = (int32_t)atoi(data[15].c_str());
    default_skill = (int32_t)atoi(data[16].c_str());
    skill_pool_exp = (int32_t)atoi(data[17].c_str());
    equip_data.assign(data[18].c_str());
    equip_skill_data.assign(data[19].c_str());
    create_time = (int32_t)atoi(data[20].c_str());
    fight_capacity = (int32_t)atoi(data[21].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_buddy::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_buddy_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_buddy::sql_data(char* buf,int size) const
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
        len =sql_buddy_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buddy_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_max_soul(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_cur_soul(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_cur_spacetime_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_bonus_item(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_gender(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_job_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_prof_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_quality(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[14])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[15])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_default_normal_attack(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[16])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_default_skill(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[17])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_skill_pool_exp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[18])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_equip_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[19])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_equip_skill_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[20])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[21])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_fight_capacity(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_buddy::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_buddy where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_buddy::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_buddy set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_buddy::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_buddy set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_buddy::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_buddy where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
