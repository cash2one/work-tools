/*******************************************************************************
 *
 *      @file: guild_configs.cpp
 *      @brief: guild csv configs read and parse.
 *
 *      @author: gxl.
 *      @Date: 2013/03/18
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <fstream>
#include "guild_configs.h"

using namespace  std;

void GuildConfigMgr::Clear()
{
	guild_skill_map.clear();
	data_group_.Clear();
	m_skill_ids.clear();
}

bool GuildConfigMgr::InitGuildSkill(const char* data_file)
{
	std::fstream  fs(data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.guild_skill_size(); ++i)
	{
		const GuildSkillData& d = data_group_.guild_skill(i);
		
		GuildSkillKey  key_ ;
		key_.first = d.skill_id();
		key_.second = d.skill_level();

		guild_skill_map.insert(make_pair(key_, &d));

		m_skill_ids.insert(d.skill_id());
	}

	return true;
}

const GuildSkillData*  GuildConfigMgr::GetGuildSkillData(int skill_id, int skill_level)
{
	GuildSkillKey  key_ ;
	key_.first = skill_id;
	key_.second = skill_level;

	if (guild_skill_map.count(key_))
	{
		return guild_skill_map[key_];
	}
	
	return NULL;
}


