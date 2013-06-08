#ifndef _generate_h_role_wing_spirit_bag 
#define _generate_h_role_wing_spirit_bag 
#include "sql_binder.h"
class role_wing_spirit_bag : public sql_binder 
{
public:
    role_wing_spirit_bag();
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

    int64_t get_spirit_item_id() const { return spirit_item_id;} ; 
    void set_spirit_item_id(int64_t value) { if(spirit_item_id!= value){dirty[1] = 1; spirit_item_id = value;} } ; 
    int sql_spirit_item_id(char* buf,int size) const{return snprintf(buf,size,"spirit_item_id='%ld'",(int64_t)spirit_item_id);}

    int32_t get_spirit_tid() const { return spirit_tid;} ; 
    void set_spirit_tid(int32_t value) { if(spirit_tid!= value){dirty[2] = 1; spirit_tid = value;} } ; 
    int sql_spirit_tid(char* buf,int size) const{return snprintf(buf,size,"spirit_tid='%ld'",(int64_t)spirit_tid);}

    int32_t get_spirit_pos() const { return spirit_pos;} ; 
    void set_spirit_pos(int32_t value) { if(spirit_pos!= value){dirty[3] = 1; spirit_pos = value;} } ; 
    int sql_spirit_pos(char* buf,int size) const{return snprintf(buf,size,"spirit_pos='%ld'",(int64_t)spirit_pos);}

private:
    //data member
    int32_t role_id ; 
    int64_t spirit_item_id ; 
    int32_t spirit_tid ; 
    int32_t spirit_pos ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 4 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
