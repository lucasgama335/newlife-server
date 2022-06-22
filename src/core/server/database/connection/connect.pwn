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
static stock Database_Init()
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

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    Database_Init();
    return 1;
}

hook OnGameModeExit()
{
    mysql_close(DBConnection);
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
	switch(errorid)
	{
		case CR_SERVER_GONE_ERROR:
		{
			printf("Lost connection to server");
		}
		case ER_SYNTAX_ERROR:
		{
			printf("Something is wrong in your syntax, query: %s",query);
		}
	}
    printf("There are %d unprocessed queries.", mysql_unprocessed_queries());
	return 1;
}