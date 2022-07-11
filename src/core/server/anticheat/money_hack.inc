#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock SetPlayerMoneyCustom(playerid, quantity)
{
    ResetPlayerMoney(playerid);
    Player_SetMoney(playerid, quantity);
    GivePlayerMoney(playerid, Player_GetMoney(playerid));
    Player_SaveMoneyData(playerid);
    return quantity;
}

stock ResetPlayerMoneyCustom(playerid)
{
    ResetPlayerMoney(playerid);
    Player_SetMoney(playerid, 0);
    GivePlayerMoney(playerid, 0);
    Player_SaveMoneyData(playerid);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

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
            SetPlayerMoneyCustom(playerid, Player_GetMoney(playerid));
            new string[MAX_LOG_STRING];
            format(string, sizeof(string), "Anti-Cheat: %s possivelmente usou money hack R$ [%s], ou o seu dinheiro bugou.", GetPlayerNameCustom(playerid), moneyString);
            PrintLog(FOLDER_ANTICHEAT_MONEY, string);
        }
    }
    return 1;
}
