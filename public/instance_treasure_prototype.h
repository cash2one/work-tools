#ifndef INSTANCE_TREASURE_PROTOTYPE_H_
#define INSTANCE_TREASURE_PROTOTYPE_H_

#include <map>
#include "../public/singleton.h"
#include "../config/instance_treasure_exchange.pb.h"



class InstanceTreasurePrototype
{
public:
    bool init(const char* data_file);

    const InstanceTreasureData* get_treasure(int instance_id,int treasure_id) const;

private:
    typedef std::map<int64_t,InstanceTreasureData> Prototypes;

    Prototypes m_prototype;


    DECLARE_SINGLETON_CONSTRUCTER(InstanceTreasurePrototype);
};

#define INSTANCE_TREASURE_INSTANCE Singleton<InstanceTreasurePrototype>::instance()


#endif 

