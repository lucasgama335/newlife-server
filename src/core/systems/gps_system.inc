#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_GPS_STRING          35
#define	MAX_CITY_NAME 		    26

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum g_GPS_INFO
{
    g_GPS_NAME[MAX_GPS_STRING],
    Float:g_GPS_POSX,
    Float:g_GPS_POSY,
    Float:g_GPS_POSZ
};

static gsGpsGeneral[][g_GPS_INFO] = 
{
	{ "Spawn Civil", SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ },
	{ "Prefeitura", 1481.0397, -1772.3135, 18.7958 },
	{ "Autoescola", 1081.1952, -1696.7833, 13.5469 },
	{ "Banco", 1462.3101, -1010.2200, 26.8438 },
	{ "Penitenciária", 1684.4442, -1343.3179, 17.4371 },
	{ "Aeroporto", 2073.4792, -2625.5288, 13.5469 },
	{ "Igreja", 2233.9839, -1333.3507, 23.9816 },
	{ "Estação de Trem", 1689.4321, -1974.5238, 8.8254 }
};

static gsGpsGasStations[][g_GPS_INFO] =
{
	{ "Temple", 1004.1940, -938.8609, 41.6993 }, 
	{ "Idlewood", 1943.0713, -1773.3390, 12.9102 }, 	
	{ "Flint Country", -90.1840, -1168.4058, 1.9309 }, 
	{ "Whetstone", -1606.0424, -2714.0076, 48.3125 }, 
	{ "Doherty", -2029.1658, 156.0342, 28.6148 }, 
	{ "Juniper Hollow", -2407.5515, 975.6099, 45.0734 }, 
	{ "Dillimore", 653.7080, -565.2718, 15.8557 }, 
	{ "Las Venturas", 2639.4431, 1106.2423, 10.3400 }, 
	{ "Redsands West", 1596.8387, 2199.4241, 10.3403 }, 
	{ "Montgomery", 1381.6135, 462.4037, 19.6371 }, 
	{ "Angel Pine", -2244.1870, -2560.7693, 31.7042 }, 
	{ "Easter Basin", -1677.9578, 412.3029, 6.9577 }, 
	{ "The Emerald Isle", 2201.9709, 2474.0715, 10.3404 }, 
	{ "Bone County", 615.2600, 1689.7572, 6.5119 }, 
	{ "Spinybed", 2147.7349, 2747.9778, 10.3396 }, 
	{ "Tierra Robada", -1329.0188, 2677.2068, 49.5827 }, 
	{ "Bone County 2", 70.2734, 1218.8157, 18.3315 }, 
	{ "Las Venturas 2", 2113.7642, 919.8799, 10.3402 }
};

static gsGpsJobs[][g_GPS_INFO] = 
{
	{ "Lixeiros",2194.0466, -1970.0131, 13.7841 },
	{ "Caminhoneiros", -74.3430, -1136.1361, 1.0781 },
	{ "Taxistas", 583.7798, -1496.8689, 15.3653 },
	{ "Advogados", 1153.9293, -1772.6785, 16.5992 },
	{ "Coveiros", 831.5405, -1095.4967, 24.2969 },
	{ "Mineradores", 2400.9707, -1504.3239, 1402.2000 },
	{ "Socorristas", 2038.0348, -1404.6837, 17.2531 },
	{ "Eletricistas", 793.8623, -613.7773, 16.3359 },
	{ "Motoristas de Ônibus", 1802.6227, -2352.5845, 13.5261 },
	{ "Fazendeiros", -93.6237, -26.5389, 3.1172 }
};

static gsGpsTunning[][g_GPS_INFO] = 
{
	{ "Trans Fender", 1042.7727, -1034.4984, 31.6971 },
	{ "Wheel Arch", -2709.8464, 217.6329, 3.9722 },
	{ "Low Rider", 2645.1450, -2029.4902, 13.3313 },
	{ "Trans Fender", 2386.1208, 1039.5265, 10.3404 }
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowPlayerGPSList(playerid)
{
    new stringGps[199 + 1];
 	strcat(stringGps, "{1e90ff}GPS » {FFFFFF}Locais Importantes\n");
 	strcat(stringGps, "{1e90ff}GPS » {FFFFFF}Postos de Gasolina\n");
	strcat(stringGps, "{1e90ff}GPS » {FFFFFF}HQ de Empregos\n");
	strcat(stringGps, "{1e90ff}GPS » {FFFFFF}Locais de Tunagem\n");
	strcat(stringGps, "{1e90ff}GPS » {FFFFFF}Desligar GPS\n");
	ShowPlayerDialog(playerid, DIALOG_GPS_MENU, DIALOG_STYLE_LIST, "{FFFFFF}GPS - Selecione uma opção", stringGps, "Escolher", "Cancelar");
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    switch (dialogid)
    {
        case DIALOG_GPS_MENU:
        {
            if (!response)
            {
                return 1;
            }
            if (response)
            {
                switch (listitem)
                {
                    case 0:
			        {
			            new gpsItems[((MAX_GPS_STRING + MAX_ZONE_NAME + 40) * sizeof(gsGpsGeneral))], string[(MAX_GPS_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(gpsItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsGpsGeneral); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsGpsGeneral[i][g_GPS_POSX], gsGpsGeneral[i][g_GPS_POSY], gsGpsGeneral[i][g_GPS_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsGpsGeneral[i][g_GPS_NAME], GetPlayerDistanceFromPoint(playerid, gsGpsGeneral[i][g_GPS_POSX], gsGpsGeneral[i][g_GPS_POSY], gsGpsGeneral[i][g_GPS_POSZ]), zoneName);
							strcat(gpsItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_GPS_GENERAL, DIALOG_STYLE_TABLIST_HEADERS, "Escolha um Local para Localizar no Mapa:", gpsItems, "Localizar", "Voltar");
                        return 1;
                    }
                    case 1:
			        {
			            new gpsItems[((MAX_GPS_STRING + MAX_ZONE_NAME + 40) * sizeof(gsGpsGasStations))], string[(MAX_GPS_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(gpsItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsGpsGasStations); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsGpsGasStations[i][g_GPS_POSX], gsGpsGasStations[i][g_GPS_POSY], gsGpsGasStations[i][g_GPS_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsGpsGasStations[i][g_GPS_NAME], GetPlayerDistanceFromPoint(playerid, gsGpsGasStations[i][g_GPS_POSX], gsGpsGasStations[i][g_GPS_POSY], gsGpsGasStations[i][g_GPS_POSZ]), zoneName);
							strcat(gpsItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_GPS_GASSTATION, DIALOG_STYLE_TABLIST_HEADERS, "Escolha um Posto de Gasolina para Localizar:", gpsItems, "Localizar", "Voltar");
                        return 1;
                    }
                    case 2:
			        {
			            new gpsItems[((MAX_GPS_STRING + MAX_ZONE_NAME + 40) * sizeof(gsGpsJobs))], string[(MAX_GPS_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(gpsItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsGpsJobs); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsGpsJobs[i][g_GPS_POSX], gsGpsJobs[i][g_GPS_POSY], gsGpsJobs[i][g_GPS_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsGpsJobs[i][g_GPS_NAME], GetPlayerDistanceFromPoint(playerid, gsGpsJobs[i][g_GPS_POSX], gsGpsJobs[i][g_GPS_POSY], gsGpsJobs[i][g_GPS_POSZ]), zoneName);
							strcat(gpsItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_GPS_JOBS, DIALOG_STYLE_TABLIST_HEADERS, "HQ de Empregos:", gpsItems, "Localizar", "Voltar");
                        return 1;
                    }
                    case 3:
			        {
			            new gpsItems[((MAX_GPS_STRING + MAX_ZONE_NAME + 40) * sizeof(gsGpsTunning))], string[(MAX_GPS_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(gpsItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsGpsTunning); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsGpsTunning[i][g_GPS_POSX], gsGpsTunning[i][g_GPS_POSY], gsGpsTunning[i][g_GPS_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsGpsTunning[i][g_GPS_NAME], GetPlayerDistanceFromPoint(playerid, gsGpsTunning[i][g_GPS_POSX], gsGpsTunning[i][g_GPS_POSY], gsGpsTunning[i][g_GPS_POSZ]), zoneName);
							strcat(gpsItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_GPS_TUNNINGS, DIALOG_STYLE_TABLIST_HEADERS, "Locais Para Tunagem:", gpsItems, "Localizar", "Voltar");
                        return 1;
                    }
                    case 4:
			        {
			            DisablePlayerCheckpoint(playerid);
                        return 1;
                    }
                }
            }
        }

        case DIALOG_GPS_GENERAL:
		{
			if (!response) 
			{
				return ShowPlayerGPSList(playerid);
			}
			if (response)
			{
				if (listitem < 0 || listitem > sizeof(gsGpsGeneral))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "Item inválido.");
				}
				new string[(42 + MAX_GPS_STRING + 1)];
				SetPlayerCheckpoint(playerid, gsGpsGeneral[listitem][g_GPS_POSX], gsGpsGeneral[listitem][g_GPS_POSY], gsGpsGeneral[listitem][g_GPS_POSZ], 5.0);
				format(string, sizeof(string), "[GPS]: Localização do(a) %s marcada no mapa.", gsGpsGeneral[listitem][g_GPS_NAME]);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
				return 1;
			}
		}
        case DIALOG_GPS_GASSTATION:
		{
			if (!response) 
			{
				return ShowPlayerGPSList(playerid);
			}
			if (response)
			{
				if (listitem < 0 || listitem > sizeof(gsGpsGasStations))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "Item inválido.");
				}
				new string[(42 + MAX_GPS_STRING + 1)];
				SetPlayerCheckpoint(playerid, gsGpsGasStations[listitem][g_GPS_POSX], gsGpsGasStations[listitem][g_GPS_POSY], gsGpsGasStations[listitem][g_GPS_POSZ], 5.0);
				format(string, sizeof(string), "[GPS]: Localização do(a) %s marcada no mapa.", gsGpsGasStations[listitem][g_GPS_NAME]);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
				return 1;
			}
		}

		case DIALOG_GPS_JOBS:
		{
			if (!response) 
			{
				return ShowPlayerGPSList(playerid);
			}
			if (response)
			{
				if (listitem < 0 || listitem > sizeof(gsGpsJobs))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "Item inválido.");
				}
				new string[(42 + MAX_GPS_STRING + 1)];
				SetPlayerCheckpoint(playerid, gsGpsJobs[listitem][g_GPS_POSX], gsGpsJobs[listitem][g_GPS_POSY], gsGpsJobs[listitem][g_GPS_POSZ], 5.0);
				format(string, sizeof(string), "[GPS]: Localização do(a) %s marcada no mapa.", gsGpsJobs[listitem][g_GPS_NAME]);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
				return 1;
			}
		}

		case DIALOG_GPS_TUNNINGS:
		{
			if (!response) 
			{
				return ShowPlayerGPSList(playerid);
			}
			if (response)
			{
				if (listitem < 0 || listitem > sizeof(gsGpsTunning))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "Item inválido.");
				}
				new string[(42 + MAX_GPS_STRING + 1)];
				SetPlayerCheckpoint(playerid, gsGpsTunning[listitem][g_GPS_POSX], gsGpsTunning[listitem][g_GPS_POSY], gsGpsTunning[listitem][g_GPS_POSZ], 5.0);
				format(string, sizeof(string), "[GPS]: Localização do(a) %s marcada no mapa.", gsGpsTunning[listitem][g_GPS_NAME]);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
				return 1;
			}
		}
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:gps(playerid, params[], help)
{
    ShowPlayerGPSList(playerid);
    return 1;
}
