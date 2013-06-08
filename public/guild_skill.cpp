#include "guild_skill.h" 

guild_skill::guild_skill()
{
    guild_id = 0;
    skill_id = 0;
    research_level = 0;
    learn_level = 0;
    skill_status = 0;
    time_to_finish_research = 0;
    memset(dirty,1,sizeof(dirty));
}
void guild_skill::load(const char** data)
{
    guild_id = (int32_t)atoi(data[0]);
    skill_id = (int32_t)atoi(data[1]);
    research_level = (int8_t)atoi(data[2]);
    learn_level = (int8_t)atoi(data[3]);
    skill_status = (int8_t)atoi(data[4]);
    time_to_finish_research = (int32_t)atoi(data[5]);
    memset(dirty,0,sizeof(dirty));
}
void guild_skill::load(const vector<string>& data)
{
    guild_id = (int32_t)atoi(data[0].c_str());
    skill_id = (int32_t)atoi(data[1].c_str());
    research_level = (int8_t)atoi(data[2].c_str());
    learn_level = (int8_t)atoi(data[3].c_str());
    skill_status = (int8_t)atoi(data[4].c_str());
    time_to_finish_research = (int32_t)atoi(data[5].c_str());
    memset(dirty,0,sizeof(dirty));
}
int guild_skill::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_guild_id(buf,size);
    buf += len ; size -= len ;
    memcpy(buf," and ",5); buf+= 5 ; size-= 5 ;
    len =sql_skill_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_skill::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_skill_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_research_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_learn_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_skill_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_time_to_finish_research(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int guild_skill::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from guild_skill where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_skill::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into guild_skill set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_skill::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update guild_skill set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int guild_skill::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from guild_skill where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
