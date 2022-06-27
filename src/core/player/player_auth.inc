#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static loginAttempts[MAX_PLAYERS],
       bool:recentlyLogged[MAX_PLAYERS],
       bool:isRegistered[MAX_PLAYERS];

static Timer:timerToKickPlayer[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock IsPlayerLogged(playerid)
{
    if (PlayerData_GetIsLogged(playerid))
    {
        SetPlayerInterior(playerid, 0);
        SetCameraBehindPlayer(playerid);
        SetSpawnInfo(playerid, -1, (PlayerData_GetGender(playerid) == 1 ? DEFAULT_SKIN_MALE : DEFAULT_SKIN_FEMALE), SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);
    }
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
timer OnLoginTimeout[60000](playerid)
{
    if (Timer_IsRunning(timerToKickPlayer[playerid])) stop timerToKickPlayer[playerid];
    ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Fazer Login ", "{FFFFFF}Você foi kickado automaticamente por ficar\nmuito tempo no processo de login sem realizar tentativas válidas.\nPor favor, logue novamente!.", "Okay", "");
    DelayedKick(playerid);
    return 1;
}

static stock Player_ClearInfoVars(playerid) 
{
    PlayerData_ResetGeneralInfo(playerid);
    PlayerData_ResetAppearenceInfo(playerid);
    PlayerData_ResetMoneyInfo(playerid);
    PlayerData_ResetScoreInfo(playerid);

    // Temporary Vars
    loginAttempts[playerid] = 0;
    recentlyLogged[playerid] = true;
    isRegistered[playerid] = false;
    PlayerData_SetIsUsingAndroid(playerid, false);
    return 1;
}

static stock InsertPlayerInDataBase(playerid, const password[]) 
{
    inline const OnPlayerRegister()
    {
        PlayerData_SetID(playerid, cache_insert_id());
        OnPlayerLogin(playerid);
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerRegister, "INSERT INTO %s (%s, %s) VALUES ('%s', '%s')", PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, PLAYER_FIELD_PASSWORD, Player_GetName(playerid), password);
    return 1;
}

static stock ShowLoginDialog(playerid)
{
    static string[256];
    SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta está registrada, digite sua senha para logar!");
    format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
    return 1;
}

static stock ShowRegisterDialog(playerid)
{
    static string[256];
    SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta não está registrada, digite uma senha para se registrar.");
    format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}Não Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, Player_GetName(playerid));
    ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Cancelar");
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    new race_check = Database_IncrementRaceCheck(playerid);

    // Reset Player Data
    Player_ClearInfoVars(playerid);

    // Textdraws
    ShowLoadingScreen(playerid);
    SetPlayerColor(playerid, COLOR_GRAD2);

    inline const OnPlayerDataLoaded()
    {
        if (race_check != Database_GetRaceCheck(playerid)) return Kick(playerid);
        if(cache_num_rows() > 0)
        {
            // General Info
            new id, admin, job, org, org_role, tutorial, last_login_date, last_login_hour, last_connected_time, Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a, interior, vw;
            cache_get_value_name_int(0, PLAYER_FIELD_ID, id);
            cache_get_value_name_int(0, PLAYER_FIELD_ADMIN, admin);
            cache_get_value_name_int(0, PLAYER_FIELD_JOB, job);
            cache_get_value_name_int(0, PLAYER_FIELD_ORG, org);
            cache_get_value_name_int(0, PLAYER_FIELD_ORG_ROLE, org_role);
            cache_get_value_name_int(0, PLAYER_FIELD_TUTORIAL, tutorial);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_LOGIN_DATE, last_login_date);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_LOGIN_HOUR, last_login_hour);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_CONNECTED_TIME, last_connected_time);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSX, pos_x);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSY, pos_y);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSZ, pos_z);
            cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSA, pos_a);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_INTERIOR, interior);
            cache_get_value_name_int(0, PLAYER_FIELD_LAST_VW, vw);

            PlayerData_SetID(playerid, id);
            PlayerData_SetAdmin(playerid, admin, false);
            PlayerData_SetJob(playerid, job);
            PlayerData_SetOrg(playerid, org, org_role);
            PlayerData_SetTutorial(playerid, (tutorial == 0 ? false : true));
            PlayerData_SetLastLoginDate(playerid, last_login_date);
            PlayerData_SetLastLoginHour(playerid, last_login_hour);
            PlayerData_SetLastConnectedTime(playerid, last_connected_time);
            PlayerData_SetLastPosition(playerid, pos_x, pos_y, pos_z, pos_a, interior, vw);

            // Appearence
            new gender, fight_style, skin, old_skin;
            cache_get_value_name_int(0, PLAYER_FIELD_GENDER, gender);
            cache_get_value_name_int(0, PLAYER_FIELD_FIGHT_STYLE, fight_style);
            cache_get_value_name_int(0, PLAYER_FIELD_SKIN, skin);
            cache_get_value_name_int(0, PLAYER_FIELD_OLDSKIN, old_skin);

            PlayerData_SetGender(playerid, gender);
            PlayerData_SetFightStyle(playerid, fight_style);
            PlayerData_SetSkin(playerid, skin);
            PlayerData_SetOldSkin(playerid, old_skin);

            // Money Info
            new money, bank_status, bank_money, coins;
            cache_get_value_name_int(0, PLAYER_FIELD_MONEY, money);
            cache_get_value_name_int(0, PLAYER_FIELD_BANK_ACCOUNT, bank_status);
            cache_get_value_name_int(0, PLAYER_FIELD_BANK_MONEY, bank_money);
            cache_get_value_name_int(0, PLAYER_FIELD_COINS, coins);

            PlayerData_SetMoney(playerid, money);
            PlayerData_SetBankStatus(playerid, bank_status == 0 ? false : true);
            PlayerData_SetBankMoney(playerid, bank_money);
            PlayerData_SetCoins(playerid, coins);

            // Score Info
            new level, experience, deaths, kills, wanted_level;
            cache_get_value_name_int(0, PLAYER_FIELD_LEVEL, level);
            cache_get_value_name_int(0, PLAYER_FIELD_EXP, experience);
            cache_get_value_name_int(0, PLAYER_FIELD_DEATHS, deaths);
            cache_get_value_name_int(0, PLAYER_FIELD_KILLS, kills);
            cache_get_value_name_int(0, PLAYER_FIELD_WANTED_LEVEL, wanted_level);

            PlayerData_SetLevel(playerid, level);
            PlayerData_SetExperience(playerid, experience);
            PlayerData_SetDeaths(playerid, deaths);
            PlayerData_SetKills(playerid, kills);
            PlayerData_SetWantedLevel(playerid, wanted_level);
            
            isRegistered[playerid] = true;

            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
            SendClientMessage(playerid, COLOR_SOFTGREY, "* Dados Carregados com sucesso, pressione em 'Fazer Login'.");
        }
        else
        {
            isRegistered[playerid] = false;
        }
        if (Timer_IsRunning(timerToKickPlayer[playerid])) stop timerToKickPlayer[playerid];
        timerToKickPlayer[playerid] = defer OnLoginTimeout(playerid);
        InterpolateCameraPos(playerid, 1205.1385, -1022.0357, 98.2310, 1323.6675, -920.1975, 92.3793, CAMERA_SPEED, CAMERA_MOVE);
        InterpolateCameraLookAt(playerid, 1205.7915, -1021.2730, 98.0759, 1324.2585, -919.3865, 92.3142, CAMERA_SPEED, CAMERA_MOVE);

        HideLoadingScreen(playerid);
        ShowLoginScreen(playerid);

        SelectTextDraw(playerid, COLOR_ORANGE);
    }
	PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/ocpam5bletkz3j8/intro.mp3?dl=1");
    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
    SendClientMessage(playerid, COLOR_SOFTGREY, "* Aguarde enquanto carregamos os seus dados...");
    // Verify if player exists in database
    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerDataLoaded, "SELECT * FROM %s WHERE %s = '%e'", PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, Player_GetName(playerid));
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    Database_IncrementRaceCheck(playerid);
    PlayerData_SetIsLogged(playerid, false);
    
    new string[150], Float:PacketLoss;
    switch (reason)
    {
        case 0: format(string, sizeof(string), "%s saiu do servidor por erro de conexão ou crash (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 1: format(string, sizeof(string), "%s saiu por vontade própria (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 2: format(string, sizeof(string), "%s saiu do servidor por ter sido kickado ou banido (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
	}
    SendMessageInRange(100.0, playerid, string, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE);
    
    CallLocalFunction("BeforeSaveOnDisconnect", "i", playerid);
    Database_SaveGeneralInfo(playerid);
    Database_SaveMoneyInfo(playerid);
    Database_SaveScoreInfo(playerid);
    return 1;
}

hook OnPlayerRequestClass(playerid, classid)
{
    if (IsPlayerNPC(playerid))
	{
		return 1;
	}

    if (recentlyLogged[playerid]) 
	{
        TogglePlayerSpectating(playerid, true);
        InterpolateCameraPos(playerid, 1205.1385, -1022.0357, 98.2310, 1323.6675, -920.1975, 92.3793, CAMERA_SPEED, CAMERA_MOVE);
		InterpolateCameraLookAt(playerid, 1205.7915, -1021.2730, 98.0759, 1324.2585, -919.3865, 92.3142, CAMERA_SPEED, CAMERA_MOVE);
        if (PlayerData_GetIsUsingAndroid(playerid))
        {
            HideLoginScreen(playerid);
            ShowPlayerDialog(playerid, DIALOG_CHECK_ANDROID, DIALOG_STYLE_MSGBOX, "Checagem de Plataforma - Servidor", "{FFFFFF}Olá jogador, detectamos uma mudança de plataforma e precisamos colher algumas informações.\nVocê deve informar em qual plataforma você está se conectando ao servidor (Android ou PC) corretamente.\n\n{9fa19e}Se você estiver se conectando pelo Android (Celular), Selecine '{03a9fd}Android{9fa19e}'.\n{9fa19e}Se você estiver se conectando pelo Computador, Selecione '{00b100}PC{9fa19e}'.\n\n{f2664d}Importante: {FFFFFF}Caso marque a opção 'Android' algumas coisas do servidor funcionarão de uma forma diferente,\npor questões de compatibilidade com a plataforma.\n\nSelecione abaixo corretamente, por qual meio você está acessando o servidor:", "Android", "PC");
        }
    }
    else
    {
        IsPlayerLogged(playerid);
    }
    return 0;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    // Login Screen: Login Button
	if (clickedid == LoginTextDraw_GetByIndex(5))
	{
		if (isRegistered[playerid])
        {
            ShowLoginDialog(playerid);
        }
        else
        {
            ShowRegisterDialog(playerid);
        }
	}
	// Login Screen: Info Button
	else if (clickedid == LoginTextDraw_GetByIndex(6))
	{
		ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Informações Gerais", "{FFFFFF}O NewLife é um servidor RPG, que tem como principal objetivo a simulação da vida real.\n\nNele haverá guerra entre facções criminosas, operacções policiais, roubos, sequestro, assaltos, emboscadas dentre outras coisas.\n\nNo servidor também é possível adquirir propriedade privada, como: empresas, casas, mansões, veículo próprio, celular, itens e etc.\n\n{6e6e6e}De início, todos os jogadores deverão ir ao centro de licenças conseguir suas habilitações para veículos motorizados\ne depois devem seguir para a prefeitura para conseguir o seu primeiro emprego, de uma maneira bem simples. Caso não saiba\nonde fica localizado, basta digitar: /gps no chat.\nConseguir o seu primeiro emprego é de extrema importância, pois é aravés dele, que você conseguirá juntar seu primeiro dinheiro para adquirir suas coisas no servidor. \n\nNesse período que você estiver trabalhando em seu emprego, irá evoluindo de nível, após atingir o nível requisitdo pelos líderes, poderá participar de uma ORGANIZAÇÃO.\nNo servidor, possuímos organizações, criminosas, policiais e outros tipos variados.\nSaiba que os empregos são diferentes das organizações.\nEmpregos são adquiridos facilmente na prefeitura, organizações são diferentes.\nPara participar de uma é necessário cumprir os requisitos exigidos pelo líder e conhecer muito bem as regras do servidor e de cada organização.\nEm nosso servidor não é obrigatório o uso de programas de comunicação para entrar em uma organização, essa exigência ficará a encargo de cada líder.\n\n{FFFFFF}Para qualquer dúvida relacionada ao servidor, dificuldade para se registrar no servidor ou fórum, dicas, compra de VIP e etc,\nentre em contato através dos nossos meios de comunicação(/sites).", "Entendi", "");
	}
	// Login Screen: Credits Button
	else if (clickedid == LoginTextDraw_GetByIndex(7))
	{
        new MEGAString[93], string[67];
        if (PlayerData_GetAdmin(playerid) < HELPER)
        {
            format(string, sizeof(string), "Admin-Aviso: %s viu os créditos do servidor.", Player_GetName(playerid));
            MensagemAdmin(COLOR_YELLOW, string, HELPER);
        }
        strcat(MEGAString, "{FFFFFF}»  RhaegarX: {696969}(Fundador/Scripter)\n");
        strcat(MEGAString, "{FFFFFF}»  Rick_M: {696969}(Beta Tester)\n");
        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Créditos do Servidor", MEGAString, "Fechar", "");
	}
	// Login Screen: Exit Button
	else if (clickedid == LoginTextDraw_GetByIndex(8))
	{
		SendClientMessage(playerid, COLOR_YELLOW, "[Servidor]: Você optou por sair do servidor.");
		DelayedKick(playerid);
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        // Auth
        case DIALOG_CHECK_ANDROID:
		{
			if (!response) 
            {
                PlayerData_SetIsUsingAndroid(playerid, false);
                return ShowLoginDialog(playerid);
            }
            if (response) 
            {
                PlayerData_SetIsUsingAndroid(playerid, true);
                return ShowRegisterDialog(playerid);                
            }
        }
        case DIALOG_LOGIN:
        {
            if (!response) 
			{
				return ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Ajuda", "{FFFFFF}Bem Vindo Ao NewLife RPG!\n\n{0080ff}Dificuldade para logar em sua conta ? Siga os passos abaixo:\n{FFFFFF}Aviso 1: {6e6e6e}Confira se seu nick realmente está registrado no servidor.\n{FFFFFF}Aviso 2: {6e6e6e}Verifique sua conexão com a internet, talvez o lag possa estar atrapalhando a comunicação com nosso servidor.\n{FFFFFF}Aviso 3: {6e6e6e}Verifique se você está usando a tecla CAPS LOCK e se sua senha possui caracteres em maiúsculos.\n{FFFFFF}Aviso 4: {6e6e6e}Para fechar o jogo, feche esse menu no botão 'SAIR', ou digite no chat '/q'.", "Fechar", "");
			}
            if (response)
	        {
	            if (strlen(inputtext) < 8 || strlen(inputtext) > MAX_PASS_LEN)
	            {
                    SendClientMessage(playerid, COLOR_INVALID, "[AVISO]: A senha deve conter de 8 a 15 caracteres.");
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
                                    DelayedKick(playerid);
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
                MySQL_TQueryInline(Database_GetConnection(), using inline OnPasswordRetrivedFromDB, "SELECT %s FROM %s WHERE %s = '%e' LIMIT 1", PLAYER_FIELD_PASSWORD, PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, Player_GetName(playerid));
	        }
        }
        case DIALOG_REGISTER:
        {
            if (!response) return SendClientMessage(playerid, COLOR_YELLOW, "Ok, Caso queira registrar-se posteriormente, clique em 'Fazer Login' novamente!");
            if (response)
            {
                if (!strlen(inputtext) || strlen(inputtext) < 8 || strlen(inputtext) > MAX_PASS_LEN)
				{
                    SendClientMessage(playerid, COLOR_INVALID, "[AVISO]: A senha deve conter de 8 a 15 caracteres.");
	                return ShowRegisterDialog(playerid);
				}

                inline const OnPassswordHash(string:hash[])
                {
                    InsertPlayerInDataBase(playerid, hash);
                }
                BCrypt_HashInline(inputtext, BCRYPT_COST, using inline OnPassswordHash);
            }
        }
    }
    return 1;
}

hook OnAndroidCheck(playerid, bool:isDisgustingThiefToBeBanned)
{
	if (isDisgustingThiefToBeBanned) PlayerData_SetIsUsingAndroid(playerid, true);
}

function:OnPlayerLogin(playerid) 
{
    recentlyLogged[playerid] = false;
    isRegistered[playerid] = true;
    if (Timer_IsRunning(timerToKickPlayer[playerid])) stop timerToKickPlayer[playerid];

    if (PlayerData_GetAdmin(playerid) > OWNER)
	{
		SendClientMessage(playerid, COLOR_ADMIN, "Nível de Administração Inválido!"); 
		DelayedKick(playerid);
        return 1;
    }

    PlayerData_SetIsLogged(playerid, true);
    SetPlayerScore(playerid, PlayerData_GetLevel(playerid));
    SetPlayerWantedLevel(playerid, PlayerData_GetWantedLevel(playerid));
    Server_SetPlayerMoney(playerid, PlayerData_GetMoney(playerid));
    SetSpawnInfo(playerid, -1, PlayerData_GetSkin(playerid), SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
    switch(PlayerData_GetFightStyle(playerid))
    {
        case 0: SetPlayerFightingStyle(playerid, FIGHT_STYLE_NORMAL);
        case 1: SetPlayerFightingStyle(playerid, FIGHT_STYLE_BOXING);
        case 2: SetPlayerFightingStyle(playerid, FIGHT_STYLE_KUNGFU);
        case 3: SetPlayerFightingStyle(playerid, FIGHT_STYLE_KNEEHEAD);
        case 4: SetPlayerFightingStyle(playerid, FIGHT_STYLE_GRABKICK);
        case 5: SetPlayerFightingStyle(playerid, FIGHT_STYLE_ELBOW);
        default: SetPlayerFightingStyle(playerid, FIGHT_STYLE_NORMAL);
    }
    ClearChatBox(playerid, 15);
	StopAudioStreamForPlayer(playerid);
	HideLoginScreen(playerid);
    CancelSelectTextDraw(playerid);
	TogglePlayerSpectating(playerid, false);
    
    new string[150];
    if (!PlayerData_GetTutorial(playerid))
    {
        ShowGenderDialog(playerid);
    }
    else
    {
        SendClientMessage(playerid, COLOR_WHITE, "________________________________________________________________________________________________");
        format(string, sizeof(string), "* [Aviso]: Seja Bem Vindo(a): {FFFFFF}%s{33ccff}.", Player_GetName(playerid));
        SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "* [Aviso]: Para voltar na última posição de onde saiu pela última vez digite ({FFFFFF}/irposicao{33ccff})!");
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "* [Aviso]: Retire suas dúvidas usando ({FFFFFF}/relato{33ccff}) ou com o chat de dúvidas ({FFFFFF}/nchat{33ccff}).");
        if (PlayerData_GetAdmin(playerid) >= HELPER)
        {
            format(string, sizeof(string), "[{FFFFFF}ADMIN{33ccff}]: Você Logou Como Admin: [{FFFFFF}%s{33ccff}].", Admin_GetRole(PlayerData_GetAdmin(playerid)));
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
        }
		if (PlayerData_GetAdmin(playerid) >= HELPER && PlayerData_GetAdmin(playerid) < SUB_OWNER)
		{
			new adminName[35];
			format(adminName, sizeof(adminName), "~w~%s ~g~ON", Player_GetName(playerid));
			GameTextForAll(adminName, 5000, 1);
		}
        format(string, sizeof(string), "~w~Bem Vindo ~n~~y~%s", Player_GetName(playerid));
        GameTextForPlayer(playerid, string, 5000, 1);
        SpawnPlayer(playerid);
    }
    format(string, sizeof(string), (PlayerData_GetAdmin(playerid) < HELPER_OWNER ? "[Conexão]: %s(ID: %d) se conectou, Level: %d | IP: [%s]!" : "[Conexão]: %s(ID: %d) se conectou, Level: %d | IP: [N/A]!"), Player_GetName(playerid), playerid, PlayerData_GetLevel(playerid), Player_GetIP(playerid));
 	MensagemAdmin(COLOR_SKIN, string, HELPER);
    return 1;
}
