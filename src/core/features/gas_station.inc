#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define FUEL_PUMP_RADIO 6.0

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:gsIsPlayerRefueling[MAX_PLAYERS];
static gsFuelTimer[MAX_PLAYERS];

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
	SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - price));
	TogglePlayerControllable(playerid, true);
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
	SendClientMessage(playerid, COLOR_YELLOW2, "[Posto de Gasolina]: Abastecimendo do veículo iniciado. Aguarde até completar o tanque...");
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

stock bool:IsPlayerRefueling(playerid)
{
    return gsIsPlayerRefueling[playerid];
}

stock SetPlayerRefueling(playerid, bool:status)
{
    gsIsPlayerRefueling[playerid] = status;
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsFuelTimer[playerid] = INVALID_VALUE;
    gsIsPlayerRefueling[playerid] = false;
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
