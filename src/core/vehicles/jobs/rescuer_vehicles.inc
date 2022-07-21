#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsRescuerVehicle[7];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsRescuerVehicle[0] = AddStaticVehicleCustom(416, 2039.7706, -1419.3419, 17.2318, 89.5749, -1, -1, 120);
	gsRescuerVehicle[1] = AddStaticVehicleCustom(416, 2039.7706, -1429.0637, 17.2318, 89.5749, -1, -1, 120);
	gsRescuerVehicle[2] = AddStaticVehicleCustom(416, 2039.7706, -1424.6201, 17.2318, 89.5749, -1, -1, 120);
	gsRescuerVehicle[3] = AddStaticVehicleCustom(416, 2015.5696, -1412.3545, 17.2318, 180.5917, -1, -1, 120);
	gsRescuerVehicle[4] = AddStaticVehicleCustom(416, 2010.6547, -1412.3545, 17.2318, 180.5917, -1, -1, 120);
	gsRescuerVehicle[5] = AddStaticVehicleCustom(407, 2033.3182, -1447.9312, 17.4290, 89.7876, -1, -1, 120);
	gsRescuerVehicle[6] = AddStaticVehicleCustom(407, 2033.7844, -1439.4271, 17.4290, 2.7910, -1, -1, 120);
	for(new i; i < sizeof(gsRescuerVehicle); i++)
	{
        Vehicle_SetJob(gsRescuerVehicle[i], j_JOB_RESCUER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
