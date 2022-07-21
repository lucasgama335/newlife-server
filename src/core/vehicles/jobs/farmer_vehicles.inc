#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsFarmerVehicle[16];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsFarmerVehicle[0] = AddStaticVehicleCustom(478, -104.0294, 21.2154, 3.1008, 71.1420, 123, 123, 120);
    gsFarmerVehicle[1] = AddStaticVehicleCustom(478, -105.1591, 17.8962, 3.1178, 70.9494, 123, 123, 120);
    gsFarmerVehicle[2] = AddStaticVehicleCustom(532, -144.0899, -26.4988, 4.1048, 68.7358, 123, 123, 6);
    gsFarmerVehicle[3] = AddStaticVehicleCustom(532, -148.3455, -37.3181, 4.1175, 69.0380, 123, 123, 6);
    gsFarmerVehicle[4] = AddStaticVehicleCustom(532, -152.9424, -49.1943, 4.1113, 68.4839, 123, 123, 6);
    gsFarmerVehicle[5] = AddStaticVehicleCustom(532, -157.3899, -60.7060, 4.1071, 68.7686, 123, 123, 6);
    gsFarmerVehicle[6] = AddStaticVehicleCustom(532, -161.8511, -72.1839, 4.1083, 67.9523, 123, 123, 6);
    gsFarmerVehicle[7] = AddStaticVehicleCustom(532, -166.1422, -82.9460, 4.1012, 69.1633, 123, 123, 6);
    gsFarmerVehicle[8] = AddStaticVehicleCustom(532, -170.7140, -94.7801, 4.1077, 68.5404, 123, 123, 6);
    gsFarmerVehicle[9] = AddStaticVehicleCustom(531, -107.2946, -33.5133, 3.0914, 71.9753, 123, 123, 6);
    gsFarmerVehicle[10] = AddStaticVehicleCustom(531, -108.1915, -36.3194, 3.0891, 64.8776, 123, 123, 6);
    gsFarmerVehicle[11] = AddStaticVehicleCustom(531, -108.3720, -38.4900, 3.0959, 64.8136, 123, 123, 6);
    gsFarmerVehicle[12] = AddStaticVehicleCustom(531, -109.3939, -40.7166, 3.0880, 71.1545, 123, 123, 6);
    gsFarmerVehicle[13] = AddStaticVehicleCustom(531, -110.4327, -42.7631, 3.0895, 73.6873, 123, 123, 6);
    gsFarmerVehicle[14] = AddStaticVehicleCustom(531, -109.5616, -45.1875, 3.0781, 69.8836, 123, 123, 6);
    gsFarmerVehicle[15] = AddStaticVehicleCustom(531, -106.4333, -48.2856, 3.0870, 73.9065, 123, 123, 6);
	for(new i; i < sizeof(gsFarmerVehicle); i++)
	{
        Vehicle_SetJob(gsFarmerVehicle[i], j_JOB_FARMER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
