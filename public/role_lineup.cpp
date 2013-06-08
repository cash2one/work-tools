#include "role_lineup.h" 

role_lineup::role_lineup()
{
    role_id = 0;
    lineup_id = 0;
    battle_skill_1 = 0;
    battle_skill_2 = 0;
    status = 0;
    create_time = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_lineup::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    lineup_id = (int32_t)atoi(data[1]);
    battle_skill_1 = (int32_t)atoi(data[2]);
    battle_skill_2 = (int32_t)atoi(data[3]);
    status = (int8_t)atoi(data[4]);
    lineup_name.assign(data[5]);
    pos_data.assign(data[6]);
    create_time = (int32_t)atoi(data[7]);
    memset(dirty,0,sizeof(dirty));
}
void role_lineup::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    lineup_id = (int32_t)atoi(data[1].c_str());
    battle_skill_1 = (int32_t)atoi(data[2].c_str());
    battle_skill_2 = (int32_t)atoi(data[3].c_str());
    status = (int8_t)atoi(data[4].c_str());
    lineup_name.assign(data[5].c_str());
    pos_data.assign(data[6].c_str());
    create_time = (int32_t)atoi(data[7].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_lineup::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_lineup_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_lineup::sql_data(char* buf,int size) const
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
        len =sql_lineup_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_battle_skill_1(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_battle_skill_2(buf,size);
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
        len =sql_lineup_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_pos_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_lineup::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_lineup where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_lineup::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_lineup set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_lineup::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_lineup set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_lineup::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_lineup where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
