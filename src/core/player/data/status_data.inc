#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_STATUS_DATA
{
    p_JAILED,
    p_JAIL_TIME,
    p_HUNGRY,
    p_DRINK,
    p_WARNINGS,
    p_MUTED,
    p_MUTED_NOOB
}
static gsStatusInfo[MAX_PLAYERS][p_STATUS_DATA];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveStatusData(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    new query_string[157];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_JAILED, gsStatusInfo[playerid][p_JAILED],
    PLAYER_FIELD_JAILTIME, gsStatusInfo[playerid][p_JAIL_TIME],
    PLAYER_FIELD_HUNGRY, gsStatusInfo[playerid][p_HUNGRY],
    PLAYER_FIELD_DRINK, gsStatusInfo[playerid][p_DRINK],
    PLAYER_FIELD_WARNINGS, gsStatusInfo[playerid][p_WARNINGS],
    PLAYER_FIELD_MUTED, gsStatusInfo[playerid][p_MUTED],
    PLAYER_FIELD_MUTED_NOOB, gsStatusInfo[playerid][p_MUTED_NOOB],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetStatusData(playerid)
{
    static const scEmptyData[p_STATUS_DATA];
    gsStatusInfo[playerid] = scEmptyData;
    return gsStatusInfo[playerid];
}

// ============== JAIL ACCESSORS ============== //
// Getters
stock Player_GetJailed(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_JAILED];
}

stock Player_GetJailTime(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_JAIL_TIME];
}

// Setters
stock Player_SetJailed(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_JAILED] = value;
}

stock Player_SetJailTime(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_JAIL_TIME] = value;
}

// ============== HUNGRY ACCESSORS ============== //
// Getters
stock Player_GetHungry(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_HUNGRY];
}

// Setters
stock Player_SetHungry(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_HUNGRY] = value;
}

// ============== DRINK ACCESSORS ============== //
// Getters
stock Player_GetDrink(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_DRINK];
}

// Setters
stock Player_SetDrink(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_DRINK] = value;
}

// ============== WARNINGS ACCESSORS ============== //
// Getters
stock Player_GetWarnings(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_WARNINGS];
}

// Setters
stock Player_SetWarnings(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;
    
    return gsStatusInfo[playerid][p_WARNINGS] = value;
}

// ============== MUTED ACCESSORS ============== //
// Getters
stock Player_GetMutedTime(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_MUTED];
}

// Setters
stock Player_SetMutedTime(playerid, time)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_MUTED] = time;
}

// ============== MUTED NOOB ACCESSORS ============== //
// Getters
stock Player_GetNoobMutedTime(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_MUTED_NOOB];
}

// Setters
stock Player_SetNoobMutedTime(playerid, time)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsStatusInfo[playerid][p_MUTED_NOOB] = time;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
