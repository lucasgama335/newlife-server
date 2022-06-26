#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static CivilVehicle[10];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_IsCivilVehicle(vehicleid)
{
    for(new x; x < sizeof(CivilVehicle); x++)
    {
        if (vehicleid == x) return true;
    }
    return false;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    CivilVehicle[0] = AddStaticVehicleEx(462, 841.7307, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[1] = AddStaticVehicleEx(462, 828.5796, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[2] = AddStaticVehicleEx(462, 829.7737, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[3] = AddStaticVehicleEx(462, 831.2488, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[4] = AddStaticVehicleEx(462, 832.7236, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[5] = AddStaticVehicleEx(462, 834.2357, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[6] = AddStaticVehicleEx(462, 835.6768, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[7] = AddStaticVehicleEx(462, 837.2051, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[8] = AddStaticVehicleEx(462, 838.7051, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	CivilVehicle[9] = AddStaticVehicleEx(462, 840.1488, -1336.1260, 13.0684, 0.0000, 7, 7, 90);
	for(new x; x < sizeof(CivilVehicle); x++)
	{
		new string[80];
	    format(string, sizeof string, "{00BFFF}%s\n{FFFFFF}•• Veículo Civil ••", Vehicle_GetName(GetVehicleModel(CivilVehicle[x])));
		new Text3D:textVehicle = Create3DTextLabel(string, 0xFFFFFFFF, 0.0, 0.0, 0.0, 10.0, 0);
		Attach3DTextLabelToVehicle(textVehicle, CivilVehicle[x], 0.0, 0.0, 0.0);
	}
    return 1;
}