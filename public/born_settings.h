#ifndef BORN_SETTINGS_H
#define BORN_SETTINGS_H

#include <map>
#include "../public/singleton.h"
#include "../public/game_common.pb.h"
#include "../config/player_init_data.pb.h"
#include "../config/phy_strength.pb.h"
#include "../config/number_limits.pb.h"

using namespace protocols::common;

class PlayerInitData;

class RoleBornSettings
{
public:
	bool Init(const char* data_file);
	bool InitPhyStrength(const char* data_file);
	bool InitNumberLimits(const char* data_file);

	// number_limit_type_: NumberLimitType
	int  GetNumberLimitByType(int number_limit_type_);

	const PlayerInitData* GetRoleBornPrototype(Gender gender, Profession pro);

	const PhyStrengthData* GetPhyStrengthData(int player_level, int vip_level);

private:
	typedef std::map<std::pair<Gender, Profession>, const PlayerInitData*> RolePrototypes;
	RolePrototypes role_prototypes_;
	PlayerInitDataGroup data_group_;

	typedef std::pair<int, int> IntRangePair;
	typedef std::pair<IntRangePair, int>  PhyStrengthKeyType;
	typedef std::map<PhyStrengthKeyType, const PhyStrengthData*>  PhyStrengthMap;

	PhyStrengthDataGroup   m_phy_str_data_group;

	typedef std::map<int, IntRangePair>  LevelToRangeMap;
	LevelToRangeMap        m_level_to_range_map;
	PhyStrengthMap         m_phy_strength_map; 

	std::map<int, int>     m_number_limits_map;

	DECLARE_SINGLETON_CONSTRUCTER(RoleBornSettings);
};

#define BS_INSTANCE Singleton<RoleBornSettings>::instance()


#endif //BORN_SETTINGS_H
