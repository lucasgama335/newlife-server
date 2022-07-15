#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_INVENTORY_SLOTS         80
#define MAX_ITEMS_PER_PAGE          20
#define INVENTORY_FIRST_PAGE        0
#define MAX_INVENTORY_PAGES         4
#define TEXTDRAW_UNSELECTED_COLOR   1296911746
#define TEXTDRAW_SELECTED_COLOR     -764862721
#define INVENTORY_INVALID_PICKUP    18631

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

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowPlayerInventory(playerid)
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
    return 1;
}

static stock HidePlayerInventory(playerid)
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

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Inventory_ResetAllSlots(playerid)
{
    // Reset Inventory Data
    for (new i; i < MAX_INVENTORY_SLOTS; i++)
    {
        gsPlayerInventory[playerid][i][i_INVENTORY_ID] = INVALID_VALUE;
        gsPlayerInventory[playerid][i][i_INVENTORY_ITEM_ID] = INVENTORY_INVALID_PICKUP;
        gsPlayerInventory[playerid][i][i_INVENTORY_ITEM_QUANTITY] = 0;
        gsPlayerInventory[playerid][i][i_INVENTORY_ITEM_SLOT] = INVALID_VALUE;
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
        ShowPlayerInventory(playerid);
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
        // Reset Box Color of last item select
        if (gsLastTextdrawSelected[playerid] != INVALID_VALUE)
        {
            Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_UNSELECTED_COLOR);
        }
        gsLastTextdrawSelected[playerid] = INVALID_VALUE;
        gsInventorySlotSelected[playerid] = INVALID_VALUE;
        Inventory_Hide(playerid);
        ShowPlayerHud(playerid);
        CancelSelectTextDraw(playerid);
        gsIsInventoryOpened[playerid] = false;
        return 1;
    }

    // Reset Button
    if (playertextid == Inventory_GetTextdraw(playerid, 9))
    {
        if (gsLastTextdrawSelected[playerid] != INVALID_VALUE)
        {
            Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_UNSELECTED_COLOR);
        }
        gsLastTextdrawSelected[playerid] = INVALID_VALUE;
        gsInventorySlotSelected[playerid] = INVALID_VALUE;
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
        // Get Slot selected from pagination calculatations
        gsInventorySlotSelected[playerid] = (index - 11) + (gsInventoryPage[playerid] * MAX_ITEMS_PER_PAGE);
        if (index != INVALID_VALUE)
        {
            // Reset Box Color of last item select
            if (gsLastTextdrawSelected[playerid] != INVALID_VALUE)
            {
                Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_UNSELECTED_COLOR);
            }
            gsLastTextdrawSelected[playerid] = index;
            Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_SELECTED_COLOR);
            Inventory_UpdateBoxInfoItem(playerid, gsInventorySlotSelected[playerid], gsPlayerInventory[playerid][gsInventorySlotSelected[playerid]][i_INVENTORY_ITEM_ID], "Desconhecido", 0, "Desconhecida");
            Inventory_ShowItemOptions(playerid);
            return 1;
        }
    }

    // Prev Page
    if (playertextid == Inventory_GetTextdraw(playerid, 32))
    {
        // Reset Box Color of last item select
        if (gsLastTextdrawSelected[playerid] != INVALID_VALUE)
        {
            Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_UNSELECTED_COLOR);
            gsLastTextdrawSelected[playerid] = INVALID_VALUE;
        }

        // Reset Box Info
        Inventory_UpdateBoxInfo(playerid);
        Inventory_HideItemOptions(playerid);

        // Change Page
        gsInventorySlotSelected[playerid] = INVALID_VALUE;
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
        // Reset Box Color of last item select
        if (gsLastTextdrawSelected[playerid] != INVALID_VALUE)
        {
            Inventory_ChangeItemBoxColor(playerid, gsLastTextdrawSelected[playerid], TEXTDRAW_UNSELECTED_COLOR);
            gsLastTextdrawSelected[playerid] = INVALID_VALUE;
        }

        // Reset Box Info
        Inventory_UpdateBoxInfo(playerid);
        Inventory_HideItemOptions(playerid);
        
        gsInventorySlotSelected[playerid] = INVALID_VALUE;
        gsInventoryPage[playerid] ++;
        if (gsInventoryPage[playerid] > (MAX_INVENTORY_PAGES - 1))
        {
            gsInventoryPage[playerid] = (MAX_INVENTORY_PAGES - 1);
            SendClientMessage(playerid, COLOR_INVALID, "Você já está na última página.");
        }
        Inventory_UpdatePageText(playerid, (gsInventoryPage[playerid] + 1), MAX_INVENTORY_PAGES);
        SyncInventoryDataWithTextdraws(playerid, gsInventoryPage[playerid]);
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:inventario(playerid, params[], help)
{
    if (!gsIsInventoryOpened[playerid])
    {
        ShowPlayerInventory(playerid);
    }
    return 1;
}