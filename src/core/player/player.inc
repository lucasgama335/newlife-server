// Database Player Data
#include <general_data>
#include <job_data>
#include <appearence_data>
#include <money_data>
#include <score_data>
#include <vip_data>
#include <status_data>
#include <config_data>
//
#include <player_admin>
#include <player_tutorial>
#include <player_vehicle>
#include <player_anims>
#include <player_auth>
#include <player_spawn>
#include <player_entrances>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_CONNECTIONS_FROM_IP     3

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsPlayerUpdateStatusTimer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock SetPlayerToTeamColor(playerid)
{
    SetPlayerColor(playerid, COLOR_WHITE);
	if (Admin_GetWorkStatus(playerid) && !Admin_GetHideStatus(playerid))
	{
		SetPlayerColor(playerid, COLOR_ADMIN);
	}
	return 1;
}

stock PlayAudioStreamForPlayerEx(playerid, const url[])
{
	if (Player_GetMusicStreamStatus(playerid))
	{
		PlayAudioStreamForPlayer(playerid, url);
	}
	return 1;
}

stock SendDuvidaMessage(color, const string[])
{
	foreach(new i: Player)
	{
		if (Player_GetNoobChatStatus(i))
	    {
			SendClientMessage(i, color, string);
		}
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
timer PlayerUpdateStatus[1000](playerid)
{
    // Tag System
    if (Player_GetWantedLevel(playerid) > 0)
    {
        new string[100];
        SetPlayerWantedLevel(playerid, Player_GetWantedLevel(playerid));
        format(string, sizeof(string), "Procurado [%d]", Player_GetWantedLevel(playerid));
        SetPlayerChatBubble(playerid, string, COLOR_RED, 100.0, 50000);
    }
    else
    {
        switch(Player_GetTag(playerid))
        {
            case NO_TAG:
            {
                if (Player_GetLevel(playerid) < 5)
                {
                    if (Player_GetUsingAndroidStatus(playerid)) SetPlayerChatBubble(playerid, "Novato Android", COLOR_TITLE, 100.0, 50000);
                    else SetPlayerChatBubble(playerid, "Novato PC", COLOR_TITLE, 100.0, 50000);
                }
                else SetPlayerChatBubble(playerid, "", COLOR_TITLE, 100.0, 50000);
            }
            case TAG_SCRIPTER: SetPlayerChatBubble(playerid, "Scripter", COLOR_ADMIN, 100.0, 50000);
            case TAG_ADMIN: SetPlayerChatBubble(playerid, "Administrador", COLOR_ADMIN, 100.0, 50000);
            case TAG_LEADER: SetPlayerChatBubble(playerid, "Líder", COLOR_TITLE, 100.0, 50000);
            case TAG_SUBLEADER: SetPlayerChatBubble(playerid, "SubLíder", COLOR_TITLE, 100.0, 50000);
            case TAG_VIP: SetPlayerChatBubble(playerid, "Membro Vip", COLOR_TITLE, 100.0, 50000);
            case TAG_SOCIO: SetPlayerChatBubble(playerid, "Membro Sócio", COLOR_TITLE, 100.0, 50000);
            case TAG_NOOB: SetPlayerChatBubble(playerid, "Noob", COLOR_TITLE, 100.0, 50000);
            case TAG_KILLER: SetPlayerChatBubble(playerid, "Matador", COLOR_TITLE, 100.0, 50000);
        }
    }

    // Muted Time
    if (Player_GetMutedTime(playerid) > 0) Player_SetMutedTime(playerid, (Player_GetMutedTime(playerid) - 1));
    if (Player_GetNoobMutedTime(playerid) > 0) Player_SetNoobMutedTime(playerid, (Player_GetNoobMutedTime(playerid) - 1));
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook BeforeSpawnPlayer(playerid)
{
	gsPlayerUpdateStatusTimer[playerid] = repeat PlayerUpdateStatus(playerid);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    new numPlayersInSameIp = GetPlayersInSameIp(GetPlayerIpCustom(playerid));
    if (numPlayersInSameIp > MAX_CONNECTIONS_FROM_IP)
	{
        printf("MAXIPs: O Jogador[%d] excedeu o número de conexões [%d] por IP: [%s].", playerid, MAX_CONNECTIONS_FROM_IP, GetPlayerIpCustom(playerid));
        Kick(playerid);
        return ~1; // Ended Hooks Calls
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if (Timer_IsRunning(gsPlayerUpdateStatusTimer[playerid])) stop gsPlayerUpdateStatusTimer[playerid];

    CallLocalFunction("BeforeSaveOnDisconnect", "i", playerid);
    Player_SetLastLogin(playerid, Player_GetLastLoginTemp(playerid));
    Player_SaveGeneralData(playerid);
    Player_SaveStatusData(playerid);
    Player_SaveMoneyData(playerid);
    Player_SaveScoreData(playerid);
    return 1;
}