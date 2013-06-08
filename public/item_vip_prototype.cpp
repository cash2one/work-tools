#include <assert.h>
#include <fstream>
#include "item_vip_prototype.h"


bool ItemVipPrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    ItemVipDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.item_size(); ++i)
    {
        const ItemVipData& d = data_group_.item(i);
        m_prototype[d.item_tid()] = d ;

    }

    return true;
}

bool ItemVipPrototype::init_limit_count(const char* data_file)
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    ItemLimitCountDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.data_size(); ++i)
    {
        const ItemLimitCountData& d = data_group_.data(i);
        m_limit_count_prototype[d.item_tid()] = d ;

    }

    return true;
}

const ItemVipData* ItemVipPrototype::get_item(int item_tid) const
{
    Prototypes::const_iterator it = m_prototype.find(item_tid);
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}
const ItemLimitCountData* ItemVipPrototype::get_limit_count_item(int item_tid) const
{
    LimitCountPrototypes::const_iterator it = m_limit_count_prototype.find(item_tid);
    if (it != m_limit_count_prototype.end()) return &(it->second);
    return NULL ;
}
