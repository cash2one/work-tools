#include <fstream>
#include "gem_prototype.h"


bool GemPrototype::init_upgrade_config( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	if (!upgrade_config_data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<upgrade_config_data_group_.data_size(); ++i)
	{
		const GemUpgradeConfigData& d = upgrade_config_data_group_.data(i);
		UpgradePrototypes::iterator it = upgrade_prototypes_.find(d.gem_id());
		if (it == upgrade_prototypes_.end())
		{
			std::vector<std::pair<int, int> > tv;
			it = upgrade_prototypes_.insert(std::make_pair(d.gem_id(), tv)).first;
		}
		if (it == upgrade_prototypes_.end())
			return -1;

		it->second.push_back(std::make_pair(d.need_item(), d.need_num()));
	}

	return true;
}

bool GemPrototype::init_insert_config( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	GemInsertConfigDataGroup data_group;

	if (!data_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<data_group.data_size(); ++i)
	{
		const GemInsertConfigData& d = data_group.data(i);
		insert_prototypes_.insert(
			std::make_pair(
				std::make_pair(d.gem_id(), d.equip_pos()), 
				std::make_pair(d.attr_bonus_id(), d.attr_bonus_num())));
	}

	return true;
}

bool GemPrototype::init_gem_base(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	if (!gem_base_info_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<gem_base_info_group_.data_size(); ++i)
	{
		const GemBaseInfoData& d = gem_base_info_group_.data(i);
		gem_base_prototypes_.insert(
			std::make_pair(d.gem_id(), &d));
	}

	return true;
}
