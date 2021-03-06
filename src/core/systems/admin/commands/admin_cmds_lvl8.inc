#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------
function:RestartServer()
{
	SendClientMessageToAll(COLOR_YELLOW, "[Servidor]: Salvamento de dados conclu�do.");
	SendClientMessageToAll(COLOR_YELLOW, "[Servidor]: Reinicializa��o iniciada.");
	print("[Server]: Server is restarting...");
	SendRconCommand("gmx");
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused listitem // need this directive, on account of YSI which shows warnings in case the parameter is not used.
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	switch (dialogid)
	{
		case DIALOG_GMX:
		{
			if (!response) return ShowPlayerDialog(playerid, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "{FFFFFF}Reinicializa��o do Servidor", "{B4B5B7}Aviso: {ED801A}GMX{FFFFFF} [Reiniciliza��o].\n\n{B4B5B7}Status: {FFFFFF}Processo de reinicializa��o iniciado.\n\n{B4B5B7}Objetivo: \n{FFFFFF}A reinicializa��o do servidor � realizada\npara introduzir novos sistemas, corre��es de bugs\nou em alguma situa��o expecional. Nesse processo \ntodos os dados de jogadores e do servidor s�o salvos.\n\n{ff6347}Importante: \n{FFFFFF}Esse processo pode demorar alguns segundos, aguarde.\nCaso voc� tenha problemas para se conectar ap�s o gmx,\n feche o seu jogo e entre novamente.\n\n{87ED34}Agradecemos a sua compreens�o.", "Entendido", "");
			if (response) return ShowPlayerDialog(playerid, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "{FFFFFF}Reinicializa��o do Servidor", "{B4B5B7}Aviso: {ED801A}GMX{FFFFFF} [Reiniciliza��o].\n\n{B4B5B7}Status: {FFFFFF}Processo de reinicializa��o iniciado.\n\n{B4B5B7}Objetivo: \n{FFFFFF}A reinicializa��o do servidor � realizada\npara introduzir novos sistemas, corre��es de bugs\nou em alguma situa��o expecional. Nesse processo \ntodos os dados de jogadores e do servidor s�o salvos.\n\n{ff6347}Importante: \n{FFFFFF}Esse processo pode demorar alguns segundos, aguarde.\nCaso voc� tenha problemas para se conectar ap�s o gmx,\n feche o seu jogo e entre novamente.\n\n{87ED34}Agradecemos a sua compreens�o.", "Entendido", "");
		}
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:gmx(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

    new gmx[91 + 1];
	Server_SetIsRestarting(true);
	foreach(new i: Player)
	{
        StopAudioStreamForPlayer(i);
		ShowPlayerDialog(i, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "{FFFFFF}Reinicializa��o do Servidor", "{B4B5B7}Aviso: {ED801A}GMX{FFFFFF} [Reiniciliza��o].\n\n{B4B5B7}Status: {FFFFFF}Processo de reinicializa��o iniciado.\n\n{B4B5B7}Objetivo: \n{FFFFFF}A reinicializa��o do servidor � realizada\npara introduzir novos sistemas, corre��es de bugs\nou em alguma situa��o expecional. Nesse processo \ntodos os dados de jogadores e do servidor s�o salvos.\n\n{ff6347}Importante: \n{FFFFFF}Esse processo pode demorar alguns segundos, aguarde.\nCaso voc� tenha problemas para se conectar ap�s o gmx,\n feche o seu jogo e entre novamente.\n\n{87ED34}Agradecemos a sua compreens�o.", "Entendido", "");
	}
    format(gmx,sizeof(gmx),"[Administra��o]: %s est� reinicializando o servidor, por favor aguarde!", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(COLOR_YELLOW, gmx);
	SendClientMessageToAll(COLOR_YELLOW, "[Servidor]: Salvamento de dados iniciado...");
	SetTimer("RestartServer", 5000, false);
    return 1;
}

YCMD:setmoedasvip(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, coins;
	if (sscanf(params, "ud", id, coins))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setmoedasvip [id] [moedas]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[126], coinsString[MAX_MONEY_STRING];
	FormatMoneyString(coins, coinsString);
	Player_SetCoins(playerid, coins);
    format(string, sizeof(string), "[Administra��o]: O Admin %s setou a quantidade de moedas vip de %s para %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), coinsString);
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	format(string, sizeof(string), "O administrador: %s setou suas moedas para [%s].", GetPlayerNameCustom(playerid), coinsString);
	SendClientAlert(id, "MOEDAS VIP", string);
    PrintLog(FOLDER_ADMIN_SETCOINS, string);
    return 1;
}

YCMD:darmoedasvip(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, coins;
	if (sscanf(params, "ud", id, coins))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /darmoedasvip [id] [moedas]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[107], coinsString[MAX_MONEY_STRING];
	FormatMoneyString(coins, coinsString);
	Player_SetCoins(playerid, (Player_GetCoins(playerid) + coins));
    format(string, sizeof(string), "[Administra��o]: %s est� dando [%s] moedas vip para %s.", GetPlayerNameCustom(playerid), coinsString, GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	format(string, sizeof(string), "Voce recebeu [%s] moedas vip do administrador: %s.", coinsString, GetPlayerNameCustom(playerid));
	SendClientAlert(id, "MOEDAS VIP", string);
    PrintLog(FOLDER_ADMIN_SETCOINS, string);
    return 1;
}

// /removerveiculo

YCMD:hideadmin(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	ShowPlayerDialog(playerid, DIALOG_ADMIN_HIDE, DIALOG_STYLE_MSGBOX, "Menu Admin Dono", "Escolha qual modo deseja ficar.", "Oculto", "Exibido");
	return 1;
}

YCMD:verpars(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	if (Admin_GetViewAllPm(playerid))
	{
		Admin_SetViewAllPm(playerid, false);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Voc� n�o est� mais vendo todos os particulares!");
	}
	else
	{
		Admin_SetViewAllPm(playerid, true);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Voc� est� vendo todos os particulares!");
	}
	return 1;
}