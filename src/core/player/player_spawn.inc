#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
static bool:plataformSelected[MAX_PLAYERS];

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    plataformSelected[playerid] = false;
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        // Plataform
        case DIALOG_CHECK_ANDROID:
        {
            if (!response) 
            {
                plataformSelected[playerid] = true;
                PlayerData_SetIsUsingAndroid(playerid, false);
                return 1;
            }
            if (response) 
            {
                plataformSelected[playerid] = true;
                PlayerData_SetIsUsingAndroid(playerid, true);
                return 1;
            }
        }
    }
    return 1;
}

hook OnAndroidCheck(playerid, bool:isDisgustingThiefToBeBanned)
{
    if (isDisgustingThiefToBeBanned) 
    {
        if (!plataformSelected[playerid]) 
        {
            SendClientMessage(playerid, 0xffcc99FF, "[SERVIDOR]: Por favor, selecione a plataforma na qual você está jogando.");
            ShowPlayerDialog(playerid, DIALOG_CHECK_ANDROID, DIALOG_STYLE_MSGBOX, "Checagem de Plataforma - Servidor", "{FFFFFF}Olá jogador, detectamos uma mudança de plataforma e precisamos colher algumas informações.\nVocê deve informar em qual plataforma você está se conectando ao servidor (Android ou PC) corretamente.\n\n{9fa19e}Se você estiver se conectando pelo Android (Celular), Selecine '{03a9fd}Android{9fa19e}'.\n{9fa19e}Se você estiver se conectando pelo Computador, Selecione '{00b100}PC{9fa19e}'.\n\n{f2664d}Importante: {FFFFFF}Caso marque a opção 'Android' algumas coisas do servidor funcionarão de uma forma diferente,\npor questões de compatibilidade com a plataforma.\n\nSelecione abaixo corretamente, por qual meio você está acessando o servidor:", "Android", "PC");
        }
    }
}

hook OnPlayerSpawn(playerid)
{
    if (!PlayerData_GetIsLogged(playerid))
    {
        new string[102];
		format(string, sizeof(string), "[AVISO]: O jogador %s foi kickado por ter spawnado ser ter realizado o login.", Player_GetName(playerid));
		MensagemAdmin(COLOR_LIGHTRED, string, HELPER);
		SendClientMessage(playerid, COLOR_LIGHTRED, "[AVISO]: Você foi kickado porque spawnou sem realizar o login.");
		DelayedKick(playerid);
		return 1;
    }
    ClearAnimations(playerid);
    SetPlayerArmour(playerid, 0);
	SetPlayerHealth(playerid, 100);
    ResetPlayerWeapons(playerid);
	SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerSkin(playerid, PlayerData_GetSkin(playerid));
	SetPlayerPos(playerid, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ);
    SetPlayerFacingAngle(playerid, SPAWN_POSA);
    SetPlayerToTeamColor(playerid);
    return 1;
}

hook OnPlayerRequestSpawn(playerid)
{
	return IsPlayerLogged(playerid);
}

hook BeforeSaveOnDisconnect(playerid)
{
    PlayerData_UpdateLastPosition(playerid);
    return 1;
}