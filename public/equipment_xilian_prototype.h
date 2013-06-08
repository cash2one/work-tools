#ifndef EQUIPMENT_XILIAN_PROTOTYPE_H
#define EQUIPMENT_XILIAN_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/equipment_xilian.pb.h"

class EquipmentXilianPrototype
{
	
public:
	int Init(const char* data_file);
	const EquipmentXilianData* GetXilianPrototypeData(const int equip_level);
	int InitLockAttrCost(const char* data_file);
	int GetLockAttrCostData(int lock_num, int* money_type, int* money_value)
	{
		LockAttrCostData::iterator it = lock_attr_cost_data_.find(lock_num);
		if (it != lock_attr_cost_data_.end())
		{
			*money_type = it->second.first;
			*money_value = it->second.second;
			return 0;
		}
		else
		{
			return -1;
		}
	}

	void clear()
	{
		prototypes_.clear();
		equip_level_range_.clear();
		data_group_.Clear();
		lock_attr_cost_data_.clear();
	}
private:
	typedef std::map<int, const EquipmentXilianData*> Prototypes;
	typedef std::map<int, std::pair<int, int> >  LockAttrCostData;

	Prototypes prototypes_;

	std::vector<int> equip_level_range_;

	EquipmentXilianDataGroup data_group_;

	LockAttrCostData lock_attr_cost_data_;

//	DECLARE_SINGLETON_CONSTRUCTER(EquipmentXilianPrototype);
};

//#define EQUIP_XILIAN_PROTO_MGR Singleton<EquipmentXilianPrototype>::instance()

#endif //EQUIPMENT_XILIAN_PROTOTYPE_H
