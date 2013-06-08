#ifndef GUILD_CONFIG_PROTO_MGR_H
#define GUILD_CONFIG_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/guild_config.pb.h"



class GuildConfigPrototype
{
public:
    bool init(const char* data_file);
	void clear()
	{
		m_prototype.clear();
	}

    const GuildConfigData* get_config(int grade) const;


private:
    typedef std::map<int,GuildConfigData> Prototypes;

    Prototypes m_prototype;


//    DECLARE_SINGLETON_CONSTRUCTER(GuildUpgradePrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<GuildUpgradePrototype>::instance()


#endif 

