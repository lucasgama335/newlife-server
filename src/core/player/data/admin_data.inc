#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:gsAdminWorkMode[MAX_PLAYERS];
static bool:gsAdminAfkMode[MAX_PLAYERS];
static bool:gsAdminHideMode[MAX_PLAYERS];

static bool:gsAdminViewAllPm[MAX_PLAYERS];

enum a_SPECTATE
{
    Float:a_POSX,
    Float:a_POSY,
    Float:a_POSZ,
    a_INTERIOR,
    a_VIRTUAL_WORLD
};
static gsSpectateInfo[MAX_PLAYERS][a_SPECTATE];
static bool:gsAdminIsWatchingPlayer[MAX_PLAYERS];
static gsAdminPlayerSpectated[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Admin_GetWorkStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminWorkMode[playerid];
}

stock bool:Admin_SetWorkStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminWorkMode[playerid] = status;
}

stock bool:Admin_GetAfkStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminAfkMode[playerid];
}

stock bool:Admin_SetAfkStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminAfkMode[playerid] = status;
}

stock bool:Admin_GetHideStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminHideMode[playerid];
}

stock bool:Admin_SetHideStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminHideMode[playerid] = status;
}

stock bool:Admin_GetViewAllPm(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

	return gsAdminViewAllPm[playerid];
}

stock bool:Admin_SetViewAllPm(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

	return gsAdminViewAllPm[playerid] = status;
}

stock bool:Admin_GetWatchStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminIsWatchingPlayer[playerid];
}

stock bool:Admin_SetWatchStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminIsWatchingPlayer[playerid] = status;
}

stock Admin_GetPlayerSpectated(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminPlayerSpectated[playerid];
}

stock Admin_SetPlayerSpectated(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminPlayerSpectated[playerid] = id;
}

stock Spectate_GetCoords(playerid, &Float:x, &Float:y, &Float:z, &interior, &world)
{
    if (!IsPlayerConnected(playerid)) return 0;
    
    x = gsSpectateInfo[playerid][a_POSX];
    y = gsSpectateInfo[playerid][a_POSY];
    z = gsSpectateInfo[playerid][a_POSZ];
    interior = gsSpectateInfo[playerid][a_INTERIOR];
    world = gsSpectateInfo[playerid][a_VIRTUAL_WORLD];
    return 1;
}

stock Spectate_SetCoords(playerid, Float:x, Float:y, Float:z, interior, world)
{
    gsSpectateInfo[playerid][a_POSX] = x;
    gsSpectateInfo[playerid][a_POSY] = y;
    gsSpectateInfo[playerid][a_POSZ] = z;
    gsSpectateInfo[playerid][a_INTERIOR] = interior;
    gsSpectateInfo[playerid][a_VIRTUAL_WORLD] = world;
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
