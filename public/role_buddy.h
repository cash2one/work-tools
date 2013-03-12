#ifndef _generate_h_role_buddy 
#define _generate_h_role_buddy 
#include "sql_binder.h"
class role_buddy : public sql_binder 
{
public:
    role_buddy();
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

    int32_t get_buddy_type() const { return buddy_type;} ; 
    void set_buddy_type(int32_t value) { if(buddy_type!= value){dirty[2] = 1; buddy_type = value;} } ; 
    int sql_buddy_type(char* buf,int size) const{return snprintf(buf,size,"buddy_type='%ld'",(int64_t)buddy_type);}

    const string& get_buddy_name() const { return buddy_name;} ; 
    void set_buddy_name(const string& value) { if(buddy_name!= value){dirty[3] = 1; buddy_name.assign(value);} }; 
    void set_buddy_name(const char* value) { if(strcmp(buddy_name.c_str(),value)!=0) {dirty[3] = 1; buddy_name.assign(value);} }; 
    int sql_buddy_name(char* buf,int size) const{return snprintf(buf,size,"buddy_name='%s'",buddy_name.c_str());}

    int32_t get_tid() const { return tid;} ; 
    void set_tid(int32_t value) { if(tid!= value){dirty[4] = 1; tid = value;} } ; 
    int sql_tid(char* buf,int size) const{return snprintf(buf,size,"tid='%ld'",(int64_t)tid);}

    int16_t get_max_soul() const { return max_soul;} ; 
    void set_max_soul(int16_t value) { if(max_soul!= value){dirty[5] = 1; max_soul = value;} } ; 
    int sql_max_soul(char* buf,int size) const{return snprintf(buf,size,"max_soul='%ld'",(int64_t)max_soul);}

    int16_t get_cur_soul() const { return cur_soul;} ; 
    void set_cur_soul(int16_t value) { if(cur_soul!= value){dirty[6] = 1; cur_soul = value;} } ; 
    int sql_cur_soul(char* buf,int size) const{return snprintf(buf,size,"cur_soul='%ld'",(int64_t)cur_soul);}

    int16_t get_cur_spacetime_level() const { return cur_spacetime_level;} ; 
    void set_cur_spacetime_level(int16_t value) { if(cur_spacetime_level!= value){dirty[7] = 1; cur_spacetime_level = value;} } ; 
    int sql_cur_spacetime_level(char* buf,int size) const{return snprintf(buf,size,"cur_spacetime_level='%ld'",(int64_t)cur_spacetime_level);}

    int16_t get_bonus_item() const { return bonus_item;} ; 
    void set_bonus_item(int16_t value) { if(bonus_item!= value){dirty[8] = 1; bonus_item = value;} } ; 
    int sql_bonus_item(char* buf,int size) const{return snprintf(buf,size,"bonus_item='%ld'",(int64_t)bonus_item);}

    int8_t get_gender() const { return gender;} ; 
    void set_gender(int8_t value) { if(gender!= value){dirty[9] = 1; gender = value;} } ; 
    int sql_gender(char* buf,int size) const{return snprintf(buf,size,"gender='%ld'",(int64_t)gender);}

    int8_t get_job_type() const { return job_type;} ; 
    void set_job_type(int8_t value) { if(job_type!= value){dirty[10] = 1; job_type = value;} } ; 
    int sql_job_type(char* buf,int size) const{return snprintf(buf,size,"job_type='%ld'",(int64_t)job_type);}

    int8_t get_prof_level() const { return prof_level;} ; 
    void set_prof_level(int8_t value) { if(prof_level!= value){dirty[11] = 1; prof_level = value;} } ; 
    int sql_prof_level(char* buf,int size) const{return snprintf(buf,size,"prof_level='%ld'",(int64_t)prof_level);}

    int8_t get_quality() const { return quality;} ; 
    void set_quality(int8_t value) { if(quality!= value){dirty[12] = 1; quality = value;} } ; 
    int sql_quality(char* buf,int size) const{return snprintf(buf,size,"quality='%ld'",(int64_t)quality);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[13] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    int32_t get_server_id() const { return server_id;} ; 
    void set_server_id(int32_t value) { if(server_id!= value){dirty[14] = 1; server_id = value;} } ; 
    int sql_server_id(char* buf,int size) const{return snprintf(buf,size,"server_id='%ld'",(int64_t)server_id);}

    int32_t get_default_normal_attack() const { return default_normal_attack;} ; 
    void set_default_normal_attack(int32_t value) { if(default_normal_attack!= value){dirty[15] = 1; default_normal_attack = value;} } ; 
    int sql_default_normal_attack(char* buf,int size) const{return snprintf(buf,size,"default_normal_attack='%ld'",(int64_t)default_normal_attack);}

    int32_t get_default_skill() const { return default_skill;} ; 
    void set_default_skill(int32_t value) { if(default_skill!= value){dirty[16] = 1; default_skill = value;} } ; 
    int sql_default_skill(char* buf,int size) const{return snprintf(buf,size,"default_skill='%ld'",(int64_t)default_skill);}

    int32_t get_skill_pool_exp() const { return skill_pool_exp;} ; 
    void set_skill_pool_exp(int32_t value) { if(skill_pool_exp!= value){dirty[17] = 1; skill_pool_exp = value;} } ; 
    int sql_skill_pool_exp(char* buf,int size) const{return snprintf(buf,size,"skill_pool_exp='%ld'",(int64_t)skill_pool_exp);}

    const string& get_equip_data() const { return equip_data;} ; 
    void set_equip_data(const string& value) { if(equip_data!= value){dirty[18] = 1; equip_data.assign(value);} }; 
    void set_equip_data(const char* value) { if(strcmp(equip_data.c_str(),value)!=0) {dirty[18] = 1; equip_data.assign(value);} }; 
    int sql_equip_data(char* buf,int size) const{return snprintf(buf,size,"equip_data='%s'",equip_data.c_str());}

    const string& get_equip_skill_data() const { return equip_skill_data;} ; 
    void set_equip_skill_data(const string& value) { if(equip_skill_data!= value){dirty[19] = 1; equip_skill_data.assign(value);} }; 
    void set_equip_skill_data(const char* value) { if(strcmp(equip_skill_data.c_str(),value)!=0) {dirty[19] = 1; equip_skill_data.assign(value);} }; 
    int sql_equip_skill_data(char* buf,int size) const{return snprintf(buf,size,"equip_skill_data='%s'",equip_skill_data.c_str());}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[20] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

    int32_t get_fight_capacity() const { return fight_capacity;} ; 
    void set_fight_capacity(int32_t value) { if(fight_capacity!= value){dirty[21] = 1; fight_capacity = value;} } ; 
    int sql_fight_capacity(char* buf,int size) const{return snprintf(buf,size,"fight_capacity='%ld'",(int64_t)fight_capacity);}

private:
    //data member
    int32_t role_id ; 
    int32_t buddy_id ; 
    int32_t buddy_type ; 
    string buddy_name ; 
    int32_t tid ; 
    int16_t max_soul ; 
    int16_t cur_soul ; 
    int16_t cur_spacetime_level ; 
    int16_t bonus_item ; 
    int8_t gender ; 
    int8_t job_type ; 
    int8_t prof_level ; 
    int8_t quality ; 
    int8_t status ; 
    int32_t server_id ; 
    int32_t default_normal_attack ; 
    int32_t default_skill ; 
    int32_t skill_pool_exp ; 
    string equip_data ; 
    string equip_skill_data ; 
    int32_t create_time ; 
    int32_t fight_capacity ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 22 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
