/*******************************************************************************
 *
 *      @file: const_strings.h
 *      @brief: convert between enum and strings
 *
 *      @author: gxl.
 *      @Date: 2012/10/10
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef CONST_ENUM_STRING_H
#define CONST_ENUM_STRING_H

const char*  get_log_src_name(int src_type) ;
const char*  get_log_action_name(int act_type) ;
const char* get_money_type_info(int money_type) ;
const char* get_money_change_type_info(int action_type) ;

// 公司的udp服务器需要的货币增减类型 task, cc, install, free
const char* get_company_money_change_type_info(int action_type) ;
const char*  get_buy_type_info(int buy_type);
const char*  get_props_change_type_info(int change_from);


#endif





