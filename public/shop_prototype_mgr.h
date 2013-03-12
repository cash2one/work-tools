#ifndef SHOP_PROTO_MGR_H
#define SHOP_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/shop.pb.h"

class ShopPrototypeManager
{
public:
	bool load_shop(const char* data_file);
    bool load_market(const char* data_file) ;
	const ShopData* get_shop_item(int shop_id, int item_id);
	int get_diamond_price(int item_id)
	{
		FastQueryPrice::const_iterator it = m_fast_query_price.find(item_id);
		if (it!=m_fast_query_price.end())
			return it->second;
		else
			return 0;
	}
    void clear() ;
private:
	typedef std::map<std::pair<int,int>, const ShopData*> Prototypes;
	typedef std::map<int, int> FastQueryPrice;

	Prototypes m_prototype ;
	ShopDataGroup m_shop_data ;
    ShopDataGroup m_market_data ;
	FastQueryPrice m_fast_query_price;

	//DECLARE_SINGLETON_CONSTRUCTER(ShopPrototypeManager);
};

//#define YINGLING_INSTANCE Singleton<ShopPrototypeManager>::instance()



#endif //SHOP_PROTO_MGR_H
