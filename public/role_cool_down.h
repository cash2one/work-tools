#ifndef _generate_h_role_cool_down 
#define _generate_h_role_cool_down 
#include "sql_binder.h"
class role_cool_down : public sql_binder 
{
public:
    role_cool_down();
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
    int32_t get_role_id() const { return role_id;} ; 
    void set_role_id(int32_t value) { if(role_id!= value){dirty[0] = 1; role_id = value;} } ; 
    int sql_role_id(char* buf,int size) const{return snprintf(buf,size,"role_id='%ld'",(int64_t)role_id);}

    const string& get_cool_down() const { return cool_down;} ; 
    void set_cool_down(const string& value) { if(cool_down!= value){dirty[1] = 1; cool_down.assign(value);} }; 
    void set_cool_down(const char* value) { if(strcmp(cool_down.c_str(),value)!=0) {dirty[1] = 1; cool_down.assign(value);} }; 
    int sql_cool_down(char* buf,int size) const{return snprintf(buf,size,"cool_down='%s'",cool_down.c_str());}

private:
    //data member
    int32_t role_id ; 
    string cool_down ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 2 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
