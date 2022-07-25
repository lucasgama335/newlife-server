#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsTrashPickup[MAX_PLAYERS];
static bool:gsMarkedTrash[MAX_PLAYERS];
static bool:gsCaughtTrash[MAX_PLAYERS];
static gsNextTrashCommand[MAX_PLAYERS];
static Float:gsSpawnTrash[][4] =
{
	{2388.1665, -2015.1119, 13.5489},
    {2416.5940, -1699.4072, 13.7904},
    {2765.6951, -2031.1461, 13.5547},
    {2817.7329, -1511.4391, 15.7644},
    {2753.1218, -1282.2955, 56.5938},
    {2623.1702, -1124.7756, 66.1440},
    {2561.7012, -954.0216, 82.7547},
    {2326.4272, -1056.4502, 52.3516},
    {2221.0327, -1055.8872, 46.0059},
    {1953.4849, -1091.4570, 25.2143},
    {1784.8915, -1217.9871, 16.9428},
    {1661.6531, -1003.0493, 24.0511},
    {1220.4478, -1067.8431, 29.2236},
    {1035.6873, -1235.5797, 16.3364},
    {901.7509, -1360.1044, 13.5469},
    {862.3225, -1383.4161, 13.6883},
    {660.5856, -1498.4351, 14.8584},
    {363.2824, -1680.8828, 32.0616},
    {204.7870, -1432.1246, 13.1673},
    {-38.4919, -1555.1075, 2.3054}
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
    if (IsPlayerAttachedObjectSlotUsed(playerid, SLOT_SERVER))
    {
        RemovePlayerAttachedObject(playerid, SLOT_SERVER);
    }
    return 1;
}

hook OnPlayerPickUpDynamicPC(playerid, pickupid)
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
            if (!gsMarkedTrash[playerid] && !gsCaughtTrash[playerid])
            {
                SendClientMessage(playerid, COLOR_SKIN, "[Dica]: Para iniciar uma rota de coleta utilize: /mlixo.");
            }
            else if (gsMarkedTrash[playerid] && !gsCaughtTrash[playerid])
            {
                SendClientMessage(playerid, COLOR_SKIN, "[Dica]: Você já está com uma rota de coleta ativa, busque-a no local marcado.");
            }
            else if (gsMarkedTrash[playerid] && gsCaughtTrash[playerid])
            {
                SendClientMessage(playerid, COLOR_SKIN, "[Dica]: Você já coletou o lixo, vá até a sua hq e digite: /elixo.");
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
    if (!IsPlayerInRangeOfPoint(playerid, 60.0, 2180.3018,-1984.0994,13.5510))
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

    new rand = random(sizeof(gsSpawnTrash)), string[80];
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
    if (!IsPlayerInRangeOfPoint(playerid, 60.0, 2180.3018,-1984.0994,13.5510))
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