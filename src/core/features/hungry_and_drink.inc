#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsUpdateHungryAndDrink[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------
timer UpdateHungryAndDrink[300000](playerid)
{
    // Hungry
    new hungryQuantity = (Player_GetHungry(playerid) - (1 + random(1)));
    if (hungryQuantity < 0)
    {   
        hungryQuantity = 0;
    }
    if (Player_GetHungry(playerid) <= 10)
    {
		SendClientMessage(playerid, COLOR_INVALID, "* Você está com muita fome, coma algo ou morrerá de fome!");
    }
    Player_SetHungry(playerid, hungryQuantity);

    // Drink
    new drinkQuantity = (Player_GetDrink(playerid) - (1 + random(2)));
    if (drinkQuantity < 0)
    {   
        drinkQuantity = 0;
    }
    if (Player_GetDrink(playerid) <= 10)
    {
		SendClientMessage(playerid, COLOR_INVALID, "* Você está com muita sede, beba algo ou morrerá de sede.");
    }
    Player_SetDrink(playerid, drinkQuantity);

    // Decrease Life
    if (Player_GetHungry(playerid) <= 0 && Player_GetDrink(playerid) <= 0)
    {
        new Float:playerHealth;
        GetPlayerHealth(playerid, playerHealth);
        new Float:decreaseHealth = (playerHealth - 10);
        if (decreaseHealth > 5.0)
        {
            SetPlayerHealth(playerid, decreaseHealth);
        }
    }
    else if (Player_GetHungry(playerid) <= 0 || Player_GetDrink(playerid) <= 0)
    {
        new Float:playerHealth;
        GetPlayerHealth(playerid, playerHealth);
        new Float:decreaseHealth = (playerHealth - 5);
        if (decreaseHealth > 5.0)
        {
            SetPlayerHealth(playerid, decreaseHealth);
        }
    }
    return 1;
}
//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook FirstSpawnOnLogin(playerid)
{
    if (Timer_IsRunning(gsUpdateHungryAndDrink[playerid]))
    {
        stop gsUpdateHungryAndDrink[playerid];
    }
    gsUpdateHungryAndDrink[playerid] = repeat UpdateHungryAndDrink(playerid);
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
