#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsUpdatePlayerNeedsTimer[MAX_PLAYERS];

enum f_LIST_INFO
{
    Float:f_POS_X,
    Float:f_POS_Y,
    Float:f_POS_Z,
    f_VIRTUAL_WORLD
};
static gsFoodBarList[][f_LIST_INFO] =
{
    { 815.7295, -1354.0405, 13.5378, 0 }, // Spawn
    { 300.1892, -1911.9113, 3.1653, 0 } // Beach Party
};

enum d_LIST_INFO
{
    Float:d_POS_X,
    Float:d_POS_Y,
    Float:d_POS_Z,
    d_VIRTUAL_WORLD
};
static gsDrinkBarList[][d_LIST_INFO] =
{
    { 811.8157, -1354.0371, 13.5378, 0 }, // Spawn
    { 319.5235, -1908.9147, 3.1653, 0 } // Beach Party
};

//------------------------- Timers (Timers used in the module.) -------------------------
function:UpdateHungryAndDrink(playerid)
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
static stock ShowFoodDialog(playerid)
{
    new StrCat[194 + 1];
	strcat(StrCat, "Item\tPreço\n");
 	strcat(StrCat, "{FFFFFF}Hamburger\tR$ {33AA33}15,00\n");
 	strcat(StrCat, "{FFFFFF}Pizza\tR$ {33AA33}30,00\n");
 	strcat(StrCat, "{FFFFFF}Comida Chinesa\tR$ {33AA33}30,00\n");
 	strcat(StrCat, "{FFFFFF}Cereal\tR$ {33AA33}10,00\n");
    strcat(StrCat, "{FFFFFF}Burrito\tR$ {33AA33}12,00\n");
	ShowPlayerDialog(playerid, DIALOG_FOOD_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Cardápio de Comidas", StrCat, "Comprar", "Fechar");
    return 1;
}

static stock ShowDrinkDialog(playerid)
{
    new StrCat[268 + 1];
	strcat(StrCat, "Item\tPreço\n");
 	strcat(StrCat, "{FFFFFF}Suco de Maçã\tR$ {33AA33}5,00\n");
 	strcat(StrCat, "{FFFFFF}Suco de Laranja\tR$ {33AA33}5,00\n");
 	strcat(StrCat, "{FFFFFF}Refrigerante\tR$ {33AA33}10,00\n");
 	strcat(StrCat, "{FFFFFF}Leite\tR$ {33AA33}5,00\n");
    strcat(StrCat, "{FFFFFF}Vinho\tR$ {33AA33}20,00\n");
    strcat(StrCat, "{FFFFFF}Whisky\tR$ {33AA33}30,00\n");
    strcat(StrCat, "{FFFFFF}Cachaça\tR$ {33AA33}15,00\n");
	ShowPlayerDialog(playerid, DIALOG_DRINK_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Cardápio de Bebidas", StrCat, "Comprar", "Fechar");
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    for (new i; i < sizeof(gsFoodBarList); i++)
    {
		CreateDynamic3DTextLabel("{FFFFFF}Cardápio de Comidas\n{B4B5B7}Para Ver as Opções\nAperte '{FFFFFF}F{B4B5B7}'", COLOR_GRAD1, gsFoodBarList[i][f_POS_X], gsFoodBarList[i][f_POS_Y], gsFoodBarList[i][f_POS_Z], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, gsFoodBarList[i][f_VIRTUAL_WORLD]);
		CreateDynamicPickup(2768, 23, gsFoodBarList[i][f_POS_X], gsFoodBarList[i][f_POS_Y], gsFoodBarList[i][f_POS_Z], gsFoodBarList[i][f_VIRTUAL_WORLD]);
    }

    for (new i; i < sizeof(gsDrinkBarList); i++)
    {
		CreateDynamic3DTextLabel("{FFFFFF}Cardápio de Bebidas\n{B4B5B7}Para Ver as Opções\nAperte '{FFFFFF}F{B4B5B7}'", COLOR_GRAD1, gsDrinkBarList[i][d_POS_X], gsDrinkBarList[i][d_POS_Y], gsDrinkBarList[i][d_POS_Z], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, gsDrinkBarList[i][d_VIRTUAL_WORLD]);
		CreateDynamicPickup(1484, 23, gsDrinkBarList[i][d_POS_X], gsDrinkBarList[i][d_POS_Y], gsDrinkBarList[i][d_POS_Z], gsDrinkBarList[i][d_VIRTUAL_WORLD]);
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    gsUpdatePlayerNeedsTimer[playerid] = INVALID_VALUE;
    return 1;
}

hook OnPlayerDisconnect(playerid)
{
    if (gsUpdatePlayerNeedsTimer[playerid] != INVALID_VALUE)
    {
        KillTimer(gsUpdatePlayerNeedsTimer[playerid]);
        gsUpdatePlayerNeedsTimer[playerid] = INVALID_VALUE;
    }
    return 1;
}

hook FirstSpawnOnLogin(playerid)
{
    if (gsUpdatePlayerNeedsTimer[playerid] != INVALID_VALUE)
    {
        KillTimer(gsUpdatePlayerNeedsTimer[playerid]);
        gsUpdatePlayerNeedsTimer[playerid] = INVALID_VALUE;
    }
    gsUpdatePlayerNeedsTimer[playerid] = SetTimerEx("UpdateHungryAndDrink", 300000, true, "i", playerid);
    return 1;
}

hook OnPlayerPressF(playerid)
{
    for (new i; i < sizeof(gsFoodBarList); i++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, gsFoodBarList[i][f_POS_X], gsFoodBarList[i][f_POS_Y], gsFoodBarList[i][f_POS_Z]))
        {
            ShowFoodDialog(playerid);
            return 1;
        }
    }

    for (new i; i < sizeof(gsDrinkBarList); i++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, gsDrinkBarList[i][d_POS_X], gsDrinkBarList[i][d_POS_Y], gsDrinkBarList[i][d_POS_Z]))
        {
            ShowDrinkDialog(playerid);
            return 1;
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    #pragma unused inputtext // need this directive, on account of YSI which shows warnings in case the parameter is not used.
   
    switch (dialogid)
    {
        case DIALOG_FOOD_LIST:
        {
            if (!response)
            {
                return 1;
            }
            if (response)
            {
                switch (listitem)
                {
                    // Hamburger
                    case 0:
                    {
                        if (Player_GetMoney(playerid) < 15)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_HAMBURGER, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_HAMBURGER, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 15));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 15,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Pizza
                    case 1:
                    {
                        if (Player_GetMoney(playerid) < 30)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_PIZZA, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_PIZZA, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 30));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 30,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Chinese Food
                    case 2:
                    {
                        if (Player_GetMoney(playerid) < 30)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_CHINESE_FOOD, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_CHINESE_FOOD, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 30));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 30,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Cereal
                    case 3:
                    {
                        if (Player_GetMoney(playerid) < 10)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_CEREAL, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_CEREAL, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 10));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 10,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Burrito
                    case 4:
                    {
                        if (Player_GetMoney(playerid) < 12)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_BURRITO, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_BURRITO, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 12));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 12,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }
                }
            }
        }

        case DIALOG_DRINK_LIST:
        {
            if (!response)
            {
                return 1;
            }
            if (response)
            {
                switch (listitem)
                {
                    // Suco de Maçã
                    case 0:
                    {
                        if (Player_GetMoney(playerid) < 5)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_APPLE_JUICE, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_APPLE_JUICE, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 5));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 5,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Suco de Laranja
                    case 1:
                    {
                        if (Player_GetMoney(playerid) < 5)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_ORANGE_JUICE, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_ORANGE_JUICE, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 5));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 5,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Refrigerante
                    case 2:
                    {
                        if (Player_GetMoney(playerid) < 10)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_SODA, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_SODA, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 10));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 10,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Leite 
                    case 3:
                    {
                        if (Player_GetMoney(playerid) < 5)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_MILK, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_MILK, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 5));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 5,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Vinho
                    case 4:
                    {
                        if (Player_GetMoney(playerid) < 20)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_WINE, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_WINE, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 20));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 20,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Whisky
                    case 5:
                    {
                        if (Player_GetMoney(playerid) < 30)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_WHISKY, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_WHISKY, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 30));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 30,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Cachaça
                    case 6:
                    {
                        if (Player_GetMoney(playerid) < 15)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Você não possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_LIQUOR, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_LIQUOR, itemName);
                            Player_SetMoney(playerid, (Player_GetMoney(playerid) - 15));
                            format(string, sizeof(string), "Você comprou um(a): %s por R$ 15,00, e o produto foi adicionado ao seu inventário.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }
                }
            }
        } 
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
