#ifndef _generate_h_role_title 
#define _generate_h_role_title 
#include "sql_binder.h"
class role_title : public sql_binder 
{
public:
    role_title();
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
    int32_t get_title_id() const { return title_id;} ; 
    void set_title_id(int32_t value) { if(title_id!= value){dirty[0] = 1; title_id = value;} } ; 
    int sql_title_id(char* buf,int size) const{return snprintf(buf,size,"title_id='%ld'",(int64_t)title_id);}

    int32_t get_role_id() const { return role_id;} ; 
    void set_role_id(int32_t value) { if(role_id!= value){dirty[1] = 1; role_id = value;} } ; 
    int sql_role_id(char* buf,int size) const{return snprintf(buf,size,"role_id='%ld'",(int64_t)role_id);}

    int32_t get_guild_id() const { return guild_id;} ; 
    void set_guild_id(int32_t value) { if(guild_id!= value){dirty[2] = 1; guild_id = value;} } ; 
    int sql_guild_id(char* buf,int size) const{return snprintf(buf,size,"guild_id='%ld'",(int64_t)guild_id);}

private:
    //data member
    int32_t title_id ; 
    int32_t role_id ; 
    int32_t guild_id ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 3 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
