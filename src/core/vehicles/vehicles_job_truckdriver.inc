#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsTruckdriverVehicle[7];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsTruckdriverVehicle[0] = AddStaticVehicleCustom(573,-77.0928,-1106.8040,1.5164,160.0013,0,0,120);
    gsTruckdriverVehicle[1] = AddStaticVehicleCustom(573,-71.3447,-1109.8883,1.5159,158.8741,0,0,120);
    gsTruckdriverVehicle[2] = AddStaticVehicleCustom(455,-66.1184,-1111.7091,1.5159,158.6986,0,0,120);
    gsTruckdriverVehicle[3] = AddStaticVehicleCustom(573,-45.4056,-1136.1332,1.5147,70.0738,0,0,120);
    gsTruckdriverVehicle[4] = AddStaticVehicleCustom(455,-59.6849,-1130.6948,1.5150,69.0487,0,0,120);
    gsTruckdriverVehicle[5] = AddStaticVehicleCustom(455,-45.0255,-1155.7328,1.5148,62.4110,0,0,120);
    gsTruckdriverVehicle[6] = AddStaticVehicleCustom(455,-59.5375,-1148.5664,1.5147,63.9188,0,0,120);
	for(new i; i < sizeof(gsTruckdriverVehicle); i++)
	{
        Vehicle_SetJob(i, j_JOB_TRUCK_DRIVER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
