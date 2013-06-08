#ifndef _generate_h_role_equipment 
#define _generate_h_role_equipment 
#include "sql_binder.h"
class role_equipment : public sql_binder 
{
public:
    role_equipment();
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
    int64_t get_item_id() const { return item_id;} ; 
    void set_item_id(int64_t value) { if(item_id!= value){dirty[0] = 1; item_id = value;} } ; 
    int sql_item_id(char* buf,int size) const{return snprintf(buf,size,"item_id='%ld'",(int64_t)item_id);}

    int32_t get_role_id() const { return role_id;} ; 
    void set_role_id(int32_t value) { if(role_id!= value){dirty[1] = 1; role_id = value;} } ; 
    int sql_role_id(char* buf,int size) const{return snprintf(buf,size,"role_id='%ld'",(int64_t)role_id);}

    int32_t get_tid() const { return tid;} ; 
    void set_tid(int32_t value) { if(tid!= value){dirty[2] = 1; tid = value;} } ; 
    int sql_tid(char* buf,int size) const{return snprintf(buf,size,"tid='%ld'",(int64_t)tid);}

    int8_t get_bind_flag() const { return bind_flag;} ; 
    void set_bind_flag(int8_t value) { if(bind_flag!= value){dirty[3] = 1; bind_flag = value;} } ; 
    int sql_bind_flag(char* buf,int size) const{return snprintf(buf,size,"bind_flag='%ld'",(int64_t)bind_flag);}

    int8_t get_slot_count() const { return slot_count;} ; 
    void set_slot_count(int8_t value) { if(slot_count!= value){dirty[4] = 1; slot_count = value;} } ; 
    int sql_slot_count(char* buf,int size) const{return snprintf(buf,size,"slot_count='%ld'",(int64_t)slot_count);}

    int8_t get_strength_level() const { return strength_level;} ; 
    void set_strength_level(int8_t value) { if(strength_level!= value){dirty[5] = 1; strength_level = value;} } ; 
    int sql_strength_level(char* buf,int size) const{return snprintf(buf,size,"strength_level='%ld'",(int64_t)strength_level);}

    const string& get_base_attr_data() const { return base_attr_data;} ; 
    void set_base_attr_data(const string& value) { if(base_attr_data!= value){dirty[6] = 1; base_attr_data.assign(value);} }; 
    void set_base_attr_data(const char* value) { if(strcmp(base_attr_data.c_str(),value)!=0) {dirty[6] = 1; base_attr_data.assign(value);} }; 
    int sql_base_attr_data(char* buf,int size) const{return snprintf(buf,size,"base_attr_data='%s'",base_attr_data.c_str());}

    const string& get_extra_attr_data() const { return extra_attr_data;} ; 
    void set_extra_attr_data(const string& value) { if(extra_attr_data!= value){dirty[7] = 1; extra_attr_data.assign(value);} }; 
    void set_extra_attr_data(const char* value) { if(strcmp(extra_attr_data.c_str(),value)!=0) {dirty[7] = 1; extra_attr_data.assign(value);} }; 
    int sql_extra_attr_data(char* buf,int size) const{return snprintf(buf,size,"extra_attr_data='%s'",extra_attr_data.c_str());}

    const string& get_strength_attr_data() const { return strength_attr_data;} ; 
    void set_strength_attr_data(const string& value) { if(strength_attr_data!= value){dirty[8] = 1; strength_attr_data.assign(value);} }; 
    void set_strength_attr_data(const char* value) { if(strcmp(strength_attr_data.c_str(),value)!=0) {dirty[8] = 1; strength_attr_data.assign(value);} }; 
    int sql_strength_attr_data(char* buf,int size) const{return snprintf(buf,size,"strength_attr_data='%s'",strength_attr_data.c_str());}

    const string& get_slot_data() const { return slot_data;} ; 
    void set_slot_data(const string& value) { if(slot_data!= value){dirty[9] = 1; slot_data.assign(value);} }; 
    void set_slot_data(const char* value) { if(strcmp(slot_data.c_str(),value)!=0) {dirty[9] = 1; slot_data.assign(value);} }; 
    int sql_slot_data(char* buf,int size) const{return snprintf(buf,size,"slot_data='%s'",slot_data.c_str());}

    const string& get_reserved_attr_value_data() const { return reserved_attr_value_data;} ; 
    void set_reserved_attr_value_data(const string& value) { if(reserved_attr_value_data!= value){dirty[10] = 1; reserved_attr_value_data.assign(value);} }; 
    void set_reserved_attr_value_data(const char* value) { if(strcmp(reserved_attr_value_data.c_str(),value)!=0) {dirty[10] = 1; reserved_attr_value_data.assign(value);} }; 
    int sql_reserved_attr_value_data(char* buf,int size) const{return snprintf(buf,size,"reserved_attr_value_data='%s'",reserved_attr_value_data.c_str());}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[11] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

    int32_t get_mark() const { return mark;} ; 
    void set_mark(int32_t value) { if(mark!= value){dirty[12] = 1; mark = value;} } ; 
    int sql_mark(char* buf,int size) const{return snprintf(buf,size,"mark='%ld'",(int64_t)mark);}

    const string& get_db_stone_data() const { return db_stone_data;} ; 
    void set_db_stone_data(const string& value) { if(db_stone_data!= value){dirty[13] = 1; db_stone_data.assign(value);} }; 
    void set_db_stone_data(const char* value) { if(strcmp(db_stone_data.c_str(),value)!=0) {dirty[13] = 1; db_stone_data.assign(value);} }; 
    int sql_db_stone_data(char* buf,int size) const{return snprintf(buf,size,"db_stone_data='%s'",db_stone_data.c_str());}

private:
    //data member
    int64_t item_id ; 
    int32_t role_id ; 
    int32_t tid ; 
    int8_t bind_flag ; 
    int8_t slot_count ; 
    int8_t strength_level ; 
    string base_attr_data ; 
    string extra_attr_data ; 
    string strength_attr_data ; 
    string slot_data ; 
    string reserved_attr_value_data ; 
    int32_t create_time ; 
    int32_t mark ; 
    string db_stone_data ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 14 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
