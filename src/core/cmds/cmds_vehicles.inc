#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsFillUpTimer[MAX_PLAYERS];

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
	if (Vehicle_GetEngineStatus(vehicleid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "O motor do veículo precisa estar desligado para ser abastecido.");
	}

    // Execução do Comando
	new StrCat[120];
	strcat(StrCat, "Tipo\tRecupera\tPreço\n");
 	strcat(StrCat, "{FFFFFF}Pouco\t+20\tR$ 60\n");
 	strcat(StrCat, "{FFFFFF}Médio\t+50\tR$ 150\n");
 	strcat(StrCat, "{FFFFFF}Completo\t+100\tR$ 300\n");
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
			            if (Player_GetMoney(playerid) < 60)
		                {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não tem dinheiro o suficiente !");
		                }
		                if (Vehicle_GetFuel(vehicleid) >= 100)
				        {
				            return SendClientMessage(playerid, COLOR_INVALID, "O Seu tanque já está completo !");
				        }
						SetPlayerRefueling(playerid, true);
						TogglePlayerControllable(playerid, false);
						GameTextForPlayer(playerid,"~n~~w~Reabastecendo~n~ ~r~~h~Aguarde", 5000, 3);
						SendClientMessage(playerid, COLOR_YELLOW2, "[Posto de Gasolina]: Abastecendo veículo...");
						if (Timer_IsRunning(gsFillUpTimer[playerid]))
						{
							stop gsFillUpTimer[playerid];
						}
						gsFillUpTimer[playerid] = defer FillUp(playerid, vehicleid, 1, 60);
	                }
	                case 1:
	                {
	                    if (!IsPlayerInGasStation(playerid))
			            {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um posto de gasolina !");
			            }
			            if (Player_GetMoney(playerid) < 150)
		                {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não tem dinheiro o suficiente !");
		                }
		                if (Vehicle_GetFuel(vehicleid) >= 100)
				        {
				            return SendClientMessage(playerid, COLOR_INVALID, "O Seu tanque já está completo !");
				        }
						SetPlayerRefueling(playerid, true);
						TogglePlayerControllable(playerid, false);
						GameTextForPlayer(playerid,"~n~~w~Reabastecendo~n~ ~r~~h~Aguarde", 5000, 3);
						SendClientMessage(playerid, COLOR_YELLOW2, "[Posto de Gasolina]: Abastecendo veículo...");
						if (Timer_IsRunning(gsFillUpTimer[playerid]))
						{
							stop gsFillUpTimer[playerid];
						}
						gsFillUpTimer[playerid] = defer FillUp(playerid, vehicleid, 2, 150);
	                }
	                case 2:
	                {
	                    if (!IsPlayerInGasStation(playerid))
			            {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um posto de gasolina !");
			            }
			            if (Player_GetMoney(playerid) < 300)
		                {
		                    return SendClientMessage(playerid, COLOR_INVALID, "Você não tem dinheiro o suficiente !");
		                }
		                if (Vehicle_GetFuel(vehicleid) >= 100)
				        {
				            return SendClientMessage(playerid, COLOR_INVALID, "O Seu tanque já está completo !");
				        }
						SetPlayerRefueling(playerid, true);
						TogglePlayerControllable(playerid, false);
						GameTextForPlayer(playerid,"~n~~w~Reabastecendo~n~ ~r~~h~Aguarde", 5000, 3);
						SendClientMessage(playerid, COLOR_YELLOW2, "[Posto de Gasolina]: Abastecendo veículo...");
						if (Timer_IsRunning(gsFillUpTimer[playerid]))
						{
							stop gsFillUpTimer[playerid];
						}
						gsFillUpTimer[playerid] = defer FillUp(playerid, vehicleid, 3, 300);
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
