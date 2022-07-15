#include <cmds_general>
#include <cmds_vehicles>
#include <cmds_anims>
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
static cmd_Cooldown[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
public e_COMMAND_ERRORS:OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
	// if player is not spawned, do not allow him to use commands.
	if(!Player_GetLoggedStatus(playerid))
	{
		SendClientMessage(playerid, COLOR_INVALID, "Você não está logado.");
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
	}

	if (Server_IsRestarting())
	{
		SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar comandos durante a reinicizalização do servidor.");
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
	}

	if (Player_IsInTutorial(playerid))
	{
		SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar comandos durante o tutorial.");
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
	}    

	// anti command spam
	if(gettime() < cmd_Cooldown[playerid]) 
    {
		SendClientMessage(playerid, COLOR_GRAD1, "Aguarde 2 segundos para digitar novamente um comando.");
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
	}

	if (success != COMMAND_OK) 
    {
        new string[134];
		format(string, sizeof(string), "[ALERTA]: O comando que você digitou ({33CCFF}%s{FFFFFF}) não foi reconhecido, use {33CCFF}/ajuda{FFFFFF}.", cmdtext);
		SendClientMessage(playerid, COLOR_WHITE, string);
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
    }

	//get time data everytime a command is recieved.
	cmd_Cooldown[playerid] = gettime() + 2;
    return COMMAND_OK;
}

public e_COMMAND_ERRORS:OnPlayerCommandPerformed(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
	if (success != COMMAND_OK) 
    {
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
    }
	
	cmd_Cooldown[playerid] = gettime() + 2;
    return COMMAND_OK;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	#pragma unused oldkeys // need this directive, on account of YSI which shows warnings in case the parameter is not used.

	switch (newkeys)
	{
		case KEY_F: 
		{
			if (newkeys == KEY_F && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
			{
				if (Player_GetAnimationStatus(playerid) && IsValidPlayer(playerid))
				{
					Player_SetAnimationStatus(playerid, false);
					ClearAnimations(playerid);
				}
				CallLocalFunction("OnPlayerPressF", "i", playerid);
			}
		}
		case KEY_N: 
		{
			new vehicleid = GetPlayerVehicleID(playerid);
			if (vehicleid != INVALID_VEHICLE_ID && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				Vehicle_SetEngineToPlayer(playerid, vehicleid, (Vehicle_GetEngineStatus(vehicleid) ? false : true));
			}
		}
		case KEY_H:
		{
			if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				if (IsPlayerInGasStation(playerid))
				{
					ShowPlayerGasStationDialog(playerid);
				}
			}
		}
		case KEY_Y:
		{
			if (newkeys == KEY_Y && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
			{
				CallLocalFunction("OnPlayerPressY", "i", playerid);
			}
		}
	}
	return 1;
}

//------------------------- Commands (Module related commands) -------------------------
