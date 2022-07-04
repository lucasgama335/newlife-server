#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook FirstSpawnOnLogin(playerid)
{
    new string[150];
    UpdatePlayerHud(playerid, Chrono_GetTimeNow(), Player_GetLevel(playerid), Player_GetHungry(playerid), Player_GetDrink(playerid), Player_GetPaydayTime(playerid));
    ShowPlayerHud(playerid);
    if (!Player_GetTutorialStatus(playerid))
    {
        ShowGenderDialog(playerid);
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "________________________________________________________________________________________________");
        format(string, sizeof(string), "* [Aviso]: Seja Bem Vindo(a): {FFFFFF}%s{33ccff}.", GetPlayerNameCustom(playerid));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "* [Aviso]: Para voltar na última posição de onde saiu pela última vez digite ({FFFFFF}/irposicao{33ccff})!");
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "* [Aviso]: Retire suas dúvidas usando ({FFFFFF}/relato{33ccff}) ou com o chat de dúvidas ({FFFFFF}/nchat{33ccff}).");
        format(string, sizeof(string), "* [Aviso]: Último login no dia: {FFFFFF}%s {33ccff}durante {FFFFFF}%d{33ccff} hora(s).", Player_GetLastLoginFormated(playerid), Player_GetLastConnectedTime(playerid));
 		SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        if (Player_GetAdminLevel(playerid) >= HELPER)
        {
            format(string, sizeof(string), "[{FFFFFF}ADMIN{33ccff}]: Você Logou Como Admin: [{FFFFFF}%s{33ccff}].", GetAdminRoleName(Player_GetAdminLevel(playerid)));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
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
            new admPassDialog[300];
            format(admPassDialog, sizeof(admPassDialog), "{FFFFFF}Conta: {0080ff}%s\n{FFFFFF}Você logou com Admin ({0080ff}%s{FFFFFF})\n\n{FFFFFF}Você precisa autenticar a senha de segurança para poder\n{FFFFFF}logar em sua conta!\n\n{ff6347}OBS: {FFFFFF}Você só tem uma tentativa ou será desconectado do servidor.\n\n\n{6e6e6e}Insira abaixo a senha da administração:", GetPlayerNameCustom(playerid), GetAdminRoleName(Player_GetAdminLevel(playerid)));
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