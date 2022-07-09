// Database Player Data
#include <account_general>
#include <account_admin>
#include <account_job>
#include <account_appearence>
#include <account_money>
#include <account_score>
#include <account_vip>
#include <account_status>
#include <account_licenses>
#include <account_config>
#include <account_ban>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    // Reset Player Data
    Player_ResetGeneralData(playerid);
    Player_ResetAdminData(playerid);
    Player_ResetJobData(playerid);
    Player_ResetAppearenceData(playerid);
    Player_ResetMoneyData(playerid);
    Player_ResetScoreData(playerid);
    Player_ResetStatusData(playerid);
    Player_ResetVipData(playerid);
    Player_ResetConfigData(playerid);
    Player_ResetLicensesData(playerid);
    // Admin
    Admin_SetBigEars(playerid, false);
	Admin_SetWorkStatus(playerid, false);
	Admin_SetAfkStatus(playerid, false);
	Admin_SetHideStatus(playerid, false);
	Admin_SetWatchStatus(playerid, false);
	Admin_SetViewAllPm(playerid, false);
    return 1;
}