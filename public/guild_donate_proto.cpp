#include "guild_donate_proto.h"
#include <fstream>
#include <assert.h>

int GuildDonatePrototype::Init( const char* data_file )
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

	for (int i=0; i<data_group_.group_size(); ++i)
	{
		const GuildDonateRateData& d = data_group_.group(i);
		prototypes_.insert(std::make_pair(d.money_type(), &d));
	}

	return true;
}

const GuildDonateRateData* GuildDonatePrototype::GetGuildDonateRateData( int money_type ) const
{
	Prototypes::const_iterator it = prototypes_.find(money_type);
	if ( it != prototypes_.end())
	{
		return it->second;
	}
	return NULL;
}
