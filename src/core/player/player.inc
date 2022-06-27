// Database Player Data
#include <general_data>
#include <appearence_data>
#include <money_data>
#include <score_data>
#include <vip_data>

// InGame Player Data
#include <admin_data>

#include <player_admin>
#include <player_tutorial>
#include <player_vehicle>
#include <player_anims>
#include <player_auth>
#include <player_spawn>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock SetPlayerToTeamColor(playerid)
{
    SetPlayerColor(playerid, COLOR_WHITE);
	if (Admin_IsWorking(playerid))
	{
		SetPlayerColor(playerid, COLOR_ADMIN);
	}
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
