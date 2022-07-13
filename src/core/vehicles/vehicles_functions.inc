#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Iterator:Vehicles<MAX_VEHICLES>;
static const Float:gsPaynsprayLocales[][] =
{
    {1025.05, -1024.23, 32.1}, // LS Temple
    {487.68, -1740.87, 11.13}, // LS Santa Maria
    {-1420.73, 2583.37, 55.56}, // El Quebrados
    {-1904.39, 284.97, 40.75}, // Wang Cars
    {-2425.91, 1022.33, 50.10}, // Juniper Hill
    {1975.60, 2162.16, 10.77}, // LV Redsands
    {2065.38, -1831.51, 13.25}, // Idlewood
    {-99.55, 1118.36, 19.44}, // Fort Carson
    {721.07, -455.94, 16.04}, // Dillimore
    {2393.74, 1493.01, 10.52} // LV Unused (Pyramid)
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

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
		Vehicle_SetHealth(tempVehicleId, MAX_VEHICLE_HEALTH);
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
		if (Vehicle_GetEngineStatus(vehicleid) && !Vehicle_IsBike(GetVehicleModel(vehicleid)))
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

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerUpdate(playerid)
{
	if (IsValidPlayer(playerid))
	{
		if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new vehicleid = GetPlayerVehicleID(playerid), Float:oldHealth = Vehicle_GetHealth(vehicleid), Float:actualHealth;
			GetVehicleHealth(vehicleid, actualHealth);

			if(actualHealth == 1000.0)
			{
				SetVehicleHealth(vehicleid, MAX_VEHICLE_HEALTH);
				Vehicle_SetHealth(vehicleid, MAX_VEHICLE_HEALTH);
				for(new i = sizeof(gsPaynsprayLocales) - 1; i != -1; --i)
				{
					if(IsPlayerInRangeOfPoint(playerid, 10.0, gsPaynsprayLocales[i][0], gsPaynsprayLocales[i][1], gsPaynsprayLocales[i][2]))
					{
						CallRemoteFunction("OnVehicleRespray", "iiii", playerid, vehicleid, -1, -1);
						return 1;
					}
				}
			}

			
			if (oldHealth != actualHealth && (oldHealth - actualHealth) >= 1.0)
			{
				Vehicle_SetHealth(vehicleid, actualHealth);
				CallLocalFunction("OnVehicleHealthChange", "iiff", vehicleid, playerid, oldHealth, actualHealth);
				return 1;
			}
		}
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
