#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Text:textDrawLogin[9];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowLoginScreen(playerid)
{
    for (new i; i < sizeof(textDrawLogin); i++)
	{
		TextDrawShowForPlayer(playerid, textDrawLogin[i]);
	}
	return 1;
}

stock HideLoginScreen(playerid)
{
    for (new i; i < sizeof(textDrawLogin); i++)
	{
		TextDrawHideForPlayer(playerid, textDrawLogin[i]);
	}
	return 1;
}

stock DestroyLoginScreen()
{
    for (new i; i < sizeof(textDrawLogin); i++)
	{
		TextDrawDestroy(textDrawLogin[i]);
	}
	return 1;
}

stock Text:LoginTextDraw_GetByIndex(index)
{
	if (index > sizeof(textDrawLogin)) return textDrawLogin[0];

	return textDrawLogin[index];
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    // Tela de Login
    textDrawLogin[0] = TextDrawCreate(93.000000, -5.000000, "_");
	TextDrawFont(textDrawLogin[0], 1);
	TextDrawLetterSize(textDrawLogin[0], 0.600000, 50.999996);
	TextDrawTextSize(textDrawLogin[0], 298.500000, 188.500000);
	TextDrawSetOutline(textDrawLogin[0], 1);
	TextDrawSetShadow(textDrawLogin[0], 0);
	TextDrawAlignment(textDrawLogin[0], 2);
	TextDrawColor(textDrawLogin[0], -1);
	TextDrawBackgroundColor(textDrawLogin[0], 255);
	TextDrawBoxColor(textDrawLogin[0], 215);
	TextDrawUseBox(textDrawLogin[0], true);
	TextDrawSetProportional(textDrawLogin[0], true);
	TextDrawSetSelectable(textDrawLogin[0], false);

	textDrawLogin[1] = TextDrawCreate(18.000000, 126.000000, "New Life RPG");
	TextDrawFont(textDrawLogin[1], 0);
	TextDrawLetterSize(textDrawLogin[1], 0.495833, 1.500000);
	TextDrawTextSize(textDrawLogin[1], 400.000000, 17.000000);
	TextDrawSetOutline(textDrawLogin[1], 0);
	TextDrawSetShadow(textDrawLogin[1], 0);
	TextDrawAlignment(textDrawLogin[1], 1);
	TextDrawColor(textDrawLogin[1], -1);
	TextDrawBackgroundColor(textDrawLogin[1], 255);
	TextDrawBoxColor(textDrawLogin[1], 50);
	TextDrawUseBox(textDrawLogin[1], false);
	TextDrawSetProportional(textDrawLogin[1], true);
	TextDrawSetSelectable(textDrawLogin[1], false);

	textDrawLogin[2] = TextDrawCreate(51.000000, 141.000000, "Seja bem vindo a sua nova vida");
	TextDrawFont(textDrawLogin[2], 1);
	TextDrawLetterSize(textDrawLogin[2], 0.191666, 1.000000);
	TextDrawTextSize(textDrawLogin[2], 400.000000, 17.000000);
	TextDrawSetOutline(textDrawLogin[2], 0);
	TextDrawSetShadow(textDrawLogin[2], 0);
	TextDrawAlignment(textDrawLogin[2], 1);
	TextDrawColor(textDrawLogin[2], -1);
	TextDrawBackgroundColor(textDrawLogin[2], 255);
	TextDrawBoxColor(textDrawLogin[2], 50);
	TextDrawUseBox(textDrawLogin[2], false);
	TextDrawSetProportional(textDrawLogin[2], true);
	TextDrawSetSelectable(textDrawLogin[2], false);

	textDrawLogin[3] = TextDrawCreate(200.000000, 153.000000, "I");
	TextDrawFont(textDrawLogin[3], 1);
	TextDrawLetterSize(textDrawLogin[3], -17.762477, 0.249999);
	TextDrawTextSize(textDrawLogin[3], 400.000000, 17.000000);
	TextDrawSetOutline(textDrawLogin[3], 0);
	TextDrawSetShadow(textDrawLogin[3], 0);
	TextDrawAlignment(textDrawLogin[3], 1);
	TextDrawColor(textDrawLogin[3], -1);
	TextDrawBackgroundColor(textDrawLogin[3], 255);
	TextDrawBoxColor(textDrawLogin[3], 50);
	TextDrawUseBox(textDrawLogin[3], false);
	TextDrawSetProportional(textDrawLogin[3], true);
	TextDrawSetSelectable(textDrawLogin[3], false);

	textDrawLogin[4] = TextDrawCreate(27.000000, 158.000000, "ESTAMOS SEMPRE TRABALHANDO PARA A SUA DIVERSAO");
	TextDrawFont(textDrawLogin[4], 1);
	TextDrawLetterSize(textDrawLogin[4], 0.129167, 0.800000);
	TextDrawTextSize(textDrawLogin[4], 400.000000, 17.000000);
	TextDrawSetOutline(textDrawLogin[4], 0);
	TextDrawSetShadow(textDrawLogin[4], 0);
	TextDrawAlignment(textDrawLogin[4], 1);
	TextDrawColor(textDrawLogin[4], -1);
	TextDrawBackgroundColor(textDrawLogin[4], 255);
	TextDrawBoxColor(textDrawLogin[4], 50);
	TextDrawUseBox(textDrawLogin[4], false);
	TextDrawSetProportional(textDrawLogin[4], true);
	TextDrawSetSelectable(textDrawLogin[4], false);

	textDrawLogin[5] = TextDrawCreate(87.000000, 222.000000, "FAZER LOGIN");
	TextDrawFont(textDrawLogin[5], 3);
	TextDrawLetterSize(textDrawLogin[5], 0.395832, 1.600000);
	TextDrawTextSize(textDrawLogin[5], 19.500000, 100.500000);
	TextDrawSetOutline(textDrawLogin[5], 0);
	TextDrawSetShadow(textDrawLogin[5], 0);
	TextDrawAlignment(textDrawLogin[5], 2);
	TextDrawColor(textDrawLogin[5], -1);
	TextDrawBackgroundColor(textDrawLogin[5], 255);
	TextDrawBoxColor(textDrawLogin[5], 1296911706);
	TextDrawUseBox(textDrawLogin[5], true);
	TextDrawSetProportional(textDrawLogin[5], true);
	TextDrawSetSelectable(textDrawLogin[5], true);

	textDrawLogin[6] = TextDrawCreate(87.000000, 247.000000, "INFORMACOES");
	TextDrawFont(textDrawLogin[6], 3);
	TextDrawLetterSize(textDrawLogin[6], 0.395832, 1.600000);
	TextDrawTextSize(textDrawLogin[6], 19.500000, 100.500000);
	TextDrawSetOutline(textDrawLogin[6], 0);
	TextDrawSetShadow(textDrawLogin[6], 0);
	TextDrawAlignment(textDrawLogin[6], 2);
	TextDrawColor(textDrawLogin[6], -1);
	TextDrawBackgroundColor(textDrawLogin[6], 255);
	TextDrawBoxColor(textDrawLogin[6], 1296911706);
	TextDrawUseBox(textDrawLogin[6], true);
	TextDrawSetProportional(textDrawLogin[6], true);
	TextDrawSetSelectable(textDrawLogin[6], true);

	textDrawLogin[7] = TextDrawCreate(87.000000, 272.000000, "CREDITOS");
	TextDrawFont(textDrawLogin[7], 3);
	TextDrawLetterSize(textDrawLogin[7], 0.395832, 1.600000);
	TextDrawTextSize(textDrawLogin[7], 19.500000, 100.500000);
	TextDrawSetOutline(textDrawLogin[7], 0);
	TextDrawSetShadow(textDrawLogin[7], 0);
	TextDrawAlignment(textDrawLogin[7], 2);
	TextDrawColor(textDrawLogin[7], -1);
	TextDrawBackgroundColor(textDrawLogin[7], 255);
	TextDrawBoxColor(textDrawLogin[7], 1296911706);
	TextDrawUseBox(textDrawLogin[7], true);
	TextDrawSetProportional(textDrawLogin[7], true);
	TextDrawSetSelectable(textDrawLogin[7], true);

	textDrawLogin[8] = TextDrawCreate(87.000000, 297.000000, "SAIR");
	TextDrawFont(textDrawLogin[8], 3);
	TextDrawLetterSize(textDrawLogin[8], 0.395832, 1.600000);
	TextDrawTextSize(textDrawLogin[8], 19.500000, 100.500000);
	TextDrawSetOutline(textDrawLogin[8], 0);
	TextDrawSetShadow(textDrawLogin[8], 0);
	TextDrawAlignment(textDrawLogin[8], 2);
	TextDrawColor(textDrawLogin[8], -1);
	TextDrawBackgroundColor(textDrawLogin[8], 255);
	TextDrawBoxColor(textDrawLogin[8], 1296911706);
	TextDrawUseBox(textDrawLogin[8], true);
	TextDrawSetProportional(textDrawLogin[8], true);
	TextDrawSetSelectable(textDrawLogin[8], true);
    return 1;
}

hook CallLocalFunction()
{
	DestroyLoginScreen();
}
