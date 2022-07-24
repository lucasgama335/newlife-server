#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define FUEL_PUMP_RADIO 6.0

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsPlayerLastCarEntered[MAX_PLAYERS];
static gsPlayerSpeedometerTimer[MAX_PLAYERS];
static gsPlayerCheckFuelTimer[MAX_PLAYERS];
static gsPlayerCheckBrokenTimer[MAX_PLAYERS];
static bool:gsIsPlayerRefueling[MAX_PLAYERS];
static Float:gsFuelPumps[][3] =
{
    { 1004.0070, -939.3102, 42.1797 },
    { 1944.3260, -1772.9254, 13.3906 },
    { -90.5515, -1169.4578, 2.4079 },
    { -1609.7958, -2718.2048, 48.5391 },
    { -1604.8998, -2711.1104, 48.9453 },
    { -2029.4968, 156.4366, 28.9498 },
    { -2408.7590, 976.0934, 45.4175 },
    { 655.3879, -564.3586, 16.3359 },
    { 2639.5940, 1106.6432, 10.8203 },
    { 1596.8081, 2199.0686, 10.8203 },
    { 1380.4712, 462.7467, 20.1107 },
    { 1385.0475, 460.5417, 20.1068 },
    { 1383.5532, 457.1286, 19.9561 },
    { 1379.1952, 459.1295, 19.9587 },
    { -2243.9629, -2560.6477, 31.8841 },
    { -1676.6323, 414.0262, 6.9484 },
    { 2202.2349, 2474.3494, 10.5258 },
    { 614.9333, 1689.7418, 6.6968 },
    { 2147.0803, 2747.8940, 10.8203 },
    { -1328.8250, 2677.2173, 49.7665 },
    { 70.3882, 1218.6783, 18.5165 },
    { 2113.7390, 920.1079, 10.5255 },
    { -1327.7218, 2678.8723, 50.0625 },
	{ 838.3388, -1750.3429, 13.6911 }
};

static const Float:gsPaynsprayLocales[][] =
{
    {1025.05, -1024.23, 32.1}, // LS Temple
    {487.68, -1740.87, 11.13}, // LS Santa Maria
    {-1420.73, 2583.37, 55.56}, // El Quebrados
    {-1904.39, 284.97, 40.75}, // Wang Cars
    {-2425.91, 1022.33, 50.10}, // Juniper Hill
    {1975.60, 2162.16, 10.77}, // LV Redsands
    {2065.38, -1831.51, 13.25}, // Idlewood
    {-99.55, 1118.36, 19.44}, // Fort Carson
    {721.07, -455.94, 16.04}, // Dillimore
    {2393.74, 1493.01, 10.52} // LV Unused (Pyramid)
};

//------------------------- Timers (Timers used in the module.) -------------------------
function:UpdateVehicleSpeedometer(playerid, vehicleid, type)
{
	UpdatePlayerSpeedometer(playerid, vehicleid, type);
	return 1;
}

function:RemovePlayerVehicleEmptyGas(playerid)
{
	RemovePlayerFromVehicle(playerid);
	return 1;
}

function:RemovePlayerVehicleBroken(playerid)
{
	RemovePlayerFromVehicle(playerid);
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowActualVehicleName(playerid, vehicleid)
{
	new string[100], vehicleName[MAX_VEHICLE_NAME_STRING];
	GetVehicleName(GetVehicleModel(vehicleid), vehicleName);
	format(string, sizeof(string), "~g~%s[%d]", vehicleName, GetVehicleModel(vehicleid));
	GameTextForPlayer(playerid, string, 6000, 1);
	return 1;
}

static stock PlayerCheckVehicleFuel(playerid, vehicleid)
{
	if (Vehicle_GetFuel(vehicleid) <= 0)
	{
		GameTextForPlayer(playerid,"~r~~n~~n~~n~~n~~n~~n~~n~~n~SEM GAS !", 1500, 3);
		SendClientMessage(playerid, COLOR_WHITE, "O Seu veículo está sem gasolina.");
		PlayerPlayMusic(playerid, 1159);
		if (gsPlayerCheckFuelTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckFuelTimer[playerid]);
			gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
		}
		gsPlayerCheckFuelTimer[playerid] = SetTimerEx("RemovePlayerVehicleEmptyGas", 5000, false, "i", playerid);
	}
	else
	{
		if (gsPlayerCheckFuelTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckFuelTimer[playerid]);
			gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
		}
	}
	return 1;
}

static stock PlayerCheckVehicleBroken(playerid, vehicleid)
{
	if (Vehicle_GetBrokenStatus(vehicleid))
	{
		SendClientMessage(playerid, COLOR_RED, "O Seu veículo bateu o motor, chame um mecânico(/solicitar) ou use seu kit(/kitcarro) !");
		GameTextForPlayer(playerid,"~r~VEICULO QUEBRADO~n~~w~ Chame um mecanico ou use um~n~~w~ KIT[/kitcarro]", 15000, 1);
		if (gsPlayerCheckBrokenTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckBrokenTimer[playerid]);
			gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
		}
		gsPlayerCheckBrokenTimer[playerid] = SetTimerEx("RemovePlayerVehicleBroken", 5000, false, "i", playerid);
	}
	else
	{
		if (gsPlayerCheckBrokenTimer[playerid] != INVALID_VALUE)
		{
			KillTimer(gsPlayerCheckBrokenTimer[playerid]);
			gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
		}
	}
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock StartSpeedometerTimer(playerid, vehicleid)
{
	if (gsPlayerSpeedometerTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerSpeedometerTimer[playerid]);
		gsPlayerSpeedometerTimer[playerid] = INVALID_VALUE;
	}
	gsPlayerSpeedometerTimer[playerid] = SetTimerEx("UpdateVehicleSpeedometer", 500, true, "iii", playerid, vehicleid, Player_GetSpeedometer(playerid));
	return 1;
}

stock bool:IsPlayerInGasStation(playerid)
{
    for (new i; i < sizeof(gsFuelPumps); i++)
    {
        if (IsPlayerInRangeOfPoint(playerid, FUEL_PUMP_RADIO, gsFuelPumps[i][0], gsFuelPumps[i][1], gsFuelPumps[i][2]))
        {
            return true;
        }
    }
    return false;
}

stock ShowPlayerGasStationDialog(playerid)
{
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em um veículo.");
	}
	if (!IsPlayerInGasStation(playerid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em um posto de gasolina.");
	}
	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está é o motorista do veículo.");
	}
	new vehicleid = GetPlayerVehicleID(playerid);
	if (Vehicle_IsBike(GetVehicleModel(vehicleid)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse veículo não precisa ser abastecido.");
	}
	if (Vehicle_GetEngineStatus(vehicleid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O motor do veículo precisa estar desligado para ser abastecido.");
	}

	new StrCat[120], priceString[MAX_MONEY_STRING], string[(27 + MAX_MONEY_STRING)];
	strcat(StrCat, "Tipo\tPreço\n");
	FormatMoneyString(PETROL_PRICE, priceString);
	format(string, sizeof(string), "{FFFFFF}Gasolina\tR$ %s/L\n", priceString);
 	strcat(StrCat, string);
 	FormatMoneyString(DIESEL_PRICE, priceString);
	format(string, sizeof(string), "{FFFFFF}Diesel\tR$ %s/L\n", priceString);
 	strcat(StrCat, string);
	FormatMoneyString(ELECTRIC_PRICE, priceString);
	format(string, sizeof(string), "{FFFFFF}Eletricidade\tR$ %s/L\n", priceString);
 	strcat(StrCat, string);
	ShowPlayerDialog(playerid, DIALOG_GAS_STATION, DIALOG_STYLE_TABLIST_HEADERS, "Abastecimento de Veículos", StrCat, "Abastecer", "Fechar");
	return 1;
}

stock bool:IsPlayerRefueling(playerid)
{
	if (!IsValidPlayer(playerid))
	{
		return false;
	}

	return gsIsPlayerRefueling[playerid];
}

stock SetPlayerRefueling(playerid, bool:status)
{
	if (!IsValidPlayer(playerid))
	{
		return 0;
	}

	gsIsPlayerRefueling[playerid] = status;
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	gsPlayerLastCarEntered[playerid] = INVALID_VEHICLE_ID;
	gsPlayerSpeedometerTimer[playerid] = INVALID_VALUE;
	gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
	gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
	return 1;
}

hook OnPlayerDisconnect(playerid)
{
	if (gsPlayerSpeedometerTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerSpeedometerTimer[playerid]);
		gsPlayerSpeedometerTimer[playerid] = INVALID_VALUE;
	}

	if (gsPlayerCheckFuelTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerCheckFuelTimer[playerid]);
		gsPlayerCheckFuelTimer[playerid] = INVALID_VALUE;
	}

	if (gsPlayerCheckBrokenTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsPlayerCheckBrokenTimer[playerid]);
		gsPlayerCheckBrokenTimer[playerid] = INVALID_VALUE;
	}

	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	new Float:Pos[3];
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    if (GetPlayerSpeed(vehicleid, true) > 1)
	{
        SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não pode entrar em veículos em movimento !");
		return 1;
	}

	if (Vehicle_GetJob(vehicleid) != j_JOB_NONE && Player_GetJob(playerid) != Vehicle_GetJob(vehicleid))
	{
		new string[(40 + MAX_JOB_NAME)];
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		format(string, sizeof(string), "* Você não é um(a) %s.", Job_GetName(Vehicle_GetJob(vehicleid)));
		SendClientMessage(playerid, COLOR_GRAD2, string);
		return 1;
	}
	
	if (Vehicle_IsCar(GetVehicleModel(vehicleid)) && Player_GetCarLicense(playerid) <= 0)
	{
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para dirigir esse carro.");
		return 1;
	}
	if (Vehicle_IsMotorBike(GetVehicleModel(vehicleid)) && Player_GetMotorCycleLicense(playerid) <= 0)
	{
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para pilotar essa moto.");
		return 1;
	}
	if (Vehicle_IsTruck(GetVehicleModel(vehicleid)) && Player_GetTruckLicense(playerid) <= 0)
	{
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para dirigir esse caminhão/ônibus.");
		return 1;
	}
	if (Vehicle_IsHelicopter(GetVehicleModel(vehicleid)) && Player_GetFlyLicense(playerid) <= 0
	|| Vehicle_IsPlane(GetVehicleModel(vehicleid)) && Player_GetFlyLicense(playerid) <= 0)
	{
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para pilotar essa aeronave.");
		return 1;
	}
	if (Vehicle_IsBoat(GetVehicleModel(vehicleid)) && Player_GetBoatLicense(playerid) <= 0)
	{
		SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
		SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para pilotar esse barco.");
		return 1;
	}

	gsPlayerLastCarEntered[playerid] = vehicleid;

    if (!Vehicle_GetEngineStatus(vehicleid) && !ispassenger)
    {
    	if (Vehicle_IsCivilVehicle(vehicleid))
        {
			SendClientMessage(playerid, COLOR_SKIN, "[Dica]: Novato, você pode achar os locais digitando: /gps.");
	    	SendClientMessage(playerid, COLOR_SKIN, "[Dica]: Em caso de dúvidas use: /faq, ou fale diretamente com os administradores: /relatorio.");		
			return 1;
		}

		SendClientMessage(playerid, COLORDGREEN, "[Veículo]: Para ligar o motor deste veículo pressione {FFFFFF}N{228b22} ou digite {FFFFFF}/motor{228b22}.");
    }
	return 1;
}

first_hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	#pragma unused oldstate // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	if (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
		ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
		StartSpeedometerTimer(playerid, vehicleid);
		PlayerCheckVehicleFuel(playerid, vehicleid);
		PlayerCheckVehicleBroken(playerid, vehicleid);
		if (gsPlayerLastCarEntered[playerid] != vehicleid)
		{
			ShowActualVehicleName(playerid, vehicleid);
		}
		
		if (newstate == PLAYER_STATE_DRIVER)
		{
			if (Vehicle_IsCivilVehicle(vehicleid) && !Vehicle_GetEngineStatus(vehicleid))
			{
				Vehicle_SetEngineToPlayer(playerid, vehicleid, true);
				return 1;
			}
			if (Vehicle_IsBike(GetVehicleModel(vehicleid)) && !Vehicle_GetEngineStatus(vehicleid))
			{
				Vehicle_SetEngine(vehicleid, true);
				return 1;
			}

			if (Vehicle_GetJob(vehicleid) != j_JOB_NONE && Player_GetJob(playerid) != Vehicle_GetJob(vehicleid))
			{
				new string[(40 + MAX_JOB_NAME)];
				RemovePlayerFromVehicle(playerid);
				format(string, sizeof(string), "* Você não é um %s.", Job_GetName(Vehicle_GetJob(vehicleid)));
				SendClientMessage(playerid, COLOR_GRAD2, string);
				return 1;
			}
			if (Vehicle_IsCar(GetVehicleModel(vehicleid)) && Player_GetCarLicense(playerid) <= 0)
			{
				RemovePlayerFromVehicle(playerid);
				SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para dirigir esse carro.");
				return 1;
			}
			if (Vehicle_IsMotorBike(GetVehicleModel(vehicleid)) && Player_GetMotorCycleLicense(playerid) <= 0)
			{
				RemovePlayerFromVehicle(playerid);
				SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para pilotar essa moto.");
				return 1;
			}
			if (Vehicle_IsTruck(GetVehicleModel(vehicleid)) && Player_GetTruckLicense(playerid) <= 0)
			{
				RemovePlayerFromVehicle(playerid);
				SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para dirigir esse caminhão/ônibus.");
				return 1;
			}
			if (Vehicle_IsHelicopter(GetVehicleModel(vehicleid)) && Player_GetFlyLicense(playerid) <= 0
			|| Vehicle_IsPlane(GetVehicleModel(vehicleid)) && Player_GetFlyLicense(playerid) <= 0)
			{
				RemovePlayerFromVehicle(playerid);
				SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para pilotar essa aeronave.");
				return 1;
			}
			if (Vehicle_IsBoat(GetVehicleModel(vehicleid)) && Player_GetBoatLicense(playerid) <= 0)
			{
				RemovePlayerFromVehicle(playerid);
				SendClientMessage(playerid, COLOR_INVALID, "Você não possui a habilitação para pilotar esse barco.");
				return 1;
			}
		}
	}
	else
	{
		HidePlayerSpeedometer(playerid);
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	switch (dialogid)
	{
		case DIALOG_GAS_STATION:
		{
	        if (!response)
	        {
				return SendClientMessage(playerid, COLOR_INVALID, "Você optou por não abastecer o veiculo !");
	        }
			if (response)
			{
	            new vehicleid = GetPlayerVehicleID(playerid);
	            switch(listitem)
	            {
	                case 0:
	                {
	                    if (!IsPlayerInGasStation(playerid))
			            {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um posto de gasolina !");
			            }
						if (GetVehicleFuelType(GetVehicleModel(vehicleid)) != e_VEHICLE_FUEL_PETROL)
						{
							new fuelName[MAX_VEHICLE_FUEL_STRING], string[(42 + MAX_VEHICLE_FUEL_STRING)];
							GetVehicleFuelName(GetVehicleModel(vehicleid), fuelName);
							format(string, sizeof(string), "O seu veículo só aceita %s como combustível.", fuelName);
							SendClientMessage(playerid, COLOR_INVALID, string);
							return 1;
						}
						new totalPrice = floatround((GetVehicleFuelCapacity(GetVehicleModel(vehicleid)) - Vehicle_GetFuel(vehicleid)) * PETROL_PRICE);
			            if (Player_GetMoney(playerid) < totalPrice)
		                {
							new string[(69 + MAX_MONEY_STRING)], priceString[MAX_MONEY_STRING];
							FormatMoneyString(totalPrice, priceString);
							format(string, sizeof(string), "Você não possui dinheiro suficiente. O custo do abastecimento é: R$ %s.", priceString);
							SendClientMessage(playerid, COLOR_INVALID, string);
		                    return 1;
		                }
		                if (Vehicle_GetFuel(vehicleid) >= GetVehicleFuelCapacity(GetVehicleModel(vehicleid)))
				        {
				            return SendClientMessage(playerid, COLOR_INVALID, "O tanque do seu veículo está cheio.");
				        }
						GasStationStartFuel(playerid, vehicleid, totalPrice, PETROL_PRICE);
						return 1;
	                }
	                case 1:
	                {
	                    if (!IsPlayerInGasStation(playerid))
			            {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um posto de gasolina !");
			            }
						if (GetVehicleFuelType(GetVehicleModel(vehicleid)) != e_VEHICLE_FUEL_DIESEL)
						{
							new fuelName[MAX_VEHICLE_FUEL_STRING], string[(42 + MAX_VEHICLE_FUEL_STRING)];
							GetVehicleFuelName(GetVehicleModel(vehicleid), fuelName);
							format(string, sizeof(string), "O seu veículo só aceita %s como combustível.", fuelName);
							SendClientMessage(playerid, COLOR_INVALID, string);
							return 1;
						}
						new totalPrice = floatround((GetVehicleFuelCapacity(GetVehicleModel(vehicleid)) - Vehicle_GetFuel(vehicleid)) * DIESEL_PRICE);
			            if (Player_GetMoney(playerid) < totalPrice)
		                {
							new string[(69 + MAX_MONEY_STRING)], priceString[MAX_MONEY_STRING];
							FormatMoneyString(totalPrice, priceString);
							format(string, sizeof(string), "Você não possui dinheiro suficiente. O custo do abastecimento é: R$ %s.", priceString);
							SendClientMessage(playerid, COLOR_INVALID, string);
		                    return 1;
		                }
		                if (Vehicle_GetFuel(vehicleid) >= GetVehicleFuelCapacity(GetVehicleModel(vehicleid)))
				        {
				            return SendClientMessage(playerid, COLOR_INVALID, "O tanque do seu veículo está cheio.");
				        }
						GasStationStartFuel(playerid, vehicleid, totalPrice, DIESEL_PRICE);
						return 1;
	                }
	                case 2:
	                {
	                    if (!IsPlayerInGasStation(playerid))
			            {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um posto de gasolina !");
			            }
						if (GetVehicleFuelType(GetVehicleModel(vehicleid)) != e_VEHICLE_FUEL_ELECTRIC)
						{
							new fuelName[MAX_VEHICLE_FUEL_STRING], string[(42 + MAX_VEHICLE_FUEL_STRING)];
							GetVehicleFuelName(GetVehicleModel(vehicleid), fuelName);
							format(string, sizeof(string), "O seu veículo só aceita %s como combustível.", fuelName);
							SendClientMessage(playerid, COLOR_INVALID, string);
							return 1;
						}
						new totalPrice = floatround((GetVehicleFuelCapacity(GetVehicleModel(vehicleid)) - Vehicle_GetFuel(vehicleid)) * ELECTRIC_PRICE);
			            if (Player_GetMoney(playerid) < totalPrice)
		                {
							new string[(69 + MAX_MONEY_STRING)], priceString[MAX_MONEY_STRING];
							FormatMoneyString(totalPrice, priceString);
							format(string, sizeof(string), "Você não possui dinheiro suficiente. O custo do abastecimento é: R$ %s.", priceString);
							SendClientMessage(playerid, COLOR_INVALID, string);
		                    return 1;
		                }
		                if (Vehicle_GetFuel(vehicleid) >= GetVehicleFuelCapacity(GetVehicleModel(vehicleid)))
				        {
				            return SendClientMessage(playerid, COLOR_INVALID, "O tanque do seu veículo está cheio.");
				        }
						GasStationStartFuel(playerid, vehicleid, totalPrice, ELECTRIC_PRICE);
						return 1;
	                }
	            }
			}
			return 1;
		}
	}
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	if (IsValidPlayer(playerid))
	{
		if (IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			new vehicleid = GetPlayerVehicleID(playerid), Float:oldHealth = Vehicle_GetHealth(vehicleid), Float:actualHealth;
			GetVehicleHealth(vehicleid, actualHealth);

			if(actualHealth == 1000.0)
			{
				SetVehicleHealth(vehicleid, MAX_VEHICLE_HEALTH);
				Vehicle_SetHealth(vehicleid, MAX_VEHICLE_HEALTH);
				for(new i = sizeof(gsPaynsprayLocales) - 1; i != -1; --i)
				{
					if(IsPlayerInRangeOfPoint(playerid, 10.0, gsPaynsprayLocales[i][0], gsPaynsprayLocales[i][1], gsPaynsprayLocales[i][2]))
					{
						CallRemoteFunction("OnVehicleRespray", "iiii", playerid, vehicleid, -1, -1);
						return 1;
					}
				}
			}

			
			if (oldHealth != actualHealth && (oldHealth - actualHealth) >= 1.0)
			{
				Vehicle_SetHealth(vehicleid, actualHealth);
				CallLocalFunction("OnVehicleHealthChange", "iiff", vehicleid, playerid, oldHealth, actualHealth);
				return 1;
			}
		}
	}
	return 1;
}

hook OnPlayerUpdateScreenSize(playerid)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	AdaptSpeedometerToScreen(playerid);
	if (IsPlayerInVehicle(playerid, vehicleid) && vehicleid != INVALID_VEHICLE_ID && IsValidVehicle(vehicleid)) 
	{
		UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
		ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
		StartSpeedometerTimer(playerid, vehicleid);
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:motor(playerid, params[], help)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	Vehicle_SetEngineToPlayer(playerid, vehicleid, (Vehicle_GetEngineStatus(vehicleid) ? false : true));
	return 1;
}

YCMD:abastecerposto(playerid, params[], help)
{
	ShowPlayerGasStationDialog(playerid);
	return 1;
}
