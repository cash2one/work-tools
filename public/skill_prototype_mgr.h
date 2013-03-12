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
	//ְҵ����
	bool InitSkill(const char* data_file);
	// ��ϼ��ܣ��󷨼���
	bool InitSkillBook(const char* data_file);
	
	bool InitSkillPracticeData(const char* data_file);

	const SkillData* GetSkillPrototype(int proto_id, int level);
	const SkillBookData* GetSkillBookPrototype(int proto_id);

	// ����ְҵ�͵ȼ��õ���ǰ��ѧ�ļ���
	const SkillIDList*  GetSkillIdList(int prof, int level);

	const SkillPracticeModeData* GetSkillPracticeModeData(int mode);
    void clear() ;
private:
	typedef std::map<std::pair<int,int>, const SkillData*> Prototypes;
	typedef std::map<int, const SkillBookData*> SkillBookPrototypes;
	typedef std::map<int, const SkillPracticeModeData*> SkillPracticePrototypes;

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

	//DECLARE_SINGLETON_CONSTRUCTER(SkillPrototypeMgr);
};


//#define YINGLING_INSTANCE Singleton<SkillPrototypeMgr>::instance()

#endif //SKILL_PROTOTYPE_MGR_H