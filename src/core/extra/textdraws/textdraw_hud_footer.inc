#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsHudTextdraw[MAX_PLAYERS][17];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowPlayerHud(playerid)
{
    for (new i; i < 17; i++)
    {
	    PlayerTextDrawShow(playerid, gsHudTextdraw[playerid][i]);
    }
	return 1;
}

stock HidePlayerHud(playerid)
{
    for (new i; i < 17; i++)
    {
	    PlayerTextDrawHide(playerid, gsHudTextdraw[playerid][i]);
    }
	return 1;
}

stock DestroyPlayerHud(playerid)
{
    for (new i; i < 17; i++)
    {
	    PlayerTextDrawDestroy(playerid, gsHudTextdraw[playerid][i]);
    }
	return 1;
}

stock UpdatePlayerHud(playerid, Timestamp:time, level, hungry, drink, paydayTime)
{
    new timeString[38];
    strcat(timeString, Chrono_GetDayName(time));
    strcat(timeString, ", ");
    strcat(timeString, Chrono_GetDate(time));
    strcat(timeString, " - ");
    strcat(timeString, Chrono_GetHour(time));
    PlayerTextDrawSetString(playerid, gsHudTextdraw[playerid][2], timeString);

    PlayerTextDrawSetString(playerid, gsHudTextdraw[playerid][10], GetPlayerNameCustom(playerid));

    new levelString[12];
    format(levelString, sizeof(levelString), "LEVEL: %d", level);
    PlayerTextDrawSetString(playerid, gsHudTextdraw[playerid][11], levelString);

    new statusString[5];
    format(statusString, sizeof(statusString), "%d%%", hungry);
    PlayerTextDrawSetString(playerid, gsHudTextdraw[playerid][7], statusString);
    format(statusString, sizeof(statusString), "%d%%", drink);
    PlayerTextDrawSetString(playerid, gsHudTextdraw[playerid][9], statusString);
    
    new sPaydayString[10];
    format(sPaydayString, sizeof(sPaydayString), "%02d:%02d", (paydayTime / 60), (paydayTime % 60));
    PlayerTextDrawSetString(playerid, gsHudTextdraw[playerid][16], sPaydayString);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsHudTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 320.000000, 435.000000, "_");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][0], 0.600000, 1.250000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][0], 308.000000, 637.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][0], 2);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][0], 250);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][0], true);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][0], false);

    gsHudTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 81.000000, 435.000000, "_");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][1], 0.600000, 1.250000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][1], 308.000000, 159.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][1], 2);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][1], 454827263);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][1], true);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][1], false);

    gsHudTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 8.000000, 436.000000, "SEXTA FEIRA, 01/07/2022 - 12:57:32");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][2], 2);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][2], 0.174999, 0.999999);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][2], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][2], -1094795521);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][2], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][2], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][2], false);

    gsHudTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 144.000000, 420.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][3], 5);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][3], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][3], 41.000000, 56.500000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][3], 230);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][3], 255);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][3], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][3], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, gsHudTextdraw[playerid][3], 1614);
    PlayerTextDrawSetPreviewRot(playerid, gsHudTextdraw[playerid][3], 0.000000, 180.000000, -90.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsHudTextdraw[playerid][3], 1, 1);

    gsHudTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 558.000000, 435.000000, "_");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][4], 1);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][4], 0.600000, 1.250000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][4], 308.000000, 159.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][4], 2);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][4], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][4], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][4], 454827263);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][4], true);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][4], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][4], false);

    gsHudTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 457.000000, 420.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][5], 5);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][5], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][5], 41.000000, 56.500000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][5], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][5], 230);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][5], 255);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][5], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][5], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][5], false);
    PlayerTextDrawSetPreviewModel(playerid, gsHudTextdraw[playerid][5], 1614);
    PlayerTextDrawSetPreviewRot(playerid, gsHudTextdraw[playerid][5], 0.000000, 180.000000, -90.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsHudTextdraw[playerid][5], 1, 1);

    gsHudTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 486.000000, 429.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][6], 5);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][6], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][6], 18.000000, 22.500000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][6], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][6], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][6], 255);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][6], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][6], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, gsHudTextdraw[playerid][6], 19580);
    PlayerTextDrawSetPreviewRot(playerid, gsHudTextdraw[playerid][6], -90.000000, 0.000000, 0.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsHudTextdraw[playerid][6], 1, 1);

    gsHudTextdraw[playerid][7] = CreatePlayerTextDraw(playerid, 522.000000, 435.000000, "100%");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][7], 2);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][7], 0.191666, 1.050000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][7], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][7], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][7], 3);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][7], -1094795521);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][7], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][7], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][7], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][7], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][7], false);

    gsHudTextdraw[playerid][8] = CreatePlayerTextDraw(playerid, 531.000000, 432.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][8], 5);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][8], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][8], 22.000000, 16.500000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][8], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][8], 255);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][8], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][8], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, gsHudTextdraw[playerid][8], 19823);
    PlayerTextDrawSetPreviewRot(playerid, gsHudTextdraw[playerid][8], -10.000000, 0.000000, -20.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsHudTextdraw[playerid][8], 1, 1);

    gsHudTextdraw[playerid][9] = CreatePlayerTextDraw(playerid, 567.000000, 435.000000, "100%");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][9], 2);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][9], 0.191666, 1.050000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][9], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][9], 3);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][9], -1094795521);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][9], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][9], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][9], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][9], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][9], false);

    gsHudTextdraw[playerid][10] = CreatePlayerTextDraw(playerid, 171.000000, 435.000000, "PLAYER_NAME");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][10], 3);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][10], 0.283333, 1.150000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][10], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][10], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][10], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][10], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][10], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][10], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][10], false);

    gsHudTextdraw[playerid][11] = CreatePlayerTextDraw(playerid, 469.000000, 435.000000, "LEVEL: 100");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][11], 3);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][11], 0.283333, 1.150000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][11], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][11], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][11], 3);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][11], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][11], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][11], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][11], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][11], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][11], false);

    gsHudTextdraw[playerid][12] = CreatePlayerTextDraw(playerid, 306.000000, 435.000000, "NEWLIFE");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][12], 3);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][12], 0.341666, 1.200000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][12], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][12], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][12], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][12], -2686721);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][12], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][12], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][12], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][12], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][12], false);

    gsHudTextdraw[playerid][13] = CreatePlayerTextDraw(playerid, 229.000000, 433.000000, "I");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][13], 1);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][13], 15.900048, 0.099999);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][13], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][13], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][13], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][13], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][13], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][13], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][13], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][13], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][13], false);

    gsHudTextdraw[playerid][14] = CreatePlayerTextDraw(playerid, 229.000000, 447.000000, "I");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][14], 1);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][14], 15.900048, 0.099999);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][14], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][14], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][14], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][14], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][14], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][14], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][14], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][14], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][14], false);

    gsHudTextdraw[playerid][15] = CreatePlayerTextDraw(playerid, 580.000000, 435.000000, "HUD:radar_cash");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][15], 4);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][15], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][15], 10.000000, 10.500000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][15], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][15], 1);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][15], -1);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][15], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][15], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][15], true);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][15], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][15], false);

    gsHudTextdraw[playerid][16] = CreatePlayerTextDraw(playerid, 614.000000, 435.000000, "30:25");
    PlayerTextDrawFont(playerid, gsHudTextdraw[playerid][16], 2);
    PlayerTextDrawLetterSize(playerid, gsHudTextdraw[playerid][16], 0.191666, 1.050000);
    PlayerTextDrawTextSize(playerid, gsHudTextdraw[playerid][16], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsHudTextdraw[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, gsHudTextdraw[playerid][16], 0);
    PlayerTextDrawAlignment(playerid, gsHudTextdraw[playerid][16], 3);
    PlayerTextDrawColor(playerid, gsHudTextdraw[playerid][16], -1094795521);
    PlayerTextDrawBackgroundColor(playerid, gsHudTextdraw[playerid][16], 255);
    PlayerTextDrawBoxColor(playerid, gsHudTextdraw[playerid][16], 50);
    PlayerTextDrawUseBox(playerid, gsHudTextdraw[playerid][16], false);
    PlayerTextDrawSetProportional(playerid, gsHudTextdraw[playerid][16], true);
    PlayerTextDrawSetSelectable(playerid, gsHudTextdraw[playerid][16], false);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	HidePlayerHud(playerid);
	DestroyPlayerHud(playerid);
	return 1;
}