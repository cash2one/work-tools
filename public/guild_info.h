#ifndef _generate_h_guild_info 
#define _generate_h_guild_info 
#include "sql_binder.h"
class guild_info : public sql_binder 
{
public:
    guild_info();
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

    int32_t get_leader_id() const { return leader_id;} ; 
    void set_leader_id(int32_t value) { if(leader_id!= value){dirty[1] = 1; leader_id = value;} } ; 
    int sql_leader_id(char* buf,int size) const{return snprintf(buf,size,"leader_id='%ld'",(int64_t)leader_id);}

    int32_t get_leader_tid() const { return leader_tid;} ; 
    void set_leader_tid(int32_t value) { if(leader_tid!= value){dirty[2] = 1; leader_tid = value;} } ; 
    int sql_leader_tid(char* buf,int size) const{return snprintf(buf,size,"leader_tid='%ld'",(int64_t)leader_tid);}

    int32_t get_money() const { return money;} ; 
    void set_money(int32_t value) { if(money!= value){dirty[3] = 1; money = value;} } ; 
    int sql_money(char* buf,int size) const{return snprintf(buf,size,"money='%ld'",(int64_t)money);}

    int32_t get_exp() const { return exp;} ; 
    void set_exp(int32_t value) { if(exp!= value){dirty[4] = 1; exp = value;} } ; 
    int sql_exp(char* buf,int size) const{return snprintf(buf,size,"exp='%ld'",(int64_t)exp);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[5] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[6] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    int8_t get_grade() const { return grade;} ; 
    void set_grade(int8_t value) { if(grade!= value){dirty[7] = 1; grade = value;} } ; 
    int sql_grade(char* buf,int size) const{return snprintf(buf,size,"grade='%ld'",(int64_t)grade);}

    int32_t get_leader_server_id() const { return leader_server_id;} ; 
    void set_leader_server_id(int32_t value) { if(leader_server_id!= value){dirty[8] = 1; leader_server_id = value;} } ; 
    int sql_leader_server_id(char* buf,int size) const{return snprintf(buf,size,"leader_server_id='%ld'",(int64_t)leader_server_id);}

    int16_t get_total_member() const { return total_member;} ; 
    void set_total_member(int16_t value) { if(total_member!= value){dirty[9] = 1; total_member = value;} } ; 
    int sql_total_member(char* buf,int size) const{return snprintf(buf,size,"total_member='%ld'",(int64_t)total_member);}

    int16_t get_max_member() const { return max_member;} ; 
    void set_max_member(int16_t value) { if(max_member!= value){dirty[10] = 1; max_member = value;} } ; 
    int sql_max_member(char* buf,int size) const{return snprintf(buf,size,"max_member='%ld'",(int64_t)max_member);}

    const string& get_leader_name() const { return leader_name;} ; 
    void set_leader_name(const string& value) { if(leader_name!= value){dirty[11] = 1; leader_name.assign(value);} }; 
    void set_leader_name(const char* value) { if(strcmp(leader_name.c_str(),value)!=0) {dirty[11] = 1; leader_name.assign(value);} }; 
    int sql_leader_name(char* buf,int size) const{return snprintf(buf,size,"leader_name='%s'",leader_name.c_str());}

    const string& get_guild_name() const { return guild_name;} ; 
    void set_guild_name(const string& value) { if(guild_name!= value){dirty[12] = 1; guild_name.assign(value);} }; 
    void set_guild_name(const char* value) { if(strcmp(guild_name.c_str(),value)!=0) {dirty[12] = 1; guild_name.assign(value);} }; 
    int sql_guild_name(char* buf,int size) const{return snprintf(buf,size,"guild_name='%s'",guild_name.c_str());}

    const string& get_notice() const { return notice;} ; 
    void set_notice(const string& value) { if(notice!= value){dirty[13] = 1; notice.assign(value);} }; 
    void set_notice(const char* value) { if(strcmp(notice.c_str(),value)!=0) {dirty[13] = 1; notice.assign(value);} }; 
    int sql_notice(char* buf,int size) const{return snprintf(buf,size,"notice='%s'",notice.c_str());}

private:
    //data member
    int32_t guild_id ; 
    int32_t leader_id ; 
    int32_t leader_tid ; 
    int32_t money ; 
    int32_t exp ; 
    int32_t create_time ; 
    int8_t status ; 
    int8_t grade ; 
    int32_t leader_server_id ; 
    int16_t total_member ; 
    int16_t max_member ; 
    string leader_name ; 
    string guild_name ; 
    string notice ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 14 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
