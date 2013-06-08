#ifndef _generate_h_role_lineup 
#define _generate_h_role_lineup 
#include "sql_binder.h"
class role_lineup : public sql_binder 
{
public:
    role_lineup();
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

    int32_t get_lineup_id() const { return lineup_id;} ; 
    void set_lineup_id(int32_t value) { if(lineup_id!= value){dirty[1] = 1; lineup_id = value;} } ; 
    int sql_lineup_id(char* buf,int size) const{return snprintf(buf,size,"lineup_id='%ld'",(int64_t)lineup_id);}

    int32_t get_battle_skill_1() const { return battle_skill_1;} ; 
    void set_battle_skill_1(int32_t value) { if(battle_skill_1!= value){dirty[2] = 1; battle_skill_1 = value;} } ; 
    int sql_battle_skill_1(char* buf,int size) const{return snprintf(buf,size,"battle_skill_1='%ld'",(int64_t)battle_skill_1);}

    int32_t get_battle_skill_2() const { return battle_skill_2;} ; 
    void set_battle_skill_2(int32_t value) { if(battle_skill_2!= value){dirty[3] = 1; battle_skill_2 = value;} } ; 
    int sql_battle_skill_2(char* buf,int size) const{return snprintf(buf,size,"battle_skill_2='%ld'",(int64_t)battle_skill_2);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[4] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    const string& get_lineup_name() const { return lineup_name;} ; 
    void set_lineup_name(const string& value) { if(lineup_name!= value){dirty[5] = 1; lineup_name.assign(value);} }; 
    void set_lineup_name(const char* value) { if(strcmp(lineup_name.c_str(),value)!=0) {dirty[5] = 1; lineup_name.assign(value);} }; 
    int sql_lineup_name(char* buf,int size) const{return snprintf(buf,size,"lineup_name='%s'",lineup_name.c_str());}

    const string& get_pos_data() const { return pos_data;} ; 
    void set_pos_data(const string& value) { if(pos_data!= value){dirty[6] = 1; pos_data.assign(value);} }; 
    void set_pos_data(const char* value) { if(strcmp(pos_data.c_str(),value)!=0) {dirty[6] = 1; pos_data.assign(value);} }; 
    int sql_pos_data(char* buf,int size) const{return snprintf(buf,size,"pos_data='%s'",pos_data.c_str());}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[7] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

private:
    //data member
    int32_t role_id ; 
    int32_t lineup_id ; 
    int32_t battle_skill_1 ; 
    int32_t battle_skill_2 ; 
    int8_t status ; 
    string lineup_name ; 
    string pos_data ; 
    int32_t create_time ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 8 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
