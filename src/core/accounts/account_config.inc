#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_CONFIG_DATA
{
    e_TAGS:p_TAG,
    p_CITY_SPAWN,
    p_SPAWN_PLACE,
    p_DOCUMENT_TYPE,
    p_SPEEDOMETER_TYPE,
    p_TRACKER_TYPE,
    p_HIT_SOUND_TYPE,
    e_SCREENS:p_SCREEN_TYPE,
    bool:p_TERRITORIAL_CHAT,
    bool:p_VIP_CHAT,
    bool:p_SOCIO_CHAT,
    bool:p_NOOB_CHAT,
    bool:p_LEADER_CHAT,
    bool:p_STREAM_MUSIC
}
static gsConfigInfo[MAX_PLAYERS][p_CONFIG_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Player_SaveConfigData(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    new query_string[329];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME, 
    PLAYER_FIELD_CONFIG_TAG, gsConfigInfo[playerid][p_TAG], 
    PLAYER_FIELD_CONFIG_CITY, gsConfigInfo[playerid][p_CITY_SPAWN], 
    PLAYER_FIELD_CONFIG_SPAWN, gsConfigInfo[playerid][p_SPAWN_PLACE], 
    PLAYER_FIELD_CONFIG_DOCUMENT, gsConfigInfo[playerid][p_DOCUMENT_TYPE], 
    PLAYER_FIELD_CONFIG_SPEED, gsConfigInfo[playerid][p_SPEEDOMETER_TYPE], 
    PLAYER_FIELD_CONFIG_TRACKER, gsConfigInfo[playerid][p_TRACKER_TYPE], 
    PLAYER_FIELD_CONFIG_HITSOUND, gsConfigInfo[playerid][p_HIT_SOUND_TYPE], 
    PLAYER_FIELD_CONFIG_SCREEN, gsConfigInfo[playerid][p_SCREEN_TYPE], 
    PLAYER_FIELD_CONFIG_TERRITORIAL_CHAT, (gsConfigInfo[playerid][p_TERRITORIAL_CHAT] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_VIP_CHAT, (gsConfigInfo[playerid][p_VIP_CHAT] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_SOCIO_CHAT, (gsConfigInfo[playerid][p_SOCIO_CHAT] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_NOOB_CHAT, (gsConfigInfo[playerid][p_NOOB_CHAT] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_LEADER_CHAT, (gsConfigInfo[playerid][p_LEADER_CHAT] ? 1 : 0), 
    PLAYER_FIELD_CONFIG_STREAM, (gsConfigInfo[playerid][p_STREAM_MUSIC] ? 1 : 0), 
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== RESET INFO ============== //
stock Player_ResetConfigData(playerid)
{
    static const scEmptyData[p_CONFIG_DATA];
    gsConfigInfo[playerid] = scEmptyData;
    gsConfigInfo[playerid][p_HIT_SOUND_TYPE] = 1;
    gsConfigInfo[playerid][p_SCREEN_TYPE] = SCREEN_NORMAL;
    gsConfigInfo[playerid][p_TERRITORIAL_CHAT] = true;
    gsConfigInfo[playerid][p_VIP_CHAT] = true;
    gsConfigInfo[playerid][p_SOCIO_CHAT] = true;
    gsConfigInfo[playerid][p_NOOB_CHAT] = true;
    gsConfigInfo[playerid][p_LEADER_CHAT] = true;
    gsConfigInfo[playerid][p_STREAM_MUSIC] = true;
    return 1;
}

// ============== TAG ACCESSORS ============== //
// Getters
stock e_TAGS:Player_GetTag(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return NO_TAG;
    }

    return gsConfigInfo[playerid][p_TAG];
}

// Setters
stock Player_SetTag(playerid, e_TAGS:tag)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_TAG] = tag;
    return 1;
}

// ============== CITY ACCESSORS ============== //
// Getters
stock Player_GetCity(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsConfigInfo[playerid][p_CITY_SPAWN];
}

// Setters
stock Player_SetCity(playerid, type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_CITY_SPAWN] = type;
    return 1;
}

// ============== SPAWN ACCESSORS ============== //
// Getters
stock Player_GetSpawn(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsConfigInfo[playerid][p_SPAWN_PLACE];
}

// Setters
stock Player_SetSpawn(playerid, type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_SPAWN_PLACE] = type;
    return 1;
}

// ============== DOCUMENT ACCESSORS ============== //
// Getters
stock Player_GetDocument(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsConfigInfo[playerid][p_DOCUMENT_TYPE];
}

// Setters
stock Player_SetDocument(playerid, type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_DOCUMENT_TYPE] = type;
    return 1;
}

// ============== SPEEDOMETER ACCESSORS ============== //
// Getters
stock Player_GetSpeedometer(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsConfigInfo[playerid][p_SPEEDOMETER_TYPE];
}

// Setters
stock Player_SetSpeedometer(playerid, type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_SPEEDOMETER_TYPE] = type;
    return 1;
}

// ============== TRACKER ACCESSORS ============== //
// Getters
stock Player_GetTracker(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsConfigInfo[playerid][p_TRACKER_TYPE];
}

// Setters
stock Player_SetTracker(playerid, type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_TRACKER_TYPE] = type;
    return 1;
}

// ============== HITSOUND ACCESSORS ============== //
// Getters
stock Player_GetHitSound(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsConfigInfo[playerid][p_HIT_SOUND_TYPE];
}

// Setters
stock Player_SetHitSound(playerid, type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_HIT_SOUND_TYPE] = type;
    return 1;
}

// ============== SCREEN TYPE ACCESSORS ============== //
// Getters
stock e_SCREENS:Player_GetScreenSize(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return SCREEN_INVALID;
    }

    return gsConfigInfo[playerid][p_SCREEN_TYPE];
}

// Setters
stock Player_SetScreenSize(playerid, e_SCREENS:type)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_SCREEN_TYPE] = type;
    return 1;
}

// ============== TERRITORIAL CHAT ACCESSORS ============== //
// Getters
stock bool:Player_GetTerritorialChatStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    return gsConfigInfo[playerid][p_TERRITORIAL_CHAT];
}

// Setters
stock Player_SetTerritorialChatStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_TERRITORIAL_CHAT] = status;
    return 1;
}

// ============== VIP CHAT ACCESSORS ============== //
// Getters
stock bool:Player_GetVipChatStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    return gsConfigInfo[playerid][p_VIP_CHAT];
}

// Setters
stock Player_SetVipChatStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_VIP_CHAT] = status;
    return 1;
}

// ============== SOCIO CHAT ACCESSORS ============== //
// Getters
stock bool:Player_GetSocioChatStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    return gsConfigInfo[playerid][p_SOCIO_CHAT];
}

// Setters
stock Player_SetSocioChatStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_SOCIO_CHAT] = status;
    return 1;
}

// ============== NOOB CHAT ACCESSORS ============== //
// Getters
stock bool:Player_GetNoobChatStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    return gsConfigInfo[playerid][p_NOOB_CHAT];
}

// Setters
stock Player_SetNoobChatStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_NOOB_CHAT] = status;
    return 1;
}

// ============== LEADER CHAT ACCESSORS ============== //
// Getters
stock bool:Player_GetLeaderChatStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    return gsConfigInfo[playerid][p_LEADER_CHAT];
}

// Setters
stock Player_SetLeaderChatStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_LEADER_CHAT] = status;
    return 1;
}

// ============== STREAM MUSIC CHAT ACCESSORS ============== //
// Getters
stock bool:Player_GetMusicStreamStatus(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    return gsConfigInfo[playerid][p_STREAM_MUSIC];
}

// Setters
stock Player_SetMusicStreamStatus(playerid, bool:status)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsConfigInfo[playerid][p_STREAM_MUSIC] = status;
    return 1;
}

// ============== AUTO UPDATE ============== //
stock Player_UpdateConfigTypes(playerid, e_TAGS:tag, city, spawn, document, speedometer, tracker, hitsound, e_SCREENS:screenSize)
{
    gsConfigInfo[playerid][p_TAG] = tag;
    gsConfigInfo[playerid][p_CITY_SPAWN] = city;
    gsConfigInfo[playerid][p_SPAWN_PLACE] = spawn;
    gsConfigInfo[playerid][p_DOCUMENT_TYPE] = document;
    gsConfigInfo[playerid][p_SPEEDOMETER_TYPE] = speedometer;
    gsConfigInfo[playerid][p_TRACKER_TYPE] = tracker;
    gsConfigInfo[playerid][p_HIT_SOUND_TYPE] = hitsound;
    gsConfigInfo[playerid][p_SCREEN_TYPE] = screenSize;
    return 1;
}

stock Player_UpdateConfigChats(playerid, bool:territorial_chat, bool:vip_chat, bool:socio_chat, bool:noob_chat, bool:leader_chat, bool:stream)
{
    gsConfigInfo[playerid][p_TERRITORIAL_CHAT] = territorial_chat;
    gsConfigInfo[playerid][p_VIP_CHAT] = vip_chat;
    gsConfigInfo[playerid][p_SOCIO_CHAT] = socio_chat;
    gsConfigInfo[playerid][p_NOOB_CHAT] = noob_chat;
    gsConfigInfo[playerid][p_LEADER_CHAT] = leader_chat;
    gsConfigInfo[playerid][p_STREAM_MUSIC] = stream;
    return 1;
}

stock Player_UpdateConfigData(playerid)
{
    gsConfigInfo[playerid][p_TAG] = Player_GetTag(playerid);
    gsConfigInfo[playerid][p_CITY_SPAWN] = Player_GetCity(playerid);
    gsConfigInfo[playerid][p_SPAWN_PLACE] = Player_GetSpawn(playerid);
    gsConfigInfo[playerid][p_DOCUMENT_TYPE] = Player_GetDocument(playerid);
    gsConfigInfo[playerid][p_SPEEDOMETER_TYPE] = Player_GetSpeedometer(playerid);
    gsConfigInfo[playerid][p_TRACKER_TYPE] = Player_GetTracker(playerid);
    gsConfigInfo[playerid][p_HIT_SOUND_TYPE] = Player_GetHitSound(playerid);
    gsConfigInfo[playerid][p_SCREEN_TYPE] = Player_GetScreenSize(playerid);
    return 1;
}

stock Player_UpdateConfigChatsData(playerid)
{
    gsConfigInfo[playerid][p_TERRITORIAL_CHAT] = Player_GetTerritorialChatStatus(playerid);
    gsConfigInfo[playerid][p_VIP_CHAT] = Player_GetVipChatStatus(playerid);
    gsConfigInfo[playerid][p_SOCIO_CHAT] = Player_GetSocioChatStatus(playerid);
    gsConfigInfo[playerid][p_NOOB_CHAT] = Player_GetNoobChatStatus(playerid);
    gsConfigInfo[playerid][p_LEADER_CHAT] = Player_GetLeaderChatStatus(playerid);
    gsConfigInfo[playerid][p_STREAM_MUSIC] = Player_GetMusicStreamStatus(playerid);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
