#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
YCMD:sethora(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new hourtime;
	if (sscanf(params, "d", hourtime))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /sethora [hora do dia(0-23)]");
	}

	new string[90];
	SetWorldTime(hourtime);
	format(string, sizeof(string), "[Administração]: %s definiu o horário do servidor para: %d hora(s).", hourtime);
	SendClientMessageToAll(COLOR_LIGHTRED, string);
	return 1;
}

YCMD:verip(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new id;
	if (sscanf(params, "d", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /verip [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}

	new string[78];
	format(string, sizeof(string), "[Administração]: Jogador %s - [IP: %s].", GetPlayerNameCustom(id), GetPlayerIpCustom(id));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
	return 1;
}

YCMD:rt(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(playerid, slx, sly, slz);
	SetPlayerPos(playerid, slx, (sly - 2), (slz - 2));
    return 1;
}

YCMD:lt(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(playerid, slx, sly, slz);
	SetPlayerPos(playerid, slx, (sly + 2), slz);
    return 1;
}

YCMD:dn(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(playerid, slx, sly, slz);
	SetPlayerPos(playerid, slx, sly, (slz - 2));
    return 1;
}

YCMD:up(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(playerid, slx, sly, slz);
	SetPlayerPos(playerid, slx, sly, (slz + 2));
    return 1;
}

YCMD:entrarveh(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new vehicleid;
	if (sscanf(params, "d", vehicleid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /entrarveh [id do veículo]");
	}

	PutPlayerInVehicle(playerid, vehicleid, 1);
	SendClientMessage(playerid, COLOR_INVALID, "Você foi teleportado por um administrador!");
	return 1;
}

YCMD:entrarveh2(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new vehicleid;
	if (sscanf(params, "d", vehicleid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /entrarveh2 [id do veículo]");
	}

	PutPlayerInVehicle(playerid, vehicleid, 0);
	SendClientMessage(playerid, COLOR_INVALID, "Você foi teleportado por um administrador!");
	return 1;
}

YCMD:fogo(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /fogo [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(playerid) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode colocar fogo em um admin dono.");
	}

	new string[88];
	new Float:burnx, Float:burny, Float:burnz;
	GetPlayerPos(id, burnx, burny, burnz);
	CreateExplosion(burnx, burny , burnz + 3, 1, 3);
	format(string, sizeof(string), "[Administração]: %s incendiou o jogador %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:boasvindas(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /boasvindas [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) > HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode das as boas vindas a um admin.");
	}
	if (Player_GetLevel(id) >= 5)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você só pode dar boas vindas a jogadores novatos.");
	}

	new string[104];
    Player_SetHoursPlayed(id, 15);
	Player_SetLevel(id, 5);
	Player_SetCoins(id, 2);
    Player_SaveScoreData(id);
	format(string, sizeof(string), "{FFFFFF}Parabéns novato, você recebeu:\n{9900ff}> {FFFFFF}Level: {00FF00}5\n{9900ff}> {FFFFFF}Horas Jogadas: {00FF00}15\n{9900ff}> {FFFFFF}Moedas VIP: {00FF00}2\n{FFFFFF}> Todas as licenças para veículos\n{FFFFFF}Administrador: %s\n{FFFFFF}Divulgue o Servidor!", GetPlayerNameCustom(playerid));
	ShowPlayerDialog(id, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Boas Vindas", string, "Fechar", "");
	format(string, sizeof(string), "[Administração]: %s deu as boas vindas ao jogador %s[%d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), id);
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

// /tesouro
// /online
// /setarevento
// /destruirgrafite