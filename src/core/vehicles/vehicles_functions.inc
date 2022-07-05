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
		Vehicle_SetFuel(tempVehicleId, 100);
		Vehicle_SetShield(tempVehicleId, 0);
		Vehicle_SetMoney(tempVehicleId, 0);
		Vehicle_SetBrokenStatus(tempVehicleId, false);
		Vehicle_SetLockedStatus(tempVehicleId, false);
		Vehicle_SetPlate(tempVehicleId, "");
		Vehicle_SetEngine(tempVehicleId, false);
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
			if (!IsVehicleBusy(vehicleid))
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
		if (Vehicle_GetFuel(vehicleid) > 0 && Vehicle_GetEngineStatus(vehicleid))
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

stock VehicleDecreaseGlobalShield()
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
		if (!IsVehicleBusy(vehicleid))
		{
			SetVehicleToRespawn(vehicleid);
		}
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
