#ifndef LIVENESS_PROTO_MGR_H
#define LIVENESS_PROTO_MGR_H

#include <map>

#include "../config/liveness_condition.pb.h"
#include "../config/liveness_award.pb.h"

class LivenessPrototypeManager
{
public:
    bool load_condition(const char* data_file);
    bool load_award(const char* data_file);
    void clear() ;
	const LivenessConditionData* get_condition(int condition_id) const;
    const LivenessAwardData* get_award(int award_id) const;
	

private:
    typedef std::map<int,LivenessConditionData> ConditionContainer;
    typedef std::map<int,LivenessAwardData> AwardContainer;

    ConditionContainer m_condition_list ;
    AwardContainer m_award_list ;

};




#endif 

