#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
YCMD:kitadmdono(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	if (!Player_GetGunLicense(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não possui porte de armas, retire-o na prefeitura.");
	}
	
	GivePlayerWeapon(playerid, 46, 1);
	GivePlayerWeapon(playerid, 24, 999);
	GivePlayerWeapon(playerid, 31, 999);
	GivePlayerWeapon(playerid, 29, 999);
	GivePlayerWeapon(playerid, 25, 999);
	GivePlayerWeapon(playerid, 4, 1);
	GivePlayerWeapon(playerid, 34, 999);
	GivePlayerWeapon(playerid, 38, 10000);
	GivePlayerWeapon(playerid, 43, 999);
	GivePlayerWeapon(playerid, 16, 49);
	SetPlayerArmour(playerid, 100);
	SetPlayerHealth(playerid, 100);
	SendClientMessage(playerid, COLOR_DARKGREEN, "Administrador: {B4B5B7}Você pegou o seu kit adm dono.");
    return 1;
}

YCMD:deslogartodos(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}

    new string[86];
 	format(string, sizeof(string), "[Administração]: %s desconectou todos os jogadores do servidor.", GetPlayerNameCustom(playerid));
	SendClientMessageToAll(COLOR_LIGHTRED, string);
	foreach(new i: Player)
	{
		KickPlayer(i);
	}
	SendClientMessage(playerid, COLOR_INVALID, "Todos os players deslogados.");
    return 1;
}

// /racessorios

YCMD:tocarsom(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}
	new sound_id;
	if (sscanf(params, "d", sound_id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /tocarsom [id do som]");
	}

	PlayerPlaySound(playerid, sound_id, 0.0, 0.0, 0.0);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "Som iniciado.");
	return 1;
}

YCMD:pararsom(playerid, params[], help)
{
    if (Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não está autorizado a utilizar esse comando.");
	}

	PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "O Som foi parado.");
	return 1;
}