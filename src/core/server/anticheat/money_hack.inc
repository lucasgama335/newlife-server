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
    new hacked_money = GetPlayerMoney(playerid); 
    if (hacked_money != PlayerData_GetMoney(playerid)) {
        Server_SetPlayerMoney(playerid, PlayerData_GetMoney(playerid));
        new string[MAX_LOG_STRING];
        format(string, sizeof(string), "Anti-Cheat: %s possivelmente usou money hack R$ [%s], ou o seu dinheiro bugou.", Player_GetName(playerid), Server_FormatToMoney((hacked_money - PlayerData_GetMoney(playerid))));
        Server_PrintLog(PASTA_ANTICHEAT_MONEY, string);
    }
    return 1;
}