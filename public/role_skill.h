#ifndef _generate_h_role_skill 
#define _generate_h_role_skill 
#include "sql_binder.h"
class role_skill : public sql_binder 
{
public:
    role_skill();
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

    int32_t get_buddy_id() const { return buddy_id;} ; 
    void set_buddy_id(int32_t value) { if(buddy_id!= value){dirty[1] = 1; buddy_id = value;} } ; 
    int sql_buddy_id(char* buf,int size) const{return snprintf(buf,size,"buddy_id='%ld'",(int64_t)buddy_id);}

    int32_t get_skill_id() const { return skill_id;} ; 
    void set_skill_id(int32_t value) { if(skill_id!= value){dirty[2] = 1; skill_id = value;} } ; 
    int sql_skill_id(char* buf,int size) const{return snprintf(buf,size,"skill_id='%ld'",(int64_t)skill_id);}

    int8_t get_sk_type() const { return sk_type;} ; 
    void set_sk_type(int8_t value) { if(sk_type!= value){dirty[3] = 1; sk_type = value;} } ; 
    int sql_sk_type(char* buf,int size) const{return snprintf(buf,size,"sk_type='%ld'",(int64_t)sk_type);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[4] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    int8_t get_sk_level() const { return sk_level;} ; 
    void set_sk_level(int8_t value) { if(sk_level!= value){dirty[5] = 1; sk_level = value;} } ; 
    int sql_sk_level(char* buf,int size) const{return snprintf(buf,size,"sk_level='%ld'",(int64_t)sk_level);}

    int8_t get_equiped_slot() const { return equiped_slot;} ; 
    void set_equiped_slot(int8_t value) { if(equiped_slot!= value){dirty[6] = 1; equiped_slot = value;} } ; 
    int sql_equiped_slot(char* buf,int size) const{return snprintf(buf,size,"equiped_slot='%ld'",(int64_t)equiped_slot);}

    int8_t get_practice_state() const { return practice_state;} ; 
    void set_practice_state(int8_t value) { if(practice_state!= value){dirty[7] = 1; practice_state = value;} } ; 
    int sql_practice_state(char* buf,int size) const{return snprintf(buf,size,"practice_state='%ld'",(int64_t)practice_state);}

    int32_t get_skill_exp() const { return skill_exp;} ; 
    void set_skill_exp(int32_t value) { if(skill_exp!= value){dirty[8] = 1; skill_exp = value;} } ; 
    int sql_skill_exp(char* buf,int size) const{return snprintf(buf,size,"skill_exp='%ld'",(int64_t)skill_exp);}

    int64_t get_last_add_exp_time() const { return last_add_exp_time;} ; 
    void set_last_add_exp_time(int64_t value) { if(last_add_exp_time!= value){dirty[9] = 1; last_add_exp_time = value;} } ; 
    int sql_last_add_exp_time(char* buf,int size) const{return snprintf(buf,size,"last_add_exp_time='%ld'",(int64_t)last_add_exp_time);}

    int32_t get_delta_time() const { return delta_time;} ; 
    void set_delta_time(int32_t value) { if(delta_time!= value){dirty[10] = 1; delta_time = value;} } ; 
    int sql_delta_time(char* buf,int size) const{return snprintf(buf,size,"delta_time='%ld'",(int64_t)delta_time);}

    int32_t get_expire_count_left() const { return expire_count_left;} ; 
    void set_expire_count_left(int32_t value) { if(expire_count_left!= value){dirty[11] = 1; expire_count_left = value;} } ; 
    int sql_expire_count_left(char* buf,int size) const{return snprintf(buf,size,"expire_count_left='%ld'",(int64_t)expire_count_left);}

    int32_t get_delta_exp() const { return delta_exp;} ; 
    void set_delta_exp(int32_t value) { if(delta_exp!= value){dirty[12] = 1; delta_exp = value;} } ; 
    int sql_delta_exp(char* buf,int size) const{return snprintf(buf,size,"delta_exp='%ld'",(int64_t)delta_exp);}

    int32_t get_is_used() const { return is_used;} ; 
    void set_is_used(int32_t value) { if(is_used!= value){dirty[13] = 1; is_used = value;} } ; 
    int sql_is_used(char* buf,int size) const{return snprintf(buf,size,"is_used='%ld'",(int64_t)is_used);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[14] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

private:
    //data member
    int32_t role_id ; 
    int32_t buddy_id ; 
    int32_t skill_id ; 
    int8_t sk_type ; 
    int8_t status ; 
    int8_t sk_level ; 
    int8_t equiped_slot ; 
    int8_t practice_state ; 
    int32_t skill_exp ; 
    int64_t last_add_exp_time ; 
    int32_t delta_time ; 
    int32_t expire_count_left ; 
    int32_t delta_exp ; 
    int32_t is_used ; 
    int32_t create_time ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 15 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
