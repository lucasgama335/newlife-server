#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:workMode[MAX_PLAYERS];
static bool:afkMode[MAX_PLAYERS];
static bool:hideAdmin[MAX_PLAYERS];
static bool:watchingPlayer[MAX_PLAYERS];
static spectatePlayer[MAX_PLAYERS];
static bool:viewAllPars[MAX_PLAYERS];

enum aSpectate
{
	 Float:aPx,
	 Float:aPy,
	 Float:aPz,
	 aInt,
	 aWorld,
};
static SpectateInfo[MAX_PLAYERS][aSpectate];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Admin_IsWorking(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return workMode[playerid];
}

stock bool:Admin_SetWorkMode(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return workMode[playerid] = status;
}

stock bool:Admin_IsAFK(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return afkMode[playerid];
}

stock bool:Admin_SetAfkMode(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return afkMode[playerid] = status;
}

stock bool:Admin_GetHideStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return hideAdmin[playerid];
}

stock bool:Admin_SetHideStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return hideAdmin[playerid] = status;
}

stock bool:Admin_GetWatchStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return watchingPlayer[playerid];
}

stock bool:Admin_SetWatchStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return watchingPlayer[playerid] = status;
}

stock Admin_GetPlayerSpectated(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return spectatePlayer[playerid];
}

stock Admin_SetPlayerSpectated(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return false;

    return spectatePlayer[playerid] = id;
}

stock bool:Admin_GetViewAllPars(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

	return viewAllPars[playerid];
}

stock bool:Admin_SetViewAllPars(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

	return viewAllPars[playerid] = status;
}

stock Spectate_GetCoords(playerid, &Float:x, &Float:y, &Float:z, &interior, &world)
{
    if (!IsPlayerConnected(playerid)) return false;
    
    x = SpectateInfo[playerid][aPx];
    y = SpectateInfo[playerid][aPy];
    z = SpectateInfo[playerid][aPz];
    interior = SpectateInfo[playerid][aInt];
    world = SpectateInfo[playerid][aWorld];
    return 1;
}

stock Spectate_SetCoords(playerid, Float:x, Float:y, Float:z, interior, world)
{
    SpectateInfo[playerid][aPx] = x;
    SpectateInfo[playerid][aPy] = y;
    SpectateInfo[playerid][aPz] = z;
    SpectateInfo[playerid][aInt] = interior;
    SpectateInfo[playerid][aWorld] = world;
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
