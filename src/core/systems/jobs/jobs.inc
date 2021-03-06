#include <job_garbageman>
#include <job_truck_driver>
#include <job_taxi_driver>
#include <job_lawyer>
#include <job_gravedigger>
#include <job_miner>
#include <job_rescuer>
#include <job_eletrician>
#include <job_bus_driver>
#include <job_farmer>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define	JOBS_LIST_MENU			361.8300,173.5202,1008.3828

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static j_JOBS_LIST:gsJobSelected[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowPlayerJobsList(playerid)
{
    if (Player_GetJob(playerid) != j_JOB_NONE)
	{
		return SendClientMessage(playerid, COLOR_YELLOW, "[Ag�ncia de Emprego]: Voc� j� tem um emprego, digite /sairdoemprego !");
	}
    if (!IsPlayerInRangeOfPoint(playerid, 2.0, JOBS_LIST_MENU))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� no menu de empregos.");
	}

    new jobsList[409 + 1];
    strcat(jobsList, "{FFFFFF}Emprego\t{FFFFFF}N�vel\t{FFFFFF}Licenciamento\n");
 	strcat(jobsList, "{FFFFFF}Lixeiro\t1+\tCaminh�o\n");
 	strcat(jobsList, "{FFFFFF}Caminhoneiro\t1+\tCaminh�o\n");
 	strcat(jobsList, "{FFFFFF}Taxista\t3+\tCarros\n");
 	strcat(jobsList, "{FFFFFF}Advogado\t1+\tNenhuma\n");
 	strcat(jobsList, "{FFFFFF}Coveiro\t1+\tCarro\n");
 	strcat(jobsList, "{FFFFFF}Minerador\t1+\tNenhuma\n");
	strcat(jobsList, "{FFFFFF}Socorrista\t6+\tCarro e Caminh�o\n");
	strcat(jobsList, "{FFFFFF}Eletricista\t3+\tCarro\n");
	strcat(jobsList, "{FFFFFF}Motorista de �nibus\t3+\tCarro\n");
	strcat(jobsList, "{FFFFFF}Fazendeiro\t1+\tNenhuma\n");
	ShowPlayerDialog(playerid, DIALOG_JOBS_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Ag�ncia de Empregos", jobsList, "Aceitar", "Fechar");
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------
stock ShowPlayerJobHelp(playerid)
{
	switch(Player_GetJob(playerid))
	{
	    case j_JOB_GARBAGEMAN:
	    {
	        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Lixeiro{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}A profiss�o de lixeiro � de extrema import�ncia na \nmanuten��o da cidade, pois ela cuida da higiene \ne limpeza da cidade, mantendo-a habit�vel para\ntodos os jogadores.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/mlixo - {FFFFFF}Inicia uma rota de coleta pela cidade.\n{B4B5B7}* {8d8dff}/elixo - {FFFFFF}Finaliza a rota de coleto, ap�s coletar o lixo.", "Fechar", "");
	    }
	    case j_JOB_TRUCK_DRIVER:
	    {
	        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Caminhoneiro{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os caminhoneiros s�o os respons�veis por movimentar\na economia de qualquer cidade. S�o eles quem realizam\no transporte de mercadorias por todo o pa�s.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/mcarga - {FFFFFF}Inicia uma rota de entrega.\n{B4B5B7}* {8d8dff}/ecarga - {FFFFFF}Finaliza a entrega.", "Fechar", "");
	    }
	    case j_JOB_TAXI_DRIVER:
	    {
	        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Taxista{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os taxistas s�o os respons�veis por transportar as\npessoas para todos os pontos da cidade. � um emprego\ncom muita intera��o com os demais jogadores.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/corrida [pre�o] - {FFFFFF}Inicia uma corrida.\n{B4B5B7}* {8d8dff}/servicos - {FFFFFF}Mostra as solicita��es dispon�veis.\n{B4B5B7}* {8d8dff}/cservico - {FFFFFF}Cancela o servi�o atual.", "Fechar", "");
	    }
	    case j_JOB_LAWYER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Advogado{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os advogados s�o respons�veis pela defesa jur�dica\ndos indiv�duos perante � justi�a.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/soltar [id] [pre�o] - {FFFFFF}Faz uma proposta de libera��o\npara um preso.\n\n{ff6347}Importante:\n{FFFFFF}Nesse emprego, h� n�veis de habilidade. Quanto mais\nalto for seu n�vel de advogado, voc� conseguir� soltar\njogadores com tempo de pris�o mais elevados.", "Fechar", "");
	    }
	    case j_JOB_GRAVEDIGGER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Coveiro{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os coveiros s�o os respons�veis por coletar os cad�veres\nque est�o pela cidade.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/mcadaver - {FFFFFF}Inicia uma coleta de cad�ver.\n{B4B5B7}* {8d8dff}/ecadaver - {FFFFFF}Entrega o cad�ver no cemit�rio.", "Fechar", "");
	    }
	    case j_JOB_MINER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Minerador{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os mineradores s�o respons�veis por coletar pedras\npreciosas e gerar riqueza para a cidade.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/minerar - {FFFFFF}Minera um veio de min�rio.\n{B4B5B7}* {8d8dff}/infominerio - {FFFFFF}Mostra informa��es sobre o min�rio.\n{B4B5B7}* {8d8dff}/pegarmineiro - {FFFFFF}Pega o min�rio que est� no ch�o.\n{B4B5B7}* {8d8dff}/venderminerio - {FFFFFF}Vende um min�rio na central.\n\n{ff6347}Importante:\n{FFFFFF}Nesse emprego, h� n�veis de habilidade. Quanto mais\nalto for seu n�vel de minera��o, voc� conseguir� minerar\nmetais mais preciosos.", "Fechar", "");
	    }
		case j_JOB_RESCUER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Socorrista{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os socorristas possuem uma import�ncia elevada na sociedade.\nEles s�o respons�veis por cuidar da sa�de dos jogadores e\ncombater inc�ndios pela cidade.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/batercartao - {FFFFFF}Entra em modo de servi�o.\n{B4B5B7}* {8d8dff}/servicos - {FFFFFF}Mostra as solicita��es de servi�os.\n{B4B5B7}* {8d8dff}/cservico - {FFFFFF}Cancela o servi�o atual.\n{B4B5B7}* {8d8dff}/curar - {FFFFFF}Recupera a sa�de do jogador.\n{B4B5B7}* {8d8dff}/mudarsexo - {FFFFFF}Realiza a mudan�a de sexo do jogador.\n{B4B5B7}* {8d8dff}/localincendio - {FFFFFF}Localiza um inc�ndio que esteja ocorrendo.", "Fechar", "");
	    }
		case j_JOB_ELETRICIAN:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Eletricista{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}A fun��o dos eletricistas � manter o pleno funcionamento\ndos servi�os el�tricos da cidade, realizando manuten��es\nnos postes de energia.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/rotaeletricista- {FFFFFF}Inicia um servi�o de reparo em um poste.", "Fechar", "");
	    }
		case j_JOB_BUS_DRIVER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Motorista de �nbus{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os Motoristas de �nibus s�o os respons�veis por transportar as\npessoas para todos os pontos da cidade. � um emprego\ncom muita intera��o com os demais jogadores.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/iniciarrota - {FFFFFF}Inicia uma rota de transporte.", "Fechar", "");
	    }
		case j_JOB_FARMER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"{FFFFFF}Ajuda Emprego", "{B4B5B7}Emprego: {9acd32}Fazendeiro{B4B5B7}.\n\n{B4B5B7}Fun��o Social:\n{FFFFFF}Os Fazendeiros s�o os respons�veis pela base econ�mica\nda cidade, pois utilizam da agricultura como meio de viv�ncia.\n\n{B4B5B7}Comandos da Profiss�o:\n\n{B4B5B7}* {8d8dff}/echat - {FFFFFF}Chat com os demais membros do emprego.\n{B4B5B7}* {8d8dff}/plantar - {FFFFFF}Planta uma semente.\n{B4B5B7}* {8d8dff}/pesquisa - {FFFFFF}Inicia uma rota de pesquisa por novas tecnologias.", "Fechar", "");
	    }
		default:
		{
			return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui um emprego.");
		}
	}
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    CreateDynamicPickup(1210, 23, JOBS_LIST_MENU);
    CreateDynamic3DTextLabel("Menu de Empregos\nAperte F", COLOR_3DLABEL, JOBS_LIST_MENU, 20.0, 0);
    
    new Float:helpX, Float:helpY, Float:helpZ;
    Job_GetHelpPosition(j_JOB_GARBAGEMAN, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_TRUCK_DRIVER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_TAXI_DRIVER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_LAWYER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_GRAVEDIGGER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_RESCUER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_MINER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_ELETRICIAN, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_BUS_DRIVER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);

    Job_GetHelpPosition(j_JOB_FARMER, helpX, helpY, helpZ);
    CreateDynamicPickup(1239, 23, helpX, helpY, helpZ);
	CreateDynamic3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    gsJobSelected[playerid] = j_JOB_NONE;
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if (Player_GetJob(playerid) != j_JOB_NONE)
    {
        new Float:posX, Float:posY, Float:posZ, Float:posA, interior, virtualWorld, e_INTERIOR_LOCALES:locale, bool:freeze, freezeTime;
        Job_GetSpawn(Player_GetJob(playerid), posX, posY, posZ, posA, interior, virtualWorld, locale, freeze, freezeTime);
        SetPlayerSkin(playerid, Job_GetSkin(playerid, Player_GetJob(playerid)));
        TeleportPlayer(playerid, posX, posY, posZ, interior, virtualWorld, locale, freeze, freezeTime);
        SetPlayerFacingAngle(playerid, posA);
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.
   
    switch (dialogid)
    {
        case DIALOG_JOBS_LIST:
        {
            if (!response)
            {
                return 1;
            }
            if (response)
            {
                switch (listitem)
                {
                    // Garbageman
                    case 0:
                    {
                        // Need Org Verify
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da habilita��o de caminh�o para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_GARBAGEMAN;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Truck Driver
                    case 1:
                    {
                        // Need Org Verify
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da habilita��o de caminh�o para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_TRUCK_DRIVER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Taxi Driver
                    case 2:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 3)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa de no m�nimo n�vel 3 para ingressar nesse emprego.");
                        }
                        if (Player_GetCarLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da habilita��o de carros para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_TAXI_DRIVER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Lawyer
                    case 3:
                    {
                        // Need Org Verify
                        gsJobSelected[playerid] = j_JOB_LAWYER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Gravedigger
                    case 4:
                    {
                        // Need Org Verify
                        if (Player_GetCarLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da habilita��o de carros para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_GRAVEDIGGER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Miner
                    case 5:
                    {
                        // Need Org Verify
                        gsJobSelected[playerid] = j_JOB_MINER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Rescuer
                    case 6:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 6)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa de no m�nimo n�vel 6 para ingressar nesse emprego.");
                        }
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da habilita��o de caminh�o para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_RESCUER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Eletrician
                    case 7:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 3)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa de no m�nimo n�vel 3 para ingressar nesse emprego.");
                        }
                        if (Player_GetCarLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da carros de carros para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_ELETRICIAN;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Bus Driver
                    case 8:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 3)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa de no m�nimo n�vel 3 para ingressar nesse emprego.");
                        }
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� precisa da carros de caminh�o para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_BUS_DRIVER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Farmer
                    case 9:
                    {
                        // Need Org Verify
                        gsJobSelected[playerid] = j_JOB_FARMER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Ap�s adquirir um Emprego, haver� um �cone na sua hq\ncom as principais informa��es e comandos da sua profiss�o.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }
                }
            }
        }

        case DIALOG_CHOOSE_JOB:
        {
            if (!response)
            {
                return SendClientMessage(playerid, COLOR_INVALID, "[Ag�ncia de Emprego]: Voc� negou a proposta de emprego.");
            }
            if (response)
            {
                Player_SetJob(playerid, gsJobSelected[playerid]);
                Player_SetSkin(playerid, GetPlayerSkin(playerid));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Ag�ncia de Emprego]: Parab�ns com seu novo emprego, digite /ajuda > Emprego para saber seus comandos.");
				StopAudioStreamForPlayer(playerid);
				Player_SaveJobData(playerid);
                gsJobSelected[playerid] = j_JOB_NONE;
				SpawnPlayer(playerid);
                return 1;
            }
        }
    }
    return 1;
}

hook OnPlayerPressF(playerid)
{
    if (IsPlayerInRangeOfPoint(playerid, 2.0, JOBS_LIST_MENU))
	{
	    ShowPlayerJobsList(playerid);
        return 1;
	}

    if (Player_GetJob(playerid) != j_JOB_NONE)
    {
        new Float:helpX, Float:helpY, Float:helpZ;
        Job_GetHelpPosition(Player_GetJob(playerid), helpX, helpY, helpZ);
        if (IsPlayerInRangeOfPoint(playerid, 2.0, helpX, helpY, helpZ))
        {
            ShowPlayerJobHelp(playerid);
            return 1;
        }
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:jobslist(playerid, params[], help)
{
    ShowPlayerJobsList(playerid);
    return 1;
}

YCMD:ajudaemprego(playerid, params[], help)
{
    ShowPlayerJobHelp(playerid);
    return 1;
}

YCMD:sairdoemprego(playerid, params[], help)
{
    if (Player_GetJob(playerid) == j_JOB_NONE)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui nenhum emprego.");
	}
	if (GetPlayerInterior(playerid) == 0)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "Voc� precisa estar em um interior para sair do seu emprego.");
 	}

	ResetPlayerWeapons(playerid);
    Player_SetJob(playerid, j_JOB_NONE);
    SetPlayerSkin(playerid, Player_GetSkin(playerid));
	Player_SaveJobData(playerid);
	DisablePlayerCheckpoint(playerid);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Ag�ncia de Emprego]: Voc� saiu do seu emprego.");
	return 1;
}

YCMD:echat(playerid, params[], help)
{
	if (Player_GetJob(playerid) == j_JOB_NONE)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o possui um emprego.");
	}
	new text[95];
	if (sscanf(params, "s[95]", text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/echat) [Chat Emprego]");
	}
	if (!strlen(text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/echat) [Chat Emprego]");
	}
    if (strlen(text) > 95)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: A mensagem digitada � muito longa.");
	}
	if (CheckInvalidWords(text))
	{
	    new string[90];
		format(string, sizeof(string), "[Alerta]: %s[%d] tentou divulgar: %s.", GetPlayerNameCustom(playerid), playerid, text);
		SendAdminMessage(COLOR_YELLOW, string, HELPER);
		PrintLog(FOLDER_ANTICHEAT_ADVERTISING, string);
       	return 0;
	}

	new string[144];
	format(string, sizeof(string), "[%s] %s: %s", Job_GetName(Player_GetJob(playerid)), GetPlayerNameCustom(playerid), text);
	SendJobMessage(0xBEBEBEFF, string, Player_GetJob(playerid));
    return 1;
}
