#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pVipInfo
{
    pVip,
    pSocio,
    pVipDays,
}
static Player_VipInfo[MAX_PLAYERS][pVipInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Database_SaveVipInfo(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    inline OnSaveData()
    {
        print("[debug]: Vip data saved.");
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnSaveData, "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME, 
    PLAYER_FIELD_VIP, Player_VipInfo[playerid][pVip], 
    PLAYER_FIELD_SOCIO, Player_VipInfo[playerid][pSocio], 
    PLAYER_FIELD_VIP_DAYS, Player_VipInfo[playerid][pVipDays], 
    PlayerData_GetID(playerid));
    return 1;
}

// ============== VIP ACCESSORS ============== //
// Getters
stock PlayerData_GetVip(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_VipInfo[playerid][pVip];
}

// Setters
stock PlayerData_SetVip(playerid, level)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_VipInfo[playerid][pVip] = level;
}

// ============== SOCIO ACCESSORS ============== //
// Getters
stock PlayerData_GetSocio(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_VipInfo[playerid][pSocio];
}

// Setters
stock PlayerData_SetSocio(playerid, level)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_VipInfo[playerid][pSocio] = level;
}

// ============== VIP DAYS ACCESSORS ============== //
// Getters
stock PlayerData_GetVipDays(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_VipInfo[playerid][pVipDays];
}

// Setters
stock PlayerData_SetVipDays(playerid, days)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_VipInfo[playerid][pVipDays] = days;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetVipInfo(playerid)
{
    static const empty_data[pVipInfo];
    Player_VipInfo[playerid] = empty_data;
    return Player_VipInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
