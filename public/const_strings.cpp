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

	default:
		return "NOT DEFINED";
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
		return "pay";
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
	case SUB_MONEY_BUY_PROPS: // ���򸶷ѵ���
		return "buy_props";
	case SUB_MONEY_BUY_PAY_FUNCTION: // ���򸶷ѹ���
		return "pay_function";
	default:
		return "not defined";
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

const char*  get_buy_type_info(int buy_type)
{
	switch (buy_type)
	{
	case BUY_PROPS: // �������
		return "BUY PROPS";
	case BUY_MORE_TIMES: // ��������ึ�ѹ���
		return "BUY MORE TIMES";

	case BUY_CLEAR_CD: // �������CD
		return "BUY CLEAR COOLDOWN";
	case BUY_OTHER_PAY_FUNCTION: // �����������ѹ���
		return "BUY OTHER PAY FUNCTION";
	default:
		return "UNKNOWN BUY TYPE";
		break;
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

	case BY_OTHER_BONUS:  // ͨ����������
		return "OTHER AWARDS";

	case USE_PROPS:  // ʹ��
		return "USE OFF";
	case SELL_PROPS: // �۳�
		return "SELL OUT";			
	default:
		return "UNKNOWN TYPE";
		break;
	}

	return "";
}

