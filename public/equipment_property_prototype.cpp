#include <assert.h>
#include <fstream>
#include "equipment_property_prototype.h"

int EquipmentPropertyPrototype::Init( const char* data_file )
{
	//assert(prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	ConfigEquipmentPropertyBag datas;
	if (!datas.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<datas.equipment_property_size(); ++i)
	{
		const ConfigEquipmentProperty& d = datas.equipment_property(i);
        EquipmentPropertyBag& bag = prototypes_[d.attr_bag_id()];
		
		EquipmentProperty* prop = bag.add_properties();
        
		prop->set_attr_id(d.attr_id());
		prop->set_gen_weight(d.gen_weight());
		prop->set_max_gen_count(d.max_gen_count());
		prop->set_max_num(d.max_num());
		prop->set_min_num(d.min_num());
	}

	return true;
}

const EquipmentPropertyBag* EquipmentPropertyPrototype::GetEquipmentProperty( int bag_id )
{
	Prototypes::iterator it = prototypes_.find(bag_id);
	if (it != prototypes_.end())
	{
		return &(it->second);
	}
    
	return NULL ;
}

