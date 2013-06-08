#include "role_wing_spirit_bag.h" 

role_wing_spirit_bag::role_wing_spirit_bag()
{
    role_id = 0;
    spirit_item_id = 0;
    spirit_tid = 0;
    spirit_pos = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_wing_spirit_bag::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    spirit_item_id = (int64_t)atol(data[1]);
    spirit_tid = (int32_t)atoi(data[2]);
    spirit_pos = (int32_t)atoi(data[3]);
    memset(dirty,0,sizeof(dirty));
}
void role_wing_spirit_bag::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    spirit_item_id = (int64_t)atol(data[1].c_str());
    spirit_tid = (int32_t)atoi(data[2].c_str());
    spirit_pos = (int32_t)atoi(data[3].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_wing_spirit_bag::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_spirit_item_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_bag::sql_data(char* buf,int size) const
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
        len =sql_spirit_item_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_spirit_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_spirit_pos(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_wing_spirit_bag::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_wing_spirit_bag where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_bag::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_wing_spirit_bag set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_bag::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_wing_spirit_bag set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_wing_spirit_bag::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_wing_spirit_bag where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
