#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
timer RestartServer[5000]()
{
	SendClientMessageToAll(COLOR_YELLOW, "[SERVIDOR]: Salvamento de dados concluído.");
	SendClientMessageToAll(COLOR_YELLOW, "[SERVIDOR]: Reinicialização iniciada.");
	print("[Server]: Server is restarting...");
	SendRconCommand("gmx");
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch (dialogid)
	{
		case DIALOG_GMX:
		{
			if (!response) return ShowPlayerDialog(playerid, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "GMX", "Reinicialização em andamento...\n\nIsso pode demorar alguns segundos\npor favor aguarde!\n\nAgradecemos sua compreensão.", "AGUARDE", "");
			if (response) return ShowPlayerDialog(playerid, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "GMX", "Reinicialização em andamento...\n\nIsso pode demorar alguns segundos\npor favor aguarde!\n\nAgradecemos sua compreensão.", "AGUARDE", "");
		}
	}
	return 1;
}

YCMD:gmx(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

    new gmx[84];
	Server_SetIsRestarting(true);
	foreach(new i: Player)
	{
        StopAudioStreamForPlayer(i);
		ShowPlayerDialog(i, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "GMX", "Reinicialização em andamento...\n\nIsso pode demorar alguns segundos\npor favor aguarde!\n\nAgradecemos sua compreensão.", "AGUARDE", "");
	}
    format(gmx,sizeof(gmx),"Admin: %s está reinicializando o servidor, por favor aguarde!", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(COLOR_YELLOW, gmx);
	SendClientMessageToAll(COLOR_YELLOW, "[SERVIDOR]: Salvamento de dados iniciados...");
	defer RestartServer();
    return 1;
}

YCMD:setmoedasvip(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id, coins;
	if (sscanf(params, "ud", id, coins))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setmoedasvip [id] [moedas]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[150];
	Player_SetCoins(playerid, coins);
    format(string, sizeof(string), "ADMIN CMD: O Admin %s setou a quantidade de moedas vip de %s para R$[%d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id), coins);
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	format(string, sizeof(string), "O administrador: %s setou suas moedas para [%s].", GetPlayerNameCustom(playerid), FormatMoneyString(coins));
	SendClientAlert(id, "MOEDAS VIP", string);
    PrintLog(FOLDER_ADMIN_SETCOINS, string);
    return 1;
}

YCMD:darmoedasvip(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id, coins;
	if (sscanf(params, "ud", id, coins))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /darmoedasvip [id] [moedas]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[150];
	Player_SetCoins(playerid, (Player_GetCoins(playerid) + coins));
    format(string, sizeof(string), "ADMIN CMD: O Admin %s está dando [%s] moedas vip para %s.", GetPlayerNameCustom(playerid), FormatMoneyString(coins), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	format(string, sizeof(string), "Voce recebeu [%s] moedas vip do administrador: %s.", FormatMoneyString(coins), GetPlayerNameCustom(playerid));
	SendClientAlert(id, "MOEDAS VIP", string);
    PrintLog(FOLDER_ADMIN_SETCOINS, string);
    return 1;
}

// /removerveiculo

YCMD:hideadmin(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

	ShowPlayerDialog(playerid, DIALOG_ADMIN_HIDE, DIALOG_STYLE_MSGBOX, "Menu Admin Dono", "Escolha qual modo deseja ficar.", "Oculto", "Exibido");
	return 1;
}

YCMD:verpars(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

	if (Admin_GetViewAllPm(playerid))
	{
		Admin_SetViewAllPm(playerid, false);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você não está mais vendo todos os particulares!");
	}
	else
	{
		Admin_SetViewAllPm(playerid, true);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você está vendo todos os particulares!");
	}
	return 1;
}