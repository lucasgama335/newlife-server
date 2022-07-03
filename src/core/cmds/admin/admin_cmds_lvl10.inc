#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
YCMD:daradmin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	new id, e_ADMIN_LEVELS:level;
	if (sscanf(params, "ud", id, level))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /daradmin [id] [nivel]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (Player_GetAdminLevel(id) == OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode alterar o nível de admin de um Dono.");
	}
	if (level < NO_ADMIN || level > OWNER)
	{
        return SendClientMessage(playerid, COLOR_INVALID, "Nível de admin inválido.");
	}

	new string[100];
	Player_SetAdminLevel(id, level, true);
	format(string, sizeof(string), "Você foi promovido para level %d de Admin - Por %s.", level, GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "Você promoveu %s para o level %d de Admin.", GetPlayerNameCustom(id), level);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}

YCMD:radmin(playerid, params[], help) = retiraradmin;
YCMD:retiraradmin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /retiraradmin [id]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (Player_GetAdminLevel(id) == OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode retirar o status de admin de um Dono.");
	}

	new string[68];
	Player_SetAdminLevel(id, NO_ADMIN, true);
	format(string, sizeof(string), "Seu Admin foi retirado pelo Administrador: %s.", GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "Você retirou o Admin de %s.", GetPlayerNameCustom(id));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}