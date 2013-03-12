#ifndef ITEM_PROTOTYPE_MGR_H
#define ITEM_PROTOTYPE_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/item.pb.h"
#include "../config/equipment.pb.h"
#include "../config/magic_item.pb.h"
#include "../config/stone.pb.h"


class ItemPrototypeMgr
{
	typedef PropsData Prototype;

public:
	bool Init(const char* data_file);
	bool InitEquip(const char* data_file);
	bool InitMagicItem(const char* data_file);
	bool InitStone(const char* data_file);
    void clear() ;
	const PropsData* GetItemPrototype(int proto_id);
	const EquipmentData* GetEquipPrototype(int proto_id);
	const MagicItemData* GetMagicItemPrototype(int proto_id);
	const StoneData* GetStonePrototype(int proto_id);

	// 是否是金钱类型，放身上不占空间的物品
	bool is_money_tid(int proto_id);

	bool need_broad_cast(int proto_id);

private:
	typedef std::map<int, const Prototype*> Prototypes;
	typedef std::map<int, const EquipmentData*> EquipPrototypes;
	typedef std::map<int, const MagicItemData*> MagicItemPrototypes;
	typedef std::map<int, const StoneData*> StonePrototypes;

	Prototypes prototypes_;
	PropsDataGroup data_group_;

	EquipPrototypes equip_prototypes_;
	EquipmentDataGroup equipment_data_group_;

	MagicItemPrototypes magic_item_prototypes_;
	MagicItemGroup magic_item_data_group_;

	StonePrototypes stone_prototypes_;
	StoneDataGroup stone_data_group_;

	//DECLARE_SINGLETON_CONSTRUCTER(ItemPrototypeMgr);
};

//#define YINGLING_INSTANCE Singleton<ItemPrototypeManager>::instance()

    

#endif //ITEM_PROTOTYPE_MGR_H
