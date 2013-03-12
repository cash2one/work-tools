#ifndef INSTANCE_PROTO_MGR_H
#define INSTANCE_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/instance.pb.h"
#include "../config/instance_npc.pb.h"
#include "instance_wanted.pb.h"

typedef std::map<int, InstanceNPCData> InstanceNPCContainer ;

struct InstanceWantedConfig
{
	int  item_id;
	int  item_count;
	int  type;
	int  weight;
	int  icon_id;

	void init() {
		memset(this, 0, sizeof(*this));
	}
};

typedef std::vector<InstanceWantedConfig>  InstanceWantedConfigList;

// [inst_id , item_list]
typedef std::map<int, InstanceWantedConfigList*> InstanceWantedConfigMap; 


struct InstanceConfig
{
    InstanceData instance_data ;
    InstanceNPCContainer npc_data ;
} ;

class InstancePrototypeMgr
{
public:
	~InstancePrototypeMgr();

    bool InitInstance(const char* data_file);
    bool InitInstanceNPC(const char* data_file);
    void clear() ;
	const InstanceConfig* GetInstanceConfig(int instance_id,int grade) const;

	// ??????
	bool InitInstanceWantedData(const char* data_file);
	const InstanceWantedConfigList*  GetInstanceWantedConfigList(int instance_id);

private:
    typedef std::map<int,InstanceConfig> Prototypes;

    Prototypes prototypes_;

	// ??????
	
	InstanceWantedConfigMap    m_instance_wanted_map;

    //DECLARE_SINGLETON_CONSTRUCTER(InstancePrototypeMgr);
};




#endif 

