#ifndef _generate_h_role_instance 
#define _generate_h_role_instance 
#include "sql_binder.h"
class role_instance : public sql_binder 
{
public:
    role_instance();
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

    int32_t get_instance_id() const { return instance_id;} ; 
    void set_instance_id(int32_t value) { if(instance_id!= value){dirty[1] = 1; instance_id = value;} } ; 
    int sql_instance_id(char* buf,int size) const{return snprintf(buf,size,"instance_id='%ld'",(int64_t)instance_id);}

    int32_t get_grade() const { return grade;} ; 
    void set_grade(int32_t value) { if(grade!= value){dirty[2] = 1; grade = value;} } ; 
    int sql_grade(char* buf,int size) const{return snprintf(buf,size,"grade='%ld'",(int64_t)grade);}

    int32_t get_update_time() const { return update_time;} ; 
    void set_update_time(int32_t value) { if(update_time!= value){dirty[3] = 1; update_time = value;} } ; 
    int sql_update_time(char* buf,int size) const{return snprintf(buf,size,"update_time='%ld'",(int64_t)update_time);}

    int32_t get_left_wanted_time() const { return left_wanted_time;} ; 
    void set_left_wanted_time(int32_t value) { if(left_wanted_time!= value){dirty[4] = 1; left_wanted_time = value;} } ; 
    int sql_left_wanted_time(char* buf,int size) const{return snprintf(buf,size,"left_wanted_time='%ld'",(int64_t)left_wanted_time);}

    const string& get_card_info() const { return card_info;} ; 
    void set_card_info(const string& value) { if(card_info!= value){dirty[5] = 1; card_info.assign(value);} }; 
    void set_card_info(const char* value) { if(strcmp(card_info.c_str(),value)!=0) {dirty[5] = 1; card_info.assign(value);} }; 
    int sql_card_info(char* buf,int size) const{return snprintf(buf,size,"card_info='%s'",card_info.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t instance_id ; 
    int32_t grade ; 
    int32_t update_time ; 
    int32_t left_wanted_time ; 
    string card_info ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 6 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
