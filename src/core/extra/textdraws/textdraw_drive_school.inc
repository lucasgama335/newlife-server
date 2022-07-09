#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsDriveSchoolTextdraw[MAX_PLAYERS][5];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock DriveSchool_CreateUltraWide(playerid)
{
	gsDriveSchoolTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 513.000000, 195.000000, "I");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][0], 19.516662, 10.999988);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][0], 515.000000, 122.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][0], 185);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][0], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][0], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][0], false);

    gsDriveSchoolTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 564.000000, 227.000000, "AUTOESCOLA");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][1], 3);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][1], 0.208333, 1.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][1], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][1], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][1], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][1], false);

    gsDriveSchoolTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 605.000000, 247.000000, "TEMPO: 05:20");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][2], 3);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][2], 0.208333, 1.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][2], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][2], 3);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][2], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][2], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][2], false);

    gsDriveSchoolTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 605.000000, 260.000000, "PROGRESSO: 10/21");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][3], 3);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][3], 0.208333, 1.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][3], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][3], 3);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][3], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][3], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][3], false);

    gsDriveSchoolTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 554.000000, 225.000000, "ld_grav:timer");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][4], 4);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][4], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][4], 8.000000, 11.500000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][4], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][4], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][4], true);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][4], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][4], false);
	return 1;
}

static stock DriveSchool_CreateNormalScreen(playerid)
{
	gsDriveSchoolTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 513.000000, 195.000000, "I");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][0], 19.516662, 10.999988);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][0], 515.000000, 122.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][0], 185);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][0], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][0], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][0], false);

    gsDriveSchoolTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 564.000000, 227.000000, "AUTOESCOLA");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][1], 3);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][1], 0.208333, 1.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][1], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][1], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][1], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][1], false);

    gsDriveSchoolTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 605.000000, 247.000000, "TEMPO: 05:20");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][2], 3);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][2], 0.208333, 1.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][2], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][2], 3);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][2], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][2], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][2], false);

    gsDriveSchoolTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 605.000000, 260.000000, "PROGRESSO: 10/21");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][3], 3);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][3], 0.208333, 1.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][3], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][3], 3);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][3], false);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][3], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][3], false);

    gsDriveSchoolTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 554.000000, 225.000000, "ld_grav:timer");
    PlayerTextDrawFont(playerid, gsDriveSchoolTextdraw[playerid][4], 4);
    PlayerTextDrawLetterSize(playerid, gsDriveSchoolTextdraw[playerid][4], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsDriveSchoolTextdraw[playerid][4], 8.000000, 11.500000);
    PlayerTextDrawSetOutline(playerid, gsDriveSchoolTextdraw[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, gsDriveSchoolTextdraw[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, gsDriveSchoolTextdraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, gsDriveSchoolTextdraw[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, gsDriveSchoolTextdraw[playerid][4], 255);
    PlayerTextDrawBoxColor(playerid, gsDriveSchoolTextdraw[playerid][4], 50);
    PlayerTextDrawUseBox(playerid, gsDriveSchoolTextdraw[playerid][4], true);
    PlayerTextDrawSetProportional(playerid, gsDriveSchoolTextdraw[playerid][4], true);
    PlayerTextDrawSetSelectable(playerid, gsDriveSchoolTextdraw[playerid][4], false);
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock AdaptDriveSchoolHudToScreen(playerid)
{
	DestroyClientAlert(playerid);
	switch (Player_GetScreenSize(playerid))
	{
		case SCREEN_NORMAL:
		{
			DriveSchool_CreateNormalScreen(playerid);
		}
		case SCREEN_ULTRAWIDE:
		{
			DriveSchool_CreateUltraWide(playerid);
		}
		default:
		{
			DriveSchool_CreateNormalScreen(playerid);
		}
	}
	return 1;
}

stock ShowDriveSchoolHud(playerid)
{
    for (new i; i < 5; i++)
    {
	    PlayerTextDrawShow(playerid, gsDriveSchoolTextdraw[playerid][i]);
    }
	return 1;
}

stock HideDriveSchoolHud(playerid)
{
    for (new i; i < 5; i++)
    {
        if (gsDriveSchoolTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
	        PlayerTextDrawHide(playerid, gsDriveSchoolTextdraw[playerid][i]);
        }
    }
	return 1;
}

stock DestroyDriveSchoolHud(playerid)
{
    for (new i; i < 5; i++)
    {
        if (gsDriveSchoolTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
	        PlayerTextDrawDestroy(playerid, gsDriveSchoolTextdraw[playerid][i]);
        }
    }
	return 1;
}

stock UpdateDriveSchoolHud(playerid, time, actualCp, maxCp)
{
    new hudString[17];
    format(hudString, sizeof(hudString), "TEMPO: %02d:%02d", (time / 60), (time % 60));
    PlayerTextDrawSetString(playerid, gsDriveSchoolTextdraw[playerid][2], hudString);

    format(hudString, sizeof(hudString), "PROGRESSO: %d/%d", actualCp, maxCp);
    PlayerTextDrawSetString(playerid, gsDriveSchoolTextdraw[playerid][3], hudString);
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	DriveSchool_CreateNormalScreen(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	HideDriveSchoolHud(playerid);
	DestroyDriveSchoolHud(playerid);
	return 1;
}