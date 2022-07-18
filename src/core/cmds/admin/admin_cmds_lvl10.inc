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
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	new id, e_ADMIN_LEVELS:level;
	if (sscanf(params, "ud", id, level))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /daradmin [id] [nivel]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) == OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode alterar o nível de admin de um Dono.");
	}
	if (level < NO_ADMIN || level > OWNER)
	{
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Nível de admin inválido.");
	}

	new string[104];
	Player_SetAdminLevel(id, level, true);
	format(string, sizeof(string), "Você foi promovido para level %d de administrador - Por %s.", level, GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "Você promoveu %s para o level %d de administrador.", GetPlayerNameCustom(id), level);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}

YCMD:radmin(playerid, params[], help) = retiraradmin;
YCMD:retiraradmin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /retiraradmin [id]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) == OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode retirar o status de admin de um Dono.");
	}

	new string[65];
	Player_SetAdminLevel(id, NO_ADMIN, true);
	format(string, sizeof(string), "Você foi removido da administração por %s.", GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "Você removeu %s da administração.", GetPlayerNameCustom(id));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}

// /excluirconta

YCMD:iro(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	new objid;
	if (sscanf(params, "d", objid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /iro [id do objeto]");
	}

	new Float:x, Float:y, Float:z;
	GetDynamicObjectPos(objid, x, y, z);
	SetPlayerPos(playerid, x, y, z);
	SendClientMessage(playerid, COLOR_INVALID, "Você foi até o objeto");
	return 1;
}

// /totalcasas
// /criarcasa
// /editarcasa
// /deletarcasa
// /deletarcasasall
// /ircasa
// /criarempresa
// /editarempresa
// /deletarempresa
// /deletarempresasall
// /irempresa