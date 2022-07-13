#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_VIP_DATA
{
    p_VIP,
    p_SOCIO,
    p_VIP_DAYS,
}
static gsVipInfo[MAX_PLAYERS][p_VIP_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveVipData(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    new query_string[71];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME, 
    PLAYER_FIELD_VIP, gsVipInfo[playerid][p_VIP], 
    PLAYER_FIELD_SOCIO, gsVipInfo[playerid][p_SOCIO], 
    PLAYER_FIELD_VIP_DAYS, gsVipInfo[playerid][p_VIP_DAYS], 
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetVipData(playerid)
{
    static const scEmptyData[p_VIP_DATA];
    gsVipInfo[playerid] = scEmptyData;
    return gsVipInfo[playerid];
}

// ============== VIP ACCESSORS ============== //
// Getters
stock Player_GetVipLevel(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsVipInfo[playerid][p_VIP];
}

// Setters
stock Player_SetVipLevel(playerid, level)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsVipInfo[playerid][p_VIP] = level;
}

// ============== SOCIO ACCESSORS ============== //
// Getters
stock Player_GetSocioLevel(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsVipInfo[playerid][p_SOCIO];
}

// Setters
stock Player_SetSocioLevel(playerid, level)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsVipInfo[playerid][p_SOCIO] = level;
}

// ============== VIP DAYS ACCESSORS ============== //
// Getters
stock Player_GetVipDays(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsVipInfo[playerid][p_VIP_DAYS];
}

// Setters
stock Player_SetVipDays(playerid, days)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsVipInfo[playerid][p_VIP_DAYS] = days;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
