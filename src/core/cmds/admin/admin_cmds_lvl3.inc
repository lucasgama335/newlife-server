#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
YCMD:1(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[15];
	format(string, sizeof(string), "~p~| ~r~1 ~p~|");
    GameTextForAll(string, 1000, 5);
    return 1;
}

YCMD:2(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[15];
	format(string, sizeof(string), "~p~| ~r~2 ~p~|");
    GameTextForAll(string, 1000, 5);
    return 1;
}

YCMD:3(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[15];
	format(string, sizeof(string), "~p~| ~y~3 ~p~|");
    GameTextForAll(string, 1000, 5);
    return 1;
}

YCMD:go(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[22];
	format(string, sizeof(string), "~p~| ~g~Go Go Go ~p~|");
    GameTextForAll(string, 1000, 5);
    return 1;
}

YCMD:voaron(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	new string[57];
	if (!Admin_IsFlying(playerid))
	{
        new Float: X, Float: Y, Float: Z;
        Admin_SetFlying(playerid, true);
		GetPlayerPos(playerid, X, Y, Z);
		SetPlayerHealth(playerid, 1000000);
	  	format(string, sizeof(string), "[Aviso]: %s ativou o modo voar.", GetPlayerNameCustom(playerid));
	    SendAdminMessage(COLOR_YELLOW, string, HELPER);
	    SendClientMessage(playerid, COLOR_LIGHTBLUE, "Para sair do modo de voar digite /voaron novamente !");
     	StartFly(playerid);
    }
    else
    {
        Admin_SetFlying(playerid, false);
		SetPlayerHealth(playerid, 100);
        format(string, sizeof(string), "[Aviso]: %s desativou o modo voar.", GetPlayerNameCustom(playerid));
		SendAdminMessage(COLOR_YELLOW, string, HELPER);
        StopFly(playerid);
	}
    return 1;
}

YCMD:orelhas(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	if (!Admin_HasBigEars(playerid))
   	{
        Admin_SetBigEars(playerid, true);
        SendClientMessage(playerid, COLOR_INVALID, "Suas orelhas cresceram!");
   	}
   	else
   	{
        Admin_SetBigEars(playerid, false);
    	SendClientMessage(playerid, COLOR_INVALID, "Suas orelhas encolheram!");
   	}
    return 1;
}

YCMD:respawnperto(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

	// Execução do Comando
	new string[77];
	RespawnNearVehicles(playerid);
	SendClientMessage(playerid, COLOR_INVALID, "Você deu respawn nos carros a 50 metros de você.");
	format(string, sizeof(string), "[Aviso]: %s deu respawn em todos os carros perto dele.", GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_YELLOW, string, HELPER);
    return 1;
}

YCMD:rarmas(playerid, params[], help) = retirararmas;
YCMD:retirararmas(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /retirararmas [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}

	new string[97];
	ResetPlayerWeapons(id);
	format(string, sizeof(string), "[Administração]: %s teve as armas retiradas por: %s.", GetPlayerNameCustom(id), GetPlayerNameCustom(playerid));
	SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
	return 1;
}

YCMD:saciar(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /saciar [id]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}

 	new string[100];
	Player_SetHungry(id, 100);
	Player_SetDrink(id, 100);
	format(string, sizeof(string), "[Administração]: O Admin %s saciou a fome e sede de %s.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(id));
	SendAdminMessage(COLOR_LIGHTGREEN, string, HELPER);
	return 1;
}

YCMD:saciarall(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}

    new string[93];
	foreach(new i: Player)
	{
	    if (Player_GetLoggedStatus(i))
	    {
			Player_SetHungry(i, 100);
			Player_SetDrink(i, 100);
		}
	}
	format(string, sizeof(string), "[Administração]: O Admin %s saciou a fome e sede de todos no servidor.", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(COLOR_LIGHTGREEN, string);
	return 1;
}

YCMD:banir(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new id, days, reason[MAX_REASON_STRING];
	if (sscanf(params, "uds[*]", id, days, MAX_REASON_STRING, reason))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /banir [id] [dias(0 = permanente)] [motivo]");
	}
	if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (id == playerid)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode dar banir a si mesmo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER && Player_GetAdminLevel(id) != OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode banir um administrador.");
	}
	if (days < 0)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Número de dias inválido.");
	}
	if (!strlen(reason))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você precisa informar um motivo para o banimento.");
	}
	if (strlen(reason) > MAX_REASON_STRING)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O motivo do banimento está muito longo");
	}

	AdminBanPlayer(id, playerid, days, reason);
	return 1;
}

YCMD:agendarban(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new name[MAX_PLAYER_NAME], days, reason[MAX_REASON_STRING];
	if (sscanf(params, "s[*]ds[*]", MAX_PLAYER_NAME, name, days, MAX_REASON_STRING, reason))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /agendarban [nick] [dias(0 = permanente)] [motivo]");
	}
	if (!strlen(name))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você precisa digitar o nome do jogador.");
	}
	if (strlen(name) > MAX_PLAYER_NAME)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O nome do jogador está muito longo.");
	}
	if (days < 0)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Número de dias inválido.");
	}
	if (!strlen(reason))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você precisa informar um motivo para o banimento.");
	}
	if (strlen(reason) > MAX_REASON_STRING)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O motivo do banimento está muito longo.");
	}
	if (!strcmp(GetPlayerNameCustom(playerid), name, true))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode banir a si mesmo.");
	}
	
	AdminBanPlayerByName(name, playerid, days, reason);
	return 1;
}

YCMD:desbanir(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < BEGINNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está em modo de trabalho. Use: /trabalhar.");
	}
	new name[MAX_PLAYER_NAME];
	if (sscanf(params, "s[24]", name))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /desbanir [nick]");
	}
	if (!strlen(name))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você precisa digitar o nome do jogador.");
	}
	if (strlen(name) > MAX_PLAYER_NAME)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O nome do jogador está muito longo.");
	}

	UnBanPlayer(name, playerid);
	return 1;
}

// /versms