#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_LICENSES_DATA
{
    p_CAR_LICENSE,
    p_MOTORCYCLE_LICENSE,
    p_TRUCK_LICENSE,
    p_FLY_LICENSE,
    p_BOAT_LICENSE,
    p_GUN_LICENSE
}
static gsLicensesInfo[MAX_PLAYERS][p_LICENSES_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== RESET INFO ============== //
stock Player_ResetLicensesData(playerid)
{
    static const scEmptyData[p_LICENSES_DATA];
    gsLicensesInfo[playerid] = scEmptyData;
    return 1;
}

// ============== SAVE DB INFO ============== //
stock Player_SaveLicensesData(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    new query_string[158];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_CAR_LICENSE, gsLicensesInfo[playerid][p_CAR_LICENSE],
    PLAYER_FIELD_MOTORCYCLE_LICENSE, gsLicensesInfo[playerid][p_MOTORCYCLE_LICENSE],
    PLAYER_FIELD_TRUCK_LICENSE, gsLicensesInfo[playerid][p_TRUCK_LICENSE],
    PLAYER_FIELD_FLY_LICENSE, gsLicensesInfo[playerid][p_FLY_LICENSE],
    PLAYER_FIELD_BOAT_LICENSE, gsLicensesInfo[playerid][p_BOAT_LICENSE],
    PLAYER_FIELD_GUN_LICENSE, gsLicensesInfo[playerid][p_GUN_LICENSE],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== CAR LICENSE ACCESSORS ============== //
// Getters
stock Player_GetCarLicense(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsLicensesInfo[playerid][p_CAR_LICENSE];
}

// Setters
stock Player_SetCarLicense(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsLicensesInfo[playerid][p_CAR_LICENSE] = quantity;
    return 1;
}

// ============== MOTORCYCLE LICENSE ACCESSORS ============== //
// Getters
stock Player_GetMotorCycleLicense(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsLicensesInfo[playerid][p_MOTORCYCLE_LICENSE];
}

// Setters
stock Player_SetMotorCycleLicense(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsLicensesInfo[playerid][p_MOTORCYCLE_LICENSE] = quantity;
    return 1;
}

// ============== TRUCK LICENSE ACCESSORS ============== //
// Getters
stock Player_GetTruckLicense(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsLicensesInfo[playerid][p_TRUCK_LICENSE];
}

// Setters
stock Player_SetTruckLicense(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsLicensesInfo[playerid][p_TRUCK_LICENSE] = quantity;
    return 1;
}

// ============== FLY LICENSE ACCESSORS ============== //
// Getters
stock Player_GetFlyLicense(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsLicensesInfo[playerid][p_FLY_LICENSE];
}

// Setters
stock Player_SetFlyLicense(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsLicensesInfo[playerid][p_FLY_LICENSE] = quantity;
    return 1;
}

// ============== BOAT LICENSE ACCESSORS ============== //
// Getters
stock Player_GetBoatLicense(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsLicensesInfo[playerid][p_BOAT_LICENSE];
}

// Setters
stock Player_SetBoatLicense(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsLicensesInfo[playerid][p_BOAT_LICENSE] = quantity;
    return 1;
}

// ============== GUN LICENSE ACCESSORS ============== //
// Getters
stock Player_GetGunLicense(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsLicensesInfo[playerid][p_GUN_LICENSE];
}

// Setters
stock Player_SetGunLicense(playerid, quantity)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsLicensesInfo[playerid][p_GUN_LICENSE] = quantity;
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
