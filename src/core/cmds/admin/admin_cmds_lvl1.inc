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

	// Execução do Comando
	new string[150];
	if (Admin_IsWorking(playerid) == true)
   	{
       	format(string, sizeof(string), "[STAFF]: O Administrador %s(%d) está Jogando!", Player_GetName(playerid), playerid);
       	SendClientMessageToAll(COLOR_GRAD1, string);
		SetPlayerSkin(playerid, skinAdmin[playerid]);
   	}
   	else
   	{
        format(string, sizeof(string), "[STAFF]: O Administrador %s(%d) está Trabalhando!", Player_GetName(playerid), playerid);
        SendClientMessageToAll(COLOR_GRAD1, string);
		skinAdmin[playerid] = GetPlayerSkin(playerid);
		SetPlayerSkin(playerid, (PlayerData_GetGender(playerid) == 1 ? DEFAULT_SKIN_ADMIN_M : DEFAULT_SKIN_ADMIN_F));
   	}
    SetPlayerToTeamColor(playerid);
    Admin_ChangeWorkMode(playerid);
    return 1;
}