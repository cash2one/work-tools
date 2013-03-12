#ifndef _generate_h_guild_member 
#define _generate_h_guild_member 
#include "sql_binder.h"
class guild_member : public sql_binder 
{
public:
    guild_member();
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

    int32_t get_role_id() const { return role_id;} ; 
    void set_role_id(int32_t value) { if(role_id!= value){dirty[1] = 1; role_id = value;} } ; 
    int sql_role_id(char* buf,int size) const{return snprintf(buf,size,"role_id='%ld'",(int64_t)role_id);}

    int32_t get_role_tid() const { return role_tid;} ; 
    void set_role_tid(int32_t value) { if(role_tid!= value){dirty[2] = 1; role_tid = value;} } ; 
    int sql_role_tid(char* buf,int size) const{return snprintf(buf,size,"role_tid='%ld'",(int64_t)role_tid);}

    int32_t get_devote() const { return devote;} ; 
    void set_devote(int32_t value) { if(devote!= value){dirty[3] = 1; devote = value;} } ; 
    int sql_devote(char* buf,int size) const{return snprintf(buf,size,"devote='%ld'",(int64_t)devote);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[4] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

    int32_t get_server_id() const { return server_id;} ; 
    void set_server_id(int32_t value) { if(server_id!= value){dirty[5] = 1; server_id = value;} } ; 
    int sql_server_id(char* buf,int size) const{return snprintf(buf,size,"server_id='%ld'",(int64_t)server_id);}

    int8_t get_job_type() const { return job_type;} ; 
    void set_job_type(int8_t value) { if(job_type!= value){dirty[6] = 1; job_type = value;} } ; 
    int sql_job_type(char* buf,int size) const{return snprintf(buf,size,"job_type='%ld'",(int64_t)job_type);}

    int8_t get_job_level() const { return job_level;} ; 
    void set_job_level(int8_t value) { if(job_level!= value){dirty[7] = 1; job_level = value;} } ; 
    int sql_job_level(char* buf,int size) const{return snprintf(buf,size,"job_level='%ld'",(int64_t)job_level);}

    int8_t get_vip_level() const { return vip_level;} ; 
    void set_vip_level(int8_t value) { if(vip_level!= value){dirty[8] = 1; vip_level = value;} } ; 
    int sql_vip_level(char* buf,int size) const{return snprintf(buf,size,"vip_level='%ld'",(int64_t)vip_level);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[9] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    int8_t get_title() const { return title;} ; 
    void set_title(int8_t value) { if(title!= value){dirty[10] = 1; title = value;} } ; 
    int sql_title(char* buf,int size) const{return snprintf(buf,size,"title='%ld'",(int64_t)title);}

    const string& get_role_name() const { return role_name;} ; 
    void set_role_name(const string& value) { if(role_name!= value){dirty[11] = 1; role_name.assign(value);} }; 
    void set_role_name(const char* value) { if(strcmp(role_name.c_str(),value)!=0) {dirty[11] = 1; role_name.assign(value);} }; 
    int sql_role_name(char* buf,int size) const{return snprintf(buf,size,"role_name='%s'",role_name.c_str());}

    int32_t get_login_time() const { return login_time;} ; 
    void set_login_time(int32_t value) { if(login_time!= value){dirty[12] = 1; login_time = value;} } ; 
    int sql_login_time(char* buf,int size) const{return snprintf(buf,size,"login_time='%ld'",(int64_t)login_time);}

    int8_t get_gender() const { return gender;} ; 
    void set_gender(int8_t value) { if(gender!= value){dirty[13] = 1; gender = value;} } ; 
    int sql_gender(char* buf,int size) const{return snprintf(buf,size,"gender='%ld'",(int64_t)gender);}

private:
    //data member
    int32_t guild_id ; 
    int32_t role_id ; 
    int32_t role_tid ; 
    int32_t devote ; 
    int32_t create_time ; 
    int32_t server_id ; 
    int8_t job_type ; 
    int8_t job_level ; 
    int8_t vip_level ; 
    int8_t status ; 
    int8_t title ; 
    string role_name ; 
    int32_t login_time ; 
    int8_t gender ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 14 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
