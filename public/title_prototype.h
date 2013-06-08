/*
 * vip_gift_prototype.h
 *
 *  Created on: 2013-6-7
 *  Author: weitq
 */

#ifndef TITLE_PROTOTYPE_H
#define TITLE_PROTOTYPE_H

#include <map>
#include "title.pb.h"

class TitleProtoManager
{
public:
	TitleProtoManager();
	~TitleProtoManager();
	void clear();
	bool init(const char* data_file);
	const TitleData* get_title_data(int title_id);

private:
	typedef std::map<int, TitleData> TitleMap;
	TitleMap m_title_map;
};

#endif /* TITLE_PROTOTYPE_H */
