#ifndef GUILD_UPGRADE_PROTO_MGR_H
#define GUILD_UPGRADE_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/guild_upgrade.pb.h"



class GuildUpgradePrototype
{
public:
    bool init(const char* data_file);
	void clear()
	{
		m_prototype.clear();
	}

    const GuildUpgradeData* get_upgrade(int upgrade_type,int grade) const;


private:
    typedef std::map<int64_t,GuildUpgradeData> Prototypes;

    Prototypes m_prototype;


//    DECLARE_SINGLETON_CONSTRUCTER(GuildUpgradePrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<GuildUpgradePrototype>::instance()


#endif 

