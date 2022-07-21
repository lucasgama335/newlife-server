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
	format(string, sizeof(string), "Nível: %s\n", formatedNumber);
	strcat(dialogString, string);

	FormatMoneyString(Player_GetExperience(id), formatedNumber);
	format(string, sizeof(string), "Experiência: %s\n", formatedNumber);
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
	format(string, sizeof(string), "Nível de Procurado: %s\n", formatedNumber);
	strcat(dialogString, string);

	format(string, sizeof(string), "Tempo de Salário: %02d:%02d", (Player_GetPaydayTime(id) / 60), (Player_GetPaydayTime(id) % 60));
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
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_LEVEL, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Nível.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe o nível desejado para ser alterado\nna conta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas números inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 1:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_EXPERIENCE, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Experiência.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe a quantidade de experiência desejada\npara ser editada na conta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas números inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 2:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_HOURS_PLAYED, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Horas Jogadas.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe a quantidade dehoras jogadas\n desejada para ser editada na conta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas números inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 3:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_DEATHS, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Mortes.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe a quantidade do número de vezes\nque o jogador morreu para ser editada na\nconta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas números inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 4:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_KILLS, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Kills.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe a quantidade do número de vezes\nque o jogador matou para ser editada na\nconta do jogador.\n\n{ff6347}OBS: {8C8C8C}Digite apenas números inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 5:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_WANTED_LEVEL, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Nível de Procurado.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe a quantidade do  nível de procurado\npela polícia do jogador para ser editada na\nconta.\n\n{ff6347}OBS: {8C8C8C}Digite apenas números inteiros.", "Editar", "Voltar");
						return 1;
					}
					case 6:
					{
						new dialogTitle[(26 + MAX_PLAYER_NAME)];
						format(dialogTitle, sizeof(dialogTitle), "{FFFFFF}Edição de Conta: %s.", GetPlayerNameCustom(gsToEditPlayer[playerid]));
						ShowPlayerDialog(playerid, DIALOG_EDIT_PLAYER_PAYDAY_TIME, DIALOG_STYLE_INPUT, dialogTitle, "{C2A2DA}Propriedade: {FFFFFF}Tempo de Salário.\n\n{C2A2DA}Modo de Edição:\n{FFFFFF}Informe a quantidade de tempo restante\npara que o jogador ganhe o salário atual.\n\n{ff6347}OBS: {8C8C8C}Digite o número de segundos necessários\npara o salário.\nLembre-se: (1 hora = 3600 segundos).", "Editar", "Voltar");
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) <= 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[133];
				Player_SetLevel(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Nível | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[140];
				Player_SetExperience(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Experiência | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[144];
				Player_SetHoursPlayed(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Horas Jogadas | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[135];
				Player_SetDeaths(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Mortes | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[134];
				Player_SetKills(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Matou | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[145];
				Player_SetWantedLevel(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveScoreData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Nível de Procurado | Valor: %d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), strval(inputtext));
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
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador válido.");
				}
				if (strval(inputtext) < 0)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Digite um valor maior que 0.");
				}
				if (strval(inputtext) > 1000)
				{
					return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Não informe um valor tão alto.");
				}

				new string[144];
				Player_SetPaydayTime(gsToEditPlayer[playerid], strval(inputtext));
				Player_SaveStatusData(gsToEditPlayer[playerid]);
				format(string, sizeof(string), "[Administração]: %s editou a conta do jogador %s - [Propriedade: Tempo de Salário | Valor: %02d:%02d].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(gsToEditPlayer[playerid]), (strval(inputtext) / 60), (strval(inputtext) % 60));
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
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /editar [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER && Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode editar um administrador.");
	}

	gsToEditPlayer[playerid] = id;
	ShowPlayerEditMenu(playerid, id);
	return 1;
}

YCMD:explodir(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /explodir [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(playerid) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode explodir um Admin Dono !");
	}

	new string[87], Float:boomx, Float:boomy, Float:boomz;
	SetPlayerHealth(id, 10);
	GetPlayerPos(id, boomx, boomy, boomz);
	CreateExplosion(boomx, boomy , boomz, 7, 10);
	format(string, sizeof(string), "[Administração]: %s explodiu o jogador %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:setskin(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new id, skinid;
	if (sscanf(params, "ud", id, skinid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setskin [id] [id da skin]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}

	new string[60];
    Player_SetOldSkin(id, GetPlayerSkin(id));
    Player_SetSkin(id, skinid);
	format(string, sizeof(string), "O admin %s mudou sua skin para %d.", GetPlayerNameCustom(playerid), skinid);
	SendClientMessage(id, COLOR_WHITE, string);
	format(string, sizeof(string), "Você mudou a skin do %s para %d.", GetPlayerNameCustom(id), skinid);
	SendClientMessage(playerid, COLOR_WHITE, string);
    SetPlayerSkin(id, Player_GetSkin(id));
    return 1;
}

YCMD:irveiculo(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new vid;
	if (sscanf(params, "d", vid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /irveiculo [id do veículo]");
	}
	if (!IsValidVehicle(vid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O ID informado é inválido.");
	}

	new Float:x, Float:y, Float:z;
	GetVehiclePos(vid, x, y, z);
	SetPlayerPos(playerid, x, (y + 4), z);
	SendClientMessage(playerid, COLOR_PURPLE, "Você foi até o veículo!");
	return 1;
}

YCMD:trazerveiculo(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new vid;
	if (sscanf(params, "d", vid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /trazerveiculo [id do veículo]");
	}
	if (!IsValidVehicle(vid))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O ID informado é inválido.");
	}

    new interiorid = GetPlayerInterior(playerid);
    new virtualid = GetPlayerVirtualWorld(playerid);
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	SetVehiclePos(vid, x, (y + 4), z);
	LinkVehicleToInterior(vid, interiorid);
	SetVehicleVirtualWorld(vid, virtualid);
	SendClientMessage(playerid, COLOR_PURPLE, "Você trouxe um carro para perto de você!");
	return 1;
}

CMD:darlicencas(playerid, params[])
{
    if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /darlicencas [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}

	new string[96];
	Player_SetCarLicense(playerid, 80);
	Player_SetMotorCycleLicense(playerid, 70);
	Player_SetFlyLicense(playerid, 110);
	Player_SetBoatLicense(playerid, 90);
	Player_SetTruckLicense(playerid, 100);
	Player_SetGunLicense(playerid, 120);
	Player_SaveLicensesData(playerid);
    format(string, sizeof(string), "O administrador: %s lhe deu todas as licenças.", GetPlayerNameCustom(playerid));
	SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administração]: %s deu todas as licenças para: %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

CMD:retirarlicencas(playerid, params[])
{
	if (Player_GetAdminLevel(playerid) < MASTER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /retirarlicencas [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
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
    format(string, sizeof(string), "O administrador: %s retirou todas as suas licenças.", GetPlayerNameCustom(playerid));
	SendClientMessage(id, COLOR_LIGHTBLUE, string);
	format(string, sizeof(string), "[Administração]: %s retirou as licenças de: %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:abastecercarros(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[69];
	RefuelAllVehicles();
	format(string, sizeof(string), "[Administração]: %s abasteceu todos os carros.", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(COLOR_LIGHTRED, string);
	return 1;
}

YCMD:rcall(playerid, params[], help) = respawncarros;
YCMD:respawncarros(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < MASTER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[83];
	RespawnAllVehicles();
	format(string, sizeof(string), "[Administração]: %s respawnou todos os veículos do servidor.", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(0x80FF8096, string);
	return 1;
}

// /guerrafavela
// /guerracasarao
// /tempoguerra
// /respawnorg
// /darlicencas
// /retirarlicencas