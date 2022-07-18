#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
// /editar

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