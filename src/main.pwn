#include <a_samp>
#include <omp>

/*==============================================================================
	Library Predefinitions
==============================================================================*/
// #define FIXES_Single 1
// #define FIXES_ServerVarMsg 0

#if defined MAX_PLAYERS
#undef MAX_PLAYERS
#define MAX_PLAYERS   50
#endif

#define YSI_NO_HEAP_MALLOC

#if !defined IsValidVehicle
    native IsValidVehicle(vehicleid);
#endif


/*==============================================================================
	Libraries and respective links to their release pages
==============================================================================*/
// #include <fixes>						// By Y_Less:				https://github.com/pawn-lang/sa-mp-fixes (have a bug on android, show a empty dialog)
#include <a_mysql>						// By pBlueG:				https://github.com/pBlueG/SA-MP-MySQL
#include <samp_bcrypt>					// By LassiR				https://github.com/LassiR/bcrypt-samp
#include <sscanf2>						// By Y_Less:				https://github.com/Y-Less/sscanf
#include <streamer>						// By Incognito:			https://github.com/samp-incognito/samp-streamer-plugin
#include <chrono>						// By Southclaws:			https://github.com/Southclaws/pawn-chrono
#include <YSI_Data\y_iterate>       	// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Visual\y_commands> 		// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Extra\y_inline_mysql>		// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Extra\y_inline_bcrypt>	// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Coding\y_timers> 			// By Y_Less:				https://github.com/pawn-lang/YSI-Includes
#include <YSI_Coding\y_hooks> 			// By Y_Less:				https://github.com/pawn-lang/YSI-Includes

/*==============================================================================
	Definitions
==============================================================================*/
#include <global_definitions>

/*==============================================================================
	Gamemode Scripts
==============================================================================*/
// SERVER CORE
#include <server>
#include <database>
#include <accounts>
#include <anticheat>
// UTILS
#include <utils>
// VEHICLES CORE
#include <vehicles>
// EXTRA
#include <maps>
#include <textdraws>
// PLAYER CORE
#include <player>
// FEATURES CORE
#include <features>
// CHAT
#include <chat>
// COMMANDS
#include <cmds>

/*==============================================================================
	Main Gamemode
==============================================================================*/
main() 
{
	// write code here and run "sampctl package build" to compile
	// then run "sampctl package run" to run it
	print("==========================================");
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
	printf("| Players:      %d          		 |", MAX_PLAYERS);
	printf("| Vehicles:     %d          		 |", (MAX_VEHICLES - 1));
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
    ShowNameTags(true);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(false);
    SetNameTagDrawDistance(100.0);
    ManualVehicleEngineAndLights();
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}
