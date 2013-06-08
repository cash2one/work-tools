#ifndef ITEM_VIP_PROTO_MGR_H
#define ITEM_VIP_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/item_vip.pb.h"



class ItemVipPrototype
{
public:
    bool init(const char* data_file);

    bool init_limit_count(const char* data_file);

	void clear()
	{
		m_prototype.clear();
		m_limit_count_prototype.clear();
	}

    const ItemVipData* get_item(int item_tid) const;

    const ItemLimitCountData* get_limit_count_item(int item_tid) const;


private:
    typedef std::map<int,ItemVipData> Prototypes;
    typedef std::map<int,ItemLimitCountData> LimitCountPrototypes;

    Prototypes m_prototype;
    LimitCountPrototypes m_limit_count_prototype;


//    DECLARE_SINGLETON_CONSTRUCTER(ItemVipPrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<ItemVipPrototype>::instance()


#endif

