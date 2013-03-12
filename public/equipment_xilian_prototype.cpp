#include <assert.h>
#include <fstream>
#include <algorithm>
#include "equipment_xilian_prototype.h"

int EquipmentXilianPrototype::Init( const char* data_file )
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
		const EquipmentXilianData& d = data_group_.data(i);
		prototypes_.insert(
			std::make_pair(d.equip_level(), &d));

		if (find(equip_level_range_.begin(),
					equip_level_range_.end(), d.equip_level()) == equip_level_range_.end())
		{
			equip_level_range_.push_back(d.equip_level());
		}
	}

	sort(equip_level_range_.begin(), equip_level_range_.end());

	return true;
}

int EquipmentXilianPrototype::InitLockAttrCost( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}
	EquipmentLockAttrDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}
	//equip_level_range_.push_back(0);
	for (int i=0; i<data_group.data_size(); ++i)
	{
		const EquipmentLockAttrData& d = data_group.data(i);
		lock_attr_cost_data_.insert(std::make_pair(d.lock_attr_count(), std::make_pair(d.cost_money_type(), d.cost_money_num())));
	}

	return true;
}

const EquipmentXilianData* EquipmentXilianPrototype::GetXilianPrototypeData(const int equip_level)
{
	int range_level = equip_level;
	for (std::vector<int>::iterator it = equip_level_range_.begin();
			it != equip_level_range_.end(); ++it)
	{
		if (range_level <= *it)
		{
			range_level = *it;
			break;
		}
	}

	Prototypes::iterator it = prototypes_.find(range_level);
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
}
