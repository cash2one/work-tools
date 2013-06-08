#include <assert.h>
#include <fstream>
#include <string>
#include "combine_string_parser.h"
#include "instance_prototype.h"

#define INSTANCE_KEY(instance_id,grade) ((instance_id) << 8 | (grade) )

using namespace std;

void InstancePrototypeMgr::clear()
{
    prototypes_.clear() ;

	InstanceWantedConfigMap::iterator  map_itor = m_instance_wanted_map.begin();
	for (; map_itor != m_instance_wanted_map.end(); ++map_itor)
	{
		InstanceWantedConfigList*  config_list = map_itor->second;
		if (config_list)
		{
			delete config_list;
			config_list = NULL;
		}
	}
	
	m_instance_wanted_map.clear();

}
InstancePrototypeMgr::~InstancePrototypeMgr()
{
	clear();
}


bool InstancePrototypeMgr::InitInstance( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    InstanceDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.instance_list_size(); ++i)
    {
        const InstanceData& d = data_group_.instance_list(i);
        InstanceConfig& config = prototypes_[INSTANCE_KEY(d.instance_id() ,d.grade())];
        config.instance_data = d ;
    }

    return true;
}

void InstancePrototypeMgr::fill_auto_instance_drop_ids(int instance_id, int grade, IntIdArray& id_array)
{
    const InstanceConfig* config = GetInstanceConfig(instance_id, grade);
    if (config == NULL) return ;

    const string  orig_string = config->instance_data.hanging_drop_bags();
    
    std::vector<std::string>  raw_strings;
    combine_string_parser::split_by(orig_string, '|', raw_strings);
    
    for (auto itor = raw_strings.begin();
        itor != raw_strings.end(); ++itor)
    {
        string id_str = *itor;
        int drop_id = atoi(id_str.c_str());

        id_array.push_back(drop_id);
    }
}


bool InstancePrototypeMgr::InitInstanceNPC( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    InstanceNPCDataGroup npc_data_group_;

    if (!npc_data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<npc_data_group_.instance_npc_list_size(); ++i)
    {
        const InstanceNPCData& d = npc_data_group_.instance_npc_list(i);
        InstanceConfig& config = prototypes_[INSTANCE_KEY(d.instance_id() ,d.grade())];
        config.npc_data[d.npc_id()] = d ;
    }

    return true;
}


const InstanceConfig* InstancePrototypeMgr::GetInstanceConfig(int instance_id,int grade) const
{
    Prototypes::const_iterator it = prototypes_.find(INSTANCE_KEY(instance_id ,grade) );
    if (it != prototypes_.end()) return &(it->second);
    return NULL ;
}

bool InstancePrototypeMgr::InitInstanceWantedData(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	InstanceWantedDataGroup    data_group_;
	if (!data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	m_instance_wanted_map.clear();

	for (int i=0; i<data_group_.inst_wanted_data_size(); ++i)
	{
		const InstanceWantedData& d = data_group_.inst_wanted_data(i);
		
		InstanceWantedConfigList*  config_list = NULL;
		if (m_instance_wanted_map.count(d.instance_id()))
		{
			config_list = m_instance_wanted_map[d.instance_id()];
		}
		else
		{
			config_list = new InstanceWantedConfigList;
			m_instance_wanted_map[d.instance_id()] = config_list;
		}

		InstanceWantedConfig  item_config ;
		item_config.item_id = d.item_id();
		item_config.item_count = d.count();
		item_config.type = d.type();
		item_config.weight = d.weight();
		item_config.icon_id = d.icon_id();

		if (d.item_id() > 0 && d.type() > 0
			&& d.count() > 0 && d.weight() > 0
			&& d.icon_id() > 0)
		{
			config_list->push_back(item_config);
		}
		else
		{
			return false;
		}	
	}

	return true;

}


const InstanceWantedConfigList*  InstancePrototypeMgr::GetInstanceWantedConfigList(int instance_id)
{
	if (m_instance_wanted_map.count(instance_id))
	{
		return m_instance_wanted_map[instance_id];
	}
	else
	{
		return NULL;
	}
}


