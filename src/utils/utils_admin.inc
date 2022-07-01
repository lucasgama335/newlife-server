#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_LOG_STRING  118

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsAdminRole[MAX_ADMIN_ROLES][] = { "Nenhum", "Estagiário", "Ajudante", "Moderador", "Supervisor", "Master", "Master +", "Master ++", "Gerente", "Sub-Dono", "Dono" };

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock GetAdminRoleName(role)
{
    new string[11];
    format(string, sizeof(string), "%s", gsAdminRole[role]);
    return string;
}

stock TeleportPlayer(playerid, Float:x, Float:y, Float:z, Float:a, interior, world)
{
	SetPlayerInterior(playerid, interior);
	SetPlayerVirtualWorld(playerid, world);
	if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
	    new vid = GetPlayerVehicleID(playerid);
	    LinkVehicleToInterior(vid, GetPlayerInterior(playerid));
		SetVehicleVirtualWorld(vid, GetPlayerVirtualWorld(playerid));
		SetVehiclePos(vid, x, y, z);
		SetVehicleZAngle(vid, a);
	}
	else
	{
	    SetPlayerPos(playerid, x, y, z);
		SetPlayerFacingAngle(playerid, a);
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
