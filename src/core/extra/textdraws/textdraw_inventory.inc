#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsInventoryTextdraw[MAX_PLAYERS][41];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
stock Inventory_CreateInfoBox(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    printf("%d", screenType);
    gsInventoryTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 241.000000, 97.000000, "_");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][0], 0.600000, 20.500068);
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

    gsInventoryTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 231.000000, 101.000000, "MOCHILA");
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

    gsInventoryTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 204.000000, 118.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 196.000000, 262.000000, "I");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][3], 1);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][3], 14.183367, -0.149998);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][3], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][3], -1094795521);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][3], 0);

    gsInventoryTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 203.000000, 224.000000, "ITEM: BARRA DE CHOCOLATE");
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

    gsInventoryTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 203.000000, 235.000000, "QUANTIDADE: 20");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][5], 3);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][5], 0.136998, 0.849999);
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

    gsInventoryTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 203.000000, 246.000000, "RARIDADE: DESCONHECIDA");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][6], 3);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][6], 0.136998, 0.849999);
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

    gsInventoryTextdraw[playerid][7] = CreatePlayerTextDraw(playerid, 196.000000, 220.000000, "I");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][7], 1);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][7], 14.183367, -0.149998);
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

    gsInventoryTextdraw[playerid][8] = CreatePlayerTextDraw(playerid, 240.500000, 269.000000, "ORGANIZAR");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][8], 2);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][8], 0.108332, 0.800000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][8], 16.500000, 72.500000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][8], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][8], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][8], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][8], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][8], 1296911816);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][8], 1);
    return 1;
}

stock Inventory_CreateItemsBox(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    printf("%d", screenType);
    gsInventoryTextdraw[playerid][9] = CreatePlayerTextDraw(playerid, 374.500000, 97.000000, "_");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][9], 1);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][9], 0.600000, 26.949993);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][9], 298.500000, 179.500000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][9], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][9], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][9], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][9], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][9], 225);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][9], 0);

    gsInventoryTextdraw[playerid][10] = CreatePlayerTextDraw(playerid, 285.000000, 98.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][10], 5);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][10], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][10], 35.000000, 54.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][10], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][10], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][10], 1296911746);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][10], 255);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][10], 0);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][10], 1);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][10], 18631);
    PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][10], -10.000000, 0.000000, -8.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][10], 1, 1);

    gsInventoryTextdraw[playerid][11] = CreatePlayerTextDraw(playerid, 321.000000, 98.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][12] = CreatePlayerTextDraw(playerid, 357.000000, 98.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][13] = CreatePlayerTextDraw(playerid, 393.000000, 98.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][14] = CreatePlayerTextDraw(playerid, 429.000000, 98.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][15] = CreatePlayerTextDraw(playerid, 285.000000, 153.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][16] = CreatePlayerTextDraw(playerid, 321.000000, 153.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][16], 5);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][16], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][16], 35.000000, 54.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][16], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][16], 1);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][16], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][16], 1296911746);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][16], 1296911871);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][16], 0);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][16], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][16], 1);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][16], 18631);
    PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][16], -10.000000, 0.000000, -8.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][16], 1, 1);

    gsInventoryTextdraw[playerid][17] = CreatePlayerTextDraw(playerid, 357.000000, 153.000000, "Preview_Model");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][17], 5);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][17], 0.600000, 2.000000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][17], 35.000000, 54.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][17], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][17], 1);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][17], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][17], 1296911746);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][17], 255);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][17], 0);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][17], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][17], 1);
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][17], 18631);
    PlayerTextDrawSetPreviewRot(playerid, gsInventoryTextdraw[playerid][17], -10.000000, 0.000000, -8.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, gsInventoryTextdraw[playerid][17], 1, 1);

    gsInventoryTextdraw[playerid][18] = CreatePlayerTextDraw(playerid, 393.000000, 153.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][19] = CreatePlayerTextDraw(playerid, 429.000000, 153.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][20] = CreatePlayerTextDraw(playerid, 285.000000, 208.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][21] = CreatePlayerTextDraw(playerid, 321.000000, 208.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][22] = CreatePlayerTextDraw(playerid, 357.000000, 208.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][23] = CreatePlayerTextDraw(playerid, 393.000000, 208.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][24] = CreatePlayerTextDraw(playerid, 429.000000, 208.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][25] = CreatePlayerTextDraw(playerid, 285.000000, 263.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][26] = CreatePlayerTextDraw(playerid, 321.000000, 263.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][27] = CreatePlayerTextDraw(playerid, 357.000000, 263.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][28] = CreatePlayerTextDraw(playerid, 393.000000, 263.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][29] = CreatePlayerTextDraw(playerid, 429.000000, 263.000000, "Preview_Model");
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

    gsInventoryTextdraw[playerid][30] = CreatePlayerTextDraw(playerid, 285.000000, 326.000000, "ITEMS: 30/80");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][30], 3);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][30], 0.183332, 1.000000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][30], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][30], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][30], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][30], 1);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][30], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][30], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][30], 50);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][30], 0);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][30], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][30], 0);

    gsInventoryTextdraw[playerid][31] = CreatePlayerTextDraw(playerid, 366.000000, 326.000000, "<<");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][31], 3);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][31], 0.129166, 0.949999);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][31], 16.500000, 9.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][31], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][31], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][31], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][31], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][31], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][31], 1296911816);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][31], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][31], 1);

    gsInventoryTextdraw[playerid][32] = CreatePlayerTextDraw(playerid, 384.000000, 326.000000, ">>");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][32], 3);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][32], 0.129166, 0.949999);
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

    gsInventoryTextdraw[playerid][33] = CreatePlayerTextDraw(playerid, 464.000000, 326.000000, "PAGINA: 1/4");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][33], 3);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][33], 0.183332, 1.000000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][33], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][33], 0);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][33], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][33], 3);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][33], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][33], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][33], 50);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][33], 0);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][33], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][33], 0);
    return 1;
}

stock Inventory_CreateItemOptions(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    printf("%d", screenType);
    gsInventoryTextdraw[playerid][34] = CreatePlayerTextDraw(playerid, 241.000000, 290.000000, "_");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][34], 1);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][34], 0.600000, 5.550066);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][34], 298.500000, 76.500000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][34], 1);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][34], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][34], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][34], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][34], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][34], 225);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][34], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][34], 0);

    gsInventoryTextdraw[playerid][35] = CreatePlayerTextDraw(playerid, 221.000000, 293.000000, "USAR");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][35], 2);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][35], 0.108332, 0.800000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][35], 16.500000, 33.500000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][35], 1);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][35], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][35], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][35], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][35], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][35], 1296911816);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][35], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][35], 1);

    gsInventoryTextdraw[playerid][36] = CreatePlayerTextDraw(playerid, 260.000000, 293.000000, "DESCARTAR");
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

    gsInventoryTextdraw[playerid][37] = CreatePlayerTextDraw(playerid, 221.000000, 311.000000, "JUNTAR");
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

    gsInventoryTextdraw[playerid][38] = CreatePlayerTextDraw(playerid, 260.000000, 311.000000, "SEPARAR");
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

    gsInventoryTextdraw[playerid][39] = CreatePlayerTextDraw(playerid, 240.500000, 329.000000, "NEGOCIAR");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][39], 2);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][39], 0.108332, 0.800000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][39], 16.500000, 72.500000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][39], 1);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][39], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][39], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][39], -1);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][39], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][39], 1296911816);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][39], 1);
    return 1;
}

stock Inventory_CreateCloseButton(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    printf("%d", screenType);
    gsInventoryTextdraw[playerid][40] = CreatePlayerTextDraw(playerid, 472.000000, 97.000000, "X");
    PlayerTextDrawFont(playerid, gsInventoryTextdraw[playerid][40], 2);
    PlayerTextDrawLetterSize(playerid, gsInventoryTextdraw[playerid][40], 0.137499, 0.850000);
    PlayerTextDrawTextSize(playerid, gsInventoryTextdraw[playerid][40], 16.500000, 5.000000);
    PlayerTextDrawSetOutline(playerid, gsInventoryTextdraw[playerid][40], 1);
    PlayerTextDrawSetShadow(playerid, gsInventoryTextdraw[playerid][40], 0);
    PlayerTextDrawAlignment(playerid, gsInventoryTextdraw[playerid][40], 2);
    PlayerTextDrawColor(playerid, gsInventoryTextdraw[playerid][40], -16776961);
    PlayerTextDrawBackgroundColor(playerid, gsInventoryTextdraw[playerid][40], 255);
    PlayerTextDrawBoxColor(playerid, gsInventoryTextdraw[playerid][40], 225);
    PlayerTextDrawUseBox(playerid, gsInventoryTextdraw[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, gsInventoryTextdraw[playerid][40], 1);
    PlayerTextDrawSetSelectable(playerid, gsInventoryTextdraw[playerid][40], 1);
    return 1;
}

static stock Inventory_CreateTextdraw(playerid)
{
    Inventory_CreateInfoBox(playerid, SCREEN_NORMAL);
    Inventory_CreateItemsBox(playerid, SCREEN_NORMAL);
    Inventory_CreateItemOptions(playerid, SCREEN_NORMAL);
    Inventory_CreateCloseButton(playerid, SCREEN_NORMAL);
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Inventory_Show(playerid)
{
    for (new i; i < 41; i++)
    {
        // Show all textdraws, except item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW && gsInventoryTextdraw[playerid][i] < 34 && gsInventoryTextdraw[playerid][i] > 39)
        {
            PlayerTextDrawShow(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock Inventory_ShowItemOptions(playerid)
{
    for (new i = 34; i < 40; i++)
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
    for (new i = 34; i < 40; i++)
    {
        // Show item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock Inventory_Hide(playerid)
{
    for (new i; i < 41; i++)
    {
        // Show item options
        if (gsInventoryTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawHide(playerid, gsInventoryTextdraw[playerid][i]);
        }
    }
    return 1;
}

stock Inventory_UpdateBoxInfo(playerid)
{
    PlayerTextDrawSetPreviewModel(playerid, gsInventoryTextdraw[playerid][2], GetPlaeyrSKin(playerid));

    new txtString[(31 + MAX_MONEY_STRING)], formatMoney[MAX_MONEY_STRING];
    format(txtString, sizeof(txtString), "NOME: %s", GetPlayerNameCustom(playerid));
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][4], txtString);

    FormatMoneyString(Player_GetMoney(playerid), formatMoney);
    format(txtString, sizeof(txtString), "DINHEIRO: %s", formatMoney);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][5], txtString);

    FormatMoneyString(Player_GetCoins(playerid), formatMoney);
    format(txtString, sizeof(txtString), "MOEDAS VIP: %s", formatMoney);
    PlayerTextDrawSetString(playerid, gsInventoryTextdraw[playerid][5], txtString);
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
	return 1;
}