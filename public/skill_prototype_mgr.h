#ifndef SKILL_PROTOTYPE_MGR_H
#define SKILL_PROTOTYPE_MGR_H

#include <map>
#include <set>
#include "../public/singleton.h"
#include "../config/skillbook.pb.h"
#include "../config/skills.pb.h"
#include "../config/skill_practice_mode.pb.h"

typedef std::set<int>  SkillIDList; // skill id

class SkillPrototypeMgr
{
public:
	//职业技能
	bool InitSkill(const char* data_file);
	// 组合技能，阵法技能
	bool InitSkillBook(const char* data_file);
	
	bool InitSkillPracticeData(const char* data_file);

	bool InitBattleSkillUpgrade(const char* data_file);

	const SkillData* GetSkillPrototype(int proto_id, int level);
	const SkillBookData* GetSkillBookPrototype(int proto_id);

	// 根据职业和等级得到当前可学的技能
	const SkillIDList*  GetSkillIdList(int prof, int level);

	const SkillPracticeModeData* GetSkillPracticeModeData(int mode);

	int GetBattleSkillUpgradeYouli(int skill_id, int cur_level) const
	{
		SkillUpgradeData::const_iterator it = skill_upgrade_data_.find(std::make_pair(skill_id, cur_level));
		if (it != skill_upgrade_data_.end())
		{
			return it->second;
		}
		else
		{
			return -1;
		}
	}

    void clear() ;
private:
	typedef std::map<std::pair<int,int>, const SkillData*> Prototypes;
	typedef std::map<int, const SkillBookData*> SkillBookPrototypes;
	typedef std::map<int, const SkillPracticeModeData*> SkillPracticePrototypes;
	typedef std::map<std::pair<int, int>, int> SkillUpgradeData;

	// [prof, level]
	typedef std::pair<int, int> ProfessionSkillKey;
	
	typedef std::map<ProfessionSkillKey, SkillIDList>   ProfLevelSkillMap;

	Prototypes prototypes_;
	SkillDataGroup data_group_;
	ProfLevelSkillMap  m_prof_level_skills;

	SkillBookPrototypes skill_book_prototypes_;
	SkillBookDataGroup skill_book_data_group_;

	SkillPracticePrototypes skill_practice_prototypes_;
	SkillPracticeModeDataGroup skill_practice_data_group_;

	SkillUpgradeData skill_upgrade_data_;

	//DECLARE_SINGLETON_CONSTRUCTER(SkillPrototypeMgr);
};


//#define YINGLING_INSTANCE Singleton<SkillPrototypeMgr>::instance()

#endif //SKILL_PROTOTYPE_MGR_H
