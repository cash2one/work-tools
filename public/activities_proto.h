#ifndef ACTIVITIES_PROTO_H
#define ACTIVITIES_PROTO_H

#include <map>
#include "singleton.h"
#include "../config/activities.pb.h"


namespace protocols { namespace common {class StartupActivityStatusNotify;};};
class ActivityPrototype
{
	typedef std::map<int, const ActivityData*> Prototypes;
	typedef std::map<std::pair<int, int>, int> HireYinglingActitityData;
	typedef std::map<std::pair<int, int>, int> StrengthEquipActitityData;
	typedef std::map<int, std::pair<int, int> > ActivitiesDurationData;
public:
	int Init(const char* data_file);
	int InitTimeLimit(const char* data_file);
	int AddTimeLimit(int activity_type, int start_sec, int end_sec);
    int ResetStartupTimeLimit(int start_sec, int end_sec);

	bool IsActivityEnd(int activity_type) const;

	void WriteActivityTimeLimit(protocols::common::StartupActivityStatusNotify* msg);

	void clear()
	{
		prototypes_.clear();
		data_group_.Clear();
		yingling_data_.clear();
		strength_equip_data_.clear();
	}
	int GetHireYinglingActivityFlag(int yingling_quality, int num) const;

	int GetStrengthEquipActivityFlag(int strength_level, int count) const;

private:
	Prototypes prototypes_;
	ActivityDataGroup data_group_;
	HireYinglingActitityData yingling_data_;
	StrengthEquipActitityData strength_equip_data_;

	ActivitiesDurationData activities_duration_data_;

};



#endif //ACTIVITIES_PROTO_H
