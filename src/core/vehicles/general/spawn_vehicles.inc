#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsCivilVehicle[10];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_IsCivilVehicle(vehicleid)
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
    gsCivilVehicle[0] = AddStaticVehicleCustom(462, 841.7307, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[1] = AddStaticVehicleCustom(462, 828.5796, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[2] = AddStaticVehicleCustom(462, 829.7737, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[3] = AddStaticVehicleCustom(462, 831.2488, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[4] = AddStaticVehicleCustom(462, 832.7236, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[5] = AddStaticVehicleCustom(462, 834.2357, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[6] = AddStaticVehicleCustom(462, 835.6768, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[7] = AddStaticVehicleCustom(462, 837.2051, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[8] = AddStaticVehicleCustom(462, 838.7051, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	gsCivilVehicle[9] = AddStaticVehicleCustom(462, 840.1488, -1336.1260, 13.0684, 0.0000, 7, 7, 90, false);
	new string[50], vehicleName[MAX_VEHICLE_NAME_STRING];
	for(new x; x < sizeof(gsCivilVehicle); x++)
	{
		GetVehicleName(GetVehicleModel(gsCivilVehicle[x]), vehicleName);
		format(string, sizeof string, "{00BFFF}%s\n{FFFFFF}•• Veículo Civil ••", vehicleName);
		new Text3D:textVehicle = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, 0.0, 0.0, 0.0, 10.0, INVALID_PLAYER_ID, gsCivilVehicle[x], 0);
		Attach3DTextLabelToVehicle(textVehicle, gsCivilVehicle[x], 0.0, 0.0, 0.0);
	}
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
