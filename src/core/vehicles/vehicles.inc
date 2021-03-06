#include <vehicles_data>
#include <player_vehicle>
#include <spawn_vehicles>
#include <driving-school_vehicles>
// Jobs
#include <garbageman_vehicles>
#include <truck-driver_vehicles>
#include <taxi-driver_vehicles>
#include <lawyer_vehicles>
#include <gravedigger_vehicles>
#include <rescuer_vehicles>
#include <eletrician_vehicles>
#include <bus_driver_vehicles>
#include <farmer_vehicles>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------
function:CheckVehicleFuel()
{
	VehicleDecreaseGlobalFuel();
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_SetEngine(vehicleid, bool:status)
{
	if (vehicleid == INVALID_VEHICLE_ID)
	{
		return 0;
	}
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	if (status == false)
    {
	    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
    }
    else
    {
	    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective);
    }
	Vehicle_SetEngineStatus(vehicleid, status);
    return 1;
}

stock Vehicle_SetEngineToPlayer(playerid, vehicleid, bool:status)
{
	if (!IsPlayerInAnyVehicle(playerid) || vehicleid == INVALID_VEHICLE_ID)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em um ve�culo.");
	}
	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o � o motorista desse ve�culo.");
	}
	if (Vehicle_IsBike(GetVehicleModel(vehicleid)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse ve�culo n�o possui um motor.");
	}
	if (IsPlayerRefueling(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode ligar o ve�culo enquanto ele est� sendo abastecido.");
	}
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && Vehicle_GetFuel(vehicleid) <= 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Seu ve�culo est� sem gasolina, use um gal�o.");
	}
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && Vehicle_GetBrokenStatus(vehicleid))
	{
		return SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Erro]: Voc� n�o pode ligar o seu ve�culo, pois ele est� quebrado.");
	}
	if (Vehicle_GetEngineStatus(vehicleid)  && GetPlayerState(playerid) == 2 && GetPlayerSpeed(playerid, true) > 1)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode mecher no motor do ve�culo com ele estando em movimento.");
	}

	new string[60];
    Vehicle_SetEngine(vehicleid, status);
	if (Vehicle_GetEngineStatus(vehicleid))
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "[Ve�culo]: {228B22}Ligado!");
		format(string, sizeof(string), "* %s deu partida no motor do ve�culo.", GetPlayerNameCustom(playerid));
    }
    else
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "[Ve�culo]: {FF0000}Desligado!");
		format(string, sizeof(string), "* %s desligou o motor do ve�culo.", GetPlayerNameCustom(playerid));
    }
	SendMessageInRange(20.0, playerid, string, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
	SetTimer("CheckVehicleFuel", 20000, true);
	return 1;
}

hook OnVehicleSpawn(vehicleid)
{
	if (vehicleid != INVALID_VEHICLE_ID)
	{
		Vehicle_SetEngine(vehicleid, false);
		Vehicle_SetHealth(vehicleid, 1000.0);
	}
	return 1;
}

hook OnVehicleHealthChange(vehicleid, playerid, Float:oldHealth, Float:actualHealth)
{
	#pragma unused playerid // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	new Float:lostHealth = (oldHealth - actualHealth);
	if (lostHealth > 0.0)
	{
		if (actualHealth <= 300.0)
		{
			SetVehicleHealth(vehicleid, 300.0);
			Vehicle_SetHealth(vehicleid, 300.0);
			Vehicle_SetEngine(vehicleid, false);
			Vehicle_SetBrokenStatus(vehicleid, true);
		}
		else
		{
			if (Vehicle_GetShield(vehicleid) > 0.0)
			{
				if (Vehicle_GetShield(vehicleid) > lostHealth)
				{
					Vehicle_SetShield(vehicleid, (Vehicle_GetShield(vehicleid) - lostHealth));
				}
				else
				{
					Vehicle_SetShield(vehicleid, 0.0);
				}
				RepairVehicleCustom(vehicleid);
			}
		}
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
