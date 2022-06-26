#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:inAnimation[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Player_GetAnimationStatus(playerid)
{
    return inAnimation[playerid];
}

stock bool:Player_SetAnimationStatus(playerid, bool:status)
{
    return inAnimation[playerid] = status;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    inAnimation[playerid] = false;
}

hook OnPlayerSpawn(playerid)
{
    inAnimation[playerid] = false;
}
