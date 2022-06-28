#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#if       defined MAX_VEHICLES
#undef    MAX_VEHICLES
#define   MAX_VEHICLES   10 + 1 // Sempre Será a Soma das Variáveis de Carros + 1
#endif

#define MAX_PLATE_STRING    9
//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum vInfo
{
    bool:vEngine,
	vFuel,
	vShield,
	bool:vLocked,
	vPlate[MAX_PLATE_STRING],
    vMoney,
	bool:vBroken
}
static VehicleInfo[MAX_VEHICLES][vInfo];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ============== ENGINE ACCESSORS ============== //
// Getters
stock bool:Vehicle_GetEngineStatus(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return VehicleInfo[vehicleid][vEngine];
}

// Setters
stock bool:Vehicle_SetEngineStatus(vehicleid, bool:status)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return VehicleInfo[vehicleid][vEngine] = status;
}

// ============== FUEL ACCESSORS ============== //
// Getters
stock Vehicle_GetFuel(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return VehicleInfo[vehicleid][vFuel];
}

// Setters
stock Vehicle_SetFuel(vehicleid, quantity)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return VehicleInfo[vehicleid][vFuel] = quantity;
}

// ============== SHIELD ACCESSORS ============== //
// Getters
stock Vehicle_GetShield(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return VehicleInfo[vehicleid][vShield];
}

// Setters
stock Vehicle_SetShield(vehicleid, quantity)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return VehicleInfo[vehicleid][vShield] = quantity;
}

// ============== LOCK ACCESSORS ============== //
// Getters
stock bool:Vehicle_GetLockedStatus(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return VehicleInfo[vehicleid][vLocked];
}

// Setters
stock bool:Vehicle_SetLockedStatus(vehicleid, bool:status)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return VehicleInfo[vehicleid][vLocked] = status;
}

// ============== PLATE ACCESSORS ============== //
// Getters
stock Vehicle_GetPlate(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    new string[MAX_PLATE_STRING];
    format(string, sizeof(string), "%s", VehicleInfo[vehicleid][vPlate]);
    return string;
}

// Setters
stock Vehicle_SetPlate(vehicleid, const string[])
{
    if (!IsValidVehicle(vehicleid)) return 0;

    format(VehicleInfo[vehicleid][vPlate], MAX_PLATE_STRING, "%s", string);
    return 1;
}

// ============== MONEY ACCESSORS ============== //
// Getters
stock Vehicle_GetMoney(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return VehicleInfo[vehicleid][vMoney];
}

// Setters
stock Vehicle_SetMoney(vehicleid, quantity)
{
    if (!IsValidVehicle(vehicleid)) return 0;

    return VehicleInfo[vehicleid][vMoney] = quantity;
}

// ============== BROKEN ACCESSORS ============== //
// Getters
stock bool:Vehicle_GetBrokenStatus(vehicleid)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return VehicleInfo[vehicleid][vBroken];
}

// Setters
stock bool:Vehicle_SetBrokenStatus(vehicleid, bool:status)
{
    if (!IsValidVehicle(vehicleid)) return false;

    return VehicleInfo[vehicleid][vBroken] = status;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    new engine, lights, alarm, doors, bonnet, boot, objective;
    for (new i = 0; i < MAX_VEHICLES; i++)
    {
        VehicleInfo[i][vEngine] = false;
        VehicleInfo[i][vFuel] = 100;
        VehicleInfo[i][vShield] = 0;
        VehicleInfo[i][vLocked] = false;
        format(VehicleInfo[i][vPlate], MAX_PLATE_STRING, "");
        VehicleInfo[i][vMoney] = 0;
        VehicleInfo[i][vBroken] = false;
        GetVehicleParamsEx(i, engine, lights, alarm, doors, bonnet, boot, objective);
	    SetVehicleParamsEx(i, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
    }
    return 1;
}