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
static cmd_Cooldown[MAX_PLAYERS], cmd_Count[MAX_PLAYERS];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
public OnPlayerCommandReceived(playerid, cmd[])
{
	// if player is not spawned, do not allow him to use commands.
	if(!PlayerData_GetIsLogged(playerid)) return 0;
    
    // anti command spam
	if(gettime() < cmd_Cooldown[playerid]) 
    {
		cmd_Count[playerid] ++;

		if(cmd_Count[playerid] >= 2) 
        {
	 		SendClientMessage(playerid, COLOR_GRAD1, "Aguarde 2 segundos para digitar novamente um comando!");
	 		return 0;
		}
	}
	else 
    {
		if(cmd_Count[playerid] > 0) 
        {
			cmd_Count[playerid] --;
		}
	}

	//get time data everytime a command is recieved.
	cmd_Cooldown[playerid] = gettime() + 2;
    return 1;
}

public OnPlayerCmdWork(playerid, cmd[], success) 
{
    if (!success) 
    {
        static string[134];
		format(string, sizeof(string), "[ALERTA]: O comando que você digitou ({33CCFF}%s{FFFFFF}) não foi reconhecido, use {33CCFF}/ajuda{FFFFFF}.", cmd);
		SendClientMessage(playerid, COLOR_WHITE, string);
		return 1;
    }

    //get time data everytime a command is performed.
    cmd_Cooldown[playerid] = gettime() + 3;
    return 1;
}