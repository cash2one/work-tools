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

// 根据日志来源类型获得来源名字
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
	case LOG_ACTION_LOGON: // 登陆
		return "LOGON";

	case LOG_ACTION_LOGOFF: // 下线
		return "LOGOFF";

	case LOG_ACTION_BUY: // 购买行为 (购买道具、付费功能(次数、清除冷却时间等))
		return "BUY";

	case LOG_ACTION_SELL: // 售出行为 (仅部分道具可售)
		return "SELL";

	case LOG_ACTION_ADD_PROPS: // 获得道具 (通过购买、各种奖励、宝箱等)
		return "ADD_PROPS";

	case LOG_ACTION_SUB_PROPS: // 消耗道具 (使用、售出、交易等)
		return "SUB_PROPS";

	case LOG_ACTION_ADD_MONEY: // 货币增加 (充值、游戏奖励、售出道具)
		return "ADD_MONEY";

	case LOG_ACTION_SUB_MONEY: // 货币减少 (购买道具和付费功能)
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
	case ADD_MONEY_BY_PAY: // 充值
		return "pay";
	case ADD_MONEY_BY_TASK: // 任务奖励
		return "task";
	case ADD_MONEY_BY_CC:   // 客服接口
		return "cc";
	case ADD_MONEY_BY_INSTALL: // 新安装附赠
		return "install";
	case ADD_MONEY_BY_GM:   // 后台GM
		return "gm";
	case ADD_MONEY_BY_SELL: // 出售
		return "sell";
	case ADD_MONEY_BY_BONUS: // 游戏中的奖励
		return "free";
	case ADD_MONEY_BY_OTHERS:// 其他途径
		return "other";
	case SUB_MONEY_BUY_PROPS: // 购买付费道具
		return "buy_props";
	case SUB_MONEY_BUY_PAY_FUNCTION: // 购买付费功能
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
	case ADD_MONEY_BY_TASK: // 任务奖励
		return "task";
	case ADD_MONEY_BY_CC:   // 客服接口
		return "cc";
	case ADD_MONEY_BY_INSTALL: // 新安装附赠
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
	case BUY_PROPS: // 购买道具
		return "BUY PROPS";
	case BUY_MORE_TIMES: // 购买次数类付费功能
		return "BUY MORE TIMES";

	case BUY_CLEAR_CD: // 购买清除CD
		return "BUY CLEAR COOLDOWN";
	case BUY_OTHER_PAY_FUNCTION: // 购买其他付费功能
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
	case BY_BUY:    // 通过付费 
		return "BUY";

	case BY_TREASURE_BOX: // 通过开宝箱
		return "OPEN TREASURE BOX";
	case BY_TASK_BONUS:  // 任务奖励
		return "TASK BONUS";
	case BY_FIGHT_BONUS: // 战斗奖励
		return "FIGHT BONUS";

	case BY_OTHER_BONUS:  // 通过其他奖励
		return "OTHER AWARDS";

	case USE_PROPS:  // 使用
		return "USE OFF";
	case SELL_PROPS: // 售出
		return "SELL OUT";			
	default:
		return "UNKNOWN TYPE";
		break;
	}

	return "";
}

