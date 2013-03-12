/*
 * gate_fsm.cpp
 *
 *  Created on: 2012-4-5
 *      Author: lixingyi
 */

#include "gate_fsm.h"
#include "gate_application.h"
#include "message.h"


using namespace kingnet ;

GateFsmManager::GateFsmManager()
{
    // TODO Auto-generated constructor stub

}

GateFsmManager::~GateFsmManager()
{
    clear() ;
}

base_fsm* GateFsmManager::alloc_fsm(int fsm_type)
{
    switch(fsm_type)
    {
   
    default:
        ;
    }

    return NULL ;
}
void GateFsmManager::free_fsm(base_fsm* object)
{
    delete object ;
}








