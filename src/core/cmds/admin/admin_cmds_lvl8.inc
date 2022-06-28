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
			if (response)
			{
				return ShowPlayerDialog(playerid, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "GMX", "Reinicialização em andamento...\n\nIsso pode demorar alguns segundos\npor favor aguarde!\n\nAgradecemos sua compreensão.", "AGUARDE", "");
			}
		}
	}
	return 1;
}

YCMD:hideadmin(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

	ShowPlayerDialog(playerid, DIALOG_ADMIN_HIDE, DIALOG_STYLE_MSGBOX, "Menu Admin Dono", "Escolha qual modo deseja ficar.", "Oculto", "Exibido");
	return 1;
}

YCMD:verpars(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

	if (Admin_GetViewAllPars(playerid))
	{
		Admin_SetViewAllPars(playerid, false);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você não está mais vendo todos os particulares!");
	}
	else
	{
		Admin_SetViewAllPars(playerid, true);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você está vendo todos os particulares!");
	}
	return 1;
}

YCMD:gmx(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}

    new gmx[84];
	Server_SetIsRestarting(true);
	foreach(new i: Player)
	{
        StopAudioStreamForPlayer(i);
		ShowPlayerDialog(i, DIALOG_GMX, DIALOG_STYLE_MSGBOX, "GMX", "Reinicialização em andamento...\n\nIsso pode demorar alguns segundos\npor favor aguarde!\n\nAgradecemos sua compreensão.", "AGUARDE", "");
	}
    format(gmx,sizeof(gmx),"Admin: %s está reinicializando o servidor, por favor aguarde!", Player_GetName(playerid));
	SendClientMessageToAll(COLOR_YELLOW, gmx);
	SendClientMessageToAll(COLOR_YELLOW, "[SERVIDOR]: Salvamento de dados iniciados...");
	defer RestartServer();
    return 1;
}