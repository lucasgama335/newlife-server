#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:gsPlayerIsInAnimation[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Player_GetAnimationStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }
    return gsPlayerIsInAnimation[playerid];
}

stock bool:Player_SetAnimationStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }
    return gsPlayerIsInAnimation[playerid] = status;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsPlayerIsInAnimation[playerid] = false;
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    gsPlayerIsInAnimation[playerid] = false;
    return 1;
}
