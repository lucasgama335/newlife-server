#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define DRIVE_SCHOOL_VEHICLES_WORLD     2

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsDriveSchoolVehicle[6];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_IsDriveSchoolVehicle(vehicleid)
{
    for(new x; x < sizeof(gsCivilVehicle); x++)
    {
        if (vehicleid != INVALID_VEHICLE_ID && vehicleid == x) return true;
    }
    return false;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    // Cars
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[0] = AddStaticVehicleCustom(565, -2064.0432, -84.2278, 34.7861, 1.6584, 1, 1, 120), DRIVE_SCHOOL_VEHICLES_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[1] = AddStaticVehicleCustom(565, -2068.5283, -84.2602, 34.7877, 359.0264, 1, 1, 120), DRIVE_SCHOOL_VEHICLES_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[2] = AddStaticVehicleCustom(565, -2072.3540, -84.4661, 34.7862, 1.6590, 1, 1, 120), DRIVE_SCHOOL_VEHICLES_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[3] = AddStaticVehicleCustom(565, -2077.1116, -84.4996, 34.7805, 1.4970, 1, 1, 120), DRIVE_SCHOOL_VEHICLES_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[4] = AddStaticVehicleCustom(565, -2081.3203, -84.5677, 34.7859, 0.7005, 1, 1, 120), DRIVE_SCHOOL_VEHICLES_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[5] = AddStaticVehicleCustom(565, -2085.5923, -84.5648, 34.7813, 0.7005, 1, 1, 120), DRIVE_SCHOOL_VEHICLES_WORLD);
    return 1;
}

hook OnVehicleSpawn(vehicleid)
{
	if (Vehicle_IsCivilVehicle(vehicleid))
	{
		Vehicle_SetFuel(vehicleid, 100);
	}
	return 1;
}
