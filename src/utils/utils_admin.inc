#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsAdminRole[MAX_ADMIN_ROLES][] = { "Nenhum", "Estagiário", "Ajudante", "Moderador", "Supervisor", "Master", "Master +", "Master ++", "Gerente", "Sub-Dono", "Dono" };

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock GetAdminRoleName(role, string[], lenght = sizeof(string))
{
    format(string, lenght, "%s", gsAdminRole[role]);
    return 1;
}

stock Admin_SendPrivateMessage(playerid, id, COLOR, const string[])
{
	SendClientMessage(id, COLOR, string);
	foreach(new i: Player)
	{
		if (Player_GetAdminLevel(playerid) >= SUB_OWNER && Admin_GetViewAllPm(i) && playerid != i)
		{
			SendClientMessage(i, COLOR, string);
		}
	}
	return 1;
}

stock SendAdminMessage(COLOR, const string[], e_ADMIN_LEVELS:level)
{
	foreach(new i: Player)
	{
		if (Player_GetAdminLevel(i) >= level)
		{
			SendClientMessage(i, COLOR, string);
		}
	}
	return 1;
}

stock GetOnlineAdmins(bool:work)
{
	new total = 0;
	foreach(new i : Player)
	{
		if (work)
		{
			if (Player_GetAdminLevel(i) >= HELPER && Admin_GetWorkStatus(playerid) && !Admin_GetHideStatus(playerid))
			{
				total ++;
			}
		}
		else
		{
			if (Player_GetAdminLevel(i) >= HELPER && !Admin_GetHideStatus(playerid))
			{
				total ++;
			}
		}
	}
	return total;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
