#include <assert.h>
#include <fstream>
#include "yingling_prototype.h"
#include <assert.h>

using namespace std;


bool YinglingPrototypes::Init( const char* data_file )
{
	//assert(proto_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!pb_data_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<=5; i++)
	{
		std::vector<int> a;
		quality_yingling_.push_back(a);
	}

	for (int i=0; i<pb_data_.yingling_size(); ++i)
	{
		const YinglingInitData& d = pb_data_.yingling(i);
		proto_data_.insert(std::make_pair(d.tid(), &d));
		
		//assert(d.quality() >=0 && d.quality() <= 5);
		quality_yingling_[d.quality()].push_back(d.tid());
	}

	return true;
}


const YinglingInitData* YinglingPrototypes::GetYinglingPrototype( const int proto_id )
{
	ProtoData::iterator it = proto_data_.find(proto_id);
	if (it != proto_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

bool YinglingPrototypes::InitCharacterExpData(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail())  return false;

	if (!m_CharacterExpDataGroup.ParseFromIstream(&fs)) return false;

	for (int i=0; i < m_CharacterExpDataGroup.exp_data_size(); i++)
	{
		const CharacterExpData&  expData = m_CharacterExpDataGroup.exp_data(i);
		m_player_levelup_exp_map.insert( make_pair(expData.level(), expData.profession_exp()) );
	}

	return true;
}

int YinglingPrototypes::get_level_up_need_exp(int level) const
{
	PlayerLevelExpMap::const_iterator  itor = m_player_levelup_exp_map.find(level);
	if (itor != m_player_levelup_exp_map.end())
	{
		return itor->second;
	}
	return -1;
}

bool YinglingPrototypes::InitGrowthData( const char* data_file )
{
	//assert(growth_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!growth_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<growth_data_group_.pro_growns_size(); ++i)
	{
		const YinglingProGrownRate& d = growth_data_group_.pro_growns(i);
		growth_data_.insert(std::make_pair(d.profession(), &d));
	}

	return true;
}

bool YinglingPrototypes::InitHiringSlotData( const char* data_file )
{
	//assert(slot_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!hiring_slot_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<hiring_slot_data_group_.group_size(); ++i)
	{
		const YinglingHiringSlotData& d = hiring_slot_data_group_.group(i);
		hiring_slot_data_.insert(std::make_pair(d.slot_index(), &d));
	}

	return true;
}

bool YinglingPrototypes::InitHiringCost( const char* data_file )
{
	//assert(hiring_config_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!hiring_config_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<hiring_config_data_group_.group_size(); ++i)
	{
		const YinglingHiringConfigData& d = hiring_config_data_group_.group(i);
		hiring_config_data_.insert(std::make_pair(d.gen_type(), &d));
	}

	return true;
}

bool YinglingPrototypes::InitSlotData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!slot_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<slot_data_group_.group_size(); ++i)
	{
		const YinglingSlotData& d = slot_data_group_.group(i);
		if (d.cost_yuanbao() == 0)
			yuanbao_slot_data_.push_back(&d);
		slot_data_.insert(std::make_pair(d.slot_index(), &d));
	}

	return true;
}

bool YinglingPrototypes::InitLingliConvertData(const char* data_file)
{
	//assert(lingli_convert_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!lingli_convert_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<lingli_convert_data_group_.group_size(); ++i)
	{
		const YinglingLingliConvertData& d = lingli_convert_data_group_.group(i);
		lingli_convert_data_.insert(std::make_pair(d.quality(), &d));
	}

	return true;
}

bool YinglingPrototypes::InitLingliSummonData(const char* data_file)
{
	//assert(lingli_summon_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	//YinglingInitDataGroup datas;
	if (!lingli_summon_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<lingli_summon_data_group_.group_size(); ++i)
	{
		const YinglingLingliSummonData& d = lingli_summon_data_group_.group(i);
		lingli_summon_data_.insert(std::make_pair(d.quality(), &d));
	}

	return true;
}

bool YinglingPrototypes::InitFightExpFactorData(const char* data_file)
{
	//assert(data_file);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	if (!m_team_fight_exp_factor_group.ParseFromIstream(&fs))
	{
		return false;
	}

	return true;
}

const YinglingProGrownRate* YinglingPrototypes::GetProfessionGrowthData( const int pro_id )
{
	GrowthData::iterator it = growth_data_.find(pro_id);
	if (it != growth_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

const std::vector<int>& YinglingPrototypes::GetYinglingsByQuality( const int quality ) const
{
	//assert(quality >=0 && quality <= 5);
	return quality_yingling_[quality];
}

const YinglingHiringSlotData* YinglingPrototypes::GetYinglingHiringSlotData(const int index)
{
	HiringSlotData::iterator it = hiring_slot_data_.find(index);
	if (it != hiring_slot_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

const YinglingHiringConfigData* YinglingPrototypes::GetYinglingHiringConfigData(const int hire_type)
{
	HiringConfigData::iterator it = hiring_config_data_.find(hire_type);
	if (it != hiring_config_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

const YinglingSlotData* YinglingPrototypes::GetYinglingSlotData( const int index )
{
	SlotData::iterator it = slot_data_.find(index);
	if (it != slot_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}


const YinglingLingliConvertData* YinglingPrototypes::GetLingliConvertData(const int quality)
{
	LingliConvertData::iterator it = lingli_convert_data_.find(quality);
	if (it != lingli_convert_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

const YinglingLingliSummonData* YinglingPrototypes::GetLingliSummonData(const int quality)
{
	LingliSummonData::iterator it = lingli_summon_data_.find(quality);
	if (it != lingli_summon_data_.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}

int YinglingPrototypes::get_exp_factor(int team_member_count)
{
	for (int i=0; i < m_team_fight_exp_factor_group.team_exp_factor_size(); i++)
	{
		const TeamFightExpFactorData&  d = m_team_fight_exp_factor_group.team_exp_factor(i);
		if (d.team_member_count() == team_member_count)
		{
			return d.exp_factor();
		}
	}
	
	return -1;
}

