/*
 * vip_gift_prototype.h
 *
 *  Created on: 2013-3-28
 *  Author: weitq
 */

#ifndef VIP_GIFT_PROTOTYPE_H
#define VIP_GIFT_PROTOTYPE_H

#include <map>
#include "vip_gift.pb.h"

class VipGiftProtoManager
{
public:
	VipGiftProtoManager();
	~VipGiftProtoManager();
	void clear();
	bool init(const char* data_file);
	const VipGiftData* get_vip_gift_by_level(int vip_lv);
	const VipGiftData* get_vip_gift_by_flag(int flag);

private:
	typedef std::map<int, VipGiftData> VipGiftMap;
	VipGiftMap m_vip_gift_map;
	VipGiftMap m_flag_gift_map;
};

#endif /* VIP_GIFT_PROTOTYPE_H */
