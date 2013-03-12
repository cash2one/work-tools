#include <assert.h>
#include <fstream>
#include "liveness_prototype.h"



void LivenessPrototypeManager::clear()
{
    m_condition_list.clear() ;

	m_award_list.clear();

}



bool LivenessPrototypeManager::load_condition( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    LivenessConditionDataGroup data_group;

    if (!data_group.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group.condition_list_size(); ++i)
    {
        const LivenessConditionData& d = data_group.condition_list(i);
        m_condition_list[d.condition_id()] = d ;
       
    }

    return true;
}

bool LivenessPrototypeManager::load_award( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    LivenessAwardDataGroup data_group;

    if (!data_group.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group.award_list_size(); ++i)
    {
        const LivenessAwardData& d = data_group.award_list(i);
        m_award_list[d.award_id()] = d ;
       
    }

    return true;
}

const LivenessConditionData* LivenessPrototypeManager::get_condition(int condition_id) const
{
    ConditionContainer::const_iterator it = m_condition_list.find(condition_id) ;
    if( it!= m_condition_list.end()) return &(it->second) ;
    return NULL ;
}

const LivenessAwardData* LivenessPrototypeManager::get_award(int award_id) const
{
    AwardContainer::const_iterator it = m_award_list.find(award_id) ;
    if( it!= m_award_list.end()) return &(it->second) ;
    return NULL ;
}



