#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pAppearance
{
    pGender,
    pFightStyle,
    pSkin,
    pOldSkin,
}
static Player_AppearanceInfo[MAX_PLAYERS][pAppearance];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== GENDER ACCESSORS ============== //
// Getters
stock PlayerData_GetGender(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_AppearanceInfo[playerid][pGender];
}

// Setters
stock PlayerData_SetGender(playerid, gender)
{
    if (!IsPlayerConnected(playerid)) return false;
    if (gender < 1 || gender > 2) gender = 1;

    return Player_AppearanceInfo[playerid][pGender] = gender;
}

// ============== FIGHT STYLE ACCESSORS ============== //
// Getters
stock PlayerData_GetFightStyle(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_AppearanceInfo[playerid][pFightStyle];
}

// Setters
stock PlayerData_SetFightStyle(playerid, style)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_AppearanceInfo[playerid][pFightStyle] = style;
}

// ============== ACTUAL SKIN ACCESSORS ============== //
// Getters
stock PlayerData_GetSkin(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_AppearanceInfo[playerid][pSkin];
}

// Setters
stock PlayerData_SetSkin(playerid, skinid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_AppearanceInfo[playerid][pSkin] = skinid;
}

// ============== OLD SKIN ACCESSORS ============== //
// Getters
stock PlayerData_GetOldSkin(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_AppearanceInfo[playerid][pOldSkin];
}

// Setters
stock PlayerData_SetOldSkin(playerid, skinid)
{
    if (!IsPlayerConnected(playerid)) return false;
    
    return Player_AppearanceInfo[playerid][pOldSkin] = skinid;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetAppearenceInfo(playerid)
{
    static const empty_data[pAppearance];
    Player_AppearanceInfo[playerid] = empty_data;
    Player_AppearanceInfo[playerid][pGender] = GENDER_MALE;
    Player_AppearanceInfo[playerid][pSkin] = DEFAULT_SKIN;
    return Player_AppearanceInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------