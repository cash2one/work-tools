#include <assert.h>
#include <fstream>
#include "born_settings.h"

using namespace std;

bool RoleBornSettings::Init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!data_group_.ParseFromIstream( &fs )) return false;

	for (int i=0; i<data_group_.players_size(); ++i)
	{
		const PlayerInitData& d = data_group_.players(i);
		role_prototypes_.insert(std::make_pair(std::make_pair((Gender)d.gender(), (Profession)d.profession()), &d));
	}

	return true;
}

bool RoleBornSettings::InitPhyStrength(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!m_phy_str_data_group.ParseFromIstream( &fs )) return false;

	// typedef std::pair<int, int> IntRangePair;
	// typedef std::pair<IntRangePair, int>  PhyStrengthKeyType;
	// typedef std::map<PhyStrengthKeyType, const PhyStrengthData*>  PhyStrengthMap;

	for (int i=0; i<m_phy_str_data_group.phy_str_size(); ++i)
	{
		const PhyStrengthData& d = m_phy_str_data_group.phy_str(i);

		if (d.player_level_max() < d.player_level_min() || d.player_level_min() < 0) return false;
		
		for (int i=d.player_level_min(); i <= d.player_level_max(); ++i)
		{
			m_level_to_range_map.insert(make_pair(i, make_pair(d.player_level_min(), d.player_level_max())));
		}
		
		PhyStrengthKeyType  key = make_pair(make_pair(d.player_level_min(), d.player_level_max()), d.vip_level());

		m_phy_strength_map.insert(make_pair(key, &d));
	}

	return true;
}

bool RoleBornSettings::InitNumberLimits(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	NumberLimitDataGroup  limits_group;
	if (!limits_group.ParseFromIstream( &fs )) return false;

	for (int i=0; i<limits_group.number_limit_data_size(); ++i)
	{
		const NumberLimitData&  d = limits_group.number_limit_data(i);
		m_number_limits_map[d.limit_type()] = d.limit_value();
	}

	return true;
}

// number_limit_type_: NumberLimitType
int  RoleBornSettings::GetNumberLimitByType(int number_limit_type_)
{
	if (m_number_limits_map.count(number_limit_type_))
	{
		return m_number_limits_map[number_limit_type_];
	}
	return -1;
}

const PhyStrengthData* RoleBornSettings::GetPhyStrengthData(int player_level, int vip_level)
{
	if (m_level_to_range_map.count(player_level) == 0) return NULL;
	
	PhyStrengthKeyType key = make_pair(m_level_to_range_map[player_level], vip_level);
	if (m_phy_strength_map.count(key) == 0) return NULL;

	return m_phy_strength_map[key];
}

const PlayerInitData* RoleBornSettings::GetRoleBornPrototype( Gender gender, Profession pro )
{
	RolePrototypes::iterator it = role_prototypes_.find(std::make_pair(gender, pro));
	if (it != role_prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

