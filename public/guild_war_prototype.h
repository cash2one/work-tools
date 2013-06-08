/*******************************************************************************
 *
 *      @file:  guild_war_prototype.h
 *      @brief: ����ս��� ���ý���
 *
 *      @author: gxl.
 *      @Date: 2013/05/21
 *      COPYRIGHT (C) 2013, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef GUILD_WAR_PROTOTYPE_H
#define GUILD_WAR_PROTOTYPE_H

#include "guild_war_win_lose.pb.h"
#include "guild_war_rank.pb.h"

// �����еĹ���ս����
enum GuildWarType 
{
    GuildWarType_BOSS = 1, // ����սԤѡ��
    GuildWarType_PvP = 2, // ����սpvp
    GuildWarType_PvP_Player_Rank_OR_FIGHT = 3, // ����սpvp
};

// �����е�ʤ������
enum GuildWarWinLoseType
{
    GuildWarWinLoseType_Win = 1,
    GuildWarWinLoseType_Lose = 2,
};


class GuildWarProtoManager
{
public:
    GuildWarProtoManager();
    ~GuildWarProtoManager();

    void clear();

    bool InitGuildWarWinLoseData(const char* data_file);
    bool InitGuildWarRankData(const char* data_file);

    const GuildWarWinLoseData* GetGuildWarWinLoseData(int guild_war_type, int win_or_lose);
    const GuildWarRankData*    GetGuildWarRankData(int guild_war_type, int rank = 0);

private:
    GuildWarWinLoseDataGroup    m_win_lose_group;
    GuildWarRankDataGroup       m_rank_group;

};










#endif

