#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Text:gsDateTextdraw;
static Text:gsClockTextdraw;

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowTimeScreen(playerid)
{
    TextDrawShowForPlayer(playerid, gsDateTextdraw);
    TextDrawShowForPlayer(playerid, gsClockTextdraw);
	return 1;
}

stock HideTimeScreen(playerid)
{
    TextDrawHideForPlayer(playerid, gsDateTextdraw);
    TextDrawHideForPlayer(playerid, gsClockTextdraw);
	return 1;
}

stock DestroyTimeScreen()
{
    TextDrawDestroy(gsDateTextdraw);
    TextDrawDestroy(gsClockTextdraw);
	return 1;
}

stock UpdateDateScreen(const string[])
{
   	TextDrawSetString(gsDateTextdraw, string);
}

stock UpdateClockScreen(const string[])
{
    TextDrawSetString(gsClockTextdraw, string);
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsDateTextdraw = TextDrawCreate(496.000000, 6.000000, "--");
    TextDrawBackgroundColor(gsDateTextdraw, 255);
    TextDrawFont(gsDateTextdraw, 3);
    TextDrawLetterSize(gsDateTextdraw, 0.399999,2.000000);
    TextDrawColor(gsDateTextdraw, 0xFFFFFFFF);
    TextDrawSetOutline(gsDateTextdraw, 1);
    TextDrawSetProportional(gsDateTextdraw, true);

    gsClockTextdraw = TextDrawCreate(551.000000, 23.000000, "--");
    TextDrawBackgroundColor(gsClockTextdraw, 255); // backup: 0x000752FF
    TextDrawFont(gsClockTextdraw, 3);
    TextDrawLetterSize(gsClockTextdraw, 0.399999,2.000000);
    TextDrawColor(gsClockTextdraw, 0xFFFFFFFF);
    TextDrawSetOutline(gsClockTextdraw, 1);
    TextDrawSetProportional(gsClockTextdraw, true);
    return 1;
}

hook OnGameModeExit()
{
	DestroyTimeScreen();
	return 1;
}
