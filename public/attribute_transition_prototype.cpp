#include <assert.h>
#include <fstream>
#include "attribute_transition_prototype.h"

bool ProfessionAttributeTransition::Init( const char* data_file )
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

	for (int i=0; i<data_group_.pro_attr_transits_size(); ++i)
	{
		const PlayerAttrTransition& d = data_group_.pro_attr_transits(i);
		prototypes_.insert(std::make_pair(d.prof_id(), &d));
	}

	return true;
}

const PlayerAttrTransition* ProfessionAttributeTransition::GetAttributeTransition( int profession )
{
	Prototypes::iterator it = prototypes_.find(profession);
	if (it != prototypes_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

