
#include "action_handler.h"

int main()
{
    packet_info pi = {0} ;
    for(int i = 0 ; i < action_handler_manager::MAX_ACTION_COUNT ; ++i)
    {
        base_action_handler* handler = action_handler_manager::instance().get_handler(i) ;
        if(handler) handler->do_action(&pi) ;
    }

    return 0 ;
}



