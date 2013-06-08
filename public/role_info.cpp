#include "role_info.h" 

role_info::role_info()
{
    role_id = 0;
    uid = 0;
    vip_end_ts = 0;
    vip_level = 0;
    gender = 0;
    job_type = 0;
    role_level = 0;
    role_exp = 0;
    tid = 0;
    coin = 0;
    coupon = 0;
    diamond = 0;
    map_id = 0;
    map_x = 0;
    map_y = 0;
    depot_size = 0;
    bag_size = 0;
    flag = 0;
    buddy_size = 0;
    lineup_size = 0;
    status = 0;
    server_id = 0;
    team_id = 0;
    team_create_time = 0;
    login_time = 0;
    default_lineup_id = 0;
    create_time = 0;
    yingling_slot = 0;
    hiring_yingling_slot = 0;
    hiring_yingling_lingli = 0;
    max_none_cooldown_hiring_count = 0;
    cur_none_cooldown_hiring_count = 0;
    hiring_cooldown_tick = 0;
    instance_count = 0;
    instance_time = 0;
    guild_id = 0;
    guild_time = 0;
    last_fight_time = 0;
    last_battle_id = 0;
    last_take_monster_exp_time = 0;
    taken_monster_exp_times_this_week = 0;
    lineup_capacity = 0;
    buff_2_id = 0;
    buff_2_expire_time = 0;
    buff_1_id = 0;
    buff_1_expire_time = 0;
    phy_strength = 0;
    extra_phy_strength = 0;
    time_to_recover_phy_strength = 0;
    time_to_recover_extra_phy_strength = 0;
    last_logoff_time = 0;
    total_online_time_of_day = 0;
    today_taken_bonus_max_time = 0;
    can_get_gift_id = 0;
    instance_reset_count = 0;
    last_instance_reset_time = 0;
    follow_buddy_id = 0;
    total_online_time = 0;
    wing_tid = 0;
    daily_first_charge_value = 0;
    daily_first_charge_time = 0;
    last_map_id = 0;
    last_map_x = 0;
    last_map_y = 0;
    alien_boss_diamond_buff = 0;
    alien_boss_coin_buff = 0;
    killed_time = 0;
    title = 0;
    cur_auto_instance_count = 0;
    max_auto_instance_count = 0;
    last_auto_instance_time = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_info::load(const char** data)
{
    role_id = (int32_t)atoi(data[0]);
    uid = (int32_t)atoi(data[1]);
    vip_end_ts = (int32_t)atoi(data[2]);
    vip_level = (int8_t)atoi(data[3]);
    gender = (int8_t)atoi(data[4]);
    job_type = (int8_t)atoi(data[5]);
    role_level = (int8_t)atoi(data[6]);
    role_exp = (int32_t)atoi(data[7]);
    tid = (int32_t)atoi(data[8]);
    coin = (int32_t)atoi(data[9]);
    coupon = (int32_t)atoi(data[10]);
    diamond = (int32_t)atoi(data[11]);
    map_id = (int16_t)atoi(data[12]);
    map_x = (int16_t)atoi(data[13]);
    map_y = (int16_t)atoi(data[14]);
    depot_size = (int16_t)atoi(data[15]);
    bag_size = (int16_t)atoi(data[16]);
    flag = (int16_t)atoi(data[17]);
    buddy_size = (int8_t)atoi(data[18]);
    lineup_size = (int8_t)atoi(data[19]);
    status = (int8_t)atoi(data[20]);
    server_id = (int32_t)atoi(data[21]);
    team_id = (int32_t)atoi(data[22]);
    team_create_time = (int32_t)atoi(data[23]);
    login_time = (int32_t)atoi(data[24]);
    login_ip.assign(data[25]);
    default_lineup_id = (int32_t)atoi(data[26]);
    create_time = (int32_t)atoi(data[27]);
    name.assign(data[28]);
    yingling_slot = (int32_t)atoi(data[29]);
    hiring_yingling_slot = (int32_t)atoi(data[30]);
    hiring_yingling_lingli = (int32_t)atoi(data[31]);
    max_none_cooldown_hiring_count = (int32_t)atoi(data[32]);
    cur_none_cooldown_hiring_count = (int32_t)atoi(data[33]);
    hiring_cooldown_tick = (int64_t)atol(data[34]);
    hiring_yingling_list.assign(data[35]);
    daily_quest_data.assign(data[36]);
    flags_data.assign(data[37]);
    hide_data.assign(data[38]);
    instance_count = (int32_t)atoi(data[39]);
    instance_time = (int32_t)atoi(data[40]);
    guild_id = (int32_t)atoi(data[41]);
    guild_time = (int32_t)atoi(data[42]);
    guild_name.assign(data[43]);
    last_fight_time = (int32_t)atoi(data[44]);
    last_battle_id = (int32_t)atoi(data[45]);
    last_take_monster_exp_time = (int32_t)atoi(data[46]);
    taken_monster_exp_times_this_week = (int32_t)atoi(data[47]);
    lineup_capacity = (int32_t)atoi(data[48]);
    buff_2_id = (int32_t)atoi(data[49]);
    buff_2_expire_time = (int32_t)atoi(data[50]);
    buff_1_id = (int32_t)atoi(data[51]);
    buff_1_expire_time = (int32_t)atoi(data[52]);
    phy_strength = (int32_t)atoi(data[53]);
    extra_phy_strength = (int32_t)atoi(data[54]);
    time_to_recover_phy_strength = (int32_t)atoi(data[55]);
    time_to_recover_extra_phy_strength = (int32_t)atoi(data[56]);
    last_logoff_time = (int32_t)atoi(data[57]);
    total_online_time_of_day = (int32_t)atoi(data[58]);
    today_taken_bonus_max_time = (int32_t)atoi(data[59]);
    can_get_gift_id = (int32_t)atoi(data[60]);
    instance_reset_count = (int32_t)atoi(data[61]);
    last_instance_reset_time = (int32_t)atoi(data[62]);
    follow_buddy_id = (int32_t)atoi(data[63]);
    total_online_time = (int32_t)atoi(data[64]);
    learned_guild_skills.assign(data[65]);
    wing_tid = (int32_t)atoi(data[66]);
    daily_first_charge_value = (int32_t)atoi(data[67]);
    daily_first_charge_time = (int32_t)atoi(data[68]);
    last_map_id = (int16_t)atoi(data[69]);
    last_map_x = (int16_t)atoi(data[70]);
    last_map_y = (int16_t)atoi(data[71]);
    alien_boss_diamond_buff = (int32_t)atoi(data[72]);
    alien_boss_coin_buff = (int32_t)atoi(data[73]);
    killed_time = (int32_t)atoi(data[74]);
    title = (int32_t)atoi(data[75]);
    cur_auto_instance_count = (int32_t)atoi(data[76]);
    max_auto_instance_count = (int32_t)atoi(data[77]);
    last_auto_instance_time = (int32_t)atoi(data[78]);
    memset(dirty,0,sizeof(dirty));
}
void role_info::load(const vector<string>& data)
{
    role_id = (int32_t)atoi(data[0].c_str());
    uid = (int32_t)atoi(data[1].c_str());
    vip_end_ts = (int32_t)atoi(data[2].c_str());
    vip_level = (int8_t)atoi(data[3].c_str());
    gender = (int8_t)atoi(data[4].c_str());
    job_type = (int8_t)atoi(data[5].c_str());
    role_level = (int8_t)atoi(data[6].c_str());
    role_exp = (int32_t)atoi(data[7].c_str());
    tid = (int32_t)atoi(data[8].c_str());
    coin = (int32_t)atoi(data[9].c_str());
    coupon = (int32_t)atoi(data[10].c_str());
    diamond = (int32_t)atoi(data[11].c_str());
    map_id = (int16_t)atoi(data[12].c_str());
    map_x = (int16_t)atoi(data[13].c_str());
    map_y = (int16_t)atoi(data[14].c_str());
    depot_size = (int16_t)atoi(data[15].c_str());
    bag_size = (int16_t)atoi(data[16].c_str());
    flag = (int16_t)atoi(data[17].c_str());
    buddy_size = (int8_t)atoi(data[18].c_str());
    lineup_size = (int8_t)atoi(data[19].c_str());
    status = (int8_t)atoi(data[20].c_str());
    server_id = (int32_t)atoi(data[21].c_str());
    team_id = (int32_t)atoi(data[22].c_str());
    team_create_time = (int32_t)atoi(data[23].c_str());
    login_time = (int32_t)atoi(data[24].c_str());
    login_ip.assign(data[25].c_str());
    default_lineup_id = (int32_t)atoi(data[26].c_str());
    create_time = (int32_t)atoi(data[27].c_str());
    name.assign(data[28].c_str());
    yingling_slot = (int32_t)atoi(data[29].c_str());
    hiring_yingling_slot = (int32_t)atoi(data[30].c_str());
    hiring_yingling_lingli = (int32_t)atoi(data[31].c_str());
    max_none_cooldown_hiring_count = (int32_t)atoi(data[32].c_str());
    cur_none_cooldown_hiring_count = (int32_t)atoi(data[33].c_str());
    hiring_cooldown_tick = (int64_t)atol(data[34].c_str());
    hiring_yingling_list.assign(data[35].c_str());
    daily_quest_data.assign(data[36].c_str());
    flags_data.assign(data[37].c_str());
    hide_data.assign(data[38].c_str());
    instance_count = (int32_t)atoi(data[39].c_str());
    instance_time = (int32_t)atoi(data[40].c_str());
    guild_id = (int32_t)atoi(data[41].c_str());
    guild_time = (int32_t)atoi(data[42].c_str());
    guild_name.assign(data[43].c_str());
    last_fight_time = (int32_t)atoi(data[44].c_str());
    last_battle_id = (int32_t)atoi(data[45].c_str());
    last_take_monster_exp_time = (int32_t)atoi(data[46].c_str());
    taken_monster_exp_times_this_week = (int32_t)atoi(data[47].c_str());
    lineup_capacity = (int32_t)atoi(data[48].c_str());
    buff_2_id = (int32_t)atoi(data[49].c_str());
    buff_2_expire_time = (int32_t)atoi(data[50].c_str());
    buff_1_id = (int32_t)atoi(data[51].c_str());
    buff_1_expire_time = (int32_t)atoi(data[52].c_str());
    phy_strength = (int32_t)atoi(data[53].c_str());
    extra_phy_strength = (int32_t)atoi(data[54].c_str());
    time_to_recover_phy_strength = (int32_t)atoi(data[55].c_str());
    time_to_recover_extra_phy_strength = (int32_t)atoi(data[56].c_str());
    last_logoff_time = (int32_t)atoi(data[57].c_str());
    total_online_time_of_day = (int32_t)atoi(data[58].c_str());
    today_taken_bonus_max_time = (int32_t)atoi(data[59].c_str());
    can_get_gift_id = (int32_t)atoi(data[60].c_str());
    instance_reset_count = (int32_t)atoi(data[61].c_str());
    last_instance_reset_time = (int32_t)atoi(data[62].c_str());
    follow_buddy_id = (int32_t)atoi(data[63].c_str());
    total_online_time = (int32_t)atoi(data[64].c_str());
    learned_guild_skills.assign(data[65].c_str());
    wing_tid = (int32_t)atoi(data[66].c_str());
    daily_first_charge_value = (int32_t)atoi(data[67].c_str());
    daily_first_charge_time = (int32_t)atoi(data[68].c_str());
    last_map_id = (int16_t)atoi(data[69].c_str());
    last_map_x = (int16_t)atoi(data[70].c_str());
    last_map_y = (int16_t)atoi(data[71].c_str());
    alien_boss_diamond_buff = (int32_t)atoi(data[72].c_str());
    alien_boss_coin_buff = (int32_t)atoi(data[73].c_str());
    killed_time = (int32_t)atoi(data[74].c_str());
    title = (int32_t)atoi(data[75].c_str());
    cur_auto_instance_count = (int32_t)atoi(data[76].c_str());
    max_auto_instance_count = (int32_t)atoi(data[77].c_str());
    last_auto_instance_time = (int32_t)atoi(data[78].c_str());
    memset(dirty,0,sizeof(dirty));
}
int role_info::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_data(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if(dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_uid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_vip_end_ts(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_vip_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_gender(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_job_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_exp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_coin(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_coupon(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_diamond(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_x(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[14])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_y(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[15])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_depot_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[16])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_bag_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[17])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_flag(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[18])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buddy_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[19])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_lineup_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[20])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[21])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[22])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_team_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[23])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_team_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[24])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_login_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[25])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_login_ip(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[26])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_default_lineup_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[27])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[28])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[29])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_yingling_slot(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[30])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_hiring_yingling_slot(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[31])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_hiring_yingling_lingli(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[32])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_max_none_cooldown_hiring_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[33])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_cur_none_cooldown_hiring_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[34])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_hiring_cooldown_tick(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[35])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_hiring_yingling_list(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[36])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_daily_quest_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[37])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_flags_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[38])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_hide_data(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[39])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_instance_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[40])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_instance_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[41])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[42])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[43])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[44])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_fight_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[45])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_battle_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[46])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_take_monster_exp_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[47])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_taken_monster_exp_times_this_week(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[48])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_lineup_capacity(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[49])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buff_2_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[50])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buff_2_expire_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[51])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buff_1_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[52])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buff_1_expire_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[53])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[54])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_extra_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[55])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_time_to_recover_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[56])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_time_to_recover_extra_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[57])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_logoff_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[58])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_total_online_time_of_day(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[59])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_today_taken_bonus_max_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[60])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_can_get_gift_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[61])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_instance_reset_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[62])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_instance_reset_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[63])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_follow_buddy_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[64])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_total_online_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[65])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_learned_guild_skills(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[66])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_wing_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[67])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_daily_first_charge_value(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[68])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_daily_first_charge_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[69])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_map_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[70])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_map_x(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[71])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_map_y(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[72])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_alien_boss_diamond_buff(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[73])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_alien_boss_coin_buff(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[74])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_killed_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[75])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_title(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[76])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_cur_auto_instance_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[77])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_max_auto_instance_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if(dirty[78])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_auto_instance_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_info::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
