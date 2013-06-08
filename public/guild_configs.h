/*******************************************************************************
 *
 *      @file: guild_configs.h
 *      @brief: guild csv configs read and parse.
 *
 *      @author: gxl.
 *      @Date: 2013/03/18
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef GUILD_CONFIGS_H
#define GUILD_CONFIGS_H

#include <map>
#include <set>

#include "guild_skills.pb.h"

typedef std::set<int> SkillIDs;

class GuildConfigMgr
{
public:
	void Clear();

	bool InitGuildSkill(const char* data_file);

	const GuildSkillData*  GetGuildSkillData(int skill_id, int skill_level);
	const SkillIDs*  GetAllSkillIds() const { return &m_skill_ids; }

private:
	typedef std::pair<int, int>  GuildSkillKey;

	typedef std::map<GuildSkillKey, const GuildSkillData*>  GuildSkillMap; 
	GuildSkillMap       guild_skill_map;
	GuildSkillDataGroup data_group_;
	SkillIDs            m_skill_ids;

};




#endif
