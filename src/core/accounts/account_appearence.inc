#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_APPEARANCE_DATA
{
    p_GENDER,
    p_FIGHT_STYLE,
    p_SKIN,
    p_OLD_SKIN
}
static gsAppearanceInfo[MAX_PLAYERS][p_APPEARANCE_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveAppearenceData(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    new query_string[90];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_GENDER, gsAppearanceInfo[playerid][p_GENDER],
    PLAYER_FIELD_FIGHT_STYLE, gsAppearanceInfo[playerid][p_FIGHT_STYLE],
    PLAYER_FIELD_SKIN, gsAppearanceInfo[playerid][p_SKIN],
    PLAYER_FIELD_OLDSKIN, gsAppearanceInfo[playerid][p_OLD_SKIN],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetAppearenceData(playerid)
{
    static const scEmptyData[p_APPEARANCE_DATA];
    gsAppearanceInfo[playerid] = scEmptyData;
    gsAppearanceInfo[playerid][p_GENDER] = GENDER_MALE;
    gsAppearanceInfo[playerid][p_SKIN] = DEFAULT_SKIN_MALE;
    return 1;
}

// ============== GENDER ACCESSORS ============== //
// Getters
stock Player_GetGender(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsAppearanceInfo[playerid][p_GENDER];
}

// Setters
stock Player_SetGender(playerid, gender)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }
    if (gender < 1 || gender > 2) 
    {
        return 0;
    }

    gsAppearanceInfo[playerid][p_GENDER] = gender;
    return 1;
}

// ============== FIGHT STYLE ACCESSORS ============== //
// Getters
stock Player_GetFightStyle(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }
    
    return gsAppearanceInfo[playerid][p_FIGHT_STYLE];
}

// Setters
stock Player_SetFightStyle(playerid, style)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsAppearanceInfo[playerid][p_FIGHT_STYLE] = style;
    switch(gsAppearanceInfo[playerid][p_FIGHT_STYLE])
    {
        case 0: SetPlayerFightingStyle(playerid, FIGHT_STYLE_NORMAL);
        case 1: SetPlayerFightingStyle(playerid, FIGHT_STYLE_BOXING);
        case 2: SetPlayerFightingStyle(playerid, FIGHT_STYLE_KUNGFU);
        case 3: SetPlayerFightingStyle(playerid, FIGHT_STYLE_KNEEHEAD);
        case 4: SetPlayerFightingStyle(playerid, FIGHT_STYLE_GRABKICK);
        case 5: SetPlayerFightingStyle(playerid, FIGHT_STYLE_ELBOW);
        default: SetPlayerFightingStyle(playerid, FIGHT_STYLE_NORMAL);
    }
    return 1;
}

// ============== ACTUAL SKIN ACCESSORS ============== //
// Getters
stock Player_GetSkin(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsAppearanceInfo[playerid][p_SKIN];
}

// Setters
stock Player_SetSkin(playerid, skinId)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsAppearanceInfo[playerid][p_SKIN] = skinId;
    return 1;
}

// ============== OLD SKIN ACCESSORS ============== //
// Getters
stock Player_GetOldSkin(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsAppearanceInfo[playerid][p_OLD_SKIN];
}

// Setters
stock Player_SetOldSkin(playerid, skinId)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }
    
    gsAppearanceInfo[playerid][p_OLD_SKIN] = skinId;
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
