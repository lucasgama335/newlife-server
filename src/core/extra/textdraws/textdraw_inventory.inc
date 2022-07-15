#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define TEXTDRAW_ARRAY_SIZE     42
//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsInventoryTextdraw[MAX_PLAYERS][TEXTDRAW_ARRAY_SIZE];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
stock Inventory_CreateInfoBox(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {   
        gsInventoryTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 232.000000, 97.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][0], 0.600000, 19.700080);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][0], 298.500000, 76.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][0], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][0], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][0], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][0], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][0], 225);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][0], 0);

        gsInventoryTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 221.000000, 96.000000, "MOCHILA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][1], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][1], 0.200000, 1.149999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][1], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][1], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][1], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][1], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][1], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][1], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][1], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][1], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][1], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][1], 0);

        gsInventoryTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 195.000000, 109.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][2], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][2], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][2], 74.000000, 99.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][2], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][2], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][2], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][2], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][2], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][2], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][2], 1, 1);

        gsInventoryTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 189.000000, 255.000000, "I");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][3], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][3], 14.183364, -0.149995);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][3], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][3], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][3], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][3], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][3], 1296911871);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][3], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][3], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][3], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][3], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][3], 0);

        gsInventoryTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 193.000000, 216.000000, "ITEM: BARRA DE CHOCOLATE");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][4], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][4], 0.137500, 0.849999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][4], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][4], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][4], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][4], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][4], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][4], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][4], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][4], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][4], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][4], 0);

        gsInventoryTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 193.000000, 226.000000, "QUANTIDADE: 20");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][5], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][5], 0.136996, 0.849999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][5], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][5], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][5], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][5], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][5], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][5], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][5], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][5], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][5], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][5], 0);

        gsInventoryTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 193.000000, 237.000000, "RARIDADE: DESCONHECIDA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][6], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][6], 0.136996, 0.849999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][6], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][6], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][6], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][6], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][6], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][6], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][6], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][6], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][6], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][6], 0);

        gsInventoryTextdraw[playerid][7] = CreatePlayerTextDraw(playerid, 189.000000, 213.000000, "I");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][7], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][7], 14.183364, -0.149995);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][7], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][7], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][7], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][7], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][7], 1296911871);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][7], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][7], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][7], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][7], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][7], 0);

        gsInventoryTextdraw[playerid][8] = CreatePlayerTextDraw(playerid, 212.500000, 262.000000, "ORGANIZAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][8], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][8], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][8], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][8], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][8], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][8], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][8], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][8], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][8], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][8], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][8], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][8], 1);

        gsInventoryTextdraw[playerid][9] = CreatePlayerTextDraw(playerid, 252.500000, 262.000000, "RESETAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][9], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][9], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][9], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][9], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][9], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][9], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][9], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][9], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][9], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][9], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][9], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][9], 1);
    }
    else
    {
        gsInventoryTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 197.000000, 96.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][0], 0.600000, 24.750003);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][0], 298.500000, 95.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][0], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][0], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][0], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][0], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][0], 225);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][0], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][0], 0);

        gsInventoryTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 180.000000, 102.000000, "MOCHILA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][1], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][1], 0.295832, 0.949998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][1], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][1], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][1], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][1], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][1], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][1], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][1], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][1], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][1], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][1], 0);

        gsInventoryTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 161.000000, 120.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][2], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][2], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][2], 74.000000, 99.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][2], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][2], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][2], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][2], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][2], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][2], 0);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][2], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][2], 1, 1);

        gsInventoryTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 107.000000, 290.000000, "I");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][3], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][3], 14.183362, -0.149994);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][3], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][3], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][3], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][3], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][3], 1296911871);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][3], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][3], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][3], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][3], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][3], 0);

        gsInventoryTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 152.000000, 231.000000, "ITEM: BARRA DE CHOCOLATE");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][4], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][4], 0.195831, 1.099997);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][4], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][4], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][4], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][4], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][4], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][4], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][4], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][4], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][4], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][4], 0);

        gsInventoryTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 152.000000, 250.000000, "QUANTIDADE: 20");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][5], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][5], 0.195555, 1.099997);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][5], 400.000000, 1.099997);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][5], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][5], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][5], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][5], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][5], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][5], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][5], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][5], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][5], 0);

        gsInventoryTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 152.000000, 270.000000, "RARIDADE: DESCONHECIDA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][6], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][6], 0.195555, 1.099997);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][6], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][6], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][6], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][6], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][6], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][6], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][6], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][6], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][6], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][6], 0);

        gsInventoryTextdraw[playerid][7] = CreatePlayerTextDraw(playerid, 107.000000, 226.000000, "I");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][7], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][7], 14.183362, -0.149994);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][7], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][7], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][7], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][7], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][7], 1296911871);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][7], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][7], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][7], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][7], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][7], 0);

        gsInventoryTextdraw[playerid][8] = CreatePlayerTextDraw(playerid, 173.500000, 303.000000, "ORGANIZAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][8], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][8], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][8], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][8], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][8], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][8], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][8], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][8], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][8], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][8], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][8], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][8], 1);

        gsInventoryTextdraw[playerid][9] = CreatePlayerTextDraw(playerid, 221.500000, 303.000000, "RESETAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][9], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][9], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][9], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][9], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][9], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][9], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][9], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][9], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][9], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][9], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][9], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][9], 1);
    }
    return 1;
}

stock Inventory_CreateItemsBox(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsInventoryTextdraw[playerid][10] = CreatePlayerTextDraw(playerid, 365.500000, 97.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][10], 0.600000, 27.999977);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][10], 298.500000, 179.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][10], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][10], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][10], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][10], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][10], 225);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][10], 0);

        gsInventoryTextdraw[playerid][11] = CreatePlayerTextDraw(playerid, 276.000000, 110.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][11], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][11], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][11], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][11], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][11], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][11], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][11], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][11], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][11], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][11], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][11], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][11], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][11], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][11], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][11], 1, 1);

        gsInventoryTextdraw[playerid][12] = CreatePlayerTextDraw(playerid, 312.000000, 110.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][12], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][12], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][12], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][12], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][12], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][12], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][12], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][12], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][12], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][12], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][12], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][12], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][12], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][12], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][12], 1, 1);

        gsInventoryTextdraw[playerid][13] = CreatePlayerTextDraw(playerid, 348.000000, 110.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][13], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][13], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][13], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][13], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][13], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][13], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][13], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][13], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][13], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][13], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][13], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][13], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][13], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][13], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][13], 1, 1);

        gsInventoryTextdraw[playerid][14] = CreatePlayerTextDraw(playerid, 384.000000, 110.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][14], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][14], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][14], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][14], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][14], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][14], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][14], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][14], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][14], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][14], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][14], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][14], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][14], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][14], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][14], 1, 1);

        gsInventoryTextdraw[playerid][15] = CreatePlayerTextDraw(playerid, 420.000000, 110.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][15], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][15], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][15], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][15], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][15], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][15], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][15], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][15], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][15], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][15], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][15], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][15], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][15], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][15], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][15], 1, 1);

        gsInventoryTextdraw[playerid][16] = CreatePlayerTextDraw(playerid, 276.000000, 165.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][16], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][16], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][16], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][16], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][16], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][16], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][16], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][16], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][16], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][16], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][16], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][16], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][16], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][16], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][16], 1, 1);

        gsInventoryTextdraw[playerid][17] = CreatePlayerTextDraw(playerid, 312.000000, 165.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][17], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][17], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][17], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][17], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][17], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][17], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][17], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][17], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][17], 1296911871);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][17], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][17], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][17], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][17], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][17], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][17], 1, 1);

        gsInventoryTextdraw[playerid][18] = CreatePlayerTextDraw(playerid, 348.000000, 165.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][18], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][18], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][18], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][18], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][18], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][18], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][18], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][18], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][18], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][18], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][18], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][18], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][18], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][18], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][18], 1, 1);

        gsInventoryTextdraw[playerid][19] = CreatePlayerTextDraw(playerid, 384.000000, 165.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][19], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][19], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][19], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][19], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][19], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][19], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][19], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][19], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][19], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][19], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][19], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][19], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][19], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][19], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][19], 1, 1);

        gsInventoryTextdraw[playerid][20] = CreatePlayerTextDraw(playerid, 420.000000, 165.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][20], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][20], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][20], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][20], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][20], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][20], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][20], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][20], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][20], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][20], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][20], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][20], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][20], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][20], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][20], 1, 1);

        gsInventoryTextdraw[playerid][21] = CreatePlayerTextDraw(playerid, 276.000000, 220.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][21], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][21], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][21], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][21], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][21], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][21], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][21], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][21], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][21], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][21], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][21], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][21], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][21], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][21], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][21], 1, 1);

        gsInventoryTextdraw[playerid][22] = CreatePlayerTextDraw(playerid, 312.000000, 220.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][22], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][22], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][22], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][22], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][22], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][22], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][22], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][22], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][22], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][22], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][22], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][22], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][22], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][22], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][22], 1, 1);

        gsInventoryTextdraw[playerid][23] = CreatePlayerTextDraw(playerid, 348.000000, 220.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][23], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][23], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][23], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][23], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][23], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][23], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][23], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][23], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][23], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][23], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][23], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][23], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][23], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][23], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][23], 1, 1);

        gsInventoryTextdraw[playerid][24] = CreatePlayerTextDraw(playerid, 384.000000, 220.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][24], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][24], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][24], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][24], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][24], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][24], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][24], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][24], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][24], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][24], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][24], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][24], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][24], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][24], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][24], 1, 1);

        gsInventoryTextdraw[playerid][25] = CreatePlayerTextDraw(playerid, 420.000000, 220.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][25], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][25], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][25], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][25], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][25], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][25], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][25], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][25], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][25], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][25], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][25], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][25], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][25], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][25], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][25], 1, 1);

        gsInventoryTextdraw[playerid][26] = CreatePlayerTextDraw(playerid, 276.000000, 275.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][26], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][26], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][26], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][26], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][26], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][26], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][26], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][26], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][26], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][26], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][26], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][26], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][26], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][26], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][26], 1, 1);

        gsInventoryTextdraw[playerid][27] = CreatePlayerTextDraw(playerid, 312.000000, 275.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][27], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][27], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][27], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][27], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][27], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][27], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][27], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][27], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][27], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][27], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][27], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][27], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][27], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][27], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][27], 1, 1);

        gsInventoryTextdraw[playerid][28] = CreatePlayerTextDraw(playerid, 348.000000, 275.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][28], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][28], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][28], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][28], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][28], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][28], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][28], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][28], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][28], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][28], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][28], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][28], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][28], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][28], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][28], 1, 1);

        gsInventoryTextdraw[playerid][29] = CreatePlayerTextDraw(playerid, 384.000000, 275.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][29], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][29], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][29], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][29], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][29], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][29], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][29], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][29], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][29], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][29], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][29], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][29], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][29], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][29], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][29], 1, 1);

        gsInventoryTextdraw[playerid][30] = CreatePlayerTextDraw(playerid, 420.000000, 275.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][30], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][30], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][30], 35.000000, 54.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][30], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][30], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][30], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][30], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][30], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][30], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][30], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][30], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][30], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][30], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][30], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][30], 1, 1);

        gsInventoryTextdraw[playerid][31] = CreatePlayerTextDraw(playerid, 277.000000, 338.000000, "ITEMS: 30/80");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][31], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][31], 0.183329, 1.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][31], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][31], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][31], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][31], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][31], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][31], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][31], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][31], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][31], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][31], 0);

        gsInventoryTextdraw[playerid][32] = CreatePlayerTextDraw(playerid, 357.000000, 337.000000, "<<");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][32], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][32], 0.129166, 0.949998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][32], 16.500000, 9.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][32], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][32], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][32], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][32], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][32], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][32], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][32], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][32], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][32], 1);

        gsInventoryTextdraw[playerid][33] = CreatePlayerTextDraw(playerid, 375.000000, 337.000000, ">>");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][33], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][33], 0.129166, 0.949998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][33], 16.500000, 9.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][33], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][33], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][33], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][33], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][33], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][33], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][33], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][33], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][33], 1);

        gsInventoryTextdraw[playerid][34] = CreatePlayerTextDraw(playerid, 455.000000, 338.000000, "PAGINA: 1/4");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][34], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][34], 0.183329, 1.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][34], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][34], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][34], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][34], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][34], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][34], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][34], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][34], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][34], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][34], 0);
    }
    else
    {
        gsInventoryTextdraw[playerid][10] = CreatePlayerTextDraw(playerid, 394.500000, 96.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][10], 0.600000, 34.099884);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][10], 298.500000, 290.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][10], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][10], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][10], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][10], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][10], 225);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][10], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][10], 0);

        gsInventoryTextdraw[playerid][11] = CreatePlayerTextDraw(playerid, 252.000000, 113.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][11], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][11], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][11], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][11], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][11], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][11], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][11], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][11], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][11], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][11], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][11], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][11], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][11], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][11], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][11], 1, 1);

        gsInventoryTextdraw[playerid][12] = CreatePlayerTextDraw(playerid, 309.000000, 113.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][12], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][12], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][12], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][12], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][12], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][12], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][12], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][12], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][12], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][12], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][12], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][12], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][12], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][12], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][12], 1, 1);

        gsInventoryTextdraw[playerid][13] = CreatePlayerTextDraw(playerid, 366.000000, 113.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][13], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][13], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][13], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][13], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][13], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][13], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][13], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][13], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][13], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][13], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][13], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][13], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][13], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][13], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][13], 1, 1);

        gsInventoryTextdraw[playerid][14] = CreatePlayerTextDraw(playerid, 423.000000, 113.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][14], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][14], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][14], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][14], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][14], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][14], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][14], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][14], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][14], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][14], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][14], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][14], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][14], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][14], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][14], 1, 1);

        gsInventoryTextdraw[playerid][15] = CreatePlayerTextDraw(playerid, 480.000000, 113.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][15], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][15], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][15], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][15], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][15], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][15], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][15], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][15], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][15], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][15], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][15], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][15], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][15], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][15], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][15], 1, 1);

        gsInventoryTextdraw[playerid][16] = CreatePlayerTextDraw(playerid, 252.000000, 180.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][16], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][16], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][16], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][16], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][16], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][16], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][16], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][16], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][16], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][16], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][16], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][16], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][16], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][16], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][16], 1, 1);

        gsInventoryTextdraw[playerid][17] = CreatePlayerTextDraw(playerid, 309.000000, 180.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][17], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][17], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][17], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][17], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][17], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][17], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][17], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][17], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][17], 1296911871);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][17], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][17], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][17], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][17], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][17], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][17], 1, 1);

        gsInventoryTextdraw[playerid][18] = CreatePlayerTextDraw(playerid, 366.000000, 180.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][18], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][18], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][18], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][18], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][18], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][18], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][18], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][18], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][18], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][18], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][18], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][18], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][18], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][18], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][18], 1, 1);

        gsInventoryTextdraw[playerid][19] = CreatePlayerTextDraw(playerid, 423.000000, 180.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][19], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][19], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][19], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][19], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][19], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][19], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][19], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][19], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][19], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][19], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][19], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][19], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][19], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][19], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][19], 1, 1);

        gsInventoryTextdraw[playerid][20] = CreatePlayerTextDraw(playerid, 480.000000, 180.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][20], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][20], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][20], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][20], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][20], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][20], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][20], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][20], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][20], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][20], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][20], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][20], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][20], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][20], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][20], 1, 1);

        gsInventoryTextdraw[playerid][21] = CreatePlayerTextDraw(playerid, 252.000000, 247.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][21], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][21], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][21], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][21], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][21], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][21], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][21], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][21], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][21], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][21], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][21], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][21], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][21], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][21], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][21], 1, 1);

        gsInventoryTextdraw[playerid][22] = CreatePlayerTextDraw(playerid, 309.000000, 247.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][22], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][22], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][22], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][22], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][22], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][22], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][22], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][22], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][22], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][22], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][22], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][22], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][22], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][22], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][22], 1, 1);

        gsInventoryTextdraw[playerid][23] = CreatePlayerTextDraw(playerid, 366.000000, 247.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][23], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][23], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][23], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][23], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][23], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][23], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][23], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][23], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][23], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][23], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][23], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][23], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][23], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][23], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][23], 1, 1);

        gsInventoryTextdraw[playerid][24] = CreatePlayerTextDraw(playerid, 423.000000, 247.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][24], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][24], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][24], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][24], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][24], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][24], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][24], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][24], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][24], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][24], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][24], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][24], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][24], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][24], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][24], 1, 1);

        gsInventoryTextdraw[playerid][25] = CreatePlayerTextDraw(playerid, 480.000000, 247.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][25], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][25], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][25], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][25], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][25], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][25], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][25], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][25], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][25], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][25], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][25], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][25], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][25], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][25], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][25], 1, 1);

        gsInventoryTextdraw[playerid][26] = CreatePlayerTextDraw(playerid, 252.000000, 314.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][26], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][26], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][26], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][26], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][26], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][26], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][26], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][26], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][26], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][26], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][26], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][26], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][26], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][26], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][26], 1, 1);

        gsInventoryTextdraw[playerid][27] = CreatePlayerTextDraw(playerid, 309.000000, 314.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][27], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][27], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][27], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][27], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][27], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][27], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][27], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][27], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][27], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][27], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][27], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][27], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][27], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][27], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][27], 1, 1);

        gsInventoryTextdraw[playerid][28] = CreatePlayerTextDraw(playerid, 366.000000, 314.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][28], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][28], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][28], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][28], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][28], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][28], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][28], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][28], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][28], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][28], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][28], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][28], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][28], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][28], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][28], 1, 1);

        gsInventoryTextdraw[playerid][29] = CreatePlayerTextDraw(playerid, 423.000000, 314.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][29], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][29], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][29], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][29], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][29], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][29], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][29], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][29], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][29], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][29], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][29], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][29], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][29], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][29], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][29], 1, 1);

        gsInventoryTextdraw[playerid][30] = CreatePlayerTextDraw(playerid, 480.000000, 314.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][30], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][30], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][30], 55.500000, 64.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][30], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][30], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][30], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][30], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][30], 1296911746);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][30], 255);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][30], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][30], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][30], 1);
        PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][30], 18631);
        PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][30], -10.000000, 0.000000, -8.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][30], 1, 1);

        gsInventoryTextdraw[playerid][31] = CreatePlayerTextDraw(playerid, 254.000000, 385.000000, "ITEMS: 30/80");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][31], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][31], 0.270828, 1.349998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][31], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][31], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][31], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][31], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][31], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][31], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][31], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][31], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][31], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][31], 0);

        gsInventoryTextdraw[playerid][32] = CreatePlayerTextDraw(playerid, 378.000000, 385.000000, "<<");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][32], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][32], 0.245000, 1.349998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][32], 16.500000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][32], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][32], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][32], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][32], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][32], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][32], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][32], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][32], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][32], 1);

        gsInventoryTextdraw[playerid][33] = CreatePlayerTextDraw(playerid, 410.000000, 385.000000, ">>");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][33], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][33], 0.245831, 1.349997);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][33], 16.500000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][33], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][33], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][33], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][33], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][33], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][33], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][33], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][33], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][33], 1);

        gsInventoryTextdraw[playerid][34] = CreatePlayerTextDraw(playerid, 536.000000, 385.000000, "PAGINA: 1/4");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][34], 3);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][34], 0.270000, 1.350000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][34], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][34], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][34], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][34], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][34], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][34], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][34], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][34], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][34], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][34], 0);
    }
    return 1;
}

stock Inventory_CreateItemOptions(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsInventoryTextdraw[playerid][35] = CreatePlayerTextDraw(playerid, 232.000000, 283.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][35], 0.600000, 7.300070);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][35], 298.500000, 76.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][35], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][35], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][35], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][35], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][35], 225);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][35], 0);

        gsInventoryTextdraw[playerid][36] = CreatePlayerTextDraw(playerid, 212.000000, 289.000000, "USAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][36], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][36], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][36], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][36], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][36], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][36], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][36], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][36], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][36], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][36], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][36], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][36], 1);

        gsInventoryTextdraw[playerid][37] = CreatePlayerTextDraw(playerid, 252.000000, 289.000000, "DESCARTAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][37], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][37], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][37], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][37], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][37], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][37], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][37], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][37], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][37], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][37], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][37], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][37], 1);

        gsInventoryTextdraw[playerid][38] = CreatePlayerTextDraw(playerid, 212.000000, 312.000000, "JUNTAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][38], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][38], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][38], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][38], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][38], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][38], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][38], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][38], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][38], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][38], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][38], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][38], 1);

        gsInventoryTextdraw[playerid][39] = CreatePlayerTextDraw(playerid, 252.000000, 312.000000, "SEPARAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][39], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][39], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][39], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][39], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][39], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][39], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][39], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][39], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][39], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][39], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][39], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][39], 1);

        gsInventoryTextdraw[playerid][40] = CreatePlayerTextDraw(playerid, 231.500000, 337.000000, "NEGOCIAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][40], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][40], 16.500000, 72.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][40], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][40], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][40], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][40], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][40], 1);
    }
    else
    {
        gsInventoryTextdraw[playerid][35] = CreatePlayerTextDraw(playerid, 197.000000, 324.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][35], 0.600000, 8.750072);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][35], 298.500000, 95.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][35], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][35], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][35], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][35], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][35], 225);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][35], 0);

        gsInventoryTextdraw[playerid][36] = CreatePlayerTextDraw(playerid, 173.000000, 336.000000, "USAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][36], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][36], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][36], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][36], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][36], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][36], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][36], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][36], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][36], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][36], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][36], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][36], 1);

        gsInventoryTextdraw[playerid][37] = CreatePlayerTextDraw(playerid, 221.000000, 336.000000, "DESCARTAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][37], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][37], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][37], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][37], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][37], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][37], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][37], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][37], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][37], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][37], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][37], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][37], 1);

        gsInventoryTextdraw[playerid][38] = CreatePlayerTextDraw(playerid, 173.000000, 362.000000, "JUNTAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][38], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][38], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][38], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][38], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][38], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][38], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][38], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][38], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][38], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][38], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][38], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][38], 1);

        gsInventoryTextdraw[playerid][39] = CreatePlayerTextDraw(playerid, 221.000000, 362.000000, "SEPARAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][39], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][39], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][39], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][39], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][39], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][39], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][39], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][39], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][39], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][39], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][39], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][39], 1);

        gsInventoryTextdraw[playerid][40] = CreatePlayerTextDraw(playerid, 196.500000, 389.000000, "NEGOCIAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][40], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][40], 16.500000, 91.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][40], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][40], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][40], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][40], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][40], 1);
    }
    return 1;
}

stock Inventory_CreateCloseButton(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsInventoryTextdraw[playerid][41] = CreatePlayerTextDraw(playerid, 453.000000, 97.000000, "X");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][41], 0.137499, 0.850000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][41], 16.500000, 5.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][41], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][41], -16776961);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][41], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][41], 0);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][41], 1);
    }
    else
    {
        gsInventoryTextdraw[playerid][41] = CreatePlayerTextDraw(playerid, 528.000000, 95.000000, "X");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][41], 0.270832, 1.449998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][41], 16.500000, 10.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][41], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][41], -16776961);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][41], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][41], 0);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][41], 1);
    }
    return 1;
}

static stock Inventory_CreateTextdraw(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    Inventory_CreateInfoBox(playerid, screenType);
    Inventory_CreateItemsBox(playerid, screenType);
    Inventory_CreateItemOptions(playerid, screenType);
    Inventory_CreateCloseButton(playerid, screenType);
    return 1;
}


//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Inventory_Show(playerid)
{
    for (new i; i < TEXTDRAW_ARRAY_SIZE; i++)
    {
        // Show all textdraws, except item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    Inventory_HideItemOptions(playerid);
    SelectTextDraw(playerid, COLOR_ORANGE);
    return 1;
}

stock Inventory_AdaptToScreen(playerid)
{
    Inventory_Hide(playerid);
    Inventory_Destroy(playerid);
    switch (Player_GetScreenSize(playerid))
    {
        case SCREEN_ULTRAWIDE:
        {
            Inventory_CreateTextdraw(playerid, SCREEN_ULTRAWIDE);
        }
        default:
        {
            Inventory_CreateTextdraw(playerid, SCREEN_NORMAL);
        }
    }
    return 1;
}

stock Inventory_ShowItemOptions(playerid)
{
    for (new i = 35; i < 41; i++)
    {
        // Show item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock Inventory_HideItemOptions(playerid)
{
    for (new i = 35; i < 41; i++)
    {
        // Hide item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock Inventory_Hide(playerid)
{
    for (new i; i < TEXTDRAW_ARRAY_SIZE; i++)
    {
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock Inventory_Destroy(playerid)
{
    for (new i; i < TEXTDRAW_ARRAY_SIZE; i++)
    {
        // Show item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawDestroy(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock PlayerText:Inventory_GetTextdraw(playerid, index)
{
    if (index < 0 || index > 41)
    {
        return gsInventoryTextdraw[playerid][0];
    }
    return gsInventoryTextdraw[playerid][index];
}

stock Inventory_GetTextdrawIndex(playerid, PlayerText:txtId)
{
    for (new i; i < TEXTDRAW_ARRAY_SIZE; i++)
    {
        // Show item options
        if (gsInventoryTextdraw[playerid][i] == txtId)
        {
            return i;
        }
    }
    return INVALID_VALUE;
}

stock Inventory_UpdateBoxInfo(playerid)
{
    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][2]);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], GetPlayerSkin(playerid));
    PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][2]);
    
    new txtString[(31 + MAX_MONEY_STRING)], formatMoney[MAX_MONEY_STRING];
    format(txtString, sizeof(txtString), "NOME: %s", GetPlayerNameCustom(playerid));
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][4], txtString);

    FormatMoneyString(Player_GetMoney(playerid), formatMoney);
    format(txtString, sizeof(txtString), "DINHEIRO: %s", formatMoney);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][5], txtString);

    FormatMoneyString(Player_GetCoins(playerid), formatMoney);
    format(txtString, sizeof(txtString), "MOEDAS VIP: %s", formatMoney);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][6], txtString);
    return 1;
}

stock Inventory_UpdateItemPreview(playerid, index, itemId, bool:reDrawing = false)
{
    if (index < 11 || index > 30)
    {
        return 0;
    }
    if (reDrawing)
    {
       PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][index]); 
    }
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][index], itemId);
    if (reDrawing)
    {
       PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][index]); 
    }
    return 1;
}

stock Inventory_ChangeItemBoxColor(playerid, index, color)
{
    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][index]);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][index], color);
    PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][index]);
    return 1;
}

stock Inventory_UpdateBoxInfoItem(playerid, invSlot, itemId, const name[], quantity, const rarity[])
{
    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][2]);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], itemId);
    PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][2]);

    new txtString[(31 + MAX_MONEY_STRING)], formatMoney[MAX_MONEY_STRING];
    format(txtString, sizeof(txtString), "ITEM[%d]: %s", invSlot, name);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][4], txtString);

    FormatMoneyString(Player_GetMoney(playerid), formatMoney);
    format(txtString, sizeof(txtString), "QUANTIDADE: %d", quantity);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][5], txtString);

    format(txtString, sizeof(txtString), "RARIDADE: %s", rarity);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][6], txtString);
    return 1;
}

stock Inventory_UpdatePageText(playerid, page, maxPages)
{
    new txtString[15];
    format(txtString, sizeof(txtString), "PAGINA: %d/%d", page, maxPages);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][34], txtString);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    Inventory_CreateTextdraw(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Inventory_Hide(playerid);
    Inventory_Destroy(playerid);
	return 1;
}