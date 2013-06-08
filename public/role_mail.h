#ifndef _generate_h_role_mail 
#define _generate_h_role_mail 
#include "sql_binder.h"
class role_mail : public sql_binder 
{
public:
    role_mail();
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

    int32_t get_mail_id() const { return mail_id;} ; 
    void set_mail_id(int32_t value) { if(mail_id!= value){dirty[1] = 1; mail_id = value;} } ; 
    int sql_mail_id(char* buf,int size) const{return snprintf(buf,size,"mail_id='%ld'",(int64_t)mail_id);}

    int32_t get_src_role_id() const { return src_role_id;} ; 
    void set_src_role_id(int32_t value) { if(src_role_id!= value){dirty[2] = 1; src_role_id = value;} } ; 
    int sql_src_role_id(char* buf,int size) const{return snprintf(buf,size,"src_role_id='%ld'",(int64_t)src_role_id);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[3] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[4] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    int8_t get_attach_flag() const { return attach_flag;} ; 
    void set_attach_flag(int8_t value) { if(attach_flag!= value){dirty[5] = 1; attach_flag = value;} } ; 
    int sql_attach_flag(char* buf,int size) const{return snprintf(buf,size,"attach_flag='%ld'",(int64_t)attach_flag);}

    int32_t get_item_0_tid() const { return item_0_tid;} ; 
    void set_item_0_tid(int32_t value) { if(item_0_tid!= value){dirty[6] = 1; item_0_tid = value;} } ; 
    int sql_item_0_tid(char* buf,int size) const{return snprintf(buf,size,"item_0_tid='%ld'",(int64_t)item_0_tid);}

    int32_t get_item_0_count() const { return item_0_count;} ; 
    void set_item_0_count(int32_t value) { if(item_0_count!= value){dirty[7] = 1; item_0_count = value;} } ; 
    int sql_item_0_count(char* buf,int size) const{return snprintf(buf,size,"item_0_count='%ld'",(int64_t)item_0_count);}

    int32_t get_item_1_tid() const { return item_1_tid;} ; 
    void set_item_1_tid(int32_t value) { if(item_1_tid!= value){dirty[8] = 1; item_1_tid = value;} } ; 
    int sql_item_1_tid(char* buf,int size) const{return snprintf(buf,size,"item_1_tid='%ld'",(int64_t)item_1_tid);}

    int32_t get_item_1_count() const { return item_1_count;} ; 
    void set_item_1_count(int32_t value) { if(item_1_count!= value){dirty[9] = 1; item_1_count = value;} } ; 
    int sql_item_1_count(char* buf,int size) const{return snprintf(buf,size,"item_1_count='%ld'",(int64_t)item_1_count);}

    int32_t get_item_2_tid() const { return item_2_tid;} ; 
    void set_item_2_tid(int32_t value) { if(item_2_tid!= value){dirty[10] = 1; item_2_tid = value;} } ; 
    int sql_item_2_tid(char* buf,int size) const{return snprintf(buf,size,"item_2_tid='%ld'",(int64_t)item_2_tid);}

    int32_t get_item_2_count() const { return item_2_count;} ; 
    void set_item_2_count(int32_t value) { if(item_2_count!= value){dirty[11] = 1; item_2_count = value;} } ; 
    int sql_item_2_count(char* buf,int size) const{return snprintf(buf,size,"item_2_count='%ld'",(int64_t)item_2_count);}

    int32_t get_item_3_tid() const { return item_3_tid;} ; 
    void set_item_3_tid(int32_t value) { if(item_3_tid!= value){dirty[12] = 1; item_3_tid = value;} } ; 
    int sql_item_3_tid(char* buf,int size) const{return snprintf(buf,size,"item_3_tid='%ld'",(int64_t)item_3_tid);}

    int32_t get_item_3_count() const { return item_3_count;} ; 
    void set_item_3_count(int32_t value) { if(item_3_count!= value){dirty[13] = 1; item_3_count = value;} } ; 
    int sql_item_3_count(char* buf,int size) const{return snprintf(buf,size,"item_3_count='%ld'",(int64_t)item_3_count);}

    int32_t get_coin() const { return coin;} ; 
    void set_coin(int32_t value) { if(coin!= value){dirty[14] = 1; coin = value;} } ; 
    int sql_coin(char* buf,int size) const{return snprintf(buf,size,"coin='%ld'",(int64_t)coin);}

    int32_t get_coupon() const { return coupon;} ; 
    void set_coupon(int32_t value) { if(coupon!= value){dirty[15] = 1; coupon = value;} } ; 
    int sql_coupon(char* buf,int size) const{return snprintf(buf,size,"coupon='%ld'",(int64_t)coupon);}

    int32_t get_diamond() const { return diamond;} ; 
    void set_diamond(int32_t value) { if(diamond!= value){dirty[16] = 1; diamond = value;} } ; 
    int sql_diamond(char* buf,int size) const{return snprintf(buf,size,"diamond='%ld'",(int64_t)diamond);}

    const string& get_src_name() const { return src_name;} ; 
    void set_src_name(const string& value) { if(src_name!= value){dirty[17] = 1; src_name.assign(value);} }; 
    void set_src_name(const char* value) { if(strcmp(src_name.c_str(),value)!=0) {dirty[17] = 1; src_name.assign(value);} }; 
    int sql_src_name(char* buf,int size) const{return snprintf(buf,size,"src_name='%s'",src_name.c_str());}

    const string& get_title() const { return title;} ; 
    void set_title(const string& value) { if(title!= value){dirty[18] = 1; title.assign(value);} }; 
    void set_title(const char* value) { if(strcmp(title.c_str(),value)!=0) {dirty[18] = 1; title.assign(value);} }; 
    int sql_title(char* buf,int size) const{return snprintf(buf,size,"title='%s'",title.c_str());}

    const string& get_content() const { return content;} ; 
    void set_content(const string& value) { if(content!= value){dirty[19] = 1; content.assign(value);} }; 
    void set_content(const char* value) { if(strcmp(content.c_str(),value)!=0) {dirty[19] = 1; content.assign(value);} }; 
    int sql_content(char* buf,int size) const{return snprintf(buf,size,"content='%s'",content.c_str());}

    const string& get_attach_data() const { return attach_data;} ; 
    void set_attach_data(const string& value) { if(attach_data!= value){dirty[20] = 1; attach_data.assign(value);} }; 
    void set_attach_data(const char* value) { if(strcmp(attach_data.c_str(),value)!=0) {dirty[20] = 1; attach_data.assign(value);} }; 
    int sql_attach_data(char* buf,int size) const{return snprintf(buf,size,"attach_data='%s'",attach_data.c_str());}

private:
    //data member
    int32_t role_id ; 
    int32_t mail_id ; 
    int32_t src_role_id ; 
    int32_t create_time ; 
    int8_t status ; 
    int8_t attach_flag ; 
    int32_t item_0_tid ; 
    int32_t item_0_count ; 
    int32_t item_1_tid ; 
    int32_t item_1_count ; 
    int32_t item_2_tid ; 
    int32_t item_2_count ; 
    int32_t item_3_tid ; 
    int32_t item_3_count ; 
    int32_t coin ; 
    int32_t coupon ; 
    int32_t diamond ; 
    string src_name ; 
    string title ; 
    string content ; 
    string attach_data ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 21 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
