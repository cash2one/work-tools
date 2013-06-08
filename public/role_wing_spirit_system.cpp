#include "role_wing_spirit_system.h" 

role_wing_spirit_system::role_wing_spirit_system()
{
    role_id = 0;
    bag_open_slot_num = 0;
    fragment_num = 0;
    money_spent = 0;
    magic_effected = 0;
    first_level_1 = 0;
    first_level_2 = 0;
    first_level_3 = 0;
    first_level_4 = 0;
    first_level_5 = 0;
    level_1 = 0;
    level_2 = 0;
    level_3 = 0;
    level_4 = 0;
    level_5 = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_wing_spirit_system::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    bag_open_slot_num = (int32_t)atoi(data[1]);
    fragment_num = (int64_t)atol(data[2]);
    money_spent = (int64_t)atol(data[3]);
    magic_effected = (int8_t)atoi(data[4]);
    first_level_1 = (int8_t)atoi(data[5]);
    first_level_2 = (int8_t)atoi(data[6]);
    first_level_3 = (int8_t)atoi(data[7]);
    first_level_4 = (int8_t)atoi(data[8]);
    first_level_5 = (int8_t)atoi(data[9]);
    level_1 = (int8_t)atoi(data[10]);
    level_2 = (int8_t)atoi(data[11]);
    level_3 = (int8_t)atoi(data[12]);
    level_4 = (int8_t)atoi(data[13]);
    level_5 = (int8_t)atoi(data[14]);
    memset(dirty,0,sizeof(dirty));
}
void role_wing_spirit_system::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    bag_open_slot_num = (int32_t)atoi(data[1].c_str());
    fragment_num = (int64_t)atol(data[2].c_str());
    money_spent = (int64_t)atol(data[3].c_str());
    magic_effected = (int8_t)atoi(data[4].c_str());
    first_level_1 = (int8_t)atoi(data[5].c_str());
    first_level_2 = (int8_t)atoi(data[6].c_str());
    first_level_3 = (int8_t)atoi(data[7].c_str());
    first_level_4 = (int8_t)atoi(data[8].c_str());
    first_level_5 = (int8_t)atoi(data[9].c_str());
    level_1 = (int8_t)atoi(data[10].c_str());
    level_2 = (int8_t)atoi(data[11].c_str());
    level_3 = (int8_t)atoi(data[12].c_str());
    level_4 = (int8_t)atoi(data[13].c_str());
    level_5 = (int8_t)atoi(data[14].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_wing_spirit_system::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_system::sql_data(char* buf,int size) const
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
        len =sql_bag_open_slot_num(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_fragment_num(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_money_spent(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_magic_effected(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_first_level_1(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_first_level_2(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_first_level_3(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_first_level_4(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_first_level_5(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_level_1(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_level_2(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_level_3(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_level_4(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[14])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_level_5(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_wing_spirit_system::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_wing_spirit_system where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_system::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_wing_spirit_system set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_system::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_wing_spirit_system set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_system::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_wing_spirit_system where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
