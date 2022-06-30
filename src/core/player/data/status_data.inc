#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pStatusInfo
{
    pJailed,
    pJailTime,
    pHungry,
    pDrink,
    pWarnings,
}
static Player_StatusInfo[MAX_PLAYERS][pStatusInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Database_SaveStatusInfo(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    new query_string[107 + 1];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_JAILED, Player_StatusInfo[playerid][pJailed],
    PLAYER_FIELD_JAILTIME, Player_StatusInfo[playerid][pJailTime],
    PLAYER_FIELD_HUNGRY, Player_StatusInfo[playerid][pHungry],
    PLAYER_FIELD_DRINK, Player_StatusInfo[playerid][pDrink],
    PLAYER_FIELD_WARNINGS, Player_StatusInfo[playerid][pWarnings],
    PlayerData_GetID(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== JAIL ACCESSORS ============== //
// Getters
stock PlayerData_GetJailed(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pJailed];
}

stock PlayerData_GetJailTime(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pJailTime];
}

// Setters
stock PlayerData_SetJailed(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pJailed] = value;
}

stock PlayerData_SetJailTime(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pJailTime] = value;
}

// ============== HUNGRY ACCESSORS ============== //
// Getters
stock PlayerData_GetHungry(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pHungry];
}

// Setters
stock PlayerData_SetHungry(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pHungry] = value;
}

// ============== DRINK ACCESSORS ============== //
// Getters
stock PlayerData_GetDrink(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pDrink];
}

// Setters
stock PlayerData_SetDrink(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pDrink] = value;
}

// ============== WARNINGS ACCESSORS ============== //
// Getters
stock PlayerData_GetWarnings(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_StatusInfo[playerid][pWarnings];
}

// Setters
stock PlayerData_SetWarnings(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return false;
    
    return Player_StatusInfo[playerid][pWarnings] = value;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetStatusInfo(playerid)
{
    static const empty_data[pStatusInfo];
    Player_StatusInfo[playerid] = empty_data;
    return Player_StatusInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
