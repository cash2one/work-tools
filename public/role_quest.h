#ifndef _generate_h_role_quest 
#define _generate_h_role_quest 
#include "sql_binder.h"
class role_quest : public sql_binder 
{
public:
    role_quest();
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

    int32_t get_quest_id() const { return quest_id;} ; 
    void set_quest_id(int32_t value) { if(quest_id!= value){dirty[1] = 1; quest_id = value;} } ; 
    int sql_quest_id(char* buf,int size) const{return snprintf(buf,size,"quest_id='%ld'",(int64_t)quest_id);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[2] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    const string& get_quest_data() const { return quest_data;} ; 
    void set_quest_data(const string& value) { if(quest_data!= value){dirty[3] = 1; quest_data.assign(value);} }; 
    void set_quest_data(const char* value) { if(strcmp(quest_data.c_str(),value)!=0) {dirty[3] = 1; quest_data.assign(value);} }; 
    int sql_quest_data(char* buf,int size) const{return snprintf(buf,size,"quest_data='%s'",quest_data.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t quest_id ; 
    int8_t status ; 
    string quest_data ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 4 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
