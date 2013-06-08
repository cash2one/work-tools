#include "role_wing_item_info.h" 

role_wing_item_info::role_wing_item_info()
{
    role_id = 0;
    wing_item_id = 0;
    slot_1 = 0;
    slot_2 = 0;
    slot_3 = 0;
    slot_4 = 0;
    slot_5 = 0;
    slot_6 = 0;
    slot_7 = 0;
    slot_8 = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_wing_item_info::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    wing_item_id = (int64_t)atol(data[1]);
    slot_1 = (int64_t)atol(data[2]);
    slot_2 = (int64_t)atol(data[3]);
    slot_3 = (int64_t)atol(data[4]);
    slot_4 = (int64_t)atol(data[5]);
    slot_5 = (int64_t)atol(data[6]);
    slot_6 = (int64_t)atol(data[7]);
    slot_7 = (int64_t)atol(data[8]);
    slot_8 = (int64_t)atol(data[9]);
    memset(dirty,0,sizeof(dirty));
}
void role_wing_item_info::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    wing_item_id = (int64_t)atol(data[1].c_str());
    slot_1 = (int64_t)atol(data[2].c_str());
    slot_2 = (int64_t)atol(data[3].c_str());
    slot_3 = (int64_t)atol(data[4].c_str());
    slot_4 = (int64_t)atol(data[5].c_str());
    slot_5 = (int64_t)atol(data[6].c_str());
    slot_6 = (int64_t)atol(data[7].c_str());
    slot_7 = (int64_t)atol(data[8].c_str());
    slot_8 = (int64_t)atol(data[9].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_wing_item_info::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_wing_item_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_item_info::sql_data(char* buf,int size) const
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
        len =sql_wing_item_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_1(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_2(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_3(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_4(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_5(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_6(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_7(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_8(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_wing_item_info::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_wing_item_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_item_info::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_wing_item_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_item_info::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_wing_item_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_item_info::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_wing_item_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
