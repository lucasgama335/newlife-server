#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_TELEPORT_STRING          35

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum t_TELEPORT_INFO
{
    t_TELEPORT_NAME[MAX_TELEPORT_STRING],
    Float:t_TELEPORT_POSX,
    Float:t_TELEPORT_POSY,
    Float:t_TELEPORT_POSZ,
    Float:t_TELEPORT_POSA
};

static gsGeneralTeleports[][t_TELEPORT_INFO] = 
{
	{ "Spawn Civil", 803.9800, -1357.7566, 13.2034, 351.4954 },
	{ "Prefeitura", 1536.9906, -1691.9696, 13.1187, 144.3588 },
	{ "Autoescola", 1083.7119, -1728.2748, 13.3157, 12.0207 },
	{ "Banco", 1466.8754, -1041.3480, 23.4014, 22.8678 },
	{ "Penitenciária",  1707.6401, -1339.7183, 13.5469, 179.5940 },
	{ "Aeroporto", 2048.0200, -2623.0063, 13.5469, 3.9104 },
	{ "Igreja", 2222.1274, -1360.2257, 23.5599, 356.5778 },
	{ "Estação de Trem", 1724.0492, -1974.6481, 13.6800, 326.9725 }
};

static gsGasStationTeleports[][t_TELEPORT_INFO] =
{
	{ "Temple", 1004.1940, -938.8609, 41.6993, 278.5006 }, 
	{ "Idlewood", 1943.0713, -1773.3390, 12.9102, 177.5726 }, 	
	{ "Flint Country", -90.1840, -1168.4058, 1.9309, 337.7906 }, 
	{ "Whetstone", -1606.0424, -2714.0076, 48.3125, 52.7881 }, 
	{ "Doherty", -2029.1658, 156.0342, 28.6148, 1.2930 }, 
	{ "Juniper Hollow", -2407.5515, 975.6099, 45.0734, 358.7534 }, 
	{ "Dillimore", 653.7080, -565.2718, 15.8557, 359.8599 }, 
	{ "Las Venturas", 2639.4431, 1106.2423, 10.3400, 269.8636 }, 
	{ "Redsands West", 1596.8387, 2199.4241, 10.3403, 89.5819 }, 
	{ "Montgomery", 1381.6135, 462.4037, 19.6371, 247.4143 }, 
	{ "Angel Pine", -2244.1870, -2560.7693, 31.7042, 333.5291 }, 
	{ "Easter Basin", -1677.9578, 412.3029, 6.9577, 314.0307 }, 
	{ "The Emerald Isle", 2201.9709, 2474.0715, 10.3404, 0.0137 }, 
	{ "Bone County", 615.2600, 1689.7572, 6.5119, 122.9244 }, 
	{ "Spinybed", 2147.7349, 2747.9778, 10.3396, 269.1475 }, 
	{ "Tierra Robada", -1329.0188, 2677.2068, 49.5827, 84.4416 }, 
	{ "Bone County 2", 70.2734, 1218.8157, 18.3315, 347.2281 }, 
	{ "Las Venturas 2", 2113.7642, 919.8799, 10.3402, 88.3859 }
};

static gsJobsTeleports[][t_TELEPORT_INFO] = 
{
	{ "Lixeiros", 2144.1885, -1977.4357, 13.5546, 264.6851 },
	{ "Caminhoneiros", -105.8247, -1114.6532, 1.8270, 244.5380 },
	{ "Taxistas", 618.4514, -1511.2411, 14.9898, 15.5726 },
	{ "Advogados", 1171.3048, -1727.1143, 13.3728, 181.0633 },
	{ "Coveiros", 848.5544, -1101.9432, 24.2969, 269.7824 },
	{ "Mineradores", 1018.5568, -76.2014, 22.4570, 95.7636 },
	{ "Socorristas", 2038.0348, -1404.6837, 17.2531, 2.2658 },
	{ "Eletricistas", 808.8510, -589.9405, 16.3359, 269.6408 },
	{ "Motoristas de Ônibus", 1801.1271, -2377.6838, 13.3750, 34.0867 },
	{ "Fazendeiros", -105.1202,43.1582,3.1172,159.3745 }
};

static gsTunningTeleports[][t_TELEPORT_INFO] = 
{
	{ "Trans Fender", 1042.7727, -1034.4984, 31.6971, 0.8952 },
	{ "Wheel Arch", -2709.8464, 217.6329, 3.9722, 91.1026 },
	{ "Low Rider", 2645.1450, -2029.4902, 13.3313, 178.6665 },
	{ "Trans Fender", 2386.1208, 1039.5265, 10.3404, 357.4445 }
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowPlayerTeleportsList(playerid)
{
    new stringTeleports[191 + 1];
 	strcat(stringTeleports, "{ff61f3}Teleportes » {FFFFFF}Locais Importantes\n");
 	strcat(stringTeleports, "{ff61f3}Teleportes » {FFFFFF}Postos de Gasolina\n");
	strcat(stringTeleports, "{ff61f3}Teleportes » {FFFFFF}HQ de Empregos\n");
	strcat(stringTeleports, "{ff61f3}Teleportes » {FFFFFF}Locais de Tunagem\n");
	ShowPlayerDialog(playerid, DIALOG_TELEPORTS_MENU, DIALOG_STYLE_LIST, "{FFFFFF}Teleportes - Selecione uma opção", stringTeleports, "Escolher", "Cancelar");
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    switch (dialogid)
    {
        case DIALOG_TELEPORTS_MENU:
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
			            new teleportItems[((MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40) * sizeof(gsGeneralTeleports))], string[(MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(teleportItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsGeneralTeleports); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsGeneralTeleports[i][t_TELEPORT_POSX], gsGeneralTeleports[i][t_TELEPORT_POSY], gsGeneralTeleports[i][t_TELEPORT_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsGeneralTeleports[i][t_TELEPORT_NAME], GetPlayerDistanceFromPoint(playerid, gsGeneralTeleports[i][t_TELEPORT_POSX], gsGeneralTeleports[i][t_TELEPORT_POSY], gsGeneralTeleports[i][t_TELEPORT_POSZ]), zoneName);
							strcat(teleportItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_TELEPORTS_GENERAL, DIALOG_STYLE_TABLIST_HEADERS, "Escolha uma opção para teleportar:", teleportItems, "Teleportar", "Voltar");
                        return 1;
                    }
                    case 1:
			        {
			            new teleportItems[((MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40) * sizeof(gsGasStationTeleports))], string[(MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(teleportItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsGasStationTeleports); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsGasStationTeleports[i][t_TELEPORT_POSX], gsGasStationTeleports[i][t_TELEPORT_POSY], gsGasStationTeleports[i][t_TELEPORT_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsGasStationTeleports[i][t_TELEPORT_NAME], GetPlayerDistanceFromPoint(playerid, gsGasStationTeleports[i][t_TELEPORT_POSX], gsGasStationTeleports[i][t_TELEPORT_POSY], gsGasStationTeleports[i][t_TELEPORT_POSZ]), zoneName);
							strcat(teleportItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_TELEPORTS_GASSTATION, DIALOG_STYLE_TABLIST_HEADERS, "Escolha uma opção para teleportar:", teleportItems, "Teleportar", "Voltar");
                        return 1;
                    }
                    case 2:
			        {
			            new teleportItems[((MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40) * sizeof(gsJobsTeleports))], string[(MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(teleportItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsJobsTeleports); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsJobsTeleports[i][t_TELEPORT_POSX], gsJobsTeleports[i][t_TELEPORT_POSY], gsJobsTeleports[i][t_TELEPORT_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsJobsTeleports[i][t_TELEPORT_NAME], GetPlayerDistanceFromPoint(playerid, gsJobsTeleports[i][t_TELEPORT_POSX], gsJobsTeleports[i][t_TELEPORT_POSY], gsJobsTeleports[i][t_TELEPORT_POSZ]), zoneName);
							strcat(teleportItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_TELEPORTS_JOBS, DIALOG_STYLE_TABLIST_HEADERS, "Escolha uma opção para teleportar:", teleportItems, "Teleportar", "Voltar");
                        return 1;
                    }
                    case 3:
			        {
			            new teleportItems[((MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40) * sizeof(gsTunningTeleports))], string[(MAX_TELEPORT_STRING + MAX_ZONE_NAME + 40)], zoneName[MAX_ZONE_NAME];
						strcat(teleportItems, "Local\tDistância\tLocalidade\n");
						for (new i; i < sizeof(gsTunningTeleports); i++)
						{
                            GetMapZoneName(GetMapZoneAtPoint(gsTunningTeleports[i][t_TELEPORT_POSX], gsTunningTeleports[i][t_TELEPORT_POSY], gsTunningTeleports[i][t_TELEPORT_POSZ]), zoneName);
							format(string, sizeof(string), "{848484}%s\t{AFAFAF}%.02fm\t{FFFFFF}%s\n", gsTunningTeleports[i][t_TELEPORT_NAME], GetPlayerDistanceFromPoint(playerid, gsTunningTeleports[i][t_TELEPORT_POSX], gsTunningTeleports[i][t_TELEPORT_POSY], gsTunningTeleports[i][t_TELEPORT_POSZ]), zoneName);
							strcat(teleportItems, string);
						}
						ShowPlayerDialog(playerid, DIALOG_TELEPORTS_TUNNINGS, DIALOG_STYLE_TABLIST_HEADERS, "Escolha uma opção para teleportar", teleportItems, "Teleportar", "Voltar");
                        return 1;
                    }
                }
            }
        }

        case DIALOG_TELEPORTS_GENERAL:
		{
			if (!response) 
			{
				return ShowPlayerTeleportsList(playerid);
			}
			if (response)
			{
                if (listitem < 0 || listitem > sizeof(gsGeneralTeleports))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Local selecionado inválido.");
				}
				new string[(57 + MAX_TELEPORT_STRING + 1)];
				TeleportPlayer(playerid, gsGeneralTeleports[listitem][t_TELEPORT_POSX], gsGeneralTeleports[listitem][t_TELEPORT_POSY], gsGeneralTeleports[listitem][t_TELEPORT_POSZ], 0, 0, NO_INTERIOR);
				format(string, sizeof(string), "[Teleporte]: {FFFFFF}Você foi teleportado(a) para a(o): %s.", gsGeneralTeleports[listitem][t_TELEPORT_NAME]);
				SendClientMessage(playerid, COLOR_ADMIN, string);
				return 1;
			}
		}
        case DIALOG_TELEPORTS_GASSTATION:
		{
			if (!response) 
			{
				return ShowPlayerTeleportsList(playerid);
			}
			if (response)
			{
                if (listitem < 0 || listitem > sizeof(gsGasStationTeleports))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Local selecionado inválido.");
				}
				new string[(57 + MAX_TELEPORT_STRING + 1)];
				TeleportPlayer(playerid, gsGasStationTeleports[listitem][t_TELEPORT_POSX], gsGasStationTeleports[listitem][t_TELEPORT_POSY], gsGasStationTeleports[listitem][t_TELEPORT_POSZ], 0, 0, NO_INTERIOR);
				format(string, sizeof(string), "[Teleporte]: {FFFFFF}Você foi teleportado(a) para a(o): %s.", gsGasStationTeleports[listitem][t_TELEPORT_NAME]);
				SendClientMessage(playerid, COLOR_ADMIN, string);
				return 1;
			}
		}

		case DIALOG_TELEPORTS_JOBS:
		{
			if (!response) 
			{
				return ShowPlayerTeleportsList(playerid);
			}
			if (response)
			{
                if (listitem < 0 || listitem > sizeof(gsJobsTeleports))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Local selecionado inválido.");
				}
				new string[(57 + MAX_TELEPORT_STRING + 1)];
				TeleportPlayer(playerid, gsJobsTeleports[listitem][t_TELEPORT_POSX], gsJobsTeleports[listitem][t_TELEPORT_POSY], gsJobsTeleports[listitem][t_TELEPORT_POSZ], 0, 0, NO_INTERIOR);
				format(string, sizeof(string), "[Teleporte]: {FFFFFF}Você foi teleportado(a) para a(o): %s.", gsJobsTeleports[listitem][t_TELEPORT_NAME]);
				SendClientMessage(playerid, COLOR_ADMIN, string);
				return 1;
			}
		}

		case DIALOG_TELEPORTS_TUNNINGS:
		{
			if (!response) 
			{
				return ShowPlayerTeleportsList(playerid);
			}
			if (response)
			{
                if (listitem < 0 || listitem > sizeof(gsTunningTeleports))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Local selecionado inválido.");
				}
				new string[(57 + MAX_TELEPORT_STRING + 1)];
				TeleportPlayer(playerid, gsTunningTeleports[listitem][t_TELEPORT_POSX], gsTunningTeleports[listitem][t_TELEPORT_POSY], gsTunningTeleports[listitem][t_TELEPORT_POSZ], 0, 0, NO_INTERIOR);
				format(string, sizeof(string), "[Teleporte]: {FFFFFF}Você foi teleportado(a) para a(o): %s.", gsTunningTeleports[listitem][t_TELEPORT_NAME]);
				SendClientMessage(playerid, COLOR_ADMIN, string);
				return 1;
			}
		}
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
