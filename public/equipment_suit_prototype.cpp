#include <assert.h>
#include <fstream>
#include <algorithm>
#include "equipment_suit_prototype.h"



int EquipmentSuitPrototype::Init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}
	EquipmentSuitDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}
	//equip_level_range_.push_back(0);
	for (int i=0; i<data_group.data_size(); ++i)
	{
		const EquipmentSuitData& d = data_group.data(i);
		
		equip_suit_prototypes.insert(std::make_pair(d.equip_id(), d.suit_id()));

		SuitPrototypes::iterator it = suit_prototypes_.find(d.suit_id());

		if (it == suit_prototypes_.end())
		{
			std::set<int> t;
			suit_prototypes_.insert(std::make_pair(d.suit_id(), t));
			it = suit_prototypes_.find(d.suit_id());
		}
		it->second.insert(d.equip_id());
	}

	return true;
}

int EquipmentSuitPrototype::InitSuitAttrData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!attr_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<attr_data_group_.data_size(); ++i)
	{
		const EquipmentSuitAttrData& d = attr_data_group_.data(i);

		suit_attr_prototypes_.insert(std::make_pair(std::make_pair(d.suit_id(), d.item_count()), &d));

	}

	return true;
}

