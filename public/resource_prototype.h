#ifndef RESOURCE_PROTOTYPE_H
#define RESOURCE_PROTOTYPE_H

#include <map>
#include "singleton.h"
#include "../config/resource.pb.h"

class ResourcePrototype
{
	typedef std::map<int, ResourceData> Prototypes;
public:
	int Init(const char* data_file);

	const ResourceData* GetResourceData(int resource_id);

private:
	Prototypes prototypes_;

	DECLARE_SINGLETON_CONSTRUCTER(ResourcePrototype);
};

#define RESOURCE_PROTO Singleton<ResourcePrototype>::instance()

#endif //RESOURCE_PROTOTYPE_H
