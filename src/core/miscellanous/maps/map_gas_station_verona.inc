#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{

	//=====================================[ 3DTEXT ]====================================||

	//=====================================[ PICKUPS ]====================================||

	//=====================================[ OBJECTS ]====================================||
    new tmpobjid;
	tmpobjid = CreateDynamicObject(19545, 827.692993, -1728.829956, 12.546998, 0.000000, 0.000000, 0.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "concretemanky", 0x00000000);
	tmpobjid = CreateDynamicObject(5409, 834.898010, -1726.822998, 17.027000, 0.000000, 0.000000, 270.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwin2", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1676, "wshxrefpump", "petrolpumptop_128", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 10763, "airport1_sfse", "ws_airportdoors1", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 4, 3979, "civic01_lan", "sl_concretewall1", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 7, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 10, 11545, "desn_truckstop", "ws_xenon_3", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 11, 16093, "a51_ext", "ws_trans_concr", 0x00000000);
	tmpobjid = CreateDynamicObject(19545, 842.692993, -1728.833007, 12.546998, 0.000000, 0.000000, 0.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "concretemanky", 0x00000000);
	tmpobjid = CreateDynamicObject(19545, 857.681030, -1728.836059, 12.546998, 0.000000, 0.000000, 0.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "concretemanky", 0x00000000);
	tmpobjid = CreateDynamicObject(8947, 835.247009, -1731.310058, 9.600000, 0.000000, 0.000000, 90.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "forumstand1_LAe", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 17545, "burnsground", "newall10_seamless", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 17545, "burnsground", "newall10_seamless", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 16093, "a51_ext", "ws_trans_concr", 0x00000000);
	tmpobjid = CreateDynamicObject(19371, 821.853027, -1726.589965, 11.791999, 0.000000, 0.000000, 90.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 10713, "gayclub_sfs", "ws_plasterwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19371, 851.526000, -1726.531982, 13.156999, 0.000000, 0.000000, 90.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 10713, "gayclub_sfs", "ws_plasterwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(3660, 852.677001, -1749.912963, 14.600000, 0.000000, 0.000000, 90.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 17545, "burnsground", "newall10_seamless", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "Bow_church_grass_alt", 0x00000000);
	tmpobjid = CreateDynamicObject(3660, 852.671020, -1736.495971, 14.600000, 0.000000, 0.000000, 90.000000);
	SetDynamicObjectMaterial(tmpobjid, 0, 17545, "burnsground", "newall10_seamless", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "Bow_church_grass_alt", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1215, 847.320983, -1738.542968, 13.168000, 0.000000, 0.000000, 0.000000);
	tmpobjid = CreateDynamicObject(1215, 823.127014, -1738.556030, 13.168000, 0.000000, 0.000000, 0.000000);
	tmpobjid = CreateDynamicObject(1209, 838.842712, -1736.521728, 12.683876, 0.000000, 0.000000, 0.000000);
	tmpobjid = CreateDynamicObject(2714, 831.877929, -1736.224853, 14.301507, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(1676, 836.45282, -1749.69055, 14.22560,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1676, 833.50232, -1749.69055, 14.22560,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1676, 843.25116, -1749.69055, 14.22560,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1676, 840.53998, -1749.69055, 14.22560,   0.00000, 0.00000, 0.00000);

    //=====================================[ ACTORS ]====================================||
    
    return 1;
}

hook OnPlayerConnect(playerid)
{
    //=====================================[ REMOVE WORLD OBJECTS ]====================================||
    RemoveBuildingForPlayer(playerid, 6098, 836.585, -1743.296, 19.609, 0.250);
	RemoveBuildingForPlayer(playerid, 6076, 836.585, -1743.296, 19.609, 0.250);
	RemoveBuildingForPlayer(playerid, 726, 865.101, -1710.554, 10.742, 0.250);

    //=====================================[ MAP ICONS ]====================================||
	return 1;
    
}