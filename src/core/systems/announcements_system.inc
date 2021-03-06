#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsAnnouncementsTimer;
static gsAnnouncementsMessages[][] =
{
    "[Aten��o]: Registre-se em nosso f�rum, ele � essencial para o servidor.",
	"[Servidor]: Tem d�vidas? Precisa de ajuda? Digite: /relatorio ou use o chat de d�vidas (/n).",
	"[Servidor]: Voc� foi ofendido? Tratado mal? Te puniram injustamente? V� at� o f�rum e denuncie.",
	"[Servidor]: Chame os seus amigos, com isso voc� ajudar� no crescimento do NewLife RPG.",
	"[Dica]: Evite ser multado, a noite ande com o /farol de seu ve�culo sempre ligado.",
	"[Dica]: Comandos �teis: /configuracoes /ajuda /admins /nchat /vip /faq /rg /inventario",
	"[Dica]: Retire suas licen�as (carro, moto, armas e etc...) indo at� o Centro de Licen�as (/gps).",
	"[Servidor]: Come�ou a jogar agora e tem d�vidas? Digite /faq ou tire suas d�vidas com um Admin (/relato).",
	"[Servidor]: Visite nosso canal no youtube e se inscreva: => link <=",
	"[Servidor]: Caso n�o tenha admins online, Tire suas d�vidas digitando: /nchat.",
	"[Dica]: Obtenha Caixa Surpresa autom�tica por PayDay deixando seu personagem de modo /dormir no HOTEL das 22h �s 07h.",
	"[Servidor]: Surpote 24 Horas atrav�s do nosso f�rum: => /sites <=",
	"[Servidor]: Veja as principais novidades do servidor digitando: /changelog.",
	"[Dica]: � novato(a)? Precisa de ajuda? Pe�a ajuda a nossa administra��o digitando /relatorio ou /nchat(Chat D�vida).",
	"[Dica]: Evite problemas com sua conta, tire print do seu /RG diariamente (Screenshot [F8]).",
	"[Servidor]: Nossa equipe est� trabalhando sempre para melhorar sua jogabilidade em nosso servidor.",
	"[Servidor]: Siga-nos no Instagram, acesse: instagram.com/newlife.",
	"[Servidor]: Gostaria de anunciar alguma coisa para todos do Servidor? Digite /an.",
	"[Aten��o]: Seja ativo em nosso f�rum e seja recompensado => /sites <=",
	"[Servidor]: Encontrou o servidor na net e n�o sabe o IP? Adicione nos favoritos: ip.",
	"[Servidor]: Obtenha VIP/S�cio e tenha v�rios benef�cios, para mais informa��es digite: /vip.",
	"[Servidor]: Fique por dentro de todas as regras do servidor utilizando: /regras."
};

static randomColors[] =
{
    0x5eb7e3FF,
	0xe0ffffFF,
	0x33aa33FF,
	0x934ff6FF,
	0xffffffFF,
	0xf68e00FF,
	0x20b2aaFF,
	0x00e7c6FF,
	0xcd6cf6FF,
	0xf4005bFF,
	0x685000FF,
	0x685000FF
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
function:RandomMessages()
{
    new randColor = random(sizeof(randomColors)), randMsg = random(sizeof(gsAnnouncementsMessages));
    SendClientMessageToAll(randomColors[randColor], gsAnnouncementsMessages[randMsg]);
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    gsAnnouncementsTimer = SetTimer("RandomMessages", 180000, true); // 3 minutes
    return 1;
}

hook OnGameModeExit()
{
    KillTimer(gsAnnouncementsTimer);
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
