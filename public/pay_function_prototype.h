/*******************************************************************************
 *
 *      @file: pay_function_prototype.h
 *      @brief: 付费功能配置数据.
 *
 *      @author: gxl.
 *      @Date: 2012/10/23
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef PAY_FUNCTION_PROTOTYPE_H
#define PAY_FUNCTION_PROTOTYPE_H

#include <map>
#include "singleton.h"

#include "pay_by_type_cost.pb.h"

class PayFunctionConfig
{
public:
	~PayFunctionConfig();

	bool init(const char* data_file);

	const PayByTypeData*  get_pay(int pay_type);

    typedef std::map<int,PayByTypeData> PrototypeContainer ;
private:


	PrototypeContainer    m_data ;

	DECLARE_SINGLETON_CONSTRUCTER(PayFunctionConfig);
};


#define PAY_FUNCTION_CONFIG_INSTANCE Singleton<PayFunctionConfig>::instance()



#endif

