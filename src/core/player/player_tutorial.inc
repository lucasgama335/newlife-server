#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define		TUTORIAL_STEP1TILE	"{FFFFFF}Seja Bem Vindo (1/10)"
#define		TUTORIAL_STEP1		"{FFFFFF}Seja Bem Vindo(a) ao NewLife RPG!\nVoc� est� prestes a come�ar a sua segunda de forma incr�vel no nosso servidor.\nN�s criamos todos os sitemas do servidor pensando na sua divers�o\ne de modo que todos os sistemas interajam entre si dando vida ao servidor.\nSinta-se livre para explorar cada detalhe no nosso servidor, sua divers�o � o nosso objetivo!\nEm caso de d�vidas, n�o hesite em procurar nossa equipe extremamente qualificada."
#define 	TUT_CAMERA_POS1   	359.8919, -2071.0210, 39.9252
#define 	TUT_CAMERA_LOOK1  	360.1927, -2070.0667, 39.5498

#define		TUTORIAL_STEP2TILE	"{FFFFFF}Estilo de jogo RPG (2/10)"
#define		TUTORIAL_STEP2		"{FFFFFF}Nosso servidor � totalmente RPG, ou seja, devemos agir igual na vida real ou voc� ser� punido por nossa equipe.\nO servidor � focado na cidade de Los Santos e possui 20 organiza��es que ditam o ritmo da cidade.\nAs organiza��es s�o institui��es da cidade, e s�o comandadas por um l�der escolhido por nossa equipe para gui�-la.\nCada uma das organiza��es possui uma fun��o seja gangsters, policiais, terroristas e etc.\nPor serem t�o importantes s�o elas que definem o ritmo de vida no servidor."
#define 	TUT_CAMERA_POS2   	404.6125, -2065.8992, 39.9252
#define 	TUT_CAMERA_LOOK2  	403.9268, -2065.1704, 39.5498

#define		TUTORIAL_STEP3TILE	"{FFFFFF}Prefeitura e Empregos (3/10)"
#define		TUTORIAL_STEP3		"{FFFFFF}Essa � a nossa prefeitura sede da organiza��o do Governo e tamb�m o local onde voc� pegar� seu primeiro emprego.\nOs empregos diferem-se das organiza��es, pois n�o possuem um l�der e s�o focados nas din�micas b�sicas do servidor,\ncomo voc� est� come�ando a sua vida aqui, ap�s o tutorial voc� deve vir conseguir seu primeiro emprego\nat� acostumar-se comas mec�nicas b�sicas, para depois preocupar-se em entrar em uma organiza��o."
#define 	TUT_CAMERA_POS3   	1483.0637, -1723.9744, 29.4023
#define 	TUT_CAMERA_LOOK3  	1483.0697, -1724.9760, 28.9769

#define		TUTORIAL_STEP4TILE	"{FFFFFF}Habilita��o (4/10)"
#define		TUTORIAL_STEP4		"{FFFFFF}Esse � o centro de licen�as, o local onde voc� ir� conseguir sua habilita��o para dirigir ve�culos.\nEsse � um dos locais mais importantes, pois n�o importa o que voc� for fazer sempre ser� necess�rio\nlocomover-se no servidor e sem habilita��o isso se torna imposs�vel. Por isso, ap�s o \nfim do tutorial esse dever� ser o primeiro local, o qual voc� dever� vir.OBS: Alguns empregos iniciais requerem habilita��o, por isso visite esse local o mais breve poss�vel."
#define 	TUT_CAMERA_POS4   	1078.6370, -1728.0460, 18.6755
#define 	TUT_CAMERA_LOOK4  	1078.6498, -1727.0453, 18.5650

#define		TUTORIAL_STEP5TILE	"{FFFFFF}Banco (5/10)"
#define		TUTORIAL_STEP5		"{FFFFFF}Esse � o principal banco da cidade de Los Santos, aqui voc� poder� abrir sua conta e armazenar o seu dinheiro.\nPossuir uma conta no banco � de extrema import�ncia, pois aqui seu dinheiro estar� seguro de assaltos e outros tipos de perdas.\nVoc� tamb�m encontrar� diversos caixas eletr�nicos espalhados pela cidades, todos eles conectados ao sistema do banco."
#define 	TUT_CAMERA_POS5   	1484.6605, -1053.9138, 32.5108
#define 	TUT_CAMERA_LOOK5  	1484.1168, -1053.0737, 32.3804

#define		TUTORIAL_STEP6TILE	"{FFFFFF}Postos de Gasolina (6/10)"
#define		TUTORIAL_STEP6		"{FFFFFF}Esse � um dos v�rios postos de gasolina espalhados pela cidade.\nAqui voc� poder� abastecer o seu ve�culo e outros servi�os.\nAconselha-mos sempre que poss�vel chamar um mec�nico para servi�os em ve�culos,\npois eles podem te ajudar com outros tipos servi�os."
#define 	TUT_CAMERA_POS6   	1974.5833, -1751.7759, 21.7589
#define 	TUT_CAMERA_LOOK6  	1973.7455, -1752.3206, 21.5984

#define		TUTORIAL_STEP7TILE	"{FFFFFF}Loja de Utilit�rios (7/10)"
#define		TUTORIAL_STEP7		"{FFFFFF}Essa � uma loja de utilit�rios, a qual possui v�rias filiais espalhadas por toda a Los Santos.\nNesse local voc� poder� comprar diversos itens de import�ncia b�sica, mas vital na sua jogatina,\ncomo: cr�dito para celular, gal�o de gasolina, kit de reparo, dentre outros.\nEssas lojas ficam abertas 24h por dia no servidor, voc� pode encontrar v�rias usando o (/gps)."
#define 	TUT_CAMERA_POS7   	1353.9879, -1731.6476, 22.3567
#define 	TUT_CAMERA_LOOK7  	1353.9620, -1732.6456, 21.9963

#define		TUTORIAL_STEP8TILE	"{FFFFFF}Loja VIP (8/10)"
#define		TUTORIAL_STEP8		"{FFFFFF}Nosso servidor � composto por um sistema VIP de import�ncia vital, pois � atrav�s dele que o servidor\nmant�m-se online e voc� consegue se divertir. Nosso sistema vip possui v�rios benef�cios e todos eles voc� encontra nessa loja.\nTodo servi�o vip consome a chamada Moedas VIP, a qual � a moeda de troca do servidor por esses tipos de servi�o.\nVoc� pode conseguir essas moedas visitando o nosso f�rum para mais informa��es.\nOBS: Diferente de v�rios servidores, nosso sistema vip � focado em cosm�ticos apenas, sem servi�os que deem vantagens\ndesbalanceadas para os jogadores.\nVoc� tamb�m poder� conseguir moedas vip jogando, em diversos eventos din�micos que aparecem no servidor.\nNosso foco � ser um servidor divertido para todos e n�o pay-to-win."
#define 	TUT_CAMERA_POS8   	363.7817, -1896.6782, 13.7987
#define 	TUT_CAMERA_LOOK8  	364.7801, -1896.6996, 13.5283

#define		TUTORIAL_STEP9TILE	"{FFFFFF}Binco (9/10)"
#define		TUTORIAL_STEP9		"{FFFFFF}Essa � a loja de roupas (Skin) do servidor.\nAqui voc� poder� comprar v�rios estilos de roupas que ficam armazenados no seu invent�rio\ne que voc� pode comercializar com outros jogadores.\nAlgumas skins especiais fazem parte do tipo raro, as quais s� s�o adquiridas nas caixinhas,\nque s�o adquiridas na roda gigante."
#define 	TUT_CAMERA_POS9   	2265.6897, -1656.1288, 22.1388
#define 	TUT_CAMERA_LOOK9  	2264.7903, -1656.5634, 21.9134

#define		TUTORIAL_STEP10TILE	"{FFFFFF}Fim do Tutorial (10/10)"
#define		TUTORIAL_STEP10		"{FFFFFF}Chegamos ao fim do nosso tutorial, esperamos que tenha aprendido bastante nessa breve explica��o.\nMuitas das coisas do servidor voc� aprender� com o tempo, n�o precisa apressar-se em conseguir tudo de uma vez.\nNossa equipe de Administradores � extremamente qualificada e estar� sempre dispon�vel para te ajudar dentro do jogo e fora.\nEstamos sempre buscando melhorar nossos sistemas e trazer inova��es para voc�, como j� citado nosso objetivo � a sua divers�o e apenas isso.\nMuito obrigado por ter escolhido o nosso servidor como sua segunda vida, iremos nos empenhar para honrar sua escolha."
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
			    SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Tutorial]: Voc� escolheu o sexo feminino!");
				format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}, deseja ler nosso tutorial para obter\nalguns conhecimentos b�sicos de como come�ar?\n\nEscolha uma op��o abaixo:", GetPlayerNameCustom(playerid));
			    ShowPlayerDialog(playerid, DIALOG_OPTION_TUT, DIALOG_STYLE_MSGBOX, "Tutorial", string, "Sim", "N�o");
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
		        SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Tutorial]: Voc� escolheu o sexo masculino!");
		        format(string, sizeof(string), "{FFFFFF}Ol�, {33CCFF}%s{FFFFFF}, deseja ler nosso tutorial para obter\nalguns conhecimentos b�sicos de como come�ar?\n\nEscolha uma op��o abaixo:", GetPlayerNameCustom(playerid));
			    ShowPlayerDialog(playerid, DIALOG_OPTION_TUT, DIALOG_STYLE_MSGBOX, "Tutorial", string, "Sim", "N�o");
		    }
		}
        case DIALOG_OPTION_TUT:
		{
		    if (!response)
		    {
                Player_SetTutorialStatus(playerid, true);
				Database_SaveTutorial(playerid);
				ShowPlayerHud(playerid);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "Voc� optou por n�o ver o tutorial!");
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
	            ShowPlayerDialog(playerid, DIALOG_STEP_TUT_1, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP1TILE, TUTORIAL_STEP1, "Avan�ar", "Cancelar");
			}
		}
		case DIALOG_STEP_TUT_1:
		{
		    if (!response)
		    {
	     		SendClientMessage(playerid, COLOR_LIGHTBLUE, "Voc� cancelou o tutorial e foi kickado!");
	     		return KickPlayer(playerid);
		    }
		    if (response)
		    {
	            ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 1
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_1, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP1TILE, TUTORIAL_STEP1, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 2
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS1, TUT_CAMERA_POS2, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK1, TUT_CAMERA_LOOK2, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_2, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP2TILE, TUTORIAL_STEP2, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_1, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP1TILE, TUTORIAL_STEP1, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 2
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_2, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP2TILE, TUTORIAL_STEP2, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 3
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS2, TUT_CAMERA_POS3, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK2, TUT_CAMERA_LOOK3, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_3, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP3TILE, TUTORIAL_STEP3, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_2, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP2TILE, TUTORIAL_STEP2, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 3
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_3, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP3TILE, TUTORIAL_STEP3, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 4
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS3, TUT_CAMERA_POS4, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK3, TUT_CAMERA_LOOK4, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_4, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP4TILE, TUTORIAL_STEP4, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_3, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP3TILE, TUTORIAL_STEP3, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 4
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_4, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP4TILE, TUTORIAL_STEP4, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 5
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS4, TUT_CAMERA_POS5, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK4, TUT_CAMERA_LOOK5, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_5, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP5TILE, TUTORIAL_STEP5, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_4, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP4TILE, TUTORIAL_STEP4, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 5
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_5, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP5TILE, TUTORIAL_STEP5, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 6
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS5, TUT_CAMERA_POS6, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK5, TUT_CAMERA_LOOK6, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_6, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP6TILE, TUTORIAL_STEP6, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_5, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP5TILE, TUTORIAL_STEP5, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 6
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_6, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP6TILE, TUTORIAL_STEP6, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 7
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS6, TUT_CAMERA_POS7, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK6, TUT_CAMERA_LOOK7, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_7, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP7TILE, TUTORIAL_STEP7, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_6, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP6TILE, TUTORIAL_STEP6, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 7
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_7, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP7TILE, TUTORIAL_STEP7, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 8
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS7, TUT_CAMERA_POS8, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK7, TUT_CAMERA_LOOK8, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_8, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP8TILE, TUTORIAL_STEP8, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_7, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP7TILE, TUTORIAL_STEP7, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 8
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_8, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP8TILE, TUTORIAL_STEP8, "Avan�ar", "Cancelar");
				}
				// Tutorial Step 9
				gsTutorialLeftTime[playerid] = 5;

				InterpolateCameraPos(playerid, TUT_CAMERA_POS8, TUT_CAMERA_POS9, CAMERA_SPEED, CAMERA_MOVE);
				InterpolateCameraLookAt(playerid, TUT_CAMERA_LOOK8, TUT_CAMERA_LOOK9, CAMERA_SPEED, CAMERA_MOVE);
	            return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_9, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP9TILE, TUTORIAL_STEP9, "Avan�ar", "Voltar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_8, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP8TILE, TUTORIAL_STEP8, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
			    ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 9
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
	                return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_9, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP9TILE, TUTORIAL_STEP9, "Avan�ar", "Cancelar");
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
				return ShowPlayerDialog(playerid, DIALOG_STEP_TUT_9, DIALOG_STYLE_MSGBOX, TUTORIAL_STEP9TILE, TUTORIAL_STEP9, "Avan�ar", "Cancelar");
		    }
			if (response)
			{
				ClearChatBox(playerid, DEFAULT_CLEAR_LINES);
		        if (gsTutorialLeftTime[playerid] != 0)
				{
					// Tutorial Step 10
					new string[128];
					format(string, sizeof(string), "Voc� ainda n�o pode avan�ar no tutorial, faltam [%d] segundos, leia o tutorial com aten��o !", gsTutorialLeftTime[playerid]);
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
