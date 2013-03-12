#include <assert.h>
#include <fstream>
#include <algorithm>
#include "hide_npc_prototype.h"
#include "../public/str_util.h"

int HideNpcPrototype::InitDefaultHide( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}
	DefaultHideNpcDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}
	//equip_level_range_.push_back(0);
	for (int i=0; i<data_group.group_size(); ++i)
	{
		const DefaultHideNpcData& d = data_group.group(i);
		protocols::common::HideNpcData* data = default_hide_npc_.add_hide_datas();
		data->set_npc_id(d.npc_id());
		data->set_is_display(false);
	}

	return true;
}

int HideNpcPrototype::InitQuestHide( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}
	QuestHideNpcDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group.group_size(); ++i)
	{
		const QuestHideNpcData& d = data_group.group(i);
		QuestHidePrototype::iterator it = quest_hide_prototypes_.find(std::make_pair(d.quest_id(), d.quest_status()));
		if (it == quest_hide_prototypes_.end())
		{
			std::vector<QuestHideNpcData> tmp;
			quest_hide_prototypes_.insert(std::make_pair(std::make_pair(d.quest_id(), d.quest_status()), tmp));
			it = quest_hide_prototypes_.find(std::make_pair(d.quest_id(), d.quest_status()));
		}
		//assert(it != quest_hide_prototypes_.end());
		it->second.push_back(d);
	}

	return true;
}

int HideNpcPrototype::InitRandomPosition( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}
	RandomPositionDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group.group_size(); ++i)
	{
		const RandomPositionData& d = data_group.group(i);
		RandomPositionPrototype::iterator it = random_positions_.find(d.pos_cate_id());
		if (it == random_positions_.end())
		{
			std::vector<protocols::common::NpcPosition> tmp;
			random_positions_.insert(std::make_pair(d.pos_cate_id(), tmp));
			it = random_positions_.find(d.pos_cate_id());
		}
		//assert(it != quest_hide_prototypes_.end());
		protocols::common::NpcPosition pos;
		pos.set_map_id(d.map_id());
		pos.set_x(d.x());
		pos.set_y(d.y());
		pos.set_rotate(d.rotate());
		it->second.push_back(pos);
	}

	return true;
}

const protocols::common::NpcPosition* HideNpcPrototype::RandomPosition( int pos_cate_id )
{
	RandomPositionPrototype::iterator it = random_positions_.find(pos_cate_id);
	if (it != random_positions_.end())
	{
		std::vector<protocols::common::NpcPosition>& v = it->second;
		if (v.size() > 0)
		{
			int i = random(0, v.size()-1);
			return &v.at(i);
		}
	}
	return NULL;
}
