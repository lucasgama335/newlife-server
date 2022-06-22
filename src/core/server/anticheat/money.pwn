#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Server_SetPlayerMoney(playerid, quantity)
{
    ResetPlayerMoney(playerid);
    PlayerData_SetMoney(playerid, quantity);
    GivePlayerMoney(playerid, quantity);
    return quantity;
}

stock Server_ResetPlayerMoney(playerid)
{
    ResetPlayerMoney(playerid);
    PlayerData_SetMoney(playerid, 0);
    GivePlayerMoney(playerid, 0);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerUpdate(playerid)
{
    if (GetPlayerMoney(playerid) != PlayerData_GetMoney(playerid)) {
        Server_SetPlayerMoney(playerid, PlayerData_GetMoney(playerid));
    }
    return 1;
}