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

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_CONNECTIONS_FROM_IP     3

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:updateStats[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock SetPlayerToTeamColor(playerid)
{
    SetPlayerColor(playerid, COLOR_WHITE);
	if (Admin_IsWorking(playerid) && !Admin_GetHideStatus(playerid))
	{
		SetPlayerColor(playerid, COLOR_ADMIN);
	}
	return 1;
}

stock PlayAudioStreamForPlayerEx(playerid, const url[])
{
	if (PlayerData_GetStreamStatus(playerid))
	{
		PlayAudioStreamForPlayer(playerid, url);
	}
	return 1;
}

stock SendDuvidaMessage(color, const string[])
{
	foreach(new i: Player)
	{
		if (PlayerData_GetNoobChat(i))
	    {
			SendClientMessage(i, color, string);
		}
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
timer Player_UpdateStats[1000](playerid)
{
    // Tag System
    if (PlayerData_GetWantedLevel(playerid) > 0)
    {
        new string[100];
        SetPlayerWantedLevel(playerid, PlayerData_GetWantedLevel(playerid));
        format(string, sizeof(string), "Procurado [%d]", PlayerData_GetWantedLevel(playerid));
        SetPlayerChatBubble(playerid, string, COLOR_RED, 100.0, 50000);
    }
    else
    {
        switch(PlayerData_GetTag(playerid))
        {
            case TAG_NONE:
            {
                if (PlayerData_GetLevel(playerid) < 5)
                {
                    if (PlayerData_GetIsUsingAndroid(playerid)) SetPlayerChatBubble(playerid, "Novato Android", COLOR_TITLE, 100.0, 50000);
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
    if (PlayerData_GetMutedTime(playerid) > 0) PlayerData_SetMutedTime(playerid, (PlayerData_GetMutedTime(playerid) - 1));
    if (PlayerData_GetMutedNoobTime(playerid) > 0) PlayerData_SetMutedNoobTime(playerid, (PlayerData_GetMutedNoobTime(playerid) - 1));
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook BeforeSpawnPlayer(playerid)
{
	updateStats[playerid] = repeat Player_UpdateStats(playerid);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    new num_players_on_ip = Server_PlayersInSameIp(Player_GetIP(playerid));
    if (num_players_on_ip > MAX_CONNECTIONS_FROM_IP)
	{
        printf("MAXIPs: O Jogador[%d] excedeu o número de conexões [%d] por IP: [%s].", playerid, MAX_CONNECTIONS_FROM_IP, Player_GetIP(playerid));
        Kick(playerid);
        return ~1; // Ended Hooks Calls
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if (Timer_IsRunning(updateStats[playerid])) stop updateStats[playerid];

    CallLocalFunction("BeforeSaveOnDisconnect", "i", playerid);
    PlayerData_SetLastLogin(playerid, PlayerData_GetLastLoginTemp(playerid));
    Database_SaveGeneralInfo(playerid);
    Database_SaveStatusInfo(playerid);
    Database_SaveMoneyInfo(playerid);
    Database_SaveScoreInfo(playerid);
    return 1;
}