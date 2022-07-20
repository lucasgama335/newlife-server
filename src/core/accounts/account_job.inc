#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_JOB_DATA
{
    p_JOB,
    p_ORG,
    p_ORG_ROLE
}
static gsJobInfo[MAX_PLAYERS][p_JOB_DATA];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== RESET INFO ============== //
stock Player_ResetJobData(playerid)
{
    static const scEmptyData[p_JOB_DATA];
    gsJobInfo[playerid] = scEmptyData;
    return 1;
}

// ============== SAVE DB INFO ============== //
stock Player_SaveJobData(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return false;
    }

    new query_string[67 + 1];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_JOB, gsJobInfo[playerid][p_JOB],
    PLAYER_FIELD_ORG, gsJobInfo[playerid][p_ORG],
    PLAYER_FIELD_ORG_ROLE, gsJobInfo[playerid][p_ORG_ROLE],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== JOB ACCESSORS ============== //
// Getters
stock Player_GetJob(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsJobInfo[playerid][p_JOB];
}

// Setters
stock Player_SetJob(playerid, jobId)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsJobInfo[playerid][p_JOB] = jobId;
    return 1;
}

// ============== ORG ACCESSORS ============== //
// Getters
stock Player_GetOrg(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsJobInfo[playerid][p_ORG];
}

stock Player_GetOrgRole(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsJobInfo[playerid][p_ORG_ROLE];
}

// Setters
stock Player_SetOrg(playerid, orgId, role)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsJobInfo[playerid][p_ORG] = orgId;
    gsJobInfo[playerid][p_ORG_ROLE] = role;
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
