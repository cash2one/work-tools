
#include "action_handler.h"

static const int move_action_id = 2 ;
struct move_request
{
    int uid ;
} ;

struct move_response
{
    int error_code  ;

} ;


class move_handler : public template_action_handler<move_action_id,move_request,move_response>
{
public:
    void process(move_request& req,move_response& res)
    {
        req.uid = 1 ;
        move_handler::request_body_type a = req ;
        printf("move_handler %d\n",a.uid) ;
    }

} g_move_handler ;




