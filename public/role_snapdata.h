#ifndef _generate_h_role_snapdata 
#define _generate_h_role_snapdata 
#include "sql_binder.h"
class role_snapdata : public sql_binder 
{
public:
    role_snapdata();
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

    int32_t get_server_id() const { return server_id;} ; 
    void set_server_id(int32_t value) { if(server_id!= value){dirty[1] = 1; server_id = value;} } ; 
    int sql_server_id(char* buf,int size) const{return snprintf(buf,size,"server_id='%ld'",(int64_t)server_id);}

    int32_t get_role_rank() const { return role_rank;} ; 
    void set_role_rank(int32_t value) { if(role_rank!= value){dirty[2] = 1; role_rank = value;} } ; 
    int sql_role_rank(char* buf,int size) const{return snprintf(buf,size,"role_rank='%ld'",(int64_t)role_rank);}

    int32_t get_highest_rank() const { return highest_rank;} ; 
    void set_highest_rank(int32_t value) { if(highest_rank!= value){dirty[3] = 1; highest_rank = value;} } ; 
    int sql_highest_rank(char* buf,int size) const{return snprintf(buf,size,"highest_rank='%ld'",(int64_t)highest_rank);}

    int8_t get_is_robot() const { return is_robot;} ; 
    void set_is_robot(int8_t value) { if(is_robot!= value){dirty[4] = 1; is_robot = value;} } ; 
    int sql_is_robot(char* buf,int size) const{return snprintf(buf,size,"is_robot='%ld'",(int64_t)is_robot);}

    const string& get_snap_data() const { return snap_data;} ; 
    void set_snap_data(const string& value) { if(snap_data!= value){dirty[5] = 1; snap_data.assign(value);} }; 
    void set_snap_data(const char* value) { if(strcmp(snap_data.c_str(),value)!=0) {dirty[5] = 1; snap_data.assign(value);} }; 
    int sql_snap_data(char* buf,int size) const{return snprintf(buf,size,"snap_data='%s'",snap_data.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t server_id ; 
    int32_t role_rank ; 
    int32_t highest_rank ; 
    int8_t is_robot ; 
    string snap_data ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 6 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
