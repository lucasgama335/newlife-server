#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define PLAYER_TABLE_NAME                       "players"
#define PLAYER_FIELD_ID                         "id"
#define PLAYER_FIELD_NAME                       "name"
#define PLAYER_FIELD_PASSWORD                   "password"
#define PLAYER_FIELD_ADMIN                      "admin"
#define PLAYER_FIELD_LEVEL                      "level"
#define PLAYER_FIELD_MONEY                      "money"
#define PLAYER_FIELD_BANK_ACCOUNT               "bank_account"
#define PLAYER_FIELD_BANK_MONEY                 "bank_money"
#define PLAYER_FIELD_GENDER                     "gender"
#define PLAYER_FIELD_FIGHT_STYLE                "fight_style"
#define PLAYER_FIELD_SKIN                       "skin"
#define PLAYER_FIELD_OLDSKIN                    "oldskin"
#define PLAYER_FIELD_COINS                      "coins"
#define PLAYER_FIELD_DEATHS                     "deaths"
#define PLAYER_FIELD_KILLS                      "kills"
#define PLAYER_FIELD_WANTED_LEVEL               "wanted_level"
#define PLAYER_FIELD_LAST_LOGIN_DATE            "last_login_date"
#define PLAYER_FIELD_LAST_LOGIN_HOUR            "last_login_hour"
#define PLAYER_FIELD_LAST_CONNECTED_TIME        "last_connected_time"
#define PLAYER_FIELD_LAST_POSX                  "last_pos_x"
#define PLAYER_FIELD_LAST_POSY                  "last_pos_y"
#define PLAYER_FIELD_LAST_POSZ                  "last_pos_z"
#define PLAYER_FIELD_LAST_POSA                  "last_pos_a"
#define PLAYER_FIELD_LAST_INTERIOR              "last_interior"
#define PLAYER_FIELD_LAST_VW                    "last_virtual_world"

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Database_CreatePlayerTable()
{
    new query_string[1082];
    format(query_string, sizeof(query_string), "CREATE TABLE IF NOT EXISTS "PLAYER_TABLE_NAME" \
    ( \
        "PLAYER_FIELD_ID" int NOT NULL PRIMARY KEY AUTO_INCREMENT, \
        "PLAYER_FIELD_NAME" varchar(%d) NOT NULL UNIQUE, \
        "PLAYER_FIELD_PASSWORD" varchar(%d) NOT NULL, \
        "PLAYER_FIELD_ADMIN" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_LEVEL" int NOT NULL DEFAULT 1, \
        "PLAYER_FIELD_MONEY" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_BANK_ACCOUNT" tinyint NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_BANK_MONEY" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_GENDER" int DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_FIGHT_STYLE" int DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_SKIN" int DEFAULT %d NOT NULL, \
        "PLAYER_FIELD_OLDSKIN" int DEFAULT %d NOT NULL, \
        "PLAYER_FIELD_COINS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_DEATHS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_KILLS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_WANTED_LEVEL" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_LOGIN_DATE" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_LOGIN_HOUR" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_CONNECTED_TIME" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_POSX" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_POSY" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_POSZ" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_POSA" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_INTERIOR" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_VW" int DEFAULT 0 NOT NULL, \
        created_at timestamp DEFAULT CURRENT_TIMESTAMP, \
        updated_at timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP \
    )", MAX_PLAYER_NAME, BCRYPT_HASH_LENGTH, DEFAULT_SKIN, DEFAULT_SKIN, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA);
    
    mysql_query(Database_GetConnection(), query_string, false);
    printf("[DATABASE]: Player's table created.");
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit() 
{
    Database_CreatePlayerTable();
    return 1;
}