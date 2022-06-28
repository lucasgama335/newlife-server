#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:spectateTextDraw[MAX_PLAYERS][27];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowSpectateScreen(playerid)
{
	for (new i; i < 27; i++)
	{
		PlayerTextDrawShow(playerid, spectateTextDraw[playerid][i]);
	}
}

stock HideSpectateScreen(playerid)
{
    for (new i; i < 27; i++)
	{
		PlayerTextDrawHide(playerid, spectateTextDraw[playerid][i]);
	}
}

stock DestroySpectateScreen(playerid)
{
    for (new i; i < 27; i++)
	{
        PlayerTextDrawDestroy(playerid, spectateTextDraw[playerid][i]);
	}
}

stock PlayerText:SpectateTextDraw_GetByIndex(playerid, index)
{
	if (index > 27) return spectateTextDraw[playerid][0];

	return spectateTextDraw[playerid][index];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    spectateTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 317.000000, 310.000000, "_");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][0], 0.600000, 11.449996);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][0], 298.500000, 265.500000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][0], 2);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][0], 538976511);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][0], true);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][0], false);

    spectateTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 193.000000, 317.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][1], 5);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][1], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][1], 55.000000, 71.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][1], 1296911741);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][1], -16776961);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][1], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, spectateTextDraw[playerid][1], 217);
    PlayerTextDrawSetPreviewRot(playerid, spectateTextDraw[playerid][1], -10.000000, 0.000000, 0.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, spectateTextDraw[playerid][1], 1, 1);

    spectateTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 193.000000, 391.000000, "~r~VIDA: ~w~98%");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][2], 2);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][2], 0.208333, 0.949998);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][2], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][2], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][2], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][2], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][2], false);

    spectateTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 193.000000, 401.000000, "~b~COLETE: ~w~100%");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][3], 2);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][3], 0.208333, 0.949998);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][3], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][3], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][3], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][3], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][3], false);

    spectateTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 254.000000, 315.000000, "OBSERVANDO:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][4], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][4], 0.274998, 1.299998);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][4], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][4], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][4], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][4], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][4], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][4], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][4], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][4], false);

    spectateTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 321.000000, 315.000000, "NOME_SOBRENOME");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][5], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][5], 0.241666, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][5], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][5], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][5], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][5], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][5], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][5], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][5], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][5], false);

    spectateTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 254.000000, 334.000000, "ID(GAME):");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][6], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][6], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][6], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][6], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][6], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][6], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][6], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][6], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][6], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][6], false);

    spectateTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 293.000000, 334.000000, "~w~50");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][7], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][7], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][7], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][7], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][7], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][7], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][7], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][7], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][7], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][7], false);

    spectateTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 254.000000, 346.000000, "ID(DATABASE):");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][8], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][8], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][8], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][8], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][8], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][8], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][8], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][8], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][8], false);

    spectateTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 309.000000, 346.000000, "1500");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][9], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][9], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][9], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][9], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][9], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][9], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][9], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][9], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][9], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][9], false);

    spectateTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 254.000000, 368.000000, "ARMA:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][10], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][10], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][10], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][10], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][10], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][10], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][10], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][10], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][10], false);

    spectateTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 279.000000, 368.000000, "AK-47");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][11], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][11], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][11], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][11], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][11], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][11], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][11], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][11], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][11], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][11], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][11], false);

    spectateTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 254.000000, 379.000000, "MUNICAO:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][12], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][12], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][12], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][12], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][12], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][12], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][12], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][12], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][12], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][12], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][12], false);

    spectateTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 294.000000, 380.000000, "450 BALAS");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][13], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][13], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][13], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][13], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][13], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][13], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][13], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][13], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][13], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][13], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][13], false);

    spectateTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 343.000000, 334.000000, "PLATAFORMA:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][14], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][14], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][14], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][14], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][14], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][14], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][14], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][14], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][14], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][14], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][14], false);

    spectateTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 396.000000, 334.000000, "ANDROID");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][15], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][15], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][15], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][15], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][15], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][15], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][15], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][15], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][15], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][15], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][15], false);

    spectateTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 343.000000, 346.000000, "DINHEIRO:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][16], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][16], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][16], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][16], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][16], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][16], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][16], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][16], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][16], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][16], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][16], false);

    spectateTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 382.000000, 346.000000, "500.000.000");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][17], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][17], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][17], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][17], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][17], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][17], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][17], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][17], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][17], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][17], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][17], false);

    spectateTextDraw[playerid][18] = CreatePlayerTextDraw(playerid, 343.000000, 380.000000, "VEICULO:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][18], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][18], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][18], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][18], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][18], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][18], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][18], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][18], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][18], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][18], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][18], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][18], false);

    spectateTextDraw[playerid][19] = CreatePlayerTextDraw(playerid, 379.000000, 380.000000, "POLICE MAVERICK");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][19], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][19], 0.274998, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][19], 325.000000, -18.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][19], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][19], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][19], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][19], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][19], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][19], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][19], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][19], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][19], false);

    spectateTextDraw[playerid][20] = CreatePlayerTextDraw(playerid, 343.000000, 368.000000, "VELOCIDADE:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][20], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][20], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][20], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][20], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][20], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][20], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][20], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][20], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][20], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][20], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][20], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][20], false);

    spectateTextDraw[playerid][21] = CreatePlayerTextDraw(playerid, 392.000000, 368.000000, "343");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][21], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][21], 0.237498, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][21], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][21], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][21], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][21], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][21], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][21], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][21], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][21], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][21], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][21], false);

    spectateTextDraw[playerid][22] = CreatePlayerTextDraw(playerid, 444.000000, 310.000000, "X");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][22], 2);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][22], 0.258332, 1.299998);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][22], 16.500000, 10.500000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][22], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][22], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][22], 2);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][22], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][22], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][22], -1962934017);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][22], true);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][22], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][22], true);

    spectateTextDraw[playerid][23] = CreatePlayerTextDraw(playerid, 254.000000, 357.000000, "NIVEL:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][23], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][23], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][23], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][23], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][23], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][23], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][23], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][23], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][23], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][23], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][23], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][23], false);

    spectateTextDraw[playerid][24] = CreatePlayerTextDraw(playerid, 279.000000, 357.000000, "45");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][24], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][24], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][24], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][24], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][24], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][24], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][24], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][24], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][24], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][24], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][24], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][24], false);

    spectateTextDraw[playerid][25] = CreatePlayerTextDraw(playerid, 343.000000, 357.000000, "MOEDAS:");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][25], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][25], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][25], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][25], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][25], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][25], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][25], -1061109505);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][25], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][25], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][25], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][25], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][25], false);

    spectateTextDraw[playerid][26] = CreatePlayerTextDraw(playerid, 378.000000, 357.000000, "500");
    PlayerTextDrawFont(playerid, spectateTextDraw[playerid][26], 1);
    PlayerTextDrawLetterSize(playerid, spectateTextDraw[playerid][26], 0.224996, 1.100000);
    PlayerTextDrawTextSize(playerid, spectateTextDraw[playerid][26], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, spectateTextDraw[playerid][26], 0);
    PlayerTextDrawSetShadow(playerid, spectateTextDraw[playerid][26], 0);
    PlayerTextDrawAlignment(playerid, spectateTextDraw[playerid][26], 1);
    PlayerTextDrawColor(playerid, spectateTextDraw[playerid][26], -1);
    PlayerTextDrawBackgroundColor(playerid, spectateTextDraw[playerid][26], 255);
    PlayerTextDrawBoxColor(playerid, spectateTextDraw[playerid][26], 50);
    PlayerTextDrawUseBox(playerid, spectateTextDraw[playerid][26], false);
    PlayerTextDrawSetProportional(playerid, spectateTextDraw[playerid][26], true);
    PlayerTextDrawSetSelectable(playerid, spectateTextDraw[playerid][26], false);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    HideSpectateScreen(playerid);
	DestroySpectateScreen(playerid);
    return 1;
}