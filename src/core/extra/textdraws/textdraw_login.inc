#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Text:gsLoginScreenTextdraw[9];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowLoginScreen(playerid)
{
    for (new i; i < sizeof(gsLoginScreenTextdraw); i++)
	{
		TextDrawShowForPlayer(playerid, gsLoginScreenTextdraw[i]);
	}
	return 1;
}

stock HideLoginScreen(playerid)
{
    for (new i; i < sizeof(gsLoginScreenTextdraw); i++)
	{
		TextDrawHideForPlayer(playerid, gsLoginScreenTextdraw[i]);
	}
	return 1;
}

stock DestroyLoginScreen()
{
    for (new i; i < sizeof(gsLoginScreenTextdraw); i++)
	{
		TextDrawDestroy(gsLoginScreenTextdraw[i]);
	}
	return 1;
}

stock Text:GetLoginScreenTextdrawId(index)
{
	if (index > sizeof(gsLoginScreenTextdraw)) return gsLoginScreenTextdraw[0];

	return gsLoginScreenTextdraw[index];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsLoginScreenTextdraw[0] = TextDrawCreate(93.000000, -5.000000, "_");
	TextDrawFont(gsLoginScreenTextdraw[0], 1);
	TextDrawLetterSize(gsLoginScreenTextdraw[0], 0.600000, 50.999996);
	TextDrawTextSize(gsLoginScreenTextdraw[0], 298.500000, 188.500000);
	TextDrawSetOutline(gsLoginScreenTextdraw[0], 1);
	TextDrawSetShadow(gsLoginScreenTextdraw[0], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[0], 2);
	TextDrawColor(gsLoginScreenTextdraw[0], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[0], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[0], 215);
	TextDrawUseBox(gsLoginScreenTextdraw[0], true);
	TextDrawSetProportional(gsLoginScreenTextdraw[0], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[0], false);

	gsLoginScreenTextdraw[1] = TextDrawCreate(18.000000, 126.000000, "New Life RPG");
	TextDrawFont(gsLoginScreenTextdraw[1], 0);
	TextDrawLetterSize(gsLoginScreenTextdraw[1], 0.495833, 1.500000);
	TextDrawTextSize(gsLoginScreenTextdraw[1], 400.000000, 17.000000);
	TextDrawSetOutline(gsLoginScreenTextdraw[1], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[1], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[1], 1);
	TextDrawColor(gsLoginScreenTextdraw[1], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[1], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[1], 50);
	TextDrawUseBox(gsLoginScreenTextdraw[1], false);
	TextDrawSetProportional(gsLoginScreenTextdraw[1], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[1], false);

	gsLoginScreenTextdraw[2] = TextDrawCreate(51.000000, 141.000000, "Seja bem vindo a sua nova vida");
	TextDrawFont(gsLoginScreenTextdraw[2], 1);
	TextDrawLetterSize(gsLoginScreenTextdraw[2], 0.191666, 1.000000);
	TextDrawTextSize(gsLoginScreenTextdraw[2], 400.000000, 17.000000);
	TextDrawSetOutline(gsLoginScreenTextdraw[2], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[2], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[2], 1);
	TextDrawColor(gsLoginScreenTextdraw[2], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[2], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[2], 50);
	TextDrawUseBox(gsLoginScreenTextdraw[2], false);
	TextDrawSetProportional(gsLoginScreenTextdraw[2], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[2], false);

	gsLoginScreenTextdraw[3] = TextDrawCreate(200.000000, 153.000000, "I");
	TextDrawFont(gsLoginScreenTextdraw[3], 1);
	TextDrawLetterSize(gsLoginScreenTextdraw[3], -17.762477, 0.249999);
	TextDrawTextSize(gsLoginScreenTextdraw[3], 400.000000, 17.000000);
	TextDrawSetOutline(gsLoginScreenTextdraw[3], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[3], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[3], 1);
	TextDrawColor(gsLoginScreenTextdraw[3], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[3], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[3], 50);
	TextDrawUseBox(gsLoginScreenTextdraw[3], false);
	TextDrawSetProportional(gsLoginScreenTextdraw[3], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[3], false);

	gsLoginScreenTextdraw[4] = TextDrawCreate(27.000000, 158.000000, "ESTAMOS SEMPRE TRABALHANDO PARA A SUA DIVERSAO");
	TextDrawFont(gsLoginScreenTextdraw[4], 1);
	TextDrawLetterSize(gsLoginScreenTextdraw[4], 0.129167, 0.800000);
	TextDrawTextSize(gsLoginScreenTextdraw[4], 400.000000, 17.000000);
	TextDrawSetOutline(gsLoginScreenTextdraw[4], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[4], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[4], 1);
	TextDrawColor(gsLoginScreenTextdraw[4], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[4], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[4], 50);
	TextDrawUseBox(gsLoginScreenTextdraw[4], false);
	TextDrawSetProportional(gsLoginScreenTextdraw[4], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[4], false);

	gsLoginScreenTextdraw[5] = TextDrawCreate(87.000000, 222.000000, "FAZER LOGIN");
	TextDrawFont(gsLoginScreenTextdraw[5], 3);
	TextDrawLetterSize(gsLoginScreenTextdraw[5], 0.395832, 1.600000);
	TextDrawTextSize(gsLoginScreenTextdraw[5], 19.500000, 100.500000);
	TextDrawSetOutline(gsLoginScreenTextdraw[5], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[5], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[5], 2);
	TextDrawColor(gsLoginScreenTextdraw[5], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[5], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[5], 1296911706);
	TextDrawUseBox(gsLoginScreenTextdraw[5], true);
	TextDrawSetProportional(gsLoginScreenTextdraw[5], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[5], true);

	gsLoginScreenTextdraw[6] = TextDrawCreate(87.000000, 247.000000, "INFORMACOES");
	TextDrawFont(gsLoginScreenTextdraw[6], 3);
	TextDrawLetterSize(gsLoginScreenTextdraw[6], 0.395832, 1.600000);
	TextDrawTextSize(gsLoginScreenTextdraw[6], 19.500000, 100.500000);
	TextDrawSetOutline(gsLoginScreenTextdraw[6], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[6], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[6], 2);
	TextDrawColor(gsLoginScreenTextdraw[6], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[6], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[6], 1296911706);
	TextDrawUseBox(gsLoginScreenTextdraw[6], true);
	TextDrawSetProportional(gsLoginScreenTextdraw[6], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[6], true);

	gsLoginScreenTextdraw[7] = TextDrawCreate(87.000000, 272.000000, "CREDITOS");
	TextDrawFont(gsLoginScreenTextdraw[7], 3);
	TextDrawLetterSize(gsLoginScreenTextdraw[7], 0.395832, 1.600000);
	TextDrawTextSize(gsLoginScreenTextdraw[7], 19.500000, 100.500000);
	TextDrawSetOutline(gsLoginScreenTextdraw[7], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[7], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[7], 2);
	TextDrawColor(gsLoginScreenTextdraw[7], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[7], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[7], 1296911706);
	TextDrawUseBox(gsLoginScreenTextdraw[7], true);
	TextDrawSetProportional(gsLoginScreenTextdraw[7], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[7], true);

	gsLoginScreenTextdraw[8] = TextDrawCreate(87.000000, 297.000000, "SAIR");
	TextDrawFont(gsLoginScreenTextdraw[8], 3);
	TextDrawLetterSize(gsLoginScreenTextdraw[8], 0.395832, 1.600000);
	TextDrawTextSize(gsLoginScreenTextdraw[8], 19.500000, 100.500000);
	TextDrawSetOutline(gsLoginScreenTextdraw[8], 0);
	TextDrawSetShadow(gsLoginScreenTextdraw[8], 0);
	TextDrawAlignment(gsLoginScreenTextdraw[8], 2);
	TextDrawColor(gsLoginScreenTextdraw[8], -1);
	TextDrawBackgroundColor(gsLoginScreenTextdraw[8], 255);
	TextDrawBoxColor(gsLoginScreenTextdraw[8], 1296911706);
	TextDrawUseBox(gsLoginScreenTextdraw[8], true);
	TextDrawSetProportional(gsLoginScreenTextdraw[8], true);
	TextDrawSetSelectable(gsLoginScreenTextdraw[8], true);
    return 1;
}

hook OnGameModeExit()
{
	DestroyLoginScreen();
	return 1;
}
