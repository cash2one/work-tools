#ifndef _generate_h_role_item 
#define _generate_h_role_item 
#include "sql_binder.h"
class role_item : public sql_binder 
{
public:
    role_item();
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

    int32_t get_item_type() const { return item_type;} ; 
    void set_item_type(int32_t value) { if(item_type!= value){dirty[3] = 1; item_type = value;} } ; 
    int sql_item_type(char* buf,int size) const{return snprintf(buf,size,"item_type='%ld'",(int64_t)item_type);}

    int32_t get_expired() const { return expired;} ; 
    void set_expired(int32_t value) { if(expired!= value){dirty[4] = 1; expired = value;} } ; 
    int sql_expired(char* buf,int size) const{return snprintf(buf,size,"expired='%ld'",(int64_t)expired);}

    int16_t get_count() const { return count;} ; 
    void set_count(int16_t value) { if(count!= value){dirty[5] = 1; count = value;} } ; 
    int sql_count(char* buf,int size) const{return snprintf(buf,size,"count='%ld'",(int64_t)count);}

    int16_t get_pos_value() const { return pos_value;} ; 
    void set_pos_value(int16_t value) { if(pos_value!= value){dirty[6] = 1; pos_value = value;} } ; 
    int sql_pos_value(char* buf,int size) const{return snprintf(buf,size,"pos_value='%ld'",(int64_t)pos_value);}

    int8_t get_pos_type() const { return pos_type;} ; 
    void set_pos_type(int8_t value) { if(pos_type!= value){dirty[7] = 1; pos_type = value;} } ; 
    int sql_pos_type(char* buf,int size) const{return snprintf(buf,size,"pos_type='%ld'",(int64_t)pos_type);}

    int8_t get_bind_flag() const { return bind_flag;} ; 
    void set_bind_flag(int8_t value) { if(bind_flag!= value){dirty[8] = 1; bind_flag = value;} } ; 
    int sql_bind_flag(char* buf,int size) const{return snprintf(buf,size,"bind_flag='%ld'",(int64_t)bind_flag);}

    int8_t get_stack_flag() const { return stack_flag;} ; 
    void set_stack_flag(int8_t value) { if(stack_flag!= value){dirty[9] = 1; stack_flag = value;} } ; 
    int sql_stack_flag(char* buf,int size) const{return snprintf(buf,size,"stack_flag='%ld'",(int64_t)stack_flag);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[10] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

private:
    //data member
    int64_t item_id ; 
    int32_t role_id ; 
    int32_t tid ; 
    int32_t item_type ; 
    int32_t expired ; 
    int16_t count ; 
    int16_t pos_value ; 
    int8_t pos_type ; 
    int8_t bind_flag ; 
    int8_t stack_flag ; 
    int32_t create_time ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 11 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
