#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static skinAdmin[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowCommandsListDialog(playerid)
{
	new stringDialog[471], string[47];
	for (new i = 1; i <= PlayerData_GetAdmin(playerid); i++)
	{
		format(string, sizeof(string), "{ff61f3}Administrador » {FFFFFF}%s\n", Admin_GetRole(i));
		strcat(stringDialog, string);
	}
	ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS, DIALOG_STYLE_LIST, "Comandos da Administração", stringDialog, "Selecionar", "Cancelar");
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch (dialogid)
    {
        case DIALOG_ADMIN_CMDS:
		{
			if (!response)
			{
				return SendClientMessage(playerid, COLOR_INVALID, "Você fechou a lista de comandos da administração.");
			}
			if (response)
			{
				switch(listitem)
				{
					case 0: 
					{
						new dialogTitle[25], string[542];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/par /kick /ir /trazer /voar /tapa /tapao /teleportes /kitadm /idcasa /idempresa /tvon /tvoff\n\
														{0080ff}*** | {FFFFFF}/av(avisar) /testegod /paredao /rparedao /teleportes /setspawn /orgvips /android /novatos\n\
														{0080ff}*** | {FFFFFF}/flip /irincendio /dincendio /infocar /menuadm /playersevento /expulsararena\n\
														{0080ff}*** | {FFFFFF}/trabalhar /fila /atender /finalizar /finalizarat /afk\n\n\
														{ff6347}OBS: {5e5f63}Aprendiz você foi colocado no modo admin em fase de testes, então trabalhe corretamente para ser promovido.\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 1: 
					{
						new dialogTitle[25], string[232];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/repararid /blindarid /abastecerid /respawnid /setclima /prendern /limparchat /calar /calarn\n\
														{0080ff}*** | {FFFFFF}/congelar /descongelar /carandiru /carandiruagendados /agendarcarandiru /excluircarandiru\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 2: 
					{
						new dialogTitle[25], string[207];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/1 /2 /3 /go /voaron /orelhas /respawnperto /retirararmas /versms\n\
														{0080ff}*** | {FFFFFF}/saciar /saciarall /banir /desbanir /bansagendados /agendarban /excluirban\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 3: 
					{
						new dialogTitle[25], string[186];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/sethora /ip /rt /lt /dn /up /entrarveh(Passageiro) /entrarveh2(Motorista) /fogo /boasvindas\n\
														{0080ff}*** | {FFFFFF}/tesouro /online /setarevento /destruirgrafite\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 4: 
					{
						new dialogTitle[25], string[192];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/editar /explodir /setskin /irveiculo /trazerveiculo /darlicenceas /retirarlicencas\n\
														{0080ff}*** | {FFFFFF}/abastecercarros /respawncarros /guerrafavela /tempoguerra\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 5: 
					{
						new dialogTitle[25], string[159];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/setworld /setinterior /darcolete /darvida /kill /setgrana /dargrana /mudarimposto\n\
														{0080ff}*** | {FFFFFF}/limparinventario /daritem\n");
						format(dialogTitle, sizeof(string), "dialogTitle do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 6: 
					{
						new dialogTitle[25], string[148];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/setpos /bloquearcaixinha /liberarcaixa /limitecaixa /setarlider /limparlider\n\
														{0080ff}*** | {FFFFFF}/setorgvip /promover\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 7: 
					{
						new dialogTitle[37], string[97];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/gmx /setmoedasvip /removerveh /darmoedasvip /agendarmoedas /dargrafite\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 8: 
					{
						new dialogTitle[25], string[127];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/kitadmdono /deslogartodos /racessorios /verpars /hideadmin\n");
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/tocarsom /pararsom\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
					case 9: 
					{
						new dialogTitle[25], string[247];
						format(string, sizeof(string), "{0080ff}*** | {FFFFFF}/daradmin /retiraradmin /excluirconta /iro /criarcasa /editarcasa\n\
														{0080ff}*** | {FFFFFF}/deletarcasa /deleteallhouses /ircasa /criarempresa /editarempresa\n\
														{0080ff}*** | {FFFFFF}/deletarempresa /deleteallbizz /irempresa\n");
						format(dialogTitle, sizeof(dialogTitle), "Comandos do %s", Admin_GetRole(listitem + 1));
						ShowPlayerDialog(playerid, DIALOG_ADMIN_CMDS2, DIALOG_STYLE_MSGBOX, dialogTitle, string, "Voltar", "Fechar");
					}
				}
				return 1;
			}
		}
		case DIALOG_ADMIN_CMDS2:
		{
			if (!response)
			{
				return SendClientMessage(playerid, COLOR_INVALID, "Você fechou a lista de comandos da administração.");
			}
			if (response)
			{
                return ShowCommandsListDialog(playerid);
			}
		}
    }
    return 1;
}

YCMD:aa(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return 0;
	}
    if (Admin_IsWorking(playerid) == false && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
 		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

	ShowCommandsListDialog(playerid);
    return 1;
}

YCMD:admin(playerid, params[], help) = a;
YCMD:a(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	new text[150];
	if (sscanf(params, "s[150]", text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/a)dmin [chat administração]");
	}
	if (!strlen(text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/a)dmin [chat administração]");
	}

	new string[250];
	format(string, sizeof(string), "Admin[%s] %s: %s", Admin_GetRole(PlayerData_GetAdmin(playerid)), Player_GetName(playerid), text);
	MensagemAdmin(COLOR_LIGHTBLUE, string, HELPER);
    return 1;
}

YCMD:trabalhar(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (Admin_IsAFK(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode entrar em modo de trabalho estando em modo afk.");
	}

	new string[150];
	if (Admin_IsWorking(playerid) == true)
   	{
       	format(string, sizeof(string), "[STAFF]: O Administrador %s(%d) está Jogando!", Player_GetName(playerid), playerid);
       	SendClientMessageToAll(COLOR_GRAD1, string);
		SetPlayerSkin(playerid, skinAdmin[playerid]);
		ResetPlayerWeapons(playerid);
       	SetPlayerHealth(playerid, 100);
		RemovePlayerAttachedObject(playerid, PLAYER_OBJECT_9);
    	RemovePlayerAttachedObject(playerid, PLAYER_OBJECT_10);
		Admin_SetWorkMode(playerid, false);
   	}
   	else
   	{
        format(string, sizeof(string), "[STAFF]: O Administrador %s(%d) está Trabalhando!", Player_GetName(playerid), playerid);
        SendClientMessageToAll(COLOR_GRAD1, string);
		skinAdmin[playerid] = GetPlayerSkin(playerid);
		SetPlayerSkin(playerid, (PlayerData_GetGender(playerid) == 1 ? DEFAULT_SKIN_ADMIN_M : DEFAULT_SKIN_ADMIN_F));
		SetPlayerAttachedObject(playerid, PLAYER_OBJECT_9, 2992, 2, 0.306000, -0.012000, 0.009000, 0.000000, -95.299942, -1.399999, 1.000000, 1.000000, 1.000000);
    	SetPlayerAttachedObject(playerid, PLAYER_OBJECT_10, 2992, 2, 0.313000, -0.007000, 0.032999, -0.299999, 83.700019, 0.000000, 1.000000, 1.000000, 1.000000);
		Admin_SetWorkMode(playerid, true);
   	}
    SetPlayerToTeamColor(playerid);
    return 1;
}

YCMD:afk(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (Admin_IsWorking(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode entrar em modo afk estando em modo trabalho.");
	}
	new converted_reason[120];
	if (isnull(params))
	{
		converted_reason = "Desconhecido";
	}
	else
	{
		if (strlen(params) > 60)
		{
			return SendClientMessage(playerid, COLOR_INVALID, "Digite no máximo 60 dígitos para o motivo.");
		}
		strmid(converted_reason, params, 0, 120, 120);
	}

	new string[142 + 1];
	switch(Admin_IsAFK(playerid))
	{
		case 0:
		{
			Admin_SetAfkMode(playerid, true);
			format(string, sizeof(string), "[Ausência]: O Admin %s entrou em modo ausência por motivo: %s.", Player_GetName(playerid), converted_reason);
		}
		case 1:
		{
			Admin_SetAfkMode(playerid, false);
			format(string, sizeof(string), "[Ausência]: O Admin %s não está mais em modo ausência.", Player_GetName(playerid), converted_reason);
		}
	}
	SendClientMessageToAll(COLOR_SOFTGREY, string);
	return 1;
}

YCMD:kitadm(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}

	new string[51];
	GivePlayerWeapon(playerid, 46, 1);
	GivePlayerWeapon(playerid, 35, 999);
	GivePlayerWeapon(playerid, 24, 299);
	GivePlayerWeapon(playerid, 31, 999);
	GivePlayerWeapon(playerid, 29, 999);
	GivePlayerWeapon(playerid, 25, 999);
	GivePlayerWeapon(playerid, 4, 1);
	GivePlayerWeapon(playerid, 34, 999);
	GivePlayerWeapon(playerid, 43, 999);
	GivePlayerWeapon(playerid, 17, 49);
	GivePlayerWeapon(playerid, 42, 1999);
	SetPlayerArmour(playerid, 100);
	SetPlayerHealth(playerid, 100);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "ADM: {B4B5B7}Você pegou o seu KitAdmin!");
	format(string, sizeof(string), "Admin: %s Pegou Seu KitAdmin.", Player_GetName(playerid));
	SendMessageInRange(30.0, playerid, string, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU);
    return 1;
}

// TO-DO
// /idcasa
// /idempresa

YCMD:tvon(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /tvon [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (PlayerData_GetAdmin(id) >= HELPER_OWNER && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode ficar de TV em um admin Dono.");
	}
	if (id == playerid)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode ficar de TV em si mesmo.");
	}
	if (Admin_GetWatchStatus(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode ficar de TV em outro jogador de TV.");
	}

	if (Admin_GetPlayerSpectated(playerid) == INVALID_PLAYER_ID)
	{
		new Float:pos_x, Float:pos_y, Float:pos_z, int, world;
		GetPlayerPos(playerid, pos_x, pos_y, pos_z);
		int = GetPlayerInterior(playerid);
		world = GetPlayerVirtualWorld(playerid);
		Spectate_SetCoords(playerid, pos_x, pos_y, pos_z, int, world);
	}
	Admin_SetPlayerSpectated(playerid, id);
	Admin_SetWatchStatus(playerid, true);
	SetPlayerInterior(playerid, GetPlayerInterior(id));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(id));
	TogglePlayerSpectating(playerid, true);
	if (IsPlayerInAnyVehicle(id)) PlayerSpectateVehicle(playerid, GetPlayerVehicleID(id));
	else PlayerSpectatePlayer(playerid, id);
	Admin_StartSpectate(playerid);
	ShowSpectatePlayer(playerid, id);
	return 1;
}

YCMD:tvoff(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	if (!Admin_GetWatchStatus(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está de TV em jogador nenhum.");
	}

	new Float:pos_x, Float:pos_y, Float:pos_z, int, world;
	Spectate_GetCoords(playerid, pos_x, pos_y, pos_z, int, world);

	Admin_SetPlayerSpectated(playerid, INVALID_PLAYER_ID);
	Admin_SetWatchStatus(playerid, false);
	TogglePlayerControllable(playerid, true);
	TogglePlayerSpectating(playerid, false);
	SetPlayerInterior(playerid, int);
	SetPlayerVirtualWorld(playerid, world);
	SetSpawnInfo(playerid, -1, PlayerData_GetSkin(playerid), pos_x,  pos_y, pos_z-1.0, 1.0, -1, -1, -1, -1, -1, -1);
	SetPlayerToTeamColor(playerid);
	HideSpectatePlayer(playerid);
	Admin_StopSpectate(playerid);
	SpawnPlayer(playerid);
	return 1;
}

YCMD:par(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id, result[150];
	if (sscanf(params, "us[150]", id, result))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /par [id] [mensagem]");
	}
	if (!strlen(result))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /par [id] [mensagem]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[200];
	format(string, sizeof(string), "%s[%d] particular: %s.", Player_GetName(playerid), playerid, (result));
	Admin_SendParMessage(playerid, id, COLOR_YELLOW, string);
	Server_PrintLog(FOLDER_ADMIN_PAR, string);
	format(string, sizeof(string), "PM enviada para %s(ID: %d).", Player_GetName(id), id, result);
	SendClientMessage(playerid, COLOR_YELLOW, string);
	return 1;
}

YCMD:kick(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id, reason[100];
	if (sscanf(params, "us[100]", id, reason))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /kick [id] [motivo]");
	}
	if (!strlen(reason))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /kick [id] [motivo]");
	}
	if (id == playerid)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "Você não pode dar um kick em si mesmo.");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[190];
	format(string, sizeof(string), "ADMIN CMD: %s foi kickado por %s. [Motivo]: %s.", Player_GetName(id), Player_GetName(playerid), (reason));
	SendClientMessageToAll(COLOR_LIGHTRED, string);
	KickPlayer(id);
	return 1;
}

YCMD:ir(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	if (Admin_GetWatchStatus(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode teleportar estando de TV.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /ir [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[66];
	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(id, x, y, z);
	GetPlayerFacingAngle(id, a);
	StopAudioStreamForPlayer(playerid);
	PlayerData_SetInteriorLocale(playerid, PlayerData_GetInteriorLocale(id));
	TeleportPlayer(playerid, x, y+4, z, a, GetPlayerInterior(id), GetPlayerVirtualWorld(id));
	SendClientMessage(playerid, 0x33FF00FF, "Você foi teleportado pelo Administrador !");
    format(string, sizeof(string), "O Admin %s Foi Até %s.", Player_GetName(playerid), Player_GetName(id));
	SendMessageInRange(30.0, playerid, string, 0x33FF00FF, 0x33FF00FF, 0x33FF00FF, 0x33FF00FF, 0x33FF00FF);
	return 1;
}

YCMD:trazer(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /trazer [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[63];
	new Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);
	StopAudioStreamForPlayer(playerid);
	PlayerData_SetInteriorLocale(id, PlayerData_GetInteriorLocale(playerid));
	TeleportPlayer(id, x, (y+4), z, a, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
	SendClientMessage(id, 0x33FF00FF, "Você foi teleportado pelo Admin !");
	format(string, sizeof(string), "Admin %s Trouxe %s.", Player_GetName(playerid), Player_GetName(id));
	SendMessageInRange(30.0, playerid, string, COLOR_NEONGREEN, COLOR_NEONGREEN, COLOR_NEONGREEN, COLOR_NEONGREEN, COLOR_NEONGREEN);
	return 1;
}

YCMD:voar(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}

	new Float:px, Float:py, Float:pz, Float:pa;
	GetPlayerFacingAngle(playerid,pa);
	if (pa >= 0.0 && pa <= 22.5) //n1
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px, py+30, pz+5);
	}
	else if (pa >= 332.5 && pa < 0.0) //n2
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px, py+30, pz+5);
	}
	else if (pa >= 22.5 && pa <= 67.5) //nw
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px-15, py+15, pz+5);
	}
	else if (pa >= 67.5 && pa <= 112.5) //w
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px-30, py, pz+5);
	}
	else if (pa >= 112.5 && pa <= 157.5) //sw
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px-15, py-15, pz+5);
	}
	else if (pa >= 157.5 && pa <= 202.5) //s
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px, py-30, pz+5);
	}
	else if (pa >= 202.5 && pa <= 247.5)//se
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px+15, py-15, pz+5);
	}
	else if (pa >= 247.5 && pa <= 292.5)//e
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px+30, py, pz+5);
	}
	else if (pa >= 292.5 && pa <= 332.5)//e
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerPos(playerid, px+15, py+15, pz+5);
	}
	else
	{
	    GetPlayerPos(playerid, px, py, pz);
	    SetPlayerPos(playerid, px+15, py+15, pz+5);
	}
    return 1;
}

YCMD:tapa(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /tapa [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (PlayerData_GetAdmin(id) >= HELPER_OWNER && PlayerData_GetAdmin(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode dar tapa em um Admin Dono !");
	}

	new string[80];
	new Float:x, Float:y, Float:z;
	GetPlayerPos(id, x, y, z);
	SetPlayerPos(id, x, y, z+12);
	PlayerPlaySound(id, 1130, x, y, z+12);
	format(string, sizeof(string), "ADMIN CMD: %s ganhou um tapa de: %s.", Player_GetName(id), Player_GetName(playerid));
	MensagemAdmin(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:tapao(playerid, params[], help)
{
    if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /tapao [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (PlayerData_GetAdmin(id) >= HELPER_OWNER && PlayerData_GetAdmin(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode dar tapão em um Admin Dono !");
	}

	new string[81];
	new Float:x, Float:y, Float:z;
	GetPlayerPos(id, x, y, z);
	SetPlayerPos(id, x, y, z+130);
	SetPlayerHealth(id, 100.0);
	PlayerPlaySound(id, 1130, x, y, z+130);
	format(string, sizeof(string), "ADMIN CMD: %s ganhou um tapao de: %s.", Player_GetName(id), Player_GetName(playerid));
	MensagemAdmin(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:av(playerid, params[], help) = avisar;
YCMD:avisar(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	new text[150];
	if (sscanf(params, "s[150]", text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/av)isar [texto]");
	}
	if (!strlen(text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/av)isar [texto]");
	}
    if (TentouDivulgar(text))
	{
	    new stringd[215];
		format(stringd, sizeof(stringd), "[ADMIN ALERTA]: %s[%d] tentou divulgar: %s.", Player_GetName(playerid), playerid, text);
		MensagemAdmin(COLOR_YELLOW, stringd, HELPER);
		Server_PrintLog(FOLDER_ANTICHEAT_ADVERTISING, stringd);
		return 1;
	}

	new string[182];
	SendClientMessageToAll(COLOR_DBLUE, "|__________________[ Aviso dos Admins ]__________________|");
	format(string, sizeof(string), "Admin {FFFFFF}%s{f04b87}: %s", Player_GetName(playerid), text);
	SendClientMessageToAll(COLOR_PINK, string);
    return 1;
}

YCMD:testegod(playerid, params[], help)
{
    if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /testegod [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (PlayerData_GetAdmin(id) >= HELPER_OWNER && PlayerData_GetAdmin(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode dar testegod em um Admin Dono !");
	}

	new string[82];
	new Float:x, Float:y, Float:z;
	new Float:boomx, Float:boomy, Float:boomz;
	GetPlayerPos(id, x, y, z);
	SetPlayerPos(id, x, y, z+12);
	GetPlayerPos(id, boomx, boomy, boomz);
	CreateExplosion(boomx, boomy , boomz, 7, 10);
	PlayerPlaySound(id, 1130, x, y, z+12);
    if (Admin_IsWorking(playerid) && Admin_GetHideStatus(playerid))
    {
		format(string, sizeof(string), "Adm-Cmd: %s ganhou um Teste God de: Anônimo.", Player_GetName(id));
	}
    else
    {
		format(string, sizeof(string), "Adm-Cmd: %s ganhou um Teste God By: %s.", Player_GetName(id), Player_GetName(playerid));
	}
	MensagemAdmin(COLOR_LIGHTRED, string, HELPER);
    SendClientMessage(playerid, COLOR_LIGHTRED, "[ATENÇÃO] Verifique se o player não está com o relógio travado.");
	return 1;
}

// TO-DO
// /paredao
// /rparedao
// /teles

YCMD:setspawn(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setspawn [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}

	new string[85 + 1];
	SpawnPlayer(id);
	format(string, sizeof(string), "ADMIN CMD: %s setou: %s para o seu spawn.", Player_GetName(playerid), Player_GetName(id));
	MensagemAdmin(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

// TO-DO
// /orgvips

YCMD:infoplayer(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_IsWorking(playerid) && PlayerData_GetAdmin(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está trabalhando! (/trabalhar)");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /infoplayer [id]");
	}
	if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (PlayerData_GetAdmin(id) >= HELPER_OWNER && PlayerData_GetAdmin(playerid) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode dar tapa em um Admin Dono !");
	}

	new infoPlayer[150], string[80];
	format(string, sizeof(string), "Nome: %s\n", Player_GetName(id));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "Level: %d\n", PlayerData_GetLevel(id));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "IP: %s\n", Player_GetIP(id));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "Moedas VIP: %s\n", Server_FormatToMoney(PlayerData_GetCoins(id)));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "Arma: %s\n", Server_GetWeaponName(GetPlayerWeapon(id)));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "Munição: %d\n", Server_GetWeaponAmmo(id, GetPlayerWeapon(id)));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "Vida: %.0f\n", Player_GetHealth(id));
	strcat(infoPlayer, string);
	format(string, sizeof(string), "Colete: %.0f\n", Player_GetArmour(id));
	strcat(infoPlayer, string);
	strcat(infoPlayer, (!PlayerData_GetIsUsingAndroid(id) ? "Plataforma: PC" : "Plataforma: Android"));
	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_LIST, "Informações do Jogador", infoPlayer, "Fechar", "");
	return 1;
}

YCMD:android(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}

	new string[39 + 1];
	SendClientMessage(playerid, COLOR_NEONGREEN, "Jogadores Android (Possivelmente):");
	foreach (new i : Player)
	{
		if (PlayerData_GetIsUsingAndroid(i))
		{	format(string, sizeof(string), "Jogador: %s[%d]", Player_GetName(i), i);
			SendClientMessage(playerid, COLOR_GRAD2, string);
		}
	}
	return 1;
}

YCMD:novatos(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}

	new string[60];
	SendClientMessage(playerid, COLOR_NEONGREEN, "Jogadores Novatos:");
	foreach (new i : Player)
	{
		if (PlayerData_GetLevel(i) < 5)
		{	format(string, sizeof(string), "Jogador: %s[%d] - Level [%d]", Player_GetName(i), i, PlayerData_GetLevel(i));
			SendClientMessage(playerid, COLOR_GRAD2, string);
		}
	}
	return 1;
}

YCMD:flip(playerid, params[], help)
{
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está em um veículo.");
	}

	new currentveh = GetPlayerVehicleID(playerid), Float:angle;
	GetVehicleZAngle(currentveh, angle);
	SetVehicleZAngle(currentveh, angle);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você desvirou seu veículo.");
	return 1;
}

// TO-DO
// /irincendio
// /dincendio
// /menuadm
// /playersevento
// /expulsararena
// /fila
// /atender
// /finalizarat
// /finalizar