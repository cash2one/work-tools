/*******************************************************************************
 *
 *      @file: arena_config_mgr.h
 *      @brief: 竞技场配置数据.
 *
 *      @author: gxl.
 *      @Date: 2012/08/24
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <assert.h>
#include <fstream>
#include "arena_config_mgr.h"

using namespace std;

bool ArenaConfigManager::InitBuyChallengeTimesCost(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!buy_challenge_times_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i< buy_challenge_times_group.buy_times_cost_size(); ++i)
	{
		const BuyChallengeTimesCostData& d = buy_challenge_times_group.buy_times_cost(i);
		if (d.add_time() > 0)
		{
			challenge_times_map[d.add_time()] = d.cost();
		}
	}

	return true;
}

bool ArenaConfigManager::InitBuyClearCDCost(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!buy_clear_cd_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i < buy_clear_cd_group.clear_cd_cost_size(); i++)
	{
		const BuyClearCDCostData& d = buy_clear_cd_group.clear_cd_cost(i);
		clear_cd_map[d.cooldown_type()] = d.cost();
	}
	
	return true;
}

bool ArenaConfigManager::InitChallengeBonus(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!challenge_bonus_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i < challenge_bonus_group.bonus_data_size(); i++)
	{
		const ChallengeBonusData& d = challenge_bonus_group.bonus_data(i);
		//assert(d.level_high() >= d.level_low());
		if (d.level_high() < d.level_low())
		{
			return false;
		}
		
		bonus_map[make_pair(d.level_low(), d.level_high())] = &d ;
	}

	return true;
}

bool ArenaConfigManager::InitChallengeContWinTitle(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!challenge_cont_win_title_group.ParseFromIstream(&fs))
	{
		return false;
	}
	
	for (int i=0; i < challenge_cont_win_title_group.cont_win_title_data_size(); i++)
	{
		const ChallengeContWinTitleData& d = challenge_cont_win_title_group.cont_win_title_data(i);
		//assert(d.cont_win_times_high() >= d.cont_win_times_low());
		if (d.cont_win_times_high() < d.cont_win_times_low())
		{
			return false;
		}
		
		cont_win_title_map[make_pair(d.cont_win_times_low(), d.cont_win_times_high())] = d.title();
	}
	
	return true;
}

bool ArenaConfigManager::InitChallengeRankTitle(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!challenge_rank_title_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i < challenge_rank_title_group.rank_title_data_size(); i++)
	{
		const ChallengeRankTitleData&  d = challenge_rank_title_group.rank_title_data(i);
		//assert(d.rank_high() == -1 || d.rank_high() >= d.rank_low());
		if (d.rank_high() < d.rank_low() && d.rank_high() != -1)
		{
			return false;
		}
		
		rank_title_map[make_pair(d.rank_low(), d.rank_high())] = d.title();
	}
	
	return true;
}

bool ArenaConfigManager::InitTreasureBox(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!treasure_box_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i < treasure_box_group.box_data_size(); i++)
	{
		const TreasureBoxData& d = treasure_box_group.box_data(i);
		//assert(d.rank_high() == -1 || d.rank_high() >= d.rank_low());
		if (d.rank_high() < d.rank_low())
		{
			return false;
		}
		
		rank_treasure_box_map[make_pair(d.rank_low(), d.rank_high())] = &d;
		treasure_box_map[d.box_id()] = &d ;
	}
	
	return true;
}

// 获得第几次挑战的花费
// @return: -1 means no config
//          >=0 means actual cost
int  ArenaConfigManager::GetChallengeTimesCost(int how_many_times)
{
	ChallengeTimesCostMap::const_iterator  itor = challenge_times_map.find(how_many_times);
	if (itor != challenge_times_map.end())
	{
		return itor->second;
	}
	
	return -1;
}

// 获得不同类型的冷却的花费
int  ArenaConfigManager::GetClearCoolDownCost(int cool_down_type)
{
	ClearCoolDownCostMap::const_iterator itor = clear_cd_map.find(cool_down_type);
	if (itor != clear_cd_map.end())
	{
		return itor->second;
	}
	
	return -1;
}

// 对手等级得到的奖励数据
const ChallengeBonusData* ArenaConfigManager::GetChallengeBonusData(int defender_level)
{
	BonusMap::const_iterator itor = bonus_map.begin();
	for ( ; itor != bonus_map.end(); ++itor)
	{
		const LevelRangePair&  level_pair = itor->first;
		
		if (defender_level >= level_pair.first)
		{
			if (level_pair.second == -1 // -1 means max
				|| defender_level <= level_pair.second)
			{
				return itor->second;
			}
		}
	}
	
	return NULL;
}

// 连胜次数对应的称号id
int ArenaConfigManager::GetContWinTitleID(int cont_win_times)
{
	ContWinTitleMap::const_iterator itor = cont_win_title_map.begin();
	for ( ; itor != cont_win_title_map.end(); ++itor)
	{
		const IntRangePair&  range_pair = itor->first;

		if (cont_win_times >= range_pair.first)
		{
			if (range_pair.second == -1 // -1 means max
				|| cont_win_times <= range_pair.second)
			{
				return itor->second;
			}
		}
	}
	
	return -1;
}

// 排名得到的称号
int ArenaConfigManager::GetRankTitleID(int rank_level)
{
	RankTitleMap::const_iterator itor = rank_title_map.begin();
	for (; itor != rank_title_map.end(); ++itor)
	{
		const RankRangePair&  rank_pair = itor->first;

		if (rank_level >= rank_pair.first)
		{
			if (rank_pair.second == -1 // -1 means max
				|| rank_level <= rank_pair.second)
			{
				return itor->second;
			}
		}
	}
	
	return -1;
}

// 根据宝箱id得到宝箱数据
const TreasureBoxData* ArenaConfigManager::GetTreasureBoxDataByID(int box_id)
{
	TreasureBoxMap::const_iterator itor = treasure_box_map.find(box_id);
	if (itor != treasure_box_map.end())
	{
		return itor->second;
	}
	
	return NULL;
}

// 根据排名等级得到宝箱数据
const TreasureBoxData* ArenaConfigManager::GetTreasureBoxDataByRank(int rank_level)
{
	RankTreasureBoxMap::const_iterator itor = rank_treasure_box_map.begin();
	for (; itor != rank_treasure_box_map.end(); ++itor)
	{
		const RankRangePair&  rank_pair = itor->first;

		if (rank_level >= rank_pair.first)
		{
			if (rank_pair.second == -1 // -1 means max
				|| rank_level <= rank_pair.second)
			{
				return itor->second;
			}
		}
	}

	return NULL;
}
