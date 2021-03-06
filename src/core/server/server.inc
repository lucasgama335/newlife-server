#include <database>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static bool:gsIsRestartingServer = false;

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock bool:Server_IsRestarting()
{
    return gsIsRestartingServer;
}

stock bool:Server_SetIsRestarting(bool:status)
{
    return gsIsRestartingServer = status;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
