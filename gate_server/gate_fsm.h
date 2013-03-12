/*
 * gate_fsm.h
 *
 *  Created on: 2012-4-5
 *      Author: lixingyi
 */

#ifndef GATE_FSM_H_
#define GATE_FSM_H_

#include "fsm_manager.h"
#include "timer_manager.h"
#include "tcp_connection.h"


using kingnet::base_fsm ;

class GateFsmManager: public kingnet::fsm_manager
{
public:
    GateFsmManager();
    virtual ~GateFsmManager();

protected:
    virtual base_fsm* alloc_fsm(int fsm_type);
    virtual void free_fsm(base_fsm* object);
};



#endif /* GATE_FSM_H_ */
