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
		return SendClientMessage(playerid, COLOR_YELLOW, "Você já tem um emprego, digite /sairdoemprego !");
	}
    if (!IsPlayerInRangeOfPoint(playerid, 2.0, JOBS_LIST_MENU))
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "Você não está no menu de empregos.");
	}

    new jobsList[409 + 1];
    strcat(jobsList, "{FFFFFF}Emprego\t{FFFFFF}Nível\t{FFFFFF}Licenciamento\n");
 	strcat(jobsList, "{FFFFFF}Lixeiro\t1+\tCaminhão\n");
 	strcat(jobsList, "{FFFFFF}Caminhoneiro\t1+\tCaminhão\n");
 	strcat(jobsList, "{FFFFFF}Taxista\t3+\tCarros\n");
 	strcat(jobsList, "{FFFFFF}Advogado\t1+\tNenhuma\n");
 	strcat(jobsList, "{FFFFFF}Coveiro\t1+\tCarro\n");
 	strcat(jobsList, "{FFFFFF}Minerador\t1+\tNenhuma\n");
	strcat(jobsList, "{FFFFFF}Socorrista\t6+\tCarro e Caminhão\n");
	strcat(jobsList, "{FFFFFF}Eletricista\t3+\tCarro\n");
	strcat(jobsList, "{FFFFFF}Motorista de Ônibus\t3+\tCarro\n");
	strcat(jobsList, "{FFFFFF}Fazendeiro\t1+\tNenhuma\n");
	ShowPlayerDialog(playerid, DIALOG_JOBS_LIST, DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Agência de Empregos", jobsList, "Aceitar", "Fechar");
    return 1;
}

static stock ShowPlayerJobHelp(playerid)
{
	switch(Player_GetJob(playerid))
	{
	    case j_JOB_GARBAGEMAN:
	    {
	        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Lixeiro{B4B5B7}]:\n\n{33CCFF}Comandos: /mlixo (Marcar um Lixo) | /elixo (Entergar um Lixo na HQ) | /echat (Chat dos Lixeiros)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é coletar lixos pela cidade.\n{ff6347}DICA:{B4B5B7} Quando chegar em um lixo, saia do veículo para poder pegá-lo.", "Fechar", "");
	    }
	    case j_JOB_TRUCK_DRIVER:
	    {
	        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Caminhoneiro{B4B5B7}]:\n\n{33CCFF}Comandos: /mcarga (Marcar uma Mercadoria) | /ecarga (Entergar uma Mercadoria na HQ) | /echat (Chat dos Caminhoneiros)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é coletar mercadorias pela cidade.\n{ff6347}DICA:{B4B5B7} Quando chegar em uma mercadoria, saia do veículo para poder pegá-la.", "Fechar", "");
	    }
	    case j_JOB_TAXI_DRIVER:
	    {
	        ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Taxista{B4B5B7}]:\n\n{33CCFF}Comandos: /corrida [Preço] (Iniciar uma Corrida) | /servicos (Serviços Disponíveis) | /cservico (Cancela o Serviço Atual)\nComandos: /echat (Chat dos Taxistas)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é transportar os jogadores pela cidade.\n{ff6347}DICA:{B4B5B7} Seja gentil com os jogadores que solicitarem serviço.", "Fechar", "");
	    }
	    case j_JOB_LAWYER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Advogado{B4B5B7}]:\n\n{33CCFF}Comandos: /soltar [ID] [Preço] (Soltar um Detento) | /autorizacao (Pegar um Habeas Corpus na Penitenciária)\nComandos: /habilidades (Habilidade do Emprego) | /echat (Chat dos Advogados)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é coletar mercadorias pela cidade.\n{ff6347}DICA:{B4B5B7} Quanto mais dententos você soltar mais a sua habilidade de advocacia irá melhorar.", "Fechar", "");
	    }
	    case j_JOB_GRAVEDIGGER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Coveiro{B4B5B7}]:\n\n{33CCFF}Comandos: /mcadaver (Marcar um Cadáver) | /ecadaver (Entergar um Cadáver na HQ) | /echat (Chat dos Advogados)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é coletar corpos pela cidade.\n{ff6347}DICA:{B4B5B7} Quando chegar em um cadáver, saia do veículo para poder pegá-lo.", "Fechar", "");
	    }
	    case j_JOB_MINER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Minerador{B4B5B7}]:\n\n{33CCFF}Comandos: /minerar (Minera um Metal Precioso) | /infominerio (Informações sobre o Minério) | /pegarminerio (Pega um Minério do Chão)\nComandos: /venderminerio (Vende um Minério) | /echat (Chat dos Mineradores)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é coletar os minérios da mina.\n{ff6347}DICA:{B4B5B7} As vezes vale mais a pena minerar metais mais comuns, pois são mais rápidos.", "Fechar", "");
	    }
		case j_JOB_RESCUER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Socorrista{B4B5B7}]:\n\n{33CCFF}Comandos: /batercartao (Entra em modo de serviço) | /mudarsexo (Muda o Sexo do Jogador) | /scurar (Cura um Jogador)\nComandos: /scolete (Vende um Colete) | /echat (Chat dos Socorristas) | /localincendio (Localiza o Incêndio)\nComandos: /servicos (Serviços Disponíveis) | /cservico (Cancela o Serviço Atual)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é curar os jogadores e apagar incêndios pela cidade.\n{ff6347}DICA:{B4B5B7} Os incêndios surgem automaticamente pelo servidor.", "Fechar", "");
	    }
		case j_JOB_ELETRICIAN:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Eletricista{B4B5B7}]:\n\n{33CCFF}Comandos: /rotaeletricista (Localizar uma ocorrência no mapa) | /echat (Chat do Emprego)\nComandos: /colocarescada (Colocar a escada no poste) OBS: A escada é colocada automaticamente ao chegar no checkpoint.\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é consertar os postes defeituosos pela cidade.\n{ff6347}DICA:{B4B5B7} É necessário segurar a tecla 'Y' para consertar o poste.", "Fechar", "");
	    }
		case j_JOB_BUS_DRIVER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Motorista de Ônibus{B4B5B7}]:\n\n{33CCFF}Comandos: /iniciarrota | /echat (Chat do Emprego)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Sua função é seguir pelas rotas marcadas no mapa\ne ajudar os jogadores a chegarem aos locais de destino.", "Fechar", "");
	    }
		case j_JOB_FARMER:
	    {
         	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX,"Ajuda Emprego", "{B4B5B7}Emprego: [{33CCFF}Fazendeiro{B4B5B7}]:\n\n{33CCFF}Comandos: /plantar /pesquisa | /echat (Chat do Emprego)\n\n{FFFFFF}Para localizar a sua HQ, use: /gps!\n{ff6347}Explicação: {FFFFFF}Você deve pegar as sementes no menu do fazendeiro e plantá-las.\nApós plantar as sementes, você deve colher elas e entregar o trigo recolhido no menu.", "Fechar", "");
	    }
		default:
		{
			return SendClientMessage(playerid, COLOR_INVALID, "Você não possui um emprego.");
		}
	}
	return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) ------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    AddStaticPickup(1210, 23, JOBS_LIST_MENU);
    Create3DTextLabel("Menu de Empregos\nAperte F", COLOR_3DLABEL, JOBS_LIST_MENU, 20.0, 0);
    
    new Float:helpX, Float:helpY, Float:helpZ;
    Job_GetHelpPosition(j_JOB_GARBAGEMAN, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_TRUCK_DRIVER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_TAXI_DRIVER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_LAWYER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_GRAVEDIGGER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_RESCUER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_MINER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_ELETRICIAN, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_BUS_DRIVER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);

    Job_GetHelpPosition(j_JOB_FARMER, helpX, helpY, helpZ);
    AddStaticPickup(1239, 23, helpX, helpY, helpZ);
	Create3DTextLabel("\nAjuda Emprego\nAperte 'F' para saber\nmais sobre o seu emprego.", 0xFFA500FF, helpX, helpY, helpZ, 20.0, 0);
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
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da habilitação de caminhão para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_GARBAGEMAN;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Truck Driver
                    case 1:
                    {
                        // Need Org Verify
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da habilitação de caminhão para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_TRUCK_DRIVER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Taxi Driver
                    case 2:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 3)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa de no mínimo nível 3 para ingressar nesse emprego.");
                        }
                        if (Player_GetCarLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da habilitação de carros para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_TAXI_DRIVER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Lawyer
                    case 3:
                    {
                        // Need Org Verify
                        gsJobSelected[playerid] = j_JOB_LAWYER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Gravedigger
                    case 4:
                    {
                        // Need Org Verify
                        if (Player_GetCarLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da habilitação de carros para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_GRAVEDIGGER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Miner
                    case 5:
                    {
                        // Need Org Verify
                        gsJobSelected[playerid] = j_JOB_MINER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Rescuer
                    case 6:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 6)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa de no mínimo nível 6 para ingressar nesse emprego.");
                        }
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da habilitação de caminhão para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_RESCUER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Eletrician
                    case 7:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 3)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa de no mínimo nível 3 para ingressar nesse emprego.");
                        }
                        if (Player_GetCarLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da carros de carros para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_ELETRICIAN;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Bus Driver
                    case 8:
                    {
                        // Need Org Verify
                        if (Player_GetLevel(playerid) < 3)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa de no mínimo nível 3 para ingressar nesse emprego.");
                        }
                        if (Player_GetTruckLicense(playerid) <= 0)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você precisa da carros de caminhão para ingressar nesse emprego.");
                        }
                        gsJobSelected[playerid] = j_JOB_BUS_DRIVER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
		        	    ShowPlayerDialog(playerid, DIALOG_CHOOSE_JOB, DIALOG_STYLE_MSGBOX, "Contrato Trabalhista", string, "Aceitar", "Negar");
                        return 1;
                    }

                    // Farmer
                    case 9:
                    {
                        // Need Org Verify
                        gsJobSelected[playerid] = j_JOB_FARMER;
                        new string[(286 + MAX_PLAYER_NAME + MAX_JOB_NAME + 1)];
                        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}!\n\n{B4B5B7}Deseja se tornar um {FFFFFF}%s {B4B5B7}?.\n\n{33CCFF}Dica: {FFFFFF}Após adquirir um Emprego, haverá um ícone na sua hq\ncom as principais informações e comandos da sua profissão.\n\n{ff6347}OBS: {B4B5B7}Para aceitar o emprego clique em 'Aceitar'.", GetPlayerNameCustom(playerid), Job_GetName(gsJobSelected[playerid]));
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
                return SendClientMessage(playerid, COLOR_INVALID, "[Agência de Emprego]: Você negou a proposta de emprego.");
            }
            if (response)
            {
                Player_SetJob(playerid, gsJobSelected[playerid]);
                Player_SetSkin(playerid, GetPlayerSkin(playerid));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Agência de Emprego]: Parabéns com seu novo emprego, digite /ajuda > Emprego para saber seus comandos.");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Você não possui nenhum emprego.");
	}
	if (GetPlayerInterior(playerid) == 0)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "Você precisa estar em um interior para sair do seu emprego.");
 	}

	ResetPlayerWeapons(playerid);
    Player_SetJob(playerid, j_JOB_NONE);
    SetPlayerSkin(playerid, Player_GetSkin(playerid));
	Player_SaveJobData(playerid);
	DisablePlayerCheckpoint(playerid);
    SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Agência de Emprego]: Você saiu do seu emprego.");
	return 1;
}

YCMD:echat(playerid, params[], help)
{
	if (Player_GetJob(playerid) == j_JOB_NONE)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não possui um emprego.");
	}
	new text[91];
	if (sscanf(params, "s[91]", text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/echat) [Chat Emprego]");
	}
	if (!strlen(text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: (/echat) [Chat Emprego]");
	}
    if (strlen(text) > 91)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: A mensagem digitada é muito longa.");
	}
	if (CheckInvalidWords(text))
	{
	    new string[90];
		format(string, sizeof(string), "[ADMIN ALERTA]: %s[%d] tentou divulgar: %s.", GetPlayerNameCustom(playerid), playerid, text);
		SendAdminMessage(COLOR_YELLOW, string, HELPER);
		PrintLog(FOLDER_ANTICHEAT_ADVERTISING, string);
       	return 0;
	}

	new string[144];
	format(string, sizeof(string), "** %s %s: %s **", Job_GetName(Player_GetJob(playerid)), GetPlayerNameCustom(playerid), text);
	SendJobMessage(0xBEBEBEFF, string, Player_GetJob(playerid));
    return 1;
}
