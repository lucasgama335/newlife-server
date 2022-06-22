#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum pTemporaryInfo
{
    pLoginAttempts,
    bool:pLogged,
    bool:pRecentlyLogged,
    bool:pIsRegistered,
    bool:pIsAndroid
}
static Player_TemporaryInfo[MAX_PLAYERS][pTemporaryInfo];
static HashPassword[MAX_PLAYERS][BCRYPT_HASH_LENGTH];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock IsPlayerLogged(playerid)
{
    if (Player_TemporaryInfo[playerid][pLogged])
    {
        SetSpawnInfo(playerid, -1, DEFAULT_SKIN, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA, 0, 0, 0, 0, 0, 0);
        SpawnPlayer(playerid);
        SetPlayerInterior(playerid, 0);
        SetCameraBehindPlayer(playerid);
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
    Player_TemporaryInfo[playerid][pLoginAttempts] = 0;
    Player_TemporaryInfo[playerid][pRecentlyLogged] = true;
    Player_TemporaryInfo[playerid][pIsRegistered] = false;
    Player_TemporaryInfo[playerid][pIsAndroid] = false;
    format(HashPassword[playerid], BCRYPT_HASH_LENGTH, "\0");
    return 1;
}

static stock InsertPlayerInDataBase(playerid, const password[]) 
{
    new query_string[256];
    format(query_string, sizeof(query_string), "INSERT INTO %s (%s, %s) VALUES ('%s', '%s')", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_NAME,
    PLAYER_FIELD_PASSWORD,
    Player_GetName(playerid),
    password);
    mysql_tquery(Database_GetConnection(), query_string, "OnPlayerRegister", "i", playerid);
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

    // Verify if player exists in database
    new Query[65 + MAX_PLAYER_NAME + 1];
    SendClientMessage(playerid, -1, "Eae");
    mysql_format(Database_GetConnection(), Query, sizeof(Query), "SELECT * FROM %s WHERE %s = '%s'", 
    PLAYER_TABLE_NAME, PLAYER_FIELD_NAME, Player_GetName(playerid));
    mysql_tquery(Database_GetConnection(), Query, "OnPlayerDataLoaded", "id", playerid, Database_GetRaceCheck(playerid));
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

    if (Player_TemporaryInfo[playerid][pRecentlyLogged]) 
	{
        TogglePlayerSpectating(playerid, true);
        InterpolateCameraPos(playerid, 1205.1385, -1022.0357, 98.2310, 1323.6675, -920.1975, 92.3793, CAMERA_SPEED, CAMERA_MOVE);
		InterpolateCameraLookAt(playerid, 1205.7915, -1021.2730, 98.0759, 1324.2585, -919.3865, 92.3142, CAMERA_SPEED, CAMERA_MOVE);
        if (Player_TemporaryInfo[playerid][pIsAndroid])
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

public OnPlayerDisconnect(playerid, reason)
{
    Database_IncrementRaceCheck(playerid);
    Player_TemporaryInfo[playerid][pLogged] = false;
    
    new string[150], Float:PacketLoss;
    switch (reason)
    {
        case 0: format(string, sizeof(string), "%s saiu do servidor por erro de conexão ou crash (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 1: format(string, sizeof(string), "%s saiu por vontade própria (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
        case 2: format(string, sizeof(string), "%s saiu do servidor por ter sido kickado ou banido (ID: %d - Ping: %d - PL: %.01f).", Player_GetName(playerid), playerid, GetPlayerPing(playerid), PacketLoss);
	}
    return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    // TELA DE LOGIN: Botão de Login
	if (clickedid == LoginTextDraw_GetByIndex(5))
	{
        new string[256];
		if (Player_TemporaryInfo[playerid][pIsRegistered])
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
	// TELA DE LOGIN: Botão de Informações
	else if (clickedid == LoginTextDraw_GetByIndex(6))
	{
		ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Informações Gerais", "{FFFFFF}O NewLife é um servidor RPG, que tem como principal objetivo a simulação da vida real.\n\nNele haverá guerra entre facções criminosas, opera��es policiais, roubos, sequestro, assaltos, emboscadas dentre outras coisas.\n\nNo servidor tamb�m � poss�vel adquirir propriedade privada, como: empresas, casas, mans�es, ve�culo pr�prio, celular, itens e etc.\n\n{6e6e6e}De in�cio, todos os jogadores dever�o ir ao centro de licen�as conseguir suas habilita��es para ve�culos motorizados\ne depois devem seguir para a prefeitura para conseguir o seu primeiro emprego, de uma maneira bem simples. Caso n�o saiba\nonde fica localizado, basta digitar: /gps no chat.\nConseguir o seu primeiro emprego � de extrema import�ncia, pois � atrav�s dele, que voc� conseguir� juntar seu primeiro dinheiro para adquirir suas coisas no servidor. \n\nNesse per�odo que voc� estiver trabalhando em seu emprego, ir� evoluindo de n�vel, ap�s atingir o n�vel requisitdo pelos l�deres, poder� participar de uma ORGANIZA��O.\nNo servidor, possu�mos organiza��es, criminosas, policiais e outros tipos variados.\nSaiba que os empregos s�o diferentes das organiza��es.\nEmpregos s�o adquiridos facilmente na prefeitura, organiza��es s�o diferentes.\nPara participar de uma � necess�rio cumprir os requisitos exigidos pelo l�der e conhecer muito bem as regras do servidor e de cada organiza��o.\nEm nosso servidor n�o � obrigat�rio o uso de programas de comunica��o para entrar em uma organiza��o, essa exig�ncia ficar� a encargo de cada l�der.\n\n{FFFFFF}Para qualquer d�vida relacionada ao servidor, dificuldade para se registrar no servidor ou f�rum, dicas, compra de VIP e etc,\nentre em contato atrav�s dos nossos meios de comuni��o(/sites).", "Entendi", "");
	}
	// TELA DE LOGIN: Botão de Créditos
	else if (clickedid == LoginTextDraw_GetByIndex(7))
	{
        return SendClientMessage(playerid, -1, "Você clicou nos créditos.");
		// return ReCommand:creditos(playerid);
	}
	// TELA DE LOGIN: Botão de Sair
	else if (clickedid == LoginTextDraw_GetByIndex(8))
	{
		SendClientMessage(playerid, COLOR_YELLOW, "[Servidor]: Você optou por sair do servidor.");
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
                Player_TemporaryInfo[playerid][pIsAndroid] = false;
                SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta está registrada, digite sua senha para logar!");
                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
                return ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
            }
            if (response) 
            {
                Player_TemporaryInfo[playerid][pIsAndroid] = true;
                SendClientMessage(playerid, 0xffcc99FF, "[CONTA]: Sua conta não está registrada, digite uma senha para se registrar.");
                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}N�o Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, Player_GetName(playerid));
                return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Cancelar");
            }
        }
        case DIALOG_LOGIN:
        {
            if (!response) 
			{
				return ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,  "Ajuda", "{FFFFFF}Bem Vindo Ao NewLife RPG!\n\n{0080ff}Dificuldade para logar em sua conta ? Siga os passos abaixo:\n{FFFFFF}Aviso 1�: {6e6e6e}Confira se seu nick realmente est� registrado no servidor.\n{FFFFFF}Aviso 2�: {6e6e6e}Verifique sua conex�o com a internet, talvez o lag possa estar atrapalhando a comunica��o com nosso servidor.\n{FFFFFF}Aviso 3�: {6e6e6e}Verifique se voc� est� usando a tecla CAPS LOCK e se sua senha possui caracteres em mai�sculos.\n{FFFFFF}Aviso 4�: {6e6e6e}Para fechar o jogo, feche esse menu no bot�o 'SAIR', ou digite no chat '/q'.", "Fechar", "");
			}
            if (response)
	        {
	            if (!strlen(inputtext))
	            {
	                new string[256];
	                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
			        ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Ajuda");
			        return 1;
	            }
                bcrypt_verify(playerid, "OnPassswordVerify", inputtext, HashPassword[playerid]);
	            return 1;
	        }
        }
        case DIALOG_REGISTER:
        {
            if (!response) return SendClientMessage(playerid, COLOR_YELLOW, "Ok, Caso queira registrar-se posteriormente, clique em 'Fazer Login' novamente!");
            if (response)
            {
                if (!strlen(inputtext) || strlen(inputtext) < 8 || strlen(inputtext) > 30)
				{
				    new string[256];
	                format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {FF0000}N�o Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para registrar.", SERVER_NAME, Player_GetName(playerid));
					return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Fazer Cadastro", string, "Registrar", "Sair");
				}
                bcrypt_hash(0, "OnPassswordHash", inputtext, BCRYPT_COST);
            }
        }
    }
    return 1;
}

public OnAndroidCheck(playerid, bool:isDisgustingThiefToBeBanned)
{
	if (isDisgustingThiefToBeBanned)
	{
        Player_TemporaryInfo[playerid][pIsAndroid] = true;
	}
}

function:OnPlayerDataLoaded(playerid, race_check)
{
    /*	race condition check:
		player A connects -> SELECT query is fired -> this query takes very long
		while the query is still processing, player A with playerid 2 disconnects
		player B joins now with playerid 2 -> our laggy SELECT query is finally finished, but for the wrong player
		what do we do against it?
		we create a connection count for each playerid and increase it everytime the playerid connects or disconnects
		we also pass the current value of the connection count to our OnPlayerDataLoaded callback
		then we check if current connection count is the same as connection count we passed to the callback
		if yes, everything is okay, if not, we just kick the player
	*/
	if (race_check != Database_GetRaceCheck(playerid)) return Kick(playerid);

    if(cache_num_rows() > 0)
	{
        new int_result;

        // Temporary Password Hash to Compare in Login
        cache_get_value_name(0, PLAYER_FIELD_PASSWORD, HashPassword[playerid], BCRYPT_HASH_LENGTH);

        // General Info
        cache_get_value_name_int(0, PLAYER_FIELD_ID, int_result);
        PlayerData_SetID(playerid, int_result);

        cache_get_value_name_int(0, PLAYER_FIELD_ADMIN, int_result);
        PlayerData_SetAdmin(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_LAST_LOGIN_DATE, int_result);
        PlayerData_SetLastLoginDate(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_LAST_LOGIN_HOUR, int_result);
        PlayerData_SetLastLoginHour(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_LAST_CONNECTED_TIME, int_result);
        PlayerData_SetLastConnectedTime(playerid, int_result);
        
        // Position
        new Float:pos_x, Float:pos_y, Float:pos_z, Float:pos_a, interior, vw;
        cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSX, pos_x);
        cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSY, pos_y);
        cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSZ, pos_z);
        cache_get_value_name_float(0, PLAYER_FIELD_LAST_POSA, pos_a);
        cache_get_value_name_int(0, PLAYER_FIELD_LAST_INTERIOR, interior);
        cache_get_value_name_int(0, PLAYER_FIELD_LAST_VW, vw);
        PlayerData_SetLastPosition(playerid, pos_x, pos_y, pos_z, pos_a, interior, vw);
        

        // Appearence
        cache_get_value_name_int(0, PLAYER_FIELD_GENDER, int_result);
        PlayerData_SetGender(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_FIGHT_STYLE, int_result);
        PlayerData_SetFightStyle(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_SKIN, int_result);
        PlayerData_SetSkin(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_OLDSKIN, int_result);
        PlayerData_SetOldSkin(playerid, int_result);
        

        // Money Info
        cache_get_value_name_int(0, PLAYER_FIELD_MONEY, int_result);
        PlayerData_SetMoney(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_BANK_ACCOUNT, int_result);
        PlayerData_SetBankStatus(playerid, int_result == 0 ? false : true);
        
        cache_get_value_name_int(0, PLAYER_FIELD_BANK_MONEY, int_result);
        PlayerData_SetBankMoney(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_COINS, int_result);
        PlayerData_SetCoins(playerid, int_result);
        

        // Score Info
        cache_get_value_name_int(0, PLAYER_FIELD_LEVEL, int_result);
        PlayerData_SetLevel(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_DEATHS, int_result);
        PlayerData_SetDeaths(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_KILLS, int_result);
        PlayerData_SetKills(playerid, int_result);
        
        cache_get_value_name_int(0, PLAYER_FIELD_WANTED_LEVEL, int_result);
        PlayerData_SetWantedLevel(playerid, int_result);
        

        Player_TemporaryInfo[playerid][pIsRegistered] = true;
	}
	else
	{
        Player_TemporaryInfo[playerid][pIsRegistered] = false;
	}
    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	SendClientMessage(playerid, COLOR_SOFTGREY, "* Dados Carregados com sucesso, pressione em 'Fazer Login'!");

    InterpolateCameraPos(playerid, 1205.1385, -1022.0357, 98.2310, 1323.6675, -920.1975, 92.3793, CAMERA_SPEED, CAMERA_MOVE);
	InterpolateCameraLookAt(playerid, 1205.7915, -1021.2730, 98.0759, 1324.2585, -919.3865, 92.3142, CAMERA_SPEED, CAMERA_MOVE);

    HideLoadingScreen(playerid);
    ShowLoginScreen(playerid);

    SelectTextDraw(playerid, COLOR_ORANGE);
	return 1;
}

function:OnPassswordHash(playerid) 
{
    new hash[BCRYPT_HASH_LENGTH];
	bcrypt_get_hash(hash);
    InsertPlayerInDataBase(playerid, hash);
    return 1;
}

function:OnPassswordVerify(playerid, bool:success)
{
    if(success) {
        format(HashPassword[playerid], BCRYPT_HASH_LENGTH, "\0");
 		OnPlayerLogin(playerid);
 	} 
    else {
 		new string[256];
        Player_TemporaryInfo[playerid][pLoginAttempts]++;
        if (Player_TemporaryInfo[playerid][pLoginAttempts] > 5)
        {
            format(HashPassword[playerid], BCRYPT_HASH_LENGTH, "\0");
            SendClientMessage(playerid, COLOR_INVALID, "Voc� errou sua senha v�rias vezes, por isso foi kickado do servidor!");
            Kick(playerid);
        }
        else
        {
            format(string, sizeof(string), "[%s AVISO]: Senha incorreta, voc� j� tentou [%d/5].", SERVER_TAG, Player_TemporaryInfo[playerid][pLoginAttempts]);
            SendClientMessage(playerid, COLOR_INVALID, string);
            format(string, sizeof(string), "[%s AVISO]: Se voc� errar al�m do limite, ser� kickado!", SERVER_TAG);
            SendClientMessage(playerid, COLOR_INVALID, string);
            format(string, sizeof(string), "{FFFFFF}Bem Vindo ao {33CCFF}%s{FFFFFF}!\n\nSua Conta: {33CCFF}%s{FFFFFF}.\nStatus: {00FF00}Registrada{FFFFFF}.\n\n{B4B5B7}Insira a senha abaixo para logar.", SERVER_NAME, Player_GetName(playerid));
            ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Fazer Login", string, "Entrar", "Sair");
        }
 	}
    return 1;
}

function:OnPlayerRegister(playerid) 
{
    PlayerData_SetID(playerid, cache_insert_id());
    Player_TemporaryInfo[playerid][pIsRegistered] = true;
    OnPlayerLogin(playerid);
    return 1;
}

function:OnPlayerLogin(playerid) 
{
    CancelSelectTextDraw(playerid);
	TogglePlayerSpectating(playerid, false);
    Player_TemporaryInfo[playerid][pLogged] = true;

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