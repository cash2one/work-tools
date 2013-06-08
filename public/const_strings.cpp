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

	case LOG_ACTION_CREATE_ROLE: // 创建角色
		return "CREATE ROLE";

	case LOG_ACTION_INVENTORY_INFO: // 背包信息 (每日首次登陆发送)'
		return "INVENTORY INFO";

	case LOG_ACTION_SERVER_DATA: // 服务器端数据 (对应公司 ser)
		return "SERVER DATA";

	case LOG_ACTION_ATTR:
		return "ATTR";   // 属性变化 (暂定等级变化)

	case LOG_ACTION_GUIDE: // 新手引导
		return "GUIDE";

	case LOG_ACTION_TRANSACTION: // 交易事件
		return "TRANSACTION";

	case LOG_ACTION_EQUIP_STAT: // 装备统计 (每次下线时发一次)
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
	case ADD_MONEY_BY_PAY: // 充值
		return "game_pay"; // 游戏内部的充值
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
	case BUY_PROPS: // 购买付费道具
		return "buy_props";

	case BUY_OPEN_YINGLING_SLOT: return "open yingling slot" ; // 英灵可拥有个数购买
	case BUY_OPEN_BAG_SLOT: return "open bag slot" ;  // 包裹格子购买
	case BUY_PHY_STRENGTH_1: return "buy phy strength 1" ; // 体力值购买1次
	case BUY_PHY_STRENGTH_2: return "buy phy strength 2" ; // 体力值购买2次
	case BUY_PHY_STRENGTH_3: return "buy phy strength 3" ; // 体力值购买3次
	case BUY_PHY_STRENGTH_4: return "buy phy strength 4" ; // 体力值购买4次
	case BUY_PHY_STRENGTH_5: return "buy phy strength 5" ; // 体力值购买5次

	case BUY_VIP_1: return "vip 1" ;  // 购买VIP 1
	case BUY_VIP_2: return "vip 2" ;  // 购买VIP 2
	case BUY_VIP_3: return "vip 3" ;  // 购买VIP 3
	case BUY_VIP_4: return "vip 4" ;  // 购买VIP 4
	case BUY_VIP_5: return "vip 5" ;  // 购买VIP 5
	case BUY_VIP_6: return "vip 6" ;  // 购买VIP 6


	case BUY_ROLE_SOUL_STONE: return "role soul stone" ; // 角色 灵魂石
	case BUY_ROLE_SOUL_FEATHER: return "role soul feather" ;  // 角色 羽毛
	case BUY_YINGLING_SOUL_STONE: return "yingling soul stone" ;  // 英灵 灵魂石
	case BUY_YINGLING_SOUL_FEATHER: return "yingling soul feather" ;  // 英灵 羽毛
	case BUY_INJECT_ROLE_SOUL: return "role soul inject" ;  // 角色灵魂注入
	case BUY_INJECT_YINGLING_SOUL: return "yingling soul inject" ;  // 英灵灵魂注入
	case BUY_SPACE_CHALLENGE_CD: return "space challenge cd" ;  // 位面挑战加速

	case BUY_SKILL_PRACTICE: return "skill practice" ;  // 技能修炼
	case BUY_SKILL_PRACTICE_SPEED_UP: return "skill speed up" ;  // 技能修炼加速

	case BUY_EQUIP_STRENGTH: return "equip strength" ;  // 装备升星
	case BUY_EQUIP_XILIAN: return "equip xilian" ;  // 装备洗练
	case BUY_EQUIP_XILIAN_LOCK: return "equip xilian lock" ; // 装备洗练锁定
	case BUY_EQUIP_INHERIT: return "equip inherit" ;  // 装备继承
	case BUY_EQUIP_SOCKET: return "equip socket" ;  // 装备打孔
	case BUY_EQUIP_STONE_INSERT: return "equip stone insert" ;  // 宝石镶嵌
	case BUY_EQUIP_STONE_REMOVE: return "equip stone remove" ;  // 宝石移除

	case BUY_EQUIP_STONE_GEM: return "equip stone gem" ;  // 宝石合成

	case BUY_OPEN_HIRE_PLACE: return "open hire place" ;   // 开启招募位消耗
	case BUY_REFRESH_YINGLING_HIRING_LIST: return "refresh yingling hiring list" ;  // 刷新英灵招募列表
	case BUY_HIRE_YINGLING: return "hire yingling" ;  // 唤醒英灵 

	case BUY_INSTANCE_WANTED_ALL_RESET_1:  // 第1次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_2: // 第2次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_3: // 第3次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_4: // 第4次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_5: // 第5次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_6: // 第6次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_7: // 第7次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_8: // 第8次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_9: // 第9次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_10: // 第10次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_11: // 第11次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_12: // 第12次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_13: // 第13次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_14: // 第14次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_15: // 第15次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_16: // 第16次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_17: // 第17次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_18: // 第18次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_19: // 第19次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_20: // 第20次重置

	case BUY_INSTANCE_WANTED_ALL_RESET_21:  // 第21次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_22:  // 第22次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_23:  // 第23次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_24:  // 第24次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_25:  // 第25次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_26:  // 第26次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_27:  // 第27次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_28:  // 第28次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_29:  // 第29次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_30:  // 第30次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_31:  // 第31次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_32:  // 第32次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_33:  // 第33次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_34:  // 第34次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_35:  // 第35次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_36:  // 第36次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_37:  // 第37次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_38:  // 第38次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_39:  // 第39次重置
	case BUY_INSTANCE_WANTED_ALL_RESET_40: return "instance wanted reset" ;  // 第40次重置

	case BUY_ARENA_CHALLENGE_TIMES_1:  // 竞技场购买1次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_2:  // 竞技场购买2次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_3:  // 竞技场购买3次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_4:  // 竞技场购买4次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_5:  // 竞技场购买5次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_6:  // 竞技场购买6次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_7:  // 竞技场购买7次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_8:  // 竞技场购买8次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_9:  // 竞技场购买9次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_10:  // 竞技场购买10次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_11:  // 竞技场购买11次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_12:  // 竞技场购买12次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_13:  // 竞技场购买13次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_14:  // 竞技场购买14次数挑战次数
	case BUY_ARENA_CHALLENGE_TIMES_15:  return "buy arena challenge time" ; // 竞技场购买15次数挑战次数

	case BUY_ARENA_REFRESH_CD: return "arena refresh cd" ;  // 竞技场CD加速
	case BUY_REFRESH_CD: return "other refresh cd" ;  // 刷新CD 临时； 需要具体扩展

	case BUY_FAST_AUTO_FIGHT: return "fast auto fight" ; // 挂机加速


	case BUY_REFRESH_REWARD_TASK: return "refresh reward task" ;  // 刷新悬赏任务
	case BUY_FAST_REWRAD_TASK: return "reward task finish" ;  // 立即完成悬赏任务
	case BUY_REWARD_TASK_1:  // 购买1次悬赏任务
	case BUY_REWARD_TASK_2: // 购买2次悬赏任务
	case BUY_REWARD_TASK_3: // 购买3次悬赏任务
	case BUY_REWARD_TASK_4:// 购买4次悬赏任务
	case BUY_REWARD_TASK_5: // 购买5次悬赏任务
	case BUY_REWARD_TASK_6: // 购买6次悬赏任务
	case BUY_REWARD_TASK_7: // 购买7次悬赏任务
	case BUY_REWARD_TASK_8: // 购买8次悬赏任务
	case BUY_REWARD_TASK_9: // 购买9次悬赏任务
	case BUY_REWARD_TASK_10: // 购买10次悬赏任务
	case BUY_REWARD_TASK_11: // 购买11次悬赏任务
	case BUY_REWARD_TASK_12: // 购买12次悬赏任务
	case BUY_REWARD_TASK_13: // 购买13次悬赏任务
	case BUY_REWARD_TASK_14: // 购买14次悬赏任务
	case BUY_REWARD_TASK_15: return "buy reward task" ; // 购买15次悬赏任务

	case BUY_YOULI_RESET_MAP: return "youli reset map" ;  // 重置地图
	case BUY_YOULI_DICE: return "youli dice" ; // 遥控色子
	case BUY_YOULI_1:   // 购买1次游历次数
	case BUY_YOULI_2:  // 购买2次游历次数
	case BUY_YOULI_3:  // 购买3次游历次数
	case BUY_YOULI_4:  // 购买4次游历次数
	case BUY_YOULI_5:  // 购买5次游历次数
	case BUY_YOULI_6:  // 购买6次游历次数
	case BUY_YOULI_7:  // 购买7次游历次数
	case BUY_YOULI_8:  // 购买8次游历次数
	case BUY_YOULI_9:  // 购买9次游历次数
	case BUY_YOULI_10: return "buy youli time" ; // 购买10次游历次数

	case BUY_SKIP_FIGHT: return "skip fight" ;  // 跳过战斗
	case BUY_QUICK_RESPAWN: return "quick respawn" ;  // 购买快速复活
	case BUY_ENCOURAGE_BUFF: return "encourage buff" ;  // 购买boss鼓舞buff
	 
	case BUY_GUILD_DONATE: return "guild donate" ;  // 公会捐献
	case BUY_CREATE_GUILD: return "create guild" ;  // 创建公会
	case BUY_GUILD_LEARN_SKILL: return "guild learn skill" ;  // 公会学习技能
	
	case BUY_DIRECT_FINISH_QUEST: return "direct finish quest" ;  // 任务直接完成
	case BUY_GEN_DAILY_QUEST: return "gen daily quest" ;  // 生成每日任务
	 
	case BUY_LIMIT_COUNT: return "buy limit count" ;  // 角色限制值 临时； 需要具体扩展

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
	case BY_USE_GIFT:
		return "USE GIFT";
	case BY_DAILY_GIFT:
		return "DAILY GIFT";

	case BY_GM:
		return "GM";

	case BY_OTHER_BONUS:  // 通过其他奖励
		return "OTHER AWARDS";

	case USE_PROPS:  // 使用
		return "USE OFF";
	case SELL_PROPS: // 售出
		return "SELL OUT";	
	case DESTROY_PROPS:
		return "DESTROY";
	default:
		return "props change";
		break;
	}

	return "";
}

