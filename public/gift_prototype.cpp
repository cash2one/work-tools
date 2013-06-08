#include <fstream>
#include "gift_prototype.h"

bool GiftPrototype::init( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	GiftPackDataGroup data_group_;

	if (!data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<data_group_.group_size(); ++i)
	{
		const GiftPackData& d = data_group_.group(i);
		Prototypes::iterator it = prototypes_.find(d.pack_id());
		if (it == prototypes_.end())
		{
			std::vector<GiftPackData> tv;
			it = prototypes_.insert(std::make_pair(d.pack_id(), tv)).first;
		}
		if (it == prototypes_.end())
			return -1;
		
		it->second.push_back(d);
	}

	return true;
}

bool GiftPrototype::init_daily_gift( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	GiftDailyDataGroup data_group_;

	if (!data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<data_group_.group_size(); ++i)
	{
		const GiftDailyData& d = data_group_.group(i);
		daily_gift_prototypes_.insert(std::make_pair(d.vip_level(), d.pack_id()));
		vip_first_reward_prototypes_.insert(std::make_pair(d.vip_level(), d.first_reward_pack_id()));
	}

	return true;
}

bool GiftPrototype::init_stackable_online_gift( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	GiftStackableOnlineDataGroup data_group_;

	if (!data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<data_group_.group_size(); ++i)
	{
		const GiftStackableOnlineData& d = data_group_.group(i);
		stackable_online_gift_prototypes_.insert(std::make_pair(d.online_day_num(), d.pack_id()));
	}

	return true;
}
