#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_BAN_DATA
{
    p_BAN_ID,
    p_PLAYER_ID,
    p_ADMIN_ID,
    p_ADMIN_NAME[MAX_PLAYER_NAME],
    p_PLAYER_IP[MAX_IP_STRING],
    Timestamp:p_BAN_TIME,
    Timestamp:p_UNBAN_TIME,
    bool:p_BAN_FOREVER,
    p_REASON[MAX_REASON_STRING]    
}
static gsBanInfo[MAX_PLAYERS][p_BAN_DATA];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveBanData(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetBanData(playerid)
{
    static const scEmptyData[p_BAN_DATA];
    gsBanInfo[playerid] = scEmptyData;
    gsBanInfo[playerid][p_BAN_ID] = INVALID_VALUE;
    gsBanInfo[playerid][p_REASON] = EOS;
    gsBanInfo[playerid][p_ADMIN_NAME] = EOS;
    gsBanInfo[playerid][p_BAN_FOREVER] = false;
    return gsBanInfo[playerid];
}

// ============== BAN STATUS INFO ============== //
// Getters
stock Player_GetBanId(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsBanInfo[playerid][p_BAN_ID];
}

// Setters
stock Player_SetBanId(playerid, banId)
{
    if (!IsPlayerConnected(playerid)) return false;

    gsBanInfo[playerid][p_BAN_ID] = banId;
    return 1;
}

// ============== PLAYER INFO ============== //
// Getters
stock Player_GetBanPlayerId(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsBanInfo[playerid][p_PLAYER_ID];
}

// Setters
stock Player_SetBanPlayerId(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return 0;

    gsBanInfo[playerid][p_PLAYER_ID] = id;
    return 1;
}

// ============== ADMIN INFO ============== //
// Getters
stock Player_GetBanAdminId(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsBanInfo[playerid][p_ADMIN_ID];
}

stock Player_GetBanAdminName(playerid)
{
    new string[MAX_PLAYER_NAME + 1];
    format(string, sizeof(string), "%s", gsBanInfo[playerid][p_ADMIN_NAME]);
    return string;
}

// Setters
stock Player_SetBanAdminId(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return 0;

    gsBanInfo[playerid][p_ADMIN_ID] = id;
    return 1;
}

stock Player_SetBanAdminName(playerid, const string[])
{
    if (!IsPlayerConnected(playerid)) return 0;

    format(gsBanInfo[playerid][p_ADMIN_NAME], (MAX_PLAYER_NAME + 1), "%s", string);
    return 1;
}

// ============== IP INFO ============== //
// Getters
stock Player_GetBanIp(playerid)
{
    new string[MAX_IP_STRING];
    format(string, sizeof(string), "%s", gsBanInfo[playerid][p_PLAYER_IP]);
    return string;
}

// Setters
stock Player_SetBanIp(playerid, const ip[])
{
    if (!IsPlayerConnected(playerid)) return 0;

    format(gsBanInfo[playerid][p_PLAYER_IP], MAX_IP_STRING, "%s", ip);
    return 1;
}

// ============== BAN INFO ============== //
// Getters
stock Timestamp:Player_GetBanTime(playerid)
{
    return gsBanInfo[playerid][p_BAN_TIME];
}

stock Timestamp:Player_GetUnBanTime(playerid)
{
    return gsBanInfo[playerid][p_UNBAN_TIME];
}

stock bool:Player_GetBanForeverStatus(playerid)
{
    return gsBanInfo[playerid][p_BAN_FOREVER];
}

// Setters
stock Player_SetBanTime(playerid, Timestamp:time)
{
    gsBanInfo[playerid][p_BAN_TIME] = time;
    return 1;
}

stock Player_SetUnBanTime(playerid, Timestamp:time)
{
    gsBanInfo[playerid][p_UNBAN_TIME] = time;
    return 1;
}

stock Player_SetBanForeverStatus(playerid, bool:time)
{
    gsBanInfo[playerid][p_BAN_FOREVER] = time;
    return 1;
}

// ============== REASON INFO ============== //
stock Player_GetBanReason(playerid)
{
    new string[MAX_REASON_STRING];
    format(string, MAX_REASON_STRING, "%s", gsBanInfo[playerid][p_REASON]);
    return string;
}

// Setters
stock Player_SetBanReason(playerid, const reason[])
{
    if (!IsPlayerConnected(playerid)) return 0;

    format(gsBanInfo[playerid][p_REASON], MAX_REASON_STRING, "%s", reason);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------