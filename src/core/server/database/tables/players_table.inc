#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define PLAYER_JOIN_PREFIX                      "p"
#define PLAYER_TABLE_NAME                       "players"
#define PLAYER_FIELD_ID                         "id"
#define PLAYER_FIELD_NAME                       "name"
#define PLAYER_FIELD_PASSWORD                   "password"
#define PLAYER_FIELD_ADMIN                      "admin"
#define PLAYER_FIELD_ATTENDANCES                "admin_attendances"
#define PLAYER_FIELD_RATING                     "admin_rating"
#define PLAYER_FIELD_NUMBERRANTING              "admin_numer_rating"
#define PLAYER_FIELD_TUTORIAL                   "tutorial"
#define PLAYER_FIELD_LAST_POSX                  "last_pos_x"
#define PLAYER_FIELD_LAST_POSY                  "last_pos_y"
#define PLAYER_FIELD_LAST_POSZ                  "last_pos_z"
#define PLAYER_FIELD_LAST_POSA                  "last_pos_a"
#define PLAYER_FIELD_LAST_INTERIOR              "last_interior"
#define PLAYER_FIELD_LAST_VW                    "last_virtual_world"
#define PLAYER_FIELD_LAST_LOGIN                 "last_login"
#define PLAYER_FIELD_LAST_CONNECTED_TIME        "last_connected_time"
#define PLAYER_FIELD_LAST_LOCALE                "last_interior_locale"

#define PLAYER_FIELD_JOB                        "job"
#define PLAYER_FIELD_ORG                        "org"
#define PLAYER_FIELD_ORG_ROLE                   "org_role"

#define PLAYER_FIELD_VIP                        "vip"
#define PLAYER_FIELD_SOCIO                      "socio"
#define PLAYER_FIELD_VIP_DAYS                   "vip_days"

#define PLAYER_FIELD_MONEY                      "money"
#define PLAYER_FIELD_ILLEGAL_MONEY              "illegal_money"
#define PLAYER_FIELD_ILLEGAL_SAFE_MONEY         "illegal_safe_money"
#define PLAYER_FIELD_BANK_ACCOUNT               "bank_account"
#define PLAYER_FIELD_BANK_MONEY                 "bank_money"

#define PLAYER_FIELD_GENDER                     "gender"
#define PLAYER_FIELD_FIGHT_STYLE                "fight_style"
#define PLAYER_FIELD_SKIN                       "skin"
#define PLAYER_FIELD_OLDSKIN                    "oldskin"
#define PLAYER_FIELD_SALARY                     "salary"
#define PLAYER_FIELD_COINS                      "coins"

#define PLAYER_FIELD_LEVEL                      "level"
#define PLAYER_FIELD_HOURS_PLAYED               "hours_played"
#define PLAYER_FIELD_NOOB_ANSWERS               "noob_answers"
#define PLAYER_FIELD_EXP                        "experience"
#define PLAYER_FIELD_DEATHS                     "deaths"
#define PLAYER_FIELD_KILLS                      "kills"
#define PLAYER_FIELD_WANTED_LEVEL               "wanted_level"

#define PLAYER_FIELD_JAILED                     "jailed"
#define PLAYER_FIELD_JAILTIME                   "jail_time"
#define PLAYER_FIELD_HUNGRY                     "hungry"
#define PLAYER_FIELD_DRINK                      "drink"
#define PLAYER_FIELD_PAYDAY_TIME                "payday_time"
#define PLAYER_FIELD_WARNINGS                   "warnings"
#define PLAYER_FIELD_MUTED                      "muted"
#define PLAYER_FIELD_MUTED_NOOB                 "muted_noob"

#define PLAYER_FIELD_CONFIG_TAG                 "config_tag"
#define PLAYER_FIELD_CONFIG_CITY                "config_city"
#define PLAYER_FIELD_CONFIG_SPAWN               "config_spawn"
#define PLAYER_FIELD_CONFIG_DOCUMENT            "config_document"
#define PLAYER_FIELD_CONFIG_SPEED               "config_speedometer"
#define PLAYER_FIELD_CONFIG_TRACKER             "config_tracker"
#define PLAYER_FIELD_CONFIG_HITSOUND            "config_hitsound"

#define PLAYER_FIELD_CONFIG_TERRITORIAL_CHAT    "config_territorial_chat"
#define PLAYER_FIELD_CONFIG_VIP_CHAT            "config_vip_chat"
#define PLAYER_FIELD_CONFIG_SOCIO_CHAT          "config_socio_chat"
#define PLAYER_FIELD_CONFIG_NOOB_CHAT           "config_noob_chat"
#define PLAYER_FIELD_CONFIG_LEADER_CHAT         "config_leader_chat"
#define PLAYER_FIELD_CONFIG_STREAM              "config_stream"
#define PLAYER_FIELD_CONFIG_SCREEN              "config_screen"

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Database_CreatePlayersTable()
{
    inline OnQueryFinished()
    {
        printf("[DATABASE]: Player's table created.");
    }

    MySQL_TQueryInline(Database_GetConnection(), using inline OnQueryFinished, "CREATE TABLE IF NOT EXISTS "PLAYER_TABLE_NAME" \
    ( \
        "PLAYER_FIELD_ID" int NOT NULL PRIMARY KEY AUTO_INCREMENT, \
        "PLAYER_FIELD_NAME" varchar(%d) NOT NULL UNIQUE, \
        "PLAYER_FIELD_PASSWORD" varchar(%d) NOT NULL, \
        "PLAYER_FIELD_ADMIN" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_ATTENDANCES" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_RATING" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_NUMBERRANTING" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_LEVEL" int NOT NULL DEFAULT 1, \
        "PLAYER_FIELD_HOURS_PLAYED" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_EXP" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_MONEY" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_ILLEGAL_MONEY" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_ILLEGAL_SAFE_MONEY" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_SALARY" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_BANK_ACCOUNT" tinyint NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_BANK_MONEY" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_JOB" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_ORG" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_ORG_ROLE" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_VIP" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_SOCIO" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_VIP_DAYS" int NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_GENDER" int DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_FIGHT_STYLE" int DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_SKIN" int DEFAULT %d NOT NULL, \
        "PLAYER_FIELD_OLDSKIN" int DEFAULT %d NOT NULL, \
        "PLAYER_FIELD_COINS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_DEATHS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_KILLS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_WANTED_LEVEL" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_JAILED" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_JAILTIME" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_HUNGRY" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_DRINK" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_PAYDAY_TIME" int DEFAULT 3600 NOT NULL, \
        "PLAYER_FIELD_WARNINGS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_MUTED" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_MUTED_NOOB" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_NOOB_ANSWERS" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_TUTORIAL" tinyint NOT NULL DEFAULT 0, \
        "PLAYER_FIELD_LAST_LOGIN" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_CONNECTED_TIME" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_POSX" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_POSY" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_POSZ" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_POSA" float DEFAULT %f NOT NULL, \
        "PLAYER_FIELD_LAST_INTERIOR" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_VW" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_LAST_LOCALE" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_TAG" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_CITY" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_SPAWN" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_DOCUMENT" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_SPEED" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_TRACKER" int DEFAULT 0 NOT NULL, \
        "PLAYER_FIELD_CONFIG_HITSOUND" int DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_SCREEN" tinyint DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_TERRITORIAL_CHAT" tinyint DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_VIP_CHAT" tinyint DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_SOCIO_CHAT" tinyint DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_NOOB_CHAT" tinyint DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_LEADER_CHAT" tinyint DEFAULT 1 NOT NULL, \
        "PLAYER_FIELD_CONFIG_STREAM" tinyint DEFAULT 1 NOT NULL, \
        created_at timestamp DEFAULT CURRENT_TIMESTAMP, \
        updated_at timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP \
    )", MAX_PLAYER_NAME, BCRYPT_HASH_LENGTH, DEFAULT_SKIN_MALE, DEFAULT_SKIN_MALE, SPAWN_POSX, SPAWN_POSY, SPAWN_POSZ, SPAWN_POSA);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
