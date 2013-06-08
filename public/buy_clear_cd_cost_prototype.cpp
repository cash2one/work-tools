/*
 * buy_clear_cd_cost_prototype.cpp
 *
 *  Created on: 2013-4-9
 *  Author: weitq
 */


#include <fstream>
#include "buy_clear_cd_cost_prototype.h"

BuyClearCdCostProtoManager::BuyClearCdCostProtoManager()
{

}
BuyClearCdCostProtoManager::~BuyClearCdCostProtoManager()
{
	clear();
}

void BuyClearCdCostProtoManager::clear()
{
	m_clear_cd_cost_map.clear();
}

bool BuyClearCdCostProtoManager::init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	BuyClearCDCostDataGroup  data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.clear_cd_cost_size(); ++i)
	{
		const BuyClearCDCostData& d = data_group_.clear_cd_cost(i);
		m_clear_cd_cost_map[d.cooldown_type()] = d;
	}

	return true;
}

const BuyClearCDCostData* BuyClearCdCostProtoManager::get_cost_by_type(int type)
{
	BuyClearCdCostMap::iterator it = m_clear_cd_cost_map.find(type);
	if (it != m_clear_cd_cost_map.end())
	{
		return &(it->second);
	}

	return NULL;
}
