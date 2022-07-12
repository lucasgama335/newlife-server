#include <vehicles_data>
#include <vehicles_functions>
#include <vehicles_spawn_civil>
#include <vehicles_driving_school>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
task CheckVehicleFuel[18000]()
{
	VehicleDecreaseGlobalFuel();
	return 1;
}

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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um veículo.");
	}
	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não é o motorista desse veículo.");
	}
	if (Vehicle_IsBike(GetVehicleModel(vehicleid)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse veículo não possui um motor.");
	}
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && Vehicle_GetFuel(vehicleid) <= 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Seu veículo está sem gasolina, use um galão.");
	}
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && Vehicle_GetBrokenStatus(vehicleid))
	{
		return SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você não pode ligar o seu veículo, pois ele está quebrado.");
	}
	if (Vehicle_GetEngineStatus(vehicleid)  && GetPlayerState(playerid) == 2 && GetPlayerSpeed(playerid, true) > 1)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode mecher no motor do veículo com ele estando em movimento.");
	}

	new string[60];
    Vehicle_SetEngine(vehicleid, status);
	if (Vehicle_GetEngineStatus(vehicleid))
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "[Veículo]: {228B22}Ligado!");
		format(string, sizeof(string), "* %s deu partida no motor do veículo.", GetPlayerNameCustom(playerid));
    }
    else
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "[Veículo]: {FF0000}Desligado!");
		format(string, sizeof(string), "* %s desligou o motor do veículo.", GetPlayerNameCustom(playerid));
    }
	SendMessageInRange(20.0, playerid, string, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
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
	new lostHealth = floatround((oldHealth - actualHealth), floatround_round);
	if (lostHealth > 0)
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
			if (Vehicle_GetShield(vehicleid) > 0)
			{
				if (Vehicle_GetShield(vehicleid) > lostHealth)
				{
					Vehicle_SetShield(vehicleid, (Vehicle_GetShield(vehicleid) - lostHealth));
				}
				else
				{
					Vehicle_SetShield(vehicleid, 0);
				}
				RepairVehicleCustom(vehicleid);
			}
		}
	}
	return 1;
}
