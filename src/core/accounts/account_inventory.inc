#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define INVENTORY_MAX_SLOTS         80
#define INVENTORY_ITEMS_PER_PAGE    20
#define INVENTORY_FIRST_PAGE        0
#define INVENTORY_MAX_PAGES         4
#define INVENTORY_MAX_ITEM_NAME     17
#define INVENTORY_MAX_ITEMS_LIST    13
#define INVENTORY_INVALID_PICKUP    18631

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
enum i_ITEM_LIST
{
    i_ITEM_INVALID,
    i_ITEM_HAMBURGER,
    i_ITEM_PIZZA,
    i_ITEM_CHINESE_FOOD,
    i_ITEM_CEREAL,
    i_ITEM_BURRITO,
    i_ITEM_APPLE_JUICE,
    i_ITEM_ORANGE_JUICE,
    i_ITEM_SODA,
    i_ITEM_MILK,
    i_ITEM_WINE,
    i_ITEM_WHISKY,
    i_ITEM_LIQUOR
};

enum i_INVENTORY_DATA
{
    i_INVENTORY_DB_ID,
    i_ITEM_LIST:i_INVENTORY_ITEM_ID,
    i_INVENTORY_ITEM_QUANTITY,
    i_INVENTORY_ITEM_SLOT
};
static gsPlayerInventory[MAX_PLAYERS][INVENTORY_MAX_SLOTS][i_INVENTORY_DATA];

enum i_RARITY_TYPE
{
    i_RARITY_COMMON,
    i_RARITY_RARE,
    i_RARITY_EPIC,
    i_RARITY_LEGENDARY
};

enum i_ITEM_CATEGORY
{
    i_ITEM_CATEGORY_INVALID,
    i_ITEM_CATEGORY_FOOD,
    i_ITEM_CATEGORY_DRINK
};

enum i_ITEMS_INFO
{
    i_ITEM_LIST:i_ITEM_ID,
    i_ITEM_OBJECT_ID,
    i_ITEM_NAME[INVENTORY_MAX_ITEM_NAME],
    i_RARITY_TYPE:i_ITEM_RARITY,
    i_ITEM_CATEGORY:i_ITEM_TYPE,
};
static gsItemsInfo[INVENTORY_MAX_ITEMS_LIST][i_ITEMS_INFO] =
{
    { i_ITEM_INVALID, INVENTORY_INVALID_PICKUP, "Vazio", i_RARITY_COMMON, i_ITEM_CATEGORY_INVALID },
    { i_ITEM_HAMBURGER, 2880, "Hamburger", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { i_ITEM_PIZZA, 19580, "Pizza", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { i_ITEM_CHINESE_FOOD, 2858, "Comida Chinesa", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { i_ITEM_CEREAL, 2821, "Cereal", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { i_ITEM_BURRITO, 2769, "Burrito", i_RARITY_COMMON, i_ITEM_CATEGORY_FOOD },
    { i_ITEM_APPLE_JUICE, 19564, "Suco de Maca", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { i_ITEM_ORANGE_JUICE, 19563, "Suco de Laranja", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { i_ITEM_SODA, 19835, "Refrigerante", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { i_ITEM_MILK, 19569, "Leite", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { i_ITEM_WINE, 19822, "Vinho", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { i_ITEM_WHISKY, 19824, "Whisky", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK },
    { i_ITEM_LIQUOR, 19823, "Cachaca", i_RARITY_COMMON, i_ITEM_CATEGORY_DRINK }
};

static gsLastTextdrawSelected[MAX_PLAYERS];
static gsInventoryPage[MAX_PLAYERS];
static gsInventorySlotSelected[MAX_PLAYERS];
static gsInventoryTotalValidItems[MAX_PLAYERS];
static bool:gsIsInventoryOpened[MAX_PLAYERS];
static bool:gsInventoryIsSyncDb[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock GetItemRarity(i_ITEM_LIST:itemId)
{
    for (new i; i < INVENTORY_MAX_ITEMS_LIST; i++)
    {
        if (gsItemsInfo[i][i_ITEM_ID] == itemId)
        {
            return gsItemsInfo[i][i_ITEM_RARITY];
        }
    }
    return INVALID_VALUE;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
// ========= INVENTORY DATA ACCESSORS ========= //
// Getters
stock Inventory_GetDbId(playerid, slot)
{
    return gsPlayerInventory[playerid][slot][i_INVENTORY_DB_ID];
}

stock i_ITEM_LIST:Inventory_GetItemId(playerid, slot)
{
    return gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_ID];
}

stock Inventory_GetItemQuantity(playerid, slot)
{
    return gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_QUANTITY];
}

stock Inventory_GetItemSlot(playerid, slot)
{
    return gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_SLOT];
}

// Setters
stock Inventory_SetDbId(playerid, slot, id)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        slot = 0;
    }

    gsPlayerInventory[playerid][slot][i_INVENTORY_DB_ID] = id;
    return 1;
}

stock Inventory_SetItemId(playerid, slot, i_ITEM_LIST:itemId)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        slot = 0;
    }

    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_ID] = itemId;
    return 1;
}

stock Inventory_SetItemQuantity(playerid, slot, quantity)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        slot = 0;
    }

    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_QUANTITY] = quantity;
    return 1;
}

stock Inventory_SetItemSlot(playerid, slot, value)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        slot = 0;
    }

    gsPlayerInventory[playerid][slot][i_INVENTORY_ITEM_SLOT] = value;
    return 1;
}

// ========= INVENTORY MANIPULATION DATA ACCESSORS ========= //
// Getters
stock Inventory_GetTextdrawSelected(playerid)
{
    return gsLastTextdrawSelected[playerid];
}

stock Inventory_GetActualPage(playerid)
{
    return gsInventoryPage[playerid];
}

stock Inventory_GetSlotSelected(playerid)
{
    return gsInventorySlotSelected[playerid];
}

stock Inventory_GetTotalValidItems(playerid)
{
    return gsInventoryTotalValidItems[playerid];
}

stock bool:Inventory_GetIsOpenedStatus(playerid)
{
    return gsIsInventoryOpened[playerid];
}

stock bool:Inventory_GetSyncStatus(playerid)
{
    return gsInventoryIsSyncDb[playerid];
}

// Setters
stock Inventory_SetTextdrawSelected(playerid, index)
{
    gsLastTextdrawSelected[playerid] = index;
    return 1;
}

stock Inventory_SetActualPage(playerid, page)
{
    gsInventoryPage[playerid] = page;
    return 1;
}

stock Inventory_SetSlotSelected(playerid, slot)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        return 0;
    }
    gsInventorySlotSelected[playerid] = slot;
    return 1;
}

stock Inventory_SetTotalValidItems(playerid, quantity)
{
    gsInventoryTotalValidItems[playerid] = quantity;
    return 1;
}

stock Inventory_SetIsOpenedStatus(playerid, bool:status)
{
    gsIsInventoryOpened[playerid] = status;
    return 1;
}

stock Inventory_SetSyncStatus(playerid, bool:status)
{
    gsInventoryIsSyncDb[playerid] = status;
    return 1;
}

// ========= INVENTORY UTILS ACCESSORS ========= //
stock bool:Inventory_ItemExists(i_ITEM_LIST:itemId)
{
    for (new i; i < INVENTORY_MAX_ITEMS_LIST; i++)
    {
        if (gsItemsInfo[i][i_ITEM_ID] == itemId)
        {
            return true;
        }
    }
    return false;
}

stock GetInventoryItemObjectId(i_ITEM_LIST:itemId)
{
    for (new i; i < INVENTORY_MAX_ITEMS_LIST; i++)
    {
        if (gsItemsInfo[i][i_ITEM_ID] == itemId)
        {
            return gsItemsInfo[i][i_ITEM_OBJECT_ID];
        }
    }
    return INVENTORY_INVALID_PICKUP;
}

stock GetInventoryItemName(i_ITEM_LIST:itemId, string[], lenght = sizeof(string))
{
    for (new i; i < INVENTORY_MAX_ITEMS_LIST; i++)
    {
        if (gsItemsInfo[i][i_ITEM_ID] == itemId)
        {
            format(string, lenght, "%s", gsItemsInfo[i][i_ITEM_NAME]);
            return 1;
        }
    }
    format(string, lenght, "Vazio");
    return 1;
}

stock GetInventoryItemRarity(i_ITEM_LIST:itemId)
{
    new string[9];
    switch (GetItemRarity(itemId))
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
            format(string, sizeof(string), "Desconhecido");
        } 
    }
    return string;
}

stock i_ITEM_CATEGORY:GetItemCategory(i_ITEM_LIST:itemId)
{
    for (new i; i < INVENTORY_MAX_ITEMS_LIST; i++)
    {
        if (gsItemsInfo[i][i_ITEM_ID] == itemId)
        {
            return gsItemsInfo[i][i_ITEM_TYPE];
        }
    }
    return i_ITEM_CATEGORY_INVALID;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
