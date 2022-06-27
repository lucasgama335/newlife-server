#include <vehicles_data>
#include <vehicles_spawn_civil>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Vehicle_SetEngine(vehicleid, bool:status)
{
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	if (status == false)
    {
	    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
    }
    else
    {
	    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective);
    }
	Vehicle_SetEngineStatus(vehicleid, status);
    return 1;
}

stock Vehicle_SetEngineToPlayer(playerid, vehicleid, bool:status)
{
	if (!IsPlayerInAnyVehicle(playerid) || vehicleid == INVALID_VEHICLE_ID)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um veículo.");
	}
	if (GetPlayerState(playerid) != 2)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não é o motorista desse veículo.");
	}
	if (GetPlayerState(playerid) == 2 && Vehicle_GetFuel(vehicleid) <= 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Seu veículo está sem gasolina, use um galão.");
	}
	if (Vehicle_GetEngineStatus(vehicleid)  && GetPlayerState(playerid) == 2 && GetPlayerSpeed(playerid, true) > 1)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode mecher no motor do veículo em movimento.");
	}
	if (GetPlayerState(playerid) == 2 && Vehicle_GetBrokenStatus(vehicleid))
	{
		return SendClientMessage(playerid, COLOR_LIGHTBLUE, "Seu veículo está quebrado, não pode mecher no motor !");
	}

    Vehicle_SetEngine(vehicleid, status);
	if (Vehicle_GetEngineStatus(vehicleid))
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "Veiculo: {228B22}Ligado!");
    }
    else
    {
	    SendClientMessage(playerid, 0xFFFFFFFF, "Veiculo: {FF0000}Desligado!");
    }
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
