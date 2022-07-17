#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define TEXTDRAW_ARRAY_SIZE     67
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

        gsInventoryTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 193.000000, 229.000000, "QUANTIDADE: 20");
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

        gsInventoryTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 193.000000, 243.000000, "RARIDADE: DESCONHECIDA");
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

        gsInventoryTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 151.000000, 120.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][2], 5);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][2], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][2], 91.500000, 101.500000);
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
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][35], 0.600000, 7.300068);
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

        gsInventoryTextdraw[playerid][38] = CreatePlayerTextDraw(playerid, 212.000000, 313.000000, "JUNTAR");
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

        gsInventoryTextdraw[playerid][39] = CreatePlayerTextDraw(playerid, 252.000000, 313.000000, "SEPARAR");
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

        gsInventoryTextdraw[playerid][40] = CreatePlayerTextDraw(playerid, 212.000000, 337.000000, "NEGOCIAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][40], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][40], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][40], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][40], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][40], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][40], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][40], 1);

        gsInventoryTextdraw[playerid][41] = CreatePlayerTextDraw(playerid, 252.000000, 337.000000, "MOVER");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][41], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][41], 16.500000, 33.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][41], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][41], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][41], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][41], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][41], 1);
    }
    else
    {
        gsInventoryTextdraw[playerid][35] = CreatePlayerTextDraw(playerid, 197.000000, 324.000000, "_");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][35], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][35], 0.600000, 8.750071);
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

        gsInventoryTextdraw[playerid][40] = CreatePlayerTextDraw(playerid, 173.000000, 388.000000, "NEGOCIAR");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][40], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][40], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][40], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][40], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][40], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][40], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][40], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][40], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][40], 1);

        gsInventoryTextdraw[playerid][41] = CreatePlayerTextDraw(playerid, 221.000000, 388.000000, "MOVER");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][41], 0.108332, 0.800000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][41], 16.500000, 42.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][41], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][41], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][41], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][41], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][41], 1296911816);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][41], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][41], 1);
    }
    return 1;
}

stock Inventory_CreateCloseButton(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsInventoryTextdraw[playerid][42] = CreatePlayerTextDraw(playerid, 453.000000, 97.000000, "X");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][42], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][42], 0.137499, 0.850000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][42], 16.500000, 5.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][42], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][42], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][42], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][42], -16776961);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][42], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][42], 0);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][42], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][42], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][42], 1);
    }
    else
    {
        gsInventoryTextdraw[playerid][42] = CreatePlayerTextDraw(playerid, 528.000000, 95.000000, "X");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][42], 2);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][42], 0.270832, 1.449998);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][42], 16.500000, 10.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][42], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][42], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][42], 2);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][42], -16776961);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][42], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][42], 0);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][42], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][42], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][42], 1);
    }
    return 1;
}

static stock Inventory_CreatePreviewOptions(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsInventoryTextdraw[playerid][43] = CreatePlayerTextDraw(playerid, 196.000000, 122.000000, "ld_beat:up");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][43], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][43], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][43], 7.500000, 10.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][43], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][43], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][43], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][43], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][43], 1);

        gsInventoryTextdraw[playerid][44] = CreatePlayerTextDraw(playerid, 196.000000, 145.000000, "ld_beat:down");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][44], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][44], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][44], 7.500000, 10.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][44], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][44], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][44], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][44], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][44], 1);

        gsInventoryTextdraw[playerid][45] = CreatePlayerTextDraw(playerid, 196.000000, 167.000000, "ld_beat:right");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][45], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][45], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][45], 7.500000, 10.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][45], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][45], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][45], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][45], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][45], 1);

        gsInventoryTextdraw[playerid][46] = CreatePlayerTextDraw(playerid, 196.000000, 187.000000, "ld_beat:left");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][46], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][46], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][46], 7.500000, 10.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][46], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][46], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][46], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][46], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][46], 1);
    }
    else
    {
        gsInventoryTextdraw[playerid][43] = CreatePlayerTextDraw(playerid, 153.000000, 129.000000, "ld_beat:up");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][43], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][43], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][43], 11.000000, 12.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][43], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][43], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][43], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][43], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][43], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][43], 1);

        gsInventoryTextdraw[playerid][44] = CreatePlayerTextDraw(playerid, 153.000000, 153.000000, "ld_beat:down");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][44], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][44], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][44], 11.000000, 12.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][44], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][44], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][44], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][44], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][44], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][44], 1);

        gsInventoryTextdraw[playerid][45] = CreatePlayerTextDraw(playerid, 153.000000, 178.000000, "ld_beat:right");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][45], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][45], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][45], 11.000000, 12.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][45], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][45], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][45], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][45], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][45], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][45], 1);

        gsInventoryTextdraw[playerid][46] = CreatePlayerTextDraw(playerid, 153.000000, 201.000000, "ld_beat:left");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][46], 4);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][46], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][46], 11.000000, 12.500000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][46], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][46], -106);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][46], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][46], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][46], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][46], 1);
    }
    return 1;
}

static stock Inventory_CreatePreviewDesc(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsInventoryTextdraw[playerid][47] = CreatePlayerTextDraw(playerid, 310.000000, 158.000000, "CAIXINHA PLATINA (~b~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][47], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][47], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][47], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][47], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][47], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][47], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][47], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][47], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][47], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][47], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][47], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][47], 0);

        gsInventoryTextdraw[playerid][48] = CreatePlayerTextDraw(playerid, 346.000000, 158.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][48], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][48], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][48], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][48], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][48], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][48], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][48], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][48], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][48], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][48], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][48], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][48], 0);

        gsInventoryTextdraw[playerid][49] = CreatePlayerTextDraw(playerid, 382.000000, 158.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][49], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][49], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][49], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][49], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][49], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][49], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][49], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][49], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][49], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][49], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][49], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][49], 0);

        gsInventoryTextdraw[playerid][50] = CreatePlayerTextDraw(playerid, 418.000000, 158.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][50], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][50], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][50], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][50], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][50], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][50], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][50], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][50], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][50], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][50], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][50], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][50], 0);

        gsInventoryTextdraw[playerid][51] = CreatePlayerTextDraw(playerid, 454.000000, 158.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][51], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][51], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][51], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][51], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][51], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][51], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][51], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][51], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][51], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][51], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][51], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][51], 0);

        gsInventoryTextdraw[playerid][52] = CreatePlayerTextDraw(playerid, 310.000000, 213.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][52], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][52], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][52], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][52], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][52], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][52], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][52], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][52], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][52], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][52], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][52], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][52], 0);

        gsInventoryTextdraw[playerid][53] = CreatePlayerTextDraw(playerid, 346.000000, 213.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][53], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][53], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][53], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][53], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][53], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][53], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][53], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][53], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][53], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][53], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][53], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][53], 0);

        gsInventoryTextdraw[playerid][54] = CreatePlayerTextDraw(playerid, 382.000000, 213.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][54], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][54], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][54], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][54], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][54], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][54], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][54], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][54], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][54], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][54], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][54], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][54], 0);

        gsInventoryTextdraw[playerid][55] = CreatePlayerTextDraw(playerid, 418.000000, 213.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][55], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][55], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][55], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][55], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][55], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][55], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][55], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][55], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][55], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][55], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][55], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][55], 0);

        gsInventoryTextdraw[playerid][56] = CreatePlayerTextDraw(playerid, 454.000000, 213.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][56], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][56], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][56], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][56], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][56], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][56], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][56], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][56], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][56], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][56], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][56], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][56], 0);

        gsInventoryTextdraw[playerid][57] = CreatePlayerTextDraw(playerid, 310.000000, 268.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][57], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][57], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][57], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][57], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][57], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][57], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][57], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][57], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][57], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][57], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][57], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][57], 0);

        gsInventoryTextdraw[playerid][58] = CreatePlayerTextDraw(playerid, 346.000000, 268.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][58], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][58], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][58], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][58], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][58], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][58], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][58], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][58], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][58], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][58], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][58], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][58], 0);

        gsInventoryTextdraw[playerid][59] = CreatePlayerTextDraw(playerid, 382.000000, 268.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][59], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][59], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][59], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][59], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][59], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][59], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][59], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][59], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][59], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][59], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][59], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][59], 0);

        gsInventoryTextdraw[playerid][60] = CreatePlayerTextDraw(playerid, 418.000000, 268.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][60], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][60], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][60], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][60], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][60], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][60], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][60], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][60], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][60], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][60], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][60], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][60], 0);

        gsInventoryTextdraw[playerid][61] = CreatePlayerTextDraw(playerid, 454.000000, 268.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][61], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][61], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][61], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][61], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][61], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][61], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][61], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][61], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][61], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][61], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][61], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][61], 0);

        gsInventoryTextdraw[playerid][62] = CreatePlayerTextDraw(playerid, 310.000000, 323.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][62], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][62], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][62], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][62], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][62], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][62], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][62], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][62], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][62], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][62], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][62], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][62], 0);

        gsInventoryTextdraw[playerid][63] = CreatePlayerTextDraw(playerid, 346.000000, 323.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][63], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][63], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][63], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][63], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][63], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][63], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][63], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][63], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][63], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][63], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][63], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][63], 0);

        gsInventoryTextdraw[playerid][64] = CreatePlayerTextDraw(playerid, 382.000000, 323.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][64], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][64], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][64], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][64], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][64], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][64], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][64], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][64], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][64], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][64], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][64], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][64], 0);

        gsInventoryTextdraw[playerid][65] = CreatePlayerTextDraw(playerid, 418.000000, 323.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][65], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][65], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][65], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][65], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][65], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][65], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][65], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][65], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][65], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][65], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][65], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][65], 0);

        gsInventoryTextdraw[playerid][66] = CreatePlayerTextDraw(playerid, 454.000000, 323.000000, "CAIXINHA PLATINA");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][66], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][66], 0.079166, 0.500000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][66], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][66], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][66], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][66], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][66], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][66], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][66], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][66], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][66], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][66], 0);
    }
    else
    {
        gsInventoryTextdraw[playerid][47] = CreatePlayerTextDraw(playerid, 306.000000, 170.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][47], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][47], 0.112500, 0.700000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][47], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][47], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][47], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][47], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][47], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][47], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][47], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][47], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][47], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][47], 0);

        gsInventoryTextdraw[playerid][48] = CreatePlayerTextDraw(playerid, 362.000000, 170.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][48], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][48], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][48], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][48], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][48], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][48], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][48], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][48], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][48], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][48], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][48], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][48], 0);

        gsInventoryTextdraw[playerid][49] = CreatePlayerTextDraw(playerid, 419.000000, 170.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][49], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][49], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][49], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][49], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][49], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][49], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][49], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][49], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][49], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][49], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][49], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][49], 0);

        gsInventoryTextdraw[playerid][50] = CreatePlayerTextDraw(playerid, 477.000000, 170.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][50], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][50], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][50], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][50], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][50], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][50], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][50], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][50], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][50], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][50], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][50], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][50], 0);

        gsInventoryTextdraw[playerid][51] = CreatePlayerTextDraw(playerid, 533.000000, 170.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][51], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][51], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][51], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][51], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][51], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][51], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][51], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][51], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][51], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][51], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][51], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][51], 0);

        gsInventoryTextdraw[playerid][52] = CreatePlayerTextDraw(playerid, 306.000000, 236.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][52], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][52], 0.112500, 0.700000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][52], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][52], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][52], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][52], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][52], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][52], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][52], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][52], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][52], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][52], 0);

        gsInventoryTextdraw[playerid][53] = CreatePlayerTextDraw(playerid, 362.000000, 236.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][53], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][53], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][53], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][53], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][53], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][53], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][53], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][53], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][53], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][53], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][53], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][53], 0);

        gsInventoryTextdraw[playerid][54] = CreatePlayerTextDraw(playerid, 419.000000, 236.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][54], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][54], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][54], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][54], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][54], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][54], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][54], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][54], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][54], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][54], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][54], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][54], 0);

        gsInventoryTextdraw[playerid][55] = CreatePlayerTextDraw(playerid, 477.000000, 236.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][55], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][55], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][55], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][55], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][55], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][55], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][55], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][55], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][55], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][55], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][55], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][55], 0);

        gsInventoryTextdraw[playerid][56] = CreatePlayerTextDraw(playerid, 533.000000, 236.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][56], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][56], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][56], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][56], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][56], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][56], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][56], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][56], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][56], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][56], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][56], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][56], 0);

        gsInventoryTextdraw[playerid][57] = CreatePlayerTextDraw(playerid, 306.000000, 304.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][57], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][57], 0.112500, 0.700000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][57], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][57], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][57], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][57], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][57], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][57], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][57], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][57], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][57], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][57], 0);

        gsInventoryTextdraw[playerid][58] = CreatePlayerTextDraw(playerid, 362.000000, 304.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][58], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][58], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][58], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][58], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][58], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][58], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][58], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][58], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][58], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][58], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][58], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][58], 0);

        gsInventoryTextdraw[playerid][59] = CreatePlayerTextDraw(playerid, 419.000000, 304.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][59], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][59], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][59], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][59], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][59], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][59], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][59], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][59], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][59], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][59], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][59], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][59], 0);

        gsInventoryTextdraw[playerid][60] = CreatePlayerTextDraw(playerid, 477.000000, 304.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][60], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][60], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][60], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][60], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][60], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][60], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][60], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][60], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][60], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][60], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][60], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][60], 0);

        gsInventoryTextdraw[playerid][61] = CreatePlayerTextDraw(playerid, 533.000000, 304.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][61], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][61], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][61], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][61], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][61], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][61], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][61], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][61], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][61], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][61], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][61], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][61], 0);

        gsInventoryTextdraw[playerid][62] = CreatePlayerTextDraw(playerid, 306.000000, 370.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][62], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][62], 0.112500, 0.700000);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][62], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][62], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][62], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][62], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][62], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][62], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][62], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][62], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][62], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][62], 0);

        gsInventoryTextdraw[playerid][63] = CreatePlayerTextDraw(playerid, 362.000000, 370.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][63], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][63], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][63], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][63], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][63], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][63], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][63], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][63], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][63], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][63], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][63], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][63], 0);

        gsInventoryTextdraw[playerid][64] = CreatePlayerTextDraw(playerid, 419.000000, 370.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][64], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][64], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][64], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][64], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][64], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][64], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][64], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][64], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][64], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][64], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][64], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][64], 0);

        gsInventoryTextdraw[playerid][65] = CreatePlayerTextDraw(playerid, 477.000000, 370.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][65], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][65], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][65], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][65], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][65], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][65], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][65], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][65], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][65], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][65], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][65], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][65], 0);

        gsInventoryTextdraw[playerid][66] = CreatePlayerTextDraw(playerid, 533.000000, 370.000000, "CAIXINHA DIAMANTE (~p~10~w~)");
        PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][66], 1);
        PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][66], 0.112219, 0.699999);
        PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][66], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][66], 0);
        PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][66], 0);
        PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][66], 3);
        PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][66], -1);
        PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][66], 255);
        PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][66], 50);
        PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][66], 0);
        PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][66], 1);
        PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][66], 0);
    }
}

static stock Inventory_CreateTextdraw(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    Inventory_CreateInfoBox(playerid, screenType);
    Inventory_CreateItemsBox(playerid, screenType);
    Inventory_CreateItemOptions(playerid, screenType);
    Inventory_CreateCloseButton(playerid, screenType);
    Inventory_CreatePreviewOptions(playerid, screenType);
    Inventory_CreatePreviewDesc(playerid, screenType);
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Inventory_Show(playerid)
{
    for (new i; i < (TEXTDRAW_ARRAY_SIZE - 20); i++)
    {
        // Show all textdraws, except item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    HideInventoryItemOptions(playerid);
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
    for (new i = 35; i < 42; i++)
    {
        // Show item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock HideInventoryItemOptions(playerid)
{
    for (new i = 35; i < 42; i++)
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
    if (index < 0 || index > TEXTDRAW_ARRAY_SIZE)
    {
        return gsInventoryTextdraw[playerid][0];
    }
    return gsInventoryTextdraw[playerid][index];
}

stock GetInventoryTextdrawIndex(playerid, PlayerText:txtId)
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

stock ResetInventoryBoxInfo(playerid)
{
    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][2]);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], GetPlayerSkin(playerid));
    PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][2], -10.000000, 0.000000, -8.000000, 1.000000);
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

stock UpdateInventoryItemPreview(playerid, index, itemId, bool:isInventoryOpened)
{
    if (index < 11 || index > 30)
    {
        return 0;
    }
    if (isInventoryOpened)
    {
       PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][index]); 
    }
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][index], itemId);
    if (isInventoryOpened)
    {
       PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][index]); 
    }
    return 1;
}

stock UpdateInventoryItemBoxColor(playerid, index, color)
{
    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][index]);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][index], color);
    PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][index]);
    return 1;
}

stock UpdateInventoryBoxInfo(playerid, invSlot, itemId, const name[], quantity, const rarity[])
{
    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][2]);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], itemId);
    PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][2], -10.000000, 0.000000, -8.000000, 1.000000);
    PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][2]);

    new txtString[(31 + MAX_MONEY_STRING)], formatMoney[MAX_MONEY_STRING];
    #if DEV_MODE
        format(txtString, sizeof(txtString), "ITEM[%d]: %s", invSlot, name);
        PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][4], txtString);
    #else
        format(txtString, sizeof(txtString), "ITEM: %s", name);
        PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][4], txtString);
    #endif

    FormatMoneyString(Player_GetMoney(playerid), formatMoney);
    format(txtString, sizeof(txtString), "QUANTIDADE: %d", quantity);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][5], txtString);

    format(txtString, sizeof(txtString), "RARIDADE: %s", rarity);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][6], txtString);
    return 1;
}

stock UpdateInventoryPageText(playerid, page, maxPages)
{
    new txtString[15];
    format(txtString, sizeof(txtString), "PAGINA: %d/%d", page, maxPages);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][34], txtString);
    return 1;
}

stock ChangeInventoryTotalItens(playerid, validItems, totalItems)
{
    new txtString[13];
    format(txtString, sizeof(txtString), "ITEMS: %d/%d", validItems, totalItems);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][31], txtString);
    return 1;
}

stock ShowPreviewDescription(playerid, index)
{
    if (index < 47 || index > 66)
    {
        return 0;
    }

    PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][index]);
    return 1;
}

stock HidePreviewDescription(playerid, index)
{
    if (index < 47 || index > 66)
    {
        return 0;
    }

    PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][index]);
    return 1;
}

stock HideAllPreviewDescription(playerid, index)
{
    for (new i = 47; i < 67; i++)
    {
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][i]);

        }
    }
    return 1;
}


stock UpdateInventoryPreviewDesc(playerid, index, const name[], quantity)
{
    if (index < 47 || index > 66)
    {
        return 0;
    }

    new txtString[32];
    format(txtString, sizeof(txtString), "%s (~p~%d~w~)", name, quantity);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][index], txtString);
    return 1;
}

stock UpdateBoxPreviewRotation(playerid, Float:xRotation, Float:zRotation, bool:isOpened = false)
{
    if (isOpened)
    {
        PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][2]);
    }
    PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][2], xRotation, 0.000000, zRotation, 1.000000);
    if (isOpened)
    {
        PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][2]);
    }
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
    #pragma unused reason // need this directive, on account of YSI which shows warnings in case the parameter is not used.
    
    Inventory_Hide(playerid);
    Inventory_Destroy(playerid);
	return 1;
}