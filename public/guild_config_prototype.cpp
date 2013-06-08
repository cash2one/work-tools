#include <assert.h>
#include <fstream>
#include "guild_config_prototype.h"


bool GuildConfigPrototype::init( const char* data_file )
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false ;

    GuildConfigDataGroup data_group_;

    if (!data_group_.ParseFromIstream(&fs))
    {
        return false;
    }

    for (int i=0; i<data_group_.config_size(); ++i)
    {
        const GuildConfigData& d = data_group_.config(i);
        m_prototype[ d.grade()] = d ;
        
    }

    return true;
}


const GuildConfigData* GuildConfigPrototype::get_config(int grade) const
{
    
    Prototypes::const_iterator it = m_prototype.find(grade );
    if (it != m_prototype.end()) return &(it->second);
    return NULL ;
}

