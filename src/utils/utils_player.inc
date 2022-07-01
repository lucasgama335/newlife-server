#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock GetPlayerNameCustom(playerid)
{
    static player_name[MAX_PLAYER_NAME + 1];
    GetPlayerName(playerid, player_name, sizeof(player_name));
    return player_name;
}

stock GetPlayerIpCustom(playerid)
{
    static str[16];
    GetPlayerIp(playerid, str, sizeof(str));
    return str;
}

stock Float:GetPlayerHealthCustom(playerid)
{
	static Float:player_Health;
	GetPlayerHealth(playerid, player_Health);
	return player_Health;
}

stock Float:GetPlayerArmourCustom(playerid)
{
	static Float:player_Armour;
	GetPlayerArmour(playerid, player_Armour);
	return player_Armour;
}

stock bool:IsValidPlayer(playerid, bool:loggedStatus)
{
    if (IsPlayerConnected(playerid) && playerid != INVALID_PLAYER_ID && loggedStatus == true)
	{
		return true;
	}
    return false;
}

stock GetPlayerSpeed(playerid, bool:kmh2)
{
    new Float:Vx, Float:Vy, Float:Vz, Float:rtn;
    if (IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), Vx, Vy, Vz);
		rtn = floatsqroot(floatpower(floatabs(Vx),2)+floatpower(floatabs(Vy),2)+floatpower(floatabs(Vz),2));
	}
	else
	{
		GetPlayerVelocity(playerid, Vx, Vy, Vz);
		rtn = floatsqroot(floatpower(floatabs(Vx),2)+floatpower(floatabs(Vy),2)+floatpower(floatabs(Vz),2));
	}
    return kmh2?floatround(rtn * 100 * 1.61):floatround(rtn * 100);
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

