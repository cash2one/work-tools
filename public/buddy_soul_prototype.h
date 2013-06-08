#ifndef BUDDY_SOUL_PROTOTYPE_H
#define BUDDY_SOUL_PROTOTYPE_H

#include <map>
#include "singleton.h"
#include "../config/soul_injection.pb.h"
#include "../config/spacetime_battle.pb.h"

class BuddySoulPrototype
{
	typedef std::map<int, const InjectSoulData*> Prototypes;
	typedef std::map< std::pair<int,int>, const SpaceTimeBattleData* > SpaceTimeBattlePrototypes;

	enum 
	{
		soul_stone_id = 80301,
		soul_protect_item_id = 80401,
	};
public:
	int Init(const char* data_file);
	int InitSpaceTimeBattlePrototypes(const char* data_file);

	const InjectSoulData* GetInjectSoulData(int quality_num) const;

	const SpaceTimeBattleData* GetSpaceTimeBattleId(int buddy_id, int spacetime_level) const;

	int SoulStoneId()
	{
		return soul_stone_id;
	}
	int SoulProtectItemId()
	{
		return soul_protect_item_id;
	}
	void clear()
	{
		prototypes_.clear();
		data_group_.Clear();
		battle_prototypes_.clear();
		spacetime_battle_data_group_.Clear();
	}
private:
	Prototypes prototypes_;
	InjectSoulDataGroup data_group_;

	SpaceTimeBattlePrototypes battle_prototypes_;
	SpaceTimeBattleDataGroup spacetime_battle_data_group_;

//	DECLARE_SINGLETON_CONSTRUCTER(BuddySoulPrototype);
};

//#define BUDDY_SOUL_PROTOTYPE Singleton<BuddySoulPrototype>::instance()

#endif //BUDDY_SOUL_PROTOTYPE_H
