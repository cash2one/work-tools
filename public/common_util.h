/*
 * common_util.h
 *
 *  Created on: 2012-9-2
 *      Author: lixingyi
 */

#ifndef COMMON_UTIL_H_
#define COMMON_UTIL_H_

#include <stdint.h>

#define PLAYER_GUID(TID,ROLE_ID)  (((int64_t)(TID) << 32) | (ROLE_ID))
#define PLAYER_ROLE_ID(GUID) ((GUID)&0xffffffff)
#define PLAYER_UID(GUID) ((GUID)&0xffffffff)
#define PLAYER_TID(GUID) ((GUID) >> 32 )

#define ITEM_GUID(TID,SEQ)  (((int64_t)(TID) << 32) | (SEQ))
#define ITEM_TID(GUID) ((GUID) >> 32 )

#endif /* */

