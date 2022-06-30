#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Text:dateTextDraw;
static Text:hourTextDraw;

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowTimeScreen(playerid)
{
    TextDrawShowForPlayer(playerid, dateTextDraw);
    TextDrawShowForPlayer(playerid, hourTextDraw);
	return 1;
}

stock HideTimeScreen(playerid)
{
    TextDrawHideForPlayer(playerid, dateTextDraw);
    TextDrawHideForPlayer(playerid, hourTextDraw);
	return 1;
}

stock UpdateDateScreen(const string[])
{
   	TextDrawSetString(dateTextDraw, string);
}

stock UpdateClockScreen(const string[])
{
    TextDrawSetString(hourTextDraw, string);
}

stock DestroyTimeScreen()
{
    TextDrawDestroy(dateTextDraw);
    TextDrawDestroy(hourTextDraw);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    dateTextDraw = TextDrawCreate(496.000000, 6.000000, "--");
    TextDrawBackgroundColor(dateTextDraw, 255);
    TextDrawFont(dateTextDraw, 3);
    TextDrawLetterSize(dateTextDraw, 0.399999,2.000000);
    TextDrawColor(dateTextDraw, 0xFFFFFFFF);
    TextDrawSetOutline(dateTextDraw, 1);
    TextDrawSetProportional(dateTextDraw, true);

    hourTextDraw = TextDrawCreate(551.000000, 23.000000, "--");
    TextDrawBackgroundColor(hourTextDraw, 255); // backup: 0x000752FF
    TextDrawFont(hourTextDraw, 3);
    TextDrawLetterSize(hourTextDraw, 0.399999,2.000000);
    TextDrawColor(hourTextDraw, 0xFFFFFFFF);
    TextDrawSetOutline(hourTextDraw, 1);
    TextDrawSetProportional(hourTextDraw, true);
    return 1;
}

hook OnGameModeExit()
{
	DestroyTimeScreen();
	return 1;
}
