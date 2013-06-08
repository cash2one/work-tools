#include <assert.h>
#include <fstream>
#include "guild_shop_prototype.h"


bool GuildShopPrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    GuildShopDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.shop_size(); ++i)
    {
        const GuildShopData& d = data_group_.shop(i);
        m_prototype[ d.item_tid()] = d ;
         
    }

    return true;
}


const GuildShopData* GuildShopPrototype::get_shop_item(int item_tid) const
{
    
    Prototypes::const_iterator it = m_prototype.find(item_tid );
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}

