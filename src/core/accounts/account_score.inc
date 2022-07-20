#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_SCORE_DATA
{
    p_LEVEL,
    p_HOURS_PLAYED,
    p_EXPERIENCE,
    p_DEATHS,
    p_KILLS,
    p_WANTED_LEVEL,
    p_NOOB_ANSWERS
}
static gsScoreInfo[MAX_PLAYERS][p_SCORE_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveScoreData(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    new query_string[200];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_LEVEL, gsScoreInfo[playerid][p_LEVEL],
    PLAYER_FIELD_HOURS_PLAYED, gsScoreInfo[playerid][p_HOURS_PLAYED],
    PLAYER_FIELD_EXP, gsScoreInfo[playerid][p_EXPERIENCE],
    PLAYER_FIELD_DEATHS, gsScoreInfo[playerid][p_DEATHS],
    PLAYER_FIELD_KILLS, gsScoreInfo[playerid][p_KILLS],
    PLAYER_FIELD_WANTED_LEVEL, gsScoreInfo[playerid][p_WANTED_LEVEL],
    PLAYER_FIELD_NOOB_ANSWERS, gsScoreInfo[playerid][p_NOOB_ANSWERS],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetScoreData(playerid)
{
    static const empty_data[p_SCORE_DATA];
    gsScoreInfo[playerid] = empty_data;
    gsScoreInfo[playerid][p_LEVEL] = 1;
    return 1;
}

// ============== LEVEL ACCESSORS ============== //
// Getters
stock Player_GetLevel(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_LEVEL];
}

// Setters
stock Player_SetLevel(playerid, level)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    SetPlayerScore(playerid, level);
    gsScoreInfo[playerid][p_LEVEL] = level;
    return 1;
}

// ============== HOURS PLAYED ACCESSORS ============== //
// Getters
stock Player_GetHoursPlayed(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_HOURS_PLAYED];
}

// Setters
stock Player_SetHoursPlayed(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsScoreInfo[playerid][p_HOURS_PLAYED] = quantity;
    return 1;
}

// ============== EXPERIENCE ACCESSORS ============== //
// Getters
stock Player_GetExperience(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_EXPERIENCE];
}

// Setters
stock Player_SetExperience(playerid, experience)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsScoreInfo[playerid][p_EXPERIENCE] = experience;
    return 1;
}

// ============== DEATHS ACCESSORS ============== //
// Getters
stock Player_GetDeaths(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_DEATHS];
}

// Setters
stock Player_SetDeaths(playerid, deaths)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsScoreInfo[playerid][p_DEATHS] = deaths;
    return 1;
}

// ============== KILLS ACCESSORS ============== //
// Getters
stock Player_GetKills(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_KILLS];
}

// Setters
stock Player_SetKills(playerid, kills)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsScoreInfo[playerid][p_KILLS] = kills;
    return 1;
}

// ============== WANTED LEVEL ACCESSORS ============== //
// Getters
stock Player_GetWantedLevel(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_WANTED_LEVEL];
}

// Setters
stock Player_SetWantedLevel(playerid, level)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }
    
    SetPlayerWantedLevel(playerid, level);
    gsScoreInfo[playerid][p_WANTED_LEVEL] = level;
    return 1;
}

// ============== NOOB ANSERS ACCESSORS ============== //
// Getters
stock Player_GetNoobAnswers(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsScoreInfo[playerid][p_NOOB_ANSWERS];
}

// Setters
stock Player_SetNoobAnswers(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }
    
    gsScoreInfo[playerid][p_NOOB_ANSWERS] = quantity;
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
