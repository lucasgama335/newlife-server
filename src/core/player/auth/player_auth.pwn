#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static loginAttempts[MAX_PLAYERS],
       bool:isLogged[MAX_PLAYERS],
       bool:recentlyLogged[MAX_PLAYERS],
       bool:isRegistered[MAX_PLAYERS],
       bool:isUsingAndroid[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock IsPlayerLogged(playerid)
{
    if (isLogged[playerid])
    {
        SetPlayerInterior(playerid, 0);
        SetCameraBehindPlayer(playerid);
        SetSpawnInfo(playerid, -1, DEFAULT_SKIN, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);
    }
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
    isUsingAndroid[playerid] = false;
    return 1;
}

static stock InsertPlayerInDataBase(playerid, const password[]) 
{
    inline const OnPlayerRegister()
    {
        PlayerData_SetID(playerid, cache_insert_id());
        isRegistered[playerid] = true;
        OnPlayerLogin(playerid);
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerRegister, "INSERT INTO %s (%s, %s) VALUES ('%s', '%s')", PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, PLAYER_FIELD_PASSWORD, Player_GetName(playerid), password);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
public OnPlayerConnect(playerid)
{
    Database_IncrementRaceCheck(playerid);

    // Reset Player Data
    Player_ClearInfoVars(playerid);

    // Textdraws
    ShowLoadingScreen(playerid);

    new race_check = Database_GetRaceCheck(playerid);
    inline const OnPlayerDataLoaded()
    {
        if (race_check != Database_GetRaceCheck(playerid)) return Kick(playerid);
        if(cache_num_rows() > 0)
        {
            // General Info
            new id, admin, last_login_date, last_login_hour, last_connected_time, Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a, interior, vw;
            cache_get_value_name_int(0, PLAYER_FIELD_ID, id);
            cache_get_value_name_int(0, PLAYER_FIELD_ADMIN, admin);
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
            PlayerData_SetAdmin(playerid, admin);
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
            new level, deaths, kills, wanted_level;
            cache_get_value_name_int(0, PLAYER_FIELD_LEVEL, level);
            cache_get_value_name_int(0, PLAYER_FIELD_DEATHS, deaths);
            cache_get_value_name_int(0, PLAYER_FIELD_KILLS, kills);
            cache_get_value_name_int(0, PLAYER_FIELD_WANTED_LEVEL, wanted_level);

            PlayerData_SetLevel(playerid, level);
            PlayerData_SetDeaths(playerid, deaths);
            PlayerData_SetKills(playerid, kills);
            PlayerData_SetWantedLevel(playerid, wanted_level);
            
            isRegistered[playerid] = true;
        }
        else
        {
            isRegistered[playerid] = false;
        }

        ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
        SendClientMessage(playerid, COLOR_SOFTGREY, "* Dados Carregados com sucesso, pressione em 'Fazer Login'!");

        InterpolateCameraPos(playerid, 1205.1385, -1022.0357, 98.2310, 1323.6675, -920.1975, 92.3793, CAMERA_SPEED, CAMERA_MOVE);
        InterpolateCameraLookAt(playerid, 1205.7915, -1021.2730, 98.0759, 1324.2585, -919.3865, 92.3142, CAMERA_SPEED, CAMERA_MOVE);

        HideLoadingScreen(playerid);
        ShowLoginScreen(playerid);

        SelectTextDraw(playerid, COLOR_ORANGE);
    }
    // Verify if player exists in database
    MySQL_TQueryInline(Database_GetConnection(), using inline OnPlayerDataLoaded, "SELECT * FROM %s WHERE %s = '%s'", PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, Player_GetName(playerid));
    return 1;
}

public OnPlayerUpdate(playerid)
{
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
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
        if (isUsingAndroid[playerid])
        {
            HideLoginScreen(playerid);
            ShowPlayerDialog(playerid, DIALOG_CHECK_ANDROID, DIALOG_STYLE_MSGBOX, "Checagem de Plataforma - Servidor", "{FFFFFF}Ol� jogador, detectamos uma mudan�a de plataforma e precisamos colher algumas informa��es.\nVoc� deve informar em qual plataforma voc� est� se conectando ao servidor (Android ou PC) corretamente.\n\n{9fa19e}Se voc� estiver se conectando pelo Android (Celular), Selecine '{03a9fd}Android{9fa19e}'.\n{9fa19e}Se voc� estiver se conectando pelo Computador, Selecione '{00b100}PC{9fa19e}'.\n\n{f2664d}Importante: {FFFFFF}Caso marque a op��o 'Android' algumas coisas do servidor funcionar�o de uma forma diferente,\npor quest�es de compatibilidade com a plataforma.\n\nSelecione abaixo corretamente, por qual meio voc� est� acessando o servidor:", "Android", "PC");
        }
    }
    else
    {
        IsPlayerLogged(playerid);
    }
    return 0;
}

public OnPlayerRequestSpawn(playerid)
{
	return IsPlayerLogged(playerid);
}

public OnPlayerDisconnect(playerid, reason)
{
    Database_IncrementRaceCheck(playerid);
    isLogged[playerid] = false;
    
    new string[150], Float:PacketLoss;
    switch (reason)
    {
        case 0: format(string, sizeof(string), "%s saiu do servidor por erro de conex�o ou crash (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 1: format(string, sizeof(string), "%s saiu por vontade pr�pria (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 2: format(string, sizeof(string), "%s saiu do servidor por ter sido kickado ou banido (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
	}
    SendMessageInRange(100.0, playerid, string, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE);
    return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    // TELA DE LOGIN: Bot�o de Login
	if (clickedid == LoginTextDraw_GetByIndex(5))
	{
        new string[256];
		if (isRegistered[playerid])
        {
            SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta est� registrada, digite sua senha para logar!");
            format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
            ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
        }
        else
        {
            SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta n�o est� registrada, digite uma senha para se registrar.");
            format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}N�o Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, Player_GetName(playerid));
            ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Cancelar");
        }
	}
	// TELA DE LOGIN: Bot�o de Informa��es
	else if (clickedid == LoginTextDraw_GetByIndex(6))
	{
		ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Informa��es Gerais", "{FFFFFF}O NewLife � um servidor RPG, que tem como principal objetivo a simula��o da vida real.\n\nNele haver� guerra entre fac��es criminosas, opera��es policiais, roubos, sequestro, assaltos, emboscadas dentre outras coisas.\n\nNo servidor tamb�m � poss�vel adquirir propriedade privada, como: empresas, casas, mans�es, ve�culo pr�prio, celular, itens e etc.\n\n{6e6e6e}De in�cio, todos os jogadores dever�o ir ao centro de licen�as conseguir suas habilita��es para ve�culos motorizados\ne depois devem seguir para a prefeitura para conseguir o seu primeiro emprego, de uma maneira bem simples. Caso n�o saiba\nonde fica localizado, basta digitar: /gps no chat.\nConseguir o seu primeiro emprego � de extrema import�ncia, pois � atrav�s dele, que voc� conseguir� juntar seu primeiro dinheiro para adquirir suas coisas no servidor. \n\nNesse per�odo que voc� estiver trabalhando em seu emprego, ir� evoluindo de n�vel, ap�s atingir o n�vel requisitdo pelos l�deres, poder� participar de uma ORGANIZA��O.\nNo servidor, possu�mos organiza��es, criminosas, policiais e outros tipos variados.\nSaiba que os empregos s�o diferentes das organiza��es.\nEmpregos s�o adquiridos facilmente na prefeitura, organiza��es s�o diferentes.\nPara participar de uma � necess�rio cumprir os requisitos exigidos pelo l�der e conhecer muito bem as regras do servidor e de cada organiza��o.\nEm nosso servidor n�o � obrigat�rio o uso de programas de comunica��o para entrar em uma organiza��o, essa exig�ncia ficar� a encargo de cada l�der.\n\n{FFFFFF}Para qualquer d�vida relacionada ao servidor, dificuldade para se registrar no servidor ou f�rum, dicas, compra de VIP e etc,\nentre em contato atrav�s dos nossos meios de comunica��o(/sites).", "Entendi", "");
	}
	// TELA DE LOGIN: Bot�o de Cr�ditos
	else if (clickedid == LoginTextDraw_GetByIndex(7))
	{
        return SendClientMessage(playerid, -1, "Voc� clicou nos cr�ditos.");
		// return ReCommand:creditos(playerid);
	}
	// TELA DE LOGIN: Bot�o de Sair
	else if (clickedid == LoginTextDraw_GetByIndex(8))
	{
		SendClientMessage(playerid, COLOR_YELLOW, "[Servidor]: Voc� optou por sair do servidor.");
		DelayedKick(playerid);
	}
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
    {
        case DIALOG_CHECK_ANDROID:
		{
            new string[256];
			if (!response) 
            {
                isUsingAndroid[playerid] = false;
                SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta est� registrada, digite sua senha para logar!");
                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
                return ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
            }
            if (response) 
            {
                isUsingAndroid[playerid] = true;
                SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta n�o est� registrada, digite uma senha para se registrar.");
                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}N�o Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, Player_GetName(playerid));
                return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Cancelar");
            }
        }
        case DIALOG_LOGIN:
        {
            if (!response) 
			{
				return ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Ajuda", "{FFFFFF}Bem Vindo Ao NewLife RPG!\n\n{0080ff}Dificuldade para logar em sua conta ? Siga os passos abaixo:\n{FFFFFF}Aviso 1: {6e6e6e}Confira se seu nick realmente est� registrado no servidor.\n{FFFFFF}Aviso 2: {6e6e6e}Verifique sua conex�o com a internet, talvez o lag possa estar atrapalhando a comunica��o com nosso servidor.\n{FFFFFF}Aviso 3: {6e6e6e}Verifique se voc� est� usando a tecla CAPS LOCK e se sua senha possui caracteres em mai�sculos.\n{FFFFFF}Aviso 4: {6e6e6e}Para fechar o jogo, feche esse menu no bot�o 'SAIR', ou digite no chat '/q'.", "Fechar", "");
			}
            if (response)
	        {
	            if (strlen(inputtext) < 8 || strlen(inputtext) > MAX_PASS_LEN)
	            {
	                new string[256];
                    SendClientMessage(playerid, COLOR_INVALID, "[AVISO]: A senha deve conter de 8 a 15 caracteres.");
	                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
			        ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
			        return 1;
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
                                    SendClientMessage(playerid, COLOR_INVALID, "Voc� errou sua senha v�rias vezes, por isso foi kickado do servidor!");
                                    DelayedKick(playerid);
                                }
                                else
                                {
                                    format(string, sizeof(string), "[%s AVISO]: Senha incorreta, voc� j� tentou [%d/5].", SERVER_TAG, loginAttempts[playerid]);
                                    SendClientMessage(playerid, COLOR_INVALID, string);
                                    format(string, sizeof(string), "[%s AVISO]: Se voc� errar al�m do limite, ser� kickado!", SERVER_TAG);
                                    SendClientMessage(playerid, COLOR_INVALID, string);
                                    format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
                                    ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Sair");
                                }
                            } 
                        }
                        // Compare hashed password with typed password by player
                        BCrypt_CheckInline(inputCopy, password_hash, using inline OnPassswordVerify);
                    }
                    else
                    {
                        SendClientMessage(playerid, COLOR_INVALID, "[AVISO]: Falha ao realizar login, tente novamente.");
                        format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
                        ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Sair");
                    }
                }
                // Get the hashed password from db
                MySQL_TQueryInline(Database_GetConnection(), using inline OnPasswordRetrivedFromDB, "SELECT %s FROM %s WHERE %s = '%s' LIMIT 1", PLAYER_FIELD_PASSWORD, PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, Player_GetName(playerid));
	        }
        }
        case DIALOG_REGISTER:
        {
            if (!response) return SendClientMessage(playerid, COLOR_YELLOW, "Ok, Caso queira registrar-se posteriormente, clique em 'Fazer Login' novamente!");
            if (response)
            {
                if (!strlen(inputtext) || strlen(inputtext) < 8 || strlen(inputtext) > MAX_PASS_LEN)
				{
				    new string[256];
                    SendClientMessage(playerid, COLOR_INVALID, "[AVISO]: A senha deve conter de 8 a 15 caracteres.");
	                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}N�o Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, Player_GetName(playerid));
					return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Sair");
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

public OnAndroidCheck(playerid, bool:isDisgustingThiefToBeBanned)
{
	if (isDisgustingThiefToBeBanned)
	{
        isUsingAndroid[playerid] = true;
	}
}

function:OnPlayerLogin(playerid) 
{
    CancelSelectTextDraw(playerid);
	TogglePlayerSpectating(playerid, false);
    isLogged[playerid] = true;

    SetPlayerScore(playerid, PlayerData_GetLevel(playerid));
    SetPlayerWantedLevel(playerid, PlayerData_GetWantedLevel(playerid));
    Server_SetPlayerMoney(playerid, PlayerData_GetMoney(playerid));
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
    SetSpawnInfo(playerid, -1, PlayerData_GetSkin(playerid), SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
    HideLoginScreen(playerid);

    ClearChatBox(playerid, 15);
	StopAudioStreamForPlayer(playerid);
    SpawnPlayer(playerid);
    return 1;
}