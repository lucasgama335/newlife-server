#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define DRIVE_SCHOOL_VEHICLES_WORLD     1
#define DRIVE_SCHOOL_MOTORCYCLE_WORLD   2
#define DRIVE_SCHOOL_FLY_WORLD          3
#define DRIVE_SCHOOL_BOAT_WORLD         4
#define DRIVE_SCHOOL_TRUCK_WORLD        5

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsDriveSchoolVehicle[28];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_IsgsDriveSchoolVehicle(vehicleid)
{
    for(new x; x < sizeof(gsCivilVehicle); x++)
    {
        if (vehicleid != INVALID_VEHICLE_ID && vehicleid == x) return true;
    }
    return false;
}

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
    // Motorcycle
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[6] = AddStaticVehicleCustom(468, 1541.0002, 12.4282, 23.8126, 277.5054, 1, 1, 120), DRIVE_SCHOOL_MOTORCYCLE_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[7] = AddStaticVehicleCustom(468, 1540.6710, 14.9252, 23.8140, 277.5027, 1, 1, 120), DRIVE_SCHOOL_MOTORCYCLE_WORLD); 
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[8] = AddStaticVehicleCustom(468, 1540.1096, 19.1900, 23.8125, 277.5016, 1, 1, 120), DRIVE_SCHOOL_MOTORCYCLE_WORLD); 
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[9] = AddStaticVehicleCustom(468, 1545.0325, 19.8383, 23.8188, 277.5047, 1, 1, 120), DRIVE_SCHOOL_MOTORCYCLE_WORLD); 
    // Fly
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[10] = AddStaticVehicleCustom(487, -1089.9575, -218.9052, 14.3207, 115.9937, 1, 1, 120), DRIVE_SCHOOL_FLY_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[11] = AddStaticVehicleCustom(487, -1096.2766, -200.4023, 14.3166, 105.0555, 1, 1, 120), DRIVE_SCHOOL_FLY_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[12] = AddStaticVehicleCustom(487, -1105.4413, -177.2243, 14.3165, 113.9803, 1, 1, 120), DRIVE_SCHOOL_FLY_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[13] = AddStaticVehicleCustom(487, -1114.0913, -160.5246, 14.2984, 130.4268, 1, 1, 120), DRIVE_SCHOOL_FLY_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[14] = AddStaticVehicleCustom(487, -1131.1014, -176.5821, 14.2935, 227.0690, 1, 1, 120), DRIVE_SCHOOL_FLY_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[15] = AddStaticVehicleCustom(487, -1143.3826, -189.0831, 14.2980, 220.3932, 1, 1, 120), DRIVE_SCHOOL_FLY_WORLD);
    // Boat
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[16] = AddStaticVehicleCustom(452, 2559.0430, -2236.1729, -0.5346, 181.4808, 1, 1, 120), DRIVE_SCHOOL_BOAT_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[17] = AddStaticVehicleCustom(452, 2564.9790, -2236.3120, -0.5119, 181.8161, 1, 1, 120), DRIVE_SCHOOL_BOAT_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[18] = AddStaticVehicleCustom(452, 2572.7480, -2236.2266, -0.5601, 181.7540, 1, 1, 120), DRIVE_SCHOOL_BOAT_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[19] = AddStaticVehicleCustom(452, 2579.3298, -2235.6895, -0.6928, 183.2329, 1, 1, 120), DRIVE_SCHOOL_BOAT_WORLD);
    // Truck
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[20] = AddStaticVehicleCustom(437, -2105.0027, -255.6560, 35.4345, 91.7755, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[21] = AddStaticVehicleCustom(437, -2105.3179, -245.5108, 35.4345, 91.7755, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[22] = AddStaticVehicleCustom(515, -2105.6106, -235.4750, 36.3107, 91.7756, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[23] = AddStaticVehicleCustom(514, -2105.8887, -226.5475, 35.9176, 91.7757, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[24] = AddStaticVehicleCustom(524, -2106.0735, -220.2445, 36.2335, 91.7755, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[25] = AddStaticVehicleCustom(524, -2106.2925, -213.4201, 36.2838, 91.7754, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[26] = AddStaticVehicleCustom(578, -2106.4944, -206.9728, 35.9730, 91.7756, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
    SetVehicleVirtualWorld(gsDriveSchoolVehicle[27] = AddStaticVehicleCustom(578, -2106.7085, -200.1200, 35.9644, 91.7662, 1, 1, 120), DRIVE_SCHOOL_TRUCK_WORLD);
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

//------------------------- Commands (Module related commands) -------------------------
