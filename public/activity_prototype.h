/*******************************************************************************
 *
 *      @file: activity_prototype.h
 *      @brief: 活动配置解析
 *
 *      @author: gxl.
 *      @Date: 2013/03/26
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef ACTIVITY_PROTOTYPE_H
#define ACTIVITY_PROTOTYPE_H

#include <set>
#include <map>
#include <vector>

#include "levelup_gift.pb.h"
#include "fight_capacity_gift.pb.h"
#include "activities_time.pb.h"
#include "alien_boss_bonus.pb.h"
#include "boss_attr_increase.pb.h"
#include "game_common.pb.h"
#include "lucky_wheel_bonus.pb.h"
#include "act_exchange.pb.h"
#include "act_collect_treasure_box.pb.h"

using protocols::common::PlayerFlagType;
using protocols::common::TreasureBoxReward;

typedef std::set<int>  GiftIDSet;

typedef std::set<const ActivityTimeData*>  ActivityTimeSet;
typedef std::multimap<int, const ActivityTimeData*>  ActivityTimeMap; 

typedef std::vector<TreasureBoxReward>  BoxRewardContainer;

enum AlienBossBonusType{
	BOSS_BONUS_TYPE_INVALID = 0,
	BOSS_BONUS_TYPE_BASE_BONUS = 1, // 基础参与奖励
	BOSS_BONUS_TYPE_RANK_1 = 2, // 伤害排名 第一
	BOSS_BONUS_TYPE_RANK_2 = 3, // 排名第二
	BOSS_BONUS_TYPE_RANK_3 = 4,  // 排名第三
	BOSS_BONUS_TYPE_RANK_4_10 = 5, // 排名 4 - 10
	BOSS_BONUS_TYPE_LAST_SHOT = 6, // 最后一击
};

enum KillAlienBossTimeType
{
	KillAlienBossTimeType_LESS_5_MIN = 1, // 小于等于5分钟
	KillAlienBossTimeType_ABOVE_5_MIN = 2, // 大于5分钟
};

class ActivityProtoManager
{
public:
	ActivityProtoManager();
	~ActivityProtoManager();

	void clear();

	bool InitLevelupGiftData(const char* data_file);
	bool InitFightCapacityGiftData(const char* data_file);
	bool InitActivityTimeData(const char* data_file);

	bool InitBossAttrIncrData(const char* data_file);
	bool InitAlienBossBonusData(const char* data_file);

	bool InitLuckyWheelBonusData(const char* data_file);
	bool InitActExchangeData(const char* data_file);

    bool InitActTreasureBoxData(const char* data_file);

    int  GenActBoxPos(int act_id, int& drop_id, BoxRewardContainer& box);
    void fill_reward_data(TreasureBoxReward& reward, const ActCollectTreasureBoxData* data);

	const LuckyWheelBonusDataGroup* GetLuckyWheelBonusData();
	const ActExchangeData*  GetActExchangeData(int item_id);

	const AlienBossBonusData* GetAlienBossBonusData(AlienBossBonusType type);
	const AlienBossAttrIncrData*  GetAlienBossAttrIncrData(KillAlienBossTimeType type);

	int  GetActivityTimeConfig(int act_id, ActivityTimeSet& time_set);

	/**
	 @ level : player current level                                       
	 @ last_gift_id: already taken last gift id, =0 if not taken first yet.
	 @ gift_ids: all the gift ids it can take. 
	 @ return number of gift ids.
	 **/
	int  GetCanGetLevelGiftIds(int level, int last_gift_id, GiftIDSet&  gift_ids);

	// return gift id if found config, or return -1 no gift to get.
	int  GetNextLevelGiftIds(int level, int last_gift_id);
	
	const FightCapacityGiftData* GetFightCapacityGiftData(PlayerFlagType type_);


private:
	typedef std::map<int, int>  LevelGiftMap;
    typedef std::multimap<int, const ActCollectTreasureBoxData*>  ActTreasureBoxMap;
    typedef std::pair< ActTreasureBoxMap::iterator, ActTreasureBoxMap::iterator > ActTreasureBoxRange;

	// [level, gift_id]
	LevelGiftMap            m_level_gift_map;
	
	FightCapacityGiftDataGroup  m_fight_gift_data_group;
	typedef std::map<int, const FightCapacityGiftData*>   FightGiftMap;
	FightGiftMap            m_fight_gift_map;

	// 活动时间配置相关
	ActivityTimeDataGroup    m_act_time_group;
	ActivityTimeMap          m_act_time_map;

	typedef std::map<int, const AlienBossAttrIncrData* >  BossAttrIncrMap;
	typedef std::map<int, const AlienBossBonusData* >     BossBonusMap;

	AlienBossBonusDataGroup     m_boss_bonus_group;
	AlienBossAttrIncrDataGroup  m_boss_attr_group;

	BossAttrIncrMap     m_boss_attr_incr_map;
	BossBonusMap        m_boss_bonus_map;

	LuckyWheelBonusDataGroup  m_luck_wheel_bonus_group;
	ActExchangeDataGroup      m_act_exchange_group;


    ActCollectTreasureBoxDataGroup   m_act_collect_box_data_group;
    ActTreasureBoxMap               m_act_collect_box_map;
};


#endif
