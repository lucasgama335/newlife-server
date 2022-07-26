#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:modernSpeedometer[MAX_PLAYERS][20];
static PlayerText:compactSpeedometer[MAX_PLAYERS][9];
static PlayerText:gsSpeedometerCenter[MAX_PLAYERS][15];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock Modern_CreateUltrawideScreen(playerid)
{
	modernSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 439.000000, 391.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][0], 23.995798, 2.099989);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][0], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][0], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][0], 0);

	modernSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 439.000000, 379.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][1], 23.995798, 2.099989);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][1], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][1], 0);

	modernSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 439.000000, 367.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][2], 23.955499, 2.099999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][2], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][2], 0);

	modernSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 439.000000, 403.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][3], 23.995798, 2.099989);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][3], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][3], 0);

	modernSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 462.000000, 373.000000, "Veiculo");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][4], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][4], 0.212221, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][4], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][4], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][4], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][4], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][4], 0);

	modernSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 462.000000, 385.000000, "COMBUSTIVEL");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][5], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][5], 0.212221, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][5], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][5], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][5], 0);

	modernSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 462.000000, 397.000000, "LATARIA");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][6], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][6], 0.212221, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][6], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][6], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][6], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][6], 0);

	modernSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 462.000000, 409.000000, "BLINDAGEM");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][7], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][7], 0.212222, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][7], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][7], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][7], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][7], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][7], 0);

	modernSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 569.000000, 373.000000, "FAGGIO");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][8], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][8], 0.212499, 0.849998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][8], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][8], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][8], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][8], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][8], 0);

	modernSpeedometer[playerid][9] = CreatePlayerTextDraw(playerid, 569.000000, 385.000000, "100L");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][9], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][9], 0.212221, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][9], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][9], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][9], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][9], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][9], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][9], 0);

	modernSpeedometer[playerid][10] = CreatePlayerTextDraw(playerid, 569.000000, 397.000000, "100%");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][10], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][10], 0.212221, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][10], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][10], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][10], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][10], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][10], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][10], 0);

	modernSpeedometer[playerid][11] = CreatePlayerTextDraw(playerid, 569.000000, 409.000000, "100%");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][11], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][11], 0.212222, 0.849999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][11], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][11], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][11], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][11], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][11], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][11], 0);

	modernSpeedometer[playerid][12] = CreatePlayerTextDraw(playerid, 515.000000, 344.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][12], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][12], 0.216665, 2.550000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][12], 297.000000, 39.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][12], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][12], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][12], 102);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][12], 0);

	modernSpeedometer[playerid][13] = CreatePlayerTextDraw(playerid, 479.000000, 356.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][13], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][13], 0.216665, 1.200001);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][13], 297.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][13], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][13], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][13], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][13], 102);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][13], 0);

	modernSpeedometer[playerid][14] = CreatePlayerTextDraw(playerid, 551.000000, 356.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][14], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][14], 0.183332, 1.200000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][14], 297.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][14], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][14], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][14], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][14], 102);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][14], 0);

	modernSpeedometer[playerid][15] = CreatePlayerTextDraw(playerid, 487.000000, 354.000000, "~g~A ~w~F");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][15], 0.283333, 1.400000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][15], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][15], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][15], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][15], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][15], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][15], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][15], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][15], 0);

	modernSpeedometer[playerid][16] = CreatePlayerTextDraw(playerid, 542.000000, 355.000000, "KM/H");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][16], 0.208333, 1.250000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][16], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][16], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][16], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][16], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][16], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][16], 0);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][16], 0);

	modernSpeedometer[playerid][17] = CreatePlayerTextDraw(playerid, 501.000000, 347.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][17], 0.374998, 1.899998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][17], 240.000000, -16.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][17], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][17], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][17], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][17], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][17], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][17], 0);

	modernSpeedometer[playerid][18] = CreatePlayerTextDraw(playerid, 515.000000, 347.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][18], 0.383332, 1.899989);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][18], 240.000000, -16.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][18], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][18], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][18], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][18], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][18], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][18], 0);

	modernSpeedometer[playerid][19] = CreatePlayerTextDraw(playerid, 529.000000, 347.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][19], 0.383332, 1.899989);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][19], 240.000000, -16.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][19], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][19], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][19], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][19], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][19], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][19], 0);
	return 1;
}

static stock Modern_CreateNormalScreen(playerid)
{
	modernSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 363.000000, 395.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][0], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][0], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][0], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][0], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][0], false);

	modernSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 363.000000, 381.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][1], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][1], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][1], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][1], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][1], false);

	modernSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 363.000000, 367.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][2], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][2], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][2], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][2], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][2], false);

	modernSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 363.000000, 409.000000, "I");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][3], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][3], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][3], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][3], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][3], false);

	modernSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 450.000000, 373.000000, "VEICULO");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][4], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][4], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][4], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][4], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][4], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][4], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][4], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][4], false);

	modernSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 450.000000, 387.000000, "COMBUSTIVEL");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][5], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][5], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][5], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][5], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][5], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][5], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][5], false);

	modernSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 450.000000, 401.000000, "LATARIA");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][6], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][6], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][6], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][6], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][6], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][6], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][6], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][6], false);

	modernSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 450.000000, 415.000000, "BLINDAGEM");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][7], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][7], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][7], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][7], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][7], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][7], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][7], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][7], false);

	modernSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 584.000000, 373.000000, "FAGGIO");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][8], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][8], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][8], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][8], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][8], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][8], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][8], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][8], false);

	modernSpeedometer[playerid][9] = CreatePlayerTextDraw(playerid, 584.000000, 387.000000, "100L");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][9], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][9], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][9], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][9], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][9], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][9], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][9], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][9], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][9], false);

	modernSpeedometer[playerid][10] = CreatePlayerTextDraw(playerid, 584.000000, 401.000000, "100%");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][10], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][10], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][10], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][10], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][10], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][10], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][10], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][10], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][10], false);

	modernSpeedometer[playerid][11] = CreatePlayerTextDraw(playerid, 584.000000, 415.000000, "100%");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][11], 3);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][11], 0.266666, 0.999999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][11], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][11], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][11], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][11], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][11], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][11], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][11], false);

	modernSpeedometer[playerid][12] = CreatePlayerTextDraw(playerid, 515.000000, 344.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][12], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][12], 0.216666, 2.750000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][12], 297.000000, 49.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][12], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][12], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][12], 102);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][12], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][12], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][12], false);

	modernSpeedometer[playerid][13] = CreatePlayerTextDraw(playerid, 471.000000, 353.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][13], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][13], 0.216666, 1.700001);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][13], 297.000000, 30.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][13], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][13], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][13], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][13], 102);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][13], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][13], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][13], false);

	modernSpeedometer[playerid][14] = CreatePlayerTextDraw(playerid, 560.000000, 353.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][14], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][14], 0.216666, 1.700001);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][14], 297.000000, 30.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][14], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][14], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][14], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][14], 102);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][14], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][14], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][14], false);

	modernSpeedometer[playerid][15] = CreatePlayerTextDraw(playerid, 483.000000, 353.000000, "~g~A ~w~F");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][15], 0.433333, 1.650000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][15], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][15], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][15], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][15], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][15], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][15], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][15], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][15], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][15], false);

	modernSpeedometer[playerid][16] = CreatePlayerTextDraw(playerid, 547.000000, 353.000000, "KM/H");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][16], 0.300000, 1.450000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][16], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][16], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][16], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][16], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][16], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][16], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][16], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][16], false);

	modernSpeedometer[playerid][17] = CreatePlayerTextDraw(playerid, 499.000000, 347.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][17], 0.383332, 2.049998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][17], 240.000000, -18.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][17], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][17], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][17], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][17], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][17], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][17], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][17], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][17], false);

	modernSpeedometer[playerid][18] = CreatePlayerTextDraw(playerid, 515.000000, 347.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][18], 0.383332, 2.049998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][18], 240.000000, -18.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][18], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][18], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][18], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][18], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][18], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][18], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][18], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][18], false);

	modernSpeedometer[playerid][19] = CreatePlayerTextDraw(playerid, 531.000000, 347.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][19], 0.383332, 2.049998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][19], 240.000000, -18.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][19], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][19], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][19], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][19], 80);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][19], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][19], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][19], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][19], false);
	return 1;
}

static stock Compact_CreateUltrawideScreen(playerid)
{
	compactSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 80.000000, 402.000000, "Blindagem: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][0], 0.204999, 1.099998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][0], 0);

	compactSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 80.000000, 392.000000, "Lataria: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][1], 0.204999, 1.099998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][1], 0);

	compactSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 104.000000, 363.000000, "100");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][2], 0.395833, 1.900000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][2], 0);

	compactSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 80.000000, 369.000000, "KM/H:");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][3], 0.204999, 1.099998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][3], 0);

	compactSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 135.000000, 364.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][4], 0.691666, -0.300004);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][4], 299.000000, 104.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][4], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][4], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][4], 0);

	compactSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 80.000000, 347.000000, "Helicoptero Policial");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][5], 0.230000, 1.150000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][5], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][5], 0);

	compactSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 136.000000, 277.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][6], 5);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][6], 54.000000, 88.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][6], 1296911871);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][6], -16777216);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][6], -2686721);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetPreviewModel(playerid, compactSpeedometer[playerid][6], 442);
	PlayerTextDrawSetPreviewRot(playerid, compactSpeedometer[playerid][6], -10.000000, 0.000000, -44.000000, 0.920000);
	PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], 1, 1);

	compactSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 191.300003, 311.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][7], 0.462500, 11.699999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][7], 295.000000, -1.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][7], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][7], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][7], 0);

	compactSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 80.000000, 381.000000, "Combustivel: 100 L");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][8], 0.205000, 1.099999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][8], 0);
	return 1;
}

static stock Compact_CreateNormalScreen(playerid)
{
	compactSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 151.000000, 402.000000, "Blindagem: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][0], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][0], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][0], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][0], false);

	compactSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 151.000000, 392.000000, "Lataria: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][1], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][1], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][1], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][1], false);

	compactSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 177.000000, 362.000000, "100");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][2], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][2], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][2], false);

	compactSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 151.000000, 367.000000, "KM/H:");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][3], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][3], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][3], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][3], false);

	compactSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 205.000000, 360.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][4], 0.691666, 0.149994);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][4], 299.000000, 104.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][4], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][4], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][4], true);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][4], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][4], false);

	compactSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 152.000000, 343.000000, "Romero");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][5], 0.287499, 1.299998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][5], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][5], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][5], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][5], false);

	compactSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 205.000000, 278.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][6], 5);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][6], 61.500000, 90.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][6], 1296911871);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][6], -16777216);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][6], -2686976);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][6], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][6], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][6], false);
	PlayerTextDrawSetPreviewModel(playerid, compactSpeedometer[playerid][6], 442);
	PlayerTextDrawSetPreviewRot(playerid, compactSpeedometer[playerid][6], -10.000000, 0.000000, -44.000000, 0.920000);
	PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], 1, 1);

	compactSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 261.000000, 311.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][7], 0.462500, 11.700005);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][7], 295.000000, 0.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][7], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][7], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][7], true);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][7], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][7], false);

	compactSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 150.000000, 381.000000, "Combustivel: 100 L");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][8], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][8], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][8], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][8], false);
	return 1;
}

static stock Center_CreateUltraWideScreen(playerid)
{
	gsSpeedometerCenter[playerid][0] = CreatePlayerTextDraw(playerid, 333.000000, 358.000000, "_");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][0], 0.600000, 0.100002);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][0], 288.500000, 144.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][0], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][0], -737645313);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][0], 0);

	gsSpeedometerCenter[playerid][1] = CreatePlayerTextDraw(playerid, 399.500000, 351.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][1], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][1], -737645313);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][1], 255);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][1], 0);

	gsSpeedometerCenter[playerid][2] = CreatePlayerTextDraw(playerid, 249.500000, 351.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][2], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][2], -737645313);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][2], 0);

	gsSpeedometerCenter[playerid][3] = CreatePlayerTextDraw(playerid, 333.000000, 362.500000, "_");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][3], 0.600000, 6.150004);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][3], 298.500000, 156.500000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][3], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][3], 225);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][3], 0);

	gsSpeedometerCenter[playerid][4] = CreatePlayerTextDraw(playerid, 316.000000, 334.000000, "ld_pool:ball");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][4], 29.500000, 45.500000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][4], 336860415);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][4], 0);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][4], 1296911666);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][4], 0);

	gsSpeedometerCenter[playerid][5] = CreatePlayerTextDraw(playerid, 331.000000, 345.000000, "120");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][5], 3);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][5], 0.379166, 1.749999);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][5], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][5], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][5], 0);

	gsSpeedometerCenter[playerid][6] = CreatePlayerTextDraw(playerid, 331.000000, 365.000000, "KM/H");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][6], 3);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][6], 0.158333, 0.699999);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][6], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][6], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][6], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][6], 0);

	gsSpeedometerCenter[playerid][7] = CreatePlayerTextDraw(playerid, 392.000000, 362.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][7], 5);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][7], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][7], 24.500000, 34.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][7], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][7], 255);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawSetPreviewModel(playerid, gsSpeedometerCenter[playerid][7], 560);
	PlayerTextDrawSetPreviewRot(playerid, gsSpeedometerCenter[playerid][7], -10.000000, 0.000000, -20.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, gsSpeedometerCenter[playerid][7], 1, 1);

	gsSpeedometerCenter[playerid][8] = CreatePlayerTextDraw(playerid, 255.000000, 375.000000, "HUD:radar_girlfriend");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][8], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][8], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][8], 9.000000, 12.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][8], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][8], 0);

	gsSpeedometerCenter[playerid][9] = CreatePlayerTextDraw(playerid, 392.000000, 393.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][9], 5);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][9], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][9], 20.000000, 17.500000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][9], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][9], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][9], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][9], 0);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][9], 255);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][9], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][9], 0);
	PlayerTextDrawSetPreviewModel(playerid, gsSpeedometerCenter[playerid][9], 1650);
	PlayerTextDrawSetPreviewRot(playerid, gsSpeedometerCenter[playerid][9], -10.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, gsSpeedometerCenter[playerid][9], 1, 1);

	gsSpeedometerCenter[playerid][10] = CreatePlayerTextDraw(playerid, 254.000000, 398.000000, "HUD:radar_modgarage");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][10], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][10], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][10], 10.500000, 12.500000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][10], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][10], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][10], 0);

	gsSpeedometerCenter[playerid][11] = CreatePlayerTextDraw(playerid, 268.000000, 378.000000, "LATARIA: 100%");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][11], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][11], 0.133333, 0.750000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][11], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][11], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][11], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][11], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][11], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][11], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][11], 0);

	gsSpeedometerCenter[playerid][12] = CreatePlayerTextDraw(playerid, 268.000000, 400.000000, "BLINDAGEM: 100%");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][12], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][12], 0.133330, 0.750000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][12], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][12], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][12], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][12], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][12], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][12], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][12], 0);

	gsSpeedometerCenter[playerid][13] = CreatePlayerTextDraw(playerid, 391.000000, 400.000000, "ELETRICIDADE: 100KWH");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][13], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][13], 0.133330, 0.750000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][13], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][13], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][13], 3);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][13], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][13], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][13], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][13], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][13], 0);

	gsSpeedometerCenter[playerid][14] = CreatePlayerTextDraw(playerid, 391.000000, 378.000000, "POLICE MAVERICK");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][14], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][14], 0.133330, 0.750000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][14], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][14], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][14], 3);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][14], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][14], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][14], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][14], 0);
	return 1;
}

static stock Center_CreateNormalScreen(playerid)
{
	gsSpeedometerCenter[playerid][0] = CreatePlayerTextDraw(playerid, 334.000000, 357.500000, "_");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][0], 0.600000, 0.100003);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][0], 288.500000, 185.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][0], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][0], -737645313);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][0], 0);

	gsSpeedometerCenter[playerid][1] = CreatePlayerTextDraw(playerid, 418.500000, 352.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][1], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][1], -737645313);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][1], 255);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][1], 0);

	gsSpeedometerCenter[playerid][2] = CreatePlayerTextDraw(playerid, 230.500000, 352.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][2], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][2], -737645313);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][2], 0);

	gsSpeedometerCenter[playerid][3] = CreatePlayerTextDraw(playerid, 333.000000, 362.500000, "_");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][3], 0.600000, 6.100004);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][3], 298.500000, 196.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][3], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][3], 225);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][3], 0);

	gsSpeedometerCenter[playerid][4] = CreatePlayerTextDraw(playerid, 314.000000, 334.000000, "ld_pool:ball");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][4], 38.000000, 46.500000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][4], 336860415);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][4], 0);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][4], 1296911666);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][4], 0);

	gsSpeedometerCenter[playerid][5] = CreatePlayerTextDraw(playerid, 333.000000, 345.000000, "120");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][5], 3);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][5], 0.479166, 2.049999);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][5], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][5], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][5], 0);

	gsSpeedometerCenter[playerid][6] = CreatePlayerTextDraw(playerid, 333.000000, 365.000000, "KM/H");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][6], 3);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][6], 0.208333, 0.900000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][6], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][6], 2);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][6], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][6], 0);

	gsSpeedometerCenter[playerid][7] = CreatePlayerTextDraw(playerid, 411.000000, 362.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][7], 5);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][7], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][7], 24.500000, 34.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][7], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][7], 255);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][7], 0);
	PlayerTextDrawSetPreviewModel(playerid, gsSpeedometerCenter[playerid][7], 560);
	PlayerTextDrawSetPreviewRot(playerid, gsSpeedometerCenter[playerid][7], -10.000000, 0.000000, -20.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, gsSpeedometerCenter[playerid][7], 1, 1);

	gsSpeedometerCenter[playerid][8] = CreatePlayerTextDraw(playerid, 411.000000, 393.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][8], 5);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][8], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][8], 20.000000, 17.500000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][8], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][8], 0);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][8], 255);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][8], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][8], 0);
	PlayerTextDrawSetPreviewModel(playerid, gsSpeedometerCenter[playerid][8], 1650);
	PlayerTextDrawSetPreviewRot(playerid, gsSpeedometerCenter[playerid][8], -10.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, gsSpeedometerCenter[playerid][8], 1, 1);

	gsSpeedometerCenter[playerid][9] = CreatePlayerTextDraw(playerid, 237.000000, 377.000000, "HUD:radar_girlfriend");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][9], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][9], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][9], 10.500000, 11.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][9], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][9], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][9], 0);

	gsSpeedometerCenter[playerid][10] = CreatePlayerTextDraw(playerid, 236.000000, 399.000000, "HUD:radar_modgarage");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][10], 4);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][10], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][10], 12.000000, 12.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][10], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][10], 255);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][10], 0);

	gsSpeedometerCenter[playerid][11] = CreatePlayerTextDraw(playerid, 251.000000, 378.000000, "LATARIA: 100%");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][11], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][11], 0.179167, 0.850000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][11], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][11], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][11], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][11], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][11], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][11], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][11], 0);

	gsSpeedometerCenter[playerid][12] = CreatePlayerTextDraw(playerid, 251.000000, 400.000000, "BLINDAGEM: 100%");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][12], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][12], 0.179167, 0.850000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][12], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][12], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][12], 1);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][12], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][12], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][12], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][12], 0);

	gsSpeedometerCenter[playerid][13] = CreatePlayerTextDraw(playerid, 410.000000, 400.000000, "ELETRICIDADE: 100KWH");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][13], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][13], 0.179167, 0.850000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][13], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][13], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][13], 3);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][13], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][13], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][13], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][13], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][13], 0);

	gsSpeedometerCenter[playerid][14] = CreatePlayerTextDraw(playerid, 410.000000, 378.000000, "POLICE MAVERICK");
	PlayerTextDrawFont(playerid, gsSpeedometerCenter[playerid][14], 1);
	PlayerTextDrawLetterSize(playerid, gsSpeedometerCenter[playerid][14], 0.179167, 0.850000);
	PlayerTextDrawTextSize(playerid, gsSpeedometerCenter[playerid][14], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, gsSpeedometerCenter[playerid][14], 0);
	PlayerTextDrawSetShadow(playerid, gsSpeedometerCenter[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, gsSpeedometerCenter[playerid][14], 3);
	PlayerTextDrawColor(playerid, gsSpeedometerCenter[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, gsSpeedometerCenter[playerid][14], -1);
	PlayerTextDrawBoxColor(playerid, gsSpeedometerCenter[playerid][14], 50);
	PlayerTextDrawUseBox(playerid, gsSpeedometerCenter[playerid][14], 0);
	PlayerTextDrawSetProportional(playerid, gsSpeedometerCenter[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, gsSpeedometerCenter[playerid][14], 0);
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock UpdatePlayerSpeedometer(playerid, vehicleid, type)
{
	if (vehicleid == INVALID_VEHICLE_ID)
	{
		return 0;
	}
	
    new speedometerString[20], Float:vehicleHealth;
    GetVehicleHealth(vehicleid, vehicleHealth);
	if (vehicleHealth == MAX_VEHICLE_HEALTH)
	{
		vehicleHealth = 1000.0;
	}
    switch (type)
    {
        case 0:
        {
            new spd1, spd2, spd3;
            spd1 = GetVehicleSpeed(vehicleid) / 100;
            spd2 = GetVehicleSpeed(vehicleid) % 100;
            spd3 = spd2 % 10;
            spd2 = spd2 / 10;

			if (Vehicle_IsBoat(GetVehicleModel(vehicleid)) || Vehicle_IsPlane(GetVehicleModel(vehicleid)) || Vehicle_IsHelicopter(GetVehicleModel(vehicleid)))
			{
				if (modernSpeedometer[playerid][16] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][16], "NOS");
				}
			}
			else
			{
				if (modernSpeedometer[playerid][16] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][16], "KM/H");
				}
			}

			if (modernSpeedometer[playerid][15] != INVALID_PLAYER_TEXT_DRAW)
			{
				if (!Vehicle_GetLockedStatus(vehicleid))
				{
					PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][15], "~g~A ~w~F");
				}
				else
				{
					PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][15], "~w~A ~r~F");
				}
			}

			if (modernSpeedometer[playerid][8] != INVALID_PLAYER_TEXT_DRAW)
			{
				new vehicleName[MAX_VEHICLE_NAME_STRING];
				GetVehicleName(GetVehicleModel(vehicleid), vehicleName);
	            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][8], vehicleName);
			}

			if (modernSpeedometer[playerid][17] != INVALID_PLAYER_TEXT_DRAW)
            {
				format(speedometerString, sizeof (speedometerString), "%d", spd1);
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][17], speedometerString);
			}

			if (modernSpeedometer[playerid][18] != INVALID_PLAYER_TEXT_DRAW)
            {
				format(speedometerString, sizeof (speedometerString), "%d", spd2);
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][18], speedometerString);
			}

			if (modernSpeedometer[playerid][19] != INVALID_PLAYER_TEXT_DRAW)
			{
				format(speedometerString, sizeof (speedometerString), "%d", spd3);
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][19], speedometerString);
			}

			if (modernSpeedometer[playerid][9] != INVALID_PLAYER_TEXT_DRAW)
            {
				new fuelName[12 + 1];
				GetVehicleFuelName(GetVehicleModel(vehicleid), fuelName);
				Text_ToUpper(fuelName);
				format(speedometerString, sizeof (speedometerString), "%s", fuelName);
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][5], speedometerString);

				format(speedometerString, sizeof (speedometerString), (GetVehicleFuelType(GetVehicleModel(vehicleid)) == e_VEHICLE_FUEL_ELECTRIC ? "%02d KWH" : "%02d Litros"), Vehicle_GetFuel(vehicleid));
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][9], speedometerString);
			}

			if (modernSpeedometer[playerid][10] != INVALID_PLAYER_TEXT_DRAW)
            {
				format(speedometerString, sizeof (speedometerString), "%0.0f%", (vehicleHealth / 10));
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][10], speedometerString);
			}

			if (modernSpeedometer[playerid][11] != INVALID_PLAYER_TEXT_DRAW)
			{
				format(speedometerString, sizeof (speedometerString), "%0.0f%", (Vehicle_GetShield(vehicleid) / 10));
            	PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][11], speedometerString);
			}
        }
        case 1:
        {
			if (Vehicle_IsBoat(GetVehicleModel(vehicleid)) || Vehicle_IsPlane(GetVehicleModel(vehicleid)) || Vehicle_IsHelicopter(GetVehicleModel(vehicleid)))
			{
				if (compactSpeedometer[playerid][3] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][3], "NOS");
				}
			}
			else
			{
				if (compactSpeedometer[playerid][3] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][3], "KM/H");
				}
			}

			if (compactSpeedometer[playerid][6] != INVALID_PLAYER_TEXT_DRAW)
			{
				PlayerTextDrawSetPreviewModel(playerid, compactSpeedometer[playerid][6], GetVehicleModel(vehicleid));
				PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], Vehicle_GetColorOne(vehicleid), Vehicle_GetColorTwo(vehicleid));
			}

			if (compactSpeedometer[playerid][5] != INVALID_PLAYER_TEXT_DRAW)
			{
				new vehicleName[MAX_VEHICLE_NAME_STRING];
				GetVehicleName(GetVehicleModel(vehicleid), vehicleName);
	            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][5], vehicleName);
			}

			if (compactSpeedometer[playerid][2] != INVALID_PLAYER_TEXT_DRAW)
			{
    	        format(speedometerString, sizeof (speedometerString), "%02d", GetVehicleSpeed(vehicleid));
	            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][2], speedometerString);
			}

			if (compactSpeedometer[playerid][8] != INVALID_PLAYER_TEXT_DRAW)
			{
				new fuelName[12 + 1];
				GetVehicleFuelName(GetVehicleModel(vehicleid), fuelName);
    	        format(speedometerString, sizeof (speedometerString), (GetVehicleFuelType(GetVehicleModel(vehicleid)) == e_VEHICLE_FUEL_ELECTRIC ? "%s: %02d KWH" : "%s: %02d L"), fuelName, Vehicle_GetFuel(vehicleid));
	            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][8], speedometerString);
			}

			if (compactSpeedometer[playerid][1] != INVALID_PLAYER_TEXT_DRAW)
			{
    	        format(speedometerString, sizeof (speedometerString), "Lataria: %0.0f%", (vehicleHealth / 10));
	            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][1], speedometerString);
			}

			if (compactSpeedometer[playerid][0] != INVALID_PLAYER_TEXT_DRAW)
			{
    	        format(speedometerString, sizeof (speedometerString), "Blindagem: %0.0f%", (Vehicle_GetShield(vehicleid) / 10));
	            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][0], speedometerString);
			}
        }
		case 2:
        {
			if (Vehicle_IsBoat(GetVehicleModel(vehicleid)) || Vehicle_IsPlane(GetVehicleModel(vehicleid)) || Vehicle_IsHelicopter(GetVehicleModel(vehicleid)))
			{
				if (gsSpeedometerCenter[playerid][6] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][6], "NOS");
				}
			}
			else
			{
				if (gsSpeedometerCenter[playerid][6] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][6], "KM/H");
				}
			}

			if (gsSpeedometerCenter[playerid][7] != INVALID_PLAYER_TEXT_DRAW)
			{
				PlayerTextDrawSetPreviewModel(playerid, gsSpeedometerCenter[playerid][7], GetVehicleModel(vehicleid));
				PlayerTextDrawSetPreviewVehCol(playerid, gsSpeedometerCenter[playerid][7], Vehicle_GetColorOne(vehicleid), Vehicle_GetColorTwo(vehicleid));
			}

			if (gsSpeedometerCenter[playerid][14] != INVALID_PLAYER_TEXT_DRAW)
			{
				new vehicleName[MAX_VEHICLE_NAME_STRING];
				GetVehicleName(GetVehicleModel(vehicleid), vehicleName);
				Text_ToUpper(vehicleName);
	            PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][14], vehicleName);
			}

			if (gsSpeedometerCenter[playerid][5] != INVALID_PLAYER_TEXT_DRAW)
			{
    	        format(speedometerString, sizeof (speedometerString), "%02d", GetVehicleSpeed(vehicleid));
	            PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][5], speedometerString);
			}

			if (gsSpeedometerCenter[playerid][13] != INVALID_PLAYER_TEXT_DRAW)
			{
				new fuelName[12 + 1];
				GetVehicleFuelName(GetVehicleModel(vehicleid), fuelName);
				Text_ToUpper(fuelName);
    	        format(speedometerString, sizeof (speedometerString), (GetVehicleFuelType(GetVehicleModel(vehicleid)) == e_VEHICLE_FUEL_ELECTRIC ? "%s: %02d KWH" : "%s: %02d L"), fuelName, Vehicle_GetFuel(vehicleid));
	            PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][13], speedometerString);
			}

			if (gsSpeedometerCenter[playerid][11] != INVALID_PLAYER_TEXT_DRAW)
			{
    	        format(speedometerString, sizeof (speedometerString), "LATARIA: %0.0f%", (vehicleHealth / 10));
	            PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][11], speedometerString);
			}

			if (gsSpeedometerCenter[playerid][12] != INVALID_PLAYER_TEXT_DRAW)
			{
    	        format(speedometerString, sizeof (speedometerString), "BLINDAGEM: %0.0f%", (Vehicle_GetShield(vehicleid) / 10));
	            PlayerTextDrawSetString(playerid, gsSpeedometerCenter[playerid][12], speedometerString);
			}
        }
    }
    return 1;
}

stock AdaptSpeedometerToScreen(playerid)
{
	for (new i; i < 20; i++)
	{
		if (modernSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
		{
			PlayerTextDrawDestroy(playerid, modernSpeedometer[playerid][i]);
		}
	}

	for (new i; i < 9; i++)
	{
		if (compactSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
		{
			PlayerTextDrawDestroy(playerid, compactSpeedometer[playerid][i]);
		}
	}

	for (new i; i < 15; i++)
	{
		if (gsSpeedometerCenter[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
		{
			PlayerTextDrawDestroy(playerid, gsSpeedometerCenter[playerid][i]);
		}
	}

	// Ultrawide corrections
	if (Player_GetScreenSize(playerid) == SCREEN_ULTRAWIDE)
	{
		Modern_CreateUltrawideScreen(playerid);
		Compact_CreateUltrawideScreen(playerid);
		Center_CreateUltraWideScreen(playerid);
	}
	else
	{
		Modern_CreateNormalScreen(playerid);
		Compact_CreateNormalScreen(playerid);
		Center_CreateNormalScreen(playerid);
	}	
	return 1;
}

stock ShowPlayerSpeedometer(playerid, type)
{
	switch(type)
	{
		case 0:
		{
			for (new i; i < 20; i++)
            {
				if (modernSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
	                PlayerTextDrawShow(playerid, modernSpeedometer[playerid][i]);
				}
            }
		}
		case 1:
		{
			for (new i; i < 9; i++)
            {
				if (compactSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
	                PlayerTextDrawShow(playerid, compactSpeedometer[playerid][i]);
				}
            }
		}
		case 2:
		{
			for (new i; i < 15; i++)
            {
				if (gsSpeedometerCenter[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
	                PlayerTextDrawShow(playerid, gsSpeedometerCenter[playerid][i]);
				}
            }
		}
	}
    return 1;
}

stock HidePlayerSpeedometer(playerid)
{
	switch (Player_GetSpeedometer(playerid))
	{
		case 0:
		{
			for (new i; i < 20; i++)
			{
				if (modernSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawHide(playerid, modernSpeedometer[playerid][i]);
				}
			}
		}
		case 1:
		{
			for (new i; i < 9; i++)
			{
				if (compactSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawHide(playerid, compactSpeedometer[playerid][i]);
				}
			}
		}
		case 2:
		{
			for (new i; i < 15; i++)
			{
				if (gsSpeedometerCenter[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawHide(playerid, gsSpeedometerCenter[playerid][i]);
				}
			}
		}
	}
    return 1;
}

stock DestroyPlayerSpeedometer(playerid)
{
	switch (Player_GetSpeedometer(playerid))
	{
		case 0:
		{
			for (new i; i < 20; i++)
			{
				if (modernSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawDestroy(playerid, modernSpeedometer[playerid][i]);
				}
			}
		}
		case 1:
		{
			for (new i; i < 9; i++)
			{
				if (compactSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawDestroy(playerid, compactSpeedometer[playerid][i]);
				}
			}
		}
		case 2:
		{
			for (new i; i < 15; i++)
			{
				if (gsSpeedometerCenter[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawDestroy(playerid, gsSpeedometerCenter[playerid][i]);
				}
			}
		}
	}
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	// Modern
    Modern_CreateNormalScreen(playerid);

	// Compact
	Compact_CreateNormalScreen(playerid);

	// Center
	Center_CreateNormalScreen(playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	#pragma unused reason // need this directive, on account of YSI which shows warnings in case the parameter is not used.
	
    HidePlayerSpeedometer(playerid);
    DestroyPlayerSpeedometer(playerid);
	return 1;
}
