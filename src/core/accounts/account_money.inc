#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_MONEY_DATA
{
    p_MONEY,
    p_ILLEGAL_MONEY,
    p_ILLEGAL_SAFE_MONEY,
    bool:p_BANK_ACCOUNT,
    p_BANK_MONEY,
    p_SALARY,
    p_COINS
}
static gsMoneyInfo[MAX_PLAYERS][p_MONEY_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveMoneyData(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    new query_string[193];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME, 
    PLAYER_FIELD_MONEY, gsMoneyInfo[playerid][p_MONEY], 
    PLAYER_FIELD_ILLEGAL_MONEY, gsMoneyInfo[playerid][p_ILLEGAL_MONEY], 
    PLAYER_FIELD_ILLEGAL_SAFE_MONEY, gsMoneyInfo[playerid][p_ILLEGAL_SAFE_MONEY], 
    PLAYER_FIELD_BANK_ACCOUNT, (gsMoneyInfo[playerid][p_BANK_ACCOUNT] ? 1 : 0), 
    PLAYER_FIELD_BANK_MONEY, gsMoneyInfo[playerid][p_BANK_MONEY], 
    PLAYER_FIELD_SALARY, gsMoneyInfo[playerid][p_SALARY], 
    PLAYER_FIELD_COINS, gsMoneyInfo[playerid][p_COINS],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetMoneyData(playerid)
{
    static const scEmptyData[p_MONEY_DATA];
    return gsMoneyInfo[playerid] = scEmptyData;
}

// ============== MONEY ACCESSORS ============== //
// Getters
stock Player_GetMoney(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_MONEY];
}

// Setters
stock Player_SetMoney(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return 0;

    gsMoneyInfo[playerid][p_MONEY] = money;
    if (Player_GetLoggedStatus(playerid))
    {
        Player_SaveMoneyData(playerid);
    }
    return 1;
}

// ============== ILLEGAL MONEY ACCESSORS ============== //
// Getters
stock Player_GetIllegalMoney(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_ILLEGAL_MONEY];
}

stock Player_GetIllegalSafeMoney(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_ILLEGAL_SAFE_MONEY];
}

// Setters
stock Player_SetIllegalMoney(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_ILLEGAL_MONEY] = money;
}

stock Player_SetIllegalSafeMoney(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_ILLEGAL_SAFE_MONEY] = money;
}

// ============== BANK STATUS ACCESSORS ============== //
// Getters
stock bool:Player_GetBankStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsMoneyInfo[playerid][p_BANK_ACCOUNT];
}

// Setters
stock bool:Player_SetBankStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsMoneyInfo[playerid][p_BANK_ACCOUNT] = status;
}

// ============== BANK MONEY ACCESSORS ============== //
// Getters
stock Player_GetBankMoney(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_BANK_MONEY];
}

// Setters
stock Player_SetBankMoney(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_BANK_MONEY] = money;
}

// ============== SALARY ACCESSORS ============== //
// Getters
stock Player_GetSalary(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_SALARY];
}

// Setters
stock Player_SetSalary(playerid, money)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_SALARY] = money;
}

// ============== COINS ACCESSORS ============== //
// Getters
stock Player_GetCoins(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsMoneyInfo[playerid][p_COINS];
}

// Setters
stock Player_SetCoins(playerid, coins)
{
    if (!IsPlayerConnected(playerid)) return 0;
    
    return gsMoneyInfo[playerid][p_COINS] = coins;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
