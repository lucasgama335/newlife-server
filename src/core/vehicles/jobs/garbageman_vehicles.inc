#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsGarbagemanVehicle[7];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsGarbagemanVehicle[0] = AddStaticVehicleCustom(408, 2192.1487, -2001.1305, 14.1199, 15.2576, 222, 222, 120);
    gsGarbagemanVehicle[1] = AddStaticVehicleCustom(408, 2182.0667, -1994.4392, 14.0547, 3.0342, 222, 222, 120);
    gsGarbagemanVehicle[2] = AddStaticVehicleCustom(408, 2168.0544, -1985.2347, 14.1076, 288.5309, 222, 222, 120);
    gsGarbagemanVehicle[3] = AddStaticVehicleCustom(408, 2166.4185, -1977.3701, 14.1180, 269.5326, 222, 222, 120);
    gsGarbagemanVehicle[4] = AddStaticVehicleCustom(574, 2191.0659, -1970.2592, 13.2851, 179.6430, 222, 222, 120);
    gsGarbagemanVehicle[5] = AddStaticVehicleCustom(574, 2199.9680, -1981.3427, 13.2738, 266.8454, 222, 222, 120);
    gsGarbagemanVehicle[6] = AddStaticVehicleCustom(574, 2198.5291, -1973.2627, 13.2721, 267.3567, 222, 222, 120);
	for(new i; i < sizeof(gsGarbagemanVehicle); i++)
	{
        Vehicle_SetJob(gsGarbagemanVehicle[i], j_JOB_GARBAGEMAN);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
