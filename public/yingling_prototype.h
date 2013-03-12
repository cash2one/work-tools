#ifndef YINGLING_PROTOTYPE_H
#define YINGLING_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/yingling_init_data.pb.h"
#include "../config/yingling_profession_growup.pb.h"
#include "../config/yingling_hiring_config.pb.h"
#include "../config/yingling_lingli.pb.h"
#include "character_exp.pb.h"
#include "team_fight_exp_factor.pb.h"

class YinglingInitData;

class YinglingPrototypes
{
public:
	YinglingPrototypes()
	{
	}
	bool Init(const char* data_file);
	bool InitGrowthData(const char* data_file);
	bool InitCharacterExpData(const char* data_file);
	bool InitHiringSlotData(const char* data_file);
	bool InitHiringCost(const char* data_file);
	bool InitSlotData(const char* data_file);
	bool InitLingliConvertData(const char* data_file);
	bool InitLingliSummonData(const char* data_file);
	bool InitFightExpFactorData(const char* data_file);

	const YinglingInitData* GetYinglingPrototype(const int proto_id);
	const YinglingProGrownRate* GetProfessionGrowthData(const int pro_id);
	const YinglingHiringSlotData* GetYinglingHiringSlotData(const int index);
	const YinglingHiringConfigData* GetYinglingHiringConfigData(const int hire_type);
	const YinglingSlotData* GetYinglingSlotData(const int index);
	const int GetYinglingSlotPayedMaxNum() const
	{
		return yuanbao_slot_data_.size();
	}
	const YinglingLingliConvertData* GetLingliConvertData(const int quality);
	const YinglingLingliSummonData* GetLingliSummonData(const int quality);
	//const YinglingInitEquip* GetYinglingProtoEquip(const int proto_id);
	//const YinglingInitSkill* GetYinglingProtoSkill(const int proto_id);

	const std::vector<int>& GetYinglingsByQuality(const int quality) const;

	int get_level_up_need_exp(int level) const; // exp need from level to level + 1

	int get_exp_factor(int team_member_count);

	void clear()
	{
		proto_data_.clear();
		pb_data_.Clear();
		quality_yingling_.clear();
		growth_data_.clear();
		growth_data_group_.Clear();
		hiring_slot_data_.clear();
		hiring_slot_data_group_.Clear();
		slot_data_.clear();
		yuanbao_slot_data_.clear();
		slot_data_group_.Clear();
		hiring_config_data_.clear();
		hiring_config_data_group_.Clear();
		lingli_convert_data_.clear();
		lingli_convert_data_group_.Clear();
		lingli_summon_data_.clear();
		lingli_summon_data_group_.Clear();
		m_CharacterExpDataGroup.Clear();
		m_player_levelup_exp_map.clear();
		m_team_fight_exp_factor_group.Clear();
	}

private:
	typedef std::map<int, const YinglingInitData*> ProtoData;
	typedef std::map<int, const YinglingProGrownRate*> GrowthData;
	typedef std::vector<std::vector<int> > QualityYingling;
	typedef std::map<int, const YinglingHiringSlotData*> HiringSlotData;
	typedef std::map<int, const YinglingHiringConfigData*> HiringConfigData;
	typedef std::map<int, const YinglingSlotData*> SlotData;
	typedef std::vector<const YinglingSlotData*> YuanBaoSlotData;
	typedef std::map<int, const YinglingLingliConvertData*> LingliConvertData;
	typedef std::map<int, const YinglingLingliSummonData*> LingliSummonData;

	ProtoData proto_data_;
	YinglingInitDataGroup pb_data_;

	QualityYingling quality_yingling_;

	GrowthData growth_data_;
	YinglingProGrownRateGroup growth_data_group_;

	HiringSlotData hiring_slot_data_;
	YinglingHiringSlotDataGroup hiring_slot_data_group_;

	SlotData slot_data_;
	YuanBaoSlotData yuanbao_slot_data_;
	YinglingSlotDataGroup slot_data_group_;

	HiringConfigData hiring_config_data_;
	YinglingHiringConfigDataGroup hiring_config_data_group_;

	LingliConvertData lingli_convert_data_;
	YinglingLingliConvertDataGroup lingli_convert_data_group_;

	LingliSummonData lingli_summon_data_;
	YinglingLingliSummonDataGroup lingli_summon_data_group_;

	// 角色经验
	CharacterExpDataGroup      m_CharacterExpDataGroup;
	typedef  std::map<int, int >   PlayerLevelExpMap;
	PlayerLevelExpMap          m_player_levelup_exp_map;

	// 战斗经验系数
	TeamFightExpFactorDataGroup m_team_fight_exp_factor_group;

//	DECLARE_SINGLETON(YinglingPrototypes);
};

//#define YINGLING_INSTANCE Singleton<YinglingPrototypes>::instance()


#endif //YINGLING_PROTOTYPE_H

