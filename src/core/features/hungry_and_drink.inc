#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_FOOD_BAR_LIST    1
#define MAX_DRINK_BAR_LIST   1

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Timer:gsUpdateHungryAndDrink[MAX_PLAYERS];

enum f_LIST_INFO
{
    Float:f_POS_X,
    Float:f_POS_Y,
    Float:f_POS_Z,
    f_VIRTUAL_WORLD
};
static gsFoodBarList[MAX_FOOD_BAR_LIST][f_LIST_INFO] =
{
    { 815.7295, -1354.0405, 13.5378, 0 }
};

enum d_LIST_INFO
{
    Float:d_POS_X,
    Float:d_POS_Y,
    Float:d_POS_Z,
    d_VIRTUAL_WORLD
};
static gsDrinkBarList[MAX_DRINK_BAR_LIST][d_LIST_INFO] =
{
    { 811.8157, -1354.0371, 13.5378, 0 }
};

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
		SendClientMessage(playerid, COLOR_INVALID, "* Voc� est� com muita fome, coma algo ou morrer� de fome!");
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
		SendClientMessage(playerid, COLOR_INVALID, "* Voc� est� com muita sede, beba algo ou morrer� de sede.");
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
	strcat(StrCat, "Item\tPre�o\n");
 	strcat(StrCat, "{FFFFFF}Hamburger\tR$ {00FF00}15,00\n");
 	strcat(StrCat, "{FFFFFF}Pizza\tR$ {00FF00}30,00\n");
 	strcat(StrCat, "{FFFFFF}Comida Chinesa\tR$ {00FF00}30,00\n");
 	strcat(StrCat, "{FFFFFF}Cereal\tR$ {00FF00}10,00\n");
    strcat(StrCat, "{FFFFFF}Burrito\tR$ {00FF00}12,00\n");
	ShowPlayerDialog(playerid, DIALOG_FOOD_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Card�pio de Comidas", StrCat, "Comprar", "Fechar");
    return 1;
}

static stock ShowDrinkDialog(playerid)
{
    new StrCat[268 + 1];
	strcat(StrCat, "Item\tPre�o\n");
 	strcat(StrCat, "{FFFFFF}Suco de Ma��\tR$ {00FF00}5,00\n");
 	strcat(StrCat, "{FFFFFF}Suco de Laranja\tR$ {00FF00}5,00\n");
 	strcat(StrCat, "{FFFFFF}Refrigerante\tR$ {00FF00}10,00\n");
 	strcat(StrCat, "{FFFFFF}Leite\tR$ {00FF00}5,00\n");
    strcat(StrCat, "{FFFFFF}Vinho\tR$ {00FF00}20,00\n");
    strcat(StrCat, "{FFFFFF}Whisky\tR$ {00FF00}30,00\n");
    strcat(StrCat, "{FFFFFF}Cacha�a\tR$ {00FF00}15,00\n");
	ShowPlayerDialog(playerid, DIALOG_DRINK_LIST, DIALOG_STYLE_TABLIST_HEADERS, "Card�pio de Bebidas", StrCat, "Comprar", "Fechar");
    return 1;
}

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

hook OnPlayerPressF(playerid)
{
    for (new i; i < MAX_FOOD_BAR_LIST; i++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, gsFoodBarList[i][f_POS_X], gsFoodBarList[i][f_POS_Y], gsFoodBarList[i][f_POS_Z]))
        {
            ShowFoodDialog(playerid);
        }
    }

    for (new i; i < MAX_DRINK_BAR_LIST; i++)
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, gsDrinkBarList[i][d_POS_X], gsDrinkBarList[i][d_POS_Y], gsDrinkBarList[i][d_POS_Z]))
        {
            ShowDrinkDialog(playerid);
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
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_HAMBURGER, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_HAMBURGER, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 15));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 15,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Pizza
                    case 1:
                    {
                        if (Player_GetMoney(playerid) < 30)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_PIZZA, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_PIZZA, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 30));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 30,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Chinese Food
                    case 2:
                    {
                        if (Player_GetMoney(playerid) < 30)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_CHINESE_FOOD, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_CHINESE_FOOD, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 30));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 30,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Cereal
                    case 3:
                    {
                        if (Player_GetMoney(playerid) < 10)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_CEREAL, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_CEREAL, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 10));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 10,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Burrito
                    case 4:
                    {
                        if (Player_GetMoney(playerid) < 12)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_BURRITO, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_BURRITO, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 12));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 12,00, e o produto foi adicionado ao seu invent�rio.", itemName);
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
                    // Suco de Ma��
                    case 0:
                    {
                        if (Player_GetMoney(playerid) < 5)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_APPLE_JUICE, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_APPLE_JUICE, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 5));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 5,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Suco de Laranja
                    case 1:
                    {
                        if (Player_GetMoney(playerid) < 5)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_ORANGE_JUICE, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_ORANGE_JUICE, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 5));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 5,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Refrigerante
                    case 2:
                    {
                        if (Player_GetMoney(playerid) < 10)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_SODA, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_SODA, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 10));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 10,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Leite 
                    case 3:
                    {
                        if (Player_GetMoney(playerid) < 5)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_MILK, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_MILK, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 5));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 5,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Vinho
                    case 4:
                    {
                        if (Player_GetMoney(playerid) < 20)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_WINE, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_WINE, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 20));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 20,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Whisky
                    case 5:
                    {
                        if (Player_GetMoney(playerid) < 30)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_WHISKY, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_WHISKY, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 30));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 30,00, e o produto foi adicionado ao seu invent�rio.", itemName);
                            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                            return 1;
                        }
                    }

                    // Cacha�a
                    case 6:
                    {
                        if (Player_GetMoney(playerid) < 15)
                        {
                            return SendClientMessage(playerid, COLOR_INVALID, "Voc� n�o possui dinheiro suficiente para comprar esse item.");
                        }

                        if (Inventory_AddItem(playerid, i_ITEM_LIQUOR, 1))
                        {
                            new string[(80 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                            GetInventoryItemName(i_ITEM_LIQUOR, itemName);
                            SetPlayerMoneyCustom(playerid, (Player_GetMoney(playerid) - 15));
                            format(string, sizeof(string), "Voc� comprou um(a): %s por R$ 15,00, e o produto foi adicionado ao seu invent�rio.", itemName);
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

hook OnGameModeInit()
{

    for (new i; i < MAX_FOOD_BAR_LIST; i++)
    {
		Create3DTextLabel("{FFFFFF}Card�pio de Comidas\n{B4B5B7}Para Ver as Op��es\nAperte '{FFFFFF}F{B4B5B7}'", COLOR_GRAD1, gsFoodBarList[i][f_POS_X], gsFoodBarList[i][f_POS_Y], gsFoodBarList[i][f_POS_Z], 10.0, gsFoodBarList[i][f_VIRTUAL_WORLD]);
		AddStaticPickup(2768, 23, gsFoodBarList[i][f_POS_X], gsFoodBarList[i][f_POS_Y], gsFoodBarList[i][f_POS_Z], gsFoodBarList[i][f_VIRTUAL_WORLD]);
    }

    for (new i; i < MAX_DRINK_BAR_LIST; i++)
    {
		Create3DTextLabel("{FFFFFF}Card�pio de Bebidas\n{B4B5B7}Para Ver as Op��es\nAperte '{FFFFFF}F{B4B5B7}'", COLOR_GRAD1, gsDrinkBarList[i][d_POS_X], gsDrinkBarList[i][d_POS_Y], gsDrinkBarList[i][d_POS_Z], 10.0, gsDrinkBarList[i][d_VIRTUAL_WORLD]);
		AddStaticPickup(1484, 23, gsDrinkBarList[i][d_POS_X], gsDrinkBarList[i][d_POS_Y], gsDrinkBarList[i][d_POS_Z], gsDrinkBarList[i][d_VIRTUAL_WORLD]);
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------