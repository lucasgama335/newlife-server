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
    CreateDynamicObject(4100, 1942.1629638672, -1772.4167480469, 14.342294692993, 0, 0, 49.624786376953);//grades posto sul
    CreateDynamicObject(4100, 1941.0621337891, -1772.3591308594, 14.342294692993, 0, 0, 49.624694824219);//grades posto sul
    CreateDynamicObject(1676, 1000.5368041992, -937.51239013672, 42.908992767334, 0, 0, 9.9249267578125);
    CreateDynamicObject(1676, 1007.5074462891, -936.49285888672, 42.908992767334, 0, 0, 7.939208984375);//2 objetos

    //=====================================[ ACTORS ]====================================||
    return 1;
}

hook OnPlayerConnect(playerid)
{
    //=====================================[ REMOVE WORLD OBJECTS ]====================================||

	//=====================================[ MAP ICONS ]====================================||
    SetPlayerMapIcon(playerid, m_MAP_ICON_GAS_STATION_1, 1000.5934, -919.9224, 42.3281, 17, 0xE6E6E6E6);
	SetPlayerMapIcon(playerid, m_MAP_ICON_GAS_STATION_2, 1928.5815, -1776.3611, 13.5469, 17, 0xE6E6E6E6);
	return 1;
}
