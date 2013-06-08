#ifndef ITEM_YINGLING_PROTO_MGR_H
#define ITEM_YINGLING_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/item_yingling.pb.h"



class ItemYinglingPrototype
{
public:
    bool init(const char* data_file);

    const ItemYinglingData* get_item_yingling(int item_tid) const;

private:
    typedef std::map<int,ItemYinglingData> Prototypes;

    Prototypes m_prototype;


    DECLARE_SINGLETON_CONSTRUCTER(ItemYinglingPrototype);
};

#define ITEM_YINGLING_INSTANCE Singleton<ItemYinglingPrototype>::instance()


#endif 

