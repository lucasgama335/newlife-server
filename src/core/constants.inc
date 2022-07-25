#include <YSI_Coding/y_hooks>

/*==============================================================================
	Definitions
==============================================================================*/
// Server Info
#define	DEV_MODE				true

#define	MYSQL_DEBUG				true
#define	MYSQL_SETUP_TABLES		false
#define	MYSQL_INVALID_VALUE		-1

#define SERVER_NAME				"NewLife"
#define	SERVER_TAG				"NL"
#define	SERVER_MODE				"RPG [BR/PT]"
#define	SERVER_MODE_ABBR		"RPG"
#define	SCRIPT_VERSION_MAJOR 	"0"
#define	SCRIPT_VERSION_MINOR 	"0"
#define	SCRIPT_VERSION_PATCH 	"1"
#define	SERVER_LANGUAGE			"Portugu�s BR/PT"
#define	SERVER_WEBSITE			"www.nlrpg.forumeiros.com"
#define	SERVER_OWNER			"Lucas Gama"
#define	SERVER_ADMIN_PASS   	"123"	

// Macros
#define function:%0(%1)			forward %0(%1); public %0(%1)
#define	first_hook%0(%1)		hook%0@0(%1)
// Configuration
#define	INVALID_VALUE			-1

#define	TIME_WEATHER_FORECAST	7200

#define DEFAULT_SKIN_MALE		23
#define DEFAULT_SKIN_FEMALE		41
#define	DEFAULT_SKIN_JAILED_M	268
#define	DEFAULT_SKIN_JAILED_F	69	
#define	DEFAULT_SKIN_ADMIN_M	217
#define	DEFAULT_SKIN_ADMIN_F	211

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

#define KEY_F           		16
#define KEY_Y           		65536
#define KEY_N           		131072
#define KEY_H           		2
#define KEY_LALT        		1024
#define KEY_LSHIFT      		32

#define MAX_ATTACHED_OBJ 		9
#define	PLAYER_OBJECT_1			0
#define	PLAYER_OBJECT_2			1
#define	PLAYER_OBJECT_3			2
#define	PLAYER_OBJECT_4			3
#define	PLAYER_OBJECT_5			4
#define	PLAYER_OBJECT_6			5
#define	PLAYER_OBJECT_7			6
#define	PLAYER_OBJECT_8			7
#define	PLAYER_OBJECT_9			8
#define	PLAYER_OBJECT_10		9
#define SLOT_SERVER      		9


#define	MAX_VEHICLE_HEALTH		999.9

// Strings Limits
#define	MAX_PASS_LEN			15
#define	MIN_PASS_LEN			8
#define MAX_LOG_STRING  		118
#define MAX_IP_STRING           16
#define MAX_REASON_STRING       65
#define	MAX_ADMIN_ROLE_STRING	11
#define	MAX_FULL_DATE_STRING	20
#define	MAX_DAY_NAME_STRING		14
#define	MAX_DATE_STRING			9
#define	MAX_HOUR_STRING			9
#define	MAX_MONEY_STRING		100
#define	MAX_VEHICLE_NAME_STRING 29
#define	MAX_VEHICLE_FUEL_STRING 13

// Others
#define	PETROL_PRICE			6
#define	DIESEL_PRICE			7
#define	ELECTRIC_PRICE			5

// Logs
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

// Admin Levels
enum e_ADMIN_LEVELS
{
	NO_ADMIN,
	HELPER,
	ASPIRANT,
	BEGINNER,
	AUXILIAR,
	MASTER,
	MASTERP,
	MASTERPP,
	HELPER_OWNER,
	SUB_OWNER,
	OWNER
};

// Interiors Locales
enum e_INTERIOR_LOCALES
{
	NO_INTERIOR,
	CITY_HALL_INTERIOR,
	DRIVING_SCHOOL_LOCALE,
	COURT_OF_JUSTICE
};

// Dialogs
enum e_DIALOGS
{
	DIALOG_ONLY_READ,
	// Auth
	DIALOG_CHECK_ANDROID,
	DIALOG_LOGIN,
	DIALOG_REGISTER,
	// Admin
	DIALOG_GMX,
	DIALOG_ADMIN_CMDS,
	DIALOG_ADMIN_CMDS2,
	DIALOG_AUTH_ADMIN,
	DIALOG_ADMIN_HIDE,
	DIALOG_EDIT_PLAYER,
	DIALOG_EDIT_PLAYER_LEVEL,
	DIALOG_EDIT_PLAYER_EXPERIENCE,
	DIALOG_EDIT_PLAYER_HOURS_PLAYED,
	DIALOG_EDIT_PLAYER_DEATHS,
	DIALOG_EDIT_PLAYER_KILLS,
	DIALOG_EDIT_PLAYER_WANTED_LEVEL,
	DIALOG_EDIT_PLAYER_PAYDAY_TIME,
	DIALOG_TELEPORTS_MENU,
	DIALOG_TELEPORTS_GENERAL,
	DIALOG_TELEPORTS_GASSTATION,
	DIALOG_TELEPORTS_JOBS,
	DIALOG_TELEPORTS_TUNNINGS,
	// Faq and Help
	DIALOG_FAQ_LIST,
	DIALOG_FAQ_ITEM,
	DIALOG_HELP_LIST,
	DIALOG_HELP_ITEM,
	DIALOG_HELP_CMDS1,
	DIALOG_HELP_CMDS2,
	// Tutorial
	DIALOG_CHOOSE_SEX,
	DIALOG_OPTION_TUT,
	DIALOG_STEP_TUT_1,
	DIALOG_STEP_TUT_2,
	DIALOG_STEP_TUT_3,
	DIALOG_STEP_TUT_4,
	DIALOG_STEP_TUT_5,
	DIALOG_STEP_TUT_6,
	DIALOG_STEP_TUT_7,
	DIALOG_STEP_TUT_8,
	DIALOG_STEP_TUT_9,
	DIALOG_STEP_TUT_10,
	// Config
	DIALOG_CONFIG_LIST,
	DIALOG_MENU_HIT,
	DIALOG_MENU_LOCATE,
	DIALOG_MANAGE_TAG,
	// Features
	DIALOG_GAS_STATION,
	DIALOG_DRIVE_SCHOOL,
	DIALOG_GUN_LICENSE,
	DIALOG_GPS_MENU,
	DIALOG_GPS_GENERAL,
	DIALOG_GPS_GASSTATION,
	DIALOG_GPS_JOBS,
	DIALOG_GPS_TUNNINGS,
	// Inventory
	DIALOG_INVENTORY_DETACH_ITEMS,
	DIALOG_INVENTORY_REMOVE_ITEM,
	// Hungry and Drink
	DIALOG_FOOD_LIST,
	DIALOG_DRINK_LIST,
	// JOBS
	DIALOG_JOBS_LIST,
	DIALOG_CHOOSE_JOB,
};

// TAGS
enum e_TAGS
{
	NO_TAG,
	TAG_SCRIPTER,
	TAG_ADMIN,
	TAG_LEADER,
	TAG_SUBLEADER,
	TAG_VIP,
	TAG_SOCIO,
	TAG_NOOB,
	TAG_KILLER
};

// Screen Sizes
enum e_SCREENS
{
	SCREEN_INVALID,
	SCREEN_NORMAL,
	SCREEN_ULTRAWIDE
};

// Jobs
enum j_JOBS_LIST
{
	j_JOB_NONE,
	j_JOB_GARBAGEMAN,
	j_JOB_TRUCK_DRIVER,
	j_JOB_TAXI_DRIVER,
	j_JOB_LAWYER,
	j_JOB_GRAVEDIGGER,
	j_JOB_MINER,
	j_JOB_RESCUER,
	j_JOB_ELETRICIAN,
	j_JOB_BUS_DRIVER,
	j_JOB_FARMER
};