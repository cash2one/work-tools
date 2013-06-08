#include <assert.h>
#include <fstream>
#include "instance_treasure_prototype.h"


bool InstanceTreasurePrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    InstanceTreasureDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.treasure_list_size(); ++i)
    {
        const InstanceTreasureData& d = data_group_.treasure_list(i);
        m_prototype[(int64_t)d.instance_id() << 32 |  d.treasure_id()] = d ; 
        
    }

    return true;
}


const InstanceTreasureData* InstanceTreasurePrototype::get_treasure(int instance_id,int treasure_id) const
{
    int64_t key = (int64_t)instance_id << 32 | treasure_id ;
    Prototypes::const_iterator it = m_prototype.find(key);
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}

