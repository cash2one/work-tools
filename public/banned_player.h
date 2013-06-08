#ifndef _generate_h_banned_player 
#define _generate_h_banned_player 
#include "sql_binder.h"
class banned_player : public sql_binder 
{
public:
    banned_player();
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

    int32_t get_ban_until_ts() const { return ban_until_ts;} ; 
    void set_ban_until_ts(int32_t value) { if(ban_until_ts!= value){dirty[1] = 1; ban_until_ts = value;} } ; 
    int sql_ban_until_ts(char* buf,int size) const{return snprintf(buf,size,"ban_until_ts='%ld'",(int64_t)ban_until_ts);}

    int32_t get_by_gm() const { return by_gm;} ; 
    void set_by_gm(int32_t value) { if(by_gm!= value){dirty[2] = 1; by_gm = value;} } ; 
    int sql_by_gm(char* buf,int size) const{return snprintf(buf,size,"by_gm='%ld'",(int64_t)by_gm);}

    const string& get_by_reason() const { return by_reason;} ; 
    void set_by_reason(const string& value) { if(by_reason!= value){dirty[3] = 1; by_reason.assign(value);} }; 
    void set_by_reason(const char* value) { if(strcmp(by_reason.c_str(),value)!=0) {dirty[3] = 1; by_reason.assign(value);} }; 
    int sql_by_reason(char* buf,int size) const{return snprintf(buf,size,"by_reason='%s'",by_reason.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t ban_until_ts ; 
    int32_t by_gm ; 
    string by_reason ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 4 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
