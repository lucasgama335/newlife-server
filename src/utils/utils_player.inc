#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsPlayerMusic[MAX_PLAYERS];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
timer StopPlayerMusic[5000](playerid)
{
	PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
	return 1;
}

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

stock bool:IsValidPlayer(playerid)
{
    if (IsPlayerConnected(playerid) && playerid != INVALID_PLAYER_ID && Player_GetLoggedStatus(playerid))
	{
		return true;
	}
    return false;
}

stock GetPlayerIdByDb(dbId)
{
	foreach (new i : Player)
	{
		if (Player_GetId(i) == dbId)
		{
			return i;
		}
	}
	return INVALID_PLAYER_ID;
}

stock GetPlayerSpeed(playerid, bool:kmh2)
{
    new Float:Vx, Float:Vy, Float:Vz, Float:rtn;
    if (IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), Vx, Vy, Vz);
		rtn = floatsqroot(floatpower(floatabs(Vx), 2) + floatpower(floatabs(Vy), 2) + floatpower(floatabs(Vz), 2));
	}
	else
	{
		GetPlayerVelocity(playerid, Vx, Vy, Vz);
		rtn = floatsqroot(floatpower(floatabs(Vx), 2) + floatpower(floatabs(Vy), 2) + floatpower(floatabs(Vz), 2));
	}
    return kmh2 ? floatround(rtn * 100 * 1.61) : floatround(rtn * 100);
}

stock PlayerPlayMusic(playerid, musicId)
{
	if (IsPlayerConnected(playerid))
	{
		if (Timer_IsRunning(gsPlayerMusic[playerid]))
		{
			stop gsPlayerMusic[playerid];
		}
		gsPlayerMusic[playerid] = defer StopPlayerMusic(playerid);
		PlayerPlaySound(playerid, musicId, 0.0, 0.0, 0.0);
	}
}

stock SetPlayerLookAt(playerid, Float:xl, Float:yl)
{
	new Float:Px, Float:Py, Float: Pa;
	GetPlayerPos(playerid, Px, Py, Pa);
	Pa = floatabs(atan((yl-Py) / (xl-Px)));
	if (xl <= Px && yl >= Py) 		Pa = floatsub(180.0, Pa);
	else if (xl < Px && yl < Py) 	Pa = floatadd(Pa, 180.0);
	else if (xl >= Px && yl <= Py)	Pa = floatsub(360.0, Pa);
	Pa = floatsub(Pa, 90.0);
	if (Pa >= 360.0)
	{
		Pa = floatsub(Pa, 360.0);
	}
	SetPlayerFacingAngle(playerid, Pa);
	return 1;
}

stock SetPlayerToTeamColor(playerid)
{
    SetPlayerColor(playerid, COLOR_WHITE);
	if (Admin_GetWorkStatus(playerid) && !Admin_GetHideStatus(playerid))
	{
		SetPlayerColor(playerid, COLOR_ADMIN);
	}
	return 1;
}

stock PlayAudioStreamForPlayerEx(playerid, const url[])
{
	if (Player_GetMusicStreamStatus(playerid))
	{
		PlayAudioStreamForPlayer(playerid, url);
	}
	return 1;
}

stock SendDuvidaMessage(color, const string[])
{
	foreach(new i: Player)
	{
		if (Player_GetNoobChatStatus(i))
	    {
			SendClientMessage(i, color, string);
		}
	}
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

