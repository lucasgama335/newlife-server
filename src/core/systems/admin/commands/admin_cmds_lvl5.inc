#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsToEditPlayer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Commands (Module related commands) -------------------------
static stock ShowPlayerEditMenu(playerid, id)
{
	new string[33], dialogString[142], formatedNumber[MAX_MONEY_STRING];

	FormatMoneyString(Player_GetLevel(id), formatedNumber);
	format(string, sizeof(string), "N�vel: %s\n", formatedNumber);
	strcat(dialogString, string);

	FormatMoneyString(Player_GetExperience(id), formatedNumber);
	format(string, sizeof(string), "Experi�ncia: %s\n", formatedNumber);
	strcat(dialogString, string);

	FormatMoneyString(Player_GetHoursPlayed(id), formatedNumber);
	format(string, sizeof(string), "Horas Jogadas: %s\n", formatedNumber);
	strcat(dialogString, string);

	FormatMoneyString(Player_GetDeaths(id), formatedNumber);
	format(string, sizeof(string), "Mortes: %s\n", formatedNumber);
	strcat(dialogString, string);

	FormatMoneyString(Player_GetKills(id), formatedNumber);
	format(string, sizeof(string), "Kills: %s\n", formatedNumber);
	strcat(dialogString, string);

	FormatMoneyString(Player_GetWantedLevel(id), formatedNumber);
	format(string, sizeof(string), "N�vel de Procurado: %s\n", formatedNumber);
	strcat(dialogString, string);

	format(string, sizeof(string), "Tempo de Sal�rio: %02d:%02d", (Player_GetPaydayTime(id) / 60), (Player_GetPaydayTime(id) % 60));
	strcat(dialogString, string);

	format(string, sizeof(string), "Editar: %s", GetPlayerNameCustom(id));
	ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER, DIALOG_STYLE_LIST, string, dialogString, "Selecionar", "Fechar");
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	gsToEditPlayer[playerid] = INVALID_VALUE;
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, const inputtext[])
{
	switch (dialogid)
	{
		case DIALOG_EDIT_PLAYER:
		{
			if (!response)
			{
				gsToEditPlayer[playerid] = INVALID_VALUE;
				return 1;
			}
			if (response)
			{
				switch (listitem)
				{
					case 0:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_LEVEL, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}N�vel.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe o n�vel desejado para ser alterado\nna conta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas n�meros inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 1:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_EXPERIENCE, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Experi�ncia.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe a quantidade de experi�ncia desejada\npara ser editada na conta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas n�meros inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 2:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_HOURS_PLAYED, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Horas Jogadas.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe a quantidade dehoras jogadas\n desejada para ser editada na conta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas n�meros inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 3:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_DEATHS, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Mortes.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe a quantidade do n�mero de vezes\nque o jogador morreu para ser editada na\nconta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas n�meros inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 4:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_KILLS, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Kills.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe a quantidade do n�mero de vezes\nque o jogador matou para ser editada na\nconta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas n�meros inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 5:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_WANTED_LEVEL, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}N�vel de Procurado.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe a quantidade do  n�vel de procurado\npela pol�cia do jogador para ser editada na\nconta.\n\n{ff6347}OBS: {8C8C8C}Digite apenas n�meros inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 6:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edi��o de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_PAYDAY_TIME, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Tempo de Sal�rio.\n\n{C2A2DA}Modo de Edi��o:\n{FFFFFF}Informe a quantidade de tempo restante\npara que o jogador ganhe o sal�rio atual.\n\n{ff6347}OBS: {8C8C8C}Digite o n�mero de segundos necess�rios\npara o sal�rio.\nLembre-se: (1 hora = 3600 segundos).", "Editar", "Voltar");
						return 1;
					}
				}
			}
		}

		case DIALOG_EDIT_PLAYER_LEVEL:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) <= 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[133];
				Player_SetLevel(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: N�vel | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}

		case DIALOG_EDIT_PLAYER_EXPERIENCE:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[140];
				Player_SetExperience(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: Experi�ncia | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}

		case DIALOG_EDIT_PLAYER_HOURS_PLAYED:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[144];
				Player_SetHoursPlayed(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: Horas Jogadas | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}

		case DIALOG_EDIT_PLAYER_DEATHS:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[135];
				Player_SetDeaths(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: Mortes | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}

		case DIALOG_EDIT_PLAYER_KILLS:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[134];
				Player_SetKills(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: Matou | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}

		case DIALOG_EDIT_PLAYER_WANTED_LEVEL:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[145];
				Player_SetWantedLevel(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: N�vel de Procurado | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}

		case DIALOG_EDIT_PLAYER_PAYDAY_TIME:
		{
			if (!response)
			{
				return ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
			}
			if (response)
			{
				if (!IsValidPlayer(gsToEditPlayer[playerid]))
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador v�lido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: N�o informe um valor t�o alto.");
				}

				new string[144];
				Player_SetPaydayTime(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveStatusData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administra��o]: %s editou a conta do jogador %s - [Propriedade: Tempo de Sal�rio | Valor: %02d:%02d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), (strval(inputtext) / 60), (strval(inputtext) % 60));
				SendAdminMessage(COLOR_YELLOW, string, HELPER);
				ShowPlayerEditMenu(playerid, gsToEditPlayer[playerid]);
				return 1;
			}
		}
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:editar(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /editar [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER && Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode editar um administrador.");
	}

	gsToEditPlayer[playerid] = id;
	ShowPlayerEditMenu(playerid, id);
	return 1;
}

YCMD:explodir(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /explodir [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(playerid) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode explodir um Admin Dono !");
	}

	new string[87], Float:boomx, Float:boomy, Float:boomz;
	SetPlayerHealth(id, 10);
	GetPlayerPos(id, boomx, boomy, boomz);
	CreateExplosion(boomx, boomy , boomz, 7, 10);
	format(string, sizeof(string), "[Administra��o]: %s explodiu o jogador %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:setskin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, skinid;
	if (sscanf(params, "ud", id, skinid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setskin [id] [id da skin]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[60];
    Player_SetOldSkin(id, GetPlayerSkin(id));
    Player_SetSkin(id, skinid);
	format(string, sizeof(string), "O admin %s mudou sua skin para %d.", GetPlayerNameCustom(playerid), skinid);
	SendClientMessage(id, COLOR_WHITE, string);
	format(string, sizeof(string), "Voc� mudou a skin do %s para %d.", GetPlayerNameCustom(id), skinid);
	SendClientMessage(playerid, COLOR_WHITE, string);
    SetPlayerSkin(id, Player_GetSkin(id));
    return 1;
}

YCMD:irveiculo(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new vid;
	if (sscanf(params, "d", vid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /irveiculo [id do ve�culo]");
	}
	if (!IsValidVehicle(vid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O ID informado � inv�lido.");
	}

	new Float:x, Float:y, Float:z;
	GetVehiclePos(vid, x, y, z);
	SetPlayerPos(playerid, x, (y + 4), z);
	SendClientMessage(playerid, COLOR_PURPLE, "Voc� foi at� o ve�culo!");
	return 1;
}

YCMD:trazerveiculo(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new vid;
	if (sscanf(params, "d", vid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /trazerveiculo [id do ve�culo]");
	}
	if (!IsValidVehicle(vid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O ID informado � inv�lido.");
	}

    new interiorid = GetPlayerInterior(playerid);
    new virtualid = GetPlayerVirtualWorld(playerid);
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	SetVehiclePos(vid, x, (y + 4), z);
	LinkVehicleToInterior(vid, interiorid);
	SetVehicleVirtualWorld(vid, virtualid);
	SendClientMessage(playerid, COLOR_PURPLE, "Voc� trouxe um carro para perto de voc�!");
	return 1;
}

CMD:darlicencas(playerid, params[])
{
    if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /darlicencas [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[96];
	Player_SetCarLicense(playerid, 80);
	Player_SetMotorCycleLicense(playerid, 70);
	Player_SetFlyLicense(playerid, 110);
	Player_SetBoatLicense(playerid, 90);
	Player_SetTruckLicense(playerid, 100);
	Player_SetGunLicense(playerid, 120);
	Player_SaveLicensesData(playerid);
    format(string, sizeof(string), "O administrador: %s lhe deu todas as licen�as.", GetPlayerNameCustom(playerid));
	SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administra��o]: %s deu todas as licen�as para: %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

CMD:retirarlicencas(playerid, params[])
{
	if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /retirarlicencas [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[92];
	ResetPlayerWeapons(id);
	Player_SetCarLicense(playerid, 0);
	Player_SetMotorCycleLicense(playerid, 0);
	Player_SetFlyLicense(playerid, 0);
	Player_SetBoatLicense(playerid, 0);
	Player_SetTruckLicense(playerid, 0);
	Player_SetGunLicense(playerid, 0);
	Player_SaveLicensesData(playerid);
    format(string, sizeof(string), "O administrador: %s retirou todas as suas licen�as.", GetPlayerNameCustom(playerid));
	SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administra��o]: %s retirou as licen�as de: %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:abastecercarros(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	new string[69];
	RefuelAllVehicles();
	format(string, sizeof(string), "[Administra��o]: %s abasteceu todos os carros.", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(COLOR_LIGHTRED, string);
	return 1;
}

YCMD:rcall(playerid, params[], help) = respawncarros;
YCMD:respawncarros(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	new string[83];
	RespawnAllVehicles();
	format(string, sizeof(string), "[Administra��o]: %s respawnou todos os ve�culos do servidor.", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(0x80FF8096, string);
	return 1;
}

// /guerrafavela
// /guerracasarao
// /tempoguerra
// /respawnorg
// /darlicencas
// /retirarlicencas