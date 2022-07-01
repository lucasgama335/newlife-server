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
    if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /kill [id]");
	}
    if (!IsValidPlayer(id, Player_GetLoggedStatus(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	// Execução do Comando
	new string[150];
	SetPlayerHealth(id, 0);
	format(string, sizeof(string), "* Você matou o jogador %s.", GetPlayerNameCustom(id));
    SendClientMessage(playerid, COLOR_INVALID, string);
    format(string, sizeof(string), "O Administrador %s te matou.", GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
    return 1;
}
