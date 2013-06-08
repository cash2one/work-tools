#ifndef ITEM_GIFT_PROTO_MGR_H
#define ITEM_GIFT_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/item_gift.pb.h"



class ItemGiftPrototype
{
public:
    bool init(const char* data_file);
	void clear()
	{
		m_prototype.clear();
	}

    const ItemGiftData* get_item_gift(int gift_id) const;


private:
    typedef std::map<int,ItemGiftData> Prototypes;

    Prototypes m_prototype;


//    DECLARE_SINGLETON_CONSTRUCTER(ItemGiftPrototype);
};

//#define ITEM_GIFT_INSTANCE Singleton<ItemGiftPrototype>::instance()


#endif 

