/*
 * buy_clear_cd_cost_prototype.h
 *
 *  Created on: 2013-4-9
 *  Author: weitq
 */

#ifndef BUY_CLEAR_CD_COST_PROTOTYPE_H
#define BUY_CLEAR_CD_COST_PROTOTYPE_H

#include <map>
#include "buy_clear_cd_cost.pb.h"

class BuyClearCdCostProtoManager
{
public:
	BuyClearCdCostProtoManager();
	~BuyClearCdCostProtoManager();
	void clear();
	bool init(const char* data_file);
	const BuyClearCDCostData* get_cost_by_type(int type);

private:
	typedef std::map<int, BuyClearCDCostData> BuyClearCdCostMap;
	BuyClearCdCostMap m_clear_cd_cost_map;
};

#endif /* BUY_CLEAR_CD_COST_PROTOTYPE_H */
