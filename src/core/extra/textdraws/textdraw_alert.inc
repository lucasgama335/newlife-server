#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsAlertMessage[MAX_PLAYERS][2]; // 0 - Title | 1 - Message
static Timer:gsAlertTimer[MAX_PLAYERS];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock Alert_CreateUltrawideScreen(playerid)
{
	gsAlertMessage[playerid][0] = CreatePlayerTextDraw(playerid, 52.000000, 257.000000, "CONFIGURACOES");
	PlayerTextDrawFont(playerid, gsAlertMessage[playerid][0], 2);
	PlayerTextDrawLetterSize(playerid, gsAlertMessage[playerid][0], 0.145833, 0.899999);
	PlayerTextDrawTextSize(playerid, gsAlertMessage[playerid][0], 400.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, gsAlertMessage[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, gsAlertMessage[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, gsAlertMessage[playerid][0], 2);
	PlayerTextDrawColor(playerid, gsAlertMessage[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, gsAlertMessage[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, gsAlertMessage[playerid][0], 120);
	PlayerTextDrawUseBox(playerid, gsAlertMessage[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, gsAlertMessage[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, gsAlertMessage[playerid][0], 0);

	gsAlertMessage[playerid][1] = CreatePlayerTextDraw(playerid, 52.000000, 274.000000, "Velocimetro alternado para o tipo padrao testando texto bla bal bla");
	PlayerTextDrawFont(playerid, gsAlertMessage[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, gsAlertMessage[playerid][1], 0.154164, 0.899998);
	PlayerTextDrawTextSize(playerid, gsAlertMessage[playerid][1], 400.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, gsAlertMessage[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, gsAlertMessage[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, gsAlertMessage[playerid][1], 2);
	PlayerTextDrawColor(playerid, gsAlertMessage[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, gsAlertMessage[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, gsAlertMessage[playerid][1], 120);
	PlayerTextDrawUseBox(playerid, gsAlertMessage[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, gsAlertMessage[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, gsAlertMessage[playerid][1], 0);
	return 1;
}

static stock Alert_CreateNormalScreen(playerid)
{
	gsAlertMessage[playerid][0] = CreatePlayerTextDraw(playerid, 74.000000, 226.000000, "Title Alert");
	PlayerTextDrawFont(playerid, gsAlertMessage[playerid][0], 2);
	PlayerTextDrawLetterSize(playerid, gsAlertMessage[playerid][0], 0.208333, 0.850000);
	PlayerTextDrawTextSize(playerid, gsAlertMessage[playerid][0], 400.500000, 113.000000);
	PlayerTextDrawSetOutline(playerid, gsAlertMessage[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, gsAlertMessage[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, gsAlertMessage[playerid][0], 2);
	PlayerTextDrawColor(playerid, gsAlertMessage[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, gsAlertMessage[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, gsAlertMessage[playerid][0], 120);
	PlayerTextDrawUseBox(playerid, gsAlertMessage[playerid][0], true);
	PlayerTextDrawSetProportional(playerid, gsAlertMessage[playerid][0], true);
	PlayerTextDrawSetSelectable(playerid, gsAlertMessage[playerid][0], false);

	gsAlertMessage[playerid][1] = CreatePlayerTextDraw(playerid, 74.000000, 238.000000, "Message Alert");
	PlayerTextDrawFont(playerid, gsAlertMessage[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, gsAlertMessage[playerid][1], 0.174999, 1.050000);
	PlayerTextDrawTextSize(playerid, gsAlertMessage[playerid][1], 402.000000, 113.000000);
	PlayerTextDrawSetOutline(playerid, gsAlertMessage[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, gsAlertMessage[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, gsAlertMessage[playerid][1], 2);
	PlayerTextDrawColor(playerid, gsAlertMessage[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, gsAlertMessage[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, gsAlertMessage[playerid][1], 120);
	PlayerTextDrawUseBox(playerid, gsAlertMessage[playerid][1], true);
	PlayerTextDrawSetProportional(playerid, gsAlertMessage[playerid][1], true);
	PlayerTextDrawSetSelectable(playerid, gsAlertMessage[playerid][1], false);
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
timer DismissClientAlert[5000](playerid)
{
    HideClientAlert(playerid);
	return 1;
}

stock AdaptAlertToScreen(playerid)
{
	DestroyClientAlert(playerid);
	switch (Player_GetScreenSize(playerid))
	{
		case SCREEN_NORMAL:
		{
			Alert_CreateNormalScreen(playerid);
		}
		case SCREEN_ULTRAWIDE:
		{
			Alert_CreateUltrawideScreen(playerid);
		}
		default:
		{
			Alert_CreateNormalScreen(playerid);
		}
	}
	return 1;
}

stock ShowClientAlert(playerid)
{
	if (gsAlertMessage[playerid][0] != INVALID_PLAYER_TEXT_DRAW) PlayerTextDrawShow(playerid, gsAlertMessage[playerid][0]);
	if (gsAlertMessage[playerid][1] != INVALID_PLAYER_TEXT_DRAW) PlayerTextDrawShow(playerid, gsAlertMessage[playerid][1]);
	return 1;
}

stock HideClientAlert(playerid)
{
	if (gsAlertMessage[playerid][0] != INVALID_PLAYER_TEXT_DRAW)
	{
    	PlayerTextDrawHide(playerid, gsAlertMessage[playerid][0]);

	}
	if (gsAlertMessage[playerid][1] != INVALID_PLAYER_TEXT_DRAW)
	{
		PlayerTextDrawHide(playerid, gsAlertMessage[playerid][1]);
	}
	return 1;
}

stock DestroyClientAlert(playerid)
{
	if (gsAlertMessage[playerid][0] != INVALID_PLAYER_TEXT_DRAW)
	{
    	PlayerTextDrawDestroy(playerid, gsAlertMessage[playerid][0]);
	}

	if (gsAlertMessage[playerid][1] != INVALID_PLAYER_TEXT_DRAW)
	{
		PlayerTextDrawDestroy(playerid, gsAlertMessage[playerid][1]);
	}
	return 1;
}

stock SendClientAlert(playerid, const title[], const message[], bool:adaptToScreen = false)
{
	new string_alert[120];
	if (adaptToScreen)
	{
		AdaptAlertToScreen(playerid);
	}
	if (gsAlertMessage[playerid][0] != INVALID_PLAYER_TEXT_DRAW)
	{
		format(string_alert, sizeof (string_alert), "%s", title);
		PlayerTextDrawSetString(playerid, gsAlertMessage[playerid][0], string_alert);	
	}
	if (gsAlertMessage[playerid][1] != INVALID_PLAYER_TEXT_DRAW)
	{
		format(string_alert, sizeof (string_alert), "%s", message);
		PlayerTextDrawSetString(playerid, gsAlertMessage[playerid][1], string_alert);	
	}
	ShowClientAlert(playerid);

    if (Timer_IsRunning(gsAlertTimer[playerid])) 
	{
		stop gsAlertTimer[playerid];
	}
    gsAlertTimer[playerid] = defer DismissClientAlert(playerid);
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	Alert_CreateNormalScreen(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	#pragma unused reason // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	HideClientAlert(playerid);
	DestroyClientAlert(playerid);
	return 1;
}