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
/**
 *  Appearance Player Info
 */
// Player Gender Accessor Function
stock PlayerData_GetGender(playerid)
{
    return Player_AppearanceInfo[playerid][pGender];
}

stock PlayerData_SetGender(playerid, gender)
{
    return Player_AppearanceInfo[playerid][pGender] = gender;
}

// Player Fight Style Accessor Function
stock PlayerData_GetFightStyle(playerid)
{
    return Player_AppearanceInfo[playerid][pFightStyle];
}

stock PlayerData_SetFightStyle(playerid, style)
{
    return Player_AppearanceInfo[playerid][pFightStyle] = style;
}

// Player Actual Skin Accessor Function
stock PlayerData_GetSkin(playerid)
{
    return Player_AppearanceInfo[playerid][pSkin];
}

stock PlayerData_SetSkin(playerid, skinid)
{
    return Player_AppearanceInfo[playerid][pSkin] = skinid;
}

// Player Old Skin Accessor Function
stock PlayerData_GetOldSkin(playerid)
{
    return Player_AppearanceInfo[playerid][pOldSkin];
}

stock PlayerData_SetOldSkin(playerid, skinid)
{
    return Player_AppearanceInfo[playerid][pOldSkin] = skinid;
}

stock PlayerData_ResetAppearenceInfo(playerid)
{
    static const empty_data[pAppearance];
    Player_AppearanceInfo[playerid] = empty_data;
    Player_AppearanceInfo[playerid][pGender] = 1;
    Player_AppearanceInfo[playerid][pSkin] = DEFAULT_SKIN;
    return Player_AppearanceInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------