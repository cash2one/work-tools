#include <assert.h>
#include <fstream>
#include "shop_prototype_mgr.h"
#include "../public/game_common.pb.h"

void ShopPrototypeManager::clear()
{
    m_prototype.clear() ;
    m_shop_data.Clear() ;
    m_market_data.Clear() ;
    m_fast_query_price.clear() ;
}
bool ShopPrototypeManager::load_shop( const char* data_file )
{
	//assert(prototypes_.size() == 0);
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		return false;
	}

	if (!m_shop_data.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<m_shop_data.shop_size(); ++i)
	{
		const ShopData& d = m_shop_data.shop(i);
		m_prototype.insert(std::make_pair(std::make_pair(d.shop_id(), d.item_id()), &d));
		if (d.sell_type() == ::protocols::common::MT_DIAMOND)
		{
			m_fast_query_price.insert(std::make_pair(d.item_id(), d.sell_value()));
		}
	}

	return true;
}


bool ShopPrototypeManager::load_market( const char* data_file )
{

	std::fstream  fs( data_file, std::ios::in | std::ios::binary );

	if (fs.fail())
	{
		return false;
	}

	if (!m_market_data.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i<m_market_data.shop_size(); ++i)
	{
		const ShopData& d = m_market_data.shop(i);
		m_prototype.insert(std::make_pair(std::make_pair(d.shop_id(), d.item_id()), &d));
		if (d.sell_type() == ::protocols::common::MT_DIAMOND)
		{
			m_fast_query_price.insert(std::make_pair(d.item_id(), d.sell_value()));
		}
	}

	return true;
}


const ShopData* ShopPrototypeManager::get_shop_item(int shop_id, int item_id)
{
	Prototypes::iterator it = m_prototype.find(std::make_pair(shop_id, item_id));
	if (it != m_prototype.end())
	{
		return it->second;
	}
	else
	{
		return 0;
	}
}
