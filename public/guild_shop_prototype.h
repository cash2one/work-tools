#ifndef GUILD_SHOP_PROTO_MGR_H
#define GUILD_SHOP_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/guild_shop.pb.h"



class GuildShopPrototype
{
public:
    bool init(const char* data_file);
	void clear()
	{
		m_prototype.clear();
	}

    const GuildShopData* get_shop_item(int item_tid) const;


private:
    typedef std::map<int64_t,GuildShopData> Prototypes;

    Prototypes m_prototype;


//    DECLARE_SINGLETON_CONSTRUCTER(GuildShopPrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<GuildShopPrototype>::instance()


#endif 

