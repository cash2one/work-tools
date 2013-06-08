/*******************************************************************************
 *
 *      @file: pvp_act_prototype.h
 *      @brief: pvp活动配置解析
 *
 *      @author: gxl.
 *      @Date: 2013/05/04
 *      COPYRIGHT (C) 2013, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef PVP_ACTIVITY_PROTOTYPE_H
#define PVP_ACTIVITY_PROTOTYPE_H

#include "pvp_fight_bonus.pb.h"
#include "pvp_level_bonus.pb.h"
#include "pvp_level_up_win_count.pb.h"
#include "pvp_map_born_place.pb.h"
#include "pvp_winner_bonus.pb.h"
#include "pvp_level_robot.pb.h"

#include <set>
#include <map>

class PvPActProtoManager
{
public:
	PvPActProtoManager();
	~PvPActProtoManager();

	bool InitPvPFightBonusData(const char* data_file);
	bool InitPvPLevelBonusData(const char* data_file);
	bool InitPvPLevelUpWinCountData(const char* data_file);
	bool InitPvPMapBornPlaceData(const char* data_file);
	bool InitPvPWinnerBonusData(const char* data_file);
	bool InitPvPLevelRobotData(const char* data_file);

	const PvPFightBonusData*  GetPvPFightBonusData(int defender_level);
	const PvPLevelBonusData*  GetPvPLevelBonusData(int map_level);

	bool  is_pvp_map(int map_id);

	int   GetPvPLevelUpWinCount(int map_level);

	int   GetMapLevel(int map_id);

	const PvPMapBornPlaceData* GetRandomBornPlace(int map_level);

	const PvPWinnerBonusData* GetPvPWinnerBonusData(int winner_rank);

	int   GetPvPLevelNpcId(int map_level);

	void clear();

private:

	PvPFightBonusDataGroup   m_fight_bonus_group;
	PvPLevelBonusDataGroup   m_level_bonus_group;
	PvPWinnerBonusDataGroup  m_winner_bonus_group;

	PvPMapBornPlaceDataGroup     m_map_born_place_group;


	typedef std::map<int, int>  IntMap;
	typedef std::set<const PvPMapBornPlaceData*>  MapBornPlaceSet;

	// [ level, set ] 每层配置4个出生点
	typedef std::map<int, MapBornPlaceSet>        LevelBornPlaceMap;
	LevelBornPlaceMap          m_level_born_place_map;

	// [ map_level, map_id]
	IntMap                     m_level_to_map_id;
	IntMap                     m_map_id_to_level; 

	// [defender_level, fight_bonus_data]
	typedef std::map<int, const PvPFightBonusData*>  PvPFightBonusMap;
	PvPFightBonusMap           m_pvp_fight_bonus_map;

	// [ pvp_level , data] 
	typedef std::map<int, const PvPLevelBonusData*>  PvPLevelBonusMap;
	PvPLevelBonusMap            m_pvp_level_bonus_map;

	// [level, win_count]
	IntMap           m_level_win_count_map;
	
	// [level, npc_id]
	IntMap           m_level_robot_id;

};



#endif






