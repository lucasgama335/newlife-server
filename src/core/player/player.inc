#include <player_auth>
#include <player_tutorial>
#include <player_ban>
#include <player_anims>
#include <player_spawn>
#include <player_commands>
#include <player_chat>
#include <player_inventory>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsPlayerUpdateStatusTimer[MAX_PLAYERS];
static gsLastDeath[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:PlayerUpdateStatus(playerid)
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
            case TAG_LEADER: SetPlayerChatBubble(playerid, "L�der", COLOR_TITLE, 100.0, 50000);
            case TAG_SUBLEADER: SetPlayerChatBubble(playerid, "SubL�der", COLOR_TITLE, 100.0, 50000);
            case TAG_VIP: SetPlayerChatBubble(playerid, "Membro Vip", COLOR_TITLE, 100.0, 50000);
            case TAG_SOCIO: SetPlayerChatBubble(playerid, "Membro S�cio", COLOR_TITLE, 100.0, 50000);
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

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock PlayerGetPayday(playerid)
{
    new string[160], salaryReceived = 0, moneyString[MAX_MONEY_STRING], salaryString[MAX_MONEY_STRING];
    FormatMoneyString(Player_GetSalary(playerid), moneyString);
    FormatMoneyString(salaryReceived, salaryString);

    SendClientMessage(playerid, COLOR_WHITE, "___________[ Sal�rio(PayDay) ]___________");
    if (salaryReceived > 0)
    {
        format(string, sizeof(string), "Sal�rio: R$ [{00FF00}%s{FFFFFF}] | Organiza��o: R$ [{00FF00}%s{FFFFFF}]", moneyString, salaryString);
    }
    else
    {
        format(string, sizeof(string), "Sal�rio: R$ [{00FF00}%s{FFFFFF}]", moneyString);
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
            format(string, sizeof(string), "{FFFF00}B�nus VIP: {FFFFFF}Experi�ncia: {00FF00}+1 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);	
        }
        case 2:
        {
            new moneyVip = 5000 + random(2000);
            vip_exp += 2;
            vip_money += moneyVip;
            format(string, sizeof(string), "{FFFF00}B�nus VIP: {FFFFFF}Experi�ncia: {00FF00}+2 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
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
            format(string, sizeof(string), "{FFFF00}B�nus S�cio: {FFFFFF}Experi�ncia: {00FF00}+3 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);	
        }
        case 2:
        {
            new moneySocio = 10000 + random(5000);
            vip_exp += 4;
            vip_money += moneySocio;
            FormatMoneyString(moneySocio, moneyVipString);
            format(string, sizeof(string), "{FFFF00}B�nus S�cio: {FFFFFF}Experi�ncia: {00FF00}+4 {FFFFFF} | Dinheiro Extra: R$ [{00FF00}%s{FFFFFF}]", moneyVipString);
            SendClientMessage(playerid, COLOR_WHITE, string);
        }
    }

    format(string, sizeof(string), "Experi�ncia Atual para passar de n�vel: ({0080ff}%d/%d{FFFFFF})", Player_GetExperience(playerid), ((Player_GetLevel(playerid) + 1) * 4));
	SendClientMessage(playerid, COLOR_WHITE, string);
    SendClientMessage(playerid, COLOR_WHITE, "_________________________________________");
    GameTextForPlayer(playerid, "~b~PAYDAY !", 5000, 1);
    if (Player_GetExperience(playerid) >= ((Player_GetLevel(playerid) + 1) * 4))
    {
        SendClientMessage(playerid, COLOR_YELLOW, "[Servidor]: Voc� j� possui experi�ncia suficiente para passar de n�vel, use: /comprarnivel");
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

    // Decrease Licenses (I save the license data in each verification because the licenses expires in different periods.)
    if (Player_GetCarLicense(playerid) > 0)
    {
        Player_SetCarLicense(playerid, (Player_GetCarLicense(playerid) - 1));
        Player_SaveLicensesData(playerid);
    }
    if (Player_GetMotorCycleLicense(playerid) > 0)
    {
        Player_SetMotorCycleLicense(playerid, (Player_GetMotorCycleLicense(playerid) - 1));
        Player_SaveLicensesData(playerid);
    }
    if (Player_GetTruckLicense(playerid) > 0)
    {
        Player_SetTruckLicense(playerid, (Player_GetTruckLicense(playerid) - 1));
        Player_SaveLicensesData(playerid);
    }
    if (Player_GetFlyLicense(playerid) > 0)
    {
        Player_SetFlyLicense(playerid, (Player_GetFlyLicense(playerid) - 1));
        Player_SaveLicensesData(playerid);
    }
    if (Player_GetBoatLicense(playerid) > 0)
    {
        Player_SetBoatLicense(playerid, (Player_GetBoatLicense(playerid) - 1));
        Player_SaveLicensesData(playerid);
    }

    if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if (IsValidVehicle(vehicleid))
        {
            if (Vehicle_IsCar(GetVehicleModel(vehicleid)) && Player_GetCarLicense(playerid) <= 0 || Vehicle_IsMotorBike(GetVehicleModel(vehicleid)) && Player_GetMotorCycleLicense(playerid) <= 0 ||
            Vehicle_IsTruck(GetVehicleModel(vehicleid)) && Player_GetTruckLicense(playerid) <= 0 || Vehicle_IsPlane(GetVehicleModel(vehicleid)) && Player_GetFlyLicense(playerid) <= 0 ||
            Vehicle_IsHelicopter(GetVehicleModel(vehicleid)) && Player_GetFlyLicense(playerid) <= 0 || Vehicle_IsBoat(GetVehicleModel(vehicleid)) && Player_GetBoatLicense(playerid) <= 0)
            {
                RemovePlayerFromVehicle(playerid);
                SendClientMessage(playerid, COLOR_INVALID, "A sua habilita��o para conduzir esse ve�culo venceu.");
            }
        }
    }

    Player_SetPaydayTime(playerid, 3600);
    Player_SaveScoreData(playerid);
    Player_SaveStatusData(playerid);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsPlayerUpdateStatusTimer[playerid] = INVALID_VALUE;
    gsLastDeath[playerid] = 0;
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if (gsPlayerUpdateStatusTimer[playerid] != INVALID_VALUE) 
    {
        KillTimer(gsPlayerUpdateStatusTimer[playerid]);
        gsPlayerUpdateStatusTimer[playerid] = INVALID_VALUE;
    }
    CallLocalFunction("BeforeSaveOnDisconnect", "i", playerid);
    Player_SetLastLogin(playerid, Player_GetLastLoginTemp(playerid));
    Player_SaveGeneralData(playerid);
    Player_SaveScoreData(playerid);
    Player_SaveAppearenceData(playerid);
    Player_SaveStatusData(playerid);
    Player_SaveConfigData(playerid);
    return 1;
}

first_hook OnPlayerDeath(playerid, killerid, reason)
{
    if ((gettime() - gsLastDeath[playerid]) < 3)
    {
		new cheatString[128];
		format(cheatString, sizeof(cheatString), "Anti-Cheat: %s[%d] foi kickado por suspeita de fake-kill.", GetPlayerNameCustom(playerid), playerid);
		SendClientMessageToAll(COLOR_LIGHTRED, cheatString);
		KickPlayer(playerid);
        return 1;
    }
	gsLastDeath[playerid] = gettime();
    SendDeathMessage(killerid, playerid, reason);
    return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
    DisablePlayerCheckpoint(playerid);
    return 1;
}

hook FirstSpawnOnLogin(playerid)
{
    gsPlayerUpdateStatusTimer[playerid] = SetTimerEx("PlayerUpdateStatus", 1000, true, "i", playerid);
    return 1;
}

hook OnPlayerUpdateScreenSize(playerid)
{
    HidePlayerHud(playerid);
    ShowPlayerHud(playerid);

    if (Inventory_GetIsOpenedStatus(playerid))
    {
        ClosePlayerInventory(playerid);
        Inventory_AdaptToScreen(playerid);
        OpenPlayerInventory(playerid);
    }
    else
    {
        Inventory_AdaptToScreen(playerid);
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
