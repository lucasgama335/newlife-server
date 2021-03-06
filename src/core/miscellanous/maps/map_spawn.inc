#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsSpawnActor[3];
//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
	//=====================================[ 3DTEXT ]====================================||
	CreateDynamic3DTextLabel("{00e7c6}AJUDA PARA NOVATOS\n{FFFFFF}Aperte '{00e7c6}F{FFFFFF}'\n{FFFFFF}Em caso de d�vidas ou use o {00e7c6}/faq{FFFFFF}.", COLOR_CYAN, 809.5279, -1341.4880, 13.5405, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

	//=====================================[ PICKUPS ]====================================||
	CreateDynamicPickup(18749, 23, 809.5279, -1341.4880, 13.5405); // Faq Civil

	//=====================================[ OBJECTS ]====================================||
    CreateDynamicObject(984, 831.67279, -1337.40552, 13.17600,   0.00000, 0.00000, 270.02731);
	CreateDynamicObject(984, 807.74200, -1343.79578, 13.17600,   0.00000, 0.00000, 180.04680);
	CreateDynamicObject(984, 818.82452, -1337.40454, 13.17600,   0.00000, 0.00000, 270.02731);
	CreateDynamicObject(984, 807.72083, -1356.62610, 13.17600,   0.00000, 0.00000, 180.04680);
	CreateDynamicObject(16151, 813.50378, -1355.69995, 12.89320,   0.00000, 0.00000, 269.99991);
	CreateDynamicObject(1960, 816.19391, -1356.85400, 16.48420,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1961, 813.74866, -1356.83679, 16.48420,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1962, 811.13232, -1356.87634, 16.48420,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1281, 819.25311, -1347.92798, 13.35770,   0.00000, 0.00000, 336.66602);
	CreateDynamicObject(1281, 810.92346, -1345.45007, 13.35770,   0.00000, 0.00000, 283.87766);
	CreateDynamicObject(1895, 820.08832, -1356.77332, 14.38175,   0.00000, 0.00000, 181.04961);
	CreateDynamicObject(2779, 827.01501, -1352.18799, 12.52810,   0.00000, 0.00000, 269.34589);
	CreateDynamicObject(2681, 823.36914, -1356.34521, 12.53782,   0.00000, 0.00000, 178.44830);
	CreateDynamicObject(3524, 807.71112, -1337.46777, 14.78770,   0.00000, 0.00000, 176.72850);
	CreateDynamicObject(3524, 812.51752, -1337.46777, 14.78770,   0.00000, 0.00000, 176.72850);
	CreateDynamicObject(1211, 807.42511, -1334.90833, 13.16330,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1257, 788.50568, -1343.50232, 13.83060,   0.00000, 0.00000, 180.32394);
	CreateDynamicObject(3928, 821.79480, -1357.97192, 21.54770,   0.00000, 0.00000, 0.18194);
	CreateDynamicObject(3928, 821.95154, -1346.04065, 21.54770,   0.00000, 0.00000, 0.18194);
	CreateDynamicObject(19425, 818.10712, -1314.66602, 12.44510,   0.00000, 0.00000, 90.20050);
	CreateDynamicObject(19425, 818.17310, -1331.06067, 12.44510,   0.00000, 0.00000, 90.20050);
	CreateDynamicObject(19425, 818.15814, -1327.81409, 12.44510,   0.00000, 0.00000, 90.20050);
	CreateDynamicObject(19425, 818.14783, -1324.52307, 12.44510,   0.00000, 0.00000, 90.20050);
	CreateDynamicObject(19425, 818.13458, -1321.22791, 12.44510,   0.00000, 0.00000, 90.20050);
	CreateDynamicObject(19425, 818.11359, -1317.94946, 12.44510,   0.00000, 0.00000, 90.20050);
	CreateDynamicObject(19425, 791.10260, -1367.80286, 12.44510,   0.00000, 0.00000, 359.60959);
	CreateDynamicObject(19425, 800.85876, -1367.89038, 12.44510,   0.00000, 0.00000, 359.60959);
	CreateDynamicObject(19425, 797.59930, -1367.86084, 12.44510,   0.00000, 0.00000, 359.60959);
	CreateDynamicObject(19425, 794.33313, -1367.83374, 12.44510,   0.00000, 0.00000, 359.60959);
	CreateDynamicObject(3525, 827.12457, -1337.90149, 14.68521,   30.00000, 0.00000, 273.13669);
	CreateDynamicObject(3525, 827.12457, -1345.19983, 14.68520,   30.00000, 0.00000, 273.13669);
	CreateDynamicObject(3528, 808.97339, -1338.04126, 25.60128,   0.00000, 0.00000, 124.53519);
	CreateDynamicObject(3472, 813.31311, -1332.63416, 12.92700,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 803.51190, -1375.58606, 12.93470,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 791.32910, -1358.05798, 12.82314,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 803.40582, -1346.79749, 12.92730,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 855.28113, -1332.61523, 12.98700,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3472, 895.30341, -1332.64453, 12.92700,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19121, 827.47028, -1337.22717, 13.12340,   0.00000, 0.00000, 2.31780);
	CreateDynamicObject(19121, 843.16132, -1337.23657, 13.12340,   0.00000, 0.00000, 2.31780);
	CreateDynamicObject(638, 826.14819, -1337.89038, 13.23450,   0.00000, 0.00000, 90.22680);
	CreateDynamicObject(638, 823.48962, -1337.89038, 13.23450,   0.00000, 0.00000, 90.22680);
	CreateDynamicObject(638, 820.86060, -1337.89038, 13.23450,   0.00000, 0.00000, 90.22680);
	CreateDynamicObject(638, 818.26379, -1337.89038, 13.23450,   0.00000, 0.00000, 90.22680);
	CreateDynamicObject(638, 815.76697, -1337.89050, 13.23450,   0.00000, 0.00000, 90.22680);
	CreateDynamicObject(638, 814.02429, -1337.89038, 13.23450,   0.00000, 0.00000, 90.22680);
	CreateDynamicObject(638, 808.18732, -1355.59485, 13.23450,   0.00000, 0.00000, 359.83420);
	CreateDynamicObject(638, 808.18732, -1353.00305, 13.23450,   0.00000, 0.00000, 359.83420);
	CreateDynamicObject(638, 808.18732, -1347.69666, 13.23450,   0.00000, 0.00000, 359.83420);
	CreateDynamicObject(638, 808.18732, -1350.36963, 13.23450,   0.00000, 0.00000, 359.83420);
	CreateDynamicObject(638, 808.18732, -1342.38806, 13.23450,   0.00000, 0.00000, 359.83420);
	CreateDynamicObject(638, 808.18732, -1345.05481, 13.23450,   0.00000, 0.00000, 359.83420);
	CreateDynamicObject(638, 808.18732, -1339.73022, 13.23450,   0.00000, 0.00000, 359.83423);

    //=====================================[ ACTORS ]====================================||
    gsSpawnActor[0] = CreateDynamicActor(211, 808.8286,-1341.5260,13.5417,265.2473);
    ApplyDynamicActorAnimation(gsSpawnActor[0], "PED", "IDLE_CHAT", 4.1, true, false, false, false, 0);
	gsSpawnActor[1] = CreateDynamicActor(11, 815.7498,-1355.5166,13.5414,357.1111);
	gsSpawnActor[2] = CreateDynamicActor(189, 811.8927,-1355.5170,13.5414,0.5015);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    //=====================================[ REMOVE WORLD OBJECTS ]====================================||
    RemoveBuildingForPlayer(playerid, 1297, 802.7109, -1375.6875, 15.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1297, 792.0859, -1358.1172, 15.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 962, 825.0547, -1356.8828, 13.6016, 0.25);
	RemoveBuildingForPlayer(playerid, 1297, 802.7109, -1346.8359, 15.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1297, 813.3359, -1331.8828, 15.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 962, 827.5078, -1353.7266, 13.6016, 0.25);
	RemoveBuildingForPlayer(playerid, 1297, 855.3047, -1331.9219, 15.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 1297, 895.3047, -1331.8828, 15.6406, 0.25);

	//=====================================[ MAP ICONS ]====================================||
	return 1;
}