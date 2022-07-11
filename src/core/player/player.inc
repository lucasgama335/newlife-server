#include <player_auth>
#include <player_tutorial>
#include <player_ban>
#include <player_anims>
#include <player_spawn>
#include <player_vehicle>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_CONNECTIONS_FROM_IP     3

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsPlayerUpdateStatusTimer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

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
    if (Player_GetMutedTime(playerid) > 0) 
    {
        Player_SetMutedTime(playerid, (Player_GetMutedTime(playerid) - 1));
    }
    if (Player_GetNoobMutedTime(playerid) > 0) 
    {
        Player_SetNoobMutedTime(playerid, (Player_GetNoobMutedTime(playerid) - 1));
    }
    
    if (Player_GetPaydayTime(playerid) <= 0 && IsValidPlayer(playerid))
    {
        PlayerGetPayday(playerid);
    }   
    else
    {
        Player_SetPaydayTime(playerid, (Player_GetPaydayTime(playerid) - 1));
    }
    
    // Update HUD
    UpdatePlayerHud(playerid, Chrono_GetTimeNow(), Player_GetHungry(playerid), Player_GetDrink(playerid), Player_GetPaydayTime(playerid));
    return 1;
}

stock PlayerGetPayday(playerid)
{
    new string[160], salaryReceived = 0, moneyString[MAX_MONEY_STRING], salaryString[MAX_MONEY_STRING];
    FormatMoneyString(Player_GetSalary(playerid), moneyString);
    FormatMoneyString(salaryReceived, salaryString);

    SendClientMessage(playerid, COLOR_WHITE, "___________[ Salário(PayDay) ]___________");
    if (salaryReceived > 0)
    {
        format(string, sizeof(string), "Salário: R$ [{00FF00}%s{FFFFFF}] | Organização: R$ [{00FF00}%s{FFFFFF}]", moneyString, salaryString);
    }
    else
    {
        format(string, sizeof(string), "Salário: R$ [{00FF00}%s{FFFFFF}]", moneyString);
    }
    SendClientMessage(playerid, COLOR_WHITE, string);


    new vip_money = 0, vip_exp = 0, moneyVipString[MAX_MONEY_STRING];
    switch(Player_GetVipLevel(playerid))
    {
        case 1:
        {
            new moneyVip = 3000 + random(2000);
            vip_exp += 1;
            vip_money += moneyVip;
            FormatMoneyString(moneyVip, moneyVipString);
            format(string, sizeof(string), "{FFFF00}Bônus VIP: {FFFFFF}Experiência: {00FF00}+1 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);	
        }
        case 2:
        {
            new moneyVip = 5000 + random(2000);
            vip_exp += 2;
            vip_money += moneyVip;
            format(string, sizeof(string), "{FFFF00}Bônus VIP: {FFFFFF}Experiência: {00FF00}+2 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
    }
    switch(Player_GetSocioLevel(playerid))
    {
        case 1:
        {
            new moneySocio = 6000 + random(3000);
            vip_exp += 3;
            vip_money += moneySocio;
            FormatMoneyString(moneySocio, moneyVipString);
            format(string, sizeof(string), "{FFFF00}Bônus Sócio: {FFFFFF}Experiência: {00FF00}+3 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);	
        }
        case 2:
        {
            new moneySocio = 10000 + random(5000);
            vip_exp += 4;
            vip_money += moneySocio;
            FormatMoneyString(moneySocio, moneyVipString);
            format(string, sizeof(string), "{FFFF00}Bônus Sócio: {FFFFFF}Experiência: {00FF00}+4 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
    }

    format(string, sizeof(string), "Experiência Atual para passar de nível: ({0080ff}%d/%d{FFFFFF})", Player_GetExperience(playerid), ((Player_GetLevel(playerid) + 1) * 4));
	SendClientMessage(playerid, COLOR_WHITE, string);
    SendClientMessage(playerid, COLOR_WHITE, "_________________________________________");
    GameTextForPlayer(playerid, "~b~PAYDAY !", 5000, 1);
    if (Player_GetExperience(playerid) >= ((Player_GetLevel(playerid) + 1) * 4))
    {
        SendClientMessage(playerid, COLOR_YELLOW, "[Servidor]: Você já possui experiência suficiente para passar de nível, use: /comprarnivel");
    }

    Player_SetExperience(playerid, (Player_GetExperience(playerid) + 1 + vip_exp));
    Player_SetSalary(playerid, (Player_GetSalary(playerid) + salaryReceived + vip_money));
    Player_SetHoursPlayed(playerid, (Player_GetHoursPlayed(playerid) + 1));
    Player_SetLastConnectedTime(playerid, (Player_GetLastConnectedTime(playerid) + 1));

    // Payment
    if (Player_GetSalary(playerid) > 0)
    {
        Player_SetMoney(playerid, (Player_GetMoney(playerid) + Player_GetSalary(playerid)));
        Player_SetSalary(playerid, 0);
    }

    Player_SetPaydayTime(playerid, 3600);
    Player_SaveScoreData(playerid);
    Player_SaveMoneyData(playerid);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    new numPlayersInSameIp = GetPlayersInSameIp(GetPlayerIpCustom(playerid));
    if (numPlayersInSameIp > MAX_CONNECTIONS_FROM_IP)
	{
        printf("MAXIPs: O Jogador[%d] excedeu o número de conexões [%d] por IP: [%s].", playerid, MAX_CONNECTIONS_FROM_IP, GetPlayerIpCustom(playerid));
        Kick(playerid);
    }
    return 1;
}

hook FirstSpawnOnLogin(playerid)
{
    gsPlayerUpdateStatusTimer[playerid] = repeat PlayerUpdateStatus(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if (Timer_IsRunning(gsPlayerUpdateStatusTimer[playerid])) 
    {
        stop gsPlayerUpdateStatusTimer[playerid];
    }
    CallLocalFunction("BeforeSaveOnDisconnect", "i", playerid);
    Player_SetLastLogin(playerid, Player_GetLastLoginTemp(playerid));
    Player_SaveGeneralData(playerid);
    Player_SaveStatusData(playerid);
    Player_SaveMoneyData(playerid);
    Player_SaveScoreData(playerid);
    Player_SaveAppearenceData(playerid);
    return 1;
}

hook OnPlayerUpdateScreenSize(playerid)
{
    HidePlayerHud(playerid);
    ShowPlayerHud(playerid);
    return 1;
}