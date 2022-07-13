#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit() 
{
    printf("[DATABASE]: TABLE SETUP BEGIN.");

    printf("[DATABASE]: Setting up '%s' table...", PLAYER_TABLE_NAME);
    Database_CreatePlayersTable();

    printf("[DATABASE]: Setting up '%s' table...", BAN_TABLE_NAME);
    Database_CreateBansTable();

    printf("[DATABASE]: Setting up '%s' table...", INVENTORY_TABLE_NAME);
    Database_CreateInventoryTable();
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
