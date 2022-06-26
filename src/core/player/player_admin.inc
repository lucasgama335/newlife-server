#include <admin_cmds_lvl1>
#include <admin_cmds_lvl2>
#include <admin_cmds_lvl3>
#include <admin_cmds_lvl4>
#include <admin_cmds_lvl5>
#include <admin_cmds_lvl6>
#include <admin_cmds_lvl7>
#include <admin_cmds_lvl8>
#include <admin_cmds_lvl9>
#include <admin_cmds_lvl10>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
	Admin_ChangeWorkMode(playerid);
	return 1;
}