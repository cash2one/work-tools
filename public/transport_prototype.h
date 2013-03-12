#ifndef TRANSPORT_PROTO_MGR_H
#define TRANSPORT_PROTO_MGR_H

#include <map>
#include "../public/singleton.h"
#include "../config/transport.pb.h"

class TransportPrototypeMgr
{
public:
	bool Init(const char* data_file);
	const TransportData* GetTransportPrototype(int npc_id);

private:
	typedef std::map<int, const TransportData*> Prototypes;

	Prototypes prototypes_;
	TransportDataGroup data_group_;

	DECLARE_SINGLETON_CONSTRUCTER(TransportPrototypeMgr);
};

#define TRANSPORT_INSTANCE Singleton<TransportPrototypeMgr>::instance()


#endif 

