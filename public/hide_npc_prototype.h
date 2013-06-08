#ifndef HIDE_NPC_PROTOTYPE_H
#define HIDE_NPC_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/hide_npc.pb.h"
#include "../public/game_common.pb.h"

class HideNpcPrototype
{
	typedef std::map<std::pair<int,int>, std::vector<QuestHideNpcData> > QuestHidePrototype;
	typedef std::map<int, std::vector<protocols::common::NpcPosition> > RandomPositionPrototype;
public:
	int InitDefaultHide(const char* data_file);
	int InitQuestHide(const char* data_file);
	int InitRandomPosition(const char* data_file);

	const protocols::common::HideNpcPb& GetDefaultHideNpc() const 
	{
		return default_hide_npc_;
	}
	void GetDefaultHideNpc(protocols::common::HideNpcPb* pb) const
	{
		pb->CopyFrom(default_hide_npc_);
	}

	const std::vector<QuestHideNpcData>* GetQuestHideNpcData(int quest_id, int quest_status)
	{
		QuestHidePrototype::iterator it = quest_hide_prototypes_.find(std::make_pair(quest_id, quest_status));
		if (it != quest_hide_prototypes_.end())
			return & it->second;
		else
			return NULL;
	}
	const protocols::common::NpcPosition* RandomPosition(int pos_cate_id);

private:
	protocols::common::HideNpcPb default_hide_npc_;

	QuestHidePrototype quest_hide_prototypes_;

	RandomPositionPrototype random_positions_;

	DECLARE_SINGLETON_CONSTRUCTER(HideNpcPrototype);
};

#define HIDE_NPC_MGR Singleton<HideNpcPrototype>::instance()

#endif //HIDE_NPC_PROTOTYPE_H
