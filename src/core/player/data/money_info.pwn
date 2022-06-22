#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pMoneyInfo
{
    pMoney,
    bool:pBankAccount,
    pBankMoney,
    pCoins,
}
static Player_MoneyInfo[MAX_PLAYERS][pMoneyInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
/**
 *  Money Player Info
 */
// Player Money Accessor Function
stock PlayerData_GetMoney(playerid)
{
    return Player_MoneyInfo[playerid][pMoney];
}

stock PlayerData_SetMoney(playerid, money)
{
    return Player_MoneyInfo[playerid][pMoney] = money;
}

// Player Bank Status Accessor Function
stock bool:PlayerData_GetBankStatus(playerid)
{
    return Player_MoneyInfo[playerid][pBankAccount];
}

stock bool:PlayerData_SetBankStatus(playerid, bool:status)
{
    return Player_MoneyInfo[playerid][pBankAccount] = status;
}

// Player Bank Money Accessor Function
stock PlayerData_GetBankMoney(playerid)
{
    return Player_MoneyInfo[playerid][pBankMoney];
}

stock PlayerData_SetBankMoney(playerid, money)
{
    return Player_MoneyInfo[playerid][pBankMoney] = money;
}

stock PlayerData_ResetMoneyInfo(playerid)
{
    static const empty_data[pMoneyInfo];
    return Player_MoneyInfo[playerid] = empty_data;
}

// Player Coins Accessor Function
stock PlayerData_GetCoins(playerid)
{
    return Player_MoneyInfo[playerid][pCoins];
}

stock PlayerData_SetCoins(playerid, coins)
{
    return Player_MoneyInfo[playerid][pCoins] = coins;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
