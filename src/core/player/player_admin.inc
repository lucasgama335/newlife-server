#include <admin_data>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define		SERVER_ADMIN_PASS   "serverteste"	

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:spectateTimer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------
stock Admin_SendParMessage(playerid, id, COLOR, const string[])
{
	SendClientMessage(id, COLOR, string);
	foreach(new i: Player)
	{
		if (PlayerData_GetAdmin(playerid) >= SUB_OWNER && Admin_GetViewAllPars(i) && playerid != i)
		{
			SendClientMessage(i, COLOR, string);
		}
	}
	return 1;
}

stock GetOnlineAdmin(bool:work)
{
	new total = 0;
	foreach(new i : Player)
	{
		if (work)
		{
			if (PlayerData_GetAdmin(i) >= HELPER && Admin_IsWorking(playerid) && !Admin_GetHideStatus(playerid))
			{
				total ++;
			}
		}
		else
		{
			if (PlayerData_GetAdmin(i) >= HELPER && !Admin_GetHideStatus(playerid))
			{
				total ++;
			}
		}
	}
	return total;
}

stock Admin_GetSpectateTimerID(playerid)
{
	return spectateTimer[playerid];
}

timer AdminSpectatePlayer[1000](playerid)
{
	new spectated_id = Admin_GetPlayerSpectated(playerid);
	if (spectated_id != INVALID_PLAYER_ID && PlayerData_GetAdmin(playerid) >= HELPER)
	{
		if (IsValidPlayer(spectated_id, PlayerData_GetIsLogged(spectated_id)))
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
	spectateTimer[playerid] = repeat AdminSpectatePlayer(playerid);
	return 1;
}

stock Admin_StopSpectate(playerid)
{
	if (Timer_IsRunning(spectateTimer[playerid])) stop spectateTimer[playerid];
	return 1;
}


stock UpdateSpectatePlayer(playerid, id)
{
	new string[120];
	PlayerTextDrawHide(playerid, SpectateTextDraw_GetByIndex(playerid, 1));
	PlayerTextDrawSetPreviewModel(playerid, SpectateTextDraw_GetByIndex(playerid, 1), GetPlayerSkin(id));
	PlayerTextDrawShow(playerid, SpectateTextDraw_GetByIndex(playerid, 1));
	format(string, sizeof(string), "~r~VIDA: ~w~%.0f", Player_GetHealth(id));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 2), string);
	format(string, sizeof(string), "~b~COLETE: ~w~%.0f", Player_GetArmour(id));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 3), string);
	format(string, sizeof(string), "%s", Player_GetName(id));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 5), string);
	format(string, sizeof(string), "%d", id);
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 7), string);
	format(string, sizeof(string), "%d", PlayerData_GetID(id));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 9), string);
	format(string, sizeof(string), "%s", Server_GetWeaponName(GetPlayerWeapon(id)));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 11), string);
	format(string, sizeof(string), "%i", Server_GetWeaponAmmo(id, GetPlayerWeapon(id)));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 13), string);
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 15), (PlayerData_GetIsUsingAndroid(id) ? "Android" : "PC"));
	format(string, sizeof(string), "%s", Server_FormatToMoney(PlayerData_GetMoney(id)));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 17), string);
	format(string, sizeof(string), "%s", Vehicle_GetName(GetVehicleModel(GetPlayerVehicleID(id))));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 19), string);
	format(string, sizeof(string), "%d", GetPlayerSpeed(id, true));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 21), string);
	format(string, sizeof(string), "%d", PlayerData_GetLevel(id));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 24), string);
	format(string, sizeof(string), "%d", PlayerData_GetCoins(id));
	PlayerTextDrawSetString(playerid, SpectateTextDraw_GetByIndex(playerid, 26), string);
	return 1;
}

stock ShowSpectatePlayer(playerid, id)
{
	UpdateSpectatePlayer(playerid, id);
	ShowSpectateScreen(playerid);
	// SelectTextDraw(playerid, COLOR_ORANGE);
	return 1;
}

stock HideSpectatePlayer(playerid)
{
	HideSpectateScreen(playerid);
	CancelSelectTextDraw(playerid);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	Admin_SetWorkMode(playerid, false);
	Admin_SetHideStatus(playerid, false);
	Admin_SetWatchStatus(playerid, false);
	Admin_SetPlayerSpectated(playerid, INVALID_PLAYER_ID);
	Admin_SetViewAllPars(playerid, false);
	return 1;
}
