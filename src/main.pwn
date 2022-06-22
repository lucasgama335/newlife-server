#include <a_samp>

/*==============================================================================
	Library Predefinitions
==============================================================================*/
#define YSI_NO_VERSION_CHECK
#define YSI_NO_OPTIMISATION_MESSAGE
#define YSI_NO_MODE_CACHE
#define YSI_NO_HEAP_MALLOC

/*==============================================================================
	Libraries and respective links to their release pages
==============================================================================*/
#include <a_mysql>					// By pBlueG:				https://github.com/pBlueG/SA-MP-MySQL
#include <samp_bcrypt>				// By LassiR				https://github.com/LassiR/bcrypt-samp
#include <crashdetect>				// By Zeex:					https://github.com/Zeex/samp-plugin-crashdetect
#include <sscanf2>					// By Y_Less:				https://github.com/Y-Less/sscanf
#include <streamer>					// By Incognito:			https://github.com/samp-incognito/samp-streamer-plugin
#include <YSI_Coding\y_hooks> 		// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Visual\y_commands> 	// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Data\y_iterate>       // By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Players\y_android>	// By Y_Less:				https://github.com/pawn-lang/YSI-Includes

/*==============================================================================
	Definitions
==============================================================================*/
// Server Info
#define	DEV_MODE				true
#define	MYSQL_DEBUG				true
#define SERVER_NAME				"NewLife"
#define	SERVER_TAG				"NL"
#define	SERVER_MODE				"RPG [BR/PT]"
#define	SERVER_MODE_ABBR		"RPG"
#define	SCRIPT_VERSION_MAJOR 	"0"
#define	SCRIPT_VERSION_MINOR 	"0"
#define	SCRIPT_VERSION_PATCH 	"1"
#define	SERVER_LANGUAGE			"Portugues BR/PT"
#define	SERVER_WEBSITE			"www.newlife.com"
#define	SERVER_OWNER			"Lucas Gama"

// Macros
#define function:%0(%1)			forward %0(%1); public %0(%1)

// Configuration
#define	INVALID_VALUE		-1
#define DEFAULT_SKIN		0
#define	SPAWN_POSX			839.1713
#define	SPAWN_POSY			-1341.7622
#define	SPAWN_POSZ			7.1719
#define	SPAWN_POSA			84.6765
#define	SPAWN_INTERIOR		0
#define	SPAWN_VW			0
#define DEFAULT_CLEAR_LINES 15
#define	CAMERA_SPEED		2000

// Dialogs
#define DIALOG_ONLY_READ		0
#define	DIALOG_CHECK_ANDROID 	1
#define DIALOG_LOGIN    		2
#define DIALOG_REGISTER    		3

/*==============================================================================
	Gamemode Scripts
==============================================================================*/
// UTILS
#include "utils/delayed_kick.pwn"
#include "utils/colors.pwn"
#include "utils/player_name.pwn"
#include "utils/chat.pwn"

// SERVER CORE
#include "core/server/database/connection/connect.pwn"
#include "core/server/database/tables/create_player_table.pwn"
#include "core/server/anticheat/money.pwn"

// EXTRA CORE
#include "core/extra/textdraws/loading_screen.pwn"
#include "core/extra/textdraws/login_screen.pwn"

// PLAYER CORE
#include "core/player/data/general_info.pwn"
#include "core/player/data/appearence_info.pwn"
#include "core/player/data/money_info.pwn"
#include "core/player/data/score_info.pwn"
#include "core/player/auth/player_auth.pwn"

// FEATURES CORE

main() 
{
	// write code here and run "sampctl package build" to compile
	// then run "sampctl package run" to run it
	print("\n==========================================");
	print("|                                    	 |");
	print("|    *** ***       ***   *** 	 	 |");
	print("|    ***  ***      ***   *** 	 	 |");
	print("|    ***   ***     ***   *** 	 	 |");
	print("|    ***    ***    ***   *** 	 	 |");
	print("|    ***     ***   ***   *** 	 	 |");
	print("|    ***      ***  ***   *************   |");
	print("|    ***       *** ***   *************   |");
	print("|                                    	 |");
	print("==========================================");
	print("|                                    	 |");
	printf("| Server:       %s %s          	 |", SERVER_NAME, SERVER_MODE_ABBR);
	printf("| Version:      v%s.%s.%s           	 |", SCRIPT_VERSION_MAJOR, SCRIPT_VERSION_MINOR, SCRIPT_VERSION_PATCH);

	/*#if MAX_VEHICLES > 0 && MAX_VEHICLES < 10
		printf("| Vehicles:     %d          		 |", MAX_VEHICLES);
	#elseif MAX_VEHICLES >= 10 && MAX_VEHICLES < 100
		printf("| Vehicles:     %d          		 |", MAX_VEHICLES);
	#elseif MAX_VEHICLES >= 100 && MAX_VEHICLES < 1000
		printf("| Vehicles:     %d          		 |", MAX_VEHICLES);
	#else
		printf("| Vehicles:     %d          		 |", MAX_VEHICLES);
	#endif*/

	printf("| Players:      %d          		 |", MAX_PLAYERS);

	printf("| Author:       %s           	 |", SERVER_OWNER);
	#if DEV_MODE == true
		print("| Status:       Initalized (MODE: Dev)   |");
	#else
		print("| Status:       Initalized (MODE: Live)  |");
	#endif
	print("|                                    	 |");
	print("==========================================\n");
}

public OnGameModeInit()
{
	//=====================================[ SERVER CONFIGURATION ]====================================||
	new serverCmd[64];
	format(serverCmd, sizeof(serverCmd), "hostname %s %s", SERVER_NAME, SERVER_MODE_ABBR);
	SendRconCommand(serverCmd);
	format(serverCmd, sizeof(serverCmd), "gamemodetext %s - v%s.%s.%s", SERVER_MODE, SCRIPT_VERSION_MAJOR, SCRIPT_VERSION_MINOR, SCRIPT_VERSION_PATCH);
	SendRconCommand(serverCmd);
	format(serverCmd, sizeof(serverCmd), "language %s", SERVER_LANGUAGE);
	SendRconCommand(serverCmd);
	format(serverCmd, sizeof(serverCmd), "weburl %s", SERVER_WEBSITE);
	SendRconCommand(serverCmd);

	//=====================================[ GAMEMODE CONFIGURATION ]====================================||
	UsePlayerPedAnims(); // Use walking animation of CJ to all skins
    ShowPlayerMarkers(0);
    ShowNameTags(1);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(0);
    SetNameTagDrawDistance(100.0);
    ManualVehicleEngineAndLights();
	return 1;
}

public OnGameModeExit()
{
	return 1;
}
