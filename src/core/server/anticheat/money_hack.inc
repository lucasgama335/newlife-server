#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerUpdate(playerid)
{
    if (Player_GetLoggedStatus(playerid)) 
    {
        new hacked_money = GetPlayerMoney(playerid); 
        if (hacked_money != Player_GetMoney(playerid))
        {
            new moneyString[MAX_MONEY_STRING];
            FormatMoneyString((hacked_money - Player_GetMoney(playerid)), moneyString);
            Player_SetMoney(playerid, Player_GetMoney(playerid));
            new string[MAX_LOG_STRING];
            format(string, sizeof(string), "Anti-Cheat: %s possivelmente usou money hack R$ [%s], ou o seu dinheiro bugou.", GetPlayerNameCustom(playerid), moneyString);
            PrintLog(FOLDER_ANTICHEAT_MONEY, string);
        }
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
