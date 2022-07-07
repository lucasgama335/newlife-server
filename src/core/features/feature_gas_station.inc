#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define FUEL_PUMP_RADIO 6.0

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
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
    { -1327.7218, 2678.8723, 50.0625 }
};

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
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

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
timer FillUp[5000](playerid, vehicleid, type, price, bool:detran)
{
	switch(type)
	{
		case 1:
		{
			if (Vehicle_GetFuel(vehicleid) <= 80)
			{
				Vehicle_SetFuel(vehicleid, (Vehicle_GetFuel(vehicleid) + 20));
			}
			else if (Vehicle_GetFuel(vehicleid) >= 78)
			{
				Vehicle_SetFuel(vehicleid, 100);
			}
		}
		case 2:
		{
			if (Vehicle_GetFuel(vehicleid) <= 49)
			{
				Vehicle_SetFuel(vehicleid, (Vehicle_GetFuel(vehicleid) + 50));
			}
			else if (Vehicle_GetFuel(vehicleid) >= 50)
			{
				Vehicle_SetFuel(vehicleid, 100);
			}
		}
		case 3:
		{
			Vehicle_SetFuel(vehicleid, 100);
		}
	}
	new string[63 + 1];
	SetPlayerRefueling(playerid, false);
	SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - price));
	TogglePlayerControllable(playerid, true);
	// if (!detran) Bizz_GiveMoney(11, price);
	if (detran) format(string, sizeof(string), "[Detran]: Seu veículo foi abastecido, custo R$ %s!", FormatMoneyString(price));
	else format(string, sizeof(string), "[Posto de Gasolina]: Seu veículo foi abastecido, custo R$ %s!", FormatMoneyString(price));
	SendClientMessage(playerid, COLOR_YELLOW2, string);
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsIsPlayerRefueling[playerid] = false;
    return 1;
}
