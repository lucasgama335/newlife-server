#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_TRASH_ROUTES    20
//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsTrashPickup[MAX_PLAYERS];
static bool:gsMarkedTrash[MAX_PLAYERS];
static bool:gsCaughtTrash[MAX_PLAYERS];
static gsNextTrashCommand[MAX_PLAYERS];
static Float:gsSpawnTrash[MAX_TRASH_ROUTES][4] =
{
	{1811.5840,-1752.1294,13.5490},
    {884.9703,-1663.8604,13.5469},
    {369.1192,-1765.5521,5.5147},
    {-90.4849,-1169.6840,2.4040},
    {279.3895,-1241.0728,74.3764},
    {1005.2083,-401.4265,68.4287},
    {2073.5068,-1575.8424,13.4414},
    {1830.8624,-1108.7552,23.8446},
    {1830.8624,-1108.7552,23.8446},
    {724.7245,-470.5882,16.3359},
    {780.9676,-596.6437,16.3359},
    {553.9373,-1358.3655,15.3062},
    {477.4827,-1744.4395,9.3750},
    {117.9634,-186.1646,1.5106},
    {159.3121,-175.2853,1.5781},
    {203.9658,-163.4601,1.5781},
    {1275.6146,304.5439,19.5547},
    {1250.1162,245.9012,19.5547},
    {1294.2323,177.9601,20.4609},
    {1486.0442,357.1795,19.3169}
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsTrashPickup[playerid] = INVALID_VALUE;
    gsMarkedTrash[playerid] = false;
    gsCaughtTrash[playerid] = false;
    gsNextTrashCommand[playerid] = gettime(); 
    return 1;
}

hook OnPlayerDisconnect(playerid)
{
    if (gsCaughtTrash[playerid])
    {
        RemovePlayerAttachedObject(playerid, SLOT_SERVER);
    }
    return 1;
}

hook OnPlayerPickUpDinamicPC(playerid, pickupid)
{
    if (pickupid == gsTrashPickup[playerid])
    {
        if (Player_GetJob(playerid) != j_JOB_GARBAGEMAN)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não é um lixeiro.");
        }
        gsCaughtTrash[playerid] = true;
        DestroyDynamicPickup(gsTrashPickup[playerid]);
        PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
        SetPlayerCheckpoint(playerid, 2190.1362, -1976.9535, 13.5528, 5.0);
        if (IsPlayerAttachedObjectSlotUsed(playerid, SLOT_SERVER)) 
        {
            RemovePlayerAttachedObject(playerid, SLOT_SERVER);
        }
        SetPlayerAttachedObject(playerid, SLOT_SERVER, 1264, 1, 0.000000, -0.313611, 0.021003, 0.445490, 86.754409, 355.370239, 0.926815, 1.000000, 1.000000);
        SendClientMessage(playerid, COLOR_WHITE, "Você pegou um lixo, leve-o até o lixão e digite /elixo.");
        SendClientMessage(playerid, COLOR_WHITE, "Digite /gps - Empregos - Lixeiros para marcar no mapa.");
        return 1;
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    #pragma unused oldstate // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
        new vehicleid = GetPlayerVehicleID(playerid);
        if (Vehicle_GetJob(vehicleid) == j_JOB_GARBAGEMAN)
        {
            if (gsCaughtTrash[playerid] && !gsMarkedTrash[playerid])
            {
                SendClientMessage(playerid, COLOR_GREEN, "Lixeiro, você já possui um lixo, vá ate o lixão e digite: /elixo.");
            }
            else
            {
                SendClientMessage(playerid, COLOR_GREEN, "Lixeiro, para marcar seu lixo no mapa, digite: /mlixo e vá buscá-lo.");
            }
        }
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:mlixo(playerid, params[], help)
{
	if (Player_GetJob(playerid) != j_JOB_GARBAGEMAN)
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não é um lixeiro.");
    }
    if ((gsNextTrashCommand[playerid] - gettime()) > 0)
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você pegou um lixo faz pouco tempo, espere 2 minutos para marcar novamente.");
    }
    if (gsCaughtTrash[playerid])
    {
      	return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Entregue o lixo que você pegou antes de buscar por outro.");
    }
    if (gsCaughtTrash[playerid])
    {
      	return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você já tem um lixo no mapa vá buscá-lo.");
    }
    if (!IsPlayerInRangeOfPoint(playerid, 80.0, 2202.9292,-1971.4089,13.5572) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2202.9536,-1981.9543,13.5515) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2193.7070,-1999.6227,13.5469) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2161.2625,-1987.3088,14.2694) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2166.5229,-1971.7751,13.5541)
	&& !IsPlayerInRangeOfPoint(playerid, 60.0, -2752.4666,90.7031,7.0313) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2737.6907,93.2707,4.4333) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2738.3879,115.5734,4.4962) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2735.8149,133.7296,4.2641) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2752.5149,129.2021,7.0313))
    {
	   SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Para marcar um lixo, você deve estar em sua HQ.");
	   SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não se lembra onde fica? digite: /gps - Empregos - Lixeiros.");
	   return 1;
	}
    new vehicleid = GetPlayerVehicleID(playerid);
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER || Vehicle_GetJob(vehicleid) != j_JOB_GARBAGEMAN)
    {
	   	return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em um caminhão de lixo.");
    }

    new rand = random(MAX_TRASH_ROUTES), string[80];
    gsMarkedTrash[playerid] = true;
    gsNextTrashCommand[playerid] = (gettime() + 120);
    gsTrashPickup[playerid] = CreateDynamicPickup(1265, 23, gsSpawnTrash[rand][0], gsSpawnTrash[rand][1], gsSpawnTrash[rand][2]);
    SetPlayerCheckpoint(playerid, gsSpawnTrash[rand][0], gsSpawnTrash[rand][1], gsSpawnTrash[rand][2], 5.0);
    format(string, sizeof(string), "[Central de Coleta]: %s iniciou uma rota de coleta de lixo.", GetPlayerNameCustom(playerid));
    SendJobMessage(0xFFEC8BFF, string, j_JOB_GARBAGEMAN);
    SendClientMessage(playerid, COLOR_INVALID, "Você marcou um lixo no mapa. Traga-o até sua HQ.");
    return 1;
}

YCMD:elixo(playerid, params[], help)
{
	if (Player_GetJob(playerid) != j_JOB_GARBAGEMAN)
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não é um lixeiro.");
    }
    if (!IsPlayerInRangeOfPoint(playerid, 80.0, 2202.9292,-1971.4089,13.5572) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2202.9536,-1981.9543,13.5515) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2193.7070,-1999.6227,13.5469) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2161.2625,-1987.3088,14.2694) && !IsPlayerInRangeOfPoint(playerid, 80.0, 2166.5229,-1971.7751,13.5541)
	&& !IsPlayerInRangeOfPoint(playerid, 60.0, -2752.4666,90.7031,7.0313) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2737.6907,93.2707,4.4333) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2738.3879,115.5734,4.4962) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2735.8149,133.7296,4.2641) && !IsPlayerInRangeOfPoint(playerid, 60.0, -2752.5149,129.2021,7.0313))
    {
	   SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Para marcar um lixo, você deve estar em sua HQ.");
	   SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não se lembra onde fica? digite: /gps - Empregos - Lixeiros.");
	   return 1;
	}
    if (!gsCaughtTrash[playerid])
    {
      	return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está com um lixo, digite /mlixo para marcar um e vá pega-lo.");
    }

    new string[66 + 1], salary = 100 + random(100);
	gsCaughtTrash[playerid] = false;
    Player_SetSalary(playerid, (Player_GetSalary(playerid) + salary));
	DisablePlayerCheckpoint(playerid);
	RemovePlayerAttachedObject(playerid, SLOT_SERVER);
    format(string, sizeof(string), "[Central de Coleta]: %s entregou um lixo.", GetPlayerNameCustom(playerid));
	SendJobMessage(0xFFEC8BFF, string, j_JOB_GARBAGEMAN);
	format(string, sizeof(string), "Você entregou um lixo e [R$ %d] foram adicionados ao seu salário.", salary);
	SendClientMessage(playerid, COLOR_INVALID, string);
	SendClientMessage(playerid, COLOR_INVALID, "Espere 2 minutos para poder entregar outro lixo.");
	return 1;
}