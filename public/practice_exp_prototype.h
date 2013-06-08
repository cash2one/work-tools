/*
 * practice_exp_prototype.h
 *
 *  Created on: 2013-5-23
 *  Author: weitq
 */

#ifndef PRACTICE_EXP_PROTOTYPE_H
#define PRACTICE_EXP_PROTOTYPE_H

#include <map>
#include "practice_exp.pb.h"

class PracticeExpProtoManager
{
public:
	PracticeExpProtoManager();
	~PracticeExpProtoManager();
	void clear();
	bool init(const char* data_file);
	int get_exp(int role_level, int vip_level);

private:
	typedef std::map<int, PracticeExpData> PracticeExpMap;
	PracticeExpMap m_practice_exp_map;
};

#endif /* PRACTICE_EXP_PROTOTYPE_H */
