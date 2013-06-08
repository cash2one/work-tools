#ifndef GUILD_DONATE_PROTO_H
#define GUILD_DONATE_PROTO_H

#include <map>
#include "singleton.h"
#include "../config/guild_donate.pb.h"

class GuildDonatePrototype
{
	typedef std::map<int, const GuildDonateRateData*> Prototypes;
public:
	int Init(const char* data_file);

	const GuildDonateRateData* GetGuildDonateRateData(int money_type) const;

	void clear()
	{
		prototypes_.clear();
		data_group_.Clear();
	}
private:
	Prototypes prototypes_;
	GuildDonateRateDataGroup data_group_;

	//	DECLARE_SINGLETON_CONSTRUCTER(BuddySoulPrototype);
};



#endif // GUILD_DONATE_PROTO_H
