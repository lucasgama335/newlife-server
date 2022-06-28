#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
YCMD:matar(playerid, params[], help) = kill;
YCMD:kill(playerid, params[], help)
{
	// Verificações
    if (PlayerData_GetAdmin(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /kill [id]");
	}
    if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	// Execução do Comando
	new string[150];
	SetPlayerHealth(id, 0);
	format(string, sizeof(string), "* Você matou o jogador %s.", Player_GetName(id));
    SendClientMessage(playerid, COLOR_INVALID, string);
    format(string, sizeof(string), "O Administrador %s te matou.", Player_GetName(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
    return 1;
}
