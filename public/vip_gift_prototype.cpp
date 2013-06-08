/*
 * vip_gift_prototype.cpp
 *
 *  Created on: 2013-3-28
 *  Author: weitq
 */


#include <fstream>
#include "vip_gift_prototype.h"

VipGiftProtoManager::VipGiftProtoManager()
{

}
VipGiftProtoManager::~VipGiftProtoManager()
{
	clear();
}

void VipGiftProtoManager::clear()
{
	m_vip_gift_map.clear();
	m_flag_gift_map.clear();
}

bool VipGiftProtoManager::init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	VipGiftDataGroup  data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.gift_data_size(); ++i)
	{
		const VipGiftData& d = data_group_.gift_data(i);
		m_vip_gift_map[d.vip_level()] = d;//d.gift_id();
		m_flag_gift_map[d.flag_value()] = d;//d.gift_id();
	}

	return true;
}

const VipGiftData* VipGiftProtoManager::get_vip_gift_by_level(int vip_lv)
{
	VipGiftMap::iterator it = m_vip_gift_map.find(vip_lv);
	if (it != m_vip_gift_map.end())
	{
		return &(it->second);
	}

	return NULL;
}

const VipGiftData* VipGiftProtoManager::get_vip_gift_by_flag(int flag)
{
	VipGiftMap::iterator it = m_flag_gift_map.find(flag);
	if (it != m_flag_gift_map.end())
	{
		return &(it->second);
	}

	return NULL;
}
