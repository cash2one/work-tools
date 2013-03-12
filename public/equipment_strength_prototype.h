#ifndef EQUIPMENT_STRENGTH_PROTOTYPE_H
#define EQUIPMENT_STRENGTH_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/equipment_strength.pb.h"

class EquipmentStrengthPrototype
{
	enum { max_strength_level_ = 10};
public:
	int Init(const char* data_file);
	const EquipmentStrengthData* GetStrengthPrototypeData(
			const int strength_level,
			const int equipment_level);
	const int max_strength_level() {return max_strength_level_;}

	int InitInheritData(const char* data_file);
	const EquipmentInheritData* GetEquipmentInheritData(int cur_equip_level, int cur_star_level) const
	{
		InheritPrototypes::const_iterator it = inherit_prototypes_.find(std::make_pair(cur_equip_level, cur_star_level));
		if (it != inherit_prototypes_.end())
			return it->second;
		else
			return NULL;
	}

	void clear()
	{
		prototypes_.clear();
		equip_level_range_.clear();
		data_group_.Clear();
		inherit_data_group_.Clear();
		inherit_prototypes_.clear();

	}
private:
	typedef std::map<std::pair<int,int>, const EquipmentStrengthData*> Prototypes;
	typedef std::map<std::pair<int,int>, const EquipmentInheritData*> InheritPrototypes;
	Prototypes prototypes_;

	std::vector<int> equip_level_range_;

	EquipmentStrengthDataGroup data_group_;

	EquipmentInheritDataGroup inherit_data_group_;
	InheritPrototypes inherit_prototypes_;

//	DECLARE_SINGLETON_CONSTRUCTER(EquipmentStrengthPrototype);
};

//#define EQUIP_STRENGTH_PROTO_MGR Singleton<EquipmentStrengthPrototype>::instance()

#endif //EQUIPMENT_STRENGTH_PROTOTYPE_H
