#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:modernSpeedometer[MAX_PLAYERS][20];
static PlayerText:compactSpeedometer[MAX_PLAYERS][9];

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock Compact_CreateUltrawideScreen(playerid)
{
	compactSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 80.000000, 402.000000, "Blindagem: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][0], 0.204999, 1.099998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][0], 0);

	compactSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 80.000000, 392.000000, "Lataria: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][1], 0.204999, 1.099998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][1], 0);

	compactSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 104.000000, 363.000000, "100");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][2], 0.395833, 1.900000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][2], 0);

	compactSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 80.000000, 369.000000, "KM/H:");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][3], 0.204999, 1.099998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][3], 0);

	compactSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 135.000000, 364.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][4], 0.691666, -0.300004);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][4], 299.000000, 104.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][4], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][4], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][4], 0);

	compactSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 80.000000, 347.000000, "Helicoptero Policial");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][5], 0.230000, 1.150000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][5], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][5], 0);

	compactSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 136.000000, 277.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][6], 5);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][6], 54.000000, 88.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][6], 1296911871);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][6], -16777216);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][6], -2686721);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetPreviewModel(playerid, compactSpeedometer[playerid][6], 442);
	PlayerTextDrawSetPreviewRot(playerid, compactSpeedometer[playerid][6], -10.000000, 0.000000, -44.000000, 0.920000);
	PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], 1, 1);

	compactSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 191.300003, 311.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][7], 0.462500, 11.699999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][7], 295.000000, -1.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][7], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][7], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][7], 0);

	compactSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 80.000000, 381.000000, "Combustivel: 100 L");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][8], 0.205000, 1.099999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][8], 0);
	return 1;
}

static stock Compact_CreateNormalScreen(playerid)
{
	compactSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 151.000000, 402.000000, "Blindagem: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][0], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][0], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][0], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][0], false);

	compactSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 151.000000, 392.000000, "Lataria: 0%");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][1], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][1], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][1], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][1], false);

	compactSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 177.000000, 362.000000, "100");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][2], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][2], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][2], false);

	compactSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 151.000000, 367.000000, "KM/H:");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][3], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][3], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][3], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][3], false);

	compactSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 205.000000, 360.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][4], 0.691666, 0.149994);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][4], 299.000000, 104.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][4], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][4], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][4], true);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][4], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][4], false);

	compactSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 152.000000, 343.000000, "Romero");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][5], 0.287499, 1.299998);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][5], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][5], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][5], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][5], false);

	compactSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 205.000000, 278.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][6], 5);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][6], 61.500000, 90.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][6], 1296911871);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][6], -16777216);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][6], -2686976);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][6], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][6], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][6], false);
	PlayerTextDrawSetPreviewModel(playerid, compactSpeedometer[playerid][6], 442);
	PlayerTextDrawSetPreviewRot(playerid, compactSpeedometer[playerid][6], -10.000000, 0.000000, -44.000000, 0.920000);
	PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], 1, 1);

	compactSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 260.000000, 311.000000, "_");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][7], 0.462500, 11.700005);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][7], 295.000000, 0.500000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][7], 2);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][7], 135);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][7], true);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][7], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][7], false);

	compactSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 150.000000, 381.000000, "Combustivel: 100 L");
	PlayerTextDrawFont(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, compactSpeedometer[playerid][8], 0.237498, 1.149999);
	PlayerTextDrawTextSize(playerid, compactSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, compactSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, compactSpeedometer[playerid][8], 1);
	PlayerTextDrawColor(playerid, compactSpeedometer[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, compactSpeedometer[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, compactSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, compactSpeedometer[playerid][8], false);
	PlayerTextDrawSetProportional(playerid, compactSpeedometer[playerid][8], true);
	PlayerTextDrawSetSelectable(playerid, compactSpeedometer[playerid][8], false);
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock UpdatePlayerSpeedometer(playerid, vehicleid, type)
{
	if (vehicleid == INVALID_VEHICLE_ID)
	{
		return 0;
	}
	
    new speedometerString[20], Float:vehicleHealth;
    GetVehicleHealth(vehicleid, vehicleHealth);
    switch (type)
    {
        case 0:
        {
            new spd1, spd2, spd3;
            spd1 = GetVehicleSpeed(vehicleid) / 100;
            spd2 = GetVehicleSpeed(vehicleid) % 100;
            spd3 = spd2 % 10;
            spd2 = spd2 / 10;

            if (!Vehicle_GetLockedStatus(vehicleid))
            {
                PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][12], "~g~A ~w~F");
            }
            else
            {
                PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][12], "~w~A ~r~F");
            }

            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][16], GetVehicleName(GetVehicleModel(vehicleid)));

            format(speedometerString, sizeof (speedometerString), "%d", spd1);
            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][13], speedometerString);

            format(speedometerString, sizeof (speedometerString), "%d", spd2);
            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][14], speedometerString);

            format(speedometerString, sizeof (speedometerString), "%d", spd3);
            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][15], speedometerString);

            format(speedometerString, sizeof (speedometerString), "%02d Litros", Vehicle_GetFuel(vehicleid));
            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][17], speedometerString);

            format(speedometerString, sizeof (speedometerString), "%0.0f%", vehicleHealth / 10);
            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][18], speedometerString);

            format(speedometerString, sizeof (speedometerString), "%d%%", Vehicle_GetShield(vehicleid));
            PlayerTextDrawSetString(playerid, modernSpeedometer[playerid][19], speedometerString);
        }
        case 1:
        {
            PlayerTextDrawSetPreviewModel(playerid, compactSpeedometer[playerid][6], GetVehicleModel(vehicleid));
			PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], Vehicle_GetColorOne(vehicleid), Vehicle_GetColorTwo(vehicleid));


            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][5], GetVehicleName(GetVehicleModel(vehicleid)));

            format(speedometerString, sizeof (speedometerString), "%02d", GetVehicleSpeed(vehicleid));
            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][2], speedometerString);

            format(speedometerString, sizeof (speedometerString), "Combustivel: %02d L", Vehicle_GetFuel(vehicleid));
            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][8], speedometerString);

            format(speedometerString, sizeof (speedometerString), "Lataria: %0.0f%", vehicleHealth / 10);
            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][1], speedometerString);

            format(speedometerString, sizeof (speedometerString), "Blindagem: %d%%", Vehicle_GetShield(vehicleid));
            PlayerTextDrawSetString(playerid, compactSpeedometer[playerid][0], speedometerString);
        }
    }
    return 1;
}

stock AdaptSpeedometerToScreen(playerid)
{
	for (new i; i < 9; i++)
	{
		if (compactSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
		{
			PlayerTextDrawDestroy(playerid, compactSpeedometer[playerid][i]);
		}
	}

	// Ultrawide corrections
	if (Player_GetScreenSize(playerid) == SCREEN_ULTRAWIDE)
	{
		Compact_CreateUltrawideScreen(playerid);
	}
	else
	{
		Compact_CreateNormalScreen(playerid);
	}	
	return 1;
}

stock ShowPlayerSpeedometer(playerid, type)
{
	switch(type)
	{
		case 0:
		{
			for (new i; i < 20; i++)
            {
                PlayerTextDrawShow(playerid, modernSpeedometer[playerid][i]);
            }
		}
		case 1:
		{
			for (new i; i < 9; i++)
            {
                PlayerTextDrawShow(playerid, compactSpeedometer[playerid][i]);
            }
		}
	}
    return 1;
}

stock HidePlayerSpeedometer(playerid)
{
	switch (Player_GetSpeedometer(playerid))
	{
		case 0:
		{
			for (new i; i < 20; i++)
			{
				PlayerTextDrawHide(playerid, modernSpeedometer[playerid][i]);
			}
		}
		case 1:
		{
			for (new i; i < 9; i++)
			{
				PlayerTextDrawHide(playerid, compactSpeedometer[playerid][i]);
			}
		}
	}
    return 1;
}

stock DestroyPlayerSpeedometer(playerid)
{
	switch (Player_GetSpeedometer(playerid))
	{
		case 0:
		{
			for (new i; i < 20; i++)
			{
				if (modernSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawDestroy(playerid, modernSpeedometer[playerid][i]);
				}
			}
		}
		case 1:
		{
			for (new i; i < 9; i++)
			{
				if (compactSpeedometer[playerid][i] != INVALID_PLAYER_TEXT_DRAW)
				{
					PlayerTextDrawDestroy(playerid, compactSpeedometer[playerid][i]);
				}
			}
		}
	}
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	Compact_CreateNormalScreen(playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    HidePlayerSpeedometer(playerid);
    DestroyPlayerSpeedometer(playerid);
	return 1;
}