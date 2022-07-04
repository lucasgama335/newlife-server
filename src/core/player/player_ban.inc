#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Query Callbacks -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock AdminBanPlayer(playerid, adminId, days, const reason[])
{
    new reasonCopy[MAX_REASON_STRING], playerIp[MAX_IP_STRING], banTime = Chrono_ConvertToInt(Chrono_GetTimeNow()), unBanTime = (days > 0 ? Chrono_ConvertToInt(Chrono_AddDays(Chrono_GetTimeNow(), days)) : 0);
    strcopy(reasonCopy, reason, MAX_REASON_STRING);
    format(playerIp, sizeof(playerIp), "%s", GetPlayerIpCustom(playerid));
    if (days <= 0) unBanTime = 0;

    inline const IsPlayerBanned()
    {
        if (cache_num_rows() > 0)
        {
            new string[142];
            format(string, sizeof(string), "[ERRO]: A tentativa de banimento do jogador %s pelo admin %s falhou, porque ele já estava banido.", GetPlayerNameCustom(playerid), GetPlayerNameCustom(adminId));
            PrintLog(FOLDER_BANS_ERROR, string);
            SendClientMessage(adminId, COLOR_INVALID, "Esse jogador já está banido.");
        }
        else
        {
            new reasonCopyInline[MAX_REASON_STRING], playerIpCopy[MAX_IP_STRING];
            strcopy(reasonCopyInline, reasonCopy, MAX_REASON_STRING);
            format(playerIpCopy, sizeof(playerIpCopy), "%s", playerIp);
            inline const OnPlayerBanned()
            {
                new db_id = cache_insert_id();
                if (db_id != MYSQL_INVALID_VALUE)
                {
                    Player_SetBanId(playerid, db_id);
                    Player_SetBanPlayerId(playerid, Player_GetId(playerid));
                    Player_SetBanAdminId(playerid, Player_GetId(adminId));
                    Player_SetBanAdminName(playerid, GetPlayerNameCustom(adminId));
                    Player_SetBanIp(playerid, playerIpCopy);
                    Player_SetBanTime(playerid, Chrono_ConvertToTimestamp(banTime));
                    if (days <= 0)
                    {
                        Player_SetBanForeverStatus(playerid, true);
                    }
                    else
                    {
                        Player_SetUnBanTime(playerid, Chrono_ConvertToTimestamp(unBanTime));
                    }
                    Player_SetBanReason(playerid, reasonCopyInline);
                    
                    new banString[144];
                    if (days <= 0)
                    {
                        format(banString, sizeof(banString), "[BAN]: %s foi banido por %s permanentemente. [Motivo]: %s.", GetPlayerNameCustom(playerid), Player_GetBanAdminName(playerid), reasonCopyInline);
                    }
                    else
                    {
                        format(banString, sizeof(banString), "[BAN]: %s foi banido por %s durante [%d] dia(s). [Motivo]: %s.", GetPlayerNameCustom(playerid), Player_GetBanAdminName(playerid), days, reasonCopyInline);
                    }
                    SendClientMessageToAll(COLOR_LIGHTRED, banString);
                    SendClientMessage(playerid, COLOR_YELLOW, "|________________Instruções para Revisão de Ban________________|");
                    SendClientMessage(playerid, COLOR_SKIN, "Tire uma SS da tela apertando F8 imediatamente após ser banido");
                    SendClientMessage(playerid, COLOR_SKIN, "E acesse o nosso fórum para solicitar uma revisão de banimento");
                    SendClientMessage(playerid, COLOR_LIGHTRED, "Atenção: Você só será desbanido se for inocente !");
                    GameTextForPlayer(playerid, "~r~banido", 2500, 3);

                    PrintLog(FOLDER_BANS_SUCCESS, banString);

                    KickPlayer(playerid);
                }
                else
                {
                    new string[115];
                    format(string, sizeof(string), "[ERRO]: Houve um erro desconhecido ao banir o jogador %s. [Admin: %s].", GetPlayerNameCustom(playerid), GetPlayerNameCustom(adminId));
                    PrintLog(FOLDER_BANS_ERROR, string);
                    SendClientMessage(adminId, COLOR_INVALID, "Houve um erro ao banir o jogador.");
                }
            }
            MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerBanned, "INSERT INTO %s (%s, %s, %s, %s, %s, %s) VALUES (%d, %d, '%s', %d, %d, '%s')", BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, BAN_FIELD_ADMIN_ID, BAN_FIELD_PLAYER_IP, BAN_FIELD_BAN_TIME, BAN_FIELD_UNBAN_TIME, BAN_FIELD_REASON,
            Player_GetId(playerid), Player_GetId(adminId), playerIp, banTime, unBanTime, reasonCopy);
        }
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline IsPlayerBanned, "SELECT %s FROM %s WHERE %s = %d", BAN_FIELD_ID, BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, Player_GetId(playerid));
    return 1;
}

stock SystemBanPlayer(playerid, days, const reason[])
{
    new reasonCopy[MAX_REASON_STRING], playerIp[MAX_IP_STRING], banTime = Chrono_ConvertToInt(Chrono_GetTimeNow()), unBanTime = (days > 0 ? Chrono_ConvertToInt(Chrono_AddDays(Chrono_GetTimeNow(), days)) : 0);
    strcopy(reasonCopy, reason, MAX_REASON_STRING);
    format(playerIp, sizeof(playerIp), "%s", GetPlayerIpCustom(playerid));
    if (days <= 0) unBanTime = 0;

    inline const IsPlayerBanned()
    {
        if (cache_num_rows() > 0)
        {
            new string[119];
            format(string, sizeof(string), "[ERRO]: A tentativa de banimento (automático) do jogador %s falhou, porque ele já estava banido.", GetPlayerNameCustom(playerid));
            PrintLog(FOLDER_BANS_ERROR, string);
        }
        else
        {
            new reasonCopyInline[MAX_REASON_STRING], playerIpCopy[MAX_IP_STRING];
            strcopy(reasonCopyInline, reasonCopy, MAX_REASON_STRING);
            format(playerIpCopy, sizeof(playerIpCopy), "%s", playerIp);
            inline const OnPlayerBanned()
            {
                new db_id = cache_insert_id();
                if (db_id != MYSQL_INVALID_VALUE)
                {
                    Player_SetBanId(playerid, db_id);
                    Player_SetBanPlayerId(playerid, Player_GetId(playerid));
                    Player_SetBanAdminId(playerid, INVALID_VALUE);
                    Player_SetBanAdminName(playerid, "Sistema");
                    Player_SetBanIp(playerid, playerIpCopy);
                    Player_SetBanTime(playerid, Chrono_ConvertToTimestamp(banTime));
                    if (days <= 0)
                    {
                        Player_SetBanForeverStatus(playerid, true);
                    }
                    else
                    {
                        Player_SetUnBanTime(playerid, Chrono_ConvertToTimestamp(unBanTime));
                    }
                    Player_SetBanReason(playerid, reasonCopyInline);
                    
                    new banString[144];
                    if (days <= 0)
                    {
                        format(banString, sizeof(banString), "[BAN]: %s foi banido permanentemente pelo sistema. [Motivo]: %s.", GetPlayerNameCustom(playerid), reasonCopyInline);

                    }
                    else
                    {
                        format(banString, sizeof(banString), "[BAN]: %s foi banido por pelo sistema durante [%d] dia(s). [Motivo]: %s.", GetPlayerNameCustom(playerid), days, reasonCopyInline);
                    }
                    SendClientMessageToAll(COLOR_LIGHTRED, banString);
                    SendClientMessage(playerid, COLOR_YELLOW, "|________________Instruções para Revisão de Ban________________|");
                    SendClientMessage(playerid, COLOR_SKIN, "Tire uma SS da tela apertando F8 imediatamente após ser banido");
                    SendClientMessage(playerid, COLOR_SKIN, "E acesse o nosso fórum para solicitar uma revisão de banimento");
                    SendClientMessage(playerid, COLOR_LIGHTRED, "Atenção: Você só será desbanido se for inocente !");
                    GameTextForPlayer(playerid, "~r~banido", 2500, 3);

                    PrintLog(FOLDER_BANS_SUCCESS, banString);

                    KickPlayer(playerid);
                }
                else
                {
                    new string[96];
                    format(string, sizeof(string), "[ERRO]: Houve um erro desconhecido ao banir o jogador automaticamente %s.", GetPlayerNameCustom(playerid));
                    PrintLog(FOLDER_BANS_ERROR, string);
                }
            }
            MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerBanned, "INSERT INTO %s (%s, %s, %s, %s, %s) VALUES (%d, '%s', %d, %d, '%s')", BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, BAN_FIELD_PLAYER_IP, BAN_FIELD_BAN_TIME, BAN_FIELD_UNBAN_TIME, BAN_FIELD_REASON,
            Player_GetId(playerid), playerIp, banTime, unBanTime, reasonCopy);
        }
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline IsPlayerBanned, "SELECT %s FROM %s WHERE %s = %d", BAN_FIELD_ID, BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, Player_GetId(playerid));
    return 1;
}

stock AdminBanPlayerByName(const name[], adminId, days, const reason[])
{
    new reasonCopy[MAX_REASON_STRING], playerName[MAX_PLAYER_NAME + 1], banTime = Chrono_ConvertToInt(Chrono_GetTimeNow()), unBanTime = (days > 0 ? Chrono_ConvertToInt(Chrono_AddDays(Chrono_GetTimeNow(), days)) : 0);
    strcopy(reasonCopy, reason, MAX_REASON_STRING);
    strcopy(playerName, name, (MAX_PLAYER_NAME + 1));

    if (days <= 0) unBanTime = 0;

    inline const PlayerExistsInDatabase()
    {
        if (cache_num_rows() > 0)
        {
            new playerIdDbm, playerIp[MAX_IP_STRING], reasonCopyInline[MAX_REASON_STRING], playerNameCopy[MAX_PLAYER_NAME + 1];
            cache_get_value_name_int(0, PLAYER_FIELD_ID, playerIdDbm);
            cache_get_value_name(0, PLAYER_FIELD_IP, playerIp, MAX_IP_STRING);

            strcopy(reasonCopyInline, reasonCopy, MAX_REASON_STRING);
            strcopy(playerNameCopy, playerName, (MAX_PLAYER_NAME + 1));

            new playerid = GetPlayerIdByDb(playerIdDbm);

            inline const IsPlayerBanned()
            {
                if (cache_num_rows() > 0)
                {
                    new string[119];
                    format(string, sizeof(string), "[ERRO]: A tentativa de banimento por nome do jogador %s falhou, porque ele já estava banido.", playerNameCopy);
                    PrintLog(FOLDER_BANS_ERROR, string);
                    SendClientMessage(adminId, COLOR_INVALID, "Esse jogador já está banido.");
                }
                else
                {
                    new playerNameCopy2[MAX_PLAYER_NAME + 1], playerIpCopy[MAX_IP_STRING], reasonCopy2[MAX_REASON_STRING];
                    strcopy(reasonCopy2, reasonCopyInline, MAX_REASON_STRING);
                    strcopy(playerNameCopy2, playerNameCopy, (MAX_PLAYER_NAME + 1));
                    strcopy(playerIpCopy, playerIp, MAX_IP_STRING);

                    inline const OnPlayerBanned()
                    {
                        new db_id = cache_insert_id();
                        if (db_id != MYSQL_INVALID_VALUE)
                        {
                            new banString[188];
                            if (days <= 0)
                            {
                                format(banString, sizeof(banString), "[BAN]: %s agendou o banimento de %s permanentemente. [Motivo]: %s.", GetPlayerNameCustom(adminId), playerNameCopy2, reasonCopy2);
                            }
                            else
                            {
                                format(banString, sizeof(banString), "[BAN]: %s agendou o banimento de %s durante [%d] dia(s). [Motivo]: %s.", GetPlayerNameCustom(adminId), playerNameCopy2, days, reasonCopy2);
                            }
                            SendClientMessageToAll(COLOR_LIGHTRED, banString);

                            if (playerid != INVALID_PLAYER_ID)
                            {
                                Player_SetBanId(playerid, db_id);
                                Player_SetBanPlayerId(playerid, Player_GetId(playerid));
                                Player_SetBanAdminId(playerid, Player_GetId(adminId));
                                Player_SetBanAdminName(playerid, GetPlayerNameCustom(adminId));
                                Player_SetBanIp(playerid, playerIpCopy);
                                Player_SetBanTime(playerid, Chrono_ConvertToTimestamp(banTime));
                                if (days <= 0)
                                {
                                    Player_SetBanForeverStatus(playerid, true);
                                }
                                else
                                {
                                    Player_SetUnBanTime(playerid, Chrono_ConvertToTimestamp(unBanTime));
                                }
                                Player_SetBanReason(playerid, reasonCopy2);

                                SendClientMessage(playerid, COLOR_YELLOW, "|________________Instruções para Revisão de Ban________________|");
                                SendClientMessage(playerid, COLOR_SKIN, "Tire uma SS da tela apertando F8 imediatamente após ser banido");
                                SendClientMessage(playerid, COLOR_SKIN, "E acesse o nosso fórum para solicitar uma revisão de banimento");
                                SendClientMessage(playerid, COLOR_LIGHTRED, "Atenção: Você só será desbanido se for inocente !");
                                GameTextForPlayer(playerid, "~r~banido", 2500, 3);

                                KickPlayer(playerid);
                            }
                            PrintLog(FOLDER_BANS_SUCCESS, banString);
                        }
                        else
                        {
                            new string[115];
                            format(string, sizeof(string), "[ERRO]: Houve um erro desconhecido ao banir o jogador %s. [Admin: %s].", playerNameCopy2, GetPlayerNameCustom(adminId));
                            PrintLog(FOLDER_BANS_ERROR, string);
                            SendClientMessage(adminId, COLOR_INVALID, "Houve um erro ao banir o jogador.");
                        }
                    }
                    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerBanned, "INSERT INTO %s (%s, %s, %s, %s, %s, %s) VALUES (%d, %d, '%s', %d, %d, '%s')", BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, BAN_FIELD_ADMIN_ID, BAN_FIELD_PLAYER_IP, BAN_FIELD_BAN_TIME, BAN_FIELD_UNBAN_TIME, BAN_FIELD_REASON,
                    playerIdDbm, Player_GetId(adminId), playerIpCopy, banTime, unBanTime, reasonCopy2);
                }
            }
            MySQL_TQueryInline(Database_GetConnection(), using inline IsPlayerBanned, "SELECT %s FROM %s WHERE %s = %d", BAN_FIELD_ID, BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, playerIdDbm);
        }
        else
        {
            new string[142];
            format(string, sizeof(string), "[ERRO]: A tentativa de banimento do jogador %s pelo admin %s falhou, porque esse jogador não existe.", playerName, GetPlayerNameCustom(adminId));
            PrintLog(FOLDER_BANS_ERROR, string);
            SendClientMessage(adminId, COLOR_INVALID, "Esse jogador não existe.");
        }
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline PlayerExistsInDatabase, "SELECT %s, %s FROM %s WHERE %s = '%s'", PLAYER_FIELD_ID, PLAYER_FIELD_IP, PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, name);
    return 1;
}

stock UnBanPlayer(const name[], adminId)
{
    new nameCopy[MAX_PLAYER_NAME + 1];
    strcopy(nameCopy, name, MAX_PLAYER_NAME);

    inline const PlayerExistsInDatabase()
    {
        if (cache_num_rows() > 0)
        {
            new playerIdDbm, nameCopy2[MAX_PLAYER_NAME + 1];
            cache_get_value_name_int(0, PLAYER_FIELD_ID, playerIdDbm);
            strcopy(nameCopy2, nameCopy, MAX_PLAYER_NAME);

            inline const IsPlayerBanned()
            {
                if (cache_num_rows() > 0)
                {
                    inline const OnPlayerBanned()
                    {
                        new unBanString[79];
                        format(unBanString, sizeof(unBanString), "[DESBAN]: %s foi desbanido por %s.", nameCopy2, GetPlayerNameCustom(adminId));
                        SendClientMessageToAll(COLOR_LIGHTRED, unBanString);
                        PrintLog(FOLDER_UNBAN_SUCCESS, unBanString);
                    }
                    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerBanned, "DELETE FROM %s WHERE %s = %d", BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, playerIdDbm);
                }
                else
                {
                    new string[153];
                    format(string, sizeof(string), "[ERRO]: A tentativa de desbanimento do jogador %s pelo admin %s falhou, porque esse jogador não está banido.", nameCopy2, GetPlayerNameCustom(adminId));
                    PrintLog(FOLDER_UNBAN_ERROR, string);
                    SendClientMessage(adminId, COLOR_INVALID, "Esse jogador não está banido.");
                }
            }
            MySQL_TQueryInline(Database_GetConnection(), using inline IsPlayerBanned, "SELECT %s FROM %s WHERE %s = %d", BAN_FIELD_ID, BAN_TABLE_NAME, BAN_FIELD_PLAYER_ID, playerIdDbm);
        }
        else
        {
            new string[148];
            format(string, sizeof(string), "[ERRO]: A tentativa de desbanimento do jogador %s pelo admin %s falhou, porque esse jogador não existe.", nameCopy, GetPlayerNameCustom(adminId));
            PrintLog(FOLDER_UNBAN_ERROR, string);
            SendClientMessage(adminId, COLOR_INVALID, "Esse jogador não existe.");
        }
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline PlayerExistsInDatabase, "SELECT %s, %s FROM %s WHERE %s = '%s'", PLAYER_FIELD_ID, PLAYER_FIELD_IP, PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, name);
    return 1;
}


//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
