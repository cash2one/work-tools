#ifndef GIFT_PROTOTYPE_H
#define GIFT_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/gift.pb.h"


class GiftPrototype
{
public:
	bool init(const char* data_file);
	bool init_daily_gift(const char* data_file);
	bool init_stackable_online_gift(const char* data_file);

	const std::vector<GiftPackData>* get_gift_pack(int pack_id) const
	{
		Prototypes::const_iterator it = prototypes_.find(pack_id);
		if (it != prototypes_.end())
			return &it->second;
		else
			return NULL;
	}

	int get_daily_gift_pack_id(int vip_level) const
	{
		DailyGiftPrototypes::const_iterator it = daily_gift_prototypes_.find(vip_level);
		if (it != daily_gift_prototypes_.end())
		{
			return it->second;
		}
		return 0;
	}

	int get_first_reward_pack_id(int vip_level) const
	{
		VipFirstRewardPrototypes::const_iterator it = vip_first_reward_prototypes_.find(vip_level);
		if (it != vip_first_reward_prototypes_.end())
		{
			return it->second;
		}
		return 0;
	}

	int get_stackable_online_gift_pack_id(int online_day_num) const
	{
		StackableOnlineGiftPrototypes::const_iterator it = stackable_online_gift_prototypes_.find(online_day_num);
		if (it != stackable_online_gift_prototypes_.end())
		{
			return it->second;
		}
		else
		{
			// 没有找到，就取0为默认
			if (online_day_num == 0)
			{
				return 0;
			}
			return get_stackable_online_gift_pack_id(0);
		}
		
	}
private:
	typedef std::map<int, std::vector<GiftPackData> > Prototypes;
	typedef std::map<int, int> DailyGiftPrototypes;
	typedef std::map<int, int> StackableOnlineGiftPrototypes;
	typedef std::map<int, int> VipFirstRewardPrototypes;
	
	Prototypes prototypes_;
	DailyGiftPrototypes daily_gift_prototypes_;
	VipFirstRewardPrototypes vip_first_reward_prototypes_;
	StackableOnlineGiftPrototypes stackable_online_gift_prototypes_;

	DECLARE_SINGLETON_CONSTRUCTER(GiftPrototype);
};

#define GIFT_PROTO Singleton<GiftPrototype>::instance()

#endif

