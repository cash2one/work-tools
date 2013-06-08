#ifndef LEVEL_EXPERIENCE_PROTOTYPE_H
#define LEVEL_EXPERIENCE_PROTOTYPE_H
#include <map>
#include "singleton.h"

class LevelExperiencePrototype
{
public:
	int Init(const char* data_file);
	int GetLevelExp(int level);
private:
	typedef std::map<int,int> Container;
	Container level_experience_;
	DECLARE_SINGLETON_CONSTRUCTER(LevelExperiencePrototype);
};

#define LEVEL_EXP_PROTOTYPE Singleton<LevelExperiencePrototype>::instance()

#endif //LEVEL_EXPERIENCE_PROTOTYPE_H
