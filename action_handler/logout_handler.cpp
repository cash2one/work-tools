
#include "action_handler.h"

static const int action_id_logout = 4 ;
struct proto_logout_request
{
    int uid ;
} ;

struct proto_logout_response
{
    int error_code  ;

} ;


/*
typedef  template_action_handler<1,logout_request,logout_response> logout_handler ;
logout_handler g_logout_handler ;
template<> void logout_handler::process(logout_request& req,logout_response& res)
{
    printf("logout_handler\n") ;
}
*/

class logout_handler : public template_action_handler<action_id_logout,proto_logout_request,proto_logout_response>
{
public:
    void process(proto_logout_request& req,proto_logout_response& res)
    {
        printf("logout_handler\n") ;
    }

} g_logout_handler ;




