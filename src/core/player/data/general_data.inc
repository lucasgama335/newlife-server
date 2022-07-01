#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_GENERAL_DATA
{
    p_ID,
    e_ADMIN_LEVELS:p_ADMIN,
    p_ATTENDANCE,
	p_RATING,
	p_NUMBER_RATING,
    bool:p_TUTORIAL,
    p_LAST_LOGIN_TIME,
    p_LAST_CONNECTED_TIME,
    Float:p_LAST_POSX,
    Float:p_LAST_POSY,
    Float:p_LAST_POSZ,
    Float:p_LAST_POSA,
    p_LAST_INTERIOR,
    e_INTERIOR_LOCALES:p_LAST_INTERIOR_LOCALE,
    p_LAST_VIRTUAL_WORLD
}
static gsGeneralInfo[MAX_PLAYERS][p_GENERAL_DATA];

static bool:gsPlayerIsUsingAndroid[MAX_PLAYERS];
static bool:gsPlayerIsLogged[MAX_PLAYERS];
static Timestamp:gsLastLoginTimeTemp[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveGeneralData(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    new query_string[394];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %f, %s = %f, %s = %f, %s = %f, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_ADMIN, gsGeneralInfo[playerid][p_ADMIN],
    PLAYER_FIELD_ATTENDANCES, gsGeneralInfo[playerid][p_ATTENDANCE],
    PLAYER_FIELD_RATING, gsGeneralInfo[playerid][p_RATING],
    PLAYER_FIELD_NUMBERRANTING, gsGeneralInfo[playerid][p_NUMBER_RATING],
    PLAYER_FIELD_TUTORIAL, (gsGeneralInfo[playerid][p_TUTORIAL] == true ? 1 : 0),
    PLAYER_FIELD_LAST_LOGIN, gsGeneralInfo[playerid][p_LAST_LOGIN_TIME],
    PLAYER_FIELD_LAST_CONNECTED_TIME, gsGeneralInfo[playerid][p_LAST_CONNECTED_TIME],
    PLAYER_FIELD_LAST_POSX, gsGeneralInfo[playerid][p_LAST_POSX],
    PLAYER_FIELD_LAST_POSY, gsGeneralInfo[playerid][p_LAST_POSY],
    PLAYER_FIELD_LAST_POSZ, gsGeneralInfo[playerid][p_LAST_POSZ],
    PLAYER_FIELD_LAST_POSA, gsGeneralInfo[playerid][p_LAST_POSA],
    PLAYER_FIELD_LAST_INTERIOR, gsGeneralInfo[playerid][p_LAST_INTERIOR],
    PLAYER_FIELD_LAST_VW, gsGeneralInfo[playerid][p_LAST_VIRTUAL_WORLD],
    PLAYER_FIELD_LAST_LOCALE, gsGeneralInfo[playerid][p_LAST_INTERIOR_LOCALE],
    gsGeneralInfo[playerid][p_ID]);
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetGeneralData(playerid)
{
    static const empty_data[p_GENERAL_DATA];
    gsGeneralInfo[playerid] = empty_data;
    gsGeneralInfo[playerid][p_LAST_POSX] = SPAWN_POSX;
    gsGeneralInfo[playerid][p_LAST_POSY] = SPAWN_POSY;
    gsGeneralInfo[playerid][p_LAST_POSZ] = SPAWN_POSZ;
    gsGeneralInfo[playerid][p_LAST_POSA] = SPAWN_POSA;
    gsGeneralInfo[playerid][p_LAST_INTERIOR] = SPAWN_INTERIOR;
    gsGeneralInfo[playerid][p_LAST_VIRTUAL_WORLD] = SPAWN_VW;
    return gsGeneralInfo[playerid];
}

// ============== ID ACCESSORS ============== //
// Getters
stock Player_GetId(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_ID];
}

// Setters
stock Player_SetId(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_ID] = id;
}

// ============== ADMIN ACCESSORS ============== //
// Getters
stock e_ADMIN_LEVELS:Player_GetAdminLevel(playerid)
{
    if (!IsPlayerConnected(playerid)) return NO_ADMIN;

    return gsGeneralInfo[playerid][p_ADMIN];
}

stock Player_GetAdminAttendances(playerid)
{
    if (!IsPlayerConnected(playerid)) return NO_ADMIN;

    return gsGeneralInfo[playerid][p_ATTENDANCE];
}

stock Player_GetAdminRating(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_RATING];
}

stock Player_GetAdminNumberRating(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_NUMBER_RATING];
}

// Setters
stock Player_SetAdminLevel(playerid, e_ADMIN_LEVELS:level, bool:save)
{
    if (!IsPlayerConnected(playerid)) return 0;

    gsGeneralInfo[playerid][p_ADMIN] = level;
    if (save) Player_SaveGeneralData(playerid);
    return 1;
}

stock Player_SetAdminAttendances(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_ATTENDANCE] = value;
}

stock Player_SetAdminRating(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_RATING] = value;
}

stock Player_SetAdminNumberRating(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_NUMBER_RATING] = value;
}

// ============== TUTORIAL ACCESSORS ============== //
// Getters
stock bool:Player_GetTutorialStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsGeneralInfo[playerid][p_TUTORIAL];
}

// Setters
stock bool:Player_SetTutorialStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsGeneralInfo[playerid][p_TUTORIAL] = status;
}

// ============== LAST LOGIN ACCESSORS ============== //
// Getters
stock Player_GetLastLoginFormated(playerid)
{
    new date[20];
    if (gsGeneralInfo[playerid][p_LAST_LOGIN_TIME] == 0)
    {
        format(date, sizeof(date), "%s", Chrono_GetFullDate(Chrono_GetTimeNow()));
    }
    else
    {
        format(date, sizeof(date), "%s", Chrono_GetFullDate(Chrono_ConvertToTimestamp(gsGeneralInfo[playerid][p_LAST_LOGIN_TIME])));
    }
    return date;
}

stock Timestamp:Player_GetLastLoginTemp(playerid)
{
    return gsLastLoginTimeTemp[playerid];
}

stock Player_GetLastConnectedTime(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_LAST_CONNECTED_TIME];
}

// Setters
stock Player_SetLastLogin(playerid, Timestamp:timestamp)
{
    if (!IsPlayerConnected(playerid)) return 0;
    gsGeneralInfo[playerid][p_LAST_LOGIN_TIME] = Chrono_ConvertToInt(timestamp);
    return 1;
}

stock Player_UpdateLastLoginTemp(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;
    gsLastLoginTimeTemp[playerid] = Chrono_GetTimeNow();
    return 1;
}

stock Player_SetLastConnectedTime(playerid, timestamp)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsGeneralInfo[playerid][p_LAST_CONNECTED_TIME] = timestamp;
}

// ============== LAST POSITION ACCESSORS ============== //
// Getters
stock Player_GetLastPosition(playerid, &Float:x, &Float:y, &Float:z, &interior, &vW)
{
    if (!IsPlayerConnected(playerid)) return 0;

    x = gsGeneralInfo[playerid][p_LAST_POSX];
    y = gsGeneralInfo[playerid][p_LAST_POSY];
    z = gsGeneralInfo[playerid][p_LAST_POSZ];
    interior = gsGeneralInfo[playerid][p_LAST_INTERIOR];
    vW = gsGeneralInfo[playerid][p_LAST_VIRTUAL_WORLD];
    return 1;
}

stock Player_GetLastPosAngle(playerid, &Float:a)
{
    if (!IsPlayerConnected(playerid)) return 0;

    a = gsGeneralInfo[playerid][p_LAST_POSA];
    return 1;
}

// Setters
stock Player_SetLastPosition(playerid, Float:setX, Float:setY, Float:setZ, Float:setA, interiorId, vW)
{
    if (!IsPlayerConnected(playerid)) return 0;

    gsGeneralInfo[playerid][p_LAST_INTERIOR] = interiorId;
    gsGeneralInfo[playerid][p_LAST_VIRTUAL_WORLD] = vW;
    gsGeneralInfo[playerid][p_LAST_POSX] = setX;
    gsGeneralInfo[playerid][p_LAST_POSY] = setY;
    gsGeneralInfo[playerid][p_LAST_POSZ] = setZ;
    gsGeneralInfo[playerid][p_LAST_POSA] = setA;
    return 1;
}

stock Player_UpdateLastPosition(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    new Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a;
    GetPlayerPos(playerid, pos_x, pos_y, pos_z);
    GetPlayerFacingAngle(playerid, pos_a);
    gsGeneralInfo[playerid][p_LAST_INTERIOR] = GetPlayerInterior(playerid);
    gsGeneralInfo[playerid][p_LAST_VIRTUAL_WORLD] = GetPlayerVirtualWorld(playerid);
    gsGeneralInfo[playerid][p_LAST_POSX] = pos_x;
    gsGeneralInfo[playerid][p_LAST_POSY] = pos_y;
    gsGeneralInfo[playerid][p_LAST_POSZ] = pos_z;
    gsGeneralInfo[playerid][p_LAST_POSA] = pos_a;
    return 1;
}

// ============== INTERIOR LOCALE ACCESSORS ============== //
// Getters
stock e_INTERIOR_LOCALES:Player_GetInteriorLocale(playerid)
{
    if (!IsPlayerConnected(playerid)) return NO_INTERIOR;

    return gsGeneralInfo[playerid][p_LAST_INTERIOR_LOCALE];
}

// Setters
stock e_INTERIOR_LOCALES:Player_SetInteriorLocale(playerid, e_INTERIOR_LOCALES:interiorId)
{
    if (!IsPlayerConnected(playerid)) return NO_INTERIOR;

    return gsGeneralInfo[playerid][p_LAST_INTERIOR_LOCALE] = interiorId;
}

// ============== TEMPORARY ACCESSORS ============== //
stock bool:Player_GetUsingAndroidStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsPlayerIsUsingAndroid[playerid];
}

stock bool:Player_GetLoggedStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsPlayerIsLogged[playerid];
}

stock bool:Player_SetUsingAndroidStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsPlayerIsLogged[playerid] = status;
}

stock bool:Player_SetLoggedStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;
    
    return gsPlayerIsLogged[playerid] = status;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
