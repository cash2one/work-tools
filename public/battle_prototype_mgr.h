#ifndef BATTLE_NPC_PROTOTYPE_MGR_H
#define BATTLE_NPC_PROTOTYPE_MGR_H

#include <map>
#include <vector>
//#include <ext/hash_map>
#include <unordered_map>
#include "singleton.h"
#include "battle_npc.pb.h"
#include "battle_group.pb.h"
#include "random_battle_group.pb.h"
#include "monster_amount_limit.pb.h"
#include "drop_items.pb.h"
#include "auto_skip_fight_time_limit.pb.h"
#include "fight_cooldown_limit.pb.h"
#include "level_battle_group.pb.h"

typedef std::pair<int, int> IntPair;

// [ battle_group_id ] ==> [ monster_id, weight ]
typedef std::vector< std::pair<int,int> >  MonsterWeightContainer;
typedef std::map<int, MonsterWeightContainer >  RandomBattleGroupMap;

// level => [min_level, max_level]
//typedef __gnu_cxx::hash_map<int, IntPair >  LevelIndexMap;
typedef std::unordered_map<int, IntPair >  LevelIndexMap;

// id, [min_level, max_level] 
typedef std::pair<int, IntPair>  LevelBattleGroupKey;

// id, [min_level, max_level] => battle_group_id
typedef std::map<LevelBattleGroupKey, int>  LevelBattleGroupMap;

// 
struct drop_item_rules
{
	int  item_id;     // 道具id
	int  weight;      // 权重
	int  item_drop_single_time; // 单次抽取本道具掉落个数
	int  item_count_limit;      // 本道具总个数限制
};

// [ drop_id ] ==> vector of [ drop_item_rules ]
typedef std::vector<drop_item_rules>  DropItemRuleContainer;

// [index_begin, index_end] ==> item_id
typedef std::map< std::pair<int, int>, int > IndexToItemIdMap;
typedef std::map< int, IndexToItemIdMap >    DropIdIndexToItemIdMap;

// [drop_id, sum_weight]
typedef std::map< int, int >  DropIDSumWeight; // 某掉落包的物品总权重

class BattlePrototypeMgr
{
public:
	bool InitBattleNpc(const char* data_file);
	bool InitBattleGroup(const char* data_file);
	bool InitRandomBattleGroup(const char* data_file);
	bool InitRandomMonsterAmount(const char* data_file);
	bool InitDropItems(const char* data_file);
	bool InitAutoSkipFightLimit(const char* data_file);
	bool InitFightCoolDownLimit(const char* data_file);

	bool InitLevelBattleGroup(const char* data_file);

    void clear() ;
	const BattleNPCData* GetBattleNpcPrototype(int battle_npc_id);
	const BattleGroupData* GetBattleGroupPrototype(int battle_group_id);

	void  GetRandomBattleGroupData(int group_id, MonsterWeightContainer&  monster_weight_data, int& drop_id);

	// [ (begin_level, end_level), player_count ] ==> [ Min_monster, Max_monster ]
	typedef  std::pair< std::pair<int, int>, int >  RandomMonsterKeyType;
	typedef  std::pair< int, int >                  RandomMonsterValueType;
	typedef  std::map< RandomMonsterKeyType, RandomMonsterValueType >  RandomMonsterMap;

	std::pair<int, int>  GetRandomMonsterAmount(int player_level, int player_count);

	// [ drop_id ] ==> [ min_items, max_items ]
	typedef std::map<int, std::pair<int, int> >    DropItemAmountRangeMap;

	std::pair<int, int>  GetDropItemAmountRange(int drop_id);

	
	typedef std::map<int, DropItemRuleContainer>  DropItemRuleMap;

	void GetDropItemRules(int drop_id, DropItemRuleContainer&  item_rule_container);


	// 
	int GetAutoSkipFightTime(int defender_level);

	// 
	int FightCoolDownLimit(int defender_level, int attacker_count);

	int GetLevelBattleGroupId(int npc_battle_group_id, int level);
public:
	DropIdIndexToItemIdMap    drop_id_index_item_id_map;
	DropIDSumWeight     drop_id_sum_weight_map;

	int  get_item_id_by_rand_index(int drop_id, int index);

private:
	typedef std::map<int, const BattleNPCData*> Prototypes;
	typedef std::map<int, const BattleGroupData*> BattleGroupPrototypes;
	typedef std::map<int, int>  RandomBattleGroupDropIDMap;


	Prototypes prototypes_;
	BattleNPCGroup data_group_;

	BattleGroupPrototypes battle_group_prototypes_;
	BattleGroupArray battle_group_data_group_;

	RandomBattleGroupDataGroup  random_battle_group_data_group_; 
	RandomBattleGroupMap   random_battle_group_map;

	MonsterRandomAmountDataGroup  monster_random_amount_data_group_;

	//typedef std::unordered_map<int, std::pair<int, int> >  LevelIndexMap;
	LevelIndexMap                 level_index;      // 等级索引 [level] ==> [begin, end]
	RandomMonsterMap              random_monster_map;


	DropItemDataGroup             drop_item_data_group;
	DropItemAmountRangeMap        drop_item_amount_range_map;
	DropItemRuleMap               drop_item_rule_map;

	RandomBattleGroupDropIDMap    random_battle_group_drop_id_map;

	//
	FightCoolDownLimitDataGroup   fight_cooldown_limit_data_group_;
	AutoSkipFightTimeLimitDataGroup  auto_skip_fight_limit_data_group_;

	// 根据等级的战斗组中的等级到 等级段的映射
	LevelIndexMap              m_battle_group_level_index;
	LevelBattleGroupMap        m_level_battle_group_map;
	LevelBattleGroupDataGroup  m_level_bg_group;

	//DECLARE_SINGLETON_CONSTRUCTER(BattlePrototypeMgr);
};

//#define YINGLING_INSTANCE Singleton<BattlePrototypeManager>::instance()



#endif //BATTLE_NPC_PROTOTYPE_MGR_H
