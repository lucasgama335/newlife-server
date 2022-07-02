#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define		SERVER_ADMIN_PASS   "123"	

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsSpectateTimer[MAX_PLAYERS];
static Timer:gsAdminFlyTimer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------
timer AdminSpectatePlayer[1000](playerid)
{
	new spectated_id = Admin_GetPlayerSpectated(playerid);
	if (spectated_id != INVALID_PLAYER_ID && Player_GetAdminLevel(playerid) >= HELPER)
	{
		if (IsValidPlayer(spectated_id, Player_GetLoggedStatus(spectated_id)))
		{
			SetPlayerToTeamColor(playerid);
			SetPlayerInterior(playerid, GetPlayerInterior(spectated_id));
			SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(spectated_id));
			UpdateSpectatePlayer(playerid, spectated_id);
		}
	}
	return 1;
}

stock Admin_StartSpectate(playerid)
{
	gsSpectateTimer[playerid] = repeat AdminSpectatePlayer(playerid);
	return 1;
}

stock Admin_StopSpectate(playerid)
{
	if (Timer_IsRunning(gsSpectateTimer[playerid])) stop gsSpectateTimer[playerid];
	return 1;
}

stock Admin_GetSpectateTimerId(playerid)
{
	return gsSpectateTimer[playerid];
}

stock UpdateSpectatePlayer(playerid, id)
{
	new string[120];
	PlayerTextDrawHide(playerid, GetSpectateTextdrawId(playerid, 1));
	PlayerTextDrawSetPreviewModel(playerid, GetSpectateTextdrawId(playerid, 1), GetPlayerSkin(id));
	PlayerTextDrawShow(playerid, GetSpectateTextdrawId(playerid, 1));
	format(string, sizeof(string), "~r~VIDA: ~w~%.0f", GetPlayerHealthCustom(id));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 2), string);
	format(string, sizeof(string), "~b~COLETE: ~w~%.0f", GetPlayerArmourCustom(id));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 3), string);
	format(string, sizeof(string), "%s", GetPlayerNameCustom(id));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 5), string);
	format(string, sizeof(string), "%d", id);
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 7), string);
	format(string, sizeof(string), "%d", Player_GetId(id));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 9), string);
	format(string, sizeof(string), "%s", GetPlayerWeaponName(GetPlayerWeapon(id)));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 11), string);
	format(string, sizeof(string), "%i", GetPlayerWeaponAmmo(id, GetPlayerWeapon(id)));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 13), string);
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 15), (Player_GetUsingAndroidStatus(id) ? "Android" : "PC"));
	format(string, sizeof(string), "%s", FormatMoneyString(Player_GetMoney(id)));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 17), string);
	format(string, sizeof(string), "%s", GetVehicleName(GetVehicleModel(GetPlayerVehicleID(id))));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 19), string);
	format(string, sizeof(string), "%d", GetPlayerSpeed(id, true));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 21), string);
	format(string, sizeof(string), "%d", Player_GetLevel(id));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 24), string);
	format(string, sizeof(string), "%d", Player_GetCoins(id));
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 26), string);
	return 1;
}

stock ShowSpectatePlayer(playerid, id)
{
	UpdateSpectatePlayer(playerid, id);
	ShowSpectateScreen(playerid);
	return 1;
}

stock HideSpectatePlayer(playerid)
{
	HideSpectateScreen(playerid);
	CancelSelectTextDraw(playerid);
	return 1;
}

timer AdminFly[100](playerid)
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
	if (Timer_IsRunning(gsAdminFlyTimer[playerid]))
	{
		stop gsAdminFlyTimer[playerid];
	}
	gsAdminFlyTimer[playerid] = repeat AdminFly(playerid);
	return true;
}

stock bool:StopFly(playerid)
{
	new Float:xf3, Float:yf3, Float:zf3;
	GetPlayerPos(playerid, xf3, yf3, zf3);
	SetPlayerPos(playerid, xf3, yf3, zf3);
	if (Timer_IsRunning(gsAdminFlyTimer[playerid]))
	{
		stop gsAdminFlyTimer[playerid];
	}
	return true;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	Admin_SetFlying(playerid, false);
	Admin_SetBigEars(playerid, false);
	Admin_SetWorkStatus(playerid, false);
	Admin_SetAfkStatus(playerid, false);
	Admin_SetHideStatus(playerid, false);
	Admin_SetWatchStatus(playerid, false);
	Admin_SetPlayerSpectated(playerid, INVALID_PLAYER_ID);
	Admin_SetViewAllPm(playerid, false);
	return 1;
}
