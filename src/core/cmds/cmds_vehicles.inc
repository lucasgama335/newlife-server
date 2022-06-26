#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
stock StartVehicleEngine(vehicleid)
{
    new engine, lights, alarm, doors, bonnet, boot, objective;
	if (!Vehicle_GetEngineStatus(vehicleid))
    {
        GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective);
	    Vehicle_SetEngineStatus(vehicleid, true);
    }
    else
    {
        GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	    SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective);
	    Vehicle_SetEngineStatus(vehicleid, false);
    }
    return 1;
}

stock StartVehicleEngineToPlayer(playerid, vehicleid)
{
    StartVehicleEngine(vehicleid);
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

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

YCMD:motor(playerid, params[], help)
{
	new vid = GetPlayerVehicleID(playerid);
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o est� em um ve�culo.");
	}
	if (GetPlayerState(playerid) != 2)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o � o motorista desse ve�culo.");
	}
	if (GetPlayerState(playerid) == 2 && Vehicle_GetFuel(vid) <= 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Seu ve�culo est� sem gasolina, use um gal�o.");
	}
	if (Vehicle_GetEngineStatus(vid)  && GetPlayerState(playerid) == 2 && GetPlayerSpeed(playerid, true) > 1)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o pode mecher no motor do ve�culo em movimento.");
	}
	if (GetPlayerState(playerid) == 2 && Vehicle_GetBrokenStatus(vid))
	{
		return SendClientMessage(playerid, COLOR_LIGHTBLUE, "Seu ve�culo est� quebrado, n�o pode mecher no motor !");
	}

	return StartVehicleEngineToPlayer(playerid, vid);
}