#ifndef VIP_BONUS_PROTOTYPE_H
#define VIP_BONUS_PROTOTYPE_H

#include <map>
#include "singleton.h"
#include "../config/vip_bonus.pb.h"

class VipSettingsPrototype
{
	typedef std::map<int, std::vector<VipBonusData> > VipBonusDataContainer;
	typedef std::map<std::pair<int, int>, int> VipSettingDataContainer;
public:
    VipSettingsPrototype()
    {

    }
	int InitVipBonusData(const char* data_file);
	const std::vector<VipBonusData>* get_vip_bonus_data(int vip_level)
	{
		VipBonusDataContainer::iterator it = vip_bonus_data_container_.find(vip_level);
		if (it != vip_bonus_data_container_.end())
			return &it->second;
		else
			return NULL;

	}
	int get_vip_setting_value(int vip_level, int setting_type) const
	{
		VipSettingDataContainer::const_iterator it = vip_setting_data_container_.find(std::make_pair(vip_level, setting_type));
		if (it != vip_setting_data_container_.end())
			return it->second;
		else
			return 0;
	}
private:
	VipBonusDataGroup vip_bonus_data_group_;
	VipBonusDataContainer vip_bonus_data_container_;

	VipSettingDataContainer vip_setting_data_container_;

	DECLARE_SINGLETON(VipSettingsPrototype);
};

#define VIP_SETTINGS Singleton<VipSettingsPrototype>::instance()

#endif //VIP_BONUS_PROTOTYPE_H
