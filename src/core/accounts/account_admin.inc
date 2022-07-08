#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_ADMIN_DATA
{
    e_ADMIN_LEVELS:p_ADMIN,
    p_ATTENDANCE,
	p_RATING,
	p_NUMBER_RATING
}
static gsAdminInfo[MAX_PLAYERS][p_ADMIN_DATA];

static bool:gsAdminWorkMode[MAX_PLAYERS];
static bool:gsAdminAfkMode[MAX_PLAYERS];
static bool:gsAdminHideMode[MAX_PLAYERS];

static bool:gsAdminViewAllPm[MAX_PLAYERS];
static bool:gsIsAdminFlying[MAX_PLAYERS];
static bool:gsAdminHasBigEars[MAX_PLAYERS];

enum a_SPECTATE
{
    Float:a_POSX,
    Float:a_POSY,
    Float:a_POSZ,
    a_INTERIOR,
    a_VIRTUAL_WORLD
};
static gsSpectateInfo[MAX_PLAYERS][a_SPECTATE];
static bool:gsAdminIsWatchingPlayer[MAX_PLAYERS];
static gsAdminPlayerSpectated[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveAdminData(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    new query_string[123];
    Player_UpdateIp(playerid);
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_ADMIN, gsAdminInfo[playerid][p_ADMIN],
    PLAYER_FIELD_ATTENDANCES, gsAdminInfo[playerid][p_ATTENDANCE],
    PLAYER_FIELD_RATING, gsAdminInfo[playerid][p_RATING],
    PLAYER_FIELD_NUMBERRANTING, gsAdminInfo[playerid][p_NUMBER_RATING],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetAdminData(playerid)
{
    static const empty_data[p_ADMIN_DATA];
    gsAdminInfo[playerid] = empty_data;
    return gsAdminInfo[playerid];
}

// ============== ADMIN ACCESSORS ============== //
// Getters
stock e_ADMIN_LEVELS:Player_GetAdminLevel(playerid)
{
    if (!IsPlayerConnected(playerid)) return NO_ADMIN;

    return gsAdminInfo[playerid][p_ADMIN];
}

stock Player_GetAdminAttendances(playerid)
{
    if (!IsPlayerConnected(playerid)) return NO_ADMIN;

    return gsAdminInfo[playerid][p_ATTENDANCE];
}

stock Player_GetAdminRating(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminInfo[playerid][p_RATING];
}

stock Player_GetAdminNumberRating(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminInfo[playerid][p_NUMBER_RATING];
}

// Setters
stock Player_SetAdminLevel(playerid, e_ADMIN_LEVELS:level, bool:save)
{
    if (!IsPlayerConnected(playerid)) return 0;

    gsAdminInfo[playerid][p_ADMIN] = level;
    if (save) Player_SaveAdminData(playerid);
    return 1;
}

stock Player_SetAdminAttendances(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminInfo[playerid][p_ATTENDANCE] = value;
}

stock Player_SetAdminRating(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminInfo[playerid][p_RATING] = value;
}

stock Player_SetAdminNumberRating(playerid, value)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminInfo[playerid][p_NUMBER_RATING] = value;
}

// ============== WORK MODE ACCESSORS ============== //
// Getters
stock bool:Admin_GetWorkStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminWorkMode[playerid];
}

// Setters
stock bool:Admin_SetWorkStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminWorkMode[playerid] = status;
}

// ============== AFK MODE ACCESSORS ============== //
// Getters
stock bool:Admin_GetAfkStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminAfkMode[playerid];
}

// Setters
stock bool:Admin_SetAfkStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminAfkMode[playerid] = status;
}

// ============== HIDE MODE ACCESSORS ============== //
// Getters
stock bool:Admin_GetHideStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminHideMode[playerid];
}

// Setters
stock bool:Admin_SetHideStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminHideMode[playerid] = status;
}

// ============== VIEW ALL PRIVATE MESSAGES ACCESSORS ============== //
// Getters
stock bool:Admin_GetViewAllPm(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

	return gsAdminViewAllPm[playerid];
}

// Setters
stock bool:Admin_SetViewAllPm(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

	return gsAdminViewAllPm[playerid] = status;
}

// ============== SPECTATE ACCESSORS ============== //
// Getters
stock bool:Admin_GetWatchStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminIsWatchingPlayer[playerid];
}

stock Admin_GetPlayerSpectated(playerid)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminPlayerSpectated[playerid];
}

stock Spectate_GetCoords(playerid, &Float:x, &Float:y, &Float:z, &interior, &world)
{
    if (!IsPlayerConnected(playerid)) return 0;
    
    x = gsSpectateInfo[playerid][a_POSX];
    y = gsSpectateInfo[playerid][a_POSY];
    z = gsSpectateInfo[playerid][a_POSZ];
    interior = gsSpectateInfo[playerid][a_INTERIOR];
    world = gsSpectateInfo[playerid][a_VIRTUAL_WORLD];
    return 1;
}

// Setters
stock bool:Admin_SetWatchStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return gsAdminIsWatchingPlayer[playerid] = status;
}

stock Admin_SetPlayerSpectated(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return 0;

    return gsAdminPlayerSpectated[playerid] = id;
}

stock Spectate_SetCoords(playerid, Float:x, Float:y, Float:z, interior, world)
{
    gsSpectateInfo[playerid][a_POSX] = x;
    gsSpectateInfo[playerid][a_POSY] = y;
    gsSpectateInfo[playerid][a_POSZ] = z;
    gsSpectateInfo[playerid][a_INTERIOR] = interior;
    gsSpectateInfo[playerid][a_VIRTUAL_WORLD] = world;
    return 1;
}

// ============== BIG EARS ACCESSORS ============== //
stock bool:Admin_HasBigEars(playerid)
{
	return gsAdminHasBigEars[playerid];
}

stock Admin_SetBigEars(playerid, bool:status)
{
	gsAdminHasBigEars[playerid] = status;
	return 1;
}

// ============== FLY MODE ACCESSORS ============== //
stock bool:Admin_IsFlying(playerid)
{
	return gsIsAdminFlying[playerid];
}

stock Admin_SetFlying(playerid, bool:status)
{
	gsIsAdminFlying[playerid] = status;
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
