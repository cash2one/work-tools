/*******************************************************************************
 *
 *      @file: pay_function_prototype.cpp
 *      @brief: 付费功能配置数据.
 *
 *      @author: gxl.
 *      @Date: 2012/10/23
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <fstream>
#include "pay_function_prototype.h"


PayFunctionConfig::~PayFunctionConfig()
{
}


bool PayFunctionConfig::init(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail()) return false;

	PayByTypeDataGroup    data_group ;

	if (!data_group.ParseFromIstream(&fs))
	{
		return false;
	}

	for (int i=0; i < data_group.pay_by_type_data_size(); i++)
	{
		const PayByTypeData&  d = data_group.pay_by_type_data(i);
		m_data[d.pay_type()] = d;
	}
	
	return true;
}

const  PayByTypeData* PayFunctionConfig::get_pay(int pay_type)
{
    PrototypeContainer::const_iterator it = m_data.find(pay_type) ;
    if(it != m_data.end())
    {
        return &it->second ;
    }

    return NULL ;
	
}
