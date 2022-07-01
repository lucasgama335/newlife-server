#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Text:gsLoadingScreenTextdraw[5];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowLoadingScreen(playerid)
{
    for (new i; i < sizeof(gsLoadingScreenTextdraw); i++)
	{
		TextDrawShowForPlayer(playerid, gsLoadingScreenTextdraw[i]);
	}
	return 1;
}

stock HideLoadingScreen(playerid)
{
    for (new i; i < sizeof(gsLoadingScreenTextdraw); i++)
	{
		TextDrawHideForPlayer(playerid, gsLoadingScreenTextdraw[i]);
	}
	return 1;
}

stock DestroyLoadingScreen()
{
    for (new i; i < sizeof(gsLoadingScreenTextdraw); i++)
	{
		TextDrawDestroy(gsLoadingScreenTextdraw[i]);
	}
	return 1;
}
//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
	gsLoadingScreenTextdraw[0] = TextDrawCreate(320.000000, -1.000000, "_");
	TextDrawFont(gsLoadingScreenTextdraw[0], 1);
	TextDrawLetterSize(gsLoadingScreenTextdraw[0], 0.600000, 50.250003);
	TextDrawTextSize(gsLoadingScreenTextdraw[0], 303.000000, 638.500000);
	TextDrawSetOutline(gsLoadingScreenTextdraw[0], 1);
	TextDrawSetShadow(gsLoadingScreenTextdraw[0], 0);
	TextDrawAlignment(gsLoadingScreenTextdraw[0], 2);
	TextDrawColor(gsLoadingScreenTextdraw[0], -1);
	TextDrawBackgroundColor(gsLoadingScreenTextdraw[0], 255);
	TextDrawBoxColor(gsLoadingScreenTextdraw[0], 255);
	TextDrawUseBox(gsLoadingScreenTextdraw[0], true);
	TextDrawSetProportional(gsLoadingScreenTextdraw[0], true);
	TextDrawSetSelectable(gsLoadingScreenTextdraw[0], false);

	gsLoadingScreenTextdraw[1] = TextDrawCreate(236.000000, 162.000000, "Newlife RPG");
	TextDrawFont(gsLoadingScreenTextdraw[1], 0);
	TextDrawLetterSize(gsLoadingScreenTextdraw[1], 0.937497, 3.299998);
	TextDrawTextSize(gsLoadingScreenTextdraw[1], 581.500000, 20.000000);
	TextDrawSetOutline(gsLoadingScreenTextdraw[1], 1);
	TextDrawSetShadow(gsLoadingScreenTextdraw[1], 0);
	TextDrawAlignment(gsLoadingScreenTextdraw[1], 1);
	TextDrawColor(gsLoadingScreenTextdraw[1], -1);
	TextDrawBackgroundColor(gsLoadingScreenTextdraw[1], 255);
	TextDrawBoxColor(gsLoadingScreenTextdraw[1], -16777166);
	TextDrawUseBox(gsLoadingScreenTextdraw[1], false);
	TextDrawSetProportional(gsLoadingScreenTextdraw[1], true);
	TextDrawSetSelectable(gsLoadingScreenTextdraw[1], false);

	gsLoadingScreenTextdraw[2] = TextDrawCreate(239.000000, 193.000000, "CARREGANDO, AGUARDE...");
	TextDrawFont(gsLoadingScreenTextdraw[2], 2);
	TextDrawLetterSize(gsLoadingScreenTextdraw[2], 0.174998, 1.200000);
	TextDrawTextSize(gsLoadingScreenTextdraw[2], 400.000000, 17.000000);
	TextDrawSetOutline(gsLoadingScreenTextdraw[2], 1);
	TextDrawSetShadow(gsLoadingScreenTextdraw[2], 0);
	TextDrawAlignment(gsLoadingScreenTextdraw[2], 1);
	TextDrawColor(gsLoadingScreenTextdraw[2], -1);
	TextDrawBackgroundColor(gsLoadingScreenTextdraw[2], 255);
	TextDrawBoxColor(gsLoadingScreenTextdraw[2], 50);
	TextDrawUseBox(gsLoadingScreenTextdraw[2], true);
	TextDrawSetProportional(gsLoadingScreenTextdraw[2], true);
	TextDrawSetSelectable(gsLoadingScreenTextdraw[2], false);

	gsLoadingScreenTextdraw[3] = TextDrawCreate(259.000000, 236.000000, "AGUARDE UM INSTANTE...");
	TextDrawFont(gsLoadingScreenTextdraw[3], 1);
	TextDrawLetterSize(gsLoadingScreenTextdraw[3], 0.316666, 1.200001);
	TextDrawTextSize(gsLoadingScreenTextdraw[3], 400.000000, 17.000000);
	TextDrawSetOutline(gsLoadingScreenTextdraw[3], 1);
	TextDrawSetShadow(gsLoadingScreenTextdraw[3], 0);
	TextDrawAlignment(gsLoadingScreenTextdraw[3], 1);
	TextDrawColor(gsLoadingScreenTextdraw[3], -1);
	TextDrawBackgroundColor(gsLoadingScreenTextdraw[3], 255);
	TextDrawBoxColor(gsLoadingScreenTextdraw[3], 50);
	TextDrawUseBox(gsLoadingScreenTextdraw[3], false);
	TextDrawSetProportional(gsLoadingScreenTextdraw[3], true);
	TextDrawSetSelectable(gsLoadingScreenTextdraw[3], false);

	gsLoadingScreenTextdraw[4] = TextDrawCreate(207.000000, 425.000000, "Todos os Direitos Reservados - 2021. Por: RhaegarX");
	TextDrawFont(gsLoadingScreenTextdraw[4], 0);
	TextDrawLetterSize(gsLoadingScreenTextdraw[4], 0.320832, 1.200000);
	TextDrawTextSize(gsLoadingScreenTextdraw[4], 670.000000, 17.000000);
	TextDrawSetOutline(gsLoadingScreenTextdraw[4], 1);
	TextDrawSetShadow(gsLoadingScreenTextdraw[4], 0);
	TextDrawAlignment(gsLoadingScreenTextdraw[4], 1);
	TextDrawColor(gsLoadingScreenTextdraw[4], -1);
	TextDrawBackgroundColor(gsLoadingScreenTextdraw[4], 255);
	TextDrawBoxColor(gsLoadingScreenTextdraw[4], 50);
	TextDrawUseBox(gsLoadingScreenTextdraw[4], false);
	TextDrawSetProportional(gsLoadingScreenTextdraw[4], true);
	TextDrawSetSelectable(gsLoadingScreenTextdraw[4], false);
    return 1;
}

hook OnGameModeExit()
{
	DestroyLoadingScreen();
	return 1;
}