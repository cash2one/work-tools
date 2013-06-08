#include "buddy_soul_prototype.h"
#include "../config/soul_injection.pb.h"
#include <fstream>
#include <assert.h>


int BuddySoulPrototype::Init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group_.data_size(); ++i)
	{
		const InjectSoulData& d = data_group_.data(i);
		prototypes_.insert(std::make_pair(d.quality_num(), &d));
	}

	return true;
}

const InjectSoulData* BuddySoulPrototype::GetInjectSoulData( int quality_num ) const
{
	Prototypes::const_iterator it = prototypes_.find(quality_num);
	if ( it != prototypes_.end())
	{
		return it->second;
	}
	return NULL;
}

int BuddySoulPrototype::InitSpaceTimeBattlePrototypes( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!spacetime_battle_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<spacetime_battle_data_group_.data_group_size(); ++i)
	{
		const SpaceTimeBattleData& d = spacetime_battle_data_group_.data_group(i);
		battle_prototypes_.insert(std::make_pair(std::make_pair(d.buddy_id(),d.spacetime_level()), &d));
	}

	return true;
}

const SpaceTimeBattleData* BuddySoulPrototype::GetSpaceTimeBattleId( int buddy_id, int spacetime_level ) const
{
	SpaceTimeBattlePrototypes::const_iterator it = 
		battle_prototypes_.find(std::make_pair(buddy_id, spacetime_level));
	if (it != battle_prototypes_.end())
	{
		return it->second;
	}
	return NULL;
}
