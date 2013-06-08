#include "alien_boss.h" 

alien_boss::alien_boss()
{
    id = 0;
    last_max_hp = 0;
    last_phy_attack = 0;
    last_mag_attack = 0;
    memset(dirty,1,sizeof(dirty));
}
void alien_boss::load(const char** data)
{
    id = (int32_t)atoi(data[0]);
    last_max_hp = (int32_t)atoi(data[1]);
    last_phy_attack = (int32_t)atoi(data[2]);
    last_mag_attack = (int32_t)atoi(data[3]);
    memset(dirty,0,sizeof(dirty));
}
void alien_boss::load(const vector<string>& data)
{
    id = (int32_t)atoi(data[0].c_str());
    last_max_hp = (int32_t)atoi(data[1].c_str());
    last_phy_attack = (int32_t)atoi(data[2].c_str());
    last_mag_attack = (int32_t)atoi(data[3].c_str());
    memset(dirty,0,sizeof(dirty));
}
int alien_boss::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int alien_boss::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_max_hp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_phy_attack(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_mag_attack(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int alien_boss::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from alien_boss where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int alien_boss::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into alien_boss set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int alien_boss::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update alien_boss set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int alien_boss::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from alien_boss where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
