#ifndef DAILY_LIMIT_COUNT_PROTOTYPE_H
#define DAILY_LIMIT_COUNT_PROTOTYPE_H

#include <map>
#include "singleton.h"
#include "../config/daily_limit_count.pb.h"

class DailyLimitPrototype
{
	typedef std::map<std::pair<int,int>, int> CoolDownContainer;
	typedef std::map<int, const DailyLimitCooldownClearData> CoolDownClearContailer;
	typedef std::map<std::pair<int,int>, const DailyLimitPurchaseData*> PurchaseContainer;
	// std::pair<limit_type, vip_level>, const DailyLimitCountData>
	typedef std::map<std::pair<int,int>, const DailyLimitCountData> CountLimitContainer;
public:
	DailyLimitPrototype()
	{
	}
	int InitCoolDownData(const char* data_file);
	//int Init
	int get_cool_down(int type, int count);

	int InitCoolDownClearData(const char* data_file);

	int get_clear_cool_down_price(int type, int cool_down_sec, int* money_type);

	int InitPurchaseData(const char* data_file);

	int get_purchase_price(int type, int count, int* money_type);

	int InitCountLimitData(const char* data_file);

	const DailyLimitCountData* GetLimitCountData(int type, int vip_level);

private:
	DailyLimitCooldownDataGroup cool_down_data_group_;
	CoolDownContainer cool_down_container_;

	CoolDownClearContailer cool_down_clear_container_;

	DailyLimitPurchaseDataGroup purchase_data_group_;
	PurchaseContainer purchase_container_;

	DailyLimitCountDataGroup limit_count_data_group_;
	CountLimitContainer count_limit_container_;

	DECLARE_SINGLETON(DailyLimitPrototype);
};

#define DAILY_LIMIT_PROTOTYPE Singleton<DailyLimitPrototype>::instance()

#endif //DAILY_LIMIT_COUNT_PROTOTYPE_H
