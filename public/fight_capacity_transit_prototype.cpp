#include <assert.h>
#include <fstream>
#include "fight_capacity_transit_prototype.h"

FightCapacityTransitPrototype::FightCapacityTransitPrototype()
{
    clear() ;
}

bool FightCapacityTransitPrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    FightCapacityTransitDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.capacity_size(); ++i)
    {
        const FightCapacityTransitData& d = data_group_.capacity(i);
        if( d.attr_key() >0 && d.attr_key() < MAX_ATTRIBUTE_COUNT && 
            d.attr_ratio()>0 )
        {
            m_capacity_transit[d.attr_key()] = d.attr_ratio() ;
        }
         
    }

    return true;
}



