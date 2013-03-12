#ifndef _generate_h_role_friend 
#define _generate_h_role_friend 
#include "sql_binder.h"
class role_friend : public sql_binder 
{
public:
    role_friend();
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

    int32_t get_friend_role_id() const { return friend_role_id;} ; 
    void set_friend_role_id(int32_t value) { if(friend_role_id!= value){dirty[1] = 1; friend_role_id = value;} } ; 
    int sql_friend_role_id(char* buf,int size) const{return snprintf(buf,size,"friend_role_id='%ld'",(int64_t)friend_role_id);}

    int32_t get_friend_tid() const { return friend_tid;} ; 
    void set_friend_tid(int32_t value) { if(friend_tid!= value){dirty[2] = 1; friend_tid = value;} } ; 
    int sql_friend_tid(char* buf,int size) const{return snprintf(buf,size,"friend_tid='%ld'",(int64_t)friend_tid);}

    int32_t get_friend_server_id() const { return friend_server_id;} ; 
    void set_friend_server_id(int32_t value) { if(friend_server_id!= value){dirty[3] = 1; friend_server_id = value;} } ; 
    int sql_friend_server_id(char* buf,int size) const{return snprintf(buf,size,"friend_server_id='%ld'",(int64_t)friend_server_id);}

    int8_t get_friend_job_type() const { return friend_job_type;} ; 
    void set_friend_job_type(int8_t value) { if(friend_job_type!= value){dirty[4] = 1; friend_job_type = value;} } ; 
    int sql_friend_job_type(char* buf,int size) const{return snprintf(buf,size,"friend_job_type='%ld'",(int64_t)friend_job_type);}

    int8_t get_friend_role_level() const { return friend_role_level;} ; 
    void set_friend_role_level(int8_t value) { if(friend_role_level!= value){dirty[5] = 1; friend_role_level = value;} } ; 
    int sql_friend_role_level(char* buf,int size) const{return snprintf(buf,size,"friend_role_level='%ld'",(int64_t)friend_role_level);}

    int8_t get_friend_vip_level() const { return friend_vip_level;} ; 
    void set_friend_vip_level(int8_t value) { if(friend_vip_level!= value){dirty[6] = 1; friend_vip_level = value;} } ; 
    int sql_friend_vip_level(char* buf,int size) const{return snprintf(buf,size,"friend_vip_level='%ld'",(int64_t)friend_vip_level);}

    const string& get_friend_name() const { return friend_name;} ; 
    void set_friend_name(const string& value) { if(friend_name!= value){dirty[7] = 1; friend_name.assign(value);} }; 
    void set_friend_name(const char* value) { if(strcmp(friend_name.c_str(),value)!=0) {dirty[7] = 1; friend_name.assign(value);} }; 
    int sql_friend_name(char* buf,int size) const{return snprintf(buf,size,"friend_name='%s'",friend_name.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t friend_role_id ; 
    int32_t friend_tid ; 
    int32_t friend_server_id ; 
    int8_t friend_job_type ; 
    int8_t friend_role_level ; 
    int8_t friend_vip_level ; 
    string friend_name ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 8 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
