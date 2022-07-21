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

//------------------------- Commands (Module related commands) -------------------------
