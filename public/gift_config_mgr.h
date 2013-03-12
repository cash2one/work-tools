/*******************************************************************************
 *
 *      @file: gift_config_mgr.h
 *      @brief: ������Ʒ��������.
 *
 *      @author: gxl.
 *      @Date: 2012/09/14
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef GIFT_CONFIG_MANAGER_H
#define GIFT_CONFIG_MANAGER_H

#include <map>
#include "singleton.h"

#include "online_time_bonus.pb.h"

typedef std::map<int, int>  OnlineTimeBonusCfgMap;

class GiftConfigManager
{
public:
	~GiftConfigManager();

	bool InitTimeBonus(const char* data_file);

	// ��ȡ��ǰ�������id
	// @return : >=0 gift item id.
	//           < 0 no gift yet.
	int  get_gift_item_id(int acc_time, int already_take_max_time, int& cur_can_get_time_point);

	// ��ȡ�´ο������id
	// @return : >=0 gift item id.
	//           < 0 no gift yet.
	int  get_next_gift_item_id(int already_take_max_time);

	// ����´ο���ʱ��
	int  get_next_step_time(int already_take_max_time);
	OnlineTimeBonusCfgMap*  get_online_time_bonus_cfg();

	
private:
	OnlineTimeBonusDataGroup  m_online_time_bonus_group;

	OnlineTimeBonusCfgMap     m_online_time_bonus;

private:
	DECLARE_SINGLETON_CONSTRUCTER(GiftConfigManager);
};


#define TIME_BONUS_CONFIG_INSTANCE Singleton<GiftConfigManager>::instance()




#endif


