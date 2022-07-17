#include <account_inventory>

#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define TEXTDRAW_UNSELECTED_COLOR   1296911746
#define TEXTDRAW_SELECTED_COLOR     -764862851 // 764862721
#define TEXTDRAW_DEFAULT_X_ROT      -10.000000
#define TEXTDRAW_DEFAULT_Z_ROT      -8.000000

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static Float:gsLastPreviewRotX[MAX_PLAYERS];
static Float:gsLastPreviewRotZ[MAX_PLAYERS];
static bool:gsSwapItemsSlots[MAX_PLAYERS];
static bool:gsJoinItems[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ResetInventorySlot(playerid, slot)
{
    Inventory_SetDbId(playerid, slot, INVALID_VALUE);
    Inventory_SetItemId(playerid, slot, i_ITEM_INVALID);
    Inventory_SetItemQuantity(playerid, slot, 0);
    Inventory_SetItemSlot(playerid, slot, INVALID_VALUE);
    return 1;
}

static stock GetInventoryFreeSlot(playerid)
{
    for (new i; i < INVENTORY_MAX_SLOTS; i++)
    {
        if (Inventory_GetItemId(playerid, i) == i_ITEM_INVALID)
        {
            return i;
        }
    }
    return INVALID_VALUE;
}

static stock SyncInventoryDataWithTextdraws(playerid, page)
{
    if (page <= INVENTORY_MAX_PAGES && page >= 0)
    {
        new txtPreviewIndex = 11, txtDescriptionIndex = 47, itemName[INVENTORY_MAX_ITEM_NAME];
        for (new i = (((page + 1) * INVENTORY_ITEMS_PER_PAGE) - INVENTORY_ITEMS_PER_PAGE); i < ((page + 1) * INVENTORY_ITEMS_PER_PAGE); i++)
        {
            if (txtPreviewIndex > 30)
            {
                txtPreviewIndex = 11;
            }   
            if (txtDescriptionIndex > 66)
            {
                txtDescriptionIndex = 47;
            }   
            UpdateInventoryItemPreview(playerid, txtPreviewIndex, GetInventoryItemObjectId(Inventory_GetItemId(playerid, i)), Inventory_GetIsOpenedStatus(playerid));
            if (Inventory_GetItemId(playerid, i) != i_ITEM_INVALID)
            {
                GetInventoryItemName(Inventory_GetItemId(playerid, i), itemName);
                ShowPreviewDescription(playerid, txtDescriptionIndex);
                UpdateInventoryPreviewDesc(playerid, txtDescriptionIndex, itemName, Inventory_GetItemQuantity(playerid, i));
            }
            else
            {
                HidePreviewDescription(playerid, txtDescriptionIndex);
            }
            txtPreviewIndex++;
            txtDescriptionIndex++;
        }
    }
    return 1;
}

static stock UnselectInventoryItem(playerid)
{
    if (Inventory_GetTextdrawSelected(playerid) != INVALID_VALUE)
    {
        UpdateInventoryItemBoxColor(playerid, Inventory_GetTextdrawSelected(playerid), TEXTDRAW_UNSELECTED_COLOR);
    }
    Inventory_SetTextdrawSelected(playerid, INVALID_VALUE);
    Inventory_SetSlotSelected(playerid, INVALID_VALUE);
    return 1;
}

static stock UpdateInventoryTotalItens(playerid, quantity)
{
    Inventory_SetTotalValidItems(playerid, quantity);
    ChangeInventoryTotalItens(playerid, Inventory_GetTotalValidItems(playerid), INVENTORY_MAX_SLOTS);
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock OpenPlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa estar logado para abrir o inventário.");
    }
    if (Inventory_GetIsOpenedStatus(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "O inventário já está aberto.");
    }
    if (!Inventory_GetSyncStatus(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Estamos carregando o seu inventário, aguarde...");
    }   
    // Update Inventory Information
    Inventory_SetIsOpenedStatus(playerid, true);
    Inventory_SetActualPage(playerid, INVENTORY_FIRST_PAGE);
    Inventory_SetTextdrawSelected(playerid, INVALID_VALUE);
    Inventory_SetSlotSelected(playerid, INVALID_VALUE);

    // Show inventory textdraw
    HidePlayerHud(playerid);
    ResetInventoryBoxInfo(playerid);
    SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));
    UpdateInventoryTotalItens(playerid, Inventory_GetTotalValidItems(playerid));
    Inventory_Show(playerid);
    gsLastPreviewRotX[playerid] = TEXTDRAW_DEFAULT_X_ROT;
    gsLastPreviewRotZ[playerid] = TEXTDRAW_DEFAULT_Z_ROT;
    gsSwapItemsSlots[playerid] = false;
    gsJoinItems[playerid] = false;
    if (!IsPlayerInAnyVehicle(playerid))
    {
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_2Idle", 4.1, false, true, true, false, 0);
    }
    return 1;
}

stock ClosePlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa estar logado para fechar o inventário.");
    }
    if (!Inventory_GetIsOpenedStatus(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "O inventário não está aberto.");
    }
    // Update Inventory Information
    Inventory_SetIsOpenedStatus(playerid, false);
    Inventory_SetActualPage(playerid, INVENTORY_FIRST_PAGE);
    Inventory_SetTextdrawSelected(playerid, INVALID_VALUE);
    Inventory_SetSlotSelected(playerid, INVALID_VALUE);

    // Hide inventory textdraw
    ShowPlayerHud(playerid);
    Inventory_Hide(playerid);
    CancelSelectTextDraw(playerid);
    return 1;
}

stock Inventory_AddItem(playerid, i_ITEM_LIST:itemId, quantity)
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

    Inventory_SetItemId(playerid, freeSlot, itemId);
    Inventory_SetItemQuantity(playerid, freeSlot, quantity);
    Inventory_SetItemSlot(playerid, freeSlot, freeSlot);
    
    UpdateInventoryTotalItens(playerid, (Inventory_GetTotalValidItems(playerid) + 1));
    if (Inventory_GetIsOpenedStatus(playerid))
    {
        SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));
    }

    inline const OnItemAddedInDatabase()
    {
        Inventory_SetDbId(playerid, freeSlot, cache_insert_id());
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnItemAddedInDatabase, "INSERT INTO %s (%s, %s, %s, %s) VALUES (%d, %d, %d, %d)", 
    INVENTORY_TABLE_NAME, INVENTORY_FIELD_PLAYER_ID, INVENTORY_FIELD_ITEM_ID, INVENTORY_FIELD_ITEM_QUANTITY, INVENTORY_FIELD_ITEM_SLOT,
    Player_GetId(playerid), itemId, quantity, freeSlot);
    return 1;
}

stock Inventory_UpdateItemQuantity(playerid, itemDbId, slot, quantity)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "O slot informado é inválido.");
        return INVALID_VALUE;
    }
    if (quantity < 0)
    {
        SendClientMessage(playerid, COLOR_INVALID, "Não foi possível adicionar o item, pois a quantidade não foi informada.");
        return INVALID_VALUE;
    }

    Inventory_SetItemQuantity(playerid, slot, quantity);

    new sqlString[70];
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "UPDATE %s SET %s = %d WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ITEM_QUANTITY, quantity, INVENTORY_FIELD_ID, itemDbId);
    mysql_tquery(Database_GetConnection(), sqlString);
    return 1;
}

stock Inventory_RemoveItem(playerid, itemDbId, slot)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "O slot informado é inválido.");
        return INVALID_VALUE;
    }

    HideInventoryItemOptions(playerid);
    UpdateInventoryTotalItens(playerid, (Inventory_GetTotalValidItems(playerid) - 1));

    new sqlString[71];
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "DELETE FROM %s WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ID, itemDbId);
    mysql_tquery(Database_GetConnection(), sqlString);
    return 1;
}   

stock Inventory_SwapItemSlot(playerid, oldSlot, newSlot)
{
    if (oldSlot < 0 || oldSlot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "Slot antigo inválido.");
        return INVALID_VALUE;
    }
    if (newSlot < 0 || newSlot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "Slot novo inválido.");
        return INVALID_VALUE;
    }
    if (Inventory_GetItemId(playerid, newSlot) != i_ITEM_INVALID)
    {
        SendClientMessage(playerid, COLOR_INVALID, "Esse espaço está ocupado por um item, mova-o ou escolha outro espaço.");
        return INVALID_VALUE;
    }

    Inventory_SetDbId(playerid, newSlot, Inventory_GetDbId(playerid, oldSlot));
    Inventory_SetItemId(playerid, newSlot, Inventory_GetItemId(playerid, oldSlot));
    Inventory_SetItemQuantity(playerid, newSlot, Inventory_GetItemQuantity(playerid, oldSlot));
    Inventory_SetItemSlot(playerid, newSlot, Inventory_GetItemSlot(playerid, oldSlot));
    ResetInventorySlot(playerid, oldSlot);
    
    new sqlString[70];
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "UPDATE %s SET %s = %d WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ITEM_SLOT, newSlot, INVENTORY_FIELD_ID, Inventory_GetDbId(playerid, newSlot));
    mysql_tquery(Database_GetConnection(), sqlString);
    return 1;
}

stock Inventory_JoinItemSlot(playerid, toJoinSlot, toRemoveSlot)
{
    if (toJoinSlot < 0 || toJoinSlot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "Slot para juntar inválido.");
        return INVALID_VALUE;
    }
    if (toRemoveSlot < 0 || toRemoveSlot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "Slot a ser removido inválido.");
        return INVALID_VALUE;
    }
    if (Inventory_GetItemId(playerid, toJoinSlot) != Inventory_GetItemId(playerid, toRemoveSlot))
    {
        SendClientMessage(playerid, COLOR_INVALID, "Você só pode juntar itens iguais.");
        return INVALID_VALUE;
    }

    new newQuantity = (Inventory_GetItemQuantity(playerid, toJoinSlot) + Inventory_GetItemQuantity(playerid, toRemoveSlot));
    Inventory_SetItemQuantity(playerid, toJoinSlot, newQuantity);
    
    new sqlString[71];
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "UPDATE %s SET %s = %d WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ITEM_QUANTITY, newQuantity, INVENTORY_FIELD_ID, Inventory_GetDbId(playerid, toJoinSlot));
    mysql_tquery(Database_GetConnection(), sqlString);

    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "DELETE FROM %s WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ID, Inventory_GetDbId(playerid, toRemoveSlot));
    mysql_tquery(Database_GetConnection(), sqlString);

    ResetInventorySlot(playerid, toRemoveSlot);
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    // Reset Inventory Data
    for (new i; i < INVENTORY_MAX_SLOTS; i++)
    {
        ResetInventorySlot(playerid, i);
    }

    // Reset All Textdraw Item Preview
    for (new i = 11; i < 31; i++)
    {
        UpdateInventoryItemPreview(playerid, i, GetInventoryItemObjectId(Inventory_GetItemId(playerid, i)), Inventory_GetIsOpenedStatus(playerid));
    }

    // Reset Inventory Data
    Inventory_SetIsOpenedStatus(playerid, false);
    Inventory_SetSyncStatus(playerid, false);
    Inventory_SetTextdrawSelected(playerid, INVALID_VALUE);
    Inventory_SetActualPage(playerid, INVENTORY_FIRST_PAGE);
    Inventory_SetSlotSelected(playerid, INVALID_VALUE);
    Inventory_SetTotalValidItems(playerid, 0);
    gsSwapItemsSlots[playerid] = false;
    gsJoinItems[playerid] = false;
    return 1;
}

hook OnPlayerPressY(playerid)
{
    if (!Inventory_GetIsOpenedStatus(playerid))
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
        Inventory_SetTotalValidItems(playerid, rows);
        if(rows > 0)
        {
            new dbId, i_ITEM_LIST:itemId, quantity, slot;
            for (new i; i < rows; i++)
            {   
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_SLOT, slot);
                Inventory_SetItemSlot(playerid, slot, slot);

                cache_get_value_name_int(i, INVENTORY_FIELD_ID, dbId);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_ID, itemId);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_QUANTITY, quantity);

                Inventory_SetDbId(playerid, slot, dbId);
                Inventory_SetItemId(playerid, slot, itemId);
                Inventory_SetItemQuantity(playerid, slot, quantity);
            }
        }
        Inventory_SetSyncStatus(playerid, true);
    }
    MySQL_TQueryInline(Database_GetConnection(), using inline OnInventoryLoad, "SELECT * FROM %s WHERE player_id = %d ORDER BY %s ASC LIMIT %d", INVENTORY_TABLE_NAME, Player_GetId(playerid), INVENTORY_FIELD_ITEM_SLOT, INVENTORY_MAX_SLOTS);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Close Button
    if (playertextid == Inventory_GetTextdraw(playerid, 42))
    {
        Inventory_SetIsOpenedStatus(playerid, false);

        UnselectInventoryItem(playerid);
        Inventory_Hide(playerid);
        ShowPlayerHud(playerid);

        CancelSelectTextDraw(playerid);
        return 1;
    }

    // Reset Button
    if (playertextid == Inventory_GetTextdraw(playerid, 9))
    {
        UnselectInventoryItem(playerid);
        HideInventoryItemOptions(playerid);
        ResetInventoryBoxInfo(playerid);
        gsLastPreviewRotX[playerid] = TEXTDRAW_DEFAULT_X_ROT;
        gsLastPreviewRotZ[playerid] = TEXTDRAW_DEFAULT_Z_ROT;
        gsSwapItemsSlots[playerid] = false;
        gsJoinItems[playerid] = false;
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
        new index = GetInventoryTextdrawIndex(playerid, playertextid);
        new slotSelected = ((index - 11) + (Inventory_GetActualPage(playerid) * INVENTORY_ITEMS_PER_PAGE));
        if (index != INVALID_VALUE)
        {
            if (gsSwapItemsSlots[playerid])
            {
                if (Inventory_SwapItemSlot(playerid, Inventory_GetSlotSelected(playerid), slotSelected) != INVALID_VALUE)
                {
                    ResetInventoryBoxInfo(playerid);
                    HideInventoryItemOptions(playerid);
                    UnselectInventoryItem(playerid);
                    SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));
                    gsSwapItemsSlots[playerid] = false;
                    gsJoinItems[playerid] = false;
                }
                return 1;
            }

            if (gsJoinItems[playerid])
            {
                if (Inventory_JoinItemSlot(playerid, slotSelected, Inventory_GetSlotSelected(playerid)) != INVALID_VALUE)
                {
                    ResetInventoryBoxInfo(playerid);
                    HideInventoryItemOptions(playerid);
                    UnselectInventoryItem(playerid);
                    SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));
                    gsSwapItemsSlots[playerid] = false;
                    gsJoinItems[playerid] = false;
                }
                return 1;
            }

            UnselectInventoryItem(playerid);

            Inventory_SetSlotSelected(playerid, slotSelected);
            Inventory_SetTextdrawSelected(playerid, index);

            new itemName[INVENTORY_MAX_ITEM_NAME];
            GetInventoryItemName(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), itemName);

            UpdateInventoryItemBoxColor(playerid, Inventory_GetTextdrawSelected(playerid), TEXTDRAW_SELECTED_COLOR);
            UpdateInventoryBoxInfo(playerid, Inventory_GetSlotSelected(playerid), GetInventoryItemObjectId(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid))), itemName, Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)), GetInventoryItemRarity(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid))));
            Inventory_ShowItemOptions(playerid);

            gsLastPreviewRotX[playerid] = TEXTDRAW_DEFAULT_X_ROT;
            gsLastPreviewRotZ[playerid] = TEXTDRAW_DEFAULT_Z_ROT;
        }
        return 1;
    }

    // Prev Page
    if (playertextid == Inventory_GetTextdraw(playerid, 32))
    {
        // Change Page
        Inventory_SetActualPage(playerid, (Inventory_GetActualPage(playerid) - 1));
        if (Inventory_GetActualPage(playerid) < INVENTORY_FIRST_PAGE)
        {
            Inventory_SetActualPage(playerid, INVENTORY_FIRST_PAGE);
            return SendClientMessage(playerid, COLOR_INVALID, "Você já está na primeira página.");
        }

        UnselectInventoryItem(playerid);
        // ResetInventoryBoxInfo(playerid);
        // HideInventoryItemOptions(playerid);
        gsLastPreviewRotX[playerid] = TEXTDRAW_DEFAULT_X_ROT;
        gsLastPreviewRotZ[playerid] = TEXTDRAW_DEFAULT_Z_ROT;

        UpdateInventoryPageText(playerid, (Inventory_GetActualPage(playerid) + 1), INVENTORY_MAX_PAGES);
        SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));
        return 1;
    }

    // Next Page
    if (playertextid == Inventory_GetTextdraw(playerid, 33))
    {
        // Change Page
        Inventory_SetActualPage(playerid, (Inventory_GetActualPage(playerid) + 1));
        if (Inventory_GetActualPage(playerid) > (INVENTORY_MAX_PAGES - 1))
        {
            Inventory_SetActualPage(playerid, (INVENTORY_MAX_PAGES - 1));
            return SendClientMessage(playerid, COLOR_INVALID, "Você já está na última página");
        }

        UnselectInventoryItem(playerid);
        // ResetInventoryBoxInfo(playerid);
        // HideInventoryItemOptions(playerid);
        gsLastPreviewRotX[playerid] = TEXTDRAW_DEFAULT_X_ROT;
        gsLastPreviewRotZ[playerid] = TEXTDRAW_DEFAULT_Z_ROT;
        
        UpdateInventoryPageText(playerid, (Inventory_GetActualPage(playerid) + 1), INVENTORY_MAX_PAGES);
        SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));
        return 1;
    }

    // Use Item
    if (playertextid == Inventory_GetTextdraw(playerid, 36))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Você deve selecionar um item.");
        }
        if (Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Não há nenhum item para ser usado nesse espaço.");
        }

        new itemQuantity = Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid));
        
        new string[(21 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
        GetInventoryItemName(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), itemName);

        format(string, sizeof(string), "* Você usou o item: %s.", itemName);
        SendClientMessage(playerid, COLOR_YELLOW, string);

        if (itemQuantity <= 1)
        {
            Inventory_RemoveItem(playerid, Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)), Inventory_GetSlotSelected(playerid));
            ResetInventorySlot(playerid, Inventory_GetSlotSelected(playerid));
            ResetInventoryBoxInfo(playerid);
            HidePreviewDescription(playerid, (Inventory_GetTextdrawSelected(playerid) + 36));
            UpdateInventoryItemPreview(playerid, Inventory_GetTextdrawSelected(playerid), GetInventoryItemObjectId(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid))), Inventory_GetIsOpenedStatus(playerid));
            UnselectInventoryItem(playerid);
        }
        else
        {
            Inventory_UpdateItemQuantity(playerid, Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)), Inventory_GetSlotSelected(playerid), (itemQuantity - 1));
            UpdateInventoryBoxInfo(playerid, Inventory_GetSlotSelected(playerid), GetInventoryItemObjectId(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid))), itemName, Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)), GetInventoryItemRarity(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid))));
            UpdateInventoryPreviewDesc(playerid, (Inventory_GetTextdrawSelected(playerid) + 36), itemName, Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)));
        }   
        gsSwapItemsSlots[playerid] = false;
        gsJoinItems[playerid] = false;
        return 1;
    }

    // Organize Inventory
    if (playertextid == Inventory_GetTextdraw(playerid, 8))
    {
        for (new i; i < INVENTORY_MAX_SLOTS; i++)
        {
            if (Inventory_GetDbId(playerid, i) != INVALID_VALUE)
            {
                new newSlot = GetInventoryFreeSlot(playerid);
                if (newSlot < i)
                {
                    Inventory_SwapItemSlot(playerid, i, newSlot);
                }
            }
        }
        ResetInventoryBoxInfo(playerid);
        HideInventoryItemOptions(playerid);
        UnselectInventoryItem(playerid);

        SyncInventoryDataWithTextdraws(playerid, Inventory_GetActualPage(playerid));

        gsSwapItemsSlots[playerid] = false;
        SendClientMessage(playerid, COLOR_YELLOW, "* Inventário organizado.");
        return 1;
    }

    // Remove Item
    if (playertextid == Inventory_GetTextdraw(playerid, 37))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Você deve selecionar um item.");
        }
        if (Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Não há nenhum item para ser usado nesse espaço.");
        }

        new string[(21 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
        GetInventoryItemName(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), itemName);
       
        format(string, sizeof(string), "* Você descartou o item: %s.", itemName);
        SendClientMessage(playerid, COLOR_YELLOW, string);

        Inventory_RemoveItem(playerid, Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)), Inventory_GetSlotSelected(playerid));
        ResetInventorySlot(playerid, Inventory_GetSlotSelected(playerid));
        ResetInventoryBoxInfo(playerid);

        HidePreviewDescription(playerid, (Inventory_GetTextdrawSelected(playerid) + 36));
        UpdateInventoryItemPreview(playerid, Inventory_GetTextdrawSelected(playerid), GetInventoryItemObjectId(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid))), Inventory_GetIsOpenedStatus(playerid));
        
        UnselectInventoryItem(playerid);

        gsSwapItemsSlots[playerid] = false;
        gsJoinItems[playerid] = false;
        return 1;
    }

    // Swap Item Slot
    if (playertextid == Inventory_GetTextdraw(playerid, 41))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Você deve selecionar um item primeiro.");
        }
        gsSwapItemsSlots[playerid] = true;
        gsJoinItems[playerid] = false;
        SendClientMessage(playerid, COLOR_YELLOW, "Selecione um espaço em branco para mudar o item de lugar.");
        return 1;
    }

    // Join Items
    if (playertextid == Inventory_GetTextdraw(playerid, 38))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "Você deve selecionar um item primeiro.");
        }
        gsJoinItems[playerid] = true;
        gsSwapItemsSlots[playerid] = false;
        SendClientMessage(playerid, COLOR_YELLOW, "Selecione o item com o qual você deseja juntar.");
        return 1;
    }

    // Box Preview Rotation (X+)
    if (playertextid == Inventory_GetTextdraw(playerid, 43))
    {
        gsLastPreviewRotX[playerid] += 5.0;
        UpdateBoxPreviewRotation(playerid, gsLastPreviewRotX[playerid], gsLastPreviewRotZ[playerid], Inventory_GetIsOpenedStatus(playerid));
        return 1;
    }

    // Box Preview Rotation (X-)
    if (playertextid == Inventory_GetTextdraw(playerid, 44))
    {
        gsLastPreviewRotX[playerid] -= 5.0;
        UpdateBoxPreviewRotation(playerid, gsLastPreviewRotX[playerid], gsLastPreviewRotZ[playerid], Inventory_GetIsOpenedStatus(playerid));
        return 1;
    }

    // Box Preview Rotation (Z+)
    if (playertextid == Inventory_GetTextdraw(playerid, 45))
    {
        gsLastPreviewRotZ[playerid] += 5.0;
        UpdateBoxPreviewRotation(playerid, gsLastPreviewRotX[playerid], gsLastPreviewRotZ[playerid], Inventory_GetIsOpenedStatus(playerid));
        return 1;
    }

    // Box Preview Rotation (Z-)
    if (playertextid == Inventory_GetTextdraw(playerid, 46))
    {
        gsLastPreviewRotZ[playerid] -= 5.0;
        UpdateBoxPreviewRotation(playerid, gsLastPreviewRotX[playerid], gsLastPreviewRotZ[playerid], Inventory_GetIsOpenedStatus(playerid));
        return 1;
    }
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:inventario(playerid, params[], help)
{
    if (!Inventory_GetIsOpenedStatus(playerid))
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
	new i_ITEM_LIST:itemId, quantity;
	if (sscanf(params, "dd", itemId, quantity))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /pegaritem [id do item] [quantidade]");
	}
    if (!Inventory_ItemExists(itemId))
    {
        return SendClientMessage(playerid, COLOR_GREY, "O item informado é inválido.");
    }
    if (quantity < 0)
    {
        return SendClientMessage(playerid, COLOR_GREY, "Você deve informar uma quantidade para o item.");
    }

    if (Inventory_AddItem(playerid, itemId, quantity) != INVALID_VALUE)
    {   
    	new string[100], itemName[INVENTORY_MAX_ITEM_NAME];
        GetInventoryItemName(itemId, itemName);
        format(string, sizeof(string), "[Aviso]: %s pegou o item %s [%d].", GetPlayerNameCustom(playerid), itemName, itemId);
        SendAdminMessage(COLOR_YELLOW, string, HELPER);
    }
    return 1;
}


YCMD:pegaritems(playerid, params[], help)
{
	if (Player_GetAdminLevel(playerid) < ASPIRANT)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "Você não está em modo trabalho. Use: /trabalhar.");
	}

    Inventory_AddItem(playerid, i_ITEM_HAMBURGER, 1);
    Inventory_AddItem(playerid, i_ITEM_PIZZA, 1);
    Inventory_AddItem(playerid, i_ITEM_CHINESE_FOOD, 1);
    Inventory_AddItem(playerid, i_ITEM_CEREAL, 1);
    Inventory_AddItem(playerid, i_ITEM_BURRITO, 1);
    Inventory_AddItem(playerid, i_ITEM_APPLE_JUICE, 1);
    Inventory_AddItem(playerid, i_ITEM_ORANGE_JUICE, 1);
    Inventory_AddItem(playerid, i_ITEM_SODA, 1);
    Inventory_AddItem(playerid, i_ITEM_MILK, 1);
    Inventory_AddItem(playerid, i_ITEM_WINE, 1);
    Inventory_AddItem(playerid, i_ITEM_WHISKY, 1);
    Inventory_AddItem(playerid, i_ITEM_LIQUOR, 1);
    return 1;
}
