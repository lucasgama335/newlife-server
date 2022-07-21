#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_JOBS        11
#define MAX_JOB_NAME    (19 + 1)

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum p_JOB_DATA
{
    j_JOBS_LIST:p_JOB,
    p_ORG,
    p_ORG_ROLE
}
static gsJobData[MAX_PLAYERS][p_JOB_DATA];

enum j_JOB_INFO
{
    j_JOBS_LIST:i_JOB_ID,
    j_JOB_NAME[MAX_JOB_NAME],
    j_JOB_SKIN_MALE,
    j_JOB_SKIN_FEMALE,
    Float:j_JOB_SPAWNX,
    Float:j_JOB_SPAWNY,
    Float:j_JOB_SPAWNZ,
    Float:j_JOB_SPAWNA,
    j_JOB_INTERIOR,
    j_JOB_VIRTUAL_WORLD,
    bool:j_JOB_FREEZE,
    j_JOB_FREEZE_TIME,
    e_INTERIOR_LOCALES:j_JOB_LOCALE,
    Float:j_JOB_HELPX,
    Float:j_JOB_HELPY,
    Float:j_JOB_HELPZ
}
static gsJobInfo[][j_JOB_INFO] = 
{
    { j_JOB_NONE, "Nenhum", 1, 1, 0.0, 0.0, 0.0, 0.0, 0, 0, false, 0, NO_INTERIOR, 0.0, 0.0, 0.0 },
    { j_JOB_GARBAGEMAN, "Lixeiro", 260, 77, 2200.0781, -1969.9874, 13.7841, 88.9771, 0, 0, false, 0, NO_INTERIOR, 2194.0466, -1970.0131, 13.7841 },
    { j_JOB_TRUCK_DRIVER, "Caminhoneiro", 133, 232, -77.8258, -1135.2129, 1.0781, 337.4821, 0, 0, false, 0, NO_INTERIOR, -74.3430, -1136.1361, 1.0781 },
    { j_JOB_TAXI_DRIVER, "Taxista", 253, 40, 588.8351, -1491.7993, 15.4013, 181.6931, 0, 0, false, 0, NO_INTERIOR, 583.7798, -1496.8689, 15.3653 },
    { j_JOB_LAWYER, "Advogado", 187, 76, 1435.7312, -1458.8724, 1616.3073, 175.7873, COURT_OF_JUSTICE, 0, true, 3000, COURT_OF_JUSTICE, 1444.6176, -1460.9321, 1616.3073 },
    { j_JOB_GRAVEDIGGER, "Coveiro", 68, 39, 832.8286, -1078.0800, 24.2969, 176.0949, 0, 0, false, 0, NO_INTERIOR, 831.5405, -1095.4967, 24.2969 },
    { j_JOB_MINER, "Minerador", 27, 77, 1003.9560, -91.6045, 22.4495, 28.0772, 0, 0, false, 0, NO_INTERIOR, 2400.9707, -1504.3239, 1402.2000 },
    { j_JOB_RESCUER, "Socorrista", 275, 219, 2041.5758, -1410.4382, 17.1641, 178.8488, 0, 0, false, 0, NO_INTERIOR, 2038.0348, -1404.6837, 17.2531 },
    { j_JOB_ELETRICIAN, "Eletricista", 16, 157, 800.6542, -613.6274, 16.3359, 177.3649, 0, 0, false, 0, NO_INTERIOR, 797.6886, -621.0000, 16.3359 },
    { j_JOB_BUS_DRIVER, "Motorista de Ônibus", 20, 157, 1796.3976, -2344.6323, 13.4902, 178.6017, 0, 0, false, 0, NO_INTERIOR, 1802.6227, -2352.5845, 13.5261 },
    { j_JOB_FARMER, "Fazendeiro", 158, 198, -93.6237, -26.5389, 3.1172, 88.9771, 0, 0, false, 0, NO_INTERIOR, -104.1152, -16.2457, 3.1094 }
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
stock Job_GetName(j_JOBS_LIST:jobId)
{
    new string[MAX_JOB_NAME];
    format(string, sizeof(string), "%s", gsJobInfo[jobId][j_JOB_NAME]);
    return string;
}

stock Job_GetSkin(playerid, j_JOBS_LIST:jobId)
{
    switch (Player_GetGender(playerid))
    {
        case 2:
        {
            return gsJobInfo[jobId][j_JOB_SKIN_FEMALE];
        }
        default:
        {
            return gsJobInfo[jobId][j_JOB_SKIN_MALE];
        }
    }
    return 1;
}

stock Job_GetSpawn(j_JOBS_LIST:jobId, &Float:posX, &Float:posY, &Float:posZ, &Float:posA, &interior, &virtualWorld, &e_INTERIOR_LOCALES:locale, &bool:freeze, &freezeTime)
{
    posX = gsJobInfo[jobId][j_JOB_SPAWNX];
    posY = gsJobInfo[jobId][j_JOB_SPAWNY];
    posZ = gsJobInfo[jobId][j_JOB_SPAWNZ];
    posA = gsJobInfo[jobId][j_JOB_SPAWNA];
    interior = gsJobInfo[jobId][j_JOB_INTERIOR];
    virtualWorld = gsJobInfo[jobId][j_JOB_VIRTUAL_WORLD];
    locale = gsJobInfo[jobId][j_JOB_LOCALE];
    freeze = gsJobInfo[jobId][j_JOB_FREEZE];
    freezeTime = gsJobInfo[jobId][j_JOB_FREEZE_TIME];
    return 1;
}

stock Job_GetHelpPosition(j_JOBS_LIST:jobId, &Float:posX, &Float:posY, &Float:posZ)
{
    posX = gsJobInfo[jobId][j_JOB_HELPX];
    posY = gsJobInfo[jobId][j_JOB_HELPY];
    posZ = gsJobInfo[jobId][j_JOB_HELPZ];
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== RESET INFO ============== //
stock Player_ResetJobData(playerid)
{
    static const scEmptyData[p_JOB_DATA];
    gsJobData[playerid] = scEmptyData;
    gsJobData[playerid][p_JOB] = j_JOB_NONE;
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
    PLAYER_FIELD_JOB, gsJobData[playerid][p_JOB],
    PLAYER_FIELD_ORG, gsJobData[playerid][p_ORG],
    PLAYER_FIELD_ORG_ROLE, gsJobData[playerid][p_ORG_ROLE],
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

// ============== JOB ACCESSORS ============== //
// Getters
stock j_JOBS_LIST:Player_GetJob(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return j_JOB_NONE;
    }

    return gsJobData[playerid][p_JOB];
}

// Setters
stock Player_SetJob(playerid, j_JOBS_LIST:jobId)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsJobData[playerid][p_JOB] = jobId;
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

    return gsJobData[playerid][p_ORG];
}

stock Player_GetOrgRole(playerid)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    return gsJobData[playerid][p_ORG_ROLE];
}

// Setters
stock Player_SetOrg(playerid, orgId, role)
{
    if (!IsPlayerConnected(playerid)) 
    {
        return 0;
    }

    gsJobData[playerid][p_ORG] = orgId;
    gsJobData[playerid][p_ORG_ROLE] = role;
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
