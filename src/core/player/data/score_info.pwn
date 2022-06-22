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
// ============== LEVEL ACCESSORS ============== //
// Getters
stock PlayerData_GetLevel(playerid)
{
    return Player_ScoreInfo[playerid][pLevel];
}

// Setters
stock PlayerData_SetLevel(playerid, level)
{
    return Player_ScoreInfo[playerid][pLevel] = level;
}

// ============== DEATHS ACCESSORS ============== //
// Getters
stock PlayerData_GetDeaths(playerid)
{
    return Player_ScoreInfo[playerid][pDeaths];
}

// Setters
stock PlayerData_SetDeaths(playerid, deaths)
{
    return Player_ScoreInfo[playerid][pDeaths] = deaths;
}

// ============== KILLS ACCESSORS ============== //
// Getters
stock PlayerData_GetKills(playerid)
{
    return Player_ScoreInfo[playerid][pKills];
}

// Setters
stock PlayerData_SetKills(playerid, kills)
{
    return Player_ScoreInfo[playerid][pKills] = kills;
}

// ============== WANTED LEVEL ACCESSORS ============== //
// Getters
stock PlayerData_GetWantedLevel(playerid)
{
    return Player_ScoreInfo[playerid][pWantedLevel];
}

// Setters
stock PlayerData_SetWantedLevel(playerid, level)
{
    return Player_ScoreInfo[playerid][pWantedLevel] = level;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetScoreInfo(playerid)
{
    static const empty_data[pScoreInfo];
    Player_ScoreInfo[playerid] = empty_data;
    Player_ScoreInfo[playerid][pLevel] = 1;
    return Player_ScoreInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
