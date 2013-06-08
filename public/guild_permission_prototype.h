#ifndef GUILD_PERMISSION_PROTOTYPE_H
#define GUILD_PERMISSION_PROTOTYPE_H

#include <map>
#include "../config/guild_permission.pb.h"

using namespace std;

class GuildPermissionPrototype
{
public:
    bool init(const char* data_file);
    void clear();
    const GuildPermissionData* get_guile_permission_config(int permission);
    bool has_guild_permission(int permission,int title);
private:  
    typedef std::map<int,const GuildPermissionData*> Prototypes;
    
    Prototypes prototypes_;
    GuildPermissionDataGroup data_group_;
};

#endif //GUILD_PERMISSION_PROTOTYPE_H
