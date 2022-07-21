#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsSpectateTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:AdminSpectatePlayer(playerid)
{
	new spectated_id = Admin_GetPlayerSpectated(playerid);
	if (spectated_id != INVALID_PLAYER_ID && Player_GetAdminLevel(playerid) >= HELPER)
	{
		if (IsValidPlayer(spectated_id))
		{
			SetPlayerToTeamColor(playerid);
			SetPlayerInterior(playerid, GetPlayerInterior(spectated_id));
			SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(spectated_id));
			UpdateSpectatePlayer(playerid, spectated_id);
		}
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------
stock Admin_StartSpectate(playerid)
{
	gsSpectateTimer[playerid] = SetTimerEx("AdminSpectatePlayer", 1000, true, "i", playerid);
	return 1;
}

stock Admin_StopSpectate(playerid)
{
	if (gsSpectateTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsSpectateTimer[playerid]);
		gsSpectateTimer[playerid] = INVALID_VALUE;
	}
	return 1;
}

stock UpdateSpectatePlayer(playerid, id)
{
	new string[120], moneyString[MAX_MONEY_STRING], vehicleName[MAX_VEHICLE_NAME_STRING];
	FormatMoneyString(Player_GetMoney(id), moneyString);
	GetVehicleName(GetVehicleModel(GetPlayerVehicleID(id)), vehicleName);
	
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
	format(string, sizeof(string), "%s", moneyString);
	PlayerTextDrawSetString(playerid, GetSpectateTextdrawId(playerid, 17), string);
	format(string, sizeof(string), "%s", vehicleName);
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

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	gsSpectateTimer[playerid] = INVALID_VALUE;
	Admin_SetWatchStatus(playerid, false);
	Admin_SetPlayerSpectated(playerid, INVALID_PLAYER_ID);
	return 1;
}

hook OnPlayerDisconnect(playerid)
{
	if (gsSpectateTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsSpectateTimer[playerid]);
		gsSpectateTimer[playerid] = INVALID_VALUE;
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
