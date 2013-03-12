#include <assert.h>
#include <fstream>
#include <algorithm>
#include "equipment_strength_prototype.h"



int EquipmentStrengthPrototype::Init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}
	//equip_level_range_.push_back(0);
	for (int i=0; i<data_group_.data_size(); ++i)
	{
		const EquipmentStrengthData& d = data_group_.data(i);
		prototypes_.insert(
			std::make_pair(
				std::make_pair(d.strength_level(), d.equip_level()), 
				&d));
		if (find(equip_level_range_.begin(),
					equip_level_range_.end(), d.equip_level()) == equip_level_range_.end())
		{
			equip_level_range_.push_back(d.equip_level());
		}
	}

	sort(equip_level_range_.begin(), equip_level_range_.end());

	return true;
}

const EquipmentStrengthData* EquipmentStrengthPrototype::GetStrengthPrototypeData( const int strength_level, const int equipment_level )
{
	int range_level = equipment_level;
	for (std::vector<int>::iterator it = equip_level_range_.begin();
			it != equip_level_range_.end(); ++it)
	{
		if (range_level <= *it)
		{
			range_level = *it;
			break;
		}
	}

	Prototypes::iterator it = prototypes_.find(std::make_pair(strength_level, range_level));
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return NULL;
	}

}

int EquipmentStrengthPrototype::InitInheritData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!inherit_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}
	//equip_level_range_.push_back(0);
	for (int i=0; i<inherit_data_group_.data_size(); ++i)
	{
		const EquipmentInheritData& d = inherit_data_group_.data(i);
		for (int j=d.inherit_equip_level_area_min();j<=d.inherit_equip_level_area_max(); ++j)
		{
			std::pair<InheritPrototypes::iterator, bool> ret = inherit_prototypes_.insert(
				std::make_pair(
					std::make_pair(j, d.origin_strength_level()), &d));
			if (!ret.second)
			{
				return false;
			}
		}
	}

	return true;
}
