#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pGeneralInfo
{
    pId,
    pName[MAX_PLAYER_NAME + 1],
    pPassword[BCRYPT_HASH_LENGTH],
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
/**
 *  General Player Info
 */
// Player ID Accessor Function
stock PlayerData_GetID(playerid)
{
    return Player_GeneralInfo[playerid][pId];
}

stock PlayerData_SetID(playerid, id)
{
    return Player_GeneralInfo[playerid][pId] = id;
}

// Player Name Accessor Function
stock PlayerData_GetName(playerid)
{
    new string[MAX_PLAYER_NAME + 1];
    format(string, sizeof(string), "%s", Player_GeneralInfo[playerid][pName]);
    return string;
}

stock PlayerData_SetName(playerid, const name[])
{
    format(Player_GeneralInfo[playerid][pName], (MAX_PLAYER_NAME + 1), "%s", name);
    return 1;
}

// Player Password Accessor Function
stock PlayerData_GetPassword(playerid)
{
    new string[BCRYPT_HASH_LENGTH];
    format(string, sizeof(string), "%s", Player_GeneralInfo[playerid][pPassword]);
    return string;
}

stock PlayerData_SetPassword(playerid, const password[])
{
    format(Player_GeneralInfo[playerid][pPassword], BCRYPT_HASH_LENGTH, "%s", password);
    return 1;
}

// Player Admin Accessor Function
stock PlayerData_GetAdmin(playerid)
{
    return Player_GeneralInfo[playerid][pAdmin];
}

stock PlayerData_SetAdmin(playerid, level)
{
    return Player_GeneralInfo[playerid][pAdmin] = level;
}

// Player Last Login Date Accessor Function
stock PlayerData_GetLastLoginDate(playerid)
{
    return Player_GeneralInfo[playerid][pLastLoginDate];
}

stock PlayerData_SetLastLoginDate(playerid, timestamp)
{
    return Player_GeneralInfo[playerid][pLastLoginDate] = timestamp;
}

// Player Last Login Hour Accessor Function
stock PlayerData_GetLastLoginHour(playerid)
{
    return Player_GeneralInfo[playerid][pLastLoginHour];
}

stock PlayerData_SetLastLoginHour(playerid, timestamp)
{
    return Player_GeneralInfo[playerid][pLastLoginHour] = timestamp;
}

// Player Last Connected Time Accessor Function
stock PlayerData_GetLastConnectedTime(playerid)
{
    return Player_GeneralInfo[playerid][pLastConnectedTime];
}

stock PlayerData_SetLastConnectedTime(playerid, time)
{
    return Player_GeneralInfo[playerid][pLastConnectedTime] = time;
}

// Player Last Pos X Accessor Function
stock Float:PlayerData_GetLastPosX(playerid)
{
    return Player_GeneralInfo[playerid][pLastPosX];
}

stock Float:PlayerData_SetLastPosX(playerid, Float:position)
{
    return Player_GeneralInfo[playerid][pLastPosX] = position;
}

// Player Last Pos Y Accessor Function
stock Float:PlayerData_GetLastPosY(playerid)
{
    return Player_GeneralInfo[playerid][pLastPosY];
}

stock Float:PlayerData_SetLastPosY(playerid, Float:position)
{
    return Player_GeneralInfo[playerid][pLastPosY] = position;
}

// Player Last Pos Z Accessor Function
stock Float:PlayerData_GetLastPosZ(playerid)
{
    return Player_GeneralInfo[playerid][pLastPosZ];
}

stock Float:PlayerData_SetLastPosZ(playerid, Float:position)
{
    return Player_GeneralInfo[playerid][pLastPosZ] = position;
}

// Player Last Pos A Accessor Function
stock Float:PlayerData_GetLastPosA(playerid)
{
    return Player_GeneralInfo[playerid][pLastPosA];
}

stock Float:PlayerData_SetLastPosA(playerid, Float:position)
{
    return Player_GeneralInfo[playerid][pLastPosA] = position;
}

// Player Last Interior Accessor Function
stock Float:PlayerData_GetLastInterior(playerid)
{
    return Player_GeneralInfo[playerid][pLastInterior];
}

stock PlayerData_SetLastInterior(playerid, interiorid)
{
    return Player_GeneralInfo[playerid][pLastInterior] = interiorid;
}

// Player Last Virtual World Accessor Function
stock Float:PlayerData_GetVirtualWorld(playerid)
{
    return Player_GeneralInfo[playerid][pLastVw];
}

stock PlayerData_SetVirtualWorld(playerid, vwid)
{
    return Player_GeneralInfo[playerid][pLastVw] = vwid;
}

stock PlayerData_ResetGeneralInfo(playerid)
{
    static const empty_data[pGeneralInfo];
    Player_GeneralInfo[playerid] = empty_data;
    PlayerData_SetName(playerid, Player_GetName(playerid));
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
