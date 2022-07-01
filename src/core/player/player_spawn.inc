#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerSpawn(playerid)
{
    if (!Player_GetLoggedStatus(playerid))
    {
        new string[102];
		format(string, sizeof(string), "[AVISO]: O jogador %s foi kickado por ter spawnado ser ter realizado o login.", GetPlayerNameCustom(playerid));
		SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
		SendClientMessage(playerid, COLOR_LIGHTRED, "[AVISO]: Você foi kickado porque spawnou sem realizar o login.");
		KickPlayer(playerid);
		return 1;
    }
    ClearAnimations(playerid);
    SetPlayerArmour(playerid, 0);
	SetPlayerHealth(playerid, 100);
    ResetPlayerWeapons(playerid);
	SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerSkin(playerid, Player_GetSkin(playerid));
	SetPlayerPos(playerid, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
    SetPlayerFacingAngle(playerid, SPAWN_POSA);
    SetPlayerToTeamColor(playerid);
    return 1;
}

hook OnPlayerRequestSpawn(playerid)
{
	SpawnPlayerLogged(playerid);
    return 1;
}

hook BeforeSaveOnDisconnect(playerid)
{
    Player_UpdateLastPosition(playerid);
    return 1;
}