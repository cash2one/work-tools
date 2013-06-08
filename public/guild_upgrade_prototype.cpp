#include <assert.h>
#include <fstream>
#include "guild_upgrade_prototype.h"


bool GuildUpgradePrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    GuildUpgradeDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.upgrade_size(); ++i)
    {
        const GuildUpgradeData& d = data_group_.upgrade(i);
        m_prototype[(int64_t)d.upgrade_type() << 32 |  d.grade()] = d ;
        
    }

    return true;
}


const GuildUpgradeData* GuildUpgradePrototype::get_upgrade(int upgrade_type,int grade) const
{
    int64_t key = (int64_t)upgrade_type << 32 | grade ;
    Prototypes::const_iterator it = m_prototype.find(key );
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}

