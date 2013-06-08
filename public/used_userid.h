#ifndef _generate_h_used_userid 
#define _generate_h_used_userid 
#include "sql_binder.h"
class used_userid : public sql_binder 
{
public:
    used_userid();
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
    int32_t get_uid() const { return uid;} ; 
    void set_uid(int32_t value) { if(uid!= value){dirty[0] = 1; uid = value;} } ; 
    int sql_uid(char* buf,int size) const{return snprintf(buf,size,"uid='%ld'",(int64_t)uid);}

    int32_t get_server_id() const { return server_id;} ; 
    void set_server_id(int32_t value) { if(server_id!= value){dirty[1] = 1; server_id = value;} } ; 
    int sql_server_id(char* buf,int size) const{return snprintf(buf,size,"server_id='%ld'",(int64_t)server_id);}

    int32_t get_role_id() const { return role_id;} ; 
    void set_role_id(int32_t value) { if(role_id!= value){dirty[2] = 1; role_id = value;} } ; 
    int sql_role_id(char* buf,int size) const{return snprintf(buf,size,"role_id='%ld'",(int64_t)role_id);}

    int32_t get_status() const { return status;} ; 
    void set_status(int32_t value) { if(status!= value){dirty[3] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    const string& get_name() const { return name;} ; 
    void set_name(const string& value) { if(name!= value){dirty[4] = 1; name.assign(value);} }; 
    void set_name(const char* value) { if(strcmp(name.c_str(),value)!=0) {dirty[4] = 1; name.assign(value);} }; 
    int sql_name(char* buf,int size) const{return snprintf(buf,size,"name='%s'",name.c_str());}

private:
    //data member
    int32_t uid ; 
    int32_t server_id ; 
    int32_t role_id ; 
    int32_t status ; 
    string name ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 5 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
