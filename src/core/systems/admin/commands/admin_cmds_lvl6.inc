#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
YCMD:setworld(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, worldid;
	if (sscanf(params, "ud", id, worldid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setworld [id] [id do mundo]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[99];
	SetPlayerVirtualWorld(id, worldid);
	format(string, sizeof(string), "* Voc� colocou o(a) %s no virtual world [%d].", GetPlayerNameCustom(id), worldid);
    SendClientMessage(playerid, COLOR_LIGHTRED, string);
    format(string, sizeof(string), "[Administra��o]: %s setou %s no virtual world %d", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), worldid);
    SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    return 1;
}

YCMD:setinterior(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, interiorid;
	if (sscanf(params, "ud", id, interiorid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setinterior [id] [id do interior]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[95];
	SetPlayerInterior(id, interiorid);
	format(string, sizeof(string), "* Voc� colocou o(a) %s no interior [%d].", GetPlayerNameCustom(id), interiorid);
    SendClientMessage(playerid, COLOR_LIGHTRED, string);
    format(string, sizeof(string), "[Administra��o]: %s setou %s no interior %d.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), interiorid);
    SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    return 1;
}

YCMD:darcolete(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, quantidade;
	if (sscanf(params, "ud", id, quantidade))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /darcolete [id] [quantidade]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[110];
	SetPlayerArmour(id, quantidade);
	format(string, sizeof(string), "* Voc� deu %d de colete para o jogador %s.", quantidade, GetPlayerNameCustom(id));
    SendClientMessage(playerid, COLOR_INVALID, string);
    format(string, sizeof(string), "O Administrador %s te deu %d de colete.", GetPlayerNameCustom(playerid), quantidade);
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administra��o]: %s setou o colete do jogador %s para %.02f.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), quantidade);
    SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    return 1;
}

YCMD:darvida(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, quantidade;
	if (sscanf(params, "ud", id, quantidade))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /darvida [id] [quantidade]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (quantidade < 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Para matar o jogador, use: /kill.");
	}

	new string[108];
	SetPlayerHealth(id, quantidade);
	format(string, sizeof(string), "* Voc� deu %d de vida para o jogador %s.", quantidade, GetPlayerNameCustom(id));
    SendClientMessage(playerid, COLOR_INVALID, string);
    format(string, sizeof(string), "O Administrador %s te deu %d de vida.", GetPlayerNameCustom(playerid), quantidade);
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administra��o]: %s setou a vida do jogador %s para %.02f.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), quantidade);
    SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    return 1;
}

YCMD:matar(playerid, params[], help) = kill;
YCMD:kill(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /kill [id]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[84];
	if (IsPlayerInAnyVehicle(id))
	{
		RemovePlayerFromVehicle(id);
	}
	SetPlayerHealth(id, 0);
	format(string, sizeof(string), "* Voc� matou o jogador %s.", GetPlayerNameCustom(id));
    SendClientMessage(playerid, COLOR_INVALID, string);
    format(string, sizeof(string), "O Administrador %s te matou.", GetPlayerNameCustom(playerid));
    SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administra��o]: %s matou o jogador %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
    SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    return 1;
}

YCMD:setgrana(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, money;
	if (sscanf(params, "ud", id, money))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setgrana [id] [money]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (money > 10000000)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o digite um valor t�o alto.");
	}

	new string[110], moneyString[MAX_MONEY_STRING];
	Player_SetMoney(id, money);
	FormatMoneyString(money, moneyString);
    format(string, sizeof(string), "[Administra��o]: %s setou a grana de %s para R$[%s].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), moneyString);
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    PrintLog(FOLDER_ADMIN_SETMONEY, string);
    return 1;
}

YCMD:dargrana(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTERP)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, money;
	if (sscanf(params, "ud", id, money))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /dargrana [id] [money]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (money > 10000000)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o digite um valor t�o alto.");
	}

	new string[97], moneyString[MAX_MONEY_STRING];
	FormatMoneyString(money, moneyString);
	Player_SetMoney(id, (Player_GetMoney(id) + money));
    format(string, sizeof(string), "[Administra��o]: %s est� dando R$[%s] para %s.", GetPlayerNameCustom(playerid), moneyString, GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
    PrintLog(FOLDER_ADMIN_SETMONEY, string);
    return 1;
}

// /limparinventario