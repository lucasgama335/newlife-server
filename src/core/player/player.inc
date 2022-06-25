// Database Player Data
#include <general_data>
#include <appearence_data>
#include <money_data>
#include <score_data>
#include <vip_data>

// InGame Player Data
#include <admin_data>

#include <player_admin> // First Hook of (OnPlayerConnect, OnDialogResponse)
#include <player_auth> // First Hook of (OnPlayerDisconnect, OnPlayerRequestClass, OnPlayerClickTextDraw) / Second Hook of (OnPlayerConnect, OnDialogResponse)
#include <player_spawn> // First Hook of (OnPlayerSpawn, OnPlayerRequestSpawn, SaveOnDisconnect)
#include <player_anims> // Second Hook of (OnPlayerSpawn)
#include <player_cmds>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------


//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
