#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define INVENTORY_TABLE_PREFIX              "inv"
#define INVENTORY_TABLE_NAME                "inventory_players"
#define INVENTORY_FIELD_ID                  "id"
#define INVENTORY_FIELD_PLAYER_ID           "player_id"
#define INVENTORY_FIELD_ITEM_ID             "item"
#define INVENTORY_FIELD_ITEM_SLOT           "slot"
#define INVENTORY_FIELD_ITEM_QUANTITY       "quantity"

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Database_CreateInventoryTable()
{
    inline OnQueryBansFinished()
    {
        printf("[DATABASE]: 'inventory_players' table created.");
    }

    MySQL_TQueryInline(Database_GetConnection(), using inline OnQueryBansFinished, "CREATE TABLE IF NOT EXISTS "INVENTORY_TABLE_NAME" \
    ( \
        "INVENTORY_FIELD_ID" int NOT NULL PRIMARY KEY AUTO_INCREMENT, \
        "INVENTORY_FIELD_PLAYER_ID" int NOT NULL, FOREIGN KEY ("INVENTORY_FIELD_PLAYER_ID") REFERENCES "PLAYER_TABLE_NAME"("PLAYER_FIELD_ID") ON DELETE CASCADE, \
        "INVENTORY_FIELD_ITEM_ID" int NOT NULL, \
        "INVENTORY_FIELD_ITEM_SLOT" int NOT NULL, \
        "INVENTORY_FIELD_ITEM_QUANTITY" int NOT NULL, \
        created_at timestamp DEFAULT CURRENT_TIMESTAMP, \
        updated_at timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP)", INVALID_VALUE);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
