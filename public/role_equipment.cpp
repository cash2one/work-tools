#include "role_equipment.h" 

role_equipment::role_equipment()
{
    item_id = 0;
    role_id = 0;
    tid = 0;
    bind_flag = 0;
    slot_count = 0;
    strength_level = 0;
    create_time = 0;
    mark = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_equipment::load(const char** data)
{
    item_id = (int64_t)atol(data[0]);
    role_id = (int32_t)atoi(data[1]);
    tid = (int32_t)atoi(data[2]);
    bind_flag = (int8_t)atoi(data[3]);
    slot_count = (int8_t)atoi(data[4]);
    strength_level = (int8_t)atoi(data[5]);
    base_attr_data.assign(data[6]);
    extra_attr_data.assign(data[7]);
    strength_attr_data.assign(data[8]);
    slot_data.assign(data[9]);
    create_time = (int32_t)atoi(data[10]);
    mark = (int32_t)atoi(data[11]);
    db_stone_data.assign(data[12]);
    memset(dirty,0,sizeof(dirty));
}
void role_equipment::load(const vector<string>& data)
{
    item_id = (int64_t)atol(data[0].c_str());
    role_id = (int32_t)atoi(data[1].c_str());
    tid = (int32_t)atoi(data[2].c_str());
    bind_flag = (int8_t)atoi(data[3].c_str());
    slot_count = (int8_t)atoi(data[4].c_str());
    strength_level = (int8_t)atoi(data[5].c_str());
    base_attr_data.assign(data[6].c_str());
    extra_attr_data.assign(data[7].c_str());
    strength_attr_data.assign(data[8].c_str());
    slot_data.assign(data[9].c_str());
    create_time = (int32_t)atoi(data[10].c_str());
    mark = (int32_t)atoi(data[11].c_str());
    db_stone_data.assign(data[12].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_equipment::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_item_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_equipment::sql_data(char* buf,int size) const
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
        len =sql_bind_flag(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_strength_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_base_attr_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_extra_attr_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_strength_attr_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_slot_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_mark(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_db_stone_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_equipment::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_equipment where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_equipment::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_equipment set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_equipment::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_equipment set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_equipment::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_equipment where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
