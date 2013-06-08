#ifndef _generate_h_guild_skill 
#define _generate_h_guild_skill 
#include "sql_binder.h"
class guild_skill : public sql_binder 
{
public:
    guild_skill();
    void clear_dirty(){ memset(dirty,0,sizeof(dirty)); } ;
    bool is_dirty() const
    {
        for(int i=0;i<FIELD_COUNT;++i) {if(dirty[i]) return true;} ;
        return false ;
    } ;
    void load(const char** data);
    void load(const vector<string>& data);
    int sql_insert(char* buf,int size) const;
    int sql_update(char* buf,int size) const;
    int sql_query(char* buf,int size) const;
    int sql_delete(char* buf,int size) const;
protected:
    int sql_key(char* buf,int size) const;
    int sql_data(char* buf,int size) const;
public:
    int32_t get_guild_id() const { return guild_id;} ; 
    void set_guild_id(int32_t value) { if(guild_id!= value){dirty[0] = 1; guild_id = value;} } ; 
    int sql_guild_id(char* buf,int size) const{return snprintf(buf,size,"guild_id='%ld'",(int64_t)guild_id);}

    int32_t get_skill_id() const { return skill_id;} ; 
    void set_skill_id(int32_t value) { if(skill_id!= value){dirty[1] = 1; skill_id = value;} } ; 
    int sql_skill_id(char* buf,int size) const{return snprintf(buf,size,"skill_id='%ld'",(int64_t)skill_id);}

    int8_t get_research_level() const { return research_level;} ; 
    void set_research_level(int8_t value) { if(research_level!= value){dirty[2] = 1; research_level = value;} } ; 
    int sql_research_level(char* buf,int size) const{return snprintf(buf,size,"research_level='%ld'",(int64_t)research_level);}

    int8_t get_learn_level() const { return learn_level;} ; 
    void set_learn_level(int8_t value) { if(learn_level!= value){dirty[3] = 1; learn_level = value;} } ; 
    int sql_learn_level(char* buf,int size) const{return snprintf(buf,size,"learn_level='%ld'",(int64_t)learn_level);}

    int8_t get_skill_status() const { return skill_status;} ; 
    void set_skill_status(int8_t value) { if(skill_status!= value){dirty[4] = 1; skill_status = value;} } ; 
    int sql_skill_status(char* buf,int size) const{return snprintf(buf,size,"skill_status='%ld'",(int64_t)skill_status);}

    int32_t get_time_to_finish_research() const { return time_to_finish_research;} ; 
    void set_time_to_finish_research(int32_t value) { if(time_to_finish_research!= value){dirty[5] = 1; time_to_finish_research = value;} } ; 
    int sql_time_to_finish_research(char* buf,int size) const{return snprintf(buf,size,"time_to_finish_research='%ld'",(int64_t)time_to_finish_research);}

private:
    //data member
    int32_t guild_id ; 
    int32_t skill_id ; 
    int8_t research_level ; 
    int8_t learn_level ; 
    int8_t skill_status ; 
    int32_t time_to_finish_research ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 6 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
