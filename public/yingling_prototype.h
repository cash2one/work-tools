#ifndef YINGLING_PROTOTYPE_H
#define YINGLING_PROTOTYPE_H

#include <map>
#include <set>
#include "../public/singleton.h"
#include "../config/yingling_init_data.pb.h"
#include "../config/yingling_profession_growup.pb.h"
#include "../config/yingling_hiring_config.pb.h"
#include "../config/yingling_lingli.pb.h"
#include "character_exp.pb.h"
#include "team_fight_exp_factor.pb.h"

class YinglingInitData;
struct HirableLibData 
{
	int max_chance;
	std::map<int, int> yingling_chance; // key chance value yingling_tid	
	std::vector<int> quality_chance; // seq: quality
	std::vector<std::vector<int> > quality_yinglings; // [quality] = std::vector<yingling_tid)
	HirableLibData()
		:max_chance(0)
	{}
};
struct SYinglingComboData
{
	int combo_id;
	int combo_status;
	int combo_level;
	int id_type; //1: id  2: pro  3: quality
	std::vector<std::pair<int, int > > ids; // first id_type, second id, use vector
};
struct SYinglingComboBonusData
{
	int combo_id;
	int combo_level;
	int cost_lingli;
	std::map<int, int > bonus;
};

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
	bool InitYinglingHiringLibData(const char* data_file);
	bool YinglingRecruitingslotData(const char* data_file);
	bool InitYinglingCombo(const char* data_file);
	bool InitYinglingComboBonus(const char* data_file);
	bool InitYinglingTrain(const char* data_file);
	bool InitYinglingTrainCost(const char* data_file);
	bool InitYinglingSoulRevert(const char* data_file);

	//bool InitYinglingComboUpgrade(const char* data_file);

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

	HirableLibData* get_yingling_lib(int lib_id) const;
	int gen_yingling_by_lib(int lib_id) const;

	const YinglingRecruitingData* GetYinglingRecruitingslotData(int recruiting_type,int player_level);

	const SYinglingComboData* GetYinglingComboData(int combo_id) const;
	const std::vector<int>* GetTriggerComboIdList(int id_type, int id) const;
	const SYinglingComboBonusData * GetCombaBonusData(int combo_id, int level) const
	{
		ComboBonusData::const_iterator it = combo_bonus_data_.find(std::make_pair(combo_id, level));
		if (it != combo_bonus_data_.end())
			return &it->second;
		else
			return NULL;
	}
	const YinglingTrainConfig* GetTrainConfig(int train_type, int level);
	const YinglingTrainCostConfig* GetTrainCostConfig(int train_type, int num);

	int GetSoulRevertNum(int soul) const
	{
		YinglingSoulRevertData::const_iterator it = soul_revert_data_.find(soul);
		if (it != soul_revert_data_.end())
			return it->second;
		else
			return 0;
	}

// 	const YinglingComboUpgradeData* GetComboUpgradeData(int combo_id, int level) const
// 	{
// 		ComboUpgradeData::const_iterator it = combo_upgrade_data_.find(std::make_pair(combo_id, level));
// 		if (it != combo_upgrade_data_.end())
// 			return &it->second;
// 		else
// 			return NULL;
// 	}
	void clear()
	{
		YinglingHiringLibData::iterator it = yingling_hiring_lib_data_.begin();
		for ( ; it!=yingling_hiring_lib_data_.end(); ++it)
		{
			delete it->second;
		}

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
		yingling_hiring_lib_data_.clear();
		recruiting_data_group_.Clear();
		recruiting_slot_data_.clear();
		syingling_combo_data_.clear();
		combo_data_ref_data_.clear();
		combo_bonus_data_.clear();
		train_config_data_.clear();
		train_cost_config_data_.clear();
		soul_revert_data_.clear();
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
	typedef std::map<int, HirableLibData* > YinglingHiringLibData;
	typedef std::pair<int, int>  LevelRangePair;
	typedef std::map<std::pair<int,LevelRangePair>, const YinglingRecruitingData*> RecruitingSlotData;
	typedef std::map<int, SYinglingComboData> SYinglingComboDatas;
	typedef std::map<std::pair<int, int>, SYinglingComboBonusData > ComboBonusData;
	//typedef std::map<std::pair<int, int>, YinglingComboUpgradeData> ComboUpgradeData;
	typedef std::map<std::pair<int, int>, std::vector<int> > ComboDataRefData;
	typedef std::vector<std::map<int, YinglingTrainConfig> > YinglingTrainConfigData;
	typedef std::vector<std::map<int, YinglingTrainCostConfig> > YinglingTrainCostConfigData;
	typedef std::map<int, int> YinglingSoulRevertData;

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
	
	//YinglingLibDataGroup yingling_lib_data_group_;
	YinglingHiringLibData yingling_hiring_lib_data_;

	YinglingRecruitingDataGroup recruiting_data_group_;
	RecruitingSlotData recruiting_slot_data_;

	//英灵组合
	SYinglingComboDatas syingling_combo_data_;
	ComboDataRefData combo_data_ref_data_;
	ComboBonusData combo_bonus_data_;
	//ComboUpgradeData combo_upgrade_data_;

	YinglingTrainConfigData train_config_data_;
	YinglingTrainCostConfigData train_cost_config_data_;

	YinglingSoulRevertData soul_revert_data_;


//	DECLARE_SINGLETON(YinglingPrototypes);
};

//#define YINGLING_INSTANCE Singleton<YinglingPrototypes>::instance()


#endif //YINGLING_PROTOTYPE_H

