#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
YCMD:daradmin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	new id, e_ADMIN_LEVELS:level;
	if (sscanf(params, "ud", id, level))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /daradmin [id] [nivel]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) == OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode alterar o n�vel de admin de um Dono.");
	}
	if (level < NO_ADMIN || level > OWNER)
	{
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�vel de admin inv�lido.");
	}

	new string[104];
	Player_SetAdminLevel(id, level, true);
	format(string, sizeof(string), "Voc� foi promovido para level %d de administrador - Por %s.", level, GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "Voc� promoveu %s para o level %d de administrador.", GetPlayerNameCustom(id), level);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}

YCMD:radmin(playerid, params[], help) = retiraradmin;
YCMD:retiraradmin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /retiraradmin [id]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) == OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode retirar o status de admin de um Dono.");
	}

	new string[65];
	Player_SetAdminLevel(id, NO_ADMIN, true);
	format(string, sizeof(string), "Voc� foi removido da administra��o por %s.", GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "Voc� removeu %s da administra��o.", GetPlayerNameCustom(id));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
    return 1;
}

// /excluirconta

YCMD:iro(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	new objid;
	if (sscanf(params, "d", objid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /iro [id do objeto]");
	}

	new Float:x, Float:y, Float:z;
	GetDynamicObjectPos(objid, x, y, z);
	SetPlayerPos(playerid, x, y, z);
	SendClientMessage(playerid, COLOR_INVALID, "Voc� foi at� o objeto");
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