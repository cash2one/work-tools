/*******************************************************************************
 *
 *      @file: const_strings.cpp
 *      @brief: convert between enum and strings
 *
 *      @author: gxl.
 *      @Date: 2012/10/10
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include "message.h"

using namespace protocols::common;

// ������־��Դ���ͻ����Դ����
const char*  get_log_src_name(int src_type)
{
	switch (src_type)
	{
	case SRC_GATE_SERVER:
		return "GATE";

	case SRC_ZONE_SERVER:
		return "ZONE";

	case SRC_LOGIC_SERVER:
		return "LOGIC";

	default:
		return "UNKNOWN SOURCE TYPE";
		break;
	}

	return "";
}

const char*  get_log_action_name(int act_type)
{
	switch (act_type)
	{
	case LOG_ACTION_LOGON: // ��½
		return "LOGON";

	case LOG_ACTION_LOGOFF: // ����
		return "LOGOFF";

	case LOG_ACTION_BUY: // ������Ϊ (������ߡ����ѹ���(�����������ȴʱ���))
		return "BUY";

	case LOG_ACTION_SELL: // �۳���Ϊ (�����ֵ��߿���)
		return "SELL";

	case LOG_ACTION_ADD_PROPS: // ��õ��� (ͨ�����򡢸��ֽ����������)
		return "ADD_PROPS";

	case LOG_ACTION_SUB_PROPS: // ���ĵ��� (ʹ�á��۳������׵�)
		return "SUB_PROPS";

	case LOG_ACTION_ADD_MONEY: // �������� (��ֵ����Ϸ�������۳�����)
		return "ADD_MONEY";

	case LOG_ACTION_SUB_MONEY: // ���Ҽ��� (������ߺ͸��ѹ���)
		return "SUB_MONEY";

	case LOG_ACTION_CREATE_ROLE: // ������ɫ
		return "CREATE ROLE";

	case LOG_ACTION_INVENTORY_INFO: // ������Ϣ (ÿ���״ε�½����)'
		return "INVENTORY INFO";

	case LOG_ACTION_SERVER_DATA: // ������������ (��Ӧ��˾ ser)
		return "SERVER DATA";

	case LOG_ACTION_ATTR:
		return "ATTR";   // ���Ա仯 (�ݶ��ȼ��仯)

	case LOG_ACTION_GUIDE: // ��������
		return "GUIDE";

	case LOG_ACTION_TRANSACTION: // �����¼�
		return "TRANSACTION";

	case LOG_ACTION_EQUIP_STAT: // װ��ͳ�� (ÿ������ʱ��һ��)
		return "EQUIP STAT";

	default:
		return "unknown action";
		break;
	}

	return "";
}


const char* get_money_type_info(int money_type)
{
	switch(money_type)
	{
	case MT_COIN :
		return "GOLD_COIN" ;

	case MT_COUPON:
		return "COUPON" ;

	case MT_DIAMOND:
		return "DIAMOND" ;
	}

	return "";
}

const char* get_money_change_type_info(int action_type)
{
	switch (action_type)
	{
	case ADD_MONEY_BY_PAY: // ��ֵ
		return "game_pay"; // ��Ϸ�ڲ��ĳ�ֵ
	case ADD_MONEY_BY_TASK: // ������
		return "task";
	case ADD_MONEY_BY_CC:   // �ͷ��ӿ�
		return "cc";
	case ADD_MONEY_BY_INSTALL: // �°�װ����
		return "install";
	case ADD_MONEY_BY_GM:   // ��̨GM
		return "gm";
	case ADD_MONEY_BY_SELL: // ����
		return "sell";
	case ADD_MONEY_BY_BONUS: // ��Ϸ�еĽ���
		return "free";
	case ADD_MONEY_BY_OTHERS:// ����;��
		return "other";
	case BUY_PROPS: // ���򸶷ѵ���
		return "buy_props";

	case BUY_OPEN_YINGLING_SLOT: return "open yingling slot" ; // Ӣ���ӵ�и�������
	case BUY_OPEN_BAG_SLOT: return "open bag slot" ;  // �������ӹ���
	case BUY_PHY_STRENGTH_1: return "buy phy strength 1" ; // ����ֵ����1��
	case BUY_PHY_STRENGTH_2: return "buy phy strength 2" ; // ����ֵ����2��
	case BUY_PHY_STRENGTH_3: return "buy phy strength 3" ; // ����ֵ����3��
	case BUY_PHY_STRENGTH_4: return "buy phy strength 4" ; // ����ֵ����4��
	case BUY_PHY_STRENGTH_5: return "buy phy strength 5" ; // ����ֵ����5��

	case BUY_VIP_1: return "vip 1" ;  // ����VIP 1
	case BUY_VIP_2: return "vip 2" ;  // ����VIP 2
	case BUY_VIP_3: return "vip 3" ;  // ����VIP 3
	case BUY_VIP_4: return "vip 4" ;  // ����VIP 4
	case BUY_VIP_5: return "vip 5" ;  // ����VIP 5
	case BUY_VIP_6: return "vip 6" ;  // ����VIP 6


	case BUY_ROLE_SOUL_STONE: return "role soul stone" ; // ��ɫ ���ʯ
	case BUY_ROLE_SOUL_FEATHER: return "role soul feather" ;  // ��ɫ ��ë
	case BUY_YINGLING_SOUL_STONE: return "yingling soul stone" ;  // Ӣ�� ���ʯ
	case BUY_YINGLING_SOUL_FEATHER: return "yingling soul feather" ;  // Ӣ�� ��ë
	case BUY_INJECT_ROLE_SOUL: return "role soul inject" ;  // ��ɫ���ע��
	case BUY_INJECT_YINGLING_SOUL: return "yingling soul inject" ;  // Ӣ�����ע��
	case BUY_SPACE_CHALLENGE_CD: return "space challenge cd" ;  // λ����ս����

	case BUY_SKILL_PRACTICE: return "skill practice" ;  // ��������
	case BUY_SKILL_PRACTICE_SPEED_UP: return "skill speed up" ;  // ������������

	case BUY_EQUIP_STRENGTH: return "equip strength" ;  // װ������
	case BUY_EQUIP_XILIAN: return "equip xilian" ;  // װ��ϴ��
	case BUY_EQUIP_XILIAN_LOCK: return "equip xilian lock" ; // װ��ϴ������
	case BUY_EQUIP_INHERIT: return "equip inherit" ;  // װ���̳�
	case BUY_EQUIP_SOCKET: return "equip socket" ;  // װ�����
	case BUY_EQUIP_STONE_INSERT: return "equip stone insert" ;  // ��ʯ��Ƕ
	case BUY_EQUIP_STONE_REMOVE: return "equip stone remove" ;  // ��ʯ�Ƴ�

	case BUY_EQUIP_STONE_GEM: return "equip stone gem" ;  // ��ʯ�ϳ�

	case BUY_OPEN_HIRE_PLACE: return "open hire place" ;   // ������ļλ����
	case BUY_REFRESH_YINGLING_HIRING_LIST: return "refresh yingling hiring list" ;  // ˢ��Ӣ����ļ�б�
	case BUY_HIRE_YINGLING: return "hire yingling" ;  // ����Ӣ�� 

	case BUY_INSTANCE_WANTED_ALL_RESET_1:  // ��1������
	case BUY_INSTANCE_WANTED_ALL_RESET_2: // ��2������
	case BUY_INSTANCE_WANTED_ALL_RESET_3: // ��3������
	case BUY_INSTANCE_WANTED_ALL_RESET_4: // ��4������
	case BUY_INSTANCE_WANTED_ALL_RESET_5: // ��5������
	case BUY_INSTANCE_WANTED_ALL_RESET_6: // ��6������
	case BUY_INSTANCE_WANTED_ALL_RESET_7: // ��7������
	case BUY_INSTANCE_WANTED_ALL_RESET_8: // ��8������
	case BUY_INSTANCE_WANTED_ALL_RESET_9: // ��9������
	case BUY_INSTANCE_WANTED_ALL_RESET_10: // ��10������
	case BUY_INSTANCE_WANTED_ALL_RESET_11: // ��11������
	case BUY_INSTANCE_WANTED_ALL_RESET_12: // ��12������
	case BUY_INSTANCE_WANTED_ALL_RESET_13: // ��13������
	case BUY_INSTANCE_WANTED_ALL_RESET_14: // ��14������
	case BUY_INSTANCE_WANTED_ALL_RESET_15: // ��15������
	case BUY_INSTANCE_WANTED_ALL_RESET_16: // ��16������
	case BUY_INSTANCE_WANTED_ALL_RESET_17: // ��17������
	case BUY_INSTANCE_WANTED_ALL_RESET_18: // ��18������
	case BUY_INSTANCE_WANTED_ALL_RESET_19: // ��19������
	case BUY_INSTANCE_WANTED_ALL_RESET_20: // ��20������

	case BUY_INSTANCE_WANTED_ALL_RESET_21:  // ��21������
	case BUY_INSTANCE_WANTED_ALL_RESET_22:  // ��22������
	case BUY_INSTANCE_WANTED_ALL_RESET_23:  // ��23������
	case BUY_INSTANCE_WANTED_ALL_RESET_24:  // ��24������
	case BUY_INSTANCE_WANTED_ALL_RESET_25:  // ��25������
	case BUY_INSTANCE_WANTED_ALL_RESET_26:  // ��26������
	case BUY_INSTANCE_WANTED_ALL_RESET_27:  // ��27������
	case BUY_INSTANCE_WANTED_ALL_RESET_28:  // ��28������
	case BUY_INSTANCE_WANTED_ALL_RESET_29:  // ��29������
	case BUY_INSTANCE_WANTED_ALL_RESET_30:  // ��30������
	case BUY_INSTANCE_WANTED_ALL_RESET_31:  // ��31������
	case BUY_INSTANCE_WANTED_ALL_RESET_32:  // ��32������
	case BUY_INSTANCE_WANTED_ALL_RESET_33:  // ��33������
	case BUY_INSTANCE_WANTED_ALL_RESET_34:  // ��34������
	case BUY_INSTANCE_WANTED_ALL_RESET_35:  // ��35������
	case BUY_INSTANCE_WANTED_ALL_RESET_36:  // ��36������
	case BUY_INSTANCE_WANTED_ALL_RESET_37:  // ��37������
	case BUY_INSTANCE_WANTED_ALL_RESET_38:  // ��38������
	case BUY_INSTANCE_WANTED_ALL_RESET_39:  // ��39������
	case BUY_INSTANCE_WANTED_ALL_RESET_40: return "instance wanted reset" ;  // ��40������

	case BUY_ARENA_CHALLENGE_TIMES_1:  // ����������1������ս����
	case BUY_ARENA_CHALLENGE_TIMES_2:  // ����������2������ս����
	case BUY_ARENA_CHALLENGE_TIMES_3:  // ����������3������ս����
	case BUY_ARENA_CHALLENGE_TIMES_4:  // ����������4������ս����
	case BUY_ARENA_CHALLENGE_TIMES_5:  // ����������5������ս����
	case BUY_ARENA_CHALLENGE_TIMES_6:  // ����������6������ս����
	case BUY_ARENA_CHALLENGE_TIMES_7:  // ����������7������ս����
	case BUY_ARENA_CHALLENGE_TIMES_8:  // ����������8������ս����
	case BUY_ARENA_CHALLENGE_TIMES_9:  // ����������9������ս����
	case BUY_ARENA_CHALLENGE_TIMES_10:  // ����������10������ս����
	case BUY_ARENA_CHALLENGE_TIMES_11:  // ����������11������ս����
	case BUY_ARENA_CHALLENGE_TIMES_12:  // ����������12������ս����
	case BUY_ARENA_CHALLENGE_TIMES_13:  // ����������13������ս����
	case BUY_ARENA_CHALLENGE_TIMES_14:  // ����������14������ս����
	case BUY_ARENA_CHALLENGE_TIMES_15:  return "buy arena challenge time" ; // ����������15������ս����

	case BUY_ARENA_REFRESH_CD: return "arena refresh cd" ;  // ������CD����
	case BUY_REFRESH_CD: return "other refresh cd" ;  // ˢ��CD ��ʱ�� ��Ҫ������չ

	case BUY_FAST_AUTO_FIGHT: return "fast auto fight" ; // �һ�����


	case BUY_REFRESH_REWARD_TASK: return "refresh reward task" ;  // ˢ����������
	case BUY_FAST_REWRAD_TASK: return "reward task finish" ;  // ���������������
	case BUY_REWARD_TASK_1:  // ����1����������
	case BUY_REWARD_TASK_2: // ����2����������
	case BUY_REWARD_TASK_3: // ����3����������
	case BUY_REWARD_TASK_4:// ����4����������
	case BUY_REWARD_TASK_5: // ����5����������
	case BUY_REWARD_TASK_6: // ����6����������
	case BUY_REWARD_TASK_7: // ����7����������
	case BUY_REWARD_TASK_8: // ����8����������
	case BUY_REWARD_TASK_9: // ����9����������
	case BUY_REWARD_TASK_10: // ����10����������
	case BUY_REWARD_TASK_11: // ����11����������
	case BUY_REWARD_TASK_12: // ����12����������
	case BUY_REWARD_TASK_13: // ����13����������
	case BUY_REWARD_TASK_14: // ����14����������
	case BUY_REWARD_TASK_15: return "buy reward task" ; // ����15����������

	case BUY_YOULI_RESET_MAP: return "youli reset map" ;  // ���õ�ͼ
	case BUY_YOULI_DICE: return "youli dice" ; // ң��ɫ��
	case BUY_YOULI_1:   // ����1����������
	case BUY_YOULI_2:  // ����2����������
	case BUY_YOULI_3:  // ����3����������
	case BUY_YOULI_4:  // ����4����������
	case BUY_YOULI_5:  // ����5����������
	case BUY_YOULI_6:  // ����6����������
	case BUY_YOULI_7:  // ����7����������
	case BUY_YOULI_8:  // ����8����������
	case BUY_YOULI_9:  // ����9����������
	case BUY_YOULI_10: return "buy youli time" ; // ����10����������

	case BUY_SKIP_FIGHT: return "skip fight" ;  // ����ս��
	case BUY_QUICK_RESPAWN: return "quick respawn" ;  // ������ٸ���
	case BUY_ENCOURAGE_BUFF: return "encourage buff" ;  // ����boss����buff
	 
	case BUY_GUILD_DONATE: return "guild donate" ;  // �������
	case BUY_CREATE_GUILD: return "create guild" ;  // ��������
	case BUY_GUILD_LEARN_SKILL: return "guild learn skill" ;  // ����ѧϰ����
	
	case BUY_DIRECT_FINISH_QUEST: return "direct finish quest" ;  // ����ֱ�����
	case BUY_GEN_DAILY_QUEST: return "gen daily quest" ;  // ����ÿ������
	 
	case BUY_LIMIT_COUNT: return "buy limit count" ;  // ��ɫ����ֵ ��ʱ�� ��Ҫ������չ

	default:
		return "sub money";
		break;
	}
	return "";
}

const char* get_company_money_change_type_info(int action_type) 
{
	switch (action_type)
	{
	case ADD_MONEY_BY_TASK: // ������
		return "task";
	case ADD_MONEY_BY_CC:   // �ͷ��ӿ�
		return "cc";
	case ADD_MONEY_BY_INSTALL: // �°�װ����
		return "install";
	default:
		return "free";
	}

	return "";
}

const char*  get_props_change_type_info(int change_from)
{
	switch (change_from)
	{
	case BY_BUY:    // ͨ������ 
		return "BUY";

	case BY_TREASURE_BOX: // ͨ��������
		return "OPEN TREASURE BOX";
	case BY_TASK_BONUS:  // ������
		return "TASK BONUS";
	case BY_FIGHT_BONUS: // ս������
		return "FIGHT BONUS";
	case BY_USE_GIFT:
		return "USE GIFT";
	case BY_DAILY_GIFT:
		return "DAILY GIFT";

	case BY_GM:
		return "GM";

	case BY_OTHER_BONUS:  // ͨ����������
		return "OTHER AWARDS";

	case USE_PROPS:  // ʹ��
		return "USE OFF";
	case SELL_PROPS: // �۳�
		return "SELL OUT";	
	case DESTROY_PROPS:
		return "DESTROY";
	default:
		return "props change";
		break;
	}

	return "";
}

