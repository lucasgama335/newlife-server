#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define KickPlayer(%0) SetTimerEx("DelayedKick", 40, false, "d", %0)

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
function:DelayedKick(playerid)
{
    Kick(playerid);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
