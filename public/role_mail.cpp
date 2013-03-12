#include "role_mail.h" 

role_mail::role_mail()
{
    role_id = 0;
    mail_id = 0;
    src_role_id = 0;
    create_time = 0;
    status = 0;
    attach_flag = 0;
    item_0_tid = 0;
    item_0_count = 0;
    item_1_tid = 0;
    item_1_count = 0;
    item_2_tid = 0;
    item_2_count = 0;
    item_3_tid = 0;
    item_3_count = 0;
    coin = 0;
    coupon = 0;
    diamond = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_mail::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    mail_id = (int32_t)atoi(data[1]);
    src_role_id = (int32_t)atoi(data[2]);
    create_time = (int32_t)atoi(data[3]);
    status = (int8_t)atoi(data[4]);
    attach_flag = (int8_t)atoi(data[5]);
    item_0_tid = (int32_t)atoi(data[6]);
    item_0_count = (int32_t)atoi(data[7]);
    item_1_tid = (int32_t)atoi(data[8]);
    item_1_count = (int32_t)atoi(data[9]);
    item_2_tid = (int32_t)atoi(data[10]);
    item_2_count = (int32_t)atoi(data[11]);
    item_3_tid = (int32_t)atoi(data[12]);
    item_3_count = (int32_t)atoi(data[13]);
    coin = (int32_t)atoi(data[14]);
    coupon = (int32_t)atoi(data[15]);
    diamond = (int32_t)atoi(data[16]);
    src_name.assign(data[17]);
    title.assign(data[18]);
    content.assign(data[19]);
    attach_data.assign(data[20]);
    memset(dirty,0,sizeof(dirty));
}
void role_mail::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    mail_id = (int32_t)atoi(data[1].c_str());
    src_role_id = (int32_t)atoi(data[2].c_str());
    create_time = (int32_t)atoi(data[3].c_str());
    status = (int8_t)atoi(data[4].c_str());
    attach_flag = (int8_t)atoi(data[5].c_str());
    item_0_tid = (int32_t)atoi(data[6].c_str());
    item_0_count = (int32_t)atoi(data[7].c_str());
    item_1_tid = (int32_t)atoi(data[8].c_str());
    item_1_count = (int32_t)atoi(data[9].c_str());
    item_2_tid = (int32_t)atoi(data[10].c_str());
    item_2_count = (int32_t)atoi(data[11].c_str());
    item_3_tid = (int32_t)atoi(data[12].c_str());
    item_3_count = (int32_t)atoi(data[13].c_str());
    coin = (int32_t)atoi(data[14].c_str());
    coupon = (int32_t)atoi(data[15].c_str());
    diamond = (int32_t)atoi(data[16].c_str());
    src_name.assign(data[17].c_str());
    title.assign(data[18].c_str());
    content.assign(data[19].c_str());
    attach_data.assign(data[20].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_mail::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_mail_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_mail::sql_data(char* buf,int size) const
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
        len =sql_mail_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_src_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
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
        len =sql_attach_flag(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_0_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_0_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_1_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_1_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_2_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_2_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_3_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_item_3_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[14])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_coin(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[15])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_coupon(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[16])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_diamond(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[17])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_src_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[18])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_title(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[19])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_content(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[20])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_attach_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_mail::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_mail where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_mail::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_mail set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_mail::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_mail set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_mail::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_mail where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
