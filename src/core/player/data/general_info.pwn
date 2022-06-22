#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pGeneralInfo
{
    pId,
    pAdmin,
    pLastLoginDate,
    pLastLoginHour,
    pLastConnectedTime,
    Float:pLastPosX,
    Float:pLastPosY,
    Float:pLastPosZ,
    Float:pLastPosA,
    pLastInterior,
    pLastVw,
}
static Player_GeneralInfo[MAX_PLAYERS][pGeneralInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== ID ACCESSORS ============== //
// Getters
stock PlayerData_GetID(playerid)
{
    return Player_GeneralInfo[playerid][pId];
}

// Setters
stock PlayerData_SetID(playerid, id)
{
    return Player_GeneralInfo[playerid][pId] = id;
}

// ============== ADMIN ACCESSORS ============== //
// Getters
stock PlayerData_GetAdmin(playerid)
{
    return Player_GeneralInfo[playerid][pAdmin];
}

// Setters
stock PlayerData_SetAdmin(playerid, level)
{
    return Player_GeneralInfo[playerid][pAdmin] = level;
}

// ============== LAST LOGIN ACCESSORS ============== //
// Getters

// Setters
stock PlayerData_SetLastLoginDate(playerid, timestamp)
{
    return Player_GeneralInfo[playerid][pLastLoginDate] = timestamp;
}

stock PlayerData_SetLastLoginHour(playerid, timestamp)
{
    return Player_GeneralInfo[playerid][pLastLoginHour] = timestamp;
}

stock PlayerData_SetLastConnectedTime(playerid, time)
{
    return Player_GeneralInfo[playerid][pLastConnectedTime] = time;
}

// ============== LAST POSITION ACCESSORS ============== //
// Getters
stock Player_GetLastPosition(playerid, &Float:x, &Float:y, &Float:z, &interior, &vw)
{
    x = Player_GeneralInfo[playerid][pLastPosX];
    y = Player_GeneralInfo[playerid][pLastPosY];
    z = Player_GeneralInfo[playerid][pLastPosZ];
    interior = Player_GeneralInfo[playerid][pLastInterior];
    vw = Player_GeneralInfo[playerid][pLastVw];
    return 1;
}

stock PlayerData_GetLastPosAngle(playerid, &Float:a)
{
    a = Player_GeneralInfo[playerid][pLastPosA];
    return 1;
}

// Setters
stock PlayerData_SetLastPosition(playerid, Float:setX, Float:setY, Float:setZ, Float:setA, interiorid, vw)
{
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
    new Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a, interior, vw;
    GetPlayerPosition(playerid, pos_x, pos_y, pos_z);
    GetPlayerFacingAngle(playerid, pos_a);
    Player_GeneralInfo[playerid][pLastInterior] = GetPlayerInterior(playerid);
    Player_GeneralInfo[playerid][pLastVw] = GetPlayerVirtualWorld(playerid);
    Player_GeneralInfo[playerid][pLastPosX] = pos_x;
    Player_GeneralInfo[playerid][pLastPosY] = pos_y;
    Player_GeneralInfo[playerid][pLastPosZ] = pos_z;
    Player_GeneralInfo[playerid][pLastPosA] = pos_a;
    return 1;
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
