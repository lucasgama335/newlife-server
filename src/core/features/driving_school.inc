#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_CAR_ROUTES                     21
#define MAX_MOTORCYCLE_ROUTES              21
#define MAX_FLY_ROUTES                     21
#define MAX_BOAT_ROUTES                    21
#define MAX_TRUCK_ROUTES                   21

#define PLAYER_FINISH_DRIVING_TEST  -2045.0015,-126.8082,-50.9141

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum e_DRIVING_TEST_TYPE
{
    e_DRIVING_TEST_CAR,
    e_DRIVING_TEST_MOTORCYCLE,
    e_DRIVING_TEST_FLY,
    e_DRIVING_TEST_BOAT,
    e_DRIVING_TEST_TRUCK
};
static e_DRIVING_TEST_TYPE:gsDrivingTestType[MAX_PLAYERS];
static bool:gsInDrivingTest[MAX_PLAYERS];
static gsSpeedWarnings[MAX_PLAYERS];
static gsActualTestCheckpoint[MAX_PLAYERS];
static gsMaxTestCheckpoints[MAX_PLAYERS];
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

static Float:gsMotorcycleRouteTest[MAX_MOTORCYCLE_ROUTES][3] =
{
    {1560.4677,13.2436,23.7764},
    {1560.7620,-36.9327,20.8891},
    {1519.0648,-183.7245,12.9714},
    {1335.9156,-203.0193,12.2131},
    {1228.1044,-119.3333,39.0134},
    {1059.9398,-65.3310,21.1299},
    {882.5222,-91.7373,24.7512},
    {781.4462,-132.3094,21.3523},
    {720.3601,-181.0635,20.7983},
    {640.9004,-197.2512,10.4846},
    {546.3196,-205.4138,16.4986},
    {496.0143,-242.2961,10.5759},
    {420.5088,-301.8568,6.9928},
    {316.2517,-362.7825,9.1974},
	{239.5094,-365.4566,7.8820},
    {209.6873,-325.9982,1.7630},
    {193.2257,-319.3530,1.2431},
    {113.3479,-259.9463,3.8264},
    {86.5635,-240.3654,3.1892},
    {51.6480,-288.5139,1.3810},
    {51.6480,-288.5139,1.3810}
};

static Float:gsFlyRouteTest[MAX_FLY_ROUTES][3] =
{
	{-1140.2377,-202.6676,34.5903},
    {-1197.1805,-280.7894,70.8384},
    {-1318.1147,-436.5503,87.4385},
    {-1532.9528,-692.0680,76.8711},
    {-1466.3580,-721.4468,5.4534},
    {-1359.8680,-715.3929,34.3193},
    {-1249.2345,-587.7202,15.1328},
    {-1235.2638,-551.5889,47.5750},
    {-1207.7776,-474.9858,19.4642},
    {-1185.5791,-423.2551,62.7526},
    {-1125.5605,-375.5390,67.3093},
    {-1040.4260,-382.8862,22.0585},
    {-1001.5632,-379.9551,11.1214},
    {-970.3692,-375.8177,7.9073},
    {-870.0438,-350.6096,17.4316},
    {-852.5836,-327.5564,25.5227},
    {-901.6478,-314.1163,13.6021},
    {-948.4770,-302.1930,8.8934},
    {-1058.2053,-267.7317,25.4300},
    {-1148.1313,-228.3088,14.1484},
    {-1148.1313,-228.3088,14.1484}
};

static Float:gsBoatRouteTest[MAX_BOAT_ROUTES][3] =
{
	{2589.8076,-2271.3611,-0.4046},
    {2535.3735,-2286.9724,-0.4574},
    {2430.7256,-2300.5454,-0.6902},
    {2356.3123,-2415.5417,-0.7410},
    {2348.9153,-2539.3254,-0.2581},
    {2325.2671,-2676.3938,-0.0274},
    {2174.1675,-2806.5137,-0.2222},
    {1799.5547,-2952.1423,-0.1172},
    {1481.0419,-2888.7302,-0.1687},
    {1165.3700,-2638.5776,-0.6791},
    {970.2130,-2391.7478,-0.5942},
    {905.5760,-2111.8318,-0.3734},
    {848.3631,-2058.7734,-0.6418},
    {825.3781,-2046.4331,-0.3769},
    {806.9658,-2025.1932,-0.4533},
    {825.9057,-1991.2635,-0.3576},
    {845.1941,-1976.4280,-0.5485},
    {839.2659,-1950.9290,-0.5719},
    {719.9696,-1703.2461,-0.5332},
    {727.1500,-1588.2313,-0.5516},
    {727.1500,-1588.2313,-0.5516}
};

static Float:gsTruckRouteTest[MAX_TRUCK_ROUTES][3] =
{
	{-2134.2053,-68.2868,36.1011},
    {-2170.6733,-86.0141,36.1002},
    {-2239.2205,-188.1835,36.1021},
    {-2260.4023,-266.8860,43.7943},
    {-1998.0717,-584.3029,26.6627},
    {-1820.2283,-599.0458,17.2184},
    {-1553.6440,-1449.5262,41.1091},
    {-1711.3805,-1090.8777,74.7628},
    {-1639.9174,-819.7148,93.5173},
    {-1441.1177,-1380.6744,101.9508},
    {-1206.4491,-1347.6797,124.5314},
    {-930.9775,-1408.9612,128.9607},
    {-831.1804,-1573.1698,127.8495},
    {-886.8446,-1625.6841,105.7189},
    {-961.2309,-1653.7246,76.0580},
    {-978.7487,-1720.8147,78.5095},
    {-1033.4119,-1661.5125,78.4922},
    {-1073.5095,-1647.8456,77.1647},
    {-1083.7719,-1623.3540,77.3871},
    {-1117.2954,-1620.1775,76.3739},
    {-1117.2954,-1620.1775,76.3739}
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
    gsMaxTestCheckpoints[playerid] = 0;
    gsSpeedWarnings[playerid] = 0;
    gsMaxSpeedTest[playerid] = 80;
    gsDrivingTestType[playerid] = e_DRIVING_TEST_CAR;
    return 1;
}

static stock ResetPlayerDrivingTest(playerid, bool:updatePos = true)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    ResetPlayerDrivingData(playerid);
    HideDriveSchoolHud(playerid);
    DisablePlayerRaceCheckpoint(playerid);
    if (updatePos)
    {
        SetPlayerWorldCustom(playerid, DRIVING_SCHOOL_LOCALE, 0, DRIVING_SCHOOL_LOCALE);
        Streamer_UpdateEx(playerid, PLAYER_FINISH_DRIVING_TEST, 0, DRIVING_SCHOOL_LOCALE, STREAMER_TYPE_OBJECT, 3000, 1);
        SetPlayerPos(playerid, PLAYER_FINISH_DRIVING_TEST);
    }
    if (vehicleid != INVALID_VEHICLE_ID && IsValidVehicle(vehicleid))
    {
        SetVehicleToRespawn(vehicleid);
    }
    if (Timer_IsRunning(gsDriveSchoolTimer[playerid]))
    {
        stop gsDriveSchoolTimer[playerid];
    }
    return 1;
}

timer DriveSchoolTimer[1000](playerid, maxCp)
{
    gsDriveSchoolTimeToFinish[playerid] --;
    if (gsDriveSchoolTimeToFinish[playerid] <= 0)
    {
        ResetPlayerDrivingTest(playerid);
        SendClientMessage(playerid, COLOR_LIGHTRED, "[Autoescola]: Você não finalizou o teste a tempo e por isso foi finalizado.");
    }
    else
    {
        UpdateDriveSchoolHud(playerid, gsDriveSchoolTimeToFinish[playerid], gsActualTestCheckpoint[playerid], (maxCp - 1));
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

hook OnPlayerDeath(playerid)
{
    if (gsInDrivingTest[playerid])
    {
        ResetPlayerDrivingTest(playerid, false);
        SendClientMessage(playerid, COLOR_LIGHTRED, "[Autoescola]: Você morreu durante o teste de habilitação e por isso o teste foi cancelado.");
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
                    gsMaxTestCheckpoints[playerid] = (MAX_CAR_ROUTES - 1);
                    gsDriveSchoolTimeToFinish[playerid] = 300;
                    gsMaxSpeedTest[playerid] = 80;
                    gsDrivingTestType[playerid] = e_DRIVING_TEST_CAR;
                    SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 1500));
                    SetPlayerWorldCustom(playerid, 0, DRIVE_SCHOOL_VEHICLES_WORLD, NO_INTERIOR);
                    SetPlayerPos(playerid, -2067.2366, -92.3412, 35.1641);
                    SetPlayerRaceCheckpoint(playerid, 0, gsCarRouteTest[gsActualTestCheckpoint[playerid]][0], gsCarRouteTest[gsActualTestCheckpoint[playerid]][1], gsCarRouteTest[gsActualTestCheckpoint[playerid]][2], gsCarRouteTest[(gsActualTestCheckpoint[playerid] + 1)][0], gsCarRouteTest[(gsActualTestCheckpoint[playerid] + 1)][1], gsCarRouteTest[(gsActualTestCheckpoint[playerid] + 1)][2], 2.0);
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
                case 1:
                {
                    if (Player_GetMotorCycleLicense(playerid) > 0)
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
                    gsMaxTestCheckpoints[playerid] = (MAX_MOTORCYCLE_ROUTES - 1);
                    gsDriveSchoolTimeToFinish[playerid] = 300;
                    gsMaxSpeedTest[playerid] = 100;
                    gsDrivingTestType[playerid] = e_DRIVING_TEST_MOTORCYCLE;
                    SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 1500));
                    SetPlayerWorldCustom(playerid, 0, DRIVE_SCHOOL_MOTORCYCLE_WORLD, NO_INTERIOR);
                    SetPlayerPos(playerid, 1546.6271, 20.8116, 24.1406);
                    SetPlayerRaceCheckpoint(playerid, 0, gsMotorcycleRouteTest[gsActualTestCheckpoint[playerid]][0], gsMotorcycleRouteTest[gsActualTestCheckpoint[playerid]][1], gsMotorcycleRouteTest[gsActualTestCheckpoint[playerid]][2], gsMotorcycleRouteTest[(gsActualTestCheckpoint[playerid] + 1)][0], gsMotorcycleRouteTest[(gsActualTestCheckpoint[playerid] + 1)][1], gsMotorcycleRouteTest[(gsActualTestCheckpoint[playerid] + 1)][2], 2.0);
                    GameTextForPlayer(playerid,"~r~siga as marcas vermelhas. ~n~ va devagar e nao bata !", 5000, 1);
                    SendClientMessage(playerid, COLOR_DARKGREEN, "Você pagou para iniciar o teste para conseguir sua licença de carro.");
                    SendClientMessage(playerid, COLOR_DARKGREEN, "O limite de velocidade é de 100 km/h, não ultrapasse e não bata em nada !");
                    if (Timer_IsRunning(gsDriveSchoolTimer[playerid]))
                    {
                        stop gsDriveSchoolTimer[playerid];
                    }
                    gsDriveSchoolTimer[playerid] = repeat DriveSchoolTimer(playerid, MAX_CAR_ROUTES);
                    ShowDriveSchoolHud(playerid);
                }
                case 2:
                {
                    if (Player_GetFlyLicense(playerid) > 0)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você já possui a habilitação dessa categoria.");
                    }
                    if (Player_GetHoursPlayed(playerid) < 1)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo uma hora de jogo para conseguir essa habilitação.");
                    }
                    if (Player_GetMoney(playerid) < 3500)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo R$ 3.500 para conseguir essa habilitação.");
                    }

                    gsInDrivingTest[playerid] = true;
                    gsActualTestCheckpoint[playerid] = 0;
                    gsMaxTestCheckpoints[playerid] = (MAX_FLY_ROUTES - 1);
                    gsDriveSchoolTimeToFinish[playerid] = 420;
                    gsMaxSpeedTest[playerid] = 100;
                    gsDrivingTestType[playerid] = e_DRIVING_TEST_FLY;
                    SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 3500));
                    SetPlayerWorldCustom(playerid, 0, DRIVE_SCHOOL_FLY_WORLD, NO_INTERIOR);
                    SetPlayerPos(playerid,-1108.5317, -209.0739, 14.1440);
                    SetPlayerRaceCheckpoint(playerid, 4, gsFlyRouteTest[gsActualTestCheckpoint[playerid]][0], gsFlyRouteTest[gsActualTestCheckpoint[playerid]][1], gsFlyRouteTest[gsActualTestCheckpoint[playerid]][2], gsFlyRouteTest[(gsActualTestCheckpoint[playerid] + 1)][0], gsFlyRouteTest[(gsActualTestCheckpoint[playerid] + 1)][1], gsFlyRouteTest[(gsActualTestCheckpoint[playerid] + 1)][2], 4.0);
                    GameTextForPlayer(playerid,"~r~siga as marcas vermelhas. ~n~ va devagar e nao bata !", 5000, 1);
                    SendClientMessage(playerid, COLOR_DARKGREEN, "Você pagou para iniciar o teste para conseguir sua licença de carro.");
                    SendClientMessage(playerid, COLOR_DARKGREEN, "O limite de velocidade é de 100 km/h, não ultrapasse e não bata em nada !");
                    if (Timer_IsRunning(gsDriveSchoolTimer[playerid]))
                    {
                        stop gsDriveSchoolTimer[playerid];
                    }
                    gsDriveSchoolTimer[playerid] = repeat DriveSchoolTimer(playerid, MAX_CAR_ROUTES);
                    ShowDriveSchoolHud(playerid);
                }
                case 3:
                {
                    if (Player_GetBoatLicense(playerid) > 0)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você já possui a habilitação dessa categoria.");
                    }
                    if (Player_GetHoursPlayed(playerid) < 1)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo uma hora de jogo para conseguir essa habilitação.");
                    }
                    if (Player_GetMoney(playerid) < 3000)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo R$ 3.000 para conseguir essa habilitação.");
                    }

                    gsInDrivingTest[playerid] = true;
                    gsActualTestCheckpoint[playerid] = 0;
                    gsMaxTestCheckpoints[playerid] = (MAX_BOAT_ROUTES - 1);
                    gsDriveSchoolTimeToFinish[playerid] = 300;
                    gsMaxSpeedTest[playerid] = 150;
                    gsDrivingTestType[playerid] = e_DRIVING_TEST_BOAT;
                    SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 3000));
                    SetPlayerWorldCustom(playerid, 0, DRIVE_SCHOOL_BOAT_WORLD, NO_INTERIOR);
                    SetPlayerPos(playerid, 2577.2090, -2202.4290, -0.2188);
                    SetPlayerRaceCheckpoint(playerid, 0, gsBoatRouteTest[gsActualTestCheckpoint[playerid]][0], gsBoatRouteTest[gsActualTestCheckpoint[playerid]][1], gsBoatRouteTest[gsActualTestCheckpoint[playerid]][2], gsBoatRouteTest[(gsActualTestCheckpoint[playerid] + 1)][0], gsBoatRouteTest[(gsActualTestCheckpoint[playerid] + 1)][1], gsBoatRouteTest[(gsActualTestCheckpoint[playerid] + 1)][2], 4.0);
                    GameTextForPlayer(playerid,"~r~siga as marcas vermelhas. ~n~ va devagar e nao bata !", 5000, 1);
                    SendClientMessage(playerid, COLOR_DARKGREEN, "Você pagou para iniciar o teste para conseguir sua licença de carro.");
                    SendClientMessage(playerid, COLOR_DARKGREEN, "O limite de velocidade é de 150 km/h, não ultrapasse e não bata em nada !");
                    if (Timer_IsRunning(gsDriveSchoolTimer[playerid]))
                    {
                        stop gsDriveSchoolTimer[playerid];
                    }
                    gsDriveSchoolTimer[playerid] = repeat DriveSchoolTimer(playerid, MAX_CAR_ROUTES);
                    ShowDriveSchoolHud(playerid);
                }
                case 4:
                {
                    if (Player_GetTruckLicense(playerid) > 0)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você já possui a habilitação dessa categoria.");
                    }
                    if (Player_GetHoursPlayed(playerid) < 1)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo uma hora de jogo para conseguir essa habilitação.");
                    }
                    if (Player_GetMoney(playerid) < 2500)
                    {
                        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa ter no mínimo R$ 2.500 para conseguir essa habilitação.");
                    }

                    gsInDrivingTest[playerid] = true;
                    gsActualTestCheckpoint[playerid] = 0;
                    gsMaxTestCheckpoints[playerid] = (MAX_TRUCK_ROUTES - 1);
                    gsDriveSchoolTimeToFinish[playerid] = 300;
                    gsMaxSpeedTest[playerid] = 90;
                    gsDrivingTestType[playerid] = e_DRIVING_TEST_TRUCK;
                    SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 2500));
                    SetPlayerWorldCustom(playerid, 0, DRIVE_SCHOOL_TRUCK_WORLD, NO_INTERIOR);
                    SetPlayerPos(playerid, -2137.1187, -248.2467, 36.5156);
                    SetPlayerRaceCheckpoint(playerid, 0, gsTruckRouteTest[gsActualTestCheckpoint[playerid]][0], gsTruckRouteTest[gsActualTestCheckpoint[playerid]][1], gsTruckRouteTest[gsActualTestCheckpoint[playerid]][2], gsTruckRouteTest[(gsActualTestCheckpoint[playerid] + 1)][0], gsTruckRouteTest[(gsActualTestCheckpoint[playerid] + 1)][1], gsTruckRouteTest[(gsActualTestCheckpoint[playerid] + 1)][2], 4.0);
                    GameTextForPlayer(playerid,"~r~siga as marcas vermelhas. ~n~ va devagar e nao bata !", 5000, 1);
                    SendClientMessage(playerid, COLOR_DARKGREEN, "Você pagou para iniciar o teste para conseguir sua licença de carro.");
                    SendClientMessage(playerid, COLOR_DARKGREEN, "O limite de velocidade é de 90 km/h, não ultrapasse e não bata em nada !");
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

        if (gsActualTestCheckpoint[playerid] >= (gsMaxTestCheckpoints[playerid] - 1))
        {
            switch (gsDrivingTestType[playerid])
            {
                case e_DRIVING_TEST_CAR: 
                {
                    Player_SetCarLicense(playerid, 80);
			        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Autoescola", "{00bfff}Você foi aprovado!\n\n{FFFFFF}Você concluiu o percuso e conseguiu o direito de conduzir {848484}Carros{FFFFFF}!\n\nPara ver as suas licenças atuais, digite {848484}/minhaslicencas{FFFFFF}!", "Fechar", "");
                }
                case e_DRIVING_TEST_MOTORCYCLE: 
                {
                    Player_SetMotorCycleLicense(playerid, 70);
			        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Autoescola", "{00bfff}Você foi aprovado!\n\n{FFFFFF}Você concluiu o percuso e conseguiu o direito de conduzir {848484}Motos{FFFFFF}!\n\nPara ver as suas licenças atuais, digite {848484}/minhaslicencas{FFFFFF}!", "Fechar", "");
                }
                case e_DRIVING_TEST_FLY: 
                {
                    Player_SetFlyLicense(playerid, 110);
			        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Autoescola", "{00bfff}Você foi aprovado!\n\n{FFFFFF}Você concluiu o percuso e conseguiu o direito de conduzir {848484}Aviões e/ou Helicópteros{FFFFFF}!\n\nPara ver as suas licenças atuais, digite {848484}/minhaslicencas{FFFFFF}!", "Fechar", "");
                }
                case e_DRIVING_TEST_BOAT: 
                {
                    Player_SetBoatLicense(playerid, 90);
			        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Autoescola", "{00bfff}Você foi aprovado!\n\n{FFFFFF}Você concluiu o percuso e conseguiu o direito de conduzir {848484}Barcos{FFFFFF}!\n\nPara ver as suas licenças atuais, digite {848484}/minhaslicencas{FFFFFF}!", "Fechar", "");
                }
                case e_DRIVING_TEST_TRUCK: 
                {
                    Player_SetTruckLicense(playerid, 100);
			        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Autoescola", "{00bfff}Você foi aprovado!\n\n{FFFFFF}Você concluiu o percuso e conseguiu o direito de conduzir {848484}Caminhões e/ou Ônibus{FFFFFF}!\n\nPara ver as suas licenças atuais, digite {848484}/minhaslicencas{FFFFFF}!", "Fechar", "");
                }
            }
            Player_SaveLicensesData(playerid);
            ResetPlayerDrivingTest(playerid);
            return 1;
        }
        new actualCp = (gsActualTestCheckpoint[playerid] + 1), nextCp = (gsActualTestCheckpoint[playerid] + 2);
        DisablePlayerRaceCheckpoint(playerid);
        switch (gsDrivingTestType[playerid])
        {
            case e_DRIVING_TEST_CAR: SetPlayerRaceCheckpoint(playerid, (gsActualTestCheckpoint[playerid] < (gsMaxTestCheckpoints[playerid] - 2) ? 0 : 1), gsCarRouteTest[actualCp][0], gsCarRouteTest[actualCp][1], gsCarRouteTest[actualCp][2], gsCarRouteTest[nextCp][0], gsCarRouteTest[nextCp][1], gsCarRouteTest[nextCp][2], 2.0);
            case e_DRIVING_TEST_MOTORCYCLE: SetPlayerRaceCheckpoint(playerid, (gsActualTestCheckpoint[playerid] < (gsMaxTestCheckpoints[playerid] - 2) ? 0 : 1), gsMotorcycleRouteTest[actualCp][0], gsMotorcycleRouteTest[actualCp][1], gsMotorcycleRouteTest[actualCp][2], gsMotorcycleRouteTest[nextCp][0], gsMotorcycleRouteTest[nextCp][1], gsMotorcycleRouteTest[nextCp][2], 2.0);
            case e_DRIVING_TEST_FLY: SetPlayerRaceCheckpoint(playerid, (gsActualTestCheckpoint[playerid] < (gsMaxTestCheckpoints[playerid] - 2) ? 4 : 1), gsFlyRouteTest[actualCp][0], gsFlyRouteTest[actualCp][1], gsFlyRouteTest[actualCp][2], gsFlyRouteTest[nextCp][0], gsFlyRouteTest[nextCp][1], gsFlyRouteTest[nextCp][2], 4.0);
            case e_DRIVING_TEST_BOAT: SetPlayerRaceCheckpoint(playerid, (gsActualTestCheckpoint[playerid] < (gsMaxTestCheckpoints[playerid] - 2) ? 0 : 1), gsBoatRouteTest[actualCp][0], gsBoatRouteTest[actualCp][1], gsBoatRouteTest[actualCp][2], gsBoatRouteTest[nextCp][0], gsBoatRouteTest[nextCp][1], gsBoatRouteTest[nextCp][2], 4.0);
            case e_DRIVING_TEST_TRUCK: SetPlayerRaceCheckpoint(playerid, (gsActualTestCheckpoint[playerid] < (gsMaxTestCheckpoints[playerid] - 2) ? 0 : 1), gsTruckRouteTest[actualCp][0], gsTruckRouteTest[actualCp][1], gsTruckRouteTest[actualCp][2], gsTruckRouteTest[nextCp][0], gsTruckRouteTest[nextCp][1], gsTruckRouteTest[nextCp][2], 4.0);
        }
        PlayerPlaySound(playerid, 1058, playerX, playerY, playerZ);
        gsActualTestCheckpoint[playerid] += 1;
        return 1;
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

hook OnPlayerUpdateScreenSize(playerid)
{
    if (gsInDrivingTest[playerid])
    {
        HideDriveSchoolHud(playerid);
        AdaptDriveSchoolHudToScreen(playerid);
        ShowDriveSchoolHud(playerid);
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
