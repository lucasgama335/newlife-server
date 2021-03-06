#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
YCMD:repararid(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em um carro.");
	}

	new vehicleid = GetPlayerVehicleID(playerid), string[74];
	format(string, sizeof(string), "Voc� reparou o ve�culo id: [%d].", vehicleid);
    SendClientMessage(playerid, COLOR_INVALID, string);
	format(string, sizeof(string), "[Aviso]: ve�culo id: [%d] foi reparado por: %s.", vehicleid, GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
    Vehicle_SetBrokenStatus(vehicleid, false);
    RepairVehicleCustom(vehicleid);
    return 1;
}

YCMD:blindarid(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em um carro.");
	}

	new vehicleid = GetPlayerVehicleID(playerid), string[74];
	format(string, sizeof(string), "Voc� blindou o ve�culo id: [%d].", vehicleid);
    SendClientMessage(playerid, COLOR_INVALID, string);
	format(string, sizeof(string), "[Aviso]: ve�culo id: [%d] foi blindado por: %s.", vehicleid, GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
    Vehicle_SetBrokenStatus(vehicleid, false);
	RepairVehicleCustom(vehicleid);
    Vehicle_SetShield(vehicleid, 1000.0);
    return 1;
}

YCMD:abastecerid(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em um carro.");
	}

    new vehicleid = GetPlayerVehicleID(playerid), string[76];
	format(string, sizeof(string), "Voc� abasteceu o ve�culo id: [%d].", vehicleid);
    SendClientMessage(playerid, COLOR_INVALID, string);
	format(string, sizeof(string), "[Aviso]: ve�culo id: [%d] foi abastecido por: %s.", vehicleid, GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
    Vehicle_SetFuel(vehicleid, 100);
    return 1;
}

YCMD:respawnid(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	if (!IsPlayerInAnyVehicle(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em um carro.");
	}

	new vehicleid = GetPlayerVehicleID(playerid), string[76];
	format(string, sizeof(string), "Voc� deu respawn no ve�culo id: [%d].", vehicleid);
    SendClientMessage(playerid, COLOR_INVALID, string);
	format(string, sizeof(string), "[Aviso]: ve�culo id: [%d] foi respawnado por: %s.", vehicleid, GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
	SetVehicleToRespawn(vehicleid);
    return 1;
}

YCMD:setclima(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new weather;
	if (sscanf(params, "d", weather))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /setclima [id do clima]");
	}
	if (weather < 0 || weather > 255)
	{
		return SendClientMessage(playerid, COLOR_GREY, "[Erro]: Tempo id de 0 ~ 255 !");
	}

	new string[57];
	SetWeather(weather);
	format(string, sizeof(string), "[Aviso]: %s setou o tempo para %d.", GetPlayerNameCustom(playerid), weather);
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
	SendClientMessage(playerid, COLOR_GREY, "Tempo setado!");
    return 1;
}

YCMD:desativarprevisao(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	new string[65];
	Server_SetWeatherForecast(false);
	format(string, sizeof(string), "[Aviso]: %s desativou a previs�o do tempo.", GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
    return 1;
}

YCMD:ativarprevisao(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	new string[62];
	Server_SetWeatherForecast(true);
	format(string, sizeof(string), "[Aviso]: %s ativou a previs�o do tempo.", GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
    return 1;
}

YCMD:calar(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, time;
	if (sscanf(params, "ud", id, time))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /calar [id] [minutos]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode calar um admin dono.");
	}
	if (time < 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Tempo inv�lido.");
	}

	if (time > 0)
	{
		new string[110];
		Player_SetMutedTime(id, (time * 60));
		format(string, sizeof(string), "[Administra��o]: %s foi calado por %s durante [%d] minutos.", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid), time);
		SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	}
	else
	{
		new string[86];
		Player_SetMutedTime(id, 0);
		format(string, sizeof(string), "[Administra��o]: %s foi descalado por %s.", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid));
		SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	}
	return 1;
}

YCMD:calarn(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}
	new id, time;
	if (sscanf(params, "ud", id, time))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /calarn [id] [minutos]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode bloquear o chat d�vida de um admin dono.");
	}
	if (time < 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Tempo inv�lido.");
	}

	if (time > 0)
	{
		new string[123];
		Player_SetMutedTime(id, (time * 60));
		format(string, sizeof(string), "[Administra��o]: %s bloqueou o chat d�vida de %s durante [%d] minuto(s).", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid), time);
		SendClientMessageToAll(COLOR_LIGHTRED, string);
	}
	else
	{
		new string[97];
		Player_SetMutedTime(id, 0);
		format(string, sizeof(string), "[Administra��o]: %s desbloqueou o chat d�vida de %s.", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid));
		SendClientMessageToAll(COLOR_LIGHTRED, string);
	}
	return 1;
}

YCMD:congelar(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /congelar [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER && Player_GetAdminLevel(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o pode congelar um admin dono.");
	}

	new string[86];
	TogglePlayerControllable(id, false);
	format(string, sizeof(string), "[Administra��o]: %s foi congelado por %s.", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:descongelar(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /descongelar [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse n�o � um jogador ativo.");
	}

	new string[89];
	TogglePlayerControllable(id, true);
	format(string, sizeof(string), "[Administra��o]: %s foi descongelado por %s.", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:limparchat(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo de trabalho. Use: /trabalhar.");
	}

	foreach(new i: Player)
	{
		ClearChatBox(i, DEFAULT_CLEAR_LINES);
	}
    return 1;
}

// TO-DO
// /carandiru
// /carandiruagendados
// /agendarcarandiru
// /excluircarandiru
// /prendern