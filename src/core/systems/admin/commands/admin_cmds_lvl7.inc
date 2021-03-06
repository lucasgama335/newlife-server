#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
YCMD:setpos(playerid, params[], help)
{
	// Verifica��es
    if (Player_GetAdminLevel(playerid) < MASTERPP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
    if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, Float:x, Float:y, Float:z;
	if (sscanf(params, "ufff", id, x, y, z))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setpos [id] [X] [Y] [Z]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	// Execu��o do Comando
	SetPlayerPos(id, x, y, z);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "Posi��o setada!");
    return 1;
}

// /bloquearcaixa
// /limitecaixa
// /liberarcaixa
// /setarlider
// /setorgvip
// /limparlider
