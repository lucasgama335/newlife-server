#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsBusdriverVehicle[6];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsBusdriverVehicle[0] = AddStaticVehicleCustom(437, 1791.6146, -2350.6851, 13.5544, 181.3456, 6, 6, 120);
	gsBusdriverVehicle[1] = AddStaticVehicleCustom(437, 1786.4606, -2350.7319, 13.6762, 181.6334, 6, 6, 120);
	gsBusdriverVehicle[2] = AddStaticVehicleCustom(437, 1781.6776, -2350.5740, 13.6679, 180.0032, 6, 6, 120);
	gsBusdriverVehicle[3] = AddStaticVehicleCustom(437, 1786.6947, -2362.9531, 13.7514, 180.0976, 6, 6, 120);
	gsBusdriverVehicle[4] = AddStaticVehicleCustom(437, 1781.7631, -2362.8447, 13.6653, 179.7903, 6, 6, 120);
	gsBusdriverVehicle[5] = AddStaticVehicleCustom(437, 1791.8979, -2362.7944, 13.6768, 180.7691, 6, 6, 120);
	for(new i; i < sizeof(gsBusdriverVehicle); i++)
	{
        Vehicle_SetJob(gsBusdriverVehicle[i], j_JOB_BUS_DRIVER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
