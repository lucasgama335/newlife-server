#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#if defined MAX_VEHICLES
#undef  MAX_VEHICLES
#define MAX_VEHICLES   118 + 1 // Sempre Será a Soma das Variáveis de Carros + 1
#endif

#define MAX_PLATE_STRING    9

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum v_VEHICLE_DATA
{
    bool:v_ENGINE,
    Float:v_HEALTH,
	v_FUEL,
	v_SHIELD,
	bool:v_LOCKED,
	v_PLATE[MAX_PLATE_STRING],
    v_MONEY,
	bool:v_BROKEN,
    v_COLOR_ONE,
    v_COLOR_TWO,
    j_JOBS_LIST:v_VEHICLE_JOB
}
static gsVehicleInfo[MAX_VEHICLES][v_VEHICLE_DATA];
static Iterator:Vehicles<MAX_VEHICLES>;

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== ENGINE ACCESSORS ============== //
// Getters
stock bool:Vehicle_GetEngineStatus(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return gsVehicleInfo[vehicleid][v_ENGINE];
}

// Setters
stock bool:Vehicle_SetEngineStatus(vehicleid, bool:status)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return gsVehicleInfo[vehicleid][v_ENGINE] = status;
}

// ============== HEALTH ACCESSORS ============== //
// Getters
stock Float:Vehicle_GetHealth(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0.0;

    return gsVehicleInfo[vehicleid][v_HEALTH];
}

// Setters
stock Vehicle_SetHealth(vehicleid, Float:health)
{
    if (IsValidVehicle(vehicleid))
    {
        gsVehicleInfo[vehicleid][v_HEALTH] = health;
    }
    return 1;
}

// ============== FUEL ACCESSORS ============== //
// Getters
stock Vehicle_GetFuel(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_FUEL];
}

// Setters
stock Vehicle_SetFuel(vehicleid, quantity)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_FUEL] = quantity;
}

// ============== SHIELD ACCESSORS ============== //
// Getters
stock Vehicle_GetShield(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_SHIELD];
}

// Setters
stock Vehicle_SetShield(vehicleid, quantity)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_SHIELD] = quantity;
}

// ============== LOCK ACCESSORS ============== //
// Getters
stock bool:Vehicle_GetLockedStatus(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return gsVehicleInfo[vehicleid][v_LOCKED];
}

// Setters
stock bool:Vehicle_SetLockedStatus(vehicleid, bool:status)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return gsVehicleInfo[vehicleid][v_LOCKED] = status;
}

// ============== PLATE ACCESSORS ============== //
// Getters
stock Vehicle_GetPlate(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    new string[MAX_PLATE_STRING];
    format(string, sizeof(string), "%s", gsVehicleInfo[vehicleid][v_PLATE]);
    return string;
}

// Setters
stock Vehicle_SetPlate(vehicleid, const string[])
{
    if (!IsValidVehicle(vehicleid)) return 0;

    format(gsVehicleInfo[vehicleid][v_PLATE], MAX_PLATE_STRING, "%s", string);
    return 1;
}

// ============== MONEY ACCESSORS ============== //
// Getters
stock Vehicle_GetMoney(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_MONEY];
}

// Setters
stock Vehicle_SetMoney(vehicleid, quantity)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_MONEY] = quantity;
}

// ============== BROKEN ACCESSORS ============== //
// Getters
stock bool:Vehicle_GetBrokenStatus(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return gsVehicleInfo[vehicleid][v_BROKEN];
}

// Setters
stock bool:Vehicle_SetBrokenStatus(vehicleid, bool:status)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return gsVehicleInfo[vehicleid][v_BROKEN] = status;
}

// ============== COLORS ACCESSORS ============== //
// Getters
stock Vehicle_GetColorOne(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_COLOR_ONE];
}

stock Vehicle_GetColorTwo(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return gsVehicleInfo[vehicleid][v_COLOR_TWO];
}

// Setters
stock Vehicle_SetColor(vehicleid, colorOne, colorTwo)
{
    if (!IsValidVehicle(vehicleid)) return false;

    gsVehicleInfo[vehicleid][v_COLOR_ONE] = colorOne;
    gsVehicleInfo[vehicleid][v_COLOR_TWO] = colorTwo;
    return 1;
}

// ============== JOB ACCESSORS ============== //
// Getters
stock j_JOBS_LIST:Vehicle_GetJob(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return j_JOB_NONE;

    return gsVehicleInfo[vehicleid][v_VEHICLE_JOB];
}

// Setters
stock Vehicle_SetJob(vehicleid, j_JOBS_LIST:jobId)
{
    if (!IsValidVehicle(vehicleid)) return false;

    gsVehicleInfo[vehicleid][v_VEHICLE_JOB] = jobId;
    return 1;
}

// ============== CUSTOM FUNCTIONS ============== //
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
		Vehicle_SetJob(tempVehicleId, j_JOB_NONE);
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

//------------------------- Commands (Module related commands) -------------------------

