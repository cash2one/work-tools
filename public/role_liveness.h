#ifndef _generate_h_role_liveness 
#define _generate_h_role_liveness 
#include "sql_binder.h"
class role_liveness : public sql_binder 
{
public:
    role_liveness();
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

    int32_t get_liveness_total() const { return liveness_total;} ; 
    void set_liveness_total(int32_t value) { if(liveness_total!= value){dirty[1] = 1; liveness_total = value;} } ; 
    int sql_liveness_total(char* buf,int size) const{return snprintf(buf,size,"liveness_total='%ld'",(int64_t)liveness_total);}

    int32_t get_update_time() const { return update_time;} ; 
    void set_update_time(int32_t value) { if(update_time!= value){dirty[2] = 1; update_time = value;} } ; 
    int sql_update_time(char* buf,int size) const{return snprintf(buf,size,"update_time='%ld'",(int64_t)update_time);}

    const string& get_cond_data() const { return cond_data;} ; 
    void set_cond_data(const string& value) { if(cond_data!= value){dirty[3] = 1; cond_data.assign(value);} }; 
    void set_cond_data(const char* value) { if(strcmp(cond_data.c_str(),value)!=0) {dirty[3] = 1; cond_data.assign(value);} }; 
    int sql_cond_data(char* buf,int size) const{return snprintf(buf,size,"cond_data='%s'",cond_data.c_str());}

    const string& get_award_data() const { return award_data;} ; 
    void set_award_data(const string& value) { if(award_data!= value){dirty[4] = 1; award_data.assign(value);} }; 
    void set_award_data(const char* value) { if(strcmp(award_data.c_str(),value)!=0) {dirty[4] = 1; award_data.assign(value);} }; 
    int sql_award_data(char* buf,int size) const{return snprintf(buf,size,"award_data='%s'",award_data.c_str());}

    const string& get_config_data() const { return config_data;} ; 
    void set_config_data(const string& value) { if(config_data!= value){dirty[5] = 1; config_data.assign(value);} }; 
    void set_config_data(const char* value) { if(strcmp(config_data.c_str(),value)!=0) {dirty[5] = 1; config_data.assign(value);} }; 
    int sql_config_data(char* buf,int size) const{return snprintf(buf,size,"config_data='%s'",config_data.c_str());}

    const string& get_contact_data() const { return contact_data;} ; 
    void set_contact_data(const string& value) { if(contact_data!= value){dirty[6] = 1; contact_data.assign(value);} }; 
    void set_contact_data(const char* value) { if(strcmp(contact_data.c_str(),value)!=0) {dirty[6] = 1; contact_data.assign(value);} }; 
    int sql_contact_data(char* buf,int size) const{return snprintf(buf,size,"contact_data='%s'",contact_data.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t liveness_total ; 
    int32_t update_time ; 
    string cond_data ; 
    string award_data ; 
    string config_data ; 
    string contact_data ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 7 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
