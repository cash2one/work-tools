#include <assert.h>
#include <fstream>
#include "battle_prototype_mgr.h"

using namespace std;

void BattlePrototypeMgr::clear()
{
    prototypes_.clear();
    data_group_.Clear();

    battle_group_prototypes_.clear();
    battle_group_data_group_.Clear();

    random_battle_group_data_group_.Clear(); 
    random_battle_group_map.clear();

    monster_random_amount_data_group_.Clear();


    level_index.clear();      // µÈ¼¶Ë÷Òý [level] ==> [begin, end]
    random_monster_map.clear();


    drop_item_data_group.Clear();
    drop_item_amount_range_map.clear();
    drop_item_rule_map.clear();
	drop_id_index_item_id_map.clear();
	drop_id_sum_weight_map.clear();

    random_battle_group_drop_id_map.clear();

    //
    fight_cooldown_limit_data_group_.Clear();
    auto_skip_fight_limit_data_group_.Clear();

	m_battle_group_level_index.clear();
	m_level_battle_group_map.clear();
	m_level_bg_group.Clear();

}
bool BattlePrototypeMgr::InitBattleNpc( const char* data_file )
{
	//assert(prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group_.battle_npc_size(); ++i)
	{
		const BattleNPCData& d = data_group_.battle_npc(i);
		prototypes_.insert(std::make_pair(d.id(), &d));
	}

	return true;
}

bool BattlePrototypeMgr::InitBattleGroup( const char* data_file )
{
	//assert(battle_group_prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!battle_group_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<battle_group_data_group_.battle_group_size(); ++i)
	{
		const BattleGroupData& d = battle_group_data_group_.battle_group(i);
		battle_group_prototypes_.insert(std::make_pair(d.id(), &d));
	}

	return true;
}

bool BattlePrototypeMgr::InitRandomBattleGroup(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!random_battle_group_data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	random_battle_group_map.clear();
	for (int i=0; i < random_battle_group_data_group_.random_battle_group_size(); ++i)
	{
		const RandomBattleGroupData& bg = random_battle_group_data_group_.random_battle_group(i);
		MonsterWeightContainer&  monster_weight = random_battle_group_map[bg.battle_group_id()];
		monster_weight.push_back(make_pair(bg.monster_id(), bg.weight()));

		if(random_battle_group_drop_id_map.count(bg.battle_group_id()) == 0)
		{
			random_battle_group_drop_id_map[bg.battle_group_id()] = bg.drop_id();
		}
	}

	return true;
}

bool BattlePrototypeMgr::InitRandomMonsterAmount(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!monster_random_amount_data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	random_monster_map.clear();
	for (int i=0; i < monster_random_amount_data_group_.monster_random_amount_data_size(); ++i)
	{
		const MonsterRandomAmountData& m = monster_random_amount_data_group_.monster_random_amount_data(i);
		random_monster_map.insert( 
			make_pair( make_pair( make_pair(m.begin_level(), m.end_level()) , m.player_amount()), 
					   make_pair(m.min_monster(), m.max_monster()) ) );

		for (int i=m.begin_level(); i <= m.end_level(); ++i)
		{
			if (level_index.count(i) == 0)
			{
				level_index[i] = make_pair(m.begin_level(), m.end_level());
			}
		}
	}

	return true;
}

bool BattlePrototypeMgr::InitDropItems(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!drop_item_data_group.ParseFromIstream(&fs))
	{
		return false;
	}

	drop_item_amount_range_map.clear();
	drop_item_rule_map.clear();
	drop_id_index_item_id_map.clear();
	drop_id_sum_weight_map.clear();

	for (int i=0; i < drop_item_data_group.drop_item_data_size(); i++)
	{
		const DropItemData&  drop_item = drop_item_data_group.drop_item_data(i);

		if (drop_item_amount_range_map.count(drop_item.drop_id()) == 0)
		{
			drop_item_amount_range_map[drop_item.drop_id()] 
				= make_pair(drop_item.drop_lower_limit(), drop_item.drop_upper_limit());
		}
			
		drop_item_rules  rule;
		rule.item_id = drop_item.item_id();
		rule.weight = drop_item.item_drop_weight();
		rule.item_drop_single_time = drop_item.item_drop_single_time();
		rule.item_count_limit = drop_item.item_count_limit();

		int drop_id_size = 0;
		if (drop_id_sum_weight_map.count(drop_item.drop_id()) > 0)
		{
			drop_id_size = drop_id_sum_weight_map[drop_item.drop_id()] ;
		}

		IndexToItemIdMap&  index_id_map = drop_id_index_item_id_map[drop_item.drop_id()];

		if (rule.weight > 0)
		{
			pair<int, int>   index_pair = make_pair(drop_id_size + 1, drop_id_size + rule.weight);
			index_id_map[index_pair] = rule.item_id;

			drop_id_sum_weight_map[drop_item.drop_id()] += rule.weight;
		}

		DropItemRuleContainer&  item_container = drop_item_rule_map[drop_item.drop_id()];
		item_container.push_back(rule);
	}

	return true;
}

int  BattlePrototypeMgr::get_item_id_by_rand_index(int drop_id, int index)
{
	if (drop_id < 0)  return 0;

	if (index <=0 || index > drop_id_sum_weight_map[drop_id] ) return 0;
	
	IndexToItemIdMap&  index_id_map = drop_id_index_item_id_map[drop_id];

	for (IndexToItemIdMap::const_iterator itor = index_id_map.begin();
		itor != index_id_map.end(); ++itor)
	{
		const pair<int, int>&  index_range = itor->first;
		if (index >= index_range.first && index <= index_range.second)
		{
			return itor->second;
		}
	}

	return 0;
}



bool BattlePrototypeMgr::InitAutoSkipFightLimit(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!auto_skip_fight_limit_data_group_.ParseFromIstream(&fs))
	{
		return false;
	}
	return true;
}

bool BattlePrototypeMgr::InitFightCoolDownLimit(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!fight_cooldown_limit_data_group_.ParseFromIstream(&fs))
	{
		return false;
	}
	return true;
}

bool BattlePrototypeMgr::InitLevelBattleGroup(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_level_bg_group.ParseFromIstream(&fs))
	{
		return false;
	}

	m_battle_group_level_index.clear();
	m_level_battle_group_map.clear();

	for (int i=0; i < m_level_bg_group.level_battle_group_size(); i++)
	{
		const LevelBattleGroupData&  d = m_level_bg_group.level_battle_group(i);

		LevelBattleGroupKey  _key = make_pair(d.id(), make_pair(d.min_level(), d.max_level()));
		m_level_battle_group_map.insert(make_pair(_key, d.battle_group_id()));

		for (int level=d.min_level(); level <= d.max_level(); level++)
		{
			if (m_battle_group_level_index.count(level) == 0)
			{
				m_battle_group_level_index[level] = make_pair(d.min_level(), d.max_level());
			}
		}
	}

	return true;
}

int BattlePrototypeMgr::GetLevelBattleGroupId(int npc_battle_group_id, int level)
{
	if (m_battle_group_level_index.count(level) == 0) return 0;
	
	LevelBattleGroupKey  _key = make_pair(npc_battle_group_id, m_battle_group_level_index[level]);
	if (m_level_battle_group_map.count(_key))
	{
		return m_level_battle_group_map[_key];
	}

	return 0;
}

std::pair<int, int>  BattlePrototypeMgr::GetDropItemAmountRange(int drop_id)
{
	DropItemAmountRangeMap::iterator  itor = drop_item_amount_range_map.find(drop_id);
	if (itor != drop_item_amount_range_map.end())
	{
		return itor->second;
	}

	return pair<int, int>(0, 0);
}

void BattlePrototypeMgr::GetDropItemRules(int drop_id, DropItemRuleContainer&  item_rule_container)
{
	DropItemRuleMap::iterator itor = drop_item_rule_map.find(drop_id);
	if (itor != drop_item_rule_map.end())
	{
		item_rule_container.assign(itor->second.begin(), itor->second.end()) ;
	}
}

void  BattlePrototypeMgr::GetRandomBattleGroupData(int group_id, MonsterWeightContainer&  monster_weight_data, int& drop_id)
{
	RandomBattleGroupMap::iterator  itor = random_battle_group_map.find(group_id);
	if (itor != random_battle_group_map.end())
	{
		monster_weight_data = itor->second;
		drop_id = random_battle_group_drop_id_map[group_id];
		return ;
	}

	monster_weight_data.clear();
}

std::pair<int, int>  BattlePrototypeMgr::GetRandomMonsterAmount(int player_level, int player_count)
{
	if (level_index.count(player_level))
	{
		RandomMonsterKeyType  my_key = make_pair(level_index[player_level], player_count);
		if (random_monster_map.count(my_key))
		{
			return random_monster_map[my_key];
		}
	}
	
	return make_pair(0, 0);
}

const BattleNPCData* BattlePrototypeMgr::GetBattleNpcPrototype( int battle_npc_id )
{
	Prototypes::iterator it = prototypes_.find(battle_npc_id);
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

const BattleGroupData* BattlePrototypeMgr::GetBattleGroupPrototype( int battle_group_id )
{
	BattleGroupPrototypes::iterator it = battle_group_prototypes_.find(battle_group_id);
	if (it != battle_group_prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

// 
int BattlePrototypeMgr::GetAutoSkipFightTime(int defender_level)
{
	for (int i=0; i < auto_skip_fight_limit_data_group_.skip_fight_limit_data_size(); i++)
	{
		const AutoSkipFightTimeLimitData&  d = auto_skip_fight_limit_data_group_.skip_fight_limit_data(i);
		if (defender_level >= d.defender_level_lower() && defender_level <= d.defender_level_high())
		{
			return d.auto_skip_time();
		}
	}
	return 0;
}

// 
int BattlePrototypeMgr::FightCoolDownLimit(int defender_level, int attacker_count)
{
	for (int i=0; i < fight_cooldown_limit_data_group_.fight_cooldown_limit_size(); i++)
	{
		const FightCoolDownLimitData& d = fight_cooldown_limit_data_group_.fight_cooldown_limit(i);
		if (defender_level >= d.defender_level_lower() && defender_level <= d.defender_level_high())
		{
			switch (attacker_count)
			{
			case 1:  return d.single();
			case 2:  return d.double_();
			case 3:  return d.triple();
			default:
				break;
			}
		}
	}
	return 0;
}







