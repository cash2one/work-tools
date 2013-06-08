#ifndef _generate_h_alien_boss 
#define _generate_h_alien_boss 
#include "sql_binder.h"
class alien_boss : public sql_binder 
{
public:
    alien_boss();
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
    int32_t get_id() const { return id;} ; 
    void set_id(int32_t value) { if(id!= value){dirty[0] = 1; id = value;} } ; 
    int sql_id(char* buf,int size) const{return snprintf(buf,size,"id='%ld'",(int64_t)id);}

    int32_t get_last_max_hp() const { return last_max_hp;} ; 
    void set_last_max_hp(int32_t value) { if(last_max_hp!= value){dirty[1] = 1; last_max_hp = value;} } ; 
    int sql_last_max_hp(char* buf,int size) const{return snprintf(buf,size,"last_max_hp='%ld'",(int64_t)last_max_hp);}

    int32_t get_last_phy_attack() const { return last_phy_attack;} ; 
    void set_last_phy_attack(int32_t value) { if(last_phy_attack!= value){dirty[2] = 1; last_phy_attack = value;} } ; 
    int sql_last_phy_attack(char* buf,int size) const{return snprintf(buf,size,"last_phy_attack='%ld'",(int64_t)last_phy_attack);}

    int32_t get_last_mag_attack() const { return last_mag_attack;} ; 
    void set_last_mag_attack(int32_t value) { if(last_mag_attack!= value){dirty[3] = 1; last_mag_attack = value;} } ; 
    int sql_last_mag_attack(char* buf,int size) const{return snprintf(buf,size,"last_mag_attack='%ld'",(int64_t)last_mag_attack);}

private:
    //data member
    int32_t id ; 
    int32_t last_max_hp ; 
    int32_t last_phy_attack ; 
    int32_t last_mag_attack ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 4 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
