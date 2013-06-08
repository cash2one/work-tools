#ifndef _generate_h_role_info 
#define _generate_h_role_info 
#include "sql_binder.h"
class role_info : public sql_binder 
{
public:
    role_info();
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

    int32_t get_uid() const { return uid;} ; 
    void set_uid(int32_t value) { if(uid!= value){dirty[1] = 1; uid = value;} } ; 
    int sql_uid(char* buf,int size) const{return snprintf(buf,size,"uid='%ld'",(int64_t)uid);}

    int32_t get_vip_end_ts() const { return vip_end_ts;} ; 
    void set_vip_end_ts(int32_t value) { if(vip_end_ts!= value){dirty[2] = 1; vip_end_ts = value;} } ; 
    int sql_vip_end_ts(char* buf,int size) const{return snprintf(buf,size,"vip_end_ts='%ld'",(int64_t)vip_end_ts);}

    int8_t get_vip_level() const { return vip_level;} ; 
    void set_vip_level(int8_t value) { if(vip_level!= value){dirty[3] = 1; vip_level = value;} } ; 
    int sql_vip_level(char* buf,int size) const{return snprintf(buf,size,"vip_level='%ld'",(int64_t)vip_level);}

    int8_t get_gender() const { return gender;} ; 
    void set_gender(int8_t value) { if(gender!= value){dirty[4] = 1; gender = value;} } ; 
    int sql_gender(char* buf,int size) const{return snprintf(buf,size,"gender='%ld'",(int64_t)gender);}

    int8_t get_job_type() const { return job_type;} ; 
    void set_job_type(int8_t value) { if(job_type!= value){dirty[5] = 1; job_type = value;} } ; 
    int sql_job_type(char* buf,int size) const{return snprintf(buf,size,"job_type='%ld'",(int64_t)job_type);}

    int8_t get_role_level() const { return role_level;} ; 
    void set_role_level(int8_t value) { if(role_level!= value){dirty[6] = 1; role_level = value;} } ; 
    int sql_role_level(char* buf,int size) const{return snprintf(buf,size,"role_level='%ld'",(int64_t)role_level);}

    int32_t get_role_exp() const { return role_exp;} ; 
    void set_role_exp(int32_t value) { if(role_exp!= value){dirty[7] = 1; role_exp = value;} } ; 
    int sql_role_exp(char* buf,int size) const{return snprintf(buf,size,"role_exp='%ld'",(int64_t)role_exp);}

    int32_t get_tid() const { return tid;} ; 
    void set_tid(int32_t value) { if(tid!= value){dirty[8] = 1; tid = value;} } ; 
    int sql_tid(char* buf,int size) const{return snprintf(buf,size,"tid='%ld'",(int64_t)tid);}

    int32_t get_coin() const { return coin;} ; 
    void set_coin(int32_t value) { if(coin!= value){dirty[9] = 1; coin = value;} } ; 
    int sql_coin(char* buf,int size) const{return snprintf(buf,size,"coin='%ld'",(int64_t)coin);}

    int32_t get_coupon() const { return coupon;} ; 
    void set_coupon(int32_t value) { if(coupon!= value){dirty[10] = 1; coupon = value;} } ; 
    int sql_coupon(char* buf,int size) const{return snprintf(buf,size,"coupon='%ld'",(int64_t)coupon);}

    int32_t get_diamond() const { return diamond;} ; 
    void set_diamond(int32_t value) { if(diamond!= value){dirty[11] = 1; diamond = value;} } ; 
    int sql_diamond(char* buf,int size) const{return snprintf(buf,size,"diamond='%ld'",(int64_t)diamond);}

    int16_t get_map_id() const { return map_id;} ; 
    void set_map_id(int16_t value) { if(map_id!= value){dirty[12] = 1; map_id = value;} } ; 
    int sql_map_id(char* buf,int size) const{return snprintf(buf,size,"map_id='%ld'",(int64_t)map_id);}

    int16_t get_map_x() const { return map_x;} ; 
    void set_map_x(int16_t value) { if(map_x!= value){dirty[13] = 1; map_x = value;} } ; 
    int sql_map_x(char* buf,int size) const{return snprintf(buf,size,"map_x='%ld'",(int64_t)map_x);}

    int16_t get_map_y() const { return map_y;} ; 
    void set_map_y(int16_t value) { if(map_y!= value){dirty[14] = 1; map_y = value;} } ; 
    int sql_map_y(char* buf,int size) const{return snprintf(buf,size,"map_y='%ld'",(int64_t)map_y);}

    int16_t get_depot_size() const { return depot_size;} ; 
    void set_depot_size(int16_t value) { if(depot_size!= value){dirty[15] = 1; depot_size = value;} } ; 
    int sql_depot_size(char* buf,int size) const{return snprintf(buf,size,"depot_size='%ld'",(int64_t)depot_size);}

    int16_t get_bag_size() const { return bag_size;} ; 
    void set_bag_size(int16_t value) { if(bag_size!= value){dirty[16] = 1; bag_size = value;} } ; 
    int sql_bag_size(char* buf,int size) const{return snprintf(buf,size,"bag_size='%ld'",(int64_t)bag_size);}

    int16_t get_flag() const { return flag;} ; 
    void set_flag(int16_t value) { if(flag!= value){dirty[17] = 1; flag = value;} } ; 
    int sql_flag(char* buf,int size) const{return snprintf(buf,size,"flag='%ld'",(int64_t)flag);}

    int8_t get_buddy_size() const { return buddy_size;} ; 
    void set_buddy_size(int8_t value) { if(buddy_size!= value){dirty[18] = 1; buddy_size = value;} } ; 
    int sql_buddy_size(char* buf,int size) const{return snprintf(buf,size,"buddy_size='%ld'",(int64_t)buddy_size);}

    int8_t get_lineup_size() const { return lineup_size;} ; 
    void set_lineup_size(int8_t value) { if(lineup_size!= value){dirty[19] = 1; lineup_size = value;} } ; 
    int sql_lineup_size(char* buf,int size) const{return snprintf(buf,size,"lineup_size='%ld'",(int64_t)lineup_size);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[20] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%ld'",(int64_t)status);}

    int32_t get_server_id() const { return server_id;} ; 
    void set_server_id(int32_t value) { if(server_id!= value){dirty[21] = 1; server_id = value;} } ; 
    int sql_server_id(char* buf,int size) const{return snprintf(buf,size,"server_id='%ld'",(int64_t)server_id);}

    int32_t get_team_id() const { return team_id;} ; 
    void set_team_id(int32_t value) { if(team_id!= value){dirty[22] = 1; team_id = value;} } ; 
    int sql_team_id(char* buf,int size) const{return snprintf(buf,size,"team_id='%ld'",(int64_t)team_id);}

    int32_t get_team_create_time() const { return team_create_time;} ; 
    void set_team_create_time(int32_t value) { if(team_create_time!= value){dirty[23] = 1; team_create_time = value;} } ; 
    int sql_team_create_time(char* buf,int size) const{return snprintf(buf,size,"team_create_time='%ld'",(int64_t)team_create_time);}

    int32_t get_login_time() const { return login_time;} ; 
    void set_login_time(int32_t value) { if(login_time!= value){dirty[24] = 1; login_time = value;} } ; 
    int sql_login_time(char* buf,int size) const{return snprintf(buf,size,"login_time='%ld'",(int64_t)login_time);}

    const string& get_login_ip() const { return login_ip;} ; 
    void set_login_ip(const string& value) { if(login_ip!= value){dirty[25] = 1; login_ip.assign(value);} }; 
    void set_login_ip(const char* value) { if(strcmp(login_ip.c_str(),value)!=0) {dirty[25] = 1; login_ip.assign(value);} }; 
    int sql_login_ip(char* buf,int size) const{return snprintf(buf,size,"login_ip='%s'",login_ip.c_str());}

    int32_t get_default_lineup_id() const { return default_lineup_id;} ; 
    void set_default_lineup_id(int32_t value) { if(default_lineup_id!= value){dirty[26] = 1; default_lineup_id = value;} } ; 
    int sql_default_lineup_id(char* buf,int size) const{return snprintf(buf,size,"default_lineup_id='%ld'",(int64_t)default_lineup_id);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[27] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%ld'",(int64_t)create_time);}

    const string& get_name() const { return name;} ; 
    void set_name(const string& value) { if(name!= value){dirty[28] = 1; name.assign(value);} }; 
    void set_name(const char* value) { if(strcmp(name.c_str(),value)!=0) {dirty[28] = 1; name.assign(value);} }; 
    int sql_name(char* buf,int size) const{return snprintf(buf,size,"name='%s'",name.c_str());}

    int32_t get_yingling_slot() const { return yingling_slot;} ; 
    void set_yingling_slot(int32_t value) { if(yingling_slot!= value){dirty[29] = 1; yingling_slot = value;} } ; 
    int sql_yingling_slot(char* buf,int size) const{return snprintf(buf,size,"yingling_slot='%ld'",(int64_t)yingling_slot);}

    int32_t get_hiring_yingling_slot() const { return hiring_yingling_slot;} ; 
    void set_hiring_yingling_slot(int32_t value) { if(hiring_yingling_slot!= value){dirty[30] = 1; hiring_yingling_slot = value;} } ; 
    int sql_hiring_yingling_slot(char* buf,int size) const{return snprintf(buf,size,"hiring_yingling_slot='%ld'",(int64_t)hiring_yingling_slot);}

    int32_t get_hiring_yingling_lingli() const { return hiring_yingling_lingli;} ; 
    void set_hiring_yingling_lingli(int32_t value) { if(hiring_yingling_lingli!= value){dirty[31] = 1; hiring_yingling_lingli = value;} } ; 
    int sql_hiring_yingling_lingli(char* buf,int size) const{return snprintf(buf,size,"hiring_yingling_lingli='%ld'",(int64_t)hiring_yingling_lingli);}

    int32_t get_max_none_cooldown_hiring_count() const { return max_none_cooldown_hiring_count;} ; 
    void set_max_none_cooldown_hiring_count(int32_t value) { if(max_none_cooldown_hiring_count!= value){dirty[32] = 1; max_none_cooldown_hiring_count = value;} } ; 
    int sql_max_none_cooldown_hiring_count(char* buf,int size) const{return snprintf(buf,size,"max_none_cooldown_hiring_count='%ld'",(int64_t)max_none_cooldown_hiring_count);}

    int32_t get_cur_none_cooldown_hiring_count() const { return cur_none_cooldown_hiring_count;} ; 
    void set_cur_none_cooldown_hiring_count(int32_t value) { if(cur_none_cooldown_hiring_count!= value){dirty[33] = 1; cur_none_cooldown_hiring_count = value;} } ; 
    int sql_cur_none_cooldown_hiring_count(char* buf,int size) const{return snprintf(buf,size,"cur_none_cooldown_hiring_count='%ld'",(int64_t)cur_none_cooldown_hiring_count);}

    int64_t get_hiring_cooldown_tick() const { return hiring_cooldown_tick;} ; 
    void set_hiring_cooldown_tick(int64_t value) { if(hiring_cooldown_tick!= value){dirty[34] = 1; hiring_cooldown_tick = value;} } ; 
    int sql_hiring_cooldown_tick(char* buf,int size) const{return snprintf(buf,size,"hiring_cooldown_tick='%ld'",(int64_t)hiring_cooldown_tick);}

    const string& get_hiring_yingling_list() const { return hiring_yingling_list;} ; 
    void set_hiring_yingling_list(const string& value) { if(hiring_yingling_list!= value){dirty[35] = 1; hiring_yingling_list.assign(value);} }; 
    void set_hiring_yingling_list(const char* value) { if(strcmp(hiring_yingling_list.c_str(),value)!=0) {dirty[35] = 1; hiring_yingling_list.assign(value);} }; 
    int sql_hiring_yingling_list(char* buf,int size) const{return snprintf(buf,size,"hiring_yingling_list='%s'",hiring_yingling_list.c_str());}

    const string& get_daily_quest_data() const { return daily_quest_data;} ; 
    void set_daily_quest_data(const string& value) { if(daily_quest_data!= value){dirty[36] = 1; daily_quest_data.assign(value);} }; 
    void set_daily_quest_data(const char* value) { if(strcmp(daily_quest_data.c_str(),value)!=0) {dirty[36] = 1; daily_quest_data.assign(value);} }; 
    int sql_daily_quest_data(char* buf,int size) const{return snprintf(buf,size,"daily_quest_data='%s'",daily_quest_data.c_str());}

    const string& get_flags_data() const { return flags_data;} ; 
    void set_flags_data(const string& value) { if(flags_data!= value){dirty[37] = 1; flags_data.assign(value);} }; 
    void set_flags_data(const char* value) { if(strcmp(flags_data.c_str(),value)!=0) {dirty[37] = 1; flags_data.assign(value);} }; 
    int sql_flags_data(char* buf,int size) const{return snprintf(buf,size,"flags_data='%s'",flags_data.c_str());}

    const string& get_hide_data() const { return hide_data;} ; 
    void set_hide_data(const string& value) { if(hide_data!= value){dirty[38] = 1; hide_data.assign(value);} }; 
    void set_hide_data(const char* value) { if(strcmp(hide_data.c_str(),value)!=0) {dirty[38] = 1; hide_data.assign(value);} }; 
    int sql_hide_data(char* buf,int size) const{return snprintf(buf,size,"hide_data='%s'",hide_data.c_str());}

    int32_t get_instance_count() const { return instance_count;} ; 
    void set_instance_count(int32_t value) { if(instance_count!= value){dirty[39] = 1; instance_count = value;} } ; 
    int sql_instance_count(char* buf,int size) const{return snprintf(buf,size,"instance_count='%ld'",(int64_t)instance_count);}

    int32_t get_instance_time() const { return instance_time;} ; 
    void set_instance_time(int32_t value) { if(instance_time!= value){dirty[40] = 1; instance_time = value;} } ; 
    int sql_instance_time(char* buf,int size) const{return snprintf(buf,size,"instance_time='%ld'",(int64_t)instance_time);}

    int32_t get_guild_id() const { return guild_id;} ; 
    void set_guild_id(int32_t value) { if(guild_id!= value){dirty[41] = 1; guild_id = value;} } ; 
    int sql_guild_id(char* buf,int size) const{return snprintf(buf,size,"guild_id='%ld'",(int64_t)guild_id);}

    int32_t get_guild_time() const { return guild_time;} ; 
    void set_guild_time(int32_t value) { if(guild_time!= value){dirty[42] = 1; guild_time = value;} } ; 
    int sql_guild_time(char* buf,int size) const{return snprintf(buf,size,"guild_time='%ld'",(int64_t)guild_time);}

    const string& get_guild_name() const { return guild_name;} ; 
    void set_guild_name(const string& value) { if(guild_name!= value){dirty[43] = 1; guild_name.assign(value);} }; 
    void set_guild_name(const char* value) { if(strcmp(guild_name.c_str(),value)!=0) {dirty[43] = 1; guild_name.assign(value);} }; 
    int sql_guild_name(char* buf,int size) const{return snprintf(buf,size,"guild_name='%s'",guild_name.c_str());}

    int32_t get_last_fight_time() const { return last_fight_time;} ; 
    void set_last_fight_time(int32_t value) { if(last_fight_time!= value){dirty[44] = 1; last_fight_time = value;} } ; 
    int sql_last_fight_time(char* buf,int size) const{return snprintf(buf,size,"last_fight_time='%ld'",(int64_t)last_fight_time);}

    int32_t get_last_battle_id() const { return last_battle_id;} ; 
    void set_last_battle_id(int32_t value) { if(last_battle_id!= value){dirty[45] = 1; last_battle_id = value;} } ; 
    int sql_last_battle_id(char* buf,int size) const{return snprintf(buf,size,"last_battle_id='%ld'",(int64_t)last_battle_id);}

    int32_t get_last_take_monster_exp_time() const { return last_take_monster_exp_time;} ; 
    void set_last_take_monster_exp_time(int32_t value) { if(last_take_monster_exp_time!= value){dirty[46] = 1; last_take_monster_exp_time = value;} } ; 
    int sql_last_take_monster_exp_time(char* buf,int size) const{return snprintf(buf,size,"last_take_monster_exp_time='%ld'",(int64_t)last_take_monster_exp_time);}

    int32_t get_taken_monster_exp_times_this_week() const { return taken_monster_exp_times_this_week;} ; 
    void set_taken_monster_exp_times_this_week(int32_t value) { if(taken_monster_exp_times_this_week!= value){dirty[47] = 1; taken_monster_exp_times_this_week = value;} } ; 
    int sql_taken_monster_exp_times_this_week(char* buf,int size) const{return snprintf(buf,size,"taken_monster_exp_times_this_week='%ld'",(int64_t)taken_monster_exp_times_this_week);}

    int32_t get_lineup_capacity() const { return lineup_capacity;} ; 
    void set_lineup_capacity(int32_t value) { if(lineup_capacity!= value){dirty[48] = 1; lineup_capacity = value;} } ; 
    int sql_lineup_capacity(char* buf,int size) const{return snprintf(buf,size,"lineup_capacity='%ld'",(int64_t)lineup_capacity);}

    int32_t get_buff_2_id() const { return buff_2_id;} ; 
    void set_buff_2_id(int32_t value) { if(buff_2_id!= value){dirty[49] = 1; buff_2_id = value;} } ; 
    int sql_buff_2_id(char* buf,int size) const{return snprintf(buf,size,"buff_2_id='%ld'",(int64_t)buff_2_id);}

    int32_t get_buff_2_expire_time() const { return buff_2_expire_time;} ; 
    void set_buff_2_expire_time(int32_t value) { if(buff_2_expire_time!= value){dirty[50] = 1; buff_2_expire_time = value;} } ; 
    int sql_buff_2_expire_time(char* buf,int size) const{return snprintf(buf,size,"buff_2_expire_time='%ld'",(int64_t)buff_2_expire_time);}

    int32_t get_buff_1_id() const { return buff_1_id;} ; 
    void set_buff_1_id(int32_t value) { if(buff_1_id!= value){dirty[51] = 1; buff_1_id = value;} } ; 
    int sql_buff_1_id(char* buf,int size) const{return snprintf(buf,size,"buff_1_id='%ld'",(int64_t)buff_1_id);}

    int32_t get_buff_1_expire_time() const { return buff_1_expire_time;} ; 
    void set_buff_1_expire_time(int32_t value) { if(buff_1_expire_time!= value){dirty[52] = 1; buff_1_expire_time = value;} } ; 
    int sql_buff_1_expire_time(char* buf,int size) const{return snprintf(buf,size,"buff_1_expire_time='%ld'",(int64_t)buff_1_expire_time);}

    int32_t get_phy_strength() const { return phy_strength;} ; 
    void set_phy_strength(int32_t value) { if(phy_strength!= value){dirty[53] = 1; phy_strength = value;} } ; 
    int sql_phy_strength(char* buf,int size) const{return snprintf(buf,size,"phy_strength='%ld'",(int64_t)phy_strength);}

    int32_t get_extra_phy_strength() const { return extra_phy_strength;} ; 
    void set_extra_phy_strength(int32_t value) { if(extra_phy_strength!= value){dirty[54] = 1; extra_phy_strength = value;} } ; 
    int sql_extra_phy_strength(char* buf,int size) const{return snprintf(buf,size,"extra_phy_strength='%ld'",(int64_t)extra_phy_strength);}

    int32_t get_time_to_recover_phy_strength() const { return time_to_recover_phy_strength;} ; 
    void set_time_to_recover_phy_strength(int32_t value) { if(time_to_recover_phy_strength!= value){dirty[55] = 1; time_to_recover_phy_strength = value;} } ; 
    int sql_time_to_recover_phy_strength(char* buf,int size) const{return snprintf(buf,size,"time_to_recover_phy_strength='%ld'",(int64_t)time_to_recover_phy_strength);}

    int32_t get_time_to_recover_extra_phy_strength() const { return time_to_recover_extra_phy_strength;} ; 
    void set_time_to_recover_extra_phy_strength(int32_t value) { if(time_to_recover_extra_phy_strength!= value){dirty[56] = 1; time_to_recover_extra_phy_strength = value;} } ; 
    int sql_time_to_recover_extra_phy_strength(char* buf,int size) const{return snprintf(buf,size,"time_to_recover_extra_phy_strength='%ld'",(int64_t)time_to_recover_extra_phy_strength);}

    int32_t get_last_logoff_time() const { return last_logoff_time;} ; 
    void set_last_logoff_time(int32_t value) { if(last_logoff_time!= value){dirty[57] = 1; last_logoff_time = value;} } ; 
    int sql_last_logoff_time(char* buf,int size) const{return snprintf(buf,size,"last_logoff_time='%ld'",(int64_t)last_logoff_time);}

    int32_t get_total_online_time_of_day() const { return total_online_time_of_day;} ; 
    void set_total_online_time_of_day(int32_t value) { if(total_online_time_of_day!= value){dirty[58] = 1; total_online_time_of_day = value;} } ; 
    int sql_total_online_time_of_day(char* buf,int size) const{return snprintf(buf,size,"total_online_time_of_day='%ld'",(int64_t)total_online_time_of_day);}

    int32_t get_today_taken_bonus_max_time() const { return today_taken_bonus_max_time;} ; 
    void set_today_taken_bonus_max_time(int32_t value) { if(today_taken_bonus_max_time!= value){dirty[59] = 1; today_taken_bonus_max_time = value;} } ; 
    int sql_today_taken_bonus_max_time(char* buf,int size) const{return snprintf(buf,size,"today_taken_bonus_max_time='%ld'",(int64_t)today_taken_bonus_max_time);}

    int32_t get_can_get_gift_id() const { return can_get_gift_id;} ; 
    void set_can_get_gift_id(int32_t value) { if(can_get_gift_id!= value){dirty[60] = 1; can_get_gift_id = value;} } ; 
    int sql_can_get_gift_id(char* buf,int size) const{return snprintf(buf,size,"can_get_gift_id='%ld'",(int64_t)can_get_gift_id);}

    int32_t get_instance_reset_count() const { return instance_reset_count;} ; 
    void set_instance_reset_count(int32_t value) { if(instance_reset_count!= value){dirty[61] = 1; instance_reset_count = value;} } ; 
    int sql_instance_reset_count(char* buf,int size) const{return snprintf(buf,size,"instance_reset_count='%ld'",(int64_t)instance_reset_count);}

    int32_t get_last_instance_reset_time() const { return last_instance_reset_time;} ; 
    void set_last_instance_reset_time(int32_t value) { if(last_instance_reset_time!= value){dirty[62] = 1; last_instance_reset_time = value;} } ; 
    int sql_last_instance_reset_time(char* buf,int size) const{return snprintf(buf,size,"last_instance_reset_time='%ld'",(int64_t)last_instance_reset_time);}

    int32_t get_follow_buddy_id() const { return follow_buddy_id;} ; 
    void set_follow_buddy_id(int32_t value) { if(follow_buddy_id!= value){dirty[63] = 1; follow_buddy_id = value;} } ; 
    int sql_follow_buddy_id(char* buf,int size) const{return snprintf(buf,size,"follow_buddy_id='%ld'",(int64_t)follow_buddy_id);}

    int32_t get_total_online_time() const { return total_online_time;} ; 
    void set_total_online_time(int32_t value) { if(total_online_time!= value){dirty[64] = 1; total_online_time = value;} } ; 
    int sql_total_online_time(char* buf,int size) const{return snprintf(buf,size,"total_online_time='%ld'",(int64_t)total_online_time);}

    const string& get_learned_guild_skills() const { return learned_guild_skills;} ; 
    void set_learned_guild_skills(const string& value) { if(learned_guild_skills!= value){dirty[65] = 1; learned_guild_skills.assign(value);} }; 
    void set_learned_guild_skills(const char* value) { if(strcmp(learned_guild_skills.c_str(),value)!=0) {dirty[65] = 1; learned_guild_skills.assign(value);} }; 
    int sql_learned_guild_skills(char* buf,int size) const{return snprintf(buf,size,"learned_guild_skills='%s'",learned_guild_skills.c_str());}

    int32_t get_wing_tid() const { return wing_tid;} ; 
    void set_wing_tid(int32_t value) { if(wing_tid!= value){dirty[66] = 1; wing_tid = value;} } ; 
    int sql_wing_tid(char* buf,int size) const{return snprintf(buf,size,"wing_tid='%ld'",(int64_t)wing_tid);}

    int32_t get_daily_first_charge_value() const { return daily_first_charge_value;} ; 
    void set_daily_first_charge_value(int32_t value) { if(daily_first_charge_value!= value){dirty[67] = 1; daily_first_charge_value = value;} } ; 
    int sql_daily_first_charge_value(char* buf,int size) const{return snprintf(buf,size,"daily_first_charge_value='%ld'",(int64_t)daily_first_charge_value);}

    int32_t get_daily_first_charge_time() const { return daily_first_charge_time;} ; 
    void set_daily_first_charge_time(int32_t value) { if(daily_first_charge_time!= value){dirty[68] = 1; daily_first_charge_time = value;} } ; 
    int sql_daily_first_charge_time(char* buf,int size) const{return snprintf(buf,size,"daily_first_charge_time='%ld'",(int64_t)daily_first_charge_time);}

    int16_t get_last_map_id() const { return last_map_id;} ; 
    void set_last_map_id(int16_t value) { if(last_map_id!= value){dirty[69] = 1; last_map_id = value;} } ; 
    int sql_last_map_id(char* buf,int size) const{return snprintf(buf,size,"last_map_id='%ld'",(int64_t)last_map_id);}

    int16_t get_last_map_x() const { return last_map_x;} ; 
    void set_last_map_x(int16_t value) { if(last_map_x!= value){dirty[70] = 1; last_map_x = value;} } ; 
    int sql_last_map_x(char* buf,int size) const{return snprintf(buf,size,"last_map_x='%ld'",(int64_t)last_map_x);}

    int16_t get_last_map_y() const { return last_map_y;} ; 
    void set_last_map_y(int16_t value) { if(last_map_y!= value){dirty[71] = 1; last_map_y = value;} } ; 
    int sql_last_map_y(char* buf,int size) const{return snprintf(buf,size,"last_map_y='%ld'",(int64_t)last_map_y);}

    int32_t get_alien_boss_diamond_buff() const { return alien_boss_diamond_buff;} ; 
    void set_alien_boss_diamond_buff(int32_t value) { if(alien_boss_diamond_buff!= value){dirty[72] = 1; alien_boss_diamond_buff = value;} } ; 
    int sql_alien_boss_diamond_buff(char* buf,int size) const{return snprintf(buf,size,"alien_boss_diamond_buff='%ld'",(int64_t)alien_boss_diamond_buff);}

    int32_t get_alien_boss_coin_buff() const { return alien_boss_coin_buff;} ; 
    void set_alien_boss_coin_buff(int32_t value) { if(alien_boss_coin_buff!= value){dirty[73] = 1; alien_boss_coin_buff = value;} } ; 
    int sql_alien_boss_coin_buff(char* buf,int size) const{return snprintf(buf,size,"alien_boss_coin_buff='%ld'",(int64_t)alien_boss_coin_buff);}

    int32_t get_killed_time() const { return killed_time;} ; 
    void set_killed_time(int32_t value) { if(killed_time!= value){dirty[74] = 1; killed_time = value;} } ; 
    int sql_killed_time(char* buf,int size) const{return snprintf(buf,size,"killed_time='%ld'",(int64_t)killed_time);}

    int32_t get_title() const { return title;} ; 
    void set_title(int32_t value) { if(title!= value){dirty[75] = 1; title = value;} } ; 
    int sql_title(char* buf,int size) const{return snprintf(buf,size,"title='%ld'",(int64_t)title);}

    int32_t get_cur_auto_instance_count() const { return cur_auto_instance_count;} ; 
    void set_cur_auto_instance_count(int32_t value) { if(cur_auto_instance_count!= value){dirty[76] = 1; cur_auto_instance_count = value;} } ; 
    int sql_cur_auto_instance_count(char* buf,int size) const{return snprintf(buf,size,"cur_auto_instance_count='%ld'",(int64_t)cur_auto_instance_count);}

    int32_t get_max_auto_instance_count() const { return max_auto_instance_count;} ; 
    void set_max_auto_instance_count(int32_t value) { if(max_auto_instance_count!= value){dirty[77] = 1; max_auto_instance_count = value;} } ; 
    int sql_max_auto_instance_count(char* buf,int size) const{return snprintf(buf,size,"max_auto_instance_count='%ld'",(int64_t)max_auto_instance_count);}

    int32_t get_last_auto_instance_time() const { return last_auto_instance_time;} ; 
    void set_last_auto_instance_time(int32_t value) { if(last_auto_instance_time!= value){dirty[78] = 1; last_auto_instance_time = value;} } ; 
    int sql_last_auto_instance_time(char* buf,int size) const{return snprintf(buf,size,"last_auto_instance_time='%ld'",(int64_t)last_auto_instance_time);}

private:
    //data member
    int32_t role_id ; 
    int32_t uid ; 
    int32_t vip_end_ts ; 
    int8_t vip_level ; 
    int8_t gender ; 
    int8_t job_type ; 
    int8_t role_level ; 
    int32_t role_exp ; 
    int32_t tid ; 
    int32_t coin ; 
    int32_t coupon ; 
    int32_t diamond ; 
    int16_t map_id ; 
    int16_t map_x ; 
    int16_t map_y ; 
    int16_t depot_size ; 
    int16_t bag_size ; 
    int16_t flag ; 
    int8_t buddy_size ; 
    int8_t lineup_size ; 
    int8_t status ; 
    int32_t server_id ; 
    int32_t team_id ; 
    int32_t team_create_time ; 
    int32_t login_time ; 
    string login_ip ; 
    int32_t default_lineup_id ; 
    int32_t create_time ; 
    string name ; 
    int32_t yingling_slot ; 
    int32_t hiring_yingling_slot ; 
    int32_t hiring_yingling_lingli ; 
    int32_t max_none_cooldown_hiring_count ; 
    int32_t cur_none_cooldown_hiring_count ; 
    int64_t hiring_cooldown_tick ; 
    string hiring_yingling_list ; 
    string daily_quest_data ; 
    string flags_data ; 
    string hide_data ; 
    int32_t instance_count ; 
    int32_t instance_time ; 
    int32_t guild_id ; 
    int32_t guild_time ; 
    string guild_name ; 
    int32_t last_fight_time ; 
    int32_t last_battle_id ; 
    int32_t last_take_monster_exp_time ; 
    int32_t taken_monster_exp_times_this_week ; 
    int32_t lineup_capacity ; 
    int32_t buff_2_id ; 
    int32_t buff_2_expire_time ; 
    int32_t buff_1_id ; 
    int32_t buff_1_expire_time ; 
    int32_t phy_strength ; 
    int32_t extra_phy_strength ; 
    int32_t time_to_recover_phy_strength ; 
    int32_t time_to_recover_extra_phy_strength ; 
    int32_t last_logoff_time ; 
    int32_t total_online_time_of_day ; 
    int32_t today_taken_bonus_max_time ; 
    int32_t can_get_gift_id ; 
    int32_t instance_reset_count ; 
    int32_t last_instance_reset_time ; 
    int32_t follow_buddy_id ; 
    int32_t total_online_time ; 
    string learned_guild_skills ; 
    int32_t wing_tid ; 
    int32_t daily_first_charge_value ; 
    int32_t daily_first_charge_time ; 
    int16_t last_map_id ; 
    int16_t last_map_x ; 
    int16_t last_map_y ; 
    int32_t alien_boss_diamond_buff ; 
    int32_t alien_boss_coin_buff ; 
    int32_t killed_time ; 
    int32_t title ; 
    int32_t cur_auto_instance_count ; 
    int32_t max_auto_instance_count ; 
    int32_t last_auto_instance_time ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 79 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
