#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsEletricianVehicle[7];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsEletricianVehicle[0] = AddStaticVehicleCustom(552, 785.7985, -610.5449, 15.9854, 0.0000, 49, 49, 120);
	gsEletricianVehicle[1] = AddStaticVehicleCustom(552, 833.4150, -609.2629, 15.9854, 89.3804, 49, 49, 120);
	gsEletricianVehicle[2] = AddStaticVehicleCustom(552, 789.9179, -610.5449, 15.9854, 0.0000, 49, 49, 120);
	gsEletricianVehicle[3] = AddStaticVehicleCustom(552, 803.5684, -610.5449, 15.9854, 0.0000, 49, 49, 120);
	gsEletricianVehicle[4] = AddStaticVehicleCustom(552, 813.0129, -610.5449, 15.9854, 0.0000, 49, 49, 120);
	gsEletricianVehicle[5] = AddStaticVehicleCustom(552, 782.6633, -600.8454, 15.9854, 271.3911, 49, 49, 120);
	gsEletricianVehicle[6] = AddStaticVehicleCustom(552, 820.5369, -610.5449, 15.9854, 0.0000, 49, 49, 120);
	for(new i; i < sizeof(gsEletricianVehicle); i++)
	{
        Vehicle_SetJob(i, j_JOB_ELETRICIAN);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
