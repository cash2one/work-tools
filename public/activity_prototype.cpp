/*******************************************************************************
 *
 *      @file: activity_prototype.cpp
 *      @brief: 活动配置解析
 *
 *      @author: gxl.
 *      @Date: 2013/03/26
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <fstream>
#include "activity_prototype.h"

using namespace std;

ActivityProtoManager::ActivityProtoManager()
{

}
ActivityProtoManager::~ActivityProtoManager()
{
	clear();
}

void ActivityProtoManager::clear()
{
	m_level_gift_map.clear();
	m_fight_gift_map.clear();
	m_fight_gift_data_group.Clear();

	m_act_time_map.clear();
	m_act_time_group.Clear();

	m_boss_attr_incr_map.clear();
	m_boss_bonus_map.clear();

	m_boss_bonus_group.Clear();
	m_boss_attr_group.Clear();

}

bool ActivityProtoManager::InitLevelupGiftData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	LevelupGiftDataGroup  data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.gift_data_size(); ++i)
	{
		const LevelupGiftData& d = data_group_.gift_data(i);
		m_level_gift_map[d.level()] = d.gift_id();
	}

	return true;
}

bool ActivityProtoManager::InitFightCapacityGiftData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_fight_gift_data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<m_fight_gift_data_group.gift_data_size(); ++i)
	{
		const FightCapacityGiftData& d = m_fight_gift_data_group.gift_data(i);
		m_fight_gift_map[d.id()] = &d;
	}

	return true;

}

bool ActivityProtoManager::InitActivityTimeData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_act_time_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<m_act_time_group.activity_time_size(); ++i)
	{
		const ActivityTimeData& d = m_act_time_group.activity_time(i);
		m_act_time_map.insert(make_pair(d.id(), &d));		
	}

	return true;
}

bool ActivityProtoManager::InitBossAttrIncrData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_boss_attr_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<m_boss_attr_group.boss_attr_data_size(); ++i)
	{
		const AlienBossAttrIncrData& d = m_boss_attr_group.boss_attr_data(i);
		m_boss_attr_incr_map.insert(make_pair(d.kill_boss_time(), &d));	
	}

	return true;
}

bool ActivityProtoManager::InitAlienBossBonusData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_boss_bonus_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<m_boss_bonus_group.bonus_data_size(); ++i)
	{
		const AlienBossBonusData& d = m_boss_bonus_group.bonus_data(i);
		m_boss_bonus_map.insert(make_pair(d.bonus_type(), &d));	
	}

	return true;
}

bool ActivityProtoManager::InitLuckyWheelBonusData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_luck_wheel_bonus_group.ParseFromIstream(&fs)) return false;

	return true;
}

bool ActivityProtoManager::InitActExchangeData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_act_exchange_group.ParseFromIstream(&fs)) return false;

	return true;
}

bool ActivityProtoManager::InitActTreasureBoxData(const char* data_file)
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false;

    if (!m_act_collect_box_data_group.ParseFromIstream(&fs)) return false;
    
    for (int i=0; i < m_act_collect_box_data_group.data_size(); i++)
    {
        const ActCollectTreasureBoxData& d = m_act_collect_box_data_group.data(i);
        m_act_collect_box_map.insert( make_pair(d.act_id(), &d) );
    }

    return true;
}

void ActivityProtoManager::fill_reward_data(TreasureBoxReward& reward, const ActCollectTreasureBoxData* data)
{
    if (data == NULL) return ;

    reward.set_act_id( data->act_id() );
    reward.set_map_id( data->map_id() );
    reward.set_map_x( data->map_x() );
    reward.set_map_y( data->map_y() );
    reward.set_icon_id( data->icon_id() );
}

int  ActivityProtoManager::GenActBoxPos(int act_id, int& drop_id, BoxRewardContainer& box)
{
    ActTreasureBoxRange  range = m_act_collect_box_map.equal_range(act_id);

    int index = 0;
    int max_count = 0;

    vector<const ActCollectTreasureBoxData*>  box_data_array;

    ActTreasureBoxMap::iterator itor = range.first;
    for (; itor != range.second; ++itor)
    {
        const ActCollectTreasureBoxData* data = itor->second ;
        if (max_count == 0) 
        {
            max_count = data->max_count();
            drop_id = data->drop_id();
        }

        box_data_array.push_back(data);
    }

    if ((size_t)max_count > box_data_array.size())
    {
        max_count = box_data_array.size();
    }

    if (box_data_array.size() == 0)
    {
        //error_log_format(get_app().logger, "no treasure box data config for act %d", act_id);
        return 0;
    }
    

    set<int>  chosed_indexes;
    for (int i=0; i < max_count; i++)
    {
        index = random() % box_data_array.size();
        if (chosed_indexes.count(index))
        {
            i--;
            continue;
        }
        
        chosed_indexes.insert(index);

        const ActCollectTreasureBoxData* data = box_data_array[index]; 
        TreasureBoxReward  reward;
        fill_reward_data(reward, data);
        reward.set_index( index++ );

        box.push_back(reward);
    }
   
    return box.size();
}


const LuckyWheelBonusDataGroup* ActivityProtoManager::GetLuckyWheelBonusData()
{
	return &m_luck_wheel_bonus_group;
}

const ActExchangeData*  ActivityProtoManager::GetActExchangeData(int item_id)
{
	for (int i=0; i < m_act_exchange_group.exchange_data_size(); i++)
	{
		const ActExchangeData& data = m_act_exchange_group.exchange_data(i);
		if (data.id() == item_id)
		{
			return &data;
		}
	}
	
	return NULL;
}



const AlienBossBonusData* ActivityProtoManager::GetAlienBossBonusData(AlienBossBonusType type)
{
	if (m_boss_bonus_map.count(type))
	{
		return m_boss_bonus_map[type];
	}
	return NULL;
}

const AlienBossAttrIncrData*  ActivityProtoManager::GetAlienBossAttrIncrData(KillAlienBossTimeType type)
{
	if (m_boss_attr_incr_map.count(type))
	{
		return m_boss_attr_incr_map[type];
	}
	return NULL;
}


int  ActivityProtoManager::GetActivityTimeConfig(int act_id, ActivityTimeSet& time_set)
{
	time_set.clear();

	pair<ActivityTimeMap::const_iterator, ActivityTimeMap::const_iterator> range_pair;

	//range_pair = m_act_time_map.equal_range(act_id);
	auto lower = m_act_time_map.lower_bound(act_id);
	auto upper = m_act_time_map.upper_bound(act_id);
	
	/*
	for (ActivityTimeMap::const_iterator itor = range_pair.first; 
		itor != range_pair.second; ++itor)
	{
		time_set.insert(itor->second);
	}*/

	for (; lower!=upper; lower++) {
		time_set.insert(lower->second);
	}
	
	return time_set.size();
}


const FightCapacityGiftData* 
	ActivityProtoManager::GetFightCapacityGiftData(PlayerFlagType type_)
{
	if (m_fight_gift_map.count(type_))
	{
		return m_fight_gift_map[type_];
	}
	return NULL;
}

/**
@ level : player current level                                       
@ last_gift_id: already taken last gift id, =0 if not taken first yet.
@ gift_ids: all the gift ids it can take. 
@ return number of gift ids.
**/
int  ActivityProtoManager::GetCanGetLevelGiftIds(int level, int last_gift_id, GiftIDSet&  gift_ids)
{
	gift_ids.clear();

	bool  b_find_at_first = false; // 从起始位置开始查找
	if (last_gift_id <= 0) b_find_at_first = true;

	bool  b_found_last_pos = false; // 是否已经找到上一个礼包的位置

	for (LevelGiftMap::iterator itor = m_level_gift_map.begin(); 
		itor != m_level_gift_map.end(); ++itor)
	{
		if (b_find_at_first) // 从起始位置开始查找
		{
			if (level >= itor->first)
			{
				gift_ids.insert(itor->second);
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (b_found_last_pos && level >= itor->first)
			{
				gift_ids.insert(itor->second);
				continue;
			}
			else if (level < itor->first)
			{
				break;
			}

			if (last_gift_id == itor->second)
			{
				b_found_last_pos = true;
			}
		}
	}

	return gift_ids.size();
}

// return gift id if found config, or return -1 no gift to get.
int  ActivityProtoManager::GetNextLevelGiftIds(int level, int last_gift_id)
{
	bool  b_find_at_first = false; // 从起始位置开始查找
	if (last_gift_id <= 0) b_find_at_first = true;
	
	bool  b_found_last_pos = false; // 是否已经找到上一个礼包的位置

	for (LevelGiftMap::iterator itor = m_level_gift_map.begin(); 
		itor != m_level_gift_map.end(); ++itor)
	{
		if (b_find_at_first)
		{
			if (level >= itor->first)
			{
				return itor->second;
			}
			else
			{
				break;
			}
		}
		else // 先要找到上一个礼包的位置
		{
			if (b_found_last_pos && level >= itor->first)
			{
				return itor->second;
			}
			else if (level < itor->first)
			{
				break;
			}
			
			if (last_gift_id == itor->second)
			{
				b_found_last_pos = true;
			}
		}
	}
	
	return -1;
}

