#include <assert.h>
#include <fstream>
#include "transport_prototype.h"


bool TransportPrototypeMgr::Init( const char* data_file )
{
	//assert(prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group_.transport_size(); ++i)
	{
		const TransportData& d = data_group_.transport(i);
		prototypes_.insert(std::make_pair(d.npc_id(), &d) );
	}

	return true;
}

const TransportData* TransportPrototypeMgr::GetTransportPrototype(int npc_id)
{
	Prototypes::iterator it = prototypes_.find(npc_id);
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}
