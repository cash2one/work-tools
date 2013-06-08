#include "activities_proto.h"
#include "../public/str_util.h"
#include "../public/game_client.pb.h"
#include <fstream>
#include <assert.h>
#include <time.h>

int ActivityPrototype::Init(const char* data_file)
{
	std::fstream fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group_.data_size(); ++i)
	{
		const ActivityData& d = data_group_.data(i);
		switch(d.activity_type())
		{
		case 1:
			yingling_data_.insert(std::make_pair(std::make_pair(d.param1(), d.param2()), d.flag_type()));
			break;
		case 2:
			strength_equip_data_.insert(std::make_pair(std::make_pair(d.param1(), d.param2()), d.flag_type()));
			break;
		default:
			return false;
		}
	}

	return true;
}

int ActivityPrototype::InitTimeLimit( const char* data_file )
{
	std::fstream fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}
	ActivityTimeLimitDataGroup data_group;
	if (!data_group.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<data_group.data_size(); ++i)
	{
		const ActivityTimeLimitData& d = data_group.data(i);
		int activity_type = d.activity_type();
		int start_sec = convert_string_to_time_t(d.start_time());
		int end_sec = convert_string_to_time_t(d.end_time());

		AddTimeLimit(activity_type, start_sec, end_sec);
	}

	return true;
}

int ActivityPrototype::AddTimeLimit( int activity_type, int start_sec, int end_sec )
{
	activities_duration_data_.insert(std::make_pair(activity_type, std::make_pair(start_sec, end_sec)));
	return 0;
}

int ActivityPrototype::ResetStartupTimeLimit(int start_sec, int end_sec)
{
    for (int i=1; i<=5; ++i)
    {
        ActivitiesDurationData::iterator it = activities_duration_data_.find(i);
        if (it != activities_duration_data_.end())
        {
            it->second.first = start_sec;
            it->second.second = end_sec;
        }
        else
        {
            activities_duration_data_.insert(std::make_pair(i, std::make_pair(start_sec, end_sec)));
        }
    }
    return 0;
}

bool ActivityPrototype::IsActivityEnd( int activity_type ) const
{
	ActivitiesDurationData::const_iterator it = activities_duration_data_.find(activity_type);
	if (it != activities_duration_data_.end())
	{
	    int current_sec = time(NULL);
		return it->second.second <= current_sec || it->second.first >= current_sec;
	}
	else
	{
		// no limit
		return false;
	}
}

void ActivityPrototype::WriteActivityTimeLimit( protocols::common::StartupActivityStatusNotify* msg )
{
	ActivitiesDurationData::iterator it;
	for (it=activities_duration_data_.begin(); it!=activities_duration_data_.end(); ++it)
	{
		protocols::common::StartupActivityStatus* status = msg->add_status();
		status->set_activity_type(it->first);
		status->set_start_sec(it->second.first);
		status->set_end_sec(it->second.second);
	}
}

int ActivityPrototype::GetHireYinglingActivityFlag( int yingling_quality, int num ) const
{
	HireYinglingActitityData::const_iterator it = yingling_data_.find(std::make_pair(yingling_quality, num));
	if (it != yingling_data_.end())
		return it->second;
	else
		return 0;
}

int ActivityPrototype::GetStrengthEquipActivityFlag( int strength_level, int count ) const
{
	StrengthEquipActitityData::const_iterator it = strength_equip_data_.find(std::make_pair(strength_level, count));
	if (it != strength_equip_data_.end())
		return it->second;
	else
		return 0;
}
