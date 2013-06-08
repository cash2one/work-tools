#ifndef _generate_h_role_wing_spirit_system 
#define _generate_h_role_wing_spirit_system 
#include "sql_binder.h"
class role_wing_spirit_system : public sql_binder 
{
public:
    role_wing_spirit_system();
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

    int32_t get_bag_open_slot_num() const { return bag_open_slot_num;} ; 
    void set_bag_open_slot_num(int32_t value) { if(bag_open_slot_num!= value){dirty[1] = 1; bag_open_slot_num = value;} } ; 
    int sql_bag_open_slot_num(char* buf,int size) const{return snprintf(buf,size,"bag_open_slot_num='%ld'",(int64_t)bag_open_slot_num);}

    int64_t get_fragment_num() const { return fragment_num;} ; 
    void set_fragment_num(int64_t value) { if(fragment_num!= value){dirty[2] = 1; fragment_num = value;} } ; 
    int sql_fragment_num(char* buf,int size) const{return snprintf(buf,size,"fragment_num='%ld'",(int64_t)fragment_num);}

    int64_t get_money_spent() const { return money_spent;} ; 
    void set_money_spent(int64_t value) { if(money_spent!= value){dirty[3] = 1; money_spent = value;} } ; 
    int sql_money_spent(char* buf,int size) const{return snprintf(buf,size,"money_spent='%ld'",(int64_t)money_spent);}

    int8_t get_magic_effected() const { return magic_effected;} ; 
    void set_magic_effected(int8_t value) { if(magic_effected!= value){dirty[4] = 1; magic_effected = value;} } ; 
    int sql_magic_effected(char* buf,int size) const{return snprintf(buf,size,"magic_effected='%ld'",(int64_t)magic_effected);}

    int8_t get_first_level_1() const { return first_level_1;} ; 
    void set_first_level_1(int8_t value) { if(first_level_1!= value){dirty[5] = 1; first_level_1 = value;} } ; 
    int sql_first_level_1(char* buf,int size) const{return snprintf(buf,size,"first_level_1='%ld'",(int64_t)first_level_1);}

    int8_t get_first_level_2() const { return first_level_2;} ; 
    void set_first_level_2(int8_t value) { if(first_level_2!= value){dirty[6] = 1; first_level_2 = value;} } ; 
    int sql_first_level_2(char* buf,int size) const{return snprintf(buf,size,"first_level_2='%ld'",(int64_t)first_level_2);}

    int8_t get_first_level_3() const { return first_level_3;} ; 
    void set_first_level_3(int8_t value) { if(first_level_3!= value){dirty[7] = 1; first_level_3 = value;} } ; 
    int sql_first_level_3(char* buf,int size) const{return snprintf(buf,size,"first_level_3='%ld'",(int64_t)first_level_3);}

    int8_t get_first_level_4() const { return first_level_4;} ; 
    void set_first_level_4(int8_t value) { if(first_level_4!= value){dirty[8] = 1; first_level_4 = value;} } ; 
    int sql_first_level_4(char* buf,int size) const{return snprintf(buf,size,"first_level_4='%ld'",(int64_t)first_level_4);}

    int8_t get_first_level_5() const { return first_level_5;} ; 
    void set_first_level_5(int8_t value) { if(first_level_5!= value){dirty[9] = 1; first_level_5 = value;} } ; 
    int sql_first_level_5(char* buf,int size) const{return snprintf(buf,size,"first_level_5='%ld'",(int64_t)first_level_5);}

    int8_t get_level_1() const { return level_1;} ; 
    void set_level_1(int8_t value) { if(level_1!= value){dirty[10] = 1; level_1 = value;} } ; 
    int sql_level_1(char* buf,int size) const{return snprintf(buf,size,"level_1='%ld'",(int64_t)level_1);}

    int8_t get_level_2() const { return level_2;} ; 
    void set_level_2(int8_t value) { if(level_2!= value){dirty[11] = 1; level_2 = value;} } ; 
    int sql_level_2(char* buf,int size) const{return snprintf(buf,size,"level_2='%ld'",(int64_t)level_2);}

    int8_t get_level_3() const { return level_3;} ; 
    void set_level_3(int8_t value) { if(level_3!= value){dirty[12] = 1; level_3 = value;} } ; 
    int sql_level_3(char* buf,int size) const{return snprintf(buf,size,"level_3='%ld'",(int64_t)level_3);}

    int8_t get_level_4() const { return level_4;} ; 
    void set_level_4(int8_t value) { if(level_4!= value){dirty[13] = 1; level_4 = value;} } ; 
    int sql_level_4(char* buf,int size) const{return snprintf(buf,size,"level_4='%ld'",(int64_t)level_4);}

    int8_t get_level_5() const { return level_5;} ; 
    void set_level_5(int8_t value) { if(level_5!= value){dirty[14] = 1; level_5 = value;} } ; 
    int sql_level_5(char* buf,int size) const{return snprintf(buf,size,"level_5='%ld'",(int64_t)level_5);}

private:
    //data member
    int32_t role_id ; 
    int32_t bag_open_slot_num ; 
    int64_t fragment_num ; 
    int64_t money_spent ; 
    int8_t magic_effected ; 
    int8_t first_level_1 ; 
    int8_t first_level_2 ; 
    int8_t first_level_3 ; 
    int8_t first_level_4 ; 
    int8_t first_level_5 ; 
    int8_t level_1 ; 
    int8_t level_2 ; 
    int8_t level_3 ; 
    int8_t level_4 ; 
    int8_t level_5 ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 15 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
