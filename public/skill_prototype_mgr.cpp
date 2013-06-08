#include <assert.h>
#include <fstream>
#include "skill_prototype_mgr.h"

using namespace std;

void SkillPrototypeMgr::clear()
{
	m_prof_level_skills.clear();
    prototypes_.clear();
    data_group_.Clear();

    skill_book_prototypes_.clear();
    skill_book_data_group_.Clear();

    skill_practice_prototypes_.clear();
    skill_practice_data_group_.Clear();

}

bool SkillPrototypeMgr::InitSkill( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.skill_size(); ++i)
	{
		const SkillData& d = data_group_.skill(i);
		prototypes_.insert(std::make_pair(std::make_pair(d.skillid(), d.skill_level()), &d));
	}

	return true;
}

bool SkillPrototypeMgr::InitSkillBook( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );

	if (fs.fail())  return false;

	if (!skill_book_data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<skill_book_data_group_.skillbook_size(); ++i)
	{
		const SkillBookData& d = skill_book_data_group_.skillbook(i);
		skill_book_prototypes_.insert(std::make_pair(d.id(), &d));

		if (d.type() == 4) // 职业技能
		{
			ProfessionSkillKey  _key = make_pair(d.prof_need(), d.prof_level_limit());

			SkillIDList&  skills = m_prof_level_skills[_key];
			skills.insert(d.id());
		}
	}

	return true;
}

const SkillIDList*  SkillPrototypeMgr::GetSkillIdList(int prof, int level)
{
	ProfessionSkillKey  _key = make_pair(prof, level);

	if (m_prof_level_skills.count(_key) > 0)
	{
		return &m_prof_level_skills[_key];
	}

	return NULL;
}

const SkillData* SkillPrototypeMgr::GetSkillPrototype( int proto_id, int level )
{
	Prototypes::iterator it = prototypes_.find(std::make_pair(proto_id,level));
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

const SkillBookData* SkillPrototypeMgr::GetSkillBookPrototype( int proto_id )
{
	SkillBookPrototypes::iterator it = skill_book_prototypes_.find(proto_id);
	if (it != skill_book_prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

bool SkillPrototypeMgr::InitSkillPracticeData( const char* data_file )
{
	//assert(skill_practice_prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!skill_practice_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<skill_practice_data_group_.practice_mode_size(); ++i)
	{
		const SkillPracticeModeData& d = skill_practice_data_group_.practice_mode(i);
		skill_practice_prototypes_.insert(std::make_pair(d.mode(), &d));
	}

	return true;
}

const SkillPracticeModeData* SkillPrototypeMgr::GetSkillPracticeModeData(int mode)
{
	if (skill_practice_prototypes_.count(mode) > 0)
	{
		return skill_practice_prototypes_[mode];
	}
	return NULL;
}

bool SkillPrototypeMgr::InitBattleSkillUpgrade( const char* data_file )
{
	////assert(skill_practice_prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	BattleSkillUpgradeDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group.data_size(); ++i)
	{
		const BattleSkillUpgradeData& d = data_group.data(i);
		skill_upgrade_data_.insert(std::make_pair(
			std::make_pair(d.battle_skill_id(), d.level()), d.need_youli()));
	}

	return true;
}

