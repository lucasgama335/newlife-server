#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pGeneralInfo
{
    pId,
    pAdmin,
    pJob,
    pOrg,
    pOrgRole,
    bool:pTutorial,
    pLastLoginDate,
    pLastLoginHour,
    pLastConnectedTime,
    Float:pLastPosX,
    Float:pLastPosY,
    Float:pLastPosZ,
    Float:pLastPosA,
    pLastInterior,
    pLastInteriorLocale,
    pLastVw,
}
static Player_GeneralInfo[MAX_PLAYERS][pGeneralInfo];
static bool:isUsingAndroid[MAX_PLAYERS];
static bool:isLogged[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Database_SaveGeneralInfo(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    new query_string[381];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %f, %s = %f, %s = %f, %s = %f, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_ADMIN, Player_GeneralInfo[playerid][pAdmin],
    PLAYER_FIELD_JOB, Player_GeneralInfo[playerid][pJob],
    PLAYER_FIELD_ORG, Player_GeneralInfo[playerid][pOrg],
    PLAYER_FIELD_ORG_ROLE, Player_GeneralInfo[playerid][pOrgRole],
    PLAYER_FIELD_TUTORIAL, (Player_GeneralInfo[playerid][pTutorial] == true ? 1 : 0),
    PLAYER_FIELD_LAST_LOGIN_DATE, Player_GeneralInfo[playerid][pLastLoginDate],
    PLAYER_FIELD_LAST_LOGIN_HOUR, Player_GeneralInfo[playerid][pLastLoginHour],
    PLAYER_FIELD_LAST_CONNECTED_TIME, Player_GeneralInfo[playerid][pLastConnectedTime],
    PLAYER_FIELD_LAST_POSX, Player_GeneralInfo[playerid][pLastPosX],
    PLAYER_FIELD_LAST_POSY, Player_GeneralInfo[playerid][pLastPosY],
    PLAYER_FIELD_LAST_POSZ, Player_GeneralInfo[playerid][pLastPosZ],
    PLAYER_FIELD_LAST_POSA, Player_GeneralInfo[playerid][pLastPosA],
    PLAYER_FIELD_LAST_INTERIOR, Player_GeneralInfo[playerid][pLastInterior],
    PLAYER_FIELD_LAST_VW, Player_GeneralInfo[playerid][pLastVw],
    PLAYER_FIELD_LAST_LOCALE, Player_GeneralInfo[playerid][pLastInteriorLocale],
    Player_GeneralInfo[playerid][pId]);
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== ID ACCESSORS ============== //
// Getters
stock PlayerData_GetID(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pId];
}

// Setters
stock PlayerData_SetID(playerid, id)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pId] = id;
}

// ============== ADMIN ACCESSORS ============== //
// Getters
stock PlayerData_GetAdmin(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pAdmin];
}

// Setters
stock PlayerData_SetAdmin(playerid, level, bool:save)
{
    if (!IsPlayerConnected(playerid)) return false;

    Player_GeneralInfo[playerid][pAdmin] = level;
    if (save) Database_SaveGeneralInfo(playerid);
    return 1;
}

// ============== JOB ACCESSORS ============== //
// Getters
stock PlayerData_GetJob(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pJob];
}

// Setters
stock PlayerData_SetJob(playerid, jobid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pJob] = jobid;
}

// ============== ORG ACCESSORS ============== //
// Getters
stock PlayerData_GetOrg(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pOrg];
}

stock PlayerData_GetOrgRole(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pOrgRole];
}

// Setters
stock PlayerData_SetOrg(playerid, orgid, role)
{
    if (!IsPlayerConnected(playerid)) return false;

    Player_GeneralInfo[playerid][pOrg] = orgid;
    Player_GeneralInfo[playerid][pOrgRole] = role;
    return 1;
}

// ============== TUTORIAL ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetTutorial(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pTutorial];
}

// Setters
stock bool:PlayerData_SetTutorial(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pTutorial] = status;
}

// ============== LAST LOGIN ACCESSORS ============== //
// Getters

// Setters
stock PlayerData_SetLastLoginDate(playerid, timestamp)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pLastLoginDate] = timestamp;
}

stock PlayerData_SetLastLoginHour(playerid, timestamp)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pLastLoginHour] = timestamp;
}

stock PlayerData_SetLastConnectedTime(playerid, time)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pLastConnectedTime] = time;
}

// ============== LAST POSITION ACCESSORS ============== //
// Getters
stock Player_GetLastPosition(playerid, &Float:x, &Float:y, &Float:z, &interior, &vw)
{
    if (!IsPlayerConnected(playerid)) return false;

    x = Player_GeneralInfo[playerid][pLastPosX];
    y = Player_GeneralInfo[playerid][pLastPosY];
    z = Player_GeneralInfo[playerid][pLastPosZ];
    interior = Player_GeneralInfo[playerid][pLastInterior];
    vw = Player_GeneralInfo[playerid][pLastVw];
    return 1;
}

stock PlayerData_GetLastPosAngle(playerid, &Float:a)
{
    if (!IsPlayerConnected(playerid)) return false;

    a = Player_GeneralInfo[playerid][pLastPosA];
    return 1;
}

// Setters
stock PlayerData_SetLastPosition(playerid, Float:setX, Float:setY, Float:setZ, Float:setA, interiorid, vw)
{
    if (!IsPlayerConnected(playerid)) return false;

    Player_GeneralInfo[playerid][pLastInterior] = interiorid;
    Player_GeneralInfo[playerid][pLastVw] = vw;
    Player_GeneralInfo[playerid][pLastPosX] = setX;
    Player_GeneralInfo[playerid][pLastPosY] = setY;
    Player_GeneralInfo[playerid][pLastPosZ] = setZ;
    Player_GeneralInfo[playerid][pLastPosA] = setA;
    return 1;
}

stock PlayerData_UpdateLastPosition(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    new Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a;
    GetPlayerPos(playerid, pos_x, pos_y, pos_z);
    GetPlayerFacingAngle(playerid, pos_a);
    Player_GeneralInfo[playerid][pLastInterior] = GetPlayerInterior(playerid);
    Player_GeneralInfo[playerid][pLastVw] = GetPlayerVirtualWorld(playerid);
    Player_GeneralInfo[playerid][pLastPosX] = pos_x;
    Player_GeneralInfo[playerid][pLastPosY] = pos_y;
    Player_GeneralInfo[playerid][pLastPosZ] = pos_z;
    Player_GeneralInfo[playerid][pLastPosA] = pos_a;
    return 1;
}

// ============== INTERIOR LOCALE ACCESSORS ============== //
// Getters
stock PlayerData_GetInteriorLocale(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pLastInteriorLocale];
}

// Setters
stock PlayerData_SetInteriorLocale(playerid, interiorid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_GeneralInfo[playerid][pLastInteriorLocale] = interiorid;
}

// ============== TEMPORARY ACCESSORS ============== //
stock bool:PlayerData_GetIsUsingAndroid(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return isUsingAndroid[playerid];
}

stock bool:PlayerData_GetIsLogged(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return isLogged[playerid];
}

stock bool:PlayerData_SetIsUsingAndroid(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return isLogged[playerid] = status;
}

stock bool:PlayerData_SetIsLogged(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;
    
    return isLogged[playerid] = status;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetGeneralInfo(playerid)
{
    static const empty_data[pGeneralInfo];
    Player_GeneralInfo[playerid] = empty_data;
    Player_GeneralInfo[playerid][pLastPosX] = SPAWN_POSX;
    Player_GeneralInfo[playerid][pLastPosY] = SPAWN_POSY;
    Player_GeneralInfo[playerid][pLastPosZ] = SPAWN_POSZ;
    Player_GeneralInfo[playerid][pLastPosA] = SPAWN_POSA;
    Player_GeneralInfo[playerid][pLastInterior] = SPAWN_INTERIOR;
    Player_GeneralInfo[playerid][pLastVw] = SPAWN_VW;
    return Player_GeneralInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
