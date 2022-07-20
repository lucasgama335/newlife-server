#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define		TUTORIAL_STEP1TILE	"{FFFFFF}Seja Bem Vindo (1/10)"
#define		TUTORIAL_STEP1		"{FFFFFF}Seja Bem Vindo(a) ao NewLife RPG!\nVocê está prestes a começar a sua segunda de forma incrível no nosso servidor.\nNós criamos todos os sitemas do servidor pensando na sua diversão\ne de modo que todos os sistemas interajam entre si dando vida ao servidor.\nSinta-se livre para explorar cada detalhe no nosso servidor, sua diversão é o nosso objetivo!\nEm caso de dúvidas, não hesite em procurar nossa equipe extremamente qualificada."
#define 	TUT_CAMERA_POS1   	359.8919, -2071.0210, 39.9252
#define 	TUT_CAMERA_LOOK1  	360.1927, -2070.0667, 39.5498

#define		TUTORIAL_STEP2TILE	"{FFFFFF}Estilo de jogo RPG (2/10)"
#define		TUTORIAL_STEP2		"{FFFFFF}Nosso servidor é totalmente RPG, ou seja, devemos agir igual na vida real ou você será punido por nossa equipe.\nO servidor é focado na cidade de Los Santos e possui 20 organizações que ditam o ritmo da cidade.\nAs organizações são instituições da cidade, e são comandadas por um líder escolhido por nossa equipe para guiá-la.\nCada uma das organizações possui uma função seja gangsters, policiais, terroristas e etc.\nPor serem tão importantes são elas que definem o ritmo de vida no servidor."
#define 	TUT_CAMERA_POS2   	404.6125, -2065.8992, 39.9252
#define 	TUT_CAMERA_LOOK2  	403.9268, -2065.1704, 39.5498

#define		TUTORIAL_STEP3TILE	"{FFFFFF}Prefeitura e Empregos (3/10)"
#define		TUTORIAL_STEP3		"{FFFFFF}Essa é a nossa prefeitura sede da organização do Governo e também o local onde você pegará seu primeiro emprego.\nOs empregos diferem-se das organizações, pois não possuem um líder e são focados nas dinâmicas básicas do servidor,\ncomo você está começando a sua vida aqui, após o tutorial você deve vir conseguir seu primeiro emprego\naté acostumar-se comas mecânicas básicas, para depois preocupar-se em entrar em uma organização."
#define 	TUT_CAMERA_POS3   	1483.0637, -1723.9744, 29.4023
#define 	TUT_CAMERA_LOOK3  	1483.0697, -1724.9760, 28.9769

#define		TUTORIAL_STEP4TILE	"{FFFFFF}Habilitação (4/10)"
#define		TUTORIAL_STEP4		"{FFFFFF}Esse é o centro de licenças, o local onde você irá conseguir sua habilitação para dirigir veículos.\nEsse é um dos locais mais importantes, pois não importa o que você for fazer sempre será necessário\nlocomover-se no servidor e sem habilitação isso se torna impossível. Por isso, após o \nfim do tutorial esse deverá ser o primeiro local, o qual você deverá vir.OBS: Alguns empregos iniciais requerem habilitação, por isso visite esse local o mais breve possível."
#define 	TUT_CAMERA_POS4   	1078.6370, -1728.0460, 18.6755
#define 	TUT_CAMERA_LOOK4  	1078.6498, -1727.0453, 18.5650

#define		TUTORIAL_STEP5TILE	"{FFFFFF}Banco (5/10)"
#define		TUTORIAL_STEP5		"{FFFFFF}Esse é o principal banco da cidade de Los Santos, aqui você poderá abrir sua conta e armazenar o seu dinheiro.\nPossuir uma conta no banco é de extrema importância, pois aqui seu dinheiro estará seguro de assaltos e outros tipos de perdas.\nVocê também encontrará diversos caixas eletrônicos espalhados pela cidades, todos eles conectados ao sistema do banco."
#define 	TUT_CAMERA_POS5   	1484.6605, -1053.9138, 32.5108
#define 	TUT_CAMERA_LOOK5  	1484.1168, -1053.0737, 32.3804

#define		TUTORIAL_STEP6TILE	"{FFFFFF}Postos de Gasolina (6/10)"
#define		TUTORIAL_STEP6		"{FFFFFF}Esse é um dos vários postos de gasolina espalhados pela cidade.\nAqui você poderá abastecer o seu veículo e outros serviços.\nAconselha-mos sempre que possível chamar um mecânico para serviços em veículos,\npois eles podem te ajudar com outros tipos serviços."
#define 	TUT_CAMERA_POS6   	1974.5833, -1751.7759, 21.7589
#define 	TUT_CAMERA_LOOK6  	1973.7455, -1752.3206, 21.5984

#define		TUTORIAL_STEP7TILE	"{FFFFFF}Loja de Utilitários (7/10)"
#define		TUTORIAL_STEP7		"{FFFFFF}Essa é uma loja de utilitários, a qual possui várias filiais espalhadas por toda a Los Santos.\nNesse local você poderá comprar diversos itens de importância básica, mas vital na sua jogatina,\ncomo: crédito para celular, galão de gasolina, kit de reparo, dentre outros.\nEssas lojas ficam abertas 24h por dia no servidor, você pode encontrar várias usando o (/gps)."
#define 	TUT_CAMERA_POS7   	1353.9879, -1731.6476, 22.3567
#define 	TUT_CAMERA_LOOK7  	1353.9620, -1732.6456, 21.9963

#define		TUTORIAL_STEP8TILE	"{FFFFFF}Loja VIP (8/10)"
#define		TUTORIAL_STEP8		"{FFFFFF}Nosso servidor é composto por um sistema VIP de importância vital, pois é através dele que o servidor\nmantém-se online e você consegue se divertir. Nosso sistema vip possui vários benefícios e todos eles você encontra nessa loja.\nTodo serviço vip consome a chamada Moedas VIP, a qual é a moeda de troca do servidor por esses tipos de serviço.\nVocê pode conseguir essas moedas visitando o nosso fórum para mais informações.\nOBS: Diferente de vários servidores, nosso sistema vip é focado em cosméticos apenas, sem serviços que deem vantagens\ndesbalanceadas para os jogadores.\nVocê também poderá conseguir moedas vip jogando, em diversos eventos dinâmicos que aparecem no servidor.\nNosso foco é ser um servidor divertido para todos e não pay-to-win."
#define 	TUT_CAMERA_POS8   	363.7817, -1896.6782, 13.7987
#define 	TUT_CAMERA_LOOK8  	364.7801, -1896.6996, 13.5283

#define		TUTORIAL_STEP9TILE	"{FFFFFF}Binco (9/10)"
#define		TUTORIAL_STEP9		"{FFFFFF}Essa é a loja de roupas (Skin) do servidor.\nAqui você poderá comprar vários estilos de roupas que ficam armazenados no seu inventário\ne que você pode comercializar com outros jogadores.\nAlgumas skins especiais fazem parte do tipo raro, as quais só são adquiridas nas caixinhas,\nque são adquiridas na roda gigante."
#define 	TUT_CAMERA_POS9   	2265.6897, -1656.1288, 22.1388
#define 	TUT_CAMERA_LOOK9  	2264.7903, -1656.5634, 21.9134

#define		TUTORIAL_STEP10TILE	"{FFFFFF}Fim do Tutorial (10/10)"
#define		TUTORIAL_STEP10		"{FFFFFF}Chegamos ao fim do nosso tutorial, esperamos que tenha aprendido bastante nessa breve explicação.\nMuitas das coisas do servidor você aprenderá com o tempo, não precisa apressar-se em conseguir tudo de uma vez.\nNossa equipe de Administradores é extremamente qualificada e estará sempre disponível para te ajudar dentro do jogo e fora.\nEstamos sempre buscando melhorar nossos sistemas e trazer inovações para você, como já citado nosso objetivo é a sua diversão e apenas isso.\nMuito obrigado por ter escolhido o nosso servidor como sua segunda vida, iremos nos empenhar para honrar sua escolha."
#define 	TUT_CAMERA_POS10   	1354.3101, -923.8914, 92.0191
#define 	TUT_CAMERA_LOOK10  	1354.8054, -923.0244, 91.7638

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsTutorialLeftTime[MAX_PLAYERS],
       bool:gsIsPlayerInTutorial[MAX_PLAYERS];
static gsTutorialTimer[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
function:NextStepTutorial(playerid)
{
    if (gsTutorialLeftTime[playerid] > 0)
    {
        gsTutorialLeftTime[playerid] --;
        if (gsTutorialLeftTime[playerid] <= 0) 
		{
        	gsTutorialLeftTime[playerid] = 0;
        }
    }
    else
    {
        gsTutorialLeftTime[playerid] = 0;
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock Database_SaveTutorial(playerid)
{
    if (!IsPlayerConnected(playerid)) return false;

	new query_string[76];
    mysql_format(Database_GetConnection(), query_string, sizeof(query_string), "UPDATE %s SET %s = %d, %s = %d, %s = %d WHERE id = %d", 
    PLAYER_TABLE_NAME,
    PLAYER_FIELD_TUTORIAL, (Player_GetTutorialStatus(playerid) == true ? 1 : 0),
    PLAYER_FIELD_SKIN, Player_GetSkin(playerid),
    PLAYER_FIELD_OLDSKIN, Player_GetOldSkin(playerid),
    Player_GetId(playerid));
    mysql_tquery(Database_GetConnection(), query_string);
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowGenderDialog(playerid)
{
    new string[150];
    format(string, sizeof(string),"{FFFFFF}Bem Vindo(a): {FFFF00}%s\n\n{FFFFFF}Escolha o seu Sexo Abaixo:\n", GetPlayerNameCustom(playerid));
    ShowPlayerDialog(playerid, DIALOG_CHOOSE_SEX, DIALOG_STYLE_MSGBOX,"{FFFFFF}Servidor - Registro", string, "Masculino", "Feminino");
    return 1;
}

stock bool:Player_IsInTutorial(playerid)
{
	return gsIsPlayerInTutorial[playerid];
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    gsTutorialLeftTime[playerid] = 0;
    gsIsPlayerInTutorial[playerid] = false;
	gsTutorialTimer[playerid] = INVALID_VALUE;
	return 1;
}

hook OnPlayerDisconnect(playerid)
{
	if (gsTutorialTimer[playerid] != INVALID_VALUE)
	{
		KillTimer(gsTutorialTimer[playerid]);
		gsTutorialTimer[playerid] = INVALID_VALUE;
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.
	#pragma unused listitem // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    switch(dialogid)
    {
        case DIALOG_CHOOSE_SEX:
		{
		    if (!response)
			{
				new string[165];
			    Player_SetGender(playerid, 2);
                Player_SetSkin(playerid, DEFAULT_SKIN_FEMALE);
                Player_SetOldSkin(playerid, DEFAULT_SKIN_FEMALE);
			    SetPlayerSkin(playerid, Player_GetSkin(playerid));
				ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
				HidePlayerHud(playerid);
			    SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Tutorial]: Você escolheu o sexo feminino!");
				format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}, deseja ler nosso tutorial para obter\nalguns conhecimentos básicos de como começar?\n\nEscolha uma opção abaixo:", GetPlayerNameCustom(playerid));
			    ShowPlayerDialog(playerid, DIALOG_OPTION_TUT, DIALOG_STYLE_MSGBOX, "Tutorial", string, "Sim", "Não");
		    }
		    if (response)
		    {
				new string[165];
                Player_SetGender(playerid, 1);
                Player_SetSkin(playerid, DEFAULT_SKIN_MALE);
                Player_SetOldSkin(playerid, DEFAULT_SKIN_MALE);
                SetPlayerSkin(playerid, Player_GetSkin(playerid));
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
				HidePlayerHud(playerid);
		        SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Tutorial]: Você escolheu o sexo masculino!");
		        format(string, sizeof(string), "{FFFFFF}Olá, {33CCFF}%s{FFFFFF}, deseja ler nosso tutorial para obter\nalguns conhecimentos básicos de como começar?\n\nEscolha uma opção abaixo:", GetPlayerNameCustom(playerid));
			    ShowPlayerDialog(playerid, DIALOG_OPTION_TUT, DIALOG_STYLE_MSGBOX, "Tutorial", string, "Sim", "Não");
		    }
		}
        case DIALOG_OPTION_TUT:
		{
		    if (!response)
		    {
                Player_SetTutorialStatus(playerid, true);
				Database_SaveTutorial(playerid);
				ShowPlayerHud(playerid);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você optou por não ver o tutorial!");
				GameTextForPlayer(playerid, "~p~CONSIGA UM EMPREGO NA PREFEITURA", 5000, 1);
				SetPlayerCheckpoint(playerid, CITY_HALL_ENTRANCE, 5.0);
				return 1;
			}
			if (response)
			{
				// Tutorial Step 1
                gsTutorialLeftTime[playerid] = 5;
	            gsIsPlayerInTutorial[playerid] = true;
                gsTutorialTimer[playerid] = SetTimerEx("NextStepTutorial", 1000, true, "i", playerid);
		
				PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/f8nrr60p9wkk4c9/tutorial.mp3?dl=1");
				ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            TogglePlayerControllable(playerid, false);
	            PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	            TogglePlayerSpectating(playerid, true);
				InterpolateCameraPos(playerid, TUT_CAMERA_POS1, TUT_CAMERA_POS1, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK1, TUT_CAMERA_LOOK1, CAMERA_SPEED, CAMERA_MOVE);
	            ShowPlayerDialog(playerid, DIALOG_STEP_TUT_1, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP1TILE, TUTORIAL_STEP1, "Avançar", "Cancelar");
			}
		}
		case DIALOG_STEP_TUT_1:
		{
		    if (!response)
		    {
	     		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Você cancelou o tutorial e foi kickado!");
	     		return KickPlayer(playerid);
		    }
		    if (response)
		    {
	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 1
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_1, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP1TILE, TUTORIAL_STEP1, "Avançar", "Cancelar");
				}
				// Tutorial Step 2
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS1, TUT_CAMERA_POS2, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK1, TUT_CAMERA_LOOK2, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_2, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP2TILE, TUTORIAL_STEP2, "Avançar", "Voltar");
		    }
		}
		case DIALOG_STEP_TUT_2:
		{
		    if (!response)
		    {
				// Tutorial Step 1
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            InterpolateCameraPos(playerid, TUT_CAMERA_POS2, TUT_CAMERA_POS1, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK2, TUT_CAMERA_LOOK1, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_1, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP1TILE, TUTORIAL_STEP1, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 2
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_2, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP2TILE, TUTORIAL_STEP2, "Avançar", "Cancelar");
				}
				// Tutorial Step 3
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS2, TUT_CAMERA_POS3, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK2, TUT_CAMERA_LOOK3, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_3, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP3TILE, TUTORIAL_STEP3, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_3:
		{
		    if (!response)
		    {
				// Tutorial Step 2
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            InterpolateCameraPos(playerid, TUT_CAMERA_POS3, TUT_CAMERA_POS2, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK3, TUT_CAMERA_LOOK2, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_2, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP2TILE, TUTORIAL_STEP2, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 3
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_3, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP3TILE, TUTORIAL_STEP3, "Avançar", "Cancelar");
				}
				// Tutorial Step 4
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS3, TUT_CAMERA_POS4, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK3, TUT_CAMERA_LOOK4, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_4, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP4TILE, TUTORIAL_STEP4, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_4:
		{
		    if (!response)
		    {
				// Tutorial Step 3
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            InterpolateCameraPos(playerid, TUT_CAMERA_POS4, TUT_CAMERA_POS3, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK4, TUT_CAMERA_LOOK3, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_3, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP3TILE, TUTORIAL_STEP3, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 4
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_4, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP4TILE, TUTORIAL_STEP4, "Avançar", "Cancelar");
				}
				// Tutorial Step 5
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS4, TUT_CAMERA_POS5, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK4, TUT_CAMERA_LOOK5, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_5, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP5TILE, TUTORIAL_STEP5, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_5:
		{
		    if (!response)
		    {
				// Tutorial Step 4
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
				InterpolateCameraPos(playerid, TUT_CAMERA_POS5, TUT_CAMERA_POS4, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK5, TUT_CAMERA_LOOK4, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_4, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP4TILE, TUTORIAL_STEP4, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 5
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_5, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP5TILE, TUTORIAL_STEP5, "Avançar", "Cancelar");
				}
				// Tutorial Step 6
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS5, TUT_CAMERA_POS6, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK5, TUT_CAMERA_LOOK6, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_6, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP6TILE, TUTORIAL_STEP6, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_6:
		{
		    if (!response)
		    {
				// Tutorial Step 5
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
				InterpolateCameraPos(playerid, TUT_CAMERA_POS6, TUT_CAMERA_POS5, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK6, TUT_CAMERA_LOOK5, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_5, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP5TILE, TUTORIAL_STEP5, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 6
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_6, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP6TILE, TUTORIAL_STEP6, "Avançar", "Cancelar");
				}
				// Tutorial Step 7
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS6, TUT_CAMERA_POS7, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK6, TUT_CAMERA_LOOK7, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_7, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP7TILE, TUTORIAL_STEP7, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_7:
		{
		    if (!response)
		    {
				// Tutorial Step 6
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            InterpolateCameraPos(playerid, TUT_CAMERA_POS7, TUT_CAMERA_POS6, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK7, TUT_CAMERA_LOOK6, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_6, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP6TILE, TUTORIAL_STEP6, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 7
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_7, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP7TILE, TUTORIAL_STEP7, "Avançar", "Cancelar");
				}
				// Tutorial Step 8
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS7, TUT_CAMERA_POS8, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK7, TUT_CAMERA_LOOK8, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_8, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP8TILE, TUTORIAL_STEP8, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_8:
		{
		    if (!response)
		    {
				// Tutorial Step 7
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            InterpolateCameraPos(playerid, TUT_CAMERA_POS8, TUT_CAMERA_POS7, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK8, TUT_CAMERA_LOOK7, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_7, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP7TILE, TUTORIAL_STEP7, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 8
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_8, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP8TILE, TUTORIAL_STEP8, "Avançar", "Cancelar");
				}
				// Tutorial Step 9
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS8, TUT_CAMERA_POS9, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK8, TUT_CAMERA_LOOK9, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_9, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP9TILE, TUTORIAL_STEP9, "Avançar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_9:
		{
		    if (!response)
		    {
				// Tutorial Step 8
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
	            InterpolateCameraPos(playerid, TUT_CAMERA_POS9, TUT_CAMERA_POS8, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK9, TUT_CAMERA_LOOK8, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_8, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP8TILE, TUTORIAL_STEP8, "Avançar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 9
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_9, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP9TILE, TUTORIAL_STEP9, "Avançar", "Cancelar");
				}
				// Tutorial Step 10
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS9, TUT_CAMERA_POS10, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK9, TUT_CAMERA_LOOK10, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_10, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP10TILE, TUTORIAL_STEP10, "Finalizar", "Voltar");
			}
		}
		case DIALOG_STEP_TUT_10:
		{
		    if (!response)
		    {
				// Tutorial Step 9
				gsTutorialLeftTime[playerid] = 5;

	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
				InterpolateCameraPos(playerid, TUT_CAMERA_POS10, TUT_CAMERA_POS9, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK10, TUT_CAMERA_LOOK9, CAMERA_SPEED, CAMERA_MOVE);
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_9, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP9TILE, TUTORIAL_STEP9, "Avançar", "Cancelar");
		    }
			if (response)
			{
				ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 10
					new string[128];
					format(string, sizeof(string), "Você ainda não pode avançar no tutorial, faltam [%d] segundos, leia o tutorial com atenção !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_10, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP10TILE, TUTORIAL_STEP10, "Finalizar", "Cancelar");
				}
				// Finished Tut
				gsIsPlayerInTutorial[playerid] = false;
	     		gsTutorialLeftTime[playerid] = 0;
                if (gsTutorialTimer[playerid] != INVALID_VALUE)
				{
					KillTimer(gsTutorialTimer[playerid]);
					gsTutorialTimer[playerid] = INVALID_VALUE;
				}

                Player_SetTutorialStatus(playerid, true);
				Database_SaveTutorial(playerid);
	     		StopAudioStreamForPlayer(playerid);
	            TogglePlayerControllable(playerid, true);
				TogglePlayerSpectating(playerid, false);
				ShowPlayerHud(playerid);
				SetCameraBehindPlayer(playerid);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "Tutorial finalizado. Tenha um bom jogo!");
				GameTextForPlayer(playerid, "~p~CONSIGA UM EMPREGO NA PREFEITURA", 5000, 1);
				SetPlayerCheckpoint(playerid, CITY_HALL_ENTRANCE, 5.0);
				SpawnPlayer(playerid);
				return 1;
			}
		}
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
