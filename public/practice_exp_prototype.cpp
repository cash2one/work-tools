/*
 * practice_exp_prototype.cpp
 *
 *  Created on: 2013-5-23
 *  Author: weitq
 */


#include <fstream>
#include "practice_exp_prototype.h"

PracticeExpProtoManager::PracticeExpProtoManager()
{

}
PracticeExpProtoManager::~PracticeExpProtoManager()
{
	clear();
}

void PracticeExpProtoManager::clear()
{
	m_practice_exp_map.clear();
}

bool PracticeExpProtoManager::init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	PracticeExpDataGroup  data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.practice_exp_data_size(); ++i)
	{
		const PracticeExpData& d = data_group_.practice_exp_data(i);
		m_practice_exp_map[d.player_level()] = d;
	}

	return true;
}

int PracticeExpProtoManager::get_exp(int role_level, int vip_level)
{
	int exp = 0;

	PracticeExpMap::iterator it = m_practice_exp_map.find(role_level);
	if (it != m_practice_exp_map.end())
	{
		switch(vip_level){
			case 0:
				exp = (it->second).has_vip0() ? (it->second).vip0() : 0;
				break;
			case 1:
				exp = (it->second).has_vip1() ? (it->second).vip1() : 0;
				break;
			case 2:
				exp = (it->second).has_vip2() ? (it->second).vip2() : 0;
				break;
			case 3:
				exp = (it->second).has_vip3() ? (it->second).vip3() : 0;
				break;
			case 4:
				exp = (it->second).has_vip4() ? (it->second).vip4() : 0;
				break;
			case 5:
				exp = (it->second).has_vip5() ? (it->second).vip5() : 0;
			default:
				break;
		}
	}

	return exp;
}
