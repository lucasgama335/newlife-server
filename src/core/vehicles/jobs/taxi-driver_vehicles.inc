#include <vehicles_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsTaxidriverVehicle[17];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsTaxidriverVehicle[0] = AddStaticVehicleCustom(420, 605.1246, -1492.9877, 14.7557, 182.7744, 6, 6, 120);
	gsTaxidriverVehicle[1] = AddStaticVehicleCustom(420, 601.6041, -1493.0991, 14.8483, 181.7202, 6, 6, 120);
	gsTaxidriverVehicle[2] = AddStaticVehicleCustom(420, 597.6719, -1493.1132, 14.9603, 181.3787, 6, 6, 120);
	gsTaxidriverVehicle[3] = AddStaticVehicleCustom(420, 593.0160, -1492.9611, 15.0972, 178.4337, 6, 6, 120);
	gsTaxidriverVehicle[4] = AddStaticVehicleCustom(420, 589.6412, -1497.5894, 15.1535, 271.6431, 6, 6, 120);
	gsTaxidriverVehicle[5] = AddStaticVehicleCustom(420, 590.7183, -1501.7946, 15.1433, 270.3393, 6, 6, 120);
	gsTaxidriverVehicle[6] = AddStaticVehicleCustom(438, 591.5882, -1506.8800, 15.1575, 268.3453, 6, 6, 120);
	gsTaxidriverVehicle[7] = AddStaticVehicleCustom(438, 592.5615, -1512.0110, 15.1176, 275.3553, 6, 6, 120);
	gsTaxidriverVehicle[8] = AddStaticVehicleCustom(438, 592.4547, -1516.8672, 15.2743, 268.3280, 6, 6, 120);
	gsTaxidriverVehicle[9] = AddStaticVehicleCustom(438, 592.1617, -1522.4406, 14.9748, 272.1155, 6, 6, 120);
	gsTaxidriverVehicle[10] = AddStaticVehicleCustom(586, 603.7915, -1521.6503, 14.5812, 3.6367, 6, 6, 120);
	gsTaxidriverVehicle[11] = AddStaticVehicleCustom(586, 605.6815, -1521.6954, 14.5907, 1.6267, 6, 6, 120);
	gsTaxidriverVehicle[12] = AddStaticVehicleCustom(586, 607.7949, -1521.6332, 14.5936, 3.0334, 6, 6, 120);
	gsTaxidriverVehicle[13] = AddStaticVehicleCustom(586, 610.3909, -1521.5165, 14.5967, 7.8216, 6, 6, 120);
	gsTaxidriverVehicle[14] = AddStaticVehicleCustom(586, 613.1254, -1521.1260, 14.5926, 3.2060, 6, 6, 120);
	gsTaxidriverVehicle[15] = AddStaticVehicleCustom(487, 600.7764, -1530.1740, 31.0452, 1.4917, 6, 6, 120);
	gsTaxidriverVehicle[16] = AddStaticVehicleCustom(487, 611.9767, -1531.8496, 31.0145, 358.2441, 6, 6, 120);
	for(new i; i < sizeof(gsTaxidriverVehicle); i++)
	{
        Vehicle_SetJob(gsTaxidriverVehicle[i], j_JOB_TAXI_DRIVER);
	}
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
