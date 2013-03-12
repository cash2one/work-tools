#include <assert.h>
#include <fstream>
#include "item_prototype_mgr.h"


void ItemPrototypeMgr::clear()
{
    prototypes_.clear();
    data_group_.Clear();

    equip_prototypes_.clear();
    equipment_data_group_.Clear();

    magic_item_prototypes_.clear();
    magic_item_data_group_.Clear();

    stone_prototypes_.clear();
    stone_data_group_.Clear();

}

bool ItemPrototypeMgr::Init( const char* data_file )
{
	//assert(prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group_.props_data_size(); ++i)
	{
		const Prototype& d = data_group_.props_data(i);
		prototypes_.insert(std::make_pair(d.item_id(), &d));
	}

	return true;
}

const PropsData* ItemPrototypeMgr::GetItemPrototype( int proto_id )
{
	Prototypes::iterator it = prototypes_.find(proto_id);
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

bool ItemPrototypeMgr::InitEquip( const char* data_file )
{
	//assert(equip_prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!equipment_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<equipment_data_group_.equipment_size(); ++i)
	{
		const EquipmentData& d = equipment_data_group_.equipment(i);
		equip_prototypes_.insert(std::make_pair(d.item_id(), &d));
	}

	return true;
}

const EquipmentData* ItemPrototypeMgr::GetEquipPrototype( int proto_id )
{
	EquipPrototypes::iterator it = equip_prototypes_.find(proto_id);
	if (it != equip_prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

bool ItemPrototypeMgr::InitMagicItem( const char* data_file )
{
	//assert(magic_item_prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!magic_item_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<magic_item_data_group_.magic_item_size(); ++i)
	{
		const MagicItemData& d = magic_item_data_group_.magic_item(i);
		magic_item_prototypes_.insert(std::make_pair(d.item_id(), &d));
	}

	return true;
}

const MagicItemData* ItemPrototypeMgr::GetMagicItemPrototype( int proto_id )
{
	MagicItemPrototypes::iterator it = magic_item_prototypes_.find(proto_id);
	if (it != magic_item_prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

bool ItemPrototypeMgr::InitStone( const char* data_file )
{
	//assert(stone_prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!stone_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<stone_data_group_.stone_size(); ++i)
	{
		const StoneData& d = stone_data_group_.stone(i);
		stone_prototypes_.insert(std::make_pair(d.item_id(), &d));
	}

	return true;
}

const StoneData* ItemPrototypeMgr::GetStonePrototype( int proto_id )
{
	StonePrototypes::iterator it = stone_prototypes_.find(proto_id);
	if (it != stone_prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

bool ItemPrototypeMgr::need_broad_cast( int proto_id )
{
	const PropsData* proto = GetItemPrototype(proto_id);
	if (proto != 0)
	{
		return proto->need_broadcast();
	}
	return false;
}

