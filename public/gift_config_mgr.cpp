/*******************************************************************************
 *
 *      @file: gift_config_mgr.h
 *      @brief: 各种礼品配置数据.
 *
 *      @author: gxl.
 *      @Date: 2012/09/14
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <assert.h>
#include <fstream>
#include "gift_config_mgr.h"

using namespace std;

GiftConfigManager::~GiftConfigManager()
{
	m_online_time_bonus.clear();
}


bool GiftConfigManager::InitTimeBonus(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!m_online_time_bonus_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i< m_online_time_bonus_group.bonus_item_size(); ++i)
	{
		const OnlineTimeBonusData& d = m_online_time_bonus_group.bonus_item(i);
		if (d.online_time() > 0 && d.item_id() >= 0)
		{
			m_online_time_bonus[d.online_time()] = d.item_id();
		}
	}


	return true;
}

// @return : >=0 gift item id.
//           < 0 no gift yet.
int  GiftConfigManager::get_gift_item_id(int acc_time, int already_take_max_time, int& cur_can_get_time_point)
{
	if (acc_time <= already_take_max_time)
	{
		return -1;
	}
	
	for (OnlineTimeBonusCfgMap::iterator itor = m_online_time_bonus.begin();
		itor != m_online_time_bonus.end(); ++itor)
	{
		if (itor->first <= already_take_max_time) continue ;
		
		if (acc_time > itor->first)
		{
			cur_can_get_time_point = itor->first;
			return itor->second;
		}
	}

	cur_can_get_time_point = -1;
	return -1;
}

int  GiftConfigManager::get_next_gift_item_id(int already_take_max_time)
{
	if (already_take_max_time < 0) return -1;

	for (OnlineTimeBonusCfgMap::iterator itor = m_online_time_bonus.begin();
		itor != m_online_time_bonus.end(); ++itor)
	{
		if (itor->first <= already_take_max_time) continue ;

		return itor->second;
	}

	return -1;
}

OnlineTimeBonusCfgMap*  GiftConfigManager::get_online_time_bonus_cfg()
{
	return &m_online_time_bonus ;
}

int  GiftConfigManager::get_next_step_time(int already_take_max_time)
{
	for (OnlineTimeBonusCfgMap::iterator itor = m_online_time_bonus.begin();
		itor != m_online_time_bonus.end(); ++itor)
	{
		if (itor->first <= already_take_max_time) continue ;

		if (already_take_max_time < itor->first)
		{
			return itor->first;
		}
	}

	return -1;
}





