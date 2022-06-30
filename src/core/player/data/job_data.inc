#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pJobInfo
{
    pJob,
    pOrg,
    pOrgRole
}
static Player_JobInfo[MAX_PLAYERS][pJobInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== SAVE DB INFO ============== //
stock Database_SaveJobInfo(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    new query_string[67 + 1];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET \
    %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_JOB, Player_JobInfo[playerid][pJob],
    PLAYER_FIELD_ORG, Player_JobInfo[playerid][pOrg],
    PLAYER_FIELD_ORG_ROLE, Player_JobInfo[playerid][pOrgRole],
    PlayerData_GetID(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== JOB ACCESSORS ============== //
// Getters
stock PlayerData_GetJob(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_JobInfo[playerid][pJob];
}

// Setters
stock PlayerData_SetJob(playerid, jobid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_JobInfo[playerid][pJob] = jobid;
}

// ============== ORG ACCESSORS ============== //
// Getters
stock PlayerData_GetOrg(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_JobInfo[playerid][pOrg];
}

stock PlayerData_GetOrgRole(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

    return Player_JobInfo[playerid][pOrgRole];
}

// Setters
stock PlayerData_SetOrg(playerid, orgid, role)
{
    if (!IsPlayerConnected(playerid)) return false;

    Player_JobInfo[playerid][pOrg] = orgid;
    Player_JobInfo[playerid][pOrgRole] = role;
    return 1;
}

// ============== RESET INFO ============== //
stock PlayerData_ResetJobInfo(playerid)
{
    static const empty_data[pJobInfo];
    Player_JobInfo[playerid] = empty_data;
    return Player_JobInfo[playerid];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
