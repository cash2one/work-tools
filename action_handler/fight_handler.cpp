
#include "action_handler.h"

static const int fight_action_id = 3 ;
struct fight_request
{
    int uid ;
} ;

struct fight_response
{
    int error_code  ;

} ;


class fight_handler : public template_action_handler<fight_action_id,fight_request,fight_response>
{
public:
    void process(fight_request& req,fight_response& res)
    {
        req.uid = 1 ;
        fight_handler::request_body_type a = req ;
        printf("fight_handler %d\n",a.uid) ;
    }

} g_fight_handler ;




