#ifndef EQUIPMENT_SUIT_PROTOTYPE_H
#define EQUIPMENT_SUIT_PROTOTYPE_H

#include <map>
#include <set>
#include "../public/singleton.h"
#include "../config/equipment_suit.pb.h"

class EquipmentSuitPrototype
{

public:
	int Init(const char* data_file);

	int GetSuitId(int equip_id)
	{
		EquipSuitIdPrototypes::iterator it = equip_suit_prototypes.find(equip_id);
		if (it != equip_suit_prototypes.end())
			return it->second;
		else
			return 0;
	}

	const std::set<int>* GetSuitData(const int suit_id)
	{
		SuitPrototypes::iterator it = suit_prototypes_.find(suit_id);
		if (it!=suit_prototypes_.end())
			return &it->second;
		else
			return NULL;
	}
	
	int InitSuitAttrData(const char* data_file);
	const EquipmentSuitAttrData* GetSuitAttrData(int suit_id, int equip_count)
	{
		SuitAttrPrototypes::iterator it = suit_attr_prototypes_.find(std::make_pair(suit_id, equip_count));
		if (it != suit_attr_prototypes_.end())
			return it->second;
		else
			return NULL;
	}

	void clear()
	{
		suit_prototypes_.clear();
		equip_suit_prototypes.clear();
		attr_data_group_.Clear();
		suit_attr_prototypes_.clear();
	}
	
private:
	typedef std::map<int, std::set<int> > SuitPrototypes;
	typedef std::map<int, int> EquipSuitIdPrototypes;
	typedef std::map<std::pair<int, int>, const EquipmentSuitAttrData* > SuitAttrPrototypes;
	
	SuitPrototypes suit_prototypes_;
	EquipSuitIdPrototypes equip_suit_prototypes;

	EquipmentSuitAttrDataGroup attr_data_group_;
	SuitAttrPrototypes suit_attr_prototypes_;

//	DECLARE_SINGLETON_CONSTRUCTER(EquipmentSuitPrototype);
};

//#define EQUIP_SUIT_PROTO_MGR Singleton<EquipmentSuitPrototype>::instance()

#endif //EQUIPMENT_SUIT_PROTOTYPE_H
