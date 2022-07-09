#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_CAR_ROUTES              21
#define PLAYER_FINISH_DRIVING_TEST  -2045.0015,-126.8082,-50.9141

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:gsInDrivingTest[MAX_PLAYERS];
static gsSpeedWarnings[MAX_PLAYERS];
static gsActualTestCheckpoint[MAX_PLAYERS];
static gsMaxSpeedTest[MAX_PLAYERS];
static gsDriveSchoolTimeToFinish[MAX_PLAYERS];
static Timer:gsDriveSchoolTimer[MAX_PLAYERS];

static Float:gsCarRouteTest[MAX_CAR_ROUTES][3] =
{
	{-2046.9772,-77.9667,34.7925},
    {-2060.9700,-67.6598,34.7941},
    {-2153.1096,-67.6350,34.7955},
    {-2358.8611,-68.4718,34.7827},
    {-2476.5073,-68.3897,28.8776},
    {-2498.5344,-54.6531,25.1244},
    {-2499.0696,27.7759,25.0959},
    {-2458.0232,37.5310,32.2684},
    {-2423.2832,24.7519,34.6741},
    {-2423.4658,-69.4174,34.9036},
    {-2384.7136,-72.5669,34.7875},
    {-2374.7224,-111.4151,34.7919},
    {-2309.2896,-192.3378,34.7977},
    {-2224.8447,-192.6196,34.8270},
    {-2212.3220,-272.4918,34.9445},
    {-2008.5969,-292.1440,34.9421},
    {-2004.4407,-84.1005,34.9051},
    {-2028.2327,-67.6241,34.7940},
    {-2047.3967,-83.1219,34.7897},
    {-2021.4834,-95.8088,34.7883},
    {51.6480,-288.5139,1.3810}
};

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowPlayerLicensesMenu(playerid)
{
    new stringLicenses[271 + 1];
    strcat(stringLicenses, "Licença\tCusto\tStatus\n");
    strcat(stringLicenses, (Player_GetCarLicense(playerid) > 0 ? "{FFFFFF}Carros\tR$ 1500\t{228B22}[POSSUI]\n" : "{FFFFFF}Carros\tR$ 1500\t{FF0000}[NÃO POSSUI]\n"));
    strcat(stringLicenses, (Player_GetMotorCycleLicense(playerid) > 0 ? "{FFFFFF}Motos\tR$ 1500\t{228B22}[POSSUI]\n" : "{FFFFFF}Motos\tR$ 1500\t{FF0000}[NÃO POSSUI]\n"));
    strcat(stringLicenses, (Player_GetFlyLicense(playerid) > 0 ? "{FFFFFF}Avião/Heli\tR$ 3500\t{228B22}[POSSUI]\n" : "{FFFFFF}Avião/Heli\tR$ 3500\t{FF0000}[NÃO POSSUI]\n"));
    strcat(stringLicenses, (Player_GetBoatLicense(playerid) > 0 ? "{FFFFFF}Barcos\tR$ 3000\t{228B22}[POSSUI]\n" : "{FFFFFF}Barcos\tR$ 3000\t{FF0000}[NÃO POSSUI]\n"));
    strcat(stringLicenses, (Player_GetTruckLicense(playerid) > 0 ? "{FFFFFF}Caminhão/Ônibus\tR$ 2500\t{228B22}[POSSUI]\n" : "{FFFFFF}Caminhão/Ônibus\tR$ 2500\t{FF0000}[NÃO POSSUI]\n"));
    ShowPlayerDialog(playerid, DIALOG_DRIVE_SCHOOL, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Autoescola - Habilitações", stringLicenses, "Selecionar", "Voltar");
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ResetPlayerDrivingData(playerid)
{
    gsInDrivingTest[playerid] = false;
    gsActualTestCheckpoint[playerid] = 0;
    gsSpeedWarnings[playerid] = 0;
    gsMaxSpeedTest[playerid] = 80;
    return 1;
}

static stock ResetPlayerDrivingTest(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    ResetPlayerDrivingData(playerid);
    HideDriveSchoolHud(playerid);
    DisablePlayerRaceCheckpoint(playerid);
    SetPlayerWorldCustom(playerid, DRIVING_SCHOOL_LOCALE, 0, DRIVING_SCHOOL_LOCALE);
    Streamer_UpdateEx(playerid, PLAYER_FINISH_DRIVING_TEST, 0, DRIVING_SCHOOL_LOCALE, STREAMER_TYPE_OBJECT, 3000, 1);
    SetPlayerPos(playerid, PLAYER_FINISH_DRIVING_TEST);
    if (vehicleid != INVALID_VEHICLE_ID && IsValidVehicle(vehicleid))
    {
        SetVehicleToRespawn(vehicleid);
    }
    return 1;
}

timer DriveSchoolTimer[1000](playerid, maxCp)
{
    gsDriveSchoolTimeToFinish[playerid] --;
    if (gsDriveSchoolTimeToFinish[playerid] <= 0)
    {
        if (Timer_IsRunning(gsDriveSchoolTimer[playerid]))
        {
            stop gsDriveSchoolTimer[playerid];
        }
        ResetPlayerDrivingTest(playerid);
        SendClientMessage(playerid, COLOR_LIGHTRED, "[Autoescola]: Você não finalizou o teste a tempo e por isso foi finalizado.");
    }
    else
    {
        UpdateDriveSchoolHud(playerid, gsDriveSchoolTimeToFinish[playerid], gsActualTestCheckpoint[playerid], maxCp);
    }
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    ResetPlayerDrivingData(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid)
{
    if (gsInDrivingTest[playerid])
    {
        ResetPlayerDrivingTest(playerid);
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch (dialogid)
    {
        case DIALOG_DRIVE_SCHOOL:
        {
            switch (listitem)
            {
                case 0:
                {
                    if (Player_GetCarLicense(playerid) > 0)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você já possui a habilitação dessa categoria.");
                    }
                    if (Player_GetHoursPlayed(playerid) < 1)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo uma hora de jogo para conseguir essa habilitação.");
                    }
                    if (Player_GetMoney(playerid) < 1500)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo R$ 1.500 para conseguir essa habilitação.");
                    }

                    gsInDrivingTest[playerid] = true;
                    gsActualTestCheckpoint[playerid] = 0;
                    gsDriveSchoolTimeToFinish[playerid] = 300;
                    SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 1500));
                    SetPlayerWorldCustom(playerid, 0, DRIVE_SCHOOL_VEHICLES_WORLD, NO_INTERIOR);
                    SetPlayerPos(playerid,-2067.2366,-92.3412,35.1641);
                    SetPlayerRaceCheckpoint(playerid, 0, gsCarRouteTest[gsActualTestCheckpoint[playerid]][0], gsCarRouteTest[gsActualTestCheckpoint[playerid]][1], gsCarRouteTest[gsActualTestCheckpoint[playerid]][2],gsCarRouteTest[(gsActualTestCheckpoint[playerid] + 1)][0], gsCarRouteTest[(gsActualTestCheckpoint[playerid] + 1)][1], gsCarRouteTest[(gsActualTestCheckpoint[playerid] + 1)][2], 2.0);
                    GameTextForPlayer(playerid,"~r~siga as marcas vermelhas. ~n~ va devagar e nao bata !", 5000, 1);
                    SendClientMessage(playerid, COLOR_DARKGREEN, "Você pagou para iniciar o teste para conseguir sua licença de carro.");
                    SendClientMessage(playerid, COLOR_DARKGREEN, "O limite de velocidade é de 80 km/h, não ultrapasse e não bata em nada !");
                    if (Timer_IsRunning(gsDriveSchoolTimer[playerid]))
                    {
                        stop gsDriveSchoolTimer[playerid];
                    }
                    gsDriveSchoolTimer[playerid] = repeat DriveSchoolTimer(playerid, MAX_CAR_ROUTES);
                    ShowDriveSchoolHud(playerid);
                }
            }
        }
    }
    return 1;
}

hook OnPlayerEnterRaceCP(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid), Float:vehicleHealth, Float:playerX, Float:playerY, Float:playerZ;
    GetPlayerPos(playerid, playerX, playerY, playerZ);
    GetVehicleHealth(vehicleid, vehicleHealth);
    if (gsInDrivingTest[playerid])
    {
        if (!IsPlayerInVehicle(playerid, vehicleid) || GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		{
	   		SendClientMessage(playerid, COLOR_INVALID, "Você deve estar em um carro da auto escola para fazer o teste !");
	   		SendClientMessage(playerid, COLOR_INVALID, "Pegue um dos carros que estão ao seu lado e siga os checkpoints !");
	   		return 1;
	 	}
        if (vehicleHealth < 980.0)
        {
            ResetPlayerDrivingTest(playerid);
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Autoescola]: Você perdeu o teste por bater com o veículo, tente novamente e tenha cautela.");
            return 1;
        }

        if (GetVehicleSpeed(vehicleid) > gsMaxSpeedTest[playerid])
        {
            if (gsSpeedWarnings[playerid] >= 3)
            {
                ResetPlayerDrivingTest(playerid);
                SendClientMessage(playerid, COLOR_LIGHTRED, "[Autoescola]: Você perdeu o teste por excesso de velocidade, tente novamente e vá mais devagar.");
                return 1;
            }
            gsSpeedWarnings[playerid] += 1;
            SendClientMessage(playerid, COLOR_LIGHTRED, "[Autoescola]: Limite de velocidade excedido, vai perder o teste, vá mais devagar.");
        }

        if (gsActualTestCheckpoint[playerid] < (MAX_CAR_ROUTES - 1))
        {
            DisablePlayerRaceCheckpoint(playerid);
            gsActualTestCheckpoint[playerid] += 1;
            SetPlayerRaceCheckpoint(playerid, (gsActualTestCheckpoint[playerid] < (MAX_CAR_ROUTES - 1) ? 0 : 1), gsCarRouteTest[(gsActualTestCheckpoint[playerid] - 1)][0], gsCarRouteTest[(gsActualTestCheckpoint[playerid] - 1)][1], gsCarRouteTest[(gsActualTestCheckpoint[playerid] - 1)][2],gsCarRouteTest[gsActualTestCheckpoint[playerid]][0], gsCarRouteTest[gsActualTestCheckpoint[playerid]][1], gsCarRouteTest[gsActualTestCheckpoint[playerid]][2], 2.0);
            PlayerPlaySound(playerid, 1058, playerX, playerY, playerZ);
            return 1;
        }
        else
        {
            Player_SetCarLicense(playerid, 100);
            Player_SaveLicensesData(playerid);
            ResetPlayerDrivingTest(playerid);
			ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Autoescola", "{00bfff}Você foi aprovado!\n\n{FFFFFF}Você concluiu o percuso e conseguiu o direito de conduzir {848484}Carros{FFFFFF}!\n\nPara ver as suas licenças atuais, digite {848484}/minhaslicencas{FFFFFF}!", "Fechar", "");
            return 1;
        }
    }
    return 1;
}

hook OnPlayerPressF(playerid)
{
	if (IsPlayerInRangeOfPoint(playerid, 2.0, LICENSES_MENU_PICKUP))
    {
        ShowPlayerLicensesMenu(playerid);
    }
	return 1;
}

YCMD:licencas(playerid, params[], help)
{
	if (!IsPlayerInRangeOfPoint(playerid, 2.0, LICENSES_MENU_PICKUP))
	{
        return 1;
	}

    ShowPlayerLicensesMenu(playerid);
 	return 1;
}
