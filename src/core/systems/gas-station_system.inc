#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsFuelTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:FillUp(playerid, vehicleid, totalPrice, pricePerLiter)
{
    new fillUp = (Vehicle_GetFuel(vehicleid) + 1);
	Vehicle_SetFuel(vehicleid, fillUp);
    new priceActual = floatround(((GetVehicleFuelCapacity(GetVehicleModel(vehicleid)) - Vehicle_GetFuel(vehicleid)) * pricePerLiter));
    priceActual = (totalPrice - priceActual);
	UpdateFuelTextdraw(playerid, GetVehicleModel(vehicleid), fillUp, priceActual);
	if (Vehicle_GetFuel(vehicleid) >= GetVehicleFuelCapacity(GetVehicleModel(vehicleid)))
	{
		GasStationFinishFuel(playerid, totalPrice);
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock GasStationFinishFuel(playerid, price)
{
	if (gsFuelTimer[playerid] != INVALID_VALUE)
	{
        KillTimer(gsFuelTimer[playerid]);
		gsFuelTimer[playerid] = INVALID_VALUE;
	}
	Player_SetMoney(playerid, (Player_GetMoney(playerid) - price));
	TogglePlayerControllable(playerid, true);
	SetPlayerRefueling(playerid, false);
	SendClientMessage(playerid, COLOR_YELLOW2, "[Posto de Gasolina]: O tanque do seu veículo foi reabastecido completamente.");
	HideFuelTextDraw(playerid);
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock GasStationStartFuel(playerid, vehicleid, totalPrice, pricePerLiter)
{
	ShowFuelTextdraw(playerid);
	if (gsFuelTimer[playerid] != INVALID_VALUE)
	{
        KillTimer(gsFuelTimer[playerid]);
		gsFuelTimer[playerid] = INVALID_VALUE;
	}
    gsFuelTimer[playerid] = SetTimerEx("FillUp", 300, true, "iiii", playerid, vehicleid, totalPrice, pricePerLiter);
	TogglePlayerControllable(playerid, false);
	SetPlayerRefueling(playerid, true);
	SendClientMessage(playerid, COLOR_YELLOW2, "[Posto de Gasolina]: Abastecimendo do veículo iniciado. Aguarde até completar o tanque...");
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsFuelTimer[playerid] = INVALID_VALUE;
	SetPlayerRefueling(playerid, false);
    return 1;
}

hook OnPlayerDisconnect(playerid)
{
    if (gsFuelTimer[playerid] != INVALID_VALUE)
	{
        KillTimer(gsFuelTimer[playerid]);
		gsFuelTimer[playerid] = INVALID_VALUE;
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

//------------------------- Commands (Module related commands) -------------------------
