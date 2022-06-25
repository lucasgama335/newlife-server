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
#include <a_mysql>						// By pBlueG:				https://github.com/pBlueG/SA-MP-MySQL
#include <samp_bcrypt>					// By LassiR				https://github.com/LassiR/bcrypt-samp
#include <sscanf2>						// By Y_Less:				https://github.com/Y-Less/sscanf
#include <streamer>						// By Incognito:			https://github.com/samp-incognito/samp-streamer-plugin
#include <YSI_Data\y_iterate>       	// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Players\y_android>		// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Extra\y_inline_mysql>		// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Extra\y_inline_bcrypt>	// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Visual\y_commands> 		// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Coding\y_hooks> 			// By Y_Less:				https://github.com/pawn-lang/YSI-Includes

/*==============================================================================
	Definitions
==============================================================================*/
// Server Info
#define	DEV_MODE				true

#define	MYSQL_DEBUG				true
#define	MYSQL_SETUP_TABLES		false

#define SERVER_NAME				"NewLife"
#define	SERVER_TAG				"NL"
#define	SERVER_MODE				"RPG [BR/PT]"
#define	SERVER_MODE_ABBR		"RPG"
#define	SCRIPT_VERSION_MAJOR 	"0"
#define	SCRIPT_VERSION_MINOR 	"0"
#define	SCRIPT_VERSION_PATCH 	"1"
#define	SERVER_LANGUAGE			"Português BR/PT"
#define	SERVER_WEBSITE			"www.newlife.com"
#define	SERVER_OWNER			"Lucas Gama"

// Macros
#define function:%0(%1)			forward %0(%1); public %0(%1)
#define ReCommand:%0(%1)    	cmd_%0(%1)

// Configuration
#define	INVALID_VALUE			-1

#define	MAX_PASS_LEN			15

#define DEFAULT_SKIN			0

#define	SPAWN_POSX				839.1713
#define	SPAWN_POSY				-1341.7622
#define	SPAWN_POSZ				7.1719
#define	SPAWN_POSA				84.6765
#define	SPAWN_INTERIOR			0
#define	SPAWN_VW				0

#define DEFAULT_CLEAR_LINES 	15

#define	CAMERA_SPEED			2000

#define	GENDER_MALE				1
#define	GENDER_FEMALE			2

#define	MAX_VEHICLE_PER_PLAYER	2

#define	MAX_ADMIN_ROLES			11

// Dialogs
enum 
{
	DIALOG_ONLY_READ,
	DIALOG_CHECK_ANDROID,
	DIALOG_LOGIN,
	DIALOG_REGISTER,
	DIALOG_ADMIN_CMDS,
	DIALOG_ADMIN_CMDS2
}

/*==============================================================================
	Gamemode Scripts
==============================================================================*/
DEFINE_HOOK_REPLACEMENT(CommandPerformed, CmdWork);

// UTILS
#include <utils>

// SERVER CORE
#include <database>
#include <anticheat>

// EXTRA CORE
#include <maps>
#include <textdraws>

// PLAYER CORE
#include <player>

// FEATURES CORE

// COMMANDS
#include <cmds>

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
	#if DEV_MODE
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
