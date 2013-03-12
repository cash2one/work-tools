#include <assert.h>
#include <fstream>
#include "item_gift_prototype.h"


bool ItemGiftPrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    ItemGiftDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.item_gift_size(); ++i)
    {
        const ItemGiftData& d = data_group_.item_gift(i);
        m_prototype[d.gift_tid()] = d ; 
        
    }

    return true;
}


const ItemGiftData* ItemGiftPrototype::get_item_gift(int gift_id) const
{
    Prototypes::const_iterator it = m_prototype.find(gift_id );
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}

