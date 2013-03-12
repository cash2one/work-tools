#include <assert.h>
#include <fstream>
#include "item_yingling_prototype.h"


bool ItemYinglingPrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    ItemYinglingDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.item_yingling_size(); ++i)
    {
        const ItemYinglingData& d = data_group_.item_yingling(i);
        m_prototype[d.item_tid()] = d ; 
        
    }

    return true;
}


const ItemYinglingData* ItemYinglingPrototype::get_item_yingling(int item_tid) const
{
    Prototypes::const_iterator it = m_prototype.find(item_tid);
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}

