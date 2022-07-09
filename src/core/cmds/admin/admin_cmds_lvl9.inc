#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
YCMD:kitadmdono(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Player_GetGunLicense(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não possui porte de armas, retire-o na prefeitura.");
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
	SendClientMessage(playerid, COLOR_DARKGREEN, "Você pegou o seu Kit Admin Dono!");
    return 1;
}

YCMD:deslogartodos(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < SUB_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}

    new string[62];
 	foreach(new i: Player)
	{
		format(string, sizeof(string), "ADMIN CMD: %s deslogou todos os players.", GetPlayerNameCustom(playerid));
		SendClientMessage(i, COLOR_LIGHTRED, string);
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}

	PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "O Som foi parado.");
	return 1;
}