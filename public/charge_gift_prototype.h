/*
 * charge_gift_prototype.h
 *
 *  Created on: 2013-3-29
 *  Author: weitq
 */

#ifndef CHARGE_GIFT_PROTOTYPE_H
#define CHARGE_GIFT_PROTOTYPE_H

#include <map>
#include <vector>
#include "charge_gift.pb.h"

class ChargeGiftProtoManager
{
public:
	ChargeGiftProtoManager();
	~ChargeGiftProtoManager();
	void clear();
	bool init(const char* data_file);
	const ChargeGiftData* get_charge_gift_by_value(int charge_value);
	const ChargeGiftData* get_charge_gift_by_flag(int flag);

private:
	typedef std::map<int, ChargeGiftData> ChargeGiftMap;
	ChargeGiftMap m_charge_gift_map;
	ChargeGiftMap m_flag_gift_map;
    std::vector<int> m_charge_step ;
};

#endif /* CHARGE_GIFT_PROTOTYPE_H */
