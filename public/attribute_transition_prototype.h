#ifndef ATTRIBUTE_TRANSITION_PROTOTYPE_H
#define ATTRIBUTE_TRANSITION_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/player_attribute_transit_rate.pb.h"

class ProfessionAttributeTransition
{
public:
	bool Init(const char* data_file);
	const PlayerAttrTransition* GetAttributeTransition(int profession);

private:
	typedef std::map<int, const PlayerAttrTransition*> Prototypes;

	Prototypes prototypes_;
	PlayerAttrTransitGroup data_group_;

	DECLARE_SINGLETON_CONSTRUCTER(ProfessionAttributeTransition);
};

#define ATTR_INSTANCE Singleton<ProfessionAttributeTransition>::instance()

#endif //ATTRIBUTE_TRANSITION_PROTOTYPE_H
