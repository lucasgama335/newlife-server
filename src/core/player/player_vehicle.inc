#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
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

    if (!Vehicle_GetEngineStatus(vehicleid) && !ispassenger)
    {
    	if (Vehicle_IsCivilVehicle(vehicleid))
        {
        	StartVehicleEngineToPlayer(playerid, vehicleid);
         	if (Vehicle_IsCivilVehicle(vehicleid))
			{
			 	SendClientMessage(playerid, COLOR_NEONGREEN, "Novato, você pode chegar aos locais digitando /gps ou falando com um admin /relatorio.");
	    		SendClientMessage(playerid, COLOR_NEONGREEN, "Consiga Seu Emprego /gps - Prefeitura | Digite /faq para tirar todas as suas dúvidas.");
			}
		}
        else
		{
		    SendClientMessage(playerid, COLORDGREEN, "[VEÍCULO]: Para dirigir em primeira pessoa digite {FFFFFF}/camera{228b22} ou {FFFFFF}/ajuda{228b22} para ver os comandos!");
			SendClientMessage(playerid, COLORDGREEN, "[VEÍCULO]: Para ligar o motor deste veículo pressione {FFFFFF}N{228b22} ou digite {FFFFFF}/motor{228b22}!");
		}
        return 1;
    }
	return 1;
}