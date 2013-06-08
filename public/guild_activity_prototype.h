#ifndef PUBLIC_GUILD_ACTIVITY_PROTOTYPE_H
#define PUBLIC_GUILD_ACTIVITY_PROTOTYPE_H

#include <map>
#include "../config/guild_activity.pb.h"

class GuildActivityPrototypeMgr
{
public:
	bool InitCrystalQuest(const char* data_file);
	bool InitReward(const char* data_file);
	bool InitTowerPowerupData(const char* data_file);
	bool InitRewardPos(const char* data_file);
	bool InitTowerCost(const char* data_file);

	const GuildActivityCrystalQuestData* GetCrystalDataByQuest(int quest_id)
	{
		Prototypes::iterator it = prototypes_.find(quest_id);
		if (it != prototypes_.end())
			return it->second;
		else
			return NULL;
	}

	const GuildActivityCrystalQuestDataGroup& GetCrystalQuests()
	{
		return quest_data_group_;
	}

	const GuildActivityCrystalRewardData* GetCrystalReward(int tower_level, int tower_quality, int tower_category) const
	{
		RewardPrototypes::const_iterator it = reward_prototypes_.find(std::make_pair(std::make_pair(tower_level, tower_quality), tower_category));
		if (it != reward_prototypes_.end())
			return &it->second;
		else
			return NULL;
	}

	const GuildCrystalTowerCostData* GetCrystalCost(int tower_level, int tower_category) const
	{
		GuildCrystalTowerCostDataPrototype::const_iterator it = tower_cost_prototype_.find(std::make_pair(tower_level, tower_category));
		if (it != tower_cost_prototype_.end())
			return &it->second;
		else
			return NULL;
	}

// 	const int GetTowerPowerupCrystalNum(int tower_quality)
// 	{
// 		TowerPowerupPrototype::iterator it = tower_powerup_prototype_.find(tower_quality);
// 		if (it != tower_powerup_prototype_.end())
// 			return it->second;
// 		else
// 			return 0;
//
// 	}
	const int GetTowerPowerupQuality(int tower_level, int tower_category, int crystal_num) const
	{
		TowerPowerupPrototype::const_iterator it = tower_powerup_prototype_.find(std::make_pair(tower_level, tower_category));
		if (it == tower_powerup_prototype_.end())
		{
			return 0;
		}
		const std::map<int, int>& v = it->second;
		std::map<int, int>::const_iterator itt = v.upper_bound(crystal_num);
		if (itt != v.end())
			return (itt->second - 1);
		else
			return max_crystal_quality();
	}

	std::vector<GuildActivityRewardPosRangeData*>& GetRandomRewardPos() {return reward_pos_prototype_;}
    int max_crystal_quality() const {return max_crystal_quality_;}
	void clear()
	{
		prototypes_.clear();
		reward_prototypes_.clear();
		tower_powerup_prototype_.clear();
		tower_cost_prototype_.clear();
		reward_pos_data_group_.Clear();
		reward_pos_prototype_.clear();
	}
private:
	typedef std::map<int, const GuildActivityCrystalQuestData*> Prototypes;
	typedef std::map<std::pair<std::pair<int, int>, int>, const GuildActivityCrystalRewardData> RewardPrototypes;
	typedef std::map<std::pair<int, int>, std::map<int,int> > TowerPowerupPrototype;
	typedef std::map<std::pair<int, int>, const GuildCrystalTowerCostData> GuildCrystalTowerCostDataPrototype;
	typedef std::vector<GuildActivityRewardPosRangeData* > RewardPosPrototype;

    int max_crystal_quality_;
	GuildActivityCrystalQuestDataGroup quest_data_group_;
	Prototypes prototypes_;
	RewardPrototypes reward_prototypes_;
	TowerPowerupPrototype tower_powerup_prototype_;
	GuildActivityRewardPosRangeDataGroup reward_pos_data_group_;
	RewardPosPrototype reward_pos_prototype_;
	GuildCrystalTowerCostDataPrototype tower_cost_prototype_;
};




#endif //PUBLIC_GUILD_ACTIVITY_PROTOTYPE_H
