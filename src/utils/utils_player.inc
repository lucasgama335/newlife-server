#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Player_GetName(playerid)
{
    static player_name[MAX_PLAYER_NAME + 1];
    GetPlayerName(playerid, player_name, sizeof(player_name));
    return player_name;
}

stock Player_GetIP(playerid)
{
    static str[16];
    GetPlayerIp(playerid, str, sizeof(str));
    return str;
}

function:SetPlayerToTeamColor(playerid, admin, org)
{
    SetPlayerColor(playerid, COLOR_WHITE);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
