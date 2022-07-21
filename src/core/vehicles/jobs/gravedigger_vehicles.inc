#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsGravediggerVehicle[5];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsGravediggerVehicle[0] = AddStaticVehicleCustom(442, 869.7429, -1107.9686, 24.0293, 268.8243, 0, 0, 120);
	gsGravediggerVehicle[1] = AddStaticVehicleCustom(442, 861.3201, -1097.7219, 24.1539, 270.9617, 0, 0, 120);
	gsGravediggerVehicle[2] = AddStaticVehicleCustom(442, 853.1974, -1091.1332, 24.0277, 187.0366, 0, 0, 120);
	gsGravediggerVehicle[3] = AddStaticVehicleCustom(442, 835.1767, -1092.6215, 24.0354, 180.8675, 0, 0, 120);
	gsGravediggerVehicle[4] = AddStaticVehicleCustom(442, 835.0997, -1111.1815, 23.9121, 0.8723, 0, 0, 120);
	for(new i; i < sizeof(gsGravediggerVehicle); i++)
	{
        Vehicle_SetJob(gsGravediggerVehicle[i], j_JOB_GRAVEDIGGER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
