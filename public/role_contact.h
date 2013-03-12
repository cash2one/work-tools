#ifndef _generate_h_role_contact 
#define _generate_h_role_contact 
#include "sql_binder.h"
class role_contact : public sql_binder 
{
public:
    role_contact();
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

    int32_t get_dst_role_id() const { return dst_role_id;} ; 
    void set_dst_role_id(int32_t value) { if(dst_role_id!= value){dirty[1] = 1; dst_role_id = value;} } ; 
    int sql_dst_role_id(char* buf,int size) const{return snprintf(buf,size,"dst_role_id='%ld'",(int64_t)dst_role_id);}

    int32_t get_dst_tid() const { return dst_tid;} ; 
    void set_dst_tid(int32_t value) { if(dst_tid!= value){dirty[2] = 1; dst_tid = value;} } ; 
    int sql_dst_tid(char* buf,int size) const{return snprintf(buf,size,"dst_tid='%ld'",(int64_t)dst_tid);}

    int32_t get_update_time() const { return update_time;} ; 
    void set_update_time(int32_t value) { if(update_time!= value){dirty[3] = 1; update_time = value;} } ; 
    int sql_update_time(char* buf,int size) const{return snprintf(buf,size,"update_time='%ld'",(int64_t)update_time);}

    const string& get_dst_name() const { return dst_name;} ; 
    void set_dst_name(const string& value) { if(dst_name!= value){dirty[4] = 1; dst_name.assign(value);} }; 
    void set_dst_name(const char* value) { if(strcmp(dst_name.c_str(),value)!=0) {dirty[4] = 1; dst_name.assign(value);} }; 
    int sql_dst_name(char* buf,int size) const{return snprintf(buf,size,"dst_name='%s'",dst_name.c_str());}

    int32_t get_dst_server_id() const { return dst_server_id;} ; 
    void set_dst_server_id(int32_t value) { if(dst_server_id!= value){dirty[5] = 1; dst_server_id = value;} } ; 
    int sql_dst_server_id(char* buf,int size) const{return snprintf(buf,size,"dst_server_id='%ld'",(int64_t)dst_server_id);}

    int8_t get_dst_job_type() const { return dst_job_type;} ; 
    void set_dst_job_type(int8_t value) { if(dst_job_type!= value){dirty[6] = 1; dst_job_type = value;} } ; 
    int sql_dst_job_type(char* buf,int size) const{return snprintf(buf,size,"dst_job_type='%ld'",(int64_t)dst_job_type);}

    int8_t get_dst_role_level() const { return dst_role_level;} ; 
    void set_dst_role_level(int8_t value) { if(dst_role_level!= value){dirty[7] = 1; dst_role_level = value;} } ; 
    int sql_dst_role_level(char* buf,int size) const{return snprintf(buf,size,"dst_role_level='%ld'",(int64_t)dst_role_level);}

    int8_t get_dst_vip_level() const { return dst_vip_level;} ; 
    void set_dst_vip_level(int8_t value) { if(dst_vip_level!= value){dirty[8] = 1; dst_vip_level = value;} } ; 
    int sql_dst_vip_level(char* buf,int size) const{return snprintf(buf,size,"dst_vip_level='%ld'",(int64_t)dst_vip_level);}

private:
    //data member
    int32_t role_id ; 
    int32_t dst_role_id ; 
    int32_t dst_tid ; 
    int32_t update_time ; 
    string dst_name ; 
    int32_t dst_server_id ; 
    int8_t dst_job_type ; 
    int8_t dst_role_level ; 
    int8_t dst_vip_level ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 9 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
