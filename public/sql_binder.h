#ifndef _generate_h_SQL_BINDER 
#define _generate_h_SQL_BINDER 
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
using std::string;
using std::vector;
class sql_binder 
{
public:
    virtual ~sql_binder() { } ;
    virtual void clear_dirty() =0;
    virtual bool is_dirty() const = 0;
    virtual void load(const char** data) = 0;
    virtual void load(const vector<string>& data) =0;
    virtual int sql_insert(char* buf,int size) const =0;
    virtual int sql_update(char* buf,int size) const =0;
    virtual int sql_query(char* buf,int size) const =0;
    virtual int sql_delete(char* buf,int size) const =0;
protected:
    virtual int sql_key(char* buf,int size) const =0;
    virtual int sql_data(char* buf,int size) const =0;
};
#endif
