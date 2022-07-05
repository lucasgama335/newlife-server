#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define FOLDER_ANTICHEAT_MONEY          "ServerLogs/AntiCheat/money_hack.log"
#define FOLDER_ANTICHEAT_ADVERTISING    "ServerLogs/AntiCheat/advertising_hack.log"
#define FOLDER_ADMIN_PAR 		        "ServerLogs/Admins/private_messages.log"
#define FOLDER_MYSQL_LOG                "ServerLogs/Admins/mysql.log"
#define FOLDER_BANS_SUCCESS             "ServerLogs/Bans/ban_success.log"
#define FOLDER_BANS_ERROR               "ServerLogs/Bans/ban_error.log"
#define FOLDER_UNBAN_SUCCESS            "ServerLogs/Bans/unban_success.log"
#define FOLDER_UNBAN_ERROR              "ServerLogs/Bans/unban_error.log"
#define FOLDER_ADMIN_SETMONEY           "ServerLogs/Admins/setmoney.log"
#define FOLDER_ADMIN_SETCOINS           "ServerLogs/Admins/setcoins.log"

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:gsIsRestartingServer = false;

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Server_IsRestarting()
{
    return gsIsRestartingServer;
}

stock bool:Server_SetIsRestarting(bool:status)
{
    return gsIsRestartingServer = status;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
