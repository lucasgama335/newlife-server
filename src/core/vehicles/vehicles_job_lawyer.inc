#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsLawyerVehicle[8];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsLawyerVehicle[0] = AddStaticVehicleCustom(471, 1097.1378, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[1] = AddStaticVehicleCustom(471, 1095.7000, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[2] = AddStaticVehicleCustom(471, 1094.2000, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[3] = AddStaticVehicleCustom(471, 1092.7000, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[4] = AddStaticVehicleCustom(471, 1091.1500, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[5] = AddStaticVehicleCustom(471, 1089.7000, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[6] = AddStaticVehicleCustom(471, 1088.2000, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	gsLawyerVehicle[7] = AddStaticVehicleCustom(471, 1086.7000, -1803.0062, 13.0120, 0.0000, 0, 0, 120);
	for(new i; i < sizeof(gsLawyerVehicle); i++)
	{
        Vehicle_SetJob(i, j_JOB_LAWYER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
