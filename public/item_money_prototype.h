#ifndef ITEM_MONEY_PROTO_MGR_H
#define ITEM_MONEY_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/item_money.pb.h"



class ItemMoneyPrototype
{
public:
    bool init(const char* data_file);
	void clear()
	{
		m_prototype.clear();
	}

    const ItemMoneyData* get_item(int item_tid) const;


private:
    typedef std::map<int,ItemMoneyData> Prototypes;

    Prototypes m_prototype;


//    DECLARE_SINGLETON_CONSTRUCTER(ItemMoneyPrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<ItemMoneyPrototype>::instance()


#endif 

