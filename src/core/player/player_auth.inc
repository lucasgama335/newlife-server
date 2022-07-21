#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_CONNECTIONS_FROM_IP     3

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static loginAttempts[MAX_PLAYERS],
       bool:recentlyLogged[MAX_PLAYERS],
       bool:isRegistered[MAX_PLAYERS];

static gskickPlayerTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:OnLoginTimeout(playerid)
{
    ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Fazer Login ", "{FFFFFF}Você foi kickado automaticamente por ficar\nmuito tempo no processo de login sem realizar tentativas válidas.\nPor favor, logue novamente!.", "Okay", "");
    KickPlayer(playerid);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock Player_ClearLoginVars(playerid) 
{
    // Temporary Vars
    loginAttempts[playerid] = 0;
    recentlyLogged[playerid] = true;
    isRegistered[playerid] = false;
    return 1;
}

static stock InsertPlayerInDataBase(playerid, const password[]) 
{
    inline const OnPlayerRegister()
    {
        Player_SetId(playerid, cache_insert_id());
        OnPlayerLogin(playerid);
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerRegister, "INSERT INTO %s (%s, %s, %s) VALUES ('%s', '%s', '%s')", PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, PLAYER_FIELD_PASSWORD, PLAYER_FIELD_IP, GetPlayerNameCustom(playerid), password, GetPlayerIpCustom(playerid));
    return 1;
}

static stock ShowLoginDialog(playerid)
{
    static string[256];
    SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta está registrada, digite sua senha para logar.");
    format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, GetPlayerNameCustom(playerid));
    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
    return 1;
}

static stock ShowRegisterDialog(playerid)
{
    static string[256];
    SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta não está registrada, digite uma senha para se registrar.");
    format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}Não Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, GetPlayerNameCustom(playerid));
    ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Cancelar");
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock SpawnPlayerLogged(playerid)
{
    if (Player_GetLoggedStatus(playerid))
    {
        SetPlayerInterior(playerid, 0);
        SetCameraBehindPlayer(playerid);
        SetSpawnInfo(playerid, -1, (Player_GetGender(playerid) == 1 ? DEFAULT_SKIN_MALE : DEFAULT_SKIN_FEMALE), SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);
    }
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
public OnPlayerConnect(playerid)
{
    new numPlayersInSameIp = GetPlayersInSameIp(playerid);
    if (numPlayersInSameIp > MAX_CONNECTIONS_FROM_IP)
	{
        printf("MAXIPs: O Jogador[%d] excedeu o número de conexões [%d] por IP: [%s].", playerid, MAX_CONNECTIONS_FROM_IP, GetPlayerIpCustom(playerid));
        Kick(playerid);
    }

    new race_check = Database_IncrementRaceCheck(playerid);
    Player_ClearLoginVars(playerid);

    // Textdraws
    ShowLoadingScreen(playerid);
    SetPlayerColor(playerid, COLOR_GRAD2);

    inline const OnPlayerDataLoaded()
    {
        if (race_check != Database_GetRaceCheck(playerid)) return Kick(playerid);
        if(cache_num_rows() > 0)
        {
            // General Info
            new id, e_ADMIN_LEVELS:admin, attendances, rating, numberRating, tutorial, lastLogin, lastConnectedTime, Float:posX, Float:posY, Float:posZ, Float:posA, interior, vW;
            cache_get_value_name_int(0, PLAYER_FIELD_ID, id);
            cache_get_value_name_int(0, PLAYER_FIELD_ADMIN, admin);
            cache_get_value_name_int(0, PLAYER_FIELD_ATTENDANCES, attendances);
            cache_get_value_name_int(0, PLAYER_FIELD_RATING, rating);
            cache_get_value_name_int(0, PLAYER_FIELD_NUMBERRANTING, numberRating);
            cache_get_value_name_int(0, PLAYER_FIELD_TUTORIAL, tutorial);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_LOGIN, lastLogin);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_CONNECTED_TIME, lastConnectedTime);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSX, posX);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSY, posY);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSZ, posZ);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSA, posA);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_INTERIOR, interior);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_VW, vW);

            Player_SetId(playerid, id);
            Player_SetAdminLevel(playerid, admin, false);
            Player_SetAdminAttendances(playerid, attendances);
            Player_SetAdminRating(playerid, rating);
            Player_SetAdminNumberRating(playerid, numberRating);
            Player_SetTutorialStatus(playerid, (tutorial == 0 ? false : true));
            Player_SetLastLogin(playerid, Chrono_ConvertToTimestamp(lastLogin));
            Player_SetLastConnectedTime(playerid, lastConnectedTime);
            Player_SetLastPosition(playerid, posX, posY, posZ, posA, interior, vW);

            // Job
            new j_JOBS_LIST:job, org, orgRole;
            cache_get_value_name_int(0, PLAYER_FIELD_JOB, job);
            cache_get_value_name_int(0, PLAYER_FIELD_ORG, org);
            cache_get_value_name_int(0, PLAYER_FIELD_ORG_ROLE, orgRole);

            Player_SetJob(playerid, job);
            Player_SetOrg(playerid, org, orgRole);

            // Appearence
            new gender, fightStyle, skin, oldSkin;
            cache_get_value_name_int(0, PLAYER_FIELD_GENDER, gender);
            cache_get_value_name_int(0, PLAYER_FIELD_FIGHT_STYLE, fightStyle);
            cache_get_value_name_int(0, PLAYER_FIELD_SKIN, skin);
            cache_get_value_name_int(0, PLAYER_FIELD_OLDSKIN, oldSkin);

            Player_SetGender(playerid, gender);
            Player_SetFightStyle(playerid, fightStyle);
            Player_SetSkin(playerid, skin);
            Player_SetOldSkin(playerid, oldSkin);

            // Money Info
            new money, illegalMoney, illegalSafeMoney, bankStatus, bankMoney, coins;
            cache_get_value_name_int(0, PLAYER_FIELD_MONEY, money);
            cache_get_value_name_int(0, PLAYER_FIELD_ILLEGAL_MONEY, illegalMoney);
            cache_get_value_name_int(0, PLAYER_FIELD_ILLEGAL_SAFE_MONEY, illegalSafeMoney);
            cache_get_value_name_int(0, PLAYER_FIELD_BANK_ACCOUNT, bankStatus);
            cache_get_value_name_int(0, PLAYER_FIELD_BANK_MONEY, bankMoney);
            cache_get_value_name_int(0, PLAYER_FIELD_COINS, coins);

            Player_SetMoney(playerid, money, false);
            Player_SetIllegalMoney(playerid, illegalMoney);
            Player_SetIllegalSafeMoney(playerid, illegalSafeMoney);
            Player_SetBankStatus(playerid, bankStatus == 0 ? false : true);
            Player_SetBankMoney(playerid, bankMoney);
            Player_SetCoins(playerid, coins);

            // Score Info
            new level, hoursPlayed, experience, deaths, kills, wantedLevel, noobAnswers;
            cache_get_value_name_int(0, PLAYER_FIELD_LEVEL, level);
            cache_get_value_name_int(0, PLAYER_FIELD_HOURS_PLAYED, hoursPlayed);
            cache_get_value_name_int(0, PLAYER_FIELD_EXP, experience);
            cache_get_value_name_int(0, PLAYER_FIELD_DEATHS, deaths);
            cache_get_value_name_int(0, PLAYER_FIELD_KILLS, kills);
            cache_get_value_name_int(0, PLAYER_FIELD_WANTED_LEVEL, wantedLevel);
            cache_get_value_name_int(0, PLAYER_FIELD_NOOB_ANSWERS, noobAnswers);

            Player_SetLevel(playerid, level);
            Player_SetHoursPlayed(playerid, hoursPlayed);
            Player_SetExperience(playerid, experience);
            Player_SetDeaths(playerid, deaths);
            Player_SetKills(playerid, kills);
            Player_SetWantedLevel(playerid, wantedLevel);
            Player_SetNoobAnswers(playerid, noobAnswers);

            // Status Info
            new jailed, jailTime, hungry, drink, paydayTime, warnings, muted, mutedNoob;
            cache_get_value_name_int(0, PLAYER_FIELD_JAILED, jailed);
            cache_get_value_name_int(0, PLAYER_FIELD_JAILTIME, jailTime);
            cache_get_value_name_int(0, PLAYER_FIELD_HUNGRY, hungry);
            cache_get_value_name_int(0, PLAYER_FIELD_DRINK, drink);
            cache_get_value_name_int(0, PLAYER_FIELD_PAYDAY_TIME, paydayTime);
            cache_get_value_name_int(0, PLAYER_FIELD_WARNINGS, warnings);
            cache_get_value_name_int(0, PLAYER_FIELD_MUTED, muted);
            cache_get_value_name_int(0, PLAYER_FIELD_MUTED_NOOB, mutedNoob);

            Player_SetJailed(playerid, jailed);
            Player_SetJailTime(playerid, jailTime);
            Player_SetHungry(playerid, hungry);
            Player_SetDrink(playerid, drink);
            Player_SetPaydayTime(playerid, paydayTime);
            Player_SetWarnings(playerid, warnings);
            Player_SetMutedTime(playerid, muted);
            Player_SetNoobMutedTime(playerid, mutedNoob);

            // Licenses Info
            new car_license, motorcycle_license, fly_license, boat_license, truck_license, gun_license;
            cache_get_value_name_int(0, PLAYER_FIELD_CAR_LICENSE, car_license);
            cache_get_value_name_int(0, PLAYER_FIELD_MOTORCYCLE_LICENSE, motorcycle_license);
            cache_get_value_name_int(0, PLAYER_FIELD_FLY_LICENSE, fly_license);
            cache_get_value_name_int(0, PLAYER_FIELD_BOAT_LICENSE, boat_license);
            cache_get_value_name_int(0, PLAYER_FIELD_TRUCK_LICENSE, truck_license);
            cache_get_value_name_int(0, PLAYER_FIELD_GUN_LICENSE, gun_license);

            Player_SetCarLicense(playerid, car_license);
            Player_SetMotorCycleLicense(playerid, motorcycle_license);
            Player_SetFlyLicense(playerid, fly_license);
            Player_SetBoatLicense(playerid, boat_license);
            Player_SetTruckLicense(playerid, truck_license);
            Player_SetGunLicense(playerid, gun_license);

            // Config Info
            new e_TAGS:tag, city, spawn, document, speedometer, tracker, hitsound, e_SCREENS:screenSize, territorialChat, vipChat, socioChat, noobChat, leaderChat, stream;
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_TAG, tag);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_CITY, city);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_SPAWN, spawn);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_DOCUMENT, document);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_SPEED, speedometer);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_TRACKER, tracker);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_HITSOUND, hitsound);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_SCREEN, screenSize);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_TERRITORIAL_CHAT, territorialChat);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_VIP_CHAT, vipChat);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_SOCIO_CHAT, socioChat);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_NOOB_CHAT, noobChat);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_LEADER_CHAT, leaderChat);
            cache_get_value_name_int(0, PLAYER_FIELD_CONFIG_STREAM, stream);

            Player_UpdateConfigTypes(playerid, tag, city, spawn, document, speedometer, tracker, hitsound, screenSize);
            Player_UpdateConfigChats(playerid, (territorialChat == 1 ? true : false), (vipChat == 1 ? true : false), (socioChat == 1 ? true : false), (noobChat == 1 ? true : false), (leaderChat == 1 ? true : false), (stream == 1 ? true : false));

            isRegistered[playerid] = true;
            AdaptSpeedometerToScreen(playerid);
            AdaptAlertToScreen(playerid);
            AdaptDriveSchoolHudToScreen(playerid);
            AdaptFuelTextdrawToScreen(playerid);
            Inventory_AdaptToScreen(playerid);
            
            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
            SendClientMessage(playerid, COLOR_SOFTGREY, "* Dados Carregados com sucesso, pressione em 'Fazer Login'.");
        }
        else
        {
            isRegistered[playerid] = false;
        }
        if (gskickPlayerTimer[playerid] != INVALID_VALUE) 
        {
            KillTimer(gskickPlayerTimer[playerid]);
            gskickPlayerTimer[playerid] = INVALID_VALUE;
        }
        gskickPlayerTimer[playerid] = SetTimerEx("OnLoginTimeout", 60000, false, "i", playerid);
        Streamer_UpdateEx(playerid, 1430.3030, -1222.7921, 153.7742, 0, 0, STREAMER_TYPE_OBJECT, 3000, 1);
        Streamer_UpdateEx(playerid, 1430.3030, -1222.7921, 153.7742, 0, 0, STREAMER_TYPE_ACTOR);
        InterpolateCameraPos(playerid, 1430.3030, -1222.7921, 153.7742, 1430.2842, -1227.1599, 153.6056, CAMERA_SPEED, CAMERA_MOVE);
		InterpolateCameraLookAt(playerid, 1430.7921, -1223.6633, 153.5791, 1431.1718, -1227.6151, 153.3904, CAMERA_SPEED, CAMERA_MOVE);

        HideLoadingScreen(playerid);
        ShowLoginScreen(playerid);
    }
    Player_UpdateLastLoginTemp(playerid, Chrono_GetTimeNow());
	PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/ocpam5bletkz3j8/intro.mp3?dl=1");
    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
    SendClientMessage(playerid, COLOR_SOFTGREY, "* Aguarde enquanto carregamos os seus dados...");
    // Verify if player exists in database
    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerDataLoaded, "SELECT * FROM %s WHERE %s = '%e'", PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, GetPlayerNameCustom(playerid));
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Database_IncrementRaceCheck(playerid);
    Player_SetLoggedStatus(playerid, false);
    
    new string[150], Float:PacketLoss;
    switch (reason)
    {
        case 0: format(string, sizeof(string), "%s saiu do servidor por erro de conexão ou crash (ID: %d - Ping: %d - PL: %.01f).", GetPlayerNameCustom(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 1: format(string, sizeof(string), "%s saiu por vontade própria (ID: %d - Ping: %d - PL: %.01f).", GetPlayerNameCustom(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 2: format(string, sizeof(string), "%s saiu do servidor por ter sido kickado ou banido (ID: %d - Ping: %d - PL: %.01f).", GetPlayerNameCustom(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
	}
    SendMessageInRange(100.0, playerid, string, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE);
    return 1;
}

hook OnPlayerRequestClass(playerid, classid)
{
    #pragma unused classid // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    if (IsPlayerNPC(playerid))
	{
		return 1;
	}

    if (recentlyLogged[playerid]) 
	{
        TogglePlayerSpectating(playerid, true);
        InterpolateCameraPos(playerid, 1430.3030, -1222.7921, 153.7742, 1430.2842, -1227.1599, 153.6056, CAMERA_SPEED, CAMERA_MOVE);
		InterpolateCameraLookAt(playerid, 1430.7921, -1223.6633, 153.5791, 1431.1718, -1227.6151, 153.3904, CAMERA_SPEED, CAMERA_MOVE);
    }
    else
    {
        SpawnPlayerLogged(playerid);
    }
    return 0;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    // Login Screen: Login Button
	if (clickedid == GetLoginScreenTextdrawId(5))
	{
        if (isRegistered[playerid])
        {
            ShowLoginDialog(playerid);
        }
        else
        {
            ShowRegisterDialog(playerid);
        }
        return 1;
	}
	// Login Screen: Info Button
	if (clickedid == GetLoginScreenTextdrawId(6))
	{
		ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Informações Gerais", "{FFFFFF}O NewLife é um servidor RPG, que tem como principal objetivo a simulação da vida real.\n\nNele haverá guerra entre facções criminosas, operacções policiais, roubos, sequestro, assaltos, emboscadas dentre outras coisas.\n\nNo servidor também é possível adquirir propriedade privada, como: empresas, casas, mansões, veículo próprio, celular, itens e etc.\n\n{6e6e6e}De início, todos os jogadores deverão ir ao centro de licenças conseguir suas habilitações para veículos motorizados\ne depois devem seguir para a prefeitura para conseguir o seu primeiro emprego, de uma maneira bem simples. Caso não saiba\nonde fica localizado, basta digitar: /gps no chat.\nConseguir o seu primeiro emprego é de extrema importância, pois é aravés dele, que você conseguirá juntar seu primeiro dinheiro para adquirir suas coisas no servidor. \n\nNesse período que você estiver trabalhando em seu emprego, irá evoluindo de nível, após atingir o nível requisitdo pelos líderes, poderá participar de uma ORGANIZAÇÃO.\nNo servidor, possuímos organizações, criminosas, policiais e outros tipos variados.\nSaiba que os empregos são diferentes das organizações.\nEmpregos são adquiridos facilmente na prefeitura, organizações são diferentes.\nPara participar de uma é necessário cumprir os requisitos exigidos pelo líder e conhecer muito bem as regras do servidor e de cada organização.\nEm nosso servidor não é obrigatório o uso de programas de comunicação para entrar em uma organização, essa exigência ficará a encargo de cada líder.\n\n{FFFFFF}Para qualquer dúvida relacionada ao servidor, dificuldade para se registrar no servidor ou fórum, dicas, compra de VIP e etc,\nentre em contato através dos nossos meios de comunicação(/sites).", "Entendi", "");
        return 1;
    }
	// Login Screen: Credits Button
	if (clickedid == GetLoginScreenTextdrawId(7))
	{
        new MEGAString[93], string[67];
        if (Player_GetAdminLevel(playerid) < HELPER)
        {
            format(string, sizeof(string), "Admin-Aviso: %s viu os créditos do servidor.", GetPlayerNameCustom(playerid));
            SendAdminMessage(COLOR_YELLOW, string, HELPER);
        }
        strcat(MEGAString, "{FFFFFF}»  RhaegarX: {696969}(Fundador/Scripter)\n");
        strcat(MEGAString, "{FFFFFF}»  Rick_M: {696969}(Beta Tester)\n");
        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Créditos do Servidor", MEGAString, "Fechar", "");
        return 1;
	}
	// Login Screen: Exit Button
	if (clickedid == GetLoginScreenTextdrawId(8))
	{
		SendClientMessage(playerid, COLOR_YELLOW, "[Servidor]: Você optou por sair do servidor.");
		KickPlayer(playerid);
        return 1;
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    #pragma unused listitem // need this directive, on account of YSI which shows warnings in case the parameter is not used.
    #pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    switch(dialogid)
    {
        // Auth
        case DIALOG_LOGIN:
        {
            if (!response) 
			{
				return ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Ajuda", "{FFFFFF}Bem Vindo Ao NewLife RPG!\n\n{0080ff}Dificuldade para logar em sua conta ? Siga os passos abaixo:\n{FFFFFF}Aviso 1: {6e6e6e}Confira se seu nick realmente está registrado no servidor.\n{FFFFFF}Aviso 2: {6e6e6e}Verifique sua conexão com a internet, talvez o lag possa estar atrapalhando a comunicação com nosso servidor.\n{FFFFFF}Aviso 3: {6e6e6e}Verifique se você está usando a tecla CAPS LOCK e se sua senha possui caracteres em maiúsculos.\n{FFFFFF}Aviso 4: {6e6e6e}Para fechar o jogo, feche esse menu no botão 'SAIR', ou digite no chat '/q'.", "Fechar", "");
			}
            if (response)
	        {
	            if (strlen(inputtext) < MIN_PASS_LEN || strlen(inputtext) > MAX_PASS_LEN)
	            {
                    new string[52];
                    format(string, sizeof(string), "[AVISO]: A senha deve conter de %d a %d caracteres.", MIN_PASS_LEN, MAX_PASS_LEN);
                    SendClientMessage(playerid, COLOR_INVALID, string);
	                return ShowLoginDialog(playerid);
	            }

                // BcryptInline cannot access the parameters of the calling function directly, only the variables of the function body, so we need to create a copy of the inputtext
                new inputCopy[MAX_PASS_LEN];
                strcopy(inputCopy, inputtext, MAX_PASS_LEN);
                inline const OnPasswordRetrivedFromDB()
                {
                    new string[256];
                    if(cache_num_rows() > 0)
                    {
                        new password_hash[BCRYPT_HASH_LENGTH];
                        cache_get_value_name(0, PLAYER_FIELD_PASSWORD, password_hash, BCRYPT_HASH_LENGTH);

                        inline const OnPassswordVerify(bool:same)
                        {
                            if(same) 
                            {
                                OnPlayerLogin(playerid);
                            } 
                            else 
                            {
                                loginAttempts[playerid]++;
                                if (loginAttempts[playerid] > 5)
                                {
                                    SendClientMessage(playerid, COLOR_INVALID, "Você errou sua senha várias vezes, por isso foi kickado do servidor!");
                                    KickPlayer(playerid);
                                }
                                else
                                {
                                    format(string, sizeof(string), "[%s AVISO]: Senha incorreta, você já tentou [%d/5].", SERVER_TAG, loginAttempts[playerid]);
                                    SendClientMessage(playerid, COLOR_INVALID, string);
                                    format(string, sizeof(string), "[%s AVISO]: Se você errar além do limite, será kickado!", SERVER_TAG);
                                    SendClientMessage(playerid, COLOR_INVALID, string);
                                    ShowLoginDialog(playerid);
                                }
                            } 
                        }
                        // Compare hashed password with typed password by player
                        BCrypt_CheckInline(inputCopy, password_hash, using inline OnPassswordVerify);
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_INVALID, "[AVISO]: Falha ao realizar login, tente novamente.");
                        ShowLoginDialog(playerid);
                    }
                }
                // Get the hashed password from db
                MySQL_TQueryInline(Database_GetConnection(), using inline OnPasswordRetrivedFromDB, "SELECT %s FROM %s WHERE %s = '%e' LIMIT 1", PLAYER_FIELD_PASSWORD, PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, GetPlayerNameCustom(playerid));
	        }
        }
        case DIALOG_REGISTER:
        {
            if (!response) return SendClientMessage(playerid, COLOR_YELLOW, "Ok, Caso queira registrar-se posteriormente, clique em 'Fazer Login' novamente!");
            if (response)
            {
                if (strlen(inputtext) < MIN_PASS_LEN || strlen(inputtext) > MAX_PASS_LEN)
				{
                    new string[52];
                    format(string, sizeof(string), "[AVISO]: A senha deve conter de %d a %d caracteres.", MIN_PASS_LEN, MAX_PASS_LEN);
                    SendClientMessage(playerid, COLOR_INVALID, string);
	                return ShowRegisterDialog(playerid);
				}

                inline const OnPassswordHash(string:hash[])
                {
                    InsertPlayerInDataBase(playerid, hash);
                }
                BCrypt_HashInline(inputtext, BCRYPT_COST, using inline OnPassswordHash);
            }
        }
        // Admin
        case DIALOG_AUTH_ADMIN:
		{
			if (!response)
			{
				SendClientMessage(playerid, COLOR_LIGHTRED, "Você não informou a senha da administração e foi kickado!");
				KickPlayer(playerid);
				return 1;
			}
			if (response)
			{
				if (!strlen(inputtext))
	            {
					new admPassDialog[300], roleName[MAX_ADMIN_ROLE_STRING];
                    GetAdminRoleName(Player_GetAdminLevel(playerid), roleName);
					format(admPassDialog, sizeof(admPassDialog), "{FFFFFF}Conta: {0080ff}%s\n{FFFFFF}Você logou com Admin ({0080ff}%s{FFFFFF})\n\n{FFFFFF}Você precisa autenticar a senha de segurança para poder\n{FFFFFF}logar em sua conta!\n\n{ff6347}OBS: {FFFFFF}Você só tem uma tentativa ou será desconectado do servidor.\n\n\n{6e6e6e}Insira abaixo a senha da administração:", GetPlayerNameCustom(playerid), roleName);
					ShowPlayerDialog(playerid, DIALOG_AUTH_ADMIN, DIALOG_STYLE_PASSWORD, "Proteção de Conta", admPassDialog, "Validar", "");
					return SendClientMessage(playerid, COLOR_INVALID, "Você precisa autenticar a sua administração.");
				}
				if (strcmp(inputtext, SERVER_ADMIN_PASS) == 0)
				{
					if (Player_GetAdminLevel(playerid) >= HELPER_OWNER)
					{
						ShowPlayerDialog(playerid, DIALOG_ADMIN_HIDE, DIALOG_STYLE_MSGBOX, "Menu Admin Dono", "Escolha qual modo deseja ficar.", "Oculto", "Exibido");
					}
					return SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você autenticou o seu nível de administrador com sucesso.");
				}
				else
				{
					new string[126];
					format(string, sizeof(string), "[AVISO]: %s errou a senha da administração e foi kickado, pode ser outra pessoa logando na conta dele.", GetPlayerNameCustom(playerid));
					SendAdminMessage(COLOR_LIGHTRED, string, HELPER);
					SendClientMessage(playerid, COLOR_LIGHTRED, "Você errou a senha da administração e foi kickado.");
					KickPlayer(playerid);
					return 1;
				}
			}
		}
        case DIALOG_ADMIN_HIDE:
        {
            if (!response)
            {
                Admin_SetHideStatus(playerid, false);
                SetPlayerToTeamColor(playerid);
                return SendClientMessage(playerid, COLOR_LIGHTRED, "INFO: {AFAFAF}Você está no modo exibido, todos poderão ver você no /admins.");
            }
            if (response)
            {
                Admin_SetHideStatus(playerid, true);
                SetPlayerToTeamColor(playerid);
                return SendClientMessage(playerid, COLOR_LIGHTRED, "INFO: {AFAFAF}Você está no modo oculto, ninguém verá você no /admins.");
            }
        }
    }
    return 1;
}

function:OnPlayerLogin(playerid) 
{
    if (gskickPlayerTimer[playerid] != INVALID_VALUE) 
    {
        KillTimer(gskickPlayerTimer[playerid]);
        gskickPlayerTimer[playerid] = INVALID_VALUE;
    }
    
    if (Player_GetAdminLevel(playerid) > OWNER)
	{
		SendClientMessage(playerid, COLOR_ADMIN, "Nível de Administração Inválido!"); 
		KickPlayer(playerid);
        return 1;
    }

    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    recentlyLogged[playerid] = false;
    isRegistered[playerid] = true;
    
    ClearChatBox(playerid, 15);
	StopAudioStreamForPlayer(playerid);
	TogglePlayerSpectating(playerid, false);
    CancelSelectTextDraw(playerid);
    SetSpawnInfo(playerid, -1, Player_GetSkin(playerid), SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
    
    Player_SetLoggedStatus(playerid, true);
	HideLoginScreen(playerid);
    
    CallLocalFunction("FirstSpawnOnLogin", "i", playerid);
    
    SpawnPlayer(playerid);
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
