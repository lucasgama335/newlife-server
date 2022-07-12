#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Iterator:Vehicles<MAX_VEHICLES>;

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock AddStaticVehicleCustom(modelId, Float:posX, Float:posY, Float:posZ, Float:posA, colorOne, colorTwo, timeToRespawn, bool:siren = false)
{
	new tempVehicleId = AddStaticVehicleEx(modelId, posX, posY, posZ, posA, colorOne, colorTwo, timeToRespawn, siren);
	if (tempVehicleId != INVALID_VEHICLE_ID)
	{
		Vehicle_SetColor(tempVehicleId, colorOne, colorTwo);
		Vehicle_SetFuel(tempVehicleId, GetVehicleFuelCapacity(modelId));
		Vehicle_SetShield(tempVehicleId, 0);
		Vehicle_SetMoney(tempVehicleId, 0);
		Vehicle_SetBrokenStatus(tempVehicleId, false);
		Vehicle_SetLockedStatus(tempVehicleId, false);
		Vehicle_SetPlate(tempVehicleId, "");
		Vehicle_SetEngine(tempVehicleId, false);
		Vehicle_SetHealth(tempVehicleId, 1000.0);
		Iter_Add(Vehicles, tempVehicleId);
	}
	return tempVehicleId;
}

stock RespawnNearVehicles(playerid)
{
	foreach (new vehicleid : Vehicles)
	{
		if (IsPlayerNearVehicle(50.0, playerid, vehicleid))
		{
			if (!IsVehicleOccupied(vehicleid))
			{
				SetVehicleToRespawn(vehicleid);
			}
		}
	}
	return 1;
}

stock VehicleDecreaseGlobalFuel()
{
    foreach (new vehicleid : Vehicles)
	{
		if (Vehicle_GetEngineStatus(vehicleid))
		{
			if (Vehicle_GetFuel(vehicleid) <= 1)
			{
				Vehicle_SetFuel(vehicleid, 0);
				Vehicle_SetEngine(vehicleid, false);
			}
			else
			{
				Vehicle_SetFuel(vehicleid, (Vehicle_GetFuel(vehicleid) - 1));
			}
		}
	}
    return 1;
}

stock RefuelAllVehicles()
{
	foreach (new vehicleid : Vehicles)
	{
		Vehicle_SetFuel(vehicleid, 100);
	}
	return 1;
}

stock RespawnAllVehicles()
{
	foreach (new vehicleid : Vehicles)
	{
		if (!IsVehicleOccupied(vehicleid))
		{
			SetVehicleToRespawn(vehicleid);
		}
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerUpdate(playerid)
{
	if (IsValidPlayer(playerid))
	{
		if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new vehicleid = GetPlayerVehicleID(playerid), Float:oldHealth = Vehicle_GetHealth(vehicleid), Float:actualHealth;
			GetVehicleHealth(vehicleid, actualHealth);
			if (oldHealth > actualHealth && actualHealth < 1000.0 && (oldHealth - actualHealth) >= 1.0)
			{
				Vehicle_SetHealth(vehicleid, actualHealth);
				CallLocalFunction("OnVehicleHealthChange", "iiff", vehicleid, playerid, oldHealth, actualHealth);
			}
		}
	}
	return 1;
}