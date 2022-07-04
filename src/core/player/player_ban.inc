#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Query Callbacks -------------------------
function:OnPlayerBanned(playerid, adminId, const playerIp[], days, const reason[], banTime, unBanTime)
{
    new db_id = cache_insert_id();
    if (db_id != MYSQL_INVALID_VALUE)
    {
        new adminName[MAX_PLAYER_NAME + 5] = "pelo Sistema";
        Player_SetBanId(playerid, db_id);
        Player_SetBanPlayerId(playerid, Player_GetId(playerid));
        Player_SetBanAdminId(playerid, Player_GetId(adminId));
        Player_SetBanIp(playerid, playerIp);
        Player_SetBanTime(playerid, Chrono_ConvertToTimestamp(banTime));
        Player_SetUnBanTime(playerid, Chrono_ConvertToTimestamp(unBanTime));
        Player_SetBanReason(playerid, reason);
        if (adminId != INVALID_PLAYER_ID) 
        {
            format(adminName, sizeof(adminName), "por %s", GetPlayerNameCustom(adminId));
        }
        
        new banString[144];
        if (days > 0)
        {
            format(banString, sizeof(banString), "[BAN]: %s foi banido %s durante [%d] dia(s). [Motivo]: %s.", GetPlayerNameCustom(playerid), adminName, days, reason);
        }
        else
        {
            format(banString, sizeof(banString), "[BAN]: %s foi banido %s permanentemente. [Motivo]: %s.", GetPlayerNameCustom(playerid), adminName, reason);
        }
        SendClientMessageToAll(COLOR_LIGHTRED, banString);
        SendClientMessage(playerid, COLOR_YELLOW, "|________________Instruções para Revisão de Ban________________|");
        SendClientMessage(playerid, COLOR_SKIN, "Tire uma SS da tela apertando F8 imediatamente após ser banido");
        SendClientMessage(playerid, COLOR_SKIN, "E acesse o nosso fórum para solicitar uma revisão de banimento");
        SendClientMessage(playerid, COLOR_LIGHTRED, "Atenção: Você só será desbanido se for inocente !");
        GameTextForPlayer(playerid, "~r~banido", 2500, 3);
        return 1;
    }
    else
    {
        SendClientMessage(adminId, COLOR_INVALID, "Ocorreu um erro ao banir o jogador.");
    }
    return 0;
}

function:TryToBanPlayer(playerid, adminId, const playerIp[], days, const reason[])
{
    if(cache_num_rows() > 0)
    {
        return SendClientMessage(adminId, COLOR_INVALID, "Esse jogador já está banido.");
    }
    else
    {
        InsertBanInDb(playerid, adminId, playerIp, days, reason);
    }
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock BanPlayer(playerid, adminId, const playerIp[], days, const reason[])
{
    new queryString[53];
    mysql_format(Database_GetConnection(), queryString, sizeof(queryString), "SELECT %s FROM %s WHERE %s = %d", 
    BAN_FIELD_ID, BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), queryString, "TryToBanPlayer", "iisis", playerid, adminId, playerIp, days, reason);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock InsertBanInDb(playerid, adminId, const playerIp[], days, const reason[])
{
    new queryString[226];
    new banTime = Chrono_ConvertToInt(Chrono_GetTimeNow()), unBanTime = (days > 0 ? Chrono_ConvertToInt(Chrono_AddDays(Chrono_GetTimeNow(), days)) : 0);
    if (adminId != INVALID_PLAYER_ID)
    {
        mysql_format(Database_GetConnection(), queryString, sizeof(queryString), "INSERT INTO %s (%s, %s, %s, %s, %s, %s) VALUES (%d, %d, '%s', %d, %d, '%s')", 
        BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, BAN_FIELD_ADMIN_ID, BAN_FIELD_PLAYER_IP, BAN_FIELD_BAN_TIME, BAN_FIELD_UNBAN_TIME, BAN_FIELD_REASON,
        Player_GetId(playerid), Player_GetId(adminId), playerIp, banTime, unBanTime, reason);
        mysql_tquery(Database_GetConnection(), queryString, "OnPlayerBanned", "iisisii", playerid, adminId, playerIp, days, reason, banTime, unBanTime);
    }
    else
    {
        mysql_format(Database_GetConnection(), queryString, sizeof(queryString), "INSERT INTO %s (%s, %s, %s, %s, %s) VALUES (%d, '%s', %d, %d, '%s')", 
        BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, BAN_FIELD_PLAYER_IP, BAN_FIELD_BAN_TIME, BAN_FIELD_UNBAN_TIME, BAN_FIELD_REASON,
        Player_GetId(playerid), playerIp, banTime, unBanTime, reason);
        mysql_tquery(Database_GetConnection(), queryString, "OnPlayerBanned", "iisisii", playerid, adminId, playerIp, days, reason, banTime, unBanTime);
    }
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
