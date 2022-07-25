#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook FirstSpawnOnLogin(playerid)
{
    new string[150];
    UpdatePlayerHud(playerid, Chrono_GetTimeNow(), Player_GetHungry(playerid), Player_GetDrink(playerid), Player_GetPaydayTime(playerid));
    ShowPlayerHud(playerid);
    if (!Player_GetTutorialStatus(playerid))
    {
        ShowGenderDialog(playerid);
    }
    else
    {
        new lastLoginString[MAX_FULL_DATE_STRING];
        Player_GetLastLoginFormated(playerid, lastLoginString);
        SendClientMessage(playerid, COLOR_WHITE, "________________________________________________________________________________________________");
        format(string, sizeof(string), "* [{FFFFFF}Aviso{934ff6}]: Seja Bem Vindo(a): {FFFFFF}%s{934ff6} ao servidor.", GetPlayerNameCustom(playerid));
        SendClientMessage(playerid, COLOR_MARKET, string);
        SendClientMessage(playerid, COLOR_MARKET, "* [{FFFFFF}Aviso{934ff6}]: Para voltar a última posição, na qual você esteve pela última vez digite: ({FFFFFF}/irposicao{934ff6}).");
        SendClientMessage(playerid, COLOR_MARKET, "* [{FFFFFF}Aviso{934ff6}]: Retire suas dúvidas usando: ({FFFFFF}/relatorio{934ff6}) ou com o chat de dúvidas: ({FFFFFF}/nchat{934ff6}).");
        format(string, sizeof(string), "* [{FFFFFF}Aviso{934ff6}]: Seu último login foi no dia: {FFFFFF}%s {934ff6}durante {FFFFFF}%d{934ff6} hora(s).", lastLoginString, Player_GetLastConnectedTime(playerid));
 		SendClientMessage(playerid, COLOR_MARKET, string);
        SendClientMessage(playerid, COLOR_WHITE, "________________________________________________________________________________________________");
        if (Player_GetAdminLevel(playerid) >= HELPER)
        {
            new roleName[MAX_ADMIN_ROLE_STRING];
            GetAdminRoleName(Player_GetAdminLevel(playerid), roleName);
            format(string, sizeof(string), "[{FFFFFF}Administração{ff3399}]: Você logou com o nível de administração: [{FFFFFF}%s{ff3399}].", roleName);
            SendClientMessage(playerid, COLOR_ADMIN, string);
        }
		if (Player_GetAdminLevel(playerid) >= HELPER && Player_GetAdminLevel(playerid) < SUB_OWNER)
		{
			new adminName[35];
			format(adminName, sizeof(adminName), "~w~%s ~g~ON", GetPlayerNameCustom(playerid));
			GameTextForAll(adminName, 5000, 1);
		}
        format(string, sizeof(string), "~w~Bem Vindo ~n~~y~%s", GetPlayerNameCustom(playerid));
        GameTextForPlayer(playerid, string, 5000, 1);
        if (Player_GetAdminLevel(playerid) >= HELPER_OWNER)
        {
            new admPassDialog[300], roleName[MAX_ADMIN_ROLE_STRING];
            GetAdminRoleName(Player_GetAdminLevel(playerid), roleName);
            format(admPassDialog, sizeof(admPassDialog), "{FFFFFF}Conta: {0080ff}%s\n{FFFFFF}Você logou com Admin ({0080ff}%s{FFFFFF})\n\n{FFFFFF}Você precisa autenticar a senha de segurança para poder\n{FFFFFF}logar em sua conta!\n\n{ff6347}OBS: {FFFFFF}Você só tem uma tentativa ou será desconectado do servidor.\n\n\n{6e6e6e}Insira abaixo a senha da administração:", GetPlayerNameCustom(playerid), roleName);
            ShowPlayerDialog(playerid, DIALOG_AUTH_ADMIN, DIALOG_STYLE_PASSWORD, "Proteção de Conta", admPassDialog, "Validar", "");
        }
    }
    if (Player_GetAdminLevel(playerid) < HELPER_OWNER) 
    {
        format(string, sizeof(string), "[Conexão]: %s(ID: %d) se conectou, Level: %d | IP: [%s]!", GetPlayerNameCustom(playerid), playerid, Player_GetLevel(playerid), GetPlayerIpCustom(playerid));
    }
    else 
    {
        format(string, sizeof(string), "[Conexão]: %s(ID: %d) se conectou, Level: %d | IP: [N/A]!", GetPlayerNameCustom(playerid), playerid, Player_GetLevel(playerid));
    }
    SendAdminMessage(COLOR_SKIN, string, HELPER);
	return 1;
}

hook OnPlayerSpawn(playerid)
{
    if (!Player_GetLoggedStatus(playerid))
    {
        new string[102];
		format(string, sizeof(string), "[Aviso]: O jogador %s foi kickado por ter spawnado ser ter realizado o login.", GetPlayerNameCustom(playerid));
		SendAdminMessage(COLOR_YELLOW, string, HELPER);
		SendClientMessage(playerid, COLOR_YELLOW, "[Aviso]: Você foi kickado porque spawnou sem realizar o login.");
		KickPlayer(playerid);
		return 1;
    }
    ClearAnimations(playerid);
    SetPlayerArmour(playerid, 0);
	SetPlayerHealth(playerid, 100);
    ResetPlayerWeapons(playerid);
    SetPlayerToTeamColor(playerid);
    if (Player_GetJob(playerid) == j_JOB_NONE)
    {
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerSkin(playerid, Player_GetSkin(playerid));
        SetPlayerPos(playerid, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
        SetPlayerFacingAngle(playerid, SPAWN_POSA);
    }
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

//------------------------- Commands (Module related commands) -------------------------
