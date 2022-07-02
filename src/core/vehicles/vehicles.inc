#include <vehicles_data>
#include <vehicles_spawn_civil>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
static Iterator:Vehicles<MAX_VEHICLES>;

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
task CheckVehicleFuel[15000]()
{
	foreach (new vehicleid : Vehicles)
	{
		if (Vehicle_GetFuel(vehicleid) > 0)
		{
			Vehicle_SetFuel(vehicleid, (Vehicle_GetFuel(vehicleid) - 1));
			if (Vehicle_GetFuel(vehicleid) <= 0)
			{
				if (Vehicle_GetEngineStatus(vehicleid))
				{
					Vehicle_SetEngine(vehicleid, false);
				}
			}
		}
		else
		{
			if (Vehicle_GetEngineStatus(vehicleid))
			{
				Vehicle_SetEngine(vehicleid, false);
			}
		}
	}
	return 1;
}

task CheckVehicleShield[1000]()
{
	foreach (new vehicleid : Vehicles)
	{
		new Float:vehicleHealth, intHealt, lostHealth;
		GetVehicleHealth(vehicleid, vehicleHealth);
		intHealt = floatround((vehicleHealth / 10), floatround_round);
		lostHealth = (100 - intHealt);
		if (Vehicle_GetShield(vehicleid) > 0 && vehicleHealth < 1000)
		{
			if (Vehicle_GetShield(vehicleid) > lostHealth)
			{
				Vehicle_SetShield(vehicleid, (Vehicle_GetShield(vehicleid) - lostHealth));
			}
			else
			{
				Vehicle_SetShield(vehicleid, 0);
			}
			RepairVehicle(vehicleid);
		}

		if (vehicleHealth <= 300.0)
		{
			Vehicle_SetEngine(vehicleid, false);
			SetVehicleHealth(vehicleid, 300);
			Vehicle_SetBrokenStatus(vehicleid, true);
		}
	}
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_SetEngine(vehicleid, bool:status)
{
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
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && Vehicle_GetFuel(vehicleid) <= 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Seu veículo está sem gasolina, use um galão.");
	}
	if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && Vehicle_GetBrokenStatus(vehicleid))
	{
		return SendClientMessage(playerid, COLOR_LIGHTBLUE, "Seu veículo está quebrado, não pode mecher no motor !");
	}
	if (Vehicle_GetEngineStatus(vehicleid)  && GetPlayerState(playerid) == 2 && GetPlayerSpeed(playerid, true) > 1)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode mecher no motor do veículo em movimento.");
	}

    Vehicle_SetEngine(vehicleid, status);
	if (Vehicle_GetEngineStatus(vehicleid))
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "Veiculo: {228B22}Ligado!");
    }
    else
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "Veiculo: {FF0000}Desligado!");
    }
    return 1;
}

stock AddStaticVehicleCustom(modelId, Float:posX, Float:posY, Float:posZ, Float:posA, colorOne, colorTwo, timeToRespawn, bool:siren = false)
{
	new tempVehicleId = INVALID_VEHICLE_ID;
	tempVehicleId = AddStaticVehicleEx(modelId, posX, posY, posZ, posA, colorOne, colorTwo, timeToRespawn, siren);
	Vehicle_SetColor(tempVehicleId, colorOne, colorTwo);
	Vehicle_SetFuel(tempVehicleId, 100);
	Vehicle_SetShield(tempVehicleId, 0);
	Vehicle_SetMoney(tempVehicleId, 0);
	Vehicle_SetBrokenStatus(tempVehicleId, false);
	Vehicle_SetLockedStatus(tempVehicleId, false);
	Vehicle_SetPlate(tempVehicleId, "");
	Vehicle_SetEngine(tempVehicleId, false);
	Iter_Add(Vehicles, tempVehicleId);
	return tempVehicleId;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnVehicleSpawn(vehicleid)
{
	Vehicle_SetEngine(vehicleid, false);
	return 1;
}
