#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:workMode[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Admin_IsWorking(playerid)
{
    return workMode[playerid];
}

stock bool:Admin_ChangeWorkMode(playerid)
{
    if (workMode[playerid] == true) workMode[playerid] = false;
    else workMode[playerid] = true;

    return workMode[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
