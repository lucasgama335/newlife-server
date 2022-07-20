#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsAdminFlyTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:AdminFly(playerid)
{
	new k, ud, lr;
	GetPlayerKeys(playerid, k, ud, lr);
	new Float:v_x,Float:v_y,Float:v_z, Float:xf2, Float:yf2, Float:zf2;
	if (ud < 0)	// forward
	{
		GetPlayerCameraFrontVector(playerid, xf2, yf2, zf2);
		v_x = xf2+0.1;
		v_y = yf2+0.1;
	}
	if (k & 128)
	{	// down
		v_z = -0.2;
	}
	else if (k & KEY_FIRE)	// up
	{
		v_z = 0.2;
	}
	if (k & KEY_WALK)	// slow
	{
		v_x /= 5.0;
		v_y /= 5.0;
		v_z /= 5.0;
	}
	if (k & KEY_SPRINT)	// fast
	{
		v_x *= 4.0;
		v_y *= 4.0;
		v_z *= 4.0;
	}
	if (v_z == 0.0)
	{
		v_z = 0.025;
	}
	SetPlayerVelocity(playerid, v_x, v_y, v_z);
	if (v_x == 0 && v_y == 0)
	{
		if (GetPlayerAnimationIndex(playerid) == 959)
		{
			ApplyAnimation(playerid, "PARACHUTE", "PARA_steerR", 6.1, true, true, true, true, 0, 1);
		}
	}
	else
	{
		GetPlayerCameraFrontVector(playerid, v_x, v_y, v_z);
		GetPlayerCameraPos(playerid, xf2, yf2, zf2);
		SetPlayerLookAt(playerid, ((v_x * 500.0) + xf2), ((v_y * 500.0) + yf2));
		if (GetPlayerAnimationIndex(playerid) != 959)
		{
			ApplyAnimation(playerid, "PARACHUTE", "FALL_SkyDive_Accel", 6.1, true, true, true, true, 0, 1);
		}
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------
stock bool:StartFly(playerid)
{
	new Float:xf, Float:yf, Float:zf;
	GetPlayerPos(playerid, xf, yf, zf);
	SetPlayerPos(playerid, xf, yf, (zf + 5.0));
	ApplyAnimation(playerid, "PARACHUTE", "PARA_steerR", 6.1, true, true, true, true, 0, 1);
	GameTextForPlayer(playerid, "~y~MODO VOAR~n~~r~~k~~PED_FIREWEAPON~ ~w~- AUMENTA ALTURA~n~~r~RMB ~w~- REDUZ ALTURA~n~\
	~r~~k~~PED_SPRINT~ ~w~- AUMENTAR SPEED~n~\
	~r~~k~~SNEAK_ABOUT~ ~w~- REDUZ SPEED", 10000, 3);
	AdminFly(playerid);
	if (gsAdminFlyTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsAdminFlyTimer[playerid]);
		gsAdminFlyTimer[playerid] = INVALID_VALUE;
	}
	gsAdminFlyTimer[playerid] = SetTimerEx("AdminFly", 100, true, "i", playerid);
	return true;
}

stock bool:StopFly(playerid)
{
	new Float:xf3, Float:yf3, Float:zf3;
	GetPlayerPos(playerid, xf3, yf3, zf3);
	SetPlayerPos(playerid, xf3, yf3, zf3);
	if (gsAdminFlyTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsAdminFlyTimer[playerid]);
		gsAdminFlyTimer[playerid] = INVALID_VALUE;
	}
	return true;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	gsAdminFlyTimer[playerid] = INVALID_VALUE;
	Admin_SetFlying(playerid, false);
    return 1;
}

hook OnPlayerDisconnect(playerid)
{
	if (gsAdminFlyTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsAdminFlyTimer[playerid]);
		gsAdminFlyTimer[playerid] = INVALID_VALUE;
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
