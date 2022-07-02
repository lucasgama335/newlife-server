#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static PlayerText:modernSpeedometer[MAX_PLAYERS][20];
static PlayerText:compactSpeedometer[MAX_PLAYERS][9];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock UpdatePlayerSpeedometer(playerid, vehicleid, type)
{
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
			PlayerTextDrawSetPreviewVehCol(playerid, compactSpeedometer[playerid][6], 1, 1);

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
    for (new i; i < 20; i++)
    {
        PlayerTextDrawHide(playerid, modernSpeedometer[playerid][i]);
    }
	for (new i; i < 9; i++)
    {
        PlayerTextDrawHide(playerid, compactSpeedometer[playerid][i]);
    }
    return 1;
}

stock DestroyPlayerSpeedometer(playerid)
{
    for (new i; i < 20; i++)
    {
        PlayerTextDrawDestroy(playerid, modernSpeedometer[playerid][i]);
    }
	for (new i; i < 9; i++)
    {
        PlayerTextDrawDestroy(playerid, compactSpeedometer[playerid][i]);
    }
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    // Modern
    modernSpeedometer[playerid][0] = CreatePlayerTextDraw(playerid, 586.000000, 368.000000, "Km/h");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][0], 0.300000, 1.250000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][0], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][0], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][0], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][0], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][0], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][0], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][0], false);

	modernSpeedometer[playerid][1] = CreatePlayerTextDraw(playerid, 442.000000, 422.000000, "l");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][1], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][1], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][1], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][1], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][1], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][1], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][1], false);

	modernSpeedometer[playerid][2] = CreatePlayerTextDraw(playerid, 442.000000, 408.000000, "l");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][2], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][2], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][2], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][2], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][2], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][2], false);

	modernSpeedometer[playerid][3] = CreatePlayerTextDraw(playerid, 442.000000, 394.000000, "l");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][3], 23.995798, 2.249999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][3], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][3], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][3], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][3], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][3], false);

	modernSpeedometer[playerid][4] = CreatePlayerTextDraw(playerid, 442.000000, 380.000000, "l");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][4], 23.995798, 2.349998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][4], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][4], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][4], 102);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][4], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][4], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][4], false);

	modernSpeedometer[playerid][5] = CreatePlayerTextDraw(playerid, 496.000000, 386.000000, "Veiculo");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][5], 0.283331, 1.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][5], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][5], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][5], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][5], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][5], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][5], false);

	modernSpeedometer[playerid][6] = CreatePlayerTextDraw(playerid, 496.000000, 399.000000, "Gasolina");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][6], 0.237498, 1.100000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][6], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][6], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][6], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][6], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][6], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][6], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][6], false);

	modernSpeedometer[playerid][7] = CreatePlayerTextDraw(playerid, 496.000000, 413.000000, "Lataria");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][7], 0.287498, 1.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][7], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][7], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][7], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][7], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][7], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][7], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][7], false);

	modernSpeedometer[playerid][8] = CreatePlayerTextDraw(playerid, 496.000000, 427.000000, "Blindagem");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][8], 0.208333, 1.049998);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][8], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][8], 1);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][8], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][8], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][8], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][8], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][8], false);

	modernSpeedometer[playerid][9] = CreatePlayerTextDraw(playerid, 513.000000, 367.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][9], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][9], 0.583333, 1.700002);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][9], 297.000000, 30.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][9], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][9], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][9], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][9], 135);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][9], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][9], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][9], false);

	modernSpeedometer[playerid][10] = CreatePlayerTextDraw(playerid, 556.000000, 357.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][10], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][10], 0.583333, 2.750001);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][10], 297.000000, 49.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][10], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][10], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][10], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][10], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][10], 135);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][10], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][10], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][10], false);

	modernSpeedometer[playerid][11] = CreatePlayerTextDraw(playerid, 599.000000, 367.000000, "_");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][11], 0);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][11], 0.583333, 1.700002);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][11], 297.000000, 30.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][11], 0);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][11], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][11], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][11], 255);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][11], 135);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][11], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][11], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][11], false);

	modernSpeedometer[playerid][12] = CreatePlayerTextDraw(playerid, 524.000000, 367.000000, "A ~r~F");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][12], 2);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][12], 0.350000, 1.400000);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][12], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][12], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][12], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][12], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][12], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][12], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][12], false);

	modernSpeedometer[playerid][13] = CreatePlayerTextDraw(playerid, 540.000000, 361.000000, "0");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][13], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][13], 0.383333, 2.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][13], 240.000000, -18.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][13], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][13], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][13], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][13], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][13], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][13], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][13], false);

	modernSpeedometer[playerid][14] = CreatePlayerTextDraw(playerid, 556.000000, 361.000000, "9");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][14], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][14], 0.383333, 2.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][14], 240.000000, -18.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][14], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][14], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][14], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][14], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][14], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][14], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][14], false);

	modernSpeedometer[playerid][15] = CreatePlayerTextDraw(playerid, 572.000000, 361.000000, "1");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][15], 0.383333, 2.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][15], 240.000000, -18.500000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][15], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][15], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][15], 2);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][15], -1);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][15], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][15], 109);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][15], true);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][15], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][15], false);

	modernSpeedometer[playerid][16] = CreatePlayerTextDraw(playerid, 615.000000, 386.000000, "Luggage Trailer B");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][16], 2);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][16], 0.174998, 1.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][16], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][16], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][16], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][16], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][16], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][16], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][16], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][16], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][16], false);

	modernSpeedometer[playerid][17] = CreatePlayerTextDraw(playerid, 615.000000, 399.000000, "100 Litros");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][17], 2);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][17], 0.204165, 1.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][17], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][17], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][17], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][17], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][17], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][17], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][17], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][17], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][17], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][17], false);

	modernSpeedometer[playerid][18] = CreatePlayerTextDraw(playerid, 615.000000, 414.000000, "100%");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][18], 2);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][18], 0.204165, 1.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][18], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][18], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][18], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][18], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][18], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][18], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][18], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][18], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][18], false);

	modernSpeedometer[playerid][19] = CreatePlayerTextDraw(playerid, 615.000000, 428.000000, "100%");
	PlayerTextDrawFont(playerid, modernSpeedometer[playerid][19], 2);
	PlayerTextDrawLetterSize(playerid, modernSpeedometer[playerid][19], 0.204165, 1.049999);
	PlayerTextDrawTextSize(playerid, modernSpeedometer[playerid][19], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, modernSpeedometer[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, modernSpeedometer[playerid][19], 0);
	PlayerTextDrawAlignment(playerid, modernSpeedometer[playerid][19], 3);
	PlayerTextDrawColor(playerid, modernSpeedometer[playerid][19], -741092353);
	PlayerTextDrawBackgroundColor(playerid, modernSpeedometer[playerid][19], 50);
	PlayerTextDrawBoxColor(playerid, modernSpeedometer[playerid][19], 50);
	PlayerTextDrawUseBox(playerid, modernSpeedometer[playerid][19], false);
	PlayerTextDrawSetProportional(playerid, modernSpeedometer[playerid][19], true);
	PlayerTextDrawSetSelectable(playerid, modernSpeedometer[playerid][19], false);

    // Compact
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

hook OnPlayerDisconnect(playerid, reason)
{
    HidePlayerSpeedometer(playerid);
    DestroyPlayerSpeedometer(playerid);
	return 1;
}