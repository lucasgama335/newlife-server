#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pMoneyInfo
{
    pMoney,
    bool:pBankAccount,
    pBankMoney,
    pSalary,
    pCoins,
}
static Player_MoneyInfo[MAX_PLAYERS][pMoneyInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== MONEY ACCESSORS ============== //
// Getters
stock PlayerData_GetMoney(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pMoney];
}

// Setters
stock PlayerData_SetMoney(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pMoney] = money;
}

// ============== BANK STATUS ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetBankStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pBankAccount];
}

// Setters
stock bool:PlayerData_SetBankStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pBankAccount] = status;
}

// ============== BANK MONEY ACCESSORS ============== //
// Getters
stock PlayerData_GetBankMoney(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pBankMoney];
}

// Setters
stock PlayerData_SetBankMoney(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pBankMoney] = money;
}

// ============== SALARY ACCESSORS ============== //
// Getters
stock PlayerData_GetSalary(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pSalary];
}

// Setters
stock PlayerData_SetSalary(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pSalary] = money;
}

// ============== COINS ACCESSORS ============== //
// Getters
stock PlayerData_GetCoins(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_MoneyInfo[playerid][pCoins];
}

// Setters
stock PlayerData_SetCoins(playerid, coins)
{
    if (!IsPlayerConnected(playerid)) return false;
    
    return Player_MoneyInfo[playerid][pCoins] = coins;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetMoneyInfo(playerid)
{
    static const empty_data[pMoneyInfo];
    return Player_MoneyInfo[playerid] = empty_data;
}

// ============== SAVE DB INFO ============== //
stock Database_SaveMoneyInfo(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    inline OnSaveData()
    {
        print("[debug]: Money data saved.");
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnSaveData, "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME, 
    PLAYER_FIELD_MONEY, Player_MoneyInfo[playerid][pMoney], 
    PLAYER_FIELD_BANK_ACCOUNT, (Player_MoneyInfo[playerid][pBankAccount] ? 1 : 0), 
    PLAYER_FIELD_BANK_MONEY, Player_MoneyInfo[playerid][pBankMoney], 
    PLAYER_FIELD_SALARY, Player_MoneyInfo[playerid][pSalary], 
    PLAYER_FIELD_COINS, Player_MoneyInfo[playerid][pCoins],
    PlayerData_GetID(playerid));
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------