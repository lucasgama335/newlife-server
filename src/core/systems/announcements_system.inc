#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsAnnouncementsTimer;
static gsAnnouncementsMessages[][] =
{
    "[Atenção]: Registre-se em nosso fórum, ele é essencial para o servidor.",
	"[Servidor]: Tem dúvidas? Precisa de ajuda? Digite: /relatorio ou use o chat de dúvidas (/n).",
	"[Servidor]: Você foi ofendido? Tratado mal? Te puniram injustamente? Vá até o fórum e denuncie.",
	"[Servidor]: Chame os seus amigos, com isso você ajudará no crescimento do NewLife RPG.",
	"[Dica]: Evite ser multado, a noite ande com o /farol de seu veículo sempre ligado.",
	"[Dica]: Comandos Úteis: /configuracoes /ajuda /admins /nchat /vip /faq /rg /inventario",
	"[Dica]: Retire suas licenças (carro, moto, armas e etc...) indo até o Centro de Licenças (/gps).",
	"[Servidor]: Começou a jogar agora e tem dúvidas? Digite /faq ou tire suas dúvidas com um Admin (/relato).",
	"[Servidor]: Visite nosso canal no youtube e se inscreva: => link <=",
	"[Servidor]: Caso não tenha admins online, Tire suas dúvidas digitando: /nchat.",
	"[Dica]: Obtenha Caixa Surpresa automática por PayDay deixando seu personagem de modo /dormir no HOTEL das 22h às 07h.",
	"[Servidor]: Surpote 24 Horas através do nosso fórum: => /sites <=",
	"[Servidor]: Veja as principais novidades do servidor digitando: /changelog.",
	"[Dica]: É novato(a)? Precisa de ajuda? Peça ajuda a nossa administração digitando /relatorio ou /nchat(Chat Dúvida).",
	"[Dica]: Evite problemas com sua conta, tire print do seu /RG diariamente (Screenshot [F8]).",
	"[Servidor]: Nossa equipe está trabalhando sempre para melhorar sua jogabilidade em nosso servidor.",
	"[Servidor]: Siga-nos no Instagram, acesse: instagram.com/newlife.",
	"[Servidor]: Gostaria de anunciar alguma coisa para todos do Servidor? Digite /an.",
	"[Atenção]: Seja ativo em nosso fórum e seja recompensado => /sites <=",
	"[Servidor]: Encontrou o servidor na net e não sabe o IP? Adicione nos favoritos: ip.",
	"[Servidor]: Obtenha VIP/Sócio e tenha vários benefícios, para mais informações digite: /vip.",
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
