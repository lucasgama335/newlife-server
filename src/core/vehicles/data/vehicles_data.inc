#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#if defined MAX_VEHICLES
#undef  MAX_VEHICLES
#define MAX_VEHICLES   10 + 1 // Sempre Será a Soma das Variáveis de Carros + 1
#endif

#define MAX_PLATE_STRING    9

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum v_VEHICLE_DATA
{
    bool:v_ENGINE,
	v_FUEL,
	v_SHIELD,
	bool:v_LOCKED,
	v_PLATE[MAX_PLATE_STRING],
    v_MONEY,
	bool:v_BROKEN
}
static gsVehicleInfo[MAX_VEHICLES][v_VEHICLE_DATA];

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

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    new engine, lights, alarm, doors, bonnet, boot, objective;
    for (new i = 0; i < MAX_VEHICLES; i++)
    {
        gsVehicleInfo[i][v_ENGINE] = false;
        gsVehicleInfo[i][v_FUEL] = 100;
        gsVehicleInfo[i][v_SHIELD] = 0;
        gsVehicleInfo[i][v_LOCKED] = false;
        format(gsVehicleInfo[i][v_PLATE], MAX_PLATE_STRING, "");
        gsVehicleInfo[i][v_MONEY] = 0;
        gsVehicleInfo[i][v_BROKEN] = false;
        GetVehicleParamsEx(i, engine, lights, alarm, doors, bonnet, boot, objective);
	    SetVehicleParamsEx(i, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
    }
    return 1;
}
