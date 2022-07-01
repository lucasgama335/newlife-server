#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook CheckPlayerEntrances(playerid)
{
	new Float:cx, Float:cy, Float:cz;
	GetPlayerPos(playerid, cx, cy, cz);
	// Entrance
	if (IsPlayerInRangeOfPoint(playerid, 3.0, 1481.0397, -1772.3135, 18.7958))
	{
	    PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/53d0kb63zneqa1i/playstory%20PREFEITURA.mp3?dl=1");
        GameTextForPlayer(playerid, "~w~bem vindo a prefeitura ls !", 5000, 1);
        SetPlayerInterior(playerid, 3);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid,390.7694,173.8226,1008.3828);
		Player_SetInteriorLocale(playerid, CITY_HALL_INTERIOR);
   	}
	// Exit
	if (IsPlayerInRangeOfPoint(playerid, 3.0, 390.7694, 173.8226, 1008.3828))
	{
	    StopAudioStreamForPlayer(playerid);
	    SetPlayerInterior(playerid, 0);
	    SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid,1481.0397,-1772.3135,18.7958);
        Player_SetInteriorLocale(playerid, NO_INTERIOR);
	}
	return 1;
}
