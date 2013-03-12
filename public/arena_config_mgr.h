/*******************************************************************************
 *
 *      @file: arena_config_mgr.h
 *      @brief: ��������������.
 *
 *      @author: gxl.
 *      @Date: 2012/08/24
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef ARENA_CONFIG_MANAGER_H
#define ARENA_CONFIG_MANAGER_H


#include <map>
#include "singleton.h"

#include "buy_challenge_times_cost.pb.h"
#include "buy_clear_cd_cost.pb.h"
#include "challenge_bonus.pb.h"
#include "challenge_cont_win_title.pb.h"
#include "challenge_rank_title.pb.h"
#include "treasure_box.pb.h"

// [ level_low, level_high ] 
typedef std::pair<int, int>  LevelRangePair;

// [ rank_low, rank_high ]
typedef std::pair<int, int>  RankRangePair;

// [min, max]
typedef std::pair<int, int>  IntRangePair; 

class ArenaConfigManager
{
public:
	~ArenaConfigManager() { }

	bool InitBuyChallengeTimesCost(const char* data_file);
	bool InitBuyClearCDCost(const char* data_file);
	bool InitChallengeBonus(const char* data_file);
	bool InitChallengeContWinTitle(const char* data_file);
	bool InitChallengeRankTitle(const char* data_file);
	bool InitTreasureBox(const char* data_file);

	// ��õڼ�����ս�Ļ���
	// @return: -1 means no config
	//          >=0 means actual cost
	int  GetChallengeTimesCost(int how_many_times);

	// ��ò�ͬ���͵���ȴ�Ļ���
	int  GetClearCoolDownCost(int cool_down_type);

	// ���ֵȼ��õ��Ľ�������
	const ChallengeBonusData* GetChallengeBonusData(int defender_level);

	// ��ʤ������Ӧ�ĳƺ�id
	int GetContWinTitleID(int cont_win_times);

	// �����õ��ĳƺ�
	int GetRankTitleID(int rank_level);

	// ���ݱ���id�õ���������
	const TreasureBoxData* GetTreasureBoxDataByID(int box_id);

	// ���������ȼ��õ���������
	const TreasureBoxData* GetTreasureBoxDataByRank(int rank_level);


private:
	// [time, cost]
	typedef std::map<int, int>    ChallengeTimesCostMap;
	// [CDtype, cost]
	typedef std::map<int, int>    ClearCoolDownCostMap;

	// [cont_win_times, title]
	typedef std::map<IntRangePair, int>    ContWinTitleMap;

	typedef std::map<LevelRangePair, const ChallengeBonusData* >  BonusMap;
	typedef std::map<RankRangePair, int >  RankTitleMap;

	typedef std::map<RankRangePair, const TreasureBoxData* >  RankTreasureBoxMap;
	// [box_id, box_data]
	typedef std::map<int, const TreasureBoxData* >  TreasureBoxMap;
	
	BuyChallengeTimesCostDataGroup     buy_challenge_times_group;
	BuyClearCDCostDataGroup            buy_clear_cd_group;
	ChallengeBonusDataGroup            challenge_bonus_group;
	ChallengeContWinTitleDataGroup     challenge_cont_win_title_group;
	ChallengeRankTitleDataGroup        challenge_rank_title_group;
	TreasureBoxDataGroup               treasure_box_group;

	ChallengeTimesCostMap  challenge_times_map;
	ClearCoolDownCostMap   clear_cd_map;
	BonusMap             bonus_map;
	ContWinTitleMap      cont_win_title_map;
	RankTitleMap         rank_title_map;
	RankTreasureBoxMap   rank_treasure_box_map;
	TreasureBoxMap       treasure_box_map;

	DECLARE_SINGLETON_CONSTRUCTER(ArenaConfigManager);
};


#define ARENA_CONFIG_INSTANCE Singleton<ArenaConfigManager>::instance()

#endif
