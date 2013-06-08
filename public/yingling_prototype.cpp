#include <assert.h>
#include <fstream>
#include <algorithm>
#include "yingling_prototype.h"
#include "../public/str_util.h"
#include <assert.h>
#include "game_common.pb.h"
#include <algorithm>

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

bool YinglingPrototypes::YinglingRecruitingslotData(const char* data_file)
{
	std::fstream fs(data_file,std::ios::in|std::ios::binary);

	if(fs.fail())
	{
		return false;
	}

	if(!recruiting_data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	for(int i=0;i<recruiting_data_group_.group_size();i++)
	{
		const YinglingRecruitingData& d=recruiting_data_group_.group(i);

		if(d.upper_limit_level()<d.lower_limit_level())
		{
			return false;
		}

		//inserted type: <<int,<int,int>>,YinglingRecruitingData*>
		recruiting_slot_data_.insert(make_pair(make_pair(d.recruiting_type(),make_pair(d.lower_limit_level(), d.upper_limit_level())),&d));
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

bool YinglingPrototypes::InitYinglingTrain( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail())  return false;

	YinglingTrainConfigGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) 
		return false;
	
	train_config_data_.resize(protocols::common::TrainType_MAX + 1);

	for (int i=0; i < data_group.group_size(); i++)
	{
		const YinglingTrainConfig&  data = data_group.group(i);
		
		train_config_data_[data.train_type()].insert(std::make_pair(data.level(), data));

	}

	return true;
}

bool YinglingPrototypes::InitYinglingTrainCost( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail())  return false;

	YinglingTrainCostConfigGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) 
		return false;

	train_cost_config_data_.resize(protocols::common::TrainType_MAX + 1);

	for (int i=0; i < data_group.group_size(); i++)
	{
		const YinglingTrainCostConfig&  data = data_group.group(i);

		train_cost_config_data_[data.train_type()].insert(std::make_pair(data.attribute_num(), data));

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

bool YinglingPrototypes::InitYinglingHiringLibData( const char* data_file )
{
	//assert(proto_data_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	YinglingLibDataGroup pb_data;
	if (!pb_data.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<pb_data.group_size(); ++i)
	{
		const YinglingLibData& d = pb_data.group(i);
		HirableLibData* lib_data = yingling_hiring_lib_data_[d.lib_id()];
		if (lib_data == NULL)
		{
			lib_data = new HirableLibData();
			lib_data->quality_chance.resize(10);
			lib_data->quality_yinglings.resize(10);
			yingling_hiring_lib_data_[d.lib_id()] = lib_data;
		}

		lib_data->max_chance += d.weight();
		lib_data->yingling_chance.insert(std::make_pair(lib_data->max_chance, d.yingling_tid()));

		const YinglingInitData* proto = GetYinglingPrototype(d.yingling_tid());
		if (!proto)
			return false;
		if (lib_data->quality_chance.capacity() < (size_t)proto->quality())
		{
			lib_data->quality_chance.resize(proto->quality() + 1);
			lib_data->quality_yinglings.resize(proto->quality() + 1);
		}
		lib_data->quality_chance[proto->quality()] += d.weight();
		lib_data->quality_yinglings[proto->quality()].push_back(d.yingling_tid());

	}

	return true;
}

HirableLibData* YinglingPrototypes::get_yingling_lib( int lib_id ) const
{
	YinglingHiringLibData::const_iterator it = yingling_hiring_lib_data_.find(lib_id);
	if (it != yingling_hiring_lib_data_.end())
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
}

const YinglingRecruitingData* YinglingPrototypes::GetYinglingRecruitingslotData(int recruiting_type,int player_level)
{
	RecruitingSlotData::const_iterator it = recruiting_slot_data_.begin();

	for( ; it != recruiting_slot_data_.end(); it++)
	{
		const LevelRangePair& level_pair = (it->first).second;

		if(player_level >= level_pair.first && player_level <= level_pair.second
            && recruiting_type == it->second->recruiting_type())
		{
            return it->second;
		}
	}

	return NULL;
}

int YinglingPrototypes::gen_yingling_by_lib( int lib_id ) const
{
	YinglingHiringLibData::const_iterator it = yingling_hiring_lib_data_.find(lib_id);
	if (it != yingling_hiring_lib_data_.end())
	{
		HirableLibData* lib_data = it->second;
		if (lib_data == NULL)
			return 0;

		int r_value = random(1, lib_data->max_chance);
		std::map<int, int>::iterator it = lib_data->yingling_chance.upper_bound(r_value);
		if (it != lib_data->yingling_chance.end())
		{
			return it->second;
		}
	}

	return 0;
}

bool YinglingPrototypes::InitYinglingCombo( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail())  return false;

	YinglingComboDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i < data_group.group_size(); i++)
	{
		const YinglingComboData&  data = data_group.group(i);
		SYinglingComboData sdata;
		sdata.combo_id = data.combo_id();
		sdata.combo_status = 0;
		sdata.combo_level = 1;
		sdata.id_type = data.id_type();
		if (data.id1() != 0) 
			sdata.ids.push_back(std::make_pair(data.id1(), 0));
		if (data.id2() != 0) 
			sdata.ids.push_back(std::make_pair(data.id2(), 0));
		if (data.id3() != 0) 
			sdata.ids.push_back(std::make_pair(data.id3(), 0));
		if (data.id4() != 0) 
			sdata.ids.push_back(std::make_pair(data.id4(), 0));
		if (data.id5() != 0) 
			sdata.ids.push_back(std::make_pair(data.id5(), 0));

		syingling_combo_data_.insert(std::make_pair(sdata.combo_id, sdata));

		{
			for (std::vector<std::pair<int,int> >::iterator itt = sdata.ids.begin(); itt!=sdata.ids.end(); ++itt)
			{
				int id = itt->first;
				ComboDataRefData::iterator it = combo_data_ref_data_.find(std::make_pair(sdata.id_type, id));
				if ( it == combo_data_ref_data_.end())
				{
					std::vector<int> vv;
					it = combo_data_ref_data_.insert(std::make_pair(std::make_pair(sdata.id_type, id), vv)).first;
					if (it == combo_data_ref_data_.end())
						return false;
				}
				if (find(it->second.begin(), it->second.end(), sdata.combo_id) == it->second.end())
                    it->second.push_back(sdata.combo_id);
			}
		}
		
	}

	return true;
}

bool YinglingPrototypes::InitYinglingComboBonus( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail())  return false;

	YinglingComboBonusDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i < data_group.group_size(); i++)
	{
		const YinglingComboBonusData&  data = data_group.group(i);
		ComboBonusData::iterator it = combo_bonus_data_.find(std::make_pair(data.combo_id(), data.level()));
		SYinglingComboBonusData bonus_data;
		bonus_data.combo_id = data.combo_id();
		bonus_data.combo_level = data.level();
		bonus_data.cost_lingli = data.cost_lingli();
		bonus_data.bonus.insert(std::make_pair(data.bonus_id1(), data.bonus_num1()));
		bonus_data.bonus.insert(std::make_pair(data.bonus_id2(), data.bonus_num2()));
		bonus_data.bonus.insert(std::make_pair(data.bonus_id3(), data.bonus_num3()));
		bonus_data.bonus.insert(std::make_pair(data.bonus_id4(), data.bonus_num4()));
		bonus_data.bonus.insert(std::make_pair(data.bonus_id5(), data.bonus_num5()));
		bonus_data.bonus.insert(std::make_pair(data.bonus_id6(), data.bonus_num6()));

		combo_bonus_data_.insert(std::make_pair(std::make_pair(bonus_data.combo_id, bonus_data.combo_level), bonus_data));

	}
	return true;
}

// bool YinglingPrototypes::InitYinglingComboUpgrade( const char* data_file )
// {
// 	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
// 	if (fs.fail())  return false;
// 
// 	YinglingComboUpgradeDataGroup data_group;
// 	if (!data_group.ParseFromIstream(&fs)) return false;
// 
// 	for (int i=0; i < data_group.group_size(); i++)
//	{
// 		const YinglingComboUpgradeData&  data = data_group.group(i);
// 		combo_upgrade_data_.insert(std::make_pair(std::make_pair(data.combo_id(), data.level()), data));
// 	}
// 
// 	return true;
// }

const SYinglingComboData* YinglingPrototypes::GetYinglingComboData( int combo_id ) const
{
	SYinglingComboDatas::const_iterator it = syingling_combo_data_.find(combo_id);
	if (it!=syingling_combo_data_.end())
	{
		return &it->second;
	}
	else
	{
		return NULL;
	}
}

const std::vector<int>* YinglingPrototypes::GetTriggerComboIdList( int id_type, int id ) const
{
	ComboDataRefData::const_iterator it = combo_data_ref_data_.find(std::make_pair(id_type, id));
	if (it != combo_data_ref_data_.end())
	{
		return &it->second;
	}
	else
	{
		return NULL;
	}	
}

const YinglingTrainConfig* YinglingPrototypes::GetTrainConfig( int train_type, int level )
{
	if (train_type < 0 || (size_t)train_type >= train_config_data_.size())
		return NULL;
	std::map<int, YinglingTrainConfig>::const_iterator it = train_config_data_[train_type].lower_bound(level);
	if (it != train_config_data_[train_type].end())
		return &it->second;
	else
		return NULL;

}

const YinglingTrainCostConfig* YinglingPrototypes::GetTrainCostConfig( int train_type, int num )
{
	if (train_type < 0 || (size_t)train_type >= train_cost_config_data_.size())
		return NULL;
	std::map<int, YinglingTrainCostConfig>::const_iterator it = train_cost_config_data_[train_type].lower_bound(num);
	if (it != train_cost_config_data_[train_type].end())
		return &it->second;
	else
		return NULL;
}

bool YinglingPrototypes::InitYinglingSoulRevert( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail())  return false;

	YinglingSoulRevertConfigGroup data_group;
	if (!data_group.ParseFromIstream(&fs)) return false;

	for (int i=0; i < data_group.group_size(); i++)
	{
		const YinglingSoulRevertConfig&  data = data_group.group(i);
		soul_revert_data_.insert(std::make_pair(data.soul(), data.revert_num()));
	}
	return true;
}


