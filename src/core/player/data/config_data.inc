#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pConfigInfo
{
    pTag,
    pCitySpawn,
    pSpawnPlace,
    pDocumentType,
    pSpeedometerType,
    pTrackerType,
    pHitSound,
    bool:pTerritorialChat,
    bool:pVipChat,
    bool:pSocioChat,
    bool:pNoobChat,
    bool:pLeaderChat,
    bool:pStreamMusic
}
static Player_ConfigInfo[MAX_PLAYERS][pConfigInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Database_SaveConfigInfo(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    new query_string[314];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME, 
    PLAYER_FIELD_CONFIG_TAG, Player_ConfigInfo[playerid][pTag], 
    PLAYER_FIELD_CONFIG_CITY, Player_ConfigInfo[playerid][pCitySpawn], 
    PLAYER_FIELD_CONFIG_SPAWN, Player_ConfigInfo[playerid][pSpawnPlace], 
    PLAYER_FIELD_CONFIG_DOCUMENT, Player_ConfigInfo[playerid][pDocumentType], 
    PLAYER_FIELD_CONFIG_SPEED, Player_ConfigInfo[playerid][pSpeedometerType], 
    PLAYER_FIELD_CONFIG_TRACKER, Player_ConfigInfo[playerid][pTrackerType], 
    PLAYER_FIELD_CONFIG_HITSOUND, Player_ConfigInfo[playerid][pHitSound], 
    PLAYER_FIELD_CONFIG_TERRITORIAL_CHAT, (Player_ConfigInfo[playerid][pTerritorialChat] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_VIP_CHAT, (Player_ConfigInfo[playerid][pVipChat] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_SOCIO_CHAT, (Player_ConfigInfo[playerid][pSocioChat] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_NOOB_CHAT, (Player_ConfigInfo[playerid][pNoobChat] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_LEADER_CHAT, (Player_ConfigInfo[playerid][pLeaderChat] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_STREAM, (Player_ConfigInfo[playerid][pStreamMusic] ? 1 : 0), 
    PlayerData_GetID(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

stock Player_UpdateConfigTypes(playerid, tag, city, spawn, document, speedometer, tracker, hitsound)
{
    Player_ConfigInfo[playerid][pTag] = tag;
    Player_ConfigInfo[playerid][pCitySpawn] = city;
    Player_ConfigInfo[playerid][pSpawnPlace] = spawn;
    Player_ConfigInfo[playerid][pDocumentType] = document;
    Player_ConfigInfo[playerid][pSpeedometerType] = speedometer;
    Player_ConfigInfo[playerid][pTrackerType] = tracker;
    Player_ConfigInfo[playerid][pHitSound] = hitsound;
    return 1;
}

stock Player_UpdateConfigChats(playerid, bool:territorial_chat, bool:vip_chat, bool:socio_chat, bool:noob_chat, bool:leader_chat, bool:stream)
{
    Player_ConfigInfo[playerid][pTerritorialChat] = territorial_chat;
    Player_ConfigInfo[playerid][pVipChat] = vip_chat;
    Player_ConfigInfo[playerid][pSocioChat] = socio_chat;
    Player_ConfigInfo[playerid][pNoobChat] = noob_chat;
    Player_ConfigInfo[playerid][pLeaderChat] = leader_chat;
    Player_ConfigInfo[playerid][pStreamMusic] = stream;
    return 1;
}

// ============== TAG ACCESSORS ============== //
// Getters
stock PlayerData_GetTag(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pTag];
}

// Setters
stock PlayerData_SetTag(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pTag] = type;
}

// ============== CITY ACCESSORS ============== //
// Getters
stock PlayerData_GetCity(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pCitySpawn];
}

// Setters
stock PlayerData_SetCity(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pCitySpawn] = type;
}

// ============== SPAWN ACCESSORS ============== //
// Getters
stock PlayerData_GetSpawn(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pSpawnPlace];
}

// Setters
stock PlayerData_SetSpawn(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pSpawnPlace] = type;
}

// ============== DOCUMENT ACCESSORS ============== //
// Getters
stock PlayerData_GetDocument(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pDocumentType];
}

// Setters
stock PlayerData_SetDocument(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pDocumentType] = type;
}

// ============== SPEEDOMETER ACCESSORS ============== //
// Getters
stock PlayerData_GetSpeedometer(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pSpeedometerType];
}

// Setters
stock PlayerData_SetSpeedometer(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pSpeedometerType] = type;
}

// ============== TRACKER ACCESSORS ============== //
// Getters
stock PlayerData_GetTracker(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pTrackerType];
}

// Setters
stock PlayerData_SetTracker(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pTrackerType] = type;
}

// ============== HITSOUND ACCESSORS ============== //
// Getters
stock PlayerData_GetHitSound(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pHitSound];
}

// Setters
stock PlayerData_SetHitSound(playerid, type)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pHitSound] = type;
}

// ============== TERRITORIAL CHAT ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetTerritorialChat(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pTerritorialChat];
}

// Setters
stock bool:PlayerData_SetTerritorialChat(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pTerritorialChat] = status;
}

// ============== VIP CHAT ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetVipChat(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pVipChat];
}

// Setters
stock bool:PlayerData_SetVipChat(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pVipChat] = status;
}

// ============== SOCIO CHAT ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetSocioChat(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pSocioChat];
}

// Setters
stock bool:PlayerData_SetSocioChat(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pSocioChat] = status;
}

// ============== NOOB CHAT ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetNoobChat(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pNoobChat];
}

// Setters
stock bool:PlayerData_SetNoobChat(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pNoobChat] = status;
}

// ============== LEADER CHAT ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetLeaderChat(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pLeaderChat];
}

// Setters
stock bool:PlayerData_SetLeaderChat(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pLeaderChat] = status;
}

// ============== STREAM MUSIC CHAT ACCESSORS ============== //
// Getters
stock bool:PlayerData_GetStreamStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pStreamMusic];
}

// Setters
stock bool:PlayerData_SetStreamStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_ConfigInfo[playerid][pStreamMusic] = status;
}

// ============== AUTO UPDATE ============== //
stock Player_UpdateAutoConfigTypes(playerid)
{
    Player_ConfigInfo[playerid][pTag] = PlayerData_GetTag(playerid);
    Player_ConfigInfo[playerid][pCitySpawn] = PlayerData_GetCity(playerid);
    Player_ConfigInfo[playerid][pSpawnPlace] = PlayerData_GetSpawn(playerid);
    Player_ConfigInfo[playerid][pDocumentType] = PlayerData_GetDocument(playerid);
    Player_ConfigInfo[playerid][pSpeedometerType] = PlayerData_GetSpeedometer(playerid);
    Player_ConfigInfo[playerid][pTrackerType] = PlayerData_GetTracker(playerid);
    Player_ConfigInfo[playerid][pHitSound] = PlayerData_GetHitSound(playerid);
    Database_SaveConfigInfo(playerid);
    return 1;
}

stock Player_UpdateAutoConfigChats(playerid)
{
    Player_ConfigInfo[playerid][pTerritorialChat] = PlayerData_GetTerritorialChat(playerid);
    Player_ConfigInfo[playerid][pVipChat] = PlayerData_GetVipChat(playerid);
    Player_ConfigInfo[playerid][pSocioChat] = PlayerData_GetSocioChat(playerid);
    Player_ConfigInfo[playerid][pNoobChat] = PlayerData_GetNoobChat(playerid);
    Player_ConfigInfo[playerid][pLeaderChat] = PlayerData_GetLeaderChat(playerid);
    Player_ConfigInfo[playerid][pStreamMusic] = PlayerData_GetStreamStatus(playerid);
    Database_SaveConfigInfo(playerid);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
