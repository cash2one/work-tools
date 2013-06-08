
#include "action_handler.h"

static const int action_id_login = 1 ;
struct proto_login_request
{
    int uid ;
} ;

struct proto_login_response
{
    int error_code  ;

} ;


/*
typedef  template_action_handler<1,login_request,login_response> login_handler ;
login_handler g_login_handler ;
template<> void login_handler::process(login_request& req,login_response& res)
{
    printf("login_handler\n") ;
}
*/

class login_handler : public template_action_handler<action_id_login,proto_login_request,proto_login_response>
{
public:
    void process(proto_login_request& req,proto_login_response& res)
    {
        printf("login_handler\n") ;
    }

} g_login_handler ;




