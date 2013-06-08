#include <assert.h>
#include <fstream>
#include "guild_activity_prototype.h"
#include "../public/str_util.h"

bool GuildActivityPrototypeMgr::InitCrystalQuest( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!quest_data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<quest_data_group_.data_size(); ++i)
	{
		const GuildActivityCrystalQuestData& d = quest_data_group_.data(i);
		prototypes_.insert(std::make_pair(d.quest_id(), &d));
	}

	return true;
}

bool GuildActivityPrototypeMgr::InitReward( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	GuildActivityCrystalRewardDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group.data_size(); ++i)
	{
		const GuildActivityCrystalRewardData& d = data_group.data(i);
		reward_prototypes_.insert(std::make_pair(
				std::make_pair(
					std::make_pair(d.crystal_tower_level(), d.crystal_tower_quality()),
					d.crystal_tower_category())
			,d));
	}

	return true;
}

bool GuildActivityPrototypeMgr::InitTowerPowerupData( const char* data_file )
{
    max_crystal_quality_ = 0;
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	GuildActivityCrystalTowerPowerupDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group.data_size(); ++i)
	{
		const GuildActivityCrystalTowerPowerupData& d = data_group.data(i);
		TowerPowerupPrototype::iterator it = tower_powerup_prototype_.find(std::make_pair(d.crystal_tower_level(), d.crystal_tower_category()));
		if (it == tower_powerup_prototype_.end())
		{
			std::map<int,int> v;
			it = tower_powerup_prototype_.insert(std::make_pair(
				std::make_pair(d.crystal_tower_level(), d.crystal_tower_category()),
				v)).first;
		}
		it->second.insert(std::make_pair(d.crystal_num(), d.crystal_tower_quality()));
		if (d.crystal_tower_quality() > max_crystal_quality_)
            max_crystal_quality_ = d.crystal_tower_quality();
	}

	return true;
}

bool GuildActivityPrototypeMgr::InitRewardPos(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!reward_pos_data_group_.ParseFromIstream(&fs)) return false;

	if (reward_pos_data_group_.data_size() <= 0)
		return -1;

	reward_pos_prototype_.reserve(reward_pos_data_group_.data_size());

	for (int i=0; i<reward_pos_data_group_.data_size(); ++i)
	{
		GuildActivityRewardPosRangeData& d = const_cast<GuildActivityRewardPosRangeData&>(reward_pos_data_group_.data(i));
		reward_pos_prototype_.push_back(&d);
	}

	return true;
}

bool GuildActivityPrototypeMgr::InitTowerCost( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	GuildCrystalTowerCostDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group.data_size(); ++i)
	{
		const GuildCrystalTowerCostData& d = data_group.data(i);
		tower_cost_prototype_.insert(std::make_pair(std::make_pair(d.crystal_tower_level(), d.crystal_tower_category()), d));
	}

	return true;
}

// std::pair<int,int> GuildActivityPrototypeMgr::RandomRewardPos()
// {
// 	int random_block = random(1,8);
// 	switch(random_block)
// 	{
// 	case 1:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x() - reward_pos_prototype_.reward_range(), reward_pos_prototype_.crystal_tower_x()),
// 			random(reward_pos_prototype_.crystal_tower_y() - reward_pos_prototype_.reward_range(), reward_pos_prototype_.crystal_tower_y()));
// 		break;
// 	case 2:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x(), reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius()),
// 			random(reward_pos_prototype_.crystal_tower_y() - reward_pos_prototype_.reward_range(), reward_pos_prototype_.crystal_tower_y()));
// 		break;
// 	case 3:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius(),
// 				reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius() + reward_pos_prototype_.reward_range()),
// 			random(reward_pos_prototype_.crystal_tower_y() - reward_pos_prototype_.reward_range(), reward_pos_prototype_.crystal_tower_y()));
// 		break;
// 	case 4:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x() - reward_pos_prototype_.reward_range(), reward_pos_prototype_.crystal_tower_x()),
// 			random(reward_pos_prototype_.crystal_tower_y(), reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius()));
// 		break;
// 	case 5:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius(),
// 				reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius() + reward_pos_prototype_.reward_range()),
// 			random(reward_pos_prototype_.crystal_tower_y(), reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius()));
// 		break;
// 	case 6:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x() - reward_pos_prototype_.reward_range(), reward_pos_prototype_.crystal_tower_x()),
// 			random(reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius(),
// 				reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius() + reward_pos_prototype_.reward_range()));
// 		break;
// 	case 7:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x(), reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius()),
// 			random(reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius(),
// 				reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius() + reward_pos_prototype_.reward_range()));
// 	case 8:
// 		return std::make_pair(
// 			random(reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius(),
// 				reward_pos_prototype_.crystal_tower_x() + reward_pos_prototype_.crystal_tower_half_radius() + reward_pos_prototype_.reward_range()),
// 			random(reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius(),
// 				reward_pos_prototype_.crystal_tower_y() + reward_pos_prototype_.crystal_tower_half_radius() + reward_pos_prototype_.reward_range()));
// 	default:
// 		break;
// 	}
// 	// won't run here
// 	return std::make_pair(0,0);
// }


