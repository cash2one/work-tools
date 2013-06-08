#include "level_experience_prototype.h"
#include "../config/level_experience.pb.h"
#include <fstream>
#include <assert.h>


int LevelExperiencePrototype::Init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	LevelExperienceGroup datas;
	if (!datas.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<datas.level_experience_size(); ++i)
	{
		const LevelExperience& d = datas.level_experience(i);
		level_experience_.insert(std::make_pair(d.level(), d.profession_exp()));
	}

	return true;
}

int LevelExperiencePrototype::GetLevelExp( int level )
{
	Container::iterator it = level_experience_.find(level);
	if (it != level_experience_.end())
	{
		return it->second;
	}
	else
	{
		return -1;
	}
}
