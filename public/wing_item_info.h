#ifndef _generate_h_wing_item_info 
#define _generate_h_wing_item_info 
#include "sql_binder.h"
class wing_item_info : public sql_binder 
{
public:
    wing_item_info();
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
    int64_t get_wing_item_id() const { return wing_item_id;} ; 
    void set_wing_item_id(int64_t value) { if(wing_item_id!= value){dirty[0] = 1; wing_item_id = value;} } ; 
    int sql_wing_item_id(char* buf,int size) const{return snprintf(buf,size,"wing_item_id='%ld'",(int64_t)wing_item_id);}

    int64_t get_slot_1() const { return slot_1;} ; 
    void set_slot_1(int64_t value) { if(slot_1!= value){dirty[1] = 1; slot_1 = value;} } ; 
    int sql_slot_1(char* buf,int size) const{return snprintf(buf,size,"slot_1='%ld'",(int64_t)slot_1);}

    int64_t get_slot_2() const { return slot_2;} ; 
    void set_slot_2(int64_t value) { if(slot_2!= value){dirty[2] = 1; slot_2 = value;} } ; 
    int sql_slot_2(char* buf,int size) const{return snprintf(buf,size,"slot_2='%ld'",(int64_t)slot_2);}

    int64_t get_slot_3() const { return slot_3;} ; 
    void set_slot_3(int64_t value) { if(slot_3!= value){dirty[3] = 1; slot_3 = value;} } ; 
    int sql_slot_3(char* buf,int size) const{return snprintf(buf,size,"slot_3='%ld'",(int64_t)slot_3);}

    int64_t get_slot_4() const { return slot_4;} ; 
    void set_slot_4(int64_t value) { if(slot_4!= value){dirty[4] = 1; slot_4 = value;} } ; 
    int sql_slot_4(char* buf,int size) const{return snprintf(buf,size,"slot_4='%ld'",(int64_t)slot_4);}

    int64_t get_slot_5() const { return slot_5;} ; 
    void set_slot_5(int64_t value) { if(slot_5!= value){dirty[5] = 1; slot_5 = value;} } ; 
    int sql_slot_5(char* buf,int size) const{return snprintf(buf,size,"slot_5='%ld'",(int64_t)slot_5);}

    int64_t get_slot_6() const { return slot_6;} ; 
    void set_slot_6(int64_t value) { if(slot_6!= value){dirty[6] = 1; slot_6 = value;} } ; 
    int sql_slot_6(char* buf,int size) const{return snprintf(buf,size,"slot_6='%ld'",(int64_t)slot_6);}

    int64_t get_slot_7() const { return slot_7;} ; 
    void set_slot_7(int64_t value) { if(slot_7!= value){dirty[7] = 1; slot_7 = value;} } ; 
    int sql_slot_7(char* buf,int size) const{return snprintf(buf,size,"slot_7='%ld'",(int64_t)slot_7);}

    int64_t get_slot_8() const { return slot_8;} ; 
    void set_slot_8(int64_t value) { if(slot_8!= value){dirty[8] = 1; slot_8 = value;} } ; 
    int sql_slot_8(char* buf,int size) const{return snprintf(buf,size,"slot_8='%ld'",(int64_t)slot_8);}

private:
    //data member
    int64_t wing_item_id ; 
    int64_t slot_1 ; 
    int64_t slot_2 ; 
    int64_t slot_3 ; 
    int64_t slot_4 ; 
    int64_t slot_5 ; 
    int64_t slot_6 ; 
    int64_t slot_7 ; 
    int64_t slot_8 ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 9 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
