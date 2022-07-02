#include <admin_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define		SERVER_ADMIN_PASS   "123"	

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsSpectateTimer[MAX_PLAYERS];

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

stock Admin_SendPrivateMessage(playerid, id, COLOR, const string[])
{
	SendClientMessage(id, COLOR, string);
	foreach(new i: Player)
	{
		if (Player_GetAdminLevel(playerid) >= SUB_OWNER && Admin_GetViewAllPm(i) && playerid != i)
		{
			SendClientMessage(i, COLOR, string);
		}
	}
	return 1;
}

stock SendAdminMessage(COLOR, const string[], e_ADMIN_LEVELS:level)
{
	foreach(new i: Player)
	{
		if (Player_GetAdminLevel(i) >= level)
		{
			SendClientMessage(i, COLOR, string);
		}
	}
	return 1;
}

stock GetOnlineAdmins(bool:work)
{
	new total = 0;
	foreach(new i : Player)
	{
		if (work)
		{
			if (Player_GetAdminLevel(i) >= HELPER && Admin_GetWorkStatus(playerid) && !Admin_GetHideStatus(playerid))
			{
				total ++;
			}
		}
		else
		{
			if (Player_GetAdminLevel(i) >= HELPER && !Admin_GetHideStatus(playerid))
			{
				total ++;
			}
		}
	}
	return total;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	Admin_SetWorkStatus(playerid, false);
	Admin_SetAfkStatus(playerid, false);
	Admin_SetHideStatus(playerid, false);
	Admin_SetWatchStatus(playerid, false);
	Admin_SetPlayerSpectated(playerid, INVALID_PLAYER_ID);
	Admin_SetViewAllPm(playerid, false);
	return 1;
}
