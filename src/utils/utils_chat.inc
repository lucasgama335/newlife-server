#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

// Send Messsage Chat to Near Players
stock SendMessageInRange(Float:range, playerid, const string[], col1, col2, col3, col4, col5)
{
	if (IsPlayerConnected(playerid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		foreach(new i: Player)
		{
            if (!Admin_HasBigEars(playerid))
            {
                GetPlayerPos(i, posx, posy, posz);
                tempposx = (oldposx -posx);
                tempposy = (oldposy -posy);
                tempposz = (oldposz -posz);
                if (((tempposx < range/16) && (tempposx > -range/16)) && ((tempposy < range/16) && (tempposy > -range/16)) && ((tempposz < range/16) && (tempposz > -range/16)))
                {
                    SendClientMessage(i, col1, string);
                }
                else if (((tempposx < range/8) && (tempposx > -range/8)) && ((tempposy < range/8) && (tempposy > -range/8)) && ((tempposz < range/8) && (tempposz > -range/8)))
                {
                    SendClientMessage(i, col2, string);
                }
                else if (((tempposx < range/4) && (tempposx > -range/4)) && ((tempposy < range/4) && (tempposy > -range/4)) && ((tempposz < range/4) && (tempposz > -range/4)))
                {
                    SendClientMessage(i, col3, string);
                }
                else if (((tempposx < range/2) && (tempposx > -range/2)) && ((tempposy < range/2) && (tempposy > -range/2)) && ((tempposz < range/2) && (tempposz > -range/2)))
                {
                    SendClientMessage(i, col4, string);
                }
                else if (((tempposx < range) && (tempposx > -range)) && ((tempposy < range) && (tempposy > -range)) && ((tempposz < range) && (tempposz > -range)))
                {
                    SendClientMessage(i, col5, string);
                }
            }
            else
            {
                SendClientMessage(i, col1, string);
            }
		}
	}
	return 1;
}

stock ClearChatBox(playerid, lines)
{
    if (IsPlayerConnected(playerid))
	{
		for (new i = 0; i < lines; i++)
		{
			SendClientMessage(playerid, -1, " ");
		}
	}
	return 1;
}