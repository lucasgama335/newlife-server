#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsAlertMessage[MAX_PLAYERS][2]; // 0 - Title | 1 - Message
static Timer:gsAlertTimer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
timer DismissClientAlert[5000](playerid)
{
    HideClientAlert(playerid);
	return 1;
}

stock ShowClientAlert(playerid)
{
	PlayerTextDrawShow(playerid, gsAlertMessage[playerid][0]);
	PlayerTextDrawShow(playerid, gsAlertMessage[playerid][1]);
	return 1;
}

stock HideClientAlert(playerid)
{
    PlayerTextDrawHide(playerid, gsAlertMessage[playerid][0]);
	PlayerTextDrawHide(playerid, gsAlertMessage[playerid][1]);
	return 1;
}

stock DestroyClientAlert(playerid)
{
    PlayerTextDrawDestroy(playerid, gsAlertMessage[playerid][0]);
	PlayerTextDrawDestroy(playerid, gsAlertMessage[playerid][1]);
	return 1;
}

stock SendClientAlert(playerid, const title[], const message[])
{
	new string_alert[120];
	format(string_alert, sizeof (string_alert), "%s", title);
	PlayerTextDrawSetString(playerid, gsAlertMessage[playerid][0], string_alert);	
	format(string_alert, sizeof (string_alert), "%s", message);
	PlayerTextDrawSetString(playerid, gsAlertMessage[playerid][1], string_alert);	

	ShowClientAlert(playerid);

    if (Timer_IsRunning(gsAlertTimer[playerid])) stop gsAlertTimer[playerid];
    gsAlertTimer[playerid] = defer DismissClientAlert(playerid);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
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

hook OnPlayerDisconnect(playerid, reason)
{
	HideClientAlert(playerid);
	DestroyClientAlert(playerid);
	return 1;
}