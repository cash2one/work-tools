#include "daily_limit_count_prototype.h"
#include <fstream>
#include <assert.h>

int DailyLimitPrototype::InitCoolDownData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!cool_down_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<cool_down_data_group_.group_size(); ++i)
	{
		const DailyLimitCooldownData& d = cool_down_data_group_.group(i);
		cool_down_container_.insert(
			std::make_pair(std::make_pair(d.daily_limit_type(), d.current_count()),
					d.cool_down()));
	}

	return true;
}


int DailyLimitPrototype::InitCoolDownClearData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	DailyLimitCooldownClearDataGroup group;
	if (!group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<group.group_size(); ++i)
	{
		const DailyLimitCooldownClearData& d = group.group(i);
		cool_down_clear_container_.insert(
			std::make_pair(d.daily_limit_type(), d));
	}

	return true;
}


int DailyLimitPrototype::get_cool_down( int type, int count )
{
	CoolDownContainer::iterator it = cool_down_container_.find(std::make_pair(type, count));
	if (it != cool_down_container_.end())
	{
		return it->second;
	}
	else
	{
		if (count <= 0)
		{
			return 0;
		}
		return get_cool_down(type, count - 1);
	}
}

int DailyLimitPrototype::InitPurchaseData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!purchase_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<purchase_data_group_.group_size(); ++i)
	{
		const DailyLimitPurchaseData& d = purchase_data_group_.group(i);
		purchase_container_.insert(
			std::make_pair(std::make_pair(d.daily_limit_type(), d.purchase_count()),
					&d));
	}

	return true;
}

int DailyLimitPrototype::get_purchase_price( int type, int count, int* money_type )
{
	PurchaseContainer::iterator it = purchase_container_.find(std::make_pair(type, 0));
	if (it == purchase_container_.end())
	{
		it = purchase_container_.find(std::make_pair(type, count));
		if (it == purchase_container_.end())
		{
			if (money_type)
			{
				*money_type = 0;
			}
			return 0;
		}
	}

	const DailyLimitPurchaseData* data = it->second;
	if (money_type)
	{
		*money_type = data->money_type();
	}
	return data->price();

}

int DailyLimitPrototype::InitCountLimitData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!limit_count_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<limit_count_data_group_.group_size(); ++i)
	{
		const DailyLimitCountData& d = limit_count_data_group_.group(i);
		count_limit_container_.insert(
			std::make_pair(std::make_pair(d.daily_limit_type(), d.vip_level()),
			d));
	}

	return true;
}

const DailyLimitCountData* DailyLimitPrototype::GetLimitCountData( int type, int vip_level )
{
	CountLimitContainer::iterator it = count_limit_container_.find(std::make_pair(type, vip_level));
	if (it != count_limit_container_.end())
	{
		return &(it->second);
	}
	else
	{
		return NULL;
	}
}

int DailyLimitPrototype::get_clear_cool_down_price( int type, int cool_down_sec, int* money_type)
{
	const DailyLimitCooldownClearData* price_data;
	CoolDownClearContailer::iterator it = cool_down_clear_container_.find(type);
	if (it != cool_down_clear_container_.end())
	{
		price_data = &(it->second);
	}
	else
	{
		it = cool_down_clear_container_.find(0);
		//assert(it != cool_down_clear_container_.end());
		if (it == cool_down_clear_container_.end())
			return 0;
		price_data = &(it->second);
	}

	//assert(price_data);
	int unit_time = price_data->unit_time();
	int unit_price = price_data->unit_price();

	int price = (cool_down_sec + unit_time - 1) / unit_time * unit_price;
	if (money_type)
	{
		*money_type = price_data->money_type();
	}

	return price;
}
