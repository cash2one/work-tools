#include "resource_prototype.h"
#include <fstream>
#include <assert.h>

int ResourcePrototype::Init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	ResourceDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group.group_size(); ++i)
	{
		const ResourceData& d = data_group.group(i);
		prototypes_.insert(std::make_pair(d.npc_id(), d));
	}

	return true;
}

const ResourceData* ResourcePrototype::GetResourceData( int resource_id )
{
	Prototypes::const_iterator it = prototypes_.find(resource_id);
	if ( it != prototypes_.end())
	{
		return &it->second;
	}
	return NULL;
}
