/*
 * charge_gift_prototype.cpp
 *
 *  Created on: 2013-3-29
 *  Author: weitq
 */

#include <algorithm>
#include <fstream>
#include "charge_gift_prototype.h"

ChargeGiftProtoManager::ChargeGiftProtoManager()
{

}
ChargeGiftProtoManager::~ChargeGiftProtoManager()
{
	clear();
}

void ChargeGiftProtoManager::clear()
{
	m_charge_gift_map.clear();
	m_flag_gift_map.clear();
    m_charge_step.clear() ;
}

bool ChargeGiftProtoManager::init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	ChargeGiftDataGroup  data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.gift_data_size(); ++i)
	{
		const ChargeGiftData& d = data_group_.gift_data(i);
		m_charge_gift_map[d.charge_value()] = d;
		m_flag_gift_map[d.flag_value()] = d;
        m_charge_step.push_back(d.charge_value()) ;
	}

    std::sort(m_charge_step.begin(),m_charge_step.end()) ;
	return true;
}

const ChargeGiftData* ChargeGiftProtoManager::get_charge_gift_by_value(int charge_value)
{
    for(std::vector<int>::reverse_iterator rit= m_charge_step.rbegin();rit != m_charge_step.rend();++rit)
    {
        if ( charge_value >= *rit)
        {
            charge_value = *rit ;
            break ;
        }
    }
    
	ChargeGiftMap::iterator it = m_charge_gift_map.find(charge_value);
	if (it != m_charge_gift_map.end())
	{
		return &(it->second);
	}

	return NULL;
}

const ChargeGiftData* ChargeGiftProtoManager::get_charge_gift_by_flag(int flag)
{
	ChargeGiftMap::iterator it = m_flag_gift_map.find(flag);
	if (it != m_flag_gift_map.end())
	{
		return &(it->second);
	}

	return NULL;
}
