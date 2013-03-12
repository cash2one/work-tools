#ifndef EQUIPMENT_PROPERTY_PROTOTYPE_H
#define EQUIPMENT_PROPERTY_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/equipment_property_bag.pb.h"

class EquipmentPropertyPrototype
{
public:
	int Init(const char* data_file);
	const EquipmentPropertyBag* GetEquipmentProperty(int bag_id);

	void clear()
	{
		prototypes_.clear();
	}
private:
	typedef std::map<int, EquipmentPropertyBag> Prototypes;
	Prototypes prototypes_;

//	DECLARE_SINGLETON_CONSTRUCTER(EquipmentPropertyPrototype);
};

//#define EQUIP_PROPERTY_INSTANCE Singleton<EquipmentPropertyPrototype>::instance()

#endif //EQUIPMENT_PROPERTY_PROTOTYPE_H
