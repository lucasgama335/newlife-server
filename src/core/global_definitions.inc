#include <YSI_Coding/y_hooks>

/*==============================================================================
	Definitions
==============================================================================*/
// Server Info
#define	DEV_MODE				true

#define	MYSQL_DEBUG				true
#define	MYSQL_SETUP_TABLES		true
#define	MYSQL_INVALID_VALUE		-1

#define SERVER_NAME				"NewLife"
#define	SERVER_TAG				"NL"
#define	SERVER_MODE				"RPG [BR/PT]"
#define	SERVER_MODE_ABBR		"RPG"
#define	SCRIPT_VERSION_MAJOR 	"0"
#define	SCRIPT_VERSION_MINOR 	"0"
#define	SCRIPT_VERSION_PATCH 	"1"
#define	SERVER_LANGUAGE			"Português BR/PT"
#define	SERVER_WEBSITE			"www.nlrpg.forumeiros.com"
#define	SERVER_OWNER			"Lucas Gama"

// Macros
#define function:%0(%1)			forward %0(%1); public %0(%1)

// Configuration
#define	INVALID_VALUE			-1

#define	MAX_PASS_LEN			15
#define	MIN_PASS_LEN			8
#define MAX_LOG_STRING  		118
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
	DIALOG_GAS_STATION
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