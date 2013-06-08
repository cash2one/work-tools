/*******************************************************************************
 *
 *      @file: pvp_act_prototype.cpp
 *      @brief: pvpªÓ∂Ø≈‰÷√Ω‚Œˆ
 *
 *      @author: gxl.
 *      @Date: 2013/05/04
 *      COPYRIGHT (C) 2013, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <fstream>
#include "pvp_act_prototype.h"

using namespace std;

PvPActProtoManager::PvPActProtoManager()
{

}

PvPActProtoManager::~PvPActProtoManager()
{
	clear();
}

bool PvPActProtoManager::InitPvPFightBonusData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_fight_bonus_group.ParseFromIstream(&fs)) return false;

	for (int i = 0; i < m_fight_bonus_group.data_size(); i++)
	{
		const PvPFightBonusData& d = m_fight_bonus_group.data(i);
		for (int level=d.defender_level_min(); level <= d.defender_level_max(); level++)
		{
			m_pvp_fight_bonus_map.insert(make_pair(level, &d));
		}
	}

	return true;
}

bool PvPActProtoManager::InitPvPLevelBonusData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_level_bonus_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i < m_level_bonus_group.data_size(); ++i)
	{
		const PvPLevelBonusData& d = m_level_bonus_group.data(i);
		m_pvp_level_bonus_map.insert(make_pair(d.level(), &d));
	}

	return true;
}

bool PvPActProtoManager::InitPvPLevelUpWinCountData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	PvPLevelUpWinCountDataGroup  level_up_win_count_group;
	if (!level_up_win_count_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i < level_up_win_count_group.data_size(); ++i)
	{
		const PvPLevelUpWinCountData& d = level_up_win_count_group.data(i);
		for (int level=d.level_min(); level <= d.level_max(); level++)
		{
			m_level_win_count_map.insert(make_pair(level, d.win_count()));
		}
	}

	return true;
}

bool PvPActProtoManager::InitPvPMapBornPlaceData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_map_born_place_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i < m_map_born_place_group.data_size(); ++i)
	{
		const PvPMapBornPlaceData& d = m_map_born_place_group.data(i);

		if (m_level_to_map_id.count(d.level()) == 0)
		{
			m_level_to_map_id[d.level()] = d.map_id();
		}

		if (m_map_id_to_level.count(d.map_id()) == 0)
		{
			m_map_id_to_level[d.map_id()] = d.level();
		}
		
		MapBornPlaceSet&  place_set = m_level_born_place_map[d.level()];
		place_set.insert(&d);
	}

	return true;
}

int   PvPActProtoManager::GetMapLevel(int map_id)
{
	if (m_map_id_to_level.count(map_id))
	{
		return m_map_id_to_level[map_id];
	}
	return 0;
}

bool  PvPActProtoManager::is_pvp_map(int map_id)
{
	return m_map_id_to_level.count(map_id) > 0;
}

bool PvPActProtoManager::InitPvPWinnerBonusData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_winner_bonus_group.ParseFromIstream(&fs)) return false;

	return true;
}

bool PvPActProtoManager::InitPvPLevelRobotData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	PvPLevelRobotDataGroup data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i < data_group_.data_size(); i++)
	{
		const PvPLevelRobotData& d = data_group_.data(i);
		m_level_robot_id[d.level()] = d.robot_npc_id();
	}

	return true;
}

void PvPActProtoManager::clear()
{
	m_pvp_fight_bonus_map.clear();
	m_fight_bonus_group.Clear();
	
	m_pvp_level_bonus_map.clear();
	
	m_level_bonus_group.Clear();
	m_level_win_count_map.clear();

	m_level_to_map_id.clear();
	m_map_id_to_level.clear();
	m_level_born_place_map.clear();
	m_map_born_place_group.Clear();

	m_winner_bonus_group.Clear();

	m_level_robot_id.clear();
}

int   PvPActProtoManager::GetPvPLevelNpcId(int map_level)
{
	if (m_level_robot_id.count(map_level))
	{
		return m_level_robot_id[map_level];
	}
	return 0;
}


const PvPFightBonusData*  PvPActProtoManager::GetPvPFightBonusData(int defender_level)
{
	if (m_pvp_fight_bonus_map.count(defender_level))
	{
		return m_pvp_fight_bonus_map[defender_level];
	}
	
	return NULL;
}

const PvPLevelBonusData*  PvPActProtoManager::GetPvPLevelBonusData(int map_level)
{
	if (m_pvp_level_bonus_map.count(map_level))
	{
		return m_pvp_level_bonus_map[map_level];
	}
	return NULL;
}

int  PvPActProtoManager::GetPvPLevelUpWinCount(int map_level)
{
	if (m_level_win_count_map.count(map_level))
	{
		return m_level_win_count_map[map_level];
	}
	
	return 0;
}

const PvPMapBornPlaceData* PvPActProtoManager::GetRandomBornPlace(int map_level)
{
	if (m_level_born_place_map.count(map_level))
	{
		MapBornPlaceSet&  place_set = m_level_born_place_map[map_level];
		if (place_set.size() > 0)
		{
			int index = random() % place_set.size(); 
			MapBornPlaceSet::iterator  itor = place_set.begin();
			for (int i=0; i < index; i++)
			{
				++itor;
			}

			if (itor != place_set.end())
			{
				return *itor;
			}
			else
			{
				assert(0);
			}
		}
	}
	
	return NULL;
}


const PvPWinnerBonusData* PvPActProtoManager::GetPvPWinnerBonusData(int winner_rank)
{
	for (int i=0; i < m_winner_bonus_group.data_size(); i++)
	{
		const PvPWinnerBonusData& d = m_winner_bonus_group.data(i);
		if (winner_rank == d.bonus_type())
		{
			return &d;
		}
	}
	
	return NULL;
}




