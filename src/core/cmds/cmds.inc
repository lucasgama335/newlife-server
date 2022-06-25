#include <cmds_general>
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

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
public e_COMMAND_ERRORS:OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
	// if player is not spawned, do not allow him to use commands.
	if(!PlayerData_GetIsLogged(playerid))
	{
		SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o est� logado.");
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
	}    

	// anti command spam
	if(gettime() < cmd_Cooldown[playerid]) 
    {
		SendClientMessage(playerid, COLOR_GRAD1, "Aguarde 2 segundos para digitar novamente um comando!");
		Command_SetDeniedReturn(true);
		return COMMAND_DENIED;
	}

	if (success != COMMAND_OK) 
    {
        new string[134];
		format(string, sizeof(string), "[ALERTA]: O comando que voc� digitou ({33CCFF}%s{FFFFFF}) n�o foi reconhecido, use {33CCFF}/ajuda{FFFFFF}.", cmdtext);
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