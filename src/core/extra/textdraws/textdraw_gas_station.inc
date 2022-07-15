#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:gsFuelTextdraw[MAX_PLAYERS][12];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock GasStationCreateTextdraw(playerid, e_SCREENS:screenType = SCREEN_NORMAL)
{
    if (screenType == SCREEN_ULTRAWIDE)
    {
        gsFuelTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 609.000000, 207.000000, "POSTO DE GASOLINA");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][0], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][0], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][0], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][0], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][0], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][0], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][0], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][0], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][0], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][0], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][0], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][0], 0);

        gsFuelTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 576.000000, 200.000000, "_");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][1], 2);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][1], 0.633333, 10.750004);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][1], 298.500000, 114.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][1], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][1], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][1], 2);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][1], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][1], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][1], 185);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][1], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][1], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][1], 0);

        gsFuelTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 519.000000, 197.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][2], 5);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][2], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][2], 24.500000, 30.500000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][2], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][2], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][2], 255);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][2], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawSetPreviewModel(playerid, gsFuelTextdraw[playerid][2], 1676);
        PlayerTextDrawSetPreviewRot(playerid, gsFuelTextdraw[playerid][2], -10.000000, 0.000000, -20.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsFuelTextdraw[playerid][2], 1, 1);

        gsFuelTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 562.000000, 255.000000, "LITROS:");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][3], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][3], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][3], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][3], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][3], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][3], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][3], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][3], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][3], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][3], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][3], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][3], 0);

        gsFuelTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 560.000000, 271.000000, "VALOR:");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][4], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][4], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][4], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][4], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][4], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][4], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][4], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][4], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][4], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][4], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][4], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][4], 0);

        gsFuelTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 566.000000, 239.000000, "MODELO:");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][5], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][5], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][5], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][5], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][5], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][5], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][5], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][5], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][5], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][5], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][5], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][5], 0);

        gsFuelTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 627.000000, 239.000000, "POLICE MAVERICK");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][6], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][6], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][6], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][6], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][6], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][6], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][6], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][6], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][6], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][6], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][6], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][6], 0);

        gsFuelTextdraw[playerid][7] = CreatePlayerTextDraw(playerid, 626.000000, 255.000000, "~y~100L ~w~/ ~p~ 120 L");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][7], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][7], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][7], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][7], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][7], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][7], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][7], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][7], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][7], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][7], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][7], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][7], 0);

        gsFuelTextdraw[playerid][8] = CreatePlayerTextDraw(playerid, 626.000000, 271.000000, "~g~R$ 350,00");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][8], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][8], 0.204166, 1.099999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][8], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][8], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][8], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][8], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][8], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][8], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][8], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][8], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][8], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][8], 0);

        gsFuelTextdraw[playerid][9] = CreatePlayerTextDraw(playerid, 527.000000, 271.000000, "HUD:radar_cash");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][9], 4);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][9], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][9], 8.500000, 10.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][9], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][9], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][9], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][9], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][9], 0);

        gsFuelTextdraw[playerid][10] = CreatePlayerTextDraw(playerid, 527.000000, 256.000000, "HUD:radar_modgarage");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][10], 4);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][10], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][10], 8.500000, 10.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][10], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][10], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][10], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][10], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][10], 0);

        gsFuelTextdraw[playerid][11] = CreatePlayerTextDraw(playerid, 527.000000, 239.000000, "HUD:radar_impound");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][11], 4);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][11], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][11], 8.500000, 10.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][11], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][11], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][11], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][11], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][11], 0);
    }
    else
    {
        gsFuelTextdraw[playerid][0] = CreatePlayerTextDraw(playerid, 606.000000, 207.000000, "POSTO DE GASOLINA");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][0], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][0], 0.316943, 1.399998);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][0], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][0], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][0], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][0], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][0], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][0], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][0], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][0], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][0], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][0], 0);

        gsFuelTextdraw[playerid][1] = CreatePlayerTextDraw(playerid, 549.000000, 198.000000, "_");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][1], 2);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][1], 0.633333, 11.850008);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][1], 298.500000, 150.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][1], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][1], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][1], 2);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][1], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][1], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][1], 185);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][1], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][1], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][1], 0);

        gsFuelTextdraw[playerid][2] = CreatePlayerTextDraw(playerid, 478.000000, 195.000000, "Preview_Model");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][2], 5);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][2], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][2], 34.500000, 37.500000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][2], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][2], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][2], 255);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][2], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][2], 0);
        PlayerTextDrawSetPreviewModel(playerid, gsFuelTextdraw[playerid][2], 1676);
        PlayerTextDrawSetPreviewRot(playerid, gsFuelTextdraw[playerid][2], -10.000000, 0.000000, -20.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, gsFuelTextdraw[playerid][2], 1, 1);

        gsFuelTextdraw[playerid][3] = CreatePlayerTextDraw(playerid, 527.000000, 262.000000, "LITROS:");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][3], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][3], 0.304443, 1.149999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][3], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][3], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][3], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][3], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][3], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][3], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][3], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][3], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][3], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][3], 0);

        gsFuelTextdraw[playerid][4] = CreatePlayerTextDraw(playerid, 524.000000, 280.000000, "VALOR:");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][4], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][4], 0.304439, 1.149999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][4], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][4], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][4], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][4], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][4], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][4], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][4], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][4], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][4], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][4], 0);

        gsFuelTextdraw[playerid][5] = CreatePlayerTextDraw(playerid, 532.000000, 244.000000, "MODELO:");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][5], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][5], 0.304165, 1.149998);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][5], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][5], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][5], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][5], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][5], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][5], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][5], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][5], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][5], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][5], 0);

        gsFuelTextdraw[playerid][6] = CreatePlayerTextDraw(playerid, 625.000000, 244.000000, "POLICE MAVERICK");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][6], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][6], 0.304443, 1.149999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][6], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][6], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][6], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][6], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][6], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][6], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][6], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][6], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][6], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][6], 0);

        gsFuelTextdraw[playerid][7] = CreatePlayerTextDraw(playerid, 624.000000, 262.000000, "~y~100L ~w~/ ~p~ 120 L");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][7], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][7], 0.304443, 1.099998);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][7], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][7], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][7], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][7], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][7], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][7], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][7], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][7], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][7], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][7], 0);

        gsFuelTextdraw[playerid][8] = CreatePlayerTextDraw(playerid, 624.000000, 279.000000, "~g~R$ 350,00");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][8], 3);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][8], 0.304444, 1.149999);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][8], 400.000000, 17.000000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][8], 0);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][8], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][8], 3);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][8], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][8], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][8], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][8], 0);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][8], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][8], 0);

        gsFuelTextdraw[playerid][9] = CreatePlayerTextDraw(playerid, 475.000000, 280.000000, "HUD:radar_cash");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][9], 4);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][9], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][9], 10.000000, 11.500000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][9], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][9], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][9], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][9], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][9], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][9], 0);

        gsFuelTextdraw[playerid][10] = CreatePlayerTextDraw(playerid, 475.000000, 262.000000, "HUD:radar_modgarage");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][10], 4);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][10], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][10], 10.000000, 11.500000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][10], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][10], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][10], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][10], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][10], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][10], 0);

        gsFuelTextdraw[playerid][11] = CreatePlayerTextDraw(playerid, 475.000000, 242.000000, "HUD:radar_impound");
        PlayerTextDrawFont(playerid, gsFuelTextdraw[playerid][11], 4);
        PlayerTextDrawLetterSize(playerid, gsFuelTextdraw[playerid][11], 0.600000, 2.000000);
        PlayerTextDrawTextSize(playerid, gsFuelTextdraw[playerid][11], 10.000000, 11.500000);
        PlayerTextDrawSetOutline(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawSetShadow(playerid, gsFuelTextdraw[playerid][11], 0);
        PlayerTextDrawAlignment(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawColor(playerid, gsFuelTextdraw[playerid][11], -1);
        PlayerTextDrawBackgroundColor(playerid, gsFuelTextdraw[playerid][11], 255);
        PlayerTextDrawBoxColor(playerid, gsFuelTextdraw[playerid][11], 50);
        PlayerTextDrawUseBox(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawSetProportional(playerid, gsFuelTextdraw[playerid][11], 1);
        PlayerTextDrawSetSelectable(playerid, gsFuelTextdraw[playerid][11], 0);
    }
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock AdaptFuelTextdrawToScreen(playerid)
{
    DestroyFuelTextdraw(playerid);
    switch (Player_GetScreenSize(playerid))
    {
        case SCREEN_ULTRAWIDE:
        {
            GasStationCreateTextdraw(playerid, SCREEN_ULTRAWIDE);
        }
        default:
        {
            GasStationCreateTextdraw(playerid, SCREEN_NORMAL);
        }
    }
	return 1;
}

stock ShowFuelTextdraw(playerid)
{
    for (new i; i < 12; i++)
    {
        if (gsFuelTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {   
            PlayerTextDrawShow(playerid, gsFuelTextdraw[playerid][i]);
        }
    }
	return 1;
}

stock HideFuelTextDraw(playerid)
{
    for (new i; i < 12; i++)
    {
        if (gsFuelTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawHide(playerid, gsFuelTextdraw[playerid][i]);
        }
    }
	return 1;
}

stock DestroyFuelTextdraw(playerid)
{
    for (new i; i < 12; i++)
    {
        if (gsFuelTextdraw[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
        {
            PlayerTextDrawDestroy(playerid, gsFuelTextdraw[playerid][i]);
        }
    }
	return 1;
}

stock UpdateFuelTextdraw(playerid, model, fuel, price)
{
    if (gsFuelTextdraw[playerid][6] != INVALID_PLAYER_TEXT_DRAW)
    {
        new vehicleName[MAX_VEHICLE_NAME_STRING];
        GetVehicleName(model, vehicleName);
        PlayerTextDrawSetString(playerid, gsFuelTextdraw[playerid][6], vehicleName);
    }

    if (gsFuelTextdraw[playerid][7] != INVALID_PLAYER_TEXT_DRAW)
    {
        new fuelString[23];
        format(fuelString, sizeof(fuelString), "~y~%dL ~w~/ ~p~ %dL", fuel, GetVehicleFuelCapacity(model));
        PlayerTextDrawSetString(playerid, gsFuelTextdraw[playerid][7], fuelString);
    }

    if (gsFuelTextdraw[playerid][8] != INVALID_PLAYER_TEXT_DRAW)
    {
        new priceString[(7 + MAX_MONEY_STRING)], priceFormated[MAX_MONEY_STRING];
        FormatMoneyString(price, priceFormated);
        format(priceString, sizeof(priceString), "~g~R$ %s", priceFormated);
        PlayerTextDrawSetString(playerid, gsFuelTextdraw[playerid][8], priceString);
    }
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    GasStationCreateTextdraw(playerid, SCREEN_NORMAL);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    #pragma unused reason // need this directive, on account of YSI which shows warnings in case the parameter is not used.
    
    HideFuelTextDraw(playerid);
    DestroyFuelTextdraw(playerid);
	return 1;
}