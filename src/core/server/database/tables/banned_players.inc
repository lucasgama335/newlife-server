#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define BAN_JOIN_PREFIX                     "b"
#define BAN_TABLE_NAME                      "banned_players"
#define BAN_FIELD_ID                        "id"
#define BAN_FIELD_PLAYER_ID                 "player_id"
#define BAN_FIELD_ADMIN_ID                  "admin_id"
#define BAN_FIELD_PLAYER_IP                 "player_ip"
#define BAN_FIELD_BAN_TIME                  "ban_time"
#define BAN_FIELD_UNBAN_TIME                "unban_time"
#define BAN_FIELD_REASON                    "reason"

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Database_CreateBansTable()
{
    inline OnQueryBansFinished()
    {
        printf("[DATABASE]: Banned Players table created.");
    }

    MySQL_TQueryInline(Database_GetConnection(), using inline OnQueryBansFinished, "CREATE TABLE IF NOT EXISTS "BAN_TABLE_NAME" \
    ( \
        "BAN_FIELD_ID" int NOT NULL PRIMARY KEY AUTO_INCREMENT, \
        "BAN_FIELD_PLAYER_ID" int NOT NULL UNIQUE, FOREIGN KEY ("BAN_FIELD_PLAYER_ID") REFERENCES players("PLAYER_FIELD_ID"), \
        "BAN_FIELD_ADMIN_ID" int NOT NULL DEFAULT %d, FOREIGN KEY ("BAN_FIELD_ADMIN_ID") REFERENCES players("PLAYER_FIELD_ID"), \
        "BAN_FIELD_PLAYER_IP" varchar(15) NOT NULL, \
        "BAN_FIELD_BAN_TIME" int NOT NULL, \
        "BAN_FIELD_UNBAN_TIME" int NOT NULL DEFAULT 0, \
        "BAN_FIELD_REASON" varchar(143) NOT NULL DEFAULT 0, \
        created_at timestamp DEFAULT CURRENT_TIMESTAMP, \
        updated_at timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP)", INVALID_VALUE);
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
