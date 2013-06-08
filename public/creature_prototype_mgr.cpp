#include <assert.h>
#include <fstream>
#include "creature_prototype_mgr.h"



bool CreaturePrototypeMgr::Init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i<data_group_.creature_size(); ++i)
	{
		const CreatureInitData& d = data_group_.creature(i);
		prototypes_.insert(std::make_pair(d.tid(), &d));
	}

	return true;
}

bool CreaturePrototypeMgr::InitMonsterBuff(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false;

	if (!buff_data_group_.ParseFromIstream(&fs)) return false;

	for (int i=0; i < buff_data_group_.buff_data_size(); ++i)
	{
		const MonsterBuffData&  d = buff_data_group_.buff_data(i);
		buff_map.insert(std::make_pair(d.buff_id(), &d));
	}

	return true;
}

const MonsterBuffData*  CreaturePrototypeMgr::GetMonsterBuff(int buff_id)
{
	if (buff_map.count(buff_id))
	{
		return buff_map[buff_id];
	}

	return NULL;
}

const CreatureInitData* CreaturePrototypeMgr::GetCreaturePrototype( int creature_id )
{
	Prototypes::iterator it = prototypes_.find(creature_id);
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}
