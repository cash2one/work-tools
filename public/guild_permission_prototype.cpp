
#include <fstream>
#include "guild_permission_prototype.h"
#include "game_guild.pb.h"

using namespace std;

bool GuildPermissionPrototype::init(const char* data_file)
{
    fstream fs( data_file,ios::in | ios::binary);
    if(fs.fail()) return false;
    if(!data_group_.ParseFromIstream(&fs))  return false;
    for(int i=0;i< data_group_.guild_permission_size();i++)
    {
        const GuildPermissionData &d = data_group_.guild_permission(i);
        prototypes_.insert(make_pair(d.permission(),&d));
    }   
    return true ;
}
void GuildPermissionPrototype::clear()
{
    prototypes_.clear();
    data_group_.Clear();
}
const GuildPermissionData* GuildPermissionPrototype::get_guile_permission_config(int permission)
{
    Prototypes::iterator it = prototypes_.find(permission);
    if(it != prototypes_.end()) return it->second;
    else return 0;
}
bool GuildPermissionPrototype::has_guild_permission(int permission,int title)
{
    Prototypes::iterator it = prototypes_.find(permission);
    if(it == prototypes_.end() ) return false ;
    switch(title)
    {
    case protocols::common::MEMBER_TITLE_LEADER:
        return it->second->leader() >0 ? true : false ;
    case protocols::common::MEMBER_TITLE_VICE_LEADER:
        return it->second->vice_leader() >0 ? true : false ;
    case protocols::common::MEMBER_TITLE_ELDER:        
        return it->second->elder() >0 ? true : false ;    
    case protocols::common::MEMBER_TITLE_ELITE:        
        return it->second->elite() >0 ? true : false ;    
    case protocols::common::MEMBER_TITLE_NORMAL:        
        return it->second->normal() >0 ? true : false ;    
    default:        
        ;
    }    
    return false;
}


