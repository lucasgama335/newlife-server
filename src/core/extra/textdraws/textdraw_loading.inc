#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Text:textLoadingConnect[5];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowLoadingScreen(playerid)
{
    for (new i; i < sizeof(textLoadingConnect); i++)
	{
		TextDrawShowForPlayer(playerid, textLoadingConnect[i]);
	}
}

stock HideLoadingScreen(playerid)
{
    for (new i; i < sizeof(textLoadingConnect); i++)
	{
		TextDrawHideForPlayer(playerid, textLoadingConnect[i]);
	}
}

stock DestroyLoadingScreen()
{
    for (new i; i < sizeof(textLoadingConnect); i++)
	{
		TextDrawDestroy(textLoadingConnect[i]);
	}
}
//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    // TextDraw Carregando (OnPlayerConnect)
	textLoadingConnect[0] = TextDrawCreate(320.000000, -1.000000, "_");
	TextDrawFont(textLoadingConnect[0], 1);
	TextDrawLetterSize(textLoadingConnect[0], 0.600000, 50.250003);
	TextDrawTextSize(textLoadingConnect[0], 303.000000, 638.500000);
	TextDrawSetOutline(textLoadingConnect[0], 1);
	TextDrawSetShadow(textLoadingConnect[0], 0);
	TextDrawAlignment(textLoadingConnect[0], 2);
	TextDrawColor(textLoadingConnect[0], -1);
	TextDrawBackgroundColor(textLoadingConnect[0], 255);
	TextDrawBoxColor(textLoadingConnect[0], 255);
	TextDrawUseBox(textLoadingConnect[0], true);
	TextDrawSetProportional(textLoadingConnect[0], true);
	TextDrawSetSelectable(textLoadingConnect[0], false);

	textLoadingConnect[1] = TextDrawCreate(236.000000, 162.000000, "Newlife RPG");
	TextDrawFont(textLoadingConnect[1], 0);
	TextDrawLetterSize(textLoadingConnect[1], 0.937497, 3.299998);
	TextDrawTextSize(textLoadingConnect[1], 581.500000, 20.000000);
	TextDrawSetOutline(textLoadingConnect[1], 1);
	TextDrawSetShadow(textLoadingConnect[1], 0);
	TextDrawAlignment(textLoadingConnect[1], 1);
	TextDrawColor(textLoadingConnect[1], -1);
	TextDrawBackgroundColor(textLoadingConnect[1], 255);
	TextDrawBoxColor(textLoadingConnect[1], -16777166);
	TextDrawUseBox(textLoadingConnect[1], false);
	TextDrawSetProportional(textLoadingConnect[1], true);
	TextDrawSetSelectable(textLoadingConnect[1], false);

	textLoadingConnect[2] = TextDrawCreate(239.000000, 193.000000, "CARREGANDO, AGUARDE...");
	TextDrawFont(textLoadingConnect[2], 2);
	TextDrawLetterSize(textLoadingConnect[2], 0.174998, 1.200000);
	TextDrawTextSize(textLoadingConnect[2], 400.000000, 17.000000);
	TextDrawSetOutline(textLoadingConnect[2], 1);
	TextDrawSetShadow(textLoadingConnect[2], 0);
	TextDrawAlignment(textLoadingConnect[2], 1);
	TextDrawColor(textLoadingConnect[2], -1);
	TextDrawBackgroundColor(textLoadingConnect[2], 255);
	TextDrawBoxColor(textLoadingConnect[2], 50);
	TextDrawUseBox(textLoadingConnect[2], true);
	TextDrawSetProportional(textLoadingConnect[2], true);
	TextDrawSetSelectable(textLoadingConnect[2], false);

	textLoadingConnect[3] = TextDrawCreate(259.000000, 236.000000, "AGUARDE UM INSTANTE...");
	TextDrawFont(textLoadingConnect[3], 1);
	TextDrawLetterSize(textLoadingConnect[3], 0.316666, 1.200001);
	TextDrawTextSize(textLoadingConnect[3], 400.000000, 17.000000);
	TextDrawSetOutline(textLoadingConnect[3], 1);
	TextDrawSetShadow(textLoadingConnect[3], 0);
	TextDrawAlignment(textLoadingConnect[3], 1);
	TextDrawColor(textLoadingConnect[3], -1);
	TextDrawBackgroundColor(textLoadingConnect[3], 255);
	TextDrawBoxColor(textLoadingConnect[3], 50);
	TextDrawUseBox(textLoadingConnect[3], false);
	TextDrawSetProportional(textLoadingConnect[3], true);
	TextDrawSetSelectable(textLoadingConnect[3], false);

	textLoadingConnect[4] = TextDrawCreate(207.000000, 425.000000, "Todos os Direitos Reservados - 2021. Por: RhaegarX");
	TextDrawFont(textLoadingConnect[4], 0);
	TextDrawLetterSize(textLoadingConnect[4], 0.320832, 1.200000);
	TextDrawTextSize(textLoadingConnect[4], 670.000000, 17.000000);
	TextDrawSetOutline(textLoadingConnect[4], 1);
	TextDrawSetShadow(textLoadingConnect[4], 0);
	TextDrawAlignment(textLoadingConnect[4], 1);
	TextDrawColor(textLoadingConnect[4], -1);
	TextDrawBackgroundColor(textLoadingConnect[4], 255);
	TextDrawBoxColor(textLoadingConnect[4], 50);
	TextDrawUseBox(textLoadingConnect[4], false);
	TextDrawSetProportional(textLoadingConnect[4], true);
	TextDrawSetSelectable(textLoadingConnect[4], false);
    return 1;
}

hook OnGameModeExit()
{
	DestroyLoadingScreen();
}