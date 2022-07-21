#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum e_CHAT_GROUPS
{
    e_OPEN_WORLD
}
static e_CHAT_GROUPS:gsChatGroup = e_OPEN_WORLD;
static gsFloodTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
public OnPlayerText(playerid, text[])
{
    if (!Player_GetLoggedStatus(playerid)) 
    {
        SendClientMessage(playerid, COLOR_INVALID,"Você não está logado.");
        return 0;
    }
    if (Player_GetMutedTime(playerid) > 0)
    {
        SendClientMessage(playerid, COLOR_INVALID, "Você não pode falar, pois está mutado.");
        return 0;
    }
    if (strlen(text) > 100) 
    {
        SendClientMessage(playerid, COLOR_INVALID,"Não escreva um texto muito grande.");
        return 0;
    }
    if (gettime() < gsFloodTimer[playerid]) 
    {
        SendClientMessage(playerid, COLOR_GRAD1, "Aguarde 2 segundos para escrever novamente uma mensagem neste chat!");
        return 0;
    }
    if (strcmp(text,"/q", true) == 0 || strcmp(text,"/quit", true) == 0 || strcmp(text," /quit", true) == 0 || strcmp(text," /q", true) == 0 || strcmp(text,"~/q", true) == 0 || strcmp(text,"~/quit", true) == 0 || strcmp(text,"  /q", true) == 0 || strcmp(text,"  /quit", true) == 0)
	{
	    SendClientMessage(playerid, COLOR_PURPLE, "Você não pode sair do jogo digitando /q !");
		return 0;
	}
	gsFloodTimer[playerid] = gettime() + 2;

    if (gsChatGroup == e_OPEN_WORLD) 
    {
        new string[137];
        format(string, sizeof(string), "%s[%d] diz: %s", GetPlayerNameCustom(playerid), playerid, text);
		SendMessageInRange(20.0, playerid, string, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
		SetPlayerChatBubble(playerid, text, 0x98FB98FF, 20.0, 10000);
        return 0;
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
