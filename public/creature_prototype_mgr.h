#ifndef CREATURE_PROTOTYPE_MGR_H
#define CREATURE_PROTOTYPE_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/creature_init_data.pb.h"
#include "../config/monster_buff.pb.h"

class CreaturePrototypeMgr
{
public:
	bool Init(const char* data_file);
	bool InitMonsterBuff(const char* data_file);

	const CreatureInitData* GetCreaturePrototype(int creature_id);
	
	const MonsterBuffData*  GetMonsterBuff(int buff_id);

	void clear()
	{
		prototypes_.clear();
		buff_map.clear();

		data_group_.Clear();
		buff_data_group_.Clear();
	}
private:
	typedef std::map<int, const CreatureInitData*> Prototypes;
	typedef std::map<int, const MonsterBuffData*>  BuffMap;
	
	Prototypes prototypes_;
	CreatureInitDataGroup data_group_;

	BuffMap               buff_map;
	MonsterBuffDataGroup  buff_data_group_;
	
};

#endif //CREATURE_PROTOTYPE_MGR_H
