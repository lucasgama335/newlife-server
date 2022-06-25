#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
// MySQL configuration
#define		MYSQL_HOST 			"localhost"
#define		MYSQL_USER 			"root"
#define		MYSQL_PASSWORD 		""
#define		MYSQL_PORT 		    3306
#define		MYSQL_DATABASE 		"samp"

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
// MySQL connection handle
static MySQL:DBConnection;
static g_MysqlRaceCheck[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock MySQL:Database_GetConnection()
{
    return DBConnection;
}

stock Database_IncrementRaceCheck(playerid)
{
    g_MysqlRaceCheck[playerid]++;
}

stock Database_GetRaceCheck(playerid)
{
    return g_MysqlRaceCheck[playerid];
}


//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    new MySQLOpt: option_id = mysql_init_options();
    mysql_set_option(option_id, AUTO_RECONNECT, true); // it automatically reconnects when loosing connection to mysql server
    mysql_set_option(option_id, SERVER_PORT, MYSQL_PORT);

    #if MYSQL_DEBUG == true
        mysql_log(ERROR | WARNING);
    #endif

    DBConnection = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);
    if (DBConnection == MYSQL_INVALID_HANDLE || mysql_errno(DBConnection) != 0)
    {
        print("[DATABASE]: Failed to connect to the database.");
        SendRconCommand("exit"); // Sending console command to shut down server.
		return 1;
    }
    
    print("[DATABASE]: Database connection established.");
    return 1;
}

hook OnGameModeExit()
{
    mysql_close(DBConnection);
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
	switch(errorid) {
		case 1136: printf("[MySQL] Error 1136 | Column count does not match value count => \"%s\"", query);
		case 1054: printf("[MySQL] Error 1054 | Invalid field name => \"%s\"", query);
		case 1065: printf("[MySQL] Error 1065 | Query was empty (variable's size too small?) => \"%s\" from \"%s\"", query, callback);
		case 1058: printf("[MySQL] Error 1058 | Column count doesn't match value count => \"%s\" from \"%s\"", query, callback);
		case 1203: printf("[MySQL] Error 1203 | User already has more than 'max_user_connections' active connections => \"%s\" from \"%s\"", query, callback);
		case 1045: printf("[MySQL] Error 1045 | Access denied");
		case ER_SYNTAX_ERROR: printf("[MySQL] Syntax Error => \"%s\"",query);

		default : printf("[MySQL] Error %d | Callback: %s | \"%s\"", errorid, callback, query);
	}
	return 1;
}