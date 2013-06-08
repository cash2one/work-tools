#include "vip_bonus_prototype.h"
#include <fstream>


int VipSettingsPrototype::InitVipBonusData( const char* data_file )
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	//assert(fs);
	if (fs.fail())
	{
		//LOG_ERROR("open file %s failed.", fs);
		return false;
	}

	if (!vip_bonus_data_group_.ParseFromIstream(&fs))
	{
		//LOG_ERROR("parse file %s failed.", fs);
		return false;
	}

	for (int i=0; i<vip_bonus_data_group_.data_size(); ++i)
	{
		const VipBonusData& d = vip_bonus_data_group_.data(i);

		// vip 固定配置
		if (d.bonus_type() == 3)
		{
			VipSettingDataContainer v;
			vip_setting_data_container_.insert(
					std::make_pair(
						std::make_pair(d.vip_level(), d.bonus_id()), 
						d.bonus_value()));
			// 固定配置不需要加入vip等级变化时候的处理，所以直接continue
			continue;
		}	

		//added by cliff
		if (d.bonus_type() == 2) {
			int vip_level = d.vip_level();
			auto p_level = function_list_.find(vip_level);
			if (p_level == function_list_.end()) {
				function_list_[vip_level] = map<int, bool> ();
			}

			function_list_[vip_level][d.bonus_id()] = (d.bonus_value() == 1);
		}

		VipBonusDataContainer::iterator it = vip_bonus_data_container_.find(d.vip_level());
		if (it == vip_bonus_data_container_.end())
		{
			std::vector<VipBonusData> tmp_v;
			it = vip_bonus_data_container_.insert(std::make_pair(d.vip_level(), tmp_v)).first;
		}
		std::vector<VipBonusData>& vec = it->second;
		vec.push_back(d);
	}

	return true;
}

bool VipSettingsPrototype::is_vip_function_opened(int vip_level, FunctionLimitType function_id)
{
	auto p_level = function_list_.find(vip_level);
	if (p_level != function_list_.end()) {
		auto p_func = p_level->second.find(static_cast<int>(function_id));
		if (p_func != p_level->second.end()) {
			return p_func->second;
		}
	}
	return false;
}

