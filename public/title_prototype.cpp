/*
 * title_prototype.cpp
 *
 *  Created on: 2013-6-7
 *  Author: weitq
 */


#include <fstream>
#include "title_prototype.h"

TitleProtoManager::TitleProtoManager()
{

}
TitleProtoManager::~TitleProtoManager()
{
	clear();
}

void TitleProtoManager::clear()
{
	m_title_map.clear();
}

bool TitleProtoManager::init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	TitleDataGroup  data_group_;
	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.title_data_size(); ++i)
	{
		const TitleData& d = data_group_.title_data(i);
		m_title_map[d.title_id()] = d;
	}

	return true;
}

const TitleData* TitleProtoManager::get_title_data(int title_id)
{
	TitleMap::iterator it = m_title_map.find(title_id);
	if (it != m_title_map.end())
	{
		return &(it->second);
	}

	return NULL;
}
