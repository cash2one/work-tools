/*******************************************************************************
 *
 *      @file:  guild_war_prototype.cpp
 *      @brief: 公会战相关 配置解析
 *
 *      @author: gxl.
 *      @Date: 2013/05/21
 *      COPYRIGHT (C) 2013, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <fstream>
#include "guild_war_prototype.h"

using namespace std;

GuildWarProtoManager::GuildWarProtoManager()
{

}

GuildWarProtoManager::~GuildWarProtoManager()
{
    clear();
}

void GuildWarProtoManager::clear()
{
    m_win_lose_group.Clear();
    m_rank_group.Clear();
}

bool GuildWarProtoManager::InitGuildWarWinLoseData(const char* data_file)
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false;

    if (!m_win_lose_group.ParseFromIstream(&fs)) return false;

    return true;
}

bool GuildWarProtoManager::InitGuildWarRankData(const char* data_file)
{
    std::fstream  fs( data_file, std::ios::in | std::ios::binary );
    if (fs.fail()) return false;

    if (!m_rank_group.ParseFromIstream(&fs)) return false;

    return true;
}

const GuildWarWinLoseData* GuildWarProtoManager::GetGuildWarWinLoseData(int guild_war_type, int win_or_lose)
{
    for (int i=0; i < m_win_lose_group.data_size(); i++)
    {
        const GuildWarWinLoseData& d = m_win_lose_group.data(i);
        if (d.guild_war_type() == guild_war_type 
            && d.win_or_lose() == win_or_lose)
        {
            return &d;
        }
    }
    
    return NULL;
}

const GuildWarRankData*    GuildWarProtoManager::GetGuildWarRankData(int guild_war_type, int rank )
{
    for (int i=0; i < m_rank_group.data_size(); i++)
    {
        const GuildWarRankData& d = m_rank_group.data(i);
        if (d.rank_type() == guild_war_type 
            && d.ranking() == rank)
        {
            return &d;
        }
    }

    return NULL;
}

