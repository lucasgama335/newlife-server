#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
YCMD:sethora(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new hourtime;
	if (sscanf(params, "d", hourtime))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /sethora [hora do dia(0-23)]");
	}

	new string[35];
	SetWorldTime(hourtime);
	format(string, sizeof(string), "Tempo definido para [%d] hora(s).", hourtime);
	SendClientMessageToAll(COLOR_INVALID, string);
	return 1;
}

YCMD:verip(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "d", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /verip [id]");
	}
	if (!IsValidPlayer(id, Player_GetLoggedStatus(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[67];
	format(string, sizeof(string), "ADMIN CMD: Jogador %s - [IP: %s].", GetPlayerNameCustom(id), GetPlayerIpCustom(id));
	SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
	return 1;
}

YCMD:rt(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new vehicleid;
	if (sscanf(params, "d", vehicleid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /entrarveh [id do veículo]");
	}

	PutPlayerInVehicle(playerid, vehicleid, 1);
	SendClientMessage(playerid, COLOR_INVALID, "Você foi teleportado pelo Administrador!");
	return 1;
}

YCMD:entrarveh2(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < AUXILIAR)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new vehicleid;
	if (sscanf(params, "d", vehicleid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /entrarveh2 [id do veículo]");
	}

	PutPlayerInVehicle(playerid, vehicleid, 0);
	SendClientMessage(playerid, COLOR_INVALID, "Você foi teleportado pelo Administrador!");
	return 1;
}

YCMD:fogo(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < AUXILIAR)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /fogo [id]");
	}
	if (!IsValidPlayer(id, Player_GetLoggedStatus(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(playerid) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode colocar fogo em um Admin Dono !");
	}

	new string[56];
	new Float:burnx, Float:burny, Float:burnz;
	GetPlayerPos(id, burnx, burny, burnz);
	CreateExplosion(burnx, burny , burnz + 3, 1, 3);
	format(string, sizeof(string), "ADMIN CMD: %s colocou fogo em %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:boasvindas(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < AUXILIAR)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /boasvindas [id]");
	}
	if (!IsValidPlayer(id, Player_GetLoggedStatus(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (Player_GetAdminLevel(id) > HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode das as boas vindas a um admin.");
	}
	if (Player_GetLevel(id) >= 5)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você só pode dar boas vindas a jogadores novatos.");
	}

	new string[280];
    Player_SetHoursPlayed(id, 15);
	Player_SetLevel(id, 5);
	Player_SetCoins(id, 2);
    Player_SaveScoreData(id);
    Player_SaveMoneyData(id);
	format(string, sizeof(string), "{FFFFFF}Parabéns novato, você recebeu:\n{9900ff}> {FFFFFF}Level: {00FF00}5\n{9900ff}> {FFFFFF}Horas Jogadas: {00FF00}15\n{9900ff}> {FFFFFF}Moedas VIP: {00FF00}2\n{FFFFFF}> Todas as licenças para veículos\n{FFFFFF}Administrador: %s\n{FFFFFF}Divulgue o Servidor!", GetPlayerNameCustom(playerid));
	ShowPlayerDialog(id, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Boas Vindas", string, "Fechar", "");
	format(string, sizeof(string), "ADMIN YCMD: %s deu as boas vindas ao jogador %s[%d] [Level: %d | Dinheiro: %s | Moedas VIP| %s].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), id, Player_GetLevel(id), FormatMoneyString(Player_GetMoney(id)), FormatMoneyString(Player_GetCoins(id)));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}