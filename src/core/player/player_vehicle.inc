#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsPlayerLastCarEntered[MAX_PLAYERS];
static gsPlayerSpeedometerTimer[MAX_PLAYERS];
static gsPlayerCheckFuelTimer[MAX_PLAYERS];
static gsPlayerCheckBrokenTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:UpdateVehicleSpeedometer(playerid, vehicleid, type)
{
	UpdatePlayerSpeedometer(playerid, vehicleid, type);
	return 1;
}

function:RemovePlayerVehicleEmptyGas(playerid)
{
	RemovePlayerFromVehicle(playerid);
	return 1;
}

function:RemovePlayerVehicleBroken(playerid)
{
	RemovePlayerFromVehicle(playerid);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowActualVehicleName(playerid, vehicleid)
{
	new string[100], vehicleName[MAX_VEHICLE_NAME_STRING];
	GetVehicleName(GetVehicleModel(vehicleid), vehicleName);
	format(string, sizeof(string), "~g~%s[%d]", vehicleName, GetVehicleModel(vehicleid));
	GameTextForPlayer(playerid, string, 6000, 1);
	return 1;
}

static stock PlayerCheckVehicleFuel(playerid, vehicleid)
{
	if (Vehicle_GetFuel(vehicleid) <= 0)
	{
		GameTextForPlayer(playerid,"~r~~n~~n~~n~~n~~n~~n~~n~~n~SEM GAS !", 1500, 3);
		SendClientMessage(playerid, COLOR_WHITE, "O Seu veículo está sem gasolina.");
		PlayerPlayMusic(playerid, 1159);
		if (gsPlayerCheckFuelTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckFuelTimer[playerid]);
			gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
		}
		gsPlayerCheckFuelTimer[playerid] = SetTimerEx("RemovePlayerVehicleEmptyGas", 5000, false, "i", playerid);
	}
	else
	{
		if (gsPlayerCheckFuelTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckFuelTimer[playerid]);
			gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
		}
	}
	return 1;
}
static stock PlayerCheckVehicleBroken(playerid, vehicleid)
{
	if (Vehicle_GetBrokenStatus(vehicleid))
	{
		SendClientMessage(playerid, COLOR_RED, "O Seu veículo bateu o motor, chame um mecânico(/solicitar) ou use seu kit(/kitcarro) !");
		GameTextForPlayer(playerid,"~r~VEICULO QUEBRADO~n~~w~ Chame um mecanico ou use um~n~~w~ KIT[/kitcarro]", 15000, 1);
		if (gsPlayerCheckBrokenTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckBrokenTimer[playerid]);
			gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
		}
		gsPlayerCheckBrokenTimer[playerid] = SetTimerEx("RemovePlayerVehicleBroken", 5000, false, "i", playerid);
	}
	else
	{
		if (gsPlayerCheckBrokenTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckBrokenTimer[playerid]);
			gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
		}
	}
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock StartSpeedometerTimer(playerid, vehicleid)
{
	if (gsPlayerSpeedometerTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerSpeedometerTimer[playerid]);
		gsPlayerSpeedometerTimer[playerid] = INVALID_VALUE;
	}
	gsPlayerSpeedometerTimer[playerid] = SetTimerEx("UpdateVehicleSpeedometer", 500, true, "iii", playerid, vehicleid, Player_GetSpeedometer(playerid));
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	gsPlayerLastCarEntered[playerid] = INVALID_VEHICLE_ID;
	gsPlayerSpeedometerTimer[playerid] = INVALID_VALUE;
	gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
	gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
	return 1;
}

hook OnPlayerDisconnect(playerid)
{
	if (gsPlayerSpeedometerTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerSpeedometerTimer[playerid]);
		gsPlayerSpeedometerTimer[playerid] = INVALID_VALUE;
	}

	if (gsPlayerCheckFuelTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerCheckFuelTimer[playerid]);
		gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
	}

	if (gsPlayerCheckBrokenTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerCheckBrokenTimer[playerid]);
		gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
	}

	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	new Float:Pos[3];
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    if (GetPlayerSpeed(vehicleid, true) > 1)
	{
        SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não pode entrar em veículos em movimento !");
		return 1;
	}

	if (Vehicle_GetJob(vehicleid) != j_JOB_NONE && Player_GetJob(playerid) != Vehicle_GetJob(vehicleid))
	{
		new string[(40 + MAX_JOB_NAME)];
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		format(string, sizeof(string), "* Você não é um %s.", Job_GetName(Vehicle_GetJob(vehicleid)));
		SendClientMessage(playerid, COLOR_GRAD2, string);
		return 1;
	}
	
	gsPlayerLastCarEntered[playerid] = vehicleid;

    if (!Vehicle_GetEngineStatus(vehicleid) && !ispassenger)
    {
    	if (Vehicle_IsCivilVehicle(vehicleid))
        {
			SendClientMessage(playerid, COLOR_NEONGREEN, "Novato, você pode achar aos locais digitando: /gps.");
	    	SendClientMessage(playerid, COLOR_NEONGREEN, "Em caso de dúvidas use: /faq, ou fale diretamente com os administradores: /relatorio.");		
		}

		SendClientMessage(playerid, COLORDGREEN, "[Veículo]: Para ligar o motor deste veículo pressione {FFFFFF}N{228b22} ou digite {FFFFFF}/motor{228b22}.");
    }
	return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	#pragma unused oldstate // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
		ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
		StartSpeedometerTimer(playerid, vehicleid);
		PlayerCheckVehicleFuel(playerid, vehicleid);
		PlayerCheckVehicleBroken(playerid, vehicleid);
		if (gsPlayerLastCarEntered[playerid] != vehicleid)
		{
			ShowActualVehicleName(playerid, vehicleid);
		}
		
		if (newstate == PLAYER_STATE_DRIVER)
		{
			if (Vehicle_IsCivilVehicle(vehicleid) && !Vehicle_GetEngineStatus(vehicleid))
			{
				Vehicle_SetEngineToPlayer(playerid, vehicleid, true);
				return 1;
			}
			if (Vehicle_IsBike(GetVehicleModel(vehicleid)) && !Vehicle_GetEngineStatus(vehicleid))
			{
				Vehicle_SetEngine(vehicleid, true);
				return 1;
			}

			if (Vehicle_GetJob(vehicleid) != j_JOB_NONE && Player_GetJob(playerid) != Vehicle_GetJob(vehicleid))
			{
				new string[(40 + MAX_JOB_NAME)];
				format(string, sizeof(string), "* Você não é um %s.", Job_GetName(Vehicle_GetJob(vehicleid)));
				SendClientMessage(playerid, COLOR_GRAD2, string);
				return 1;
			}
		}
	}
	else
	{
		HidePlayerSpeedometer(playerid);
	}
	return 1;
}

hook OnPlayerUpdateScreenSize(playerid)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	AdaptSpeedometerToScreen(playerid);
	if (IsPlayerInVehicle(playerid, vehicleid) && vehicleid != INVALID_VEHICLE_ID && IsValidVehicle(vehicleid)) 
	{
		UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
		ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
		StartSpeedometerTimer(playerid, vehicleid);
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
