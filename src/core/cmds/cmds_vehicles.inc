#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowPlayerGasStationDialog(playerid)
{
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um veículo.");
	}
	if (!IsPlayerInGasStation(playerid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um posto de gasolina.");
	}
	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está é o motorista do veículo.");
	}
	new vehicleid = GetPlayerVehicleID(playerid);
	if (Vehicle_IsBike(GetVehicleModel(vehicleid)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse veículo não precisa ser abastecido.");
	}
	if (Vehicle_GetEngineStatus(vehicleid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "O motor do veículo precisa estar desligado para ser abastecido.");
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

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
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
