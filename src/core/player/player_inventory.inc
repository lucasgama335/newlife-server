#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_INVENTORY_SLOTS         80
#define MAX_ITEMS_PER_PAGE          20
#define INVENTORY_FIRST_PAGE        0
#define MAX_INVENTORY_PAGES         4
#define TEXTDRAW_UNSELECTED_COLOR   1296911746
#define TEXTDRAW_SELECTED_COLOR     -764862721
#define INVENTORY_INVALID_PICKUP    18631
#define MAX_INVENTORY_ITEM_NAME     50
#define MAX_ITEMS_LIST              12

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum i_INVENTORY_DATA
{
    i_INVENTORY_ID,
    i_INVENTORY_ITEM_ID,
    i_INVENTORY_ITEM_QUANTITY,
    i_INVENTORY_ITEM_SLOT
};
static gsPlayerInventory[MAX_PLAYERS][MAX_INVENTORY_SLOTS][i_INVENTORY_DATA];
static gsItemSelect[MAX_PLAYERS];
static gsLastTextdrawSelected[MAX_PLAYERS];
static gsInventoryPage[MAX_PLAYERS];
static gsInventorySlotSelected[MAX_PLAYERS];
static gsInventoryTotalValidItems[MAX_PLAYERS];
static bool:gsIsInventoryOpened[MAX_PLAYERS];
static bool:gsInventoryIsSyncDb[MAX_PLAYERS];


enum i_RARITY_TYPE
{
    i_RARITY_COMMON,
    i_RARITY_RARE,
    i_RARITY_EPIC,
    i_RARITY_LEGENDARY
};

enum i_ITEM_CATEGORY
{
    i_ITEM_CATEGORY_FOOD,
    i_ITEM_CATEGORY_DRINK
};

enum i_ITEMS_DATA
{
    i_ITEM_ID,
    i_ITEM_NAME[MAX_INVENTORY_ITEM_NAME],
    i_RARITY_TYPE:i_ITEM_RARITY,
    i_ITEM_CATEGORY:i_ITEM_TYPE,
};
static gsItemsList[MAX_ITEMS_LIST][i_ITEMS_DATA] =
{
    { 2703, "Hamburger", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { 19580, "Pizza", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { 2858, "Comida Chinesa", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { 2821, "Cereal", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { 2769, "Burrito", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { 19564, "Suco de Maçã", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { 19563, "Suco de Laranja", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { 19835, "Refrigerante", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { 19569, "Leite", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { 19822, "Vinho", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { 19824, "Whisky", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { 19823, "Cachaça", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK }
};

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock OpenPlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa estar logado para abrir o inventário.");
    }
    if (gsIsInventoryOpened[playerid])
    {
        return SendClientMessage(playerid, COLOR_INVALID, "O inventário já está aberto.");
    }
    if (!gsInventoryIsSyncDb[playerid])
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Estamos carregando o seu inventário, aguarde...");
    }   

    HidePlayerHud(playerid);
    Inventory_UpdateBoxInfo(playerid);
    SyncInventoryDataWithTextdraws(playerid, gsInventoryPage[playerid]);
    Inventory_UpdateTotalItens(playerid, gsInventoryTotalValidItems[playerid], MAX_INVENTORY_SLOTS);
    Inventory_Show(playerid);
    gsIsInventoryOpened[playerid] = true;
    gsInventoryPage[playerid] = INVENTORY_FIRST_PAGE;
    gsInventorySlotSelected[playerid] = INVALID_VALUE;
    if (!IsPlayerInAnyVehicle(playerid))
    {
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_2Idle", 4.1, false, true, true, false, 0);
    }
    return 1;
}

static stock ClosePlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa estar logado para fechar o inventário.");
    }
    if (!gsIsInventoryOpened[playerid])
    {
        return SendClientMessage(playerid, -1, "O inventário não está aberto.");
    }

    ShowPlayerHud(playerid);
    Inventory_Hide(playerid);
    CancelSelectTextDraw(playerid);
    gsIsInventoryOpened[playerid] = false;
    gsInventoryPage[playerid] = INVENTORY_FIRST_PAGE;
    gsInventorySlotSelected[playerid] = INVALID_VALUE;
    return 1;
}

static stock UnSelectLastTextdrawSelected(playerid)
{
    if (gsLastTextdrawSelected[playerid] != INVALID_VALUE)
    {
        Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_UNSELECTED_COLOR);
    }
    gsLastTextdrawSelected[playerid] = INVALID_VALUE;
    gsInventorySlotSelected[playerid] = INVALID_VALUE;
    return 1;
}

static stock SyncInventoryDataWithTextdraws(playerid, page)
{
    if (page <= MAX_INVENTORY_PAGES && page >= 0)
    {
        new txtIndex = 11;
        for (new i = (((page + 1) * MAX_ITEMS_PER_PAGE) - MAX_ITEMS_PER_PAGE); i < (((page + 1) * MAX_ITEMS_PER_PAGE) - 1); i++)
        {
            if (txtIndex > 30)
            {
                txtIndex = 11;
            }   
            Inventory_UpdateItemPreview(playerid, txtIndex, gsPlayerInventory[playerid][i][i_INVENTORY_ITEM_ID], gsIsInventoryOpened[playerid]);
            txtIndex++;
        }
    }
    return 1;
}

static stock GetInventoryFreeSlot(playerid)
{
    for (new i; i < MAX_INVENTORY_SLOTS; i++)
    {
        if (gsPlayerInventory[playerid][i][i_INVENTORY_ID] == INVALID_VALUE)
        {
            return i;
        }
    }
    return INVALID_VALUE;
}

static stock ResetInventorySlot(playerid, slot)
{
    gsPlayerInventory[playerid][slot][i_INVENTORY_ID] = INVALID_VALUE;
    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_ID] = INVENTORY_INVALID_PICKUP;
    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_QUANTITY] = 0;
    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_SLOT] = INVALID_VALUE;
    return 1;
}

static stock GetItemRarity(itemId)
{
    for (new i; i < MAX_ITEMS_LIST; i++)
    {
        if (gsItemsList[i][i_ITEM_ID] == itemId)
        {
            return gsItemsList[i][i_ITEM_RARITY];
        }
    }
    return INVALID_VALUE;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Inventory_ResetAllSlots(playerid)
{
    // Reset Inventory Data
    for (new i; i < MAX_INVENTORY_SLOTS; i++)
    {
        ResetInventorySlot(playerid, i);
    }

    // Reset All Textdraw Item Preview
    for (new i = 11; i < 31; i++)
    {
        Inventory_UpdateItemPreview(playerid, i, gsPlayerInventory[playerid][i][i_INVENTORY_ITEM_ID], gsIsInventoryOpened[playerid]);
    }
    return 1;
}

stock bool:IsPlayerInventoryOpened(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return false;
    }
    
    return gsIsInventoryOpened[playerid];
}

stock bool:Inventory_ItemExists(itemId)
{
    for (new i; i < MAX_ITEMS_LIST; i++)
    {
        if (gsItemsList[i][i_ITEM_ID] == itemId)
        {
            return true;
        }
    }
    return false;
}

stock Inventory_AddItem(playerid, itemId, quantity)
{
    if (!Inventory_ItemExists(itemId))
    {
        SendClientMessage(playerid, COLOR_INVALID, "Esse item não existe.");
        return INVALID_VALUE;
    }
    if (quantity < 0)
    {
        SendClientMessage(playerid, COLOR_INVALID, "Não foi possível adicionar o item, pois a quantidade não foi informada.");
        return INVALID_VALUE;
    }
    new freeSlot = GetInventoryFreeSlot(playerid);
    if (freeSlot == INVALID_VALUE)
    {
        SendClientMessage(playerid, COLOR_INVALID, "Não foi possível adicionar o item, pois inventário está cheio.");
        return INVALID_VALUE;
    }

    inline const OnItemAddedInDatabase()
    {
        gsPlayerInventory[playerid][freeSlot][i_INVENTORY_ID] = cache_insert_id();
        gsPlayerInventory[playerid][freeSlot][i_INVENTORY_ITEM_ID] = itemId;
        gsPlayerInventory[playerid][freeSlot][i_INVENTORY_ITEM_QUANTITY] = quantity;
        gsPlayerInventory[playerid][freeSlot][i_INVENTORY_ITEM_SLOT] = freeSlot;
        if (gsIsInventoryOpened[playerid])
        {
            SyncInventoryDataWithTextdraws(playerid, gsInventoryPage[playerid]);
        }
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnItemAddedInDatabase, "INSERT INTO %s (%s, %s, %s, %s) VALUES (%d, %d, %d, %d)", 
    INVENTORY_TABLE_NAME, INVENTORY_FIELD_PLAYER_ID, INVENTORY_FIELD_ITEM_ID, INVENTORY_FIELD_ITEM_QUANTITY, INVENTORY_FIELD_ITEM_SLOT,
    Player_GetId(playerid), itemId, quantity, freeSlot);
    return 1;
}

stock Inventory_SetItemQuantity(playerid, itemDbId, slot, quantity)
{
    if (slot < 0 || slot > MAX_INVENTORY_SLOTS)
    {
        SendClientMessage(playerid, COLOR_INVALID, "O slot informado é inválido.");
        return INVALID_VALUE;
    }
    if (quantity < 0)
    {
        SendClientMessage(playerid, COLOR_INVALID, "Não foi possível adicionar o item, pois a quantidade não foi informada.");
        return INVALID_VALUE;
    }

    new sqlString[70];
    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_QUANTITY] = quantity;
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "UPDATE %s SET %s = %d WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ITEM_QUANTITY, quantity, INVENTORY_FIELD_ID, itemDbId);
    mysql_tquery(Database_GetConnection(), sqlString);
    return 1;
}

stock Inventory_RemoveItem(playerid, itemDbId, slot)
{
    if (slot < 0 || slot > MAX_INVENTORY_SLOTS)
    {
        SendClientMessage(playerid, COLOR_INVALID, "O slot informado é inválido.");
        return INVALID_VALUE;
    }

    new sqlString[71];
    ResetInventorySlot(playerid, slot);
    Inventory_HideItemOptions(playerid);
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "DELETE FROM %s WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ID, itemDbId);
    mysql_tquery(Database_GetConnection(), sqlString);
    return 1;
}   

stock Inventory_GetItemName(itemId, string[], lenght = sizeof(string))
{
    for (new i; i < MAX_ITEMS_LIST; i++)
    {
        if (gsItemsList[i][i_ITEM_ID] == itemId)
        {
            format(string, lenght, "%s", gsItemsList[i][i_ITEM_NAME]);
            return 1;
        }
    }
    format(string, lenght, "Vazio");
    return 1;
}

stock Inventory_GetItemRarity(itemId)
{
    new string[9];
    new rarity = GetItemRarity(itemId);
    switch (rarity)
    {
        case i_RARITY_COMMON:
        {
            format(string, sizeof(string), "Comum");
        }    
        case i_RARITY_RARE:
        {
            format(string, sizeof(string), "Raro");
        }    
        case i_RARITY_EPIC:
        {
            format(string, sizeof(string), "Epico");
        }    
        case i_RARITY_LEGENDARY:
        {
            format(string, sizeof(string), "Lendario");
        }   
        default: 
        {
            format(string, sizeof(string), "Unknown");
        } 
    }
    return string;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    Inventory_ResetAllSlots(playerid);
    gsItemSelect[playerid] = INVALID_VALUE;
    gsLastTextdrawSelected[playerid] = INVALID_VALUE;
    gsIsInventoryOpened[playerid] = false;
    gsInventoryPage[playerid] = INVENTORY_FIRST_PAGE;
    gsInventorySlotSelected[playerid] = INVALID_VALUE;
    gsInventoryIsSyncDb[playerid] = false;
    gsInventoryTotalValidItems[playerid] = 0;
    return 1;
}

hook OnPlayerPressY(playerid)
{
    if (!gsIsInventoryOpened[playerid])
    {
        OpenPlayerInventory(playerid);
    }
    return 1;
}

hook FirstSpawnOnLogin(playerid)
{
    inline const OnInventoryLoad()
    {
        new rows = cache_num_rows();
        gsInventoryTotalValidItems[playerid] = rows;
        if(rows > 0)
        {
            new slot;
            for (new i; i < rows; i++)
            {   
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_SLOT, slot);

                cache_get_value_name_int(i, INVENTORY_FIELD_ID, gsPlayerInventory[playerid][slot][i_INVENTORY_ID]);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_ID, gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_ID]);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_QUANTITY, gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_QUANTITY]);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_SLOT, gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_SLOT]);
            }
        }
        gsInventoryIsSyncDb[playerid] = true;
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnInventoryLoad, "SELECT * FROM %s WHERE player_id = %d ORDER BY %s ASC LIMIT %d", INVENTORY_TABLE_NAME, Player_GetId(playerid), INVENTORY_FIELD_ITEM_SLOT, MAX_INVENTORY_SLOTS);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Close Button
    if (playertextid == Inventory_GetTextdraw(playerid, 41))
    {
        UnSelectLastTextdrawSelected(playerid);
        Inventory_Hide(playerid);
        ShowPlayerHud(playerid);
        CancelSelectTextDraw(playerid);
        gsIsInventoryOpened[playerid] = false;
        return 1;
    }

    // Reset Button
    if (playertextid == Inventory_GetTextdraw(playerid, 9))
    {
        UnSelectLastTextdrawSelected(playerid);
        Inventory_HideItemOptions(playerid);
        Inventory_UpdateBoxInfo(playerid);
        return 1;
    }

    // Select a Item
    if (playertextid == Inventory_GetTextdraw(playerid, 11) || playertextid == Inventory_GetTextdraw(playerid, 12) || playertextid == Inventory_GetTextdraw(playerid, 13)
    || playertextid == Inventory_GetTextdraw(playerid, 14) || playertextid == Inventory_GetTextdraw(playerid, 15) || playertextid == Inventory_GetTextdraw(playerid, 16)
    || playertextid == Inventory_GetTextdraw(playerid, 17) || playertextid == Inventory_GetTextdraw(playerid, 18) || playertextid == Inventory_GetTextdraw(playerid, 19)
    || playertextid == Inventory_GetTextdraw(playerid, 20) || playertextid == Inventory_GetTextdraw(playerid, 21) || playertextid == Inventory_GetTextdraw(playerid, 22)
    || playertextid == Inventory_GetTextdraw(playerid, 23) || playertextid == Inventory_GetTextdraw(playerid, 24) || playertextid == Inventory_GetTextdraw(playerid, 25)
    || playertextid == Inventory_GetTextdraw(playerid, 26) || playertextid == Inventory_GetTextdraw(playerid, 27) || playertextid == Inventory_GetTextdraw(playerid, 28)
    || playertextid == Inventory_GetTextdraw(playerid, 29) || playertextid == Inventory_GetTextdraw(playerid, 30))
    {
        // Get Textdraw index array from textdraw id
        new index = Inventory_GetTextdrawIndex(playerid, playertextid);
        if (index != INVALID_VALUE)
        {
            new itemName[MAX_INVENTORY_ITEM_NAME];
            UnSelectLastTextdrawSelected(playerid);
            // Get Slot selected from pagination calculatations
            gsInventorySlotSelected[playerid] = (index - 11) + (gsInventoryPage[playerid] * MAX_ITEMS_PER_PAGE);
            gsLastTextdrawSelected[playerid] = index;

            Inventory_GetItemName(gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID], itemName);
            Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_SELECTED_COLOR);
            Inventory_UpdateBoxInfoItem(playerid, gsInventorySlotSelected[playerid], gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID], itemName, gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_QUANTITY], Inventory_GetItemRarity(gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID]));
            Inventory_ShowItemOptions(playerid);
            return 1;
        }
    }

    // Prev Page
    if (playertextid == Inventory_GetTextdraw(playerid, 32))
    {
        UnSelectLastTextdrawSelected(playerid);
        Inventory_UpdateBoxInfo(playerid);
        Inventory_HideItemOptions(playerid);

        // Change Page
        gsInventoryPage[playerid] --;
        if (gsInventoryPage[playerid] < INVENTORY_FIRST_PAGE)
        {
            gsInventoryPage[playerid] = INVENTORY_FIRST_PAGE;
            SendClientMessage(playerid, COLOR_INVALID, "Você já está na primeira página.");
        }
        Inventory_UpdatePageText(playerid, (gsInventoryPage[playerid] + 1), MAX_INVENTORY_PAGES);
        SyncInventoryDataWithTextdraws(playerid, gsInventoryPage[playerid]);
    }

    // Next Page
    if (playertextid == Inventory_GetTextdraw(playerid, 33))
    {
        UnSelectLastTextdrawSelected(playerid);
        Inventory_UpdateBoxInfo(playerid);
        Inventory_HideItemOptions(playerid);
        
        gsInventoryPage[playerid] ++;
        if (gsInventoryPage[playerid] > (MAX_INVENTORY_PAGES - 1))
        {
            gsInventoryPage[playerid] = (MAX_INVENTORY_PAGES - 1);
            SendClientMessage(playerid, COLOR_INVALID, "Você já está na última página.");
        }
        Inventory_UpdatePageText(playerid, (gsInventoryPage[playerid] + 1), MAX_INVENTORY_PAGES);
        SyncInventoryDataWithTextdraws(playerid, gsInventoryPage[playerid]);
    }

    // Use Item
    if (playertextid == Inventory_GetTextdraw(playerid, 36))
    {
        if (gsInventorySlotSelected[playerid] == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Você deve selecionar um item.");
        }
        if (gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ID] == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Não há nenhum item para ser usado nesse espaço.");
        }

        new itemQuantity = gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_QUANTITY];
        
        new string[(21 + MAX_INVENTORY_ITEM_NAME)], itemName[MAX_INVENTORY_ITEM_NAME];
        Inventory_GetItemName(gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID], itemName);
        format(string, sizeof(string), "* Você usou o item: %s.", itemName);
        SendClientMessage(playerid, COLOR_YELLOW, string);
        if (itemQuantity <= 1)
        {
            Inventory_RemoveItem(playerid, gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ID], gsInventorySlotSelected[playerid]);
            Inventory_UpdateBoxInfo(playerid);
            Inventory_UpdateItemPreview(playerid, gsLastTextdrawSelected[playerid], gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID], gsIsInventoryOpened[playerid]);
            UnSelectLastTextdrawSelected(playerid);
        }
        else
        {
            Inventory_SetItemQuantity(playerid, gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ID], gsInventorySlotSelected[playerid], (itemQuantity - 1));
            Inventory_UpdateBoxInfoItem(playerid, gsInventorySlotSelected[playerid], gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID], itemName, gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_QUANTITY], Inventory_GetItemRarity(gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID]));
        }   
        return 1;
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:inventario(playerid, params[], help)
{
    if (!gsIsInventoryOpened[playerid])
    {
        OpenPlayerInventory(playerid);
    }
    return 1;
}

YCMD:pegaritem(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está em modo trabalho. Use: /trabalhar.");
	}
	new itemId, quantity;
	if (sscanf(params, "dd", itemId, quantity))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /pegaritem [id do item] [quantidade]");
	}
    if (quantity < 0)
    {
        return SendClientMessage(playerid, COLOR_GREY, "Você deve informar uma quantidade para o item.");
    }

    if (Inventory_AddItem(playerid, itemId, quantity) != INVALID_VALUE)
    {   
    	new string[57];
        format(string, sizeof(string), "[Aviso]: %s pegou o item %d.", GetPlayerNameCustom(playerid), itemId);
        SendAdminMessage(COLOR_YELLOW, string, HELPER);
    }
    return 1;
}