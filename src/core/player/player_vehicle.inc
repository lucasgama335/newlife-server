#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsPlayerLastCarEntered[MAX_PLAYERS];
static Timer:gsPlayerSpeedometerTimer[MAX_PLAYERS];
static Timer:gsPlayerCheckFuelTimer[MAX_PLAYERS];
static Timer:gsPlayerCheckBrokenTimer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
timer UpdateVehicleSpeedometer[500](playerid, vehicleid, type)
{
	UpdatePlayerSpeedometer(playerid, vehicleid, type);
	return 1;
}

stock StartSpeedometerTimer(playerid, vehicleid)
{
	if (Timer_IsRunning(gsPlayerSpeedometerTimer[playerid]))
	{
		stop gsPlayerSpeedometerTimer[playerid];
	}
	gsPlayerSpeedometerTimer[playerid] = repeat UpdateVehicleSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
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

timer RemovePlayerVehicleEmptyGas[5000](playerid)
{
	RemovePlayerFromVehicle(playerid);
	return 1;
}

static stock PlayerCheckVehicleFuel(playerid, vehicleid)
{
	if (Vehicle_GetFuel(vehicleid) <= 0)
	{
		GameTextForPlayer(playerid,"~r~~n~~n~~n~~n~~n~~n~~n~~n~SEM GAS !", 1500, 3);
		SendClientMessage(playerid, COLOR_WHITE, "O Seu veículo está sem gasolina.");
		PlayerPlayMusic(playerid, 1159);
		if (Timer_IsRunning(gsPlayerCheckFuelTimer[playerid]))
		{
			stop gsPlayerCheckFuelTimer[playerid];
		}
		gsPlayerCheckFuelTimer[playerid] = defer RemovePlayerVehicleEmptyGas(playerid); 
	}
	else
	{
		if (Timer_IsRunning(gsPlayerCheckFuelTimer[playerid]))
		{
			stop gsPlayerCheckFuelTimer[playerid];
		}
	}
	return 1;
}

timer RemovePlayerVehicleBroken[5000](playerid)
{
	RemovePlayerFromVehicle(playerid);
	return 1;
}

static stock PlayerCheckVehicleBroken(playerid, vehicleid)
{
	if (Vehicle_GetBrokenStatus(vehicleid))
	{
		SendClientMessage(playerid, COLOR_RED, "O Seu veículo bateu o motor, chame um mecânico(/solicitar) ou use seu kit(/kitcarro) !");
		GameTextForPlayer(playerid,"~r~VEICULO QUEBRADO~n~~w~ Chame um mecanico ou use um~n~~w~ KIT[/kitcarro]", 15000, 1);
		if (Timer_IsRunning(gsPlayerCheckBrokenTimer[playerid]))
		{
			stop gsPlayerCheckBrokenTimer[playerid];
		}
		gsPlayerCheckBrokenTimer[playerid] = defer RemovePlayerVehicleBroken(playerid); 
	}
	else
	{
		if (Timer_IsRunning(gsPlayerCheckBrokenTimer[playerid]))
		{
			stop gsPlayerCheckBrokenTimer[playerid];
		}
	}
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	gsPlayerLastCarEntered[playerid] = INVALID_VEHICLE_ID;
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

    if (!Vehicle_GetEngineStatus(vehicleid) && !ispassenger)
    {
    	if (Vehicle_IsCivilVehicle(vehicleid))
        {
			SendClientMessage(playerid, COLOR_NEONGREEN, "Novato, você pode chegar aos locais digitando /gps ou falando com um admin /relatorio.");
	    	SendClientMessage(playerid, COLOR_NEONGREEN, "Consiga Seu Emprego /gps - Prefeitura | Digite /faq para tirar todas as suas dúvidas.");		}
        else
		{
		    SendClientMessage(playerid, COLORDGREEN, "[VEÍCULO]: Para dirigir em primeira pessoa digite {FFFFFF}/camera{228b22} ou {FFFFFF}/ajuda{228b22} para ver os comandos!");
			SendClientMessage(playerid, COLORDGREEN, "[VEÍCULO]: Para ligar o motor deste veículo pressione {FFFFFF}N{228b22} ou digite {FFFFFF}/motor{228b22}!");
		}
        return 1;
    }

	gsPlayerLastCarEntered[playerid] = vehicleid;
	return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
		ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
		StartSpeedometerTimer(playerid, vehicleid);
		PlayerCheckVehicleFuel(playerid, vehicleid);
		PlayerCheckVehicleBroken(playerid, vehicleid);
		if (newstate == PLAYER_STATE_DRIVER)
		{
			if (Vehicle_IsCivilVehicle(vehicleid) && !Vehicle_GetEngineStatus(vehicleid))
			{
				Vehicle_SetEngineToPlayer(playerid, vehicleid, true);
			}
		}
		if (gsPlayerLastCarEntered[playerid] != vehicleid)
		{
			ShowActualVehicleName(playerid, vehicleid);
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