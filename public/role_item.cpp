#include "role_item.h" 

role_item::role_item()
{
    item_id = 0;
    role_id = 0;
    tid = 0;
    item_type = 0;
    expired = 0;
    count = 0;
    pos_value = 0;
    pos_type = 0;
    bind_flag = 0;
    stack_flag = 0;
    create_time = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_item::load(const char** data)
{
    item_id = (int64_t)atol(data[0]);
    role_id = (int32_t)atoi(data[1]);
    tid = (int32_t)atoi(data[2]);
    item_type = (int32_t)atoi(data[3]);
    expired = (int32_t)atoi(data[4]);
    count = (int16_t)atoi(data[5]);
    pos_value = (int16_t)atoi(data[6]);
    pos_type = (int8_t)atoi(data[7]);
    bind_flag = (int8_t)atoi(data[8]);
    stack_flag = (int8_t)atoi(data[9]);
    create_time = (int32_t)atoi(data[10]);
    memset(dirty,0,sizeof(dirty));
}
void role_item::load(const vector<string>& data)
{
    item_id = (int64_t)atol(data[0].c_str());
    role_id = (int32_t)atoi(data[1].c_str());
    tid = (int32_t)atoi(data[2].c_str());
    item_type = (int32_t)atoi(data[3].c_str());
    expired = (int32_t)atoi(data[4].c_str());
    count = (int16_t)atoi(data[5].c_str());
    pos_value = (int16_t)atoi(data[6].c_str());
    pos_type = (int8_t)atoi(data[7].c_str());
    bind_flag = (int8_t)atoi(data[8].c_str());
    stack_flag = (int8_t)atoi(data[9].c_str());
    create_time = (int32_t)atoi(data[10].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_item::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_item_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_item::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_id(buf,size);
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
        len =sql_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_expired(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_pos_value(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_pos_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_bind_flag(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_stack_flag(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_item::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_item where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_item::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_item set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_item::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_item set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_item::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_item where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
