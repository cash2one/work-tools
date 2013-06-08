#ifndef FIGHT_CAPACITY_PROTO_MGR_H
#define FIGHT_CAPACITY_PROTO_MGR_H

#include <map>
#include <stdint.h>
#include "../public/singleton.h"
#include "../config/fight_capacity_transit.pb.h"



class FightCapacityTransitPrototype
{
public:
    enum { MAX_ATTRIBUTE_COUNT = 64 , } ;
public:
    FightCapacityTransitPrototype() ;

    bool init(const char* data_file);

	void clear()
	{
        memset(m_capacity_transit,0,sizeof(m_capacity_transit)) ;
	}

    int calc_capacity(int attr_key,int attr_value)
    {
        if( attr_key < 0 || (size_t)attr_key >= sizeof(m_capacity_transit)) return 0 ;
        return m_capacity_transit[attr_key] * attr_value ;

    }

private:
    int8_t m_capacity_transit[MAX_ATTRIBUTE_COUNT] ;


//    DECLARE_SINGLETON_CONSTRUCTER(FightCapacityTransitPrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<FightCapacityTransitPrototype>::instance()


#endif 

