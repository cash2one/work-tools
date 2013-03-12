#ifndef PUBLIC_GEM_PROTOTYPE_H
#define PUBLIC_GEM_PROTOTYPE_H

#include <map>
#include "../public/singleton.h"
#include "../config/gem.pb.h"


class GemPrototype
{
	typedef std::map<int, std::vector<std::pair<int, int> > > UpgradePrototypes;
	typedef std::map<std::pair<int, int>, std::pair<int, int> > InsertPrototypes;
	typedef std::map<int, const GemBaseInfoData*> GemBasePrototypes;
public:
	bool init_upgrade_config(const char* data_file);
	const std::vector<std::pair<int, int> > * get_upgrade_config(int gem_id)
	{
		UpgradePrototypes::iterator it = upgrade_prototypes_.find(gem_id);
		if (it != upgrade_prototypes_.end())
			return &it->second;
		else
			return NULL;

	};
	bool init_insert_config(const char* data_file);
	const std::pair<int, int>* get_insert_config(int gem_id, int equip_pos)
	{
		InsertPrototypes::iterator it = insert_prototypes_.find(std::make_pair(gem_id, equip_pos));
		if (it != insert_prototypes_.end())
			return &it->second;
		else
			return NULL;
	}
	bool init_gem_base(const char* data_file);
	const GemBaseInfoData* get_gem_base_info(int gem_id)
	{
		GemBasePrototypes::iterator it = gem_base_prototypes_.find(gem_id);
		if (it != gem_base_prototypes_.end())
			return it->second;
		else
			return NULL;
	}
private:
	UpgradePrototypes upgrade_prototypes_;
	InsertPrototypes insert_prototypes_;
	GemBasePrototypes gem_base_prototypes_;

	GemUpgradeConfigDataGroup upgrade_config_data_group_;

	GemBaseInfoDataGroup gem_base_info_group_;

	DECLARE_SINGLETON_CONSTRUCTER(GemPrototype);
};

#define GEM_PROTO Singleton<GemPrototype>::instance()

#endif //PUBLIC_GEM_PROTOTYPE_H

