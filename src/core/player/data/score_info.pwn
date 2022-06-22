#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pScoreInfo
{
    pLevel,
    pDeaths,
    pKills,
    pWantedLevel,
}
static Player_ScoreInfo[MAX_PLAYERS][pScoreInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
/**
 *  Score Player Info
 */
// Player Level Accessor Function
stock PlayerData_GetLevel(playerid)
{
    return Player_ScoreInfo[playerid][pLevel];
}

stock PlayerData_SetLevel(playerid, level)
{
    return Player_ScoreInfo[playerid][pLevel] = level;
}

// Player Deaths Accessor Function
stock PlayerData_GetDeaths(playerid)
{
    return Player_ScoreInfo[playerid][pDeaths];
}

stock PlayerData_SetDeaths(playerid, deaths)
{
    return Player_ScoreInfo[playerid][pDeaths] = deaths;
}

// Player Kills Accessor Function
stock PlayerData_GetKills(playerid)
{
    return Player_ScoreInfo[playerid][pKills];
}

stock PlayerData_SetKills(playerid, kills)
{
    return Player_ScoreInfo[playerid][pKills] = kills;
}

// Player Wanted Level Accessor Function
stock PlayerData_GetWantedLevel(playerid)
{
    return Player_ScoreInfo[playerid][pWantedLevel];
}

stock PlayerData_SetWantedLevel(playerid, level)
{
    return Player_ScoreInfo[playerid][pWantedLevel] = level;
}

stock PlayerData_ResetScoreInfo(playerid)
{
    static const empty_data[pScoreInfo];
    Player_ScoreInfo[playerid] = empty_data;
    Player_ScoreInfo[playerid][pLevel] = 1;
    return Player_ScoreInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
