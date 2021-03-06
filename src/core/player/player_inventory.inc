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

static stock UpdateInventorySlot(playerid, textdrawIndex, slot)
{
    new itemName[INVENTORY_MAX_ITEM_NAME];
    GetInventoryItemName(Inventory_GetItemId(playerid, slot), itemName);
    UpdateInventoryPreviewDesc(playerid, (textdrawIndex + 36), itemName, Inventory_GetItemQuantity(playerid, slot));
    if (Inventory_GetItemId(playerid, slot) == i_ITEM_INVALID)
    {
        HidePreviewDescription(playerid, (textdrawIndex + 36));
    }
    else
    {
        ShowPreviewDescription(playerid, (textdrawIndex + 36));
    }
    UpdateInventoryItemPreview(playerid, textdrawIndex, GetInventoryItemObjectId(Inventory_GetItemId(playerid, slot)), Inventory_GetIsOpenedStatus(playerid));
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock OpenPlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� precisa estar logado para abrir o invent�rio.");
    }
    if (Inventory_GetIsOpenedStatus(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O invent�rio j� est� aberto.");
    }
    if (!Inventory_GetSyncStatus(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Estamos carregando o seu invent�rio, aguarde...");
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
    UpdateInventoryPageText(playerid, (Inventory_GetActualPage(playerid) + 1), INVENTORY_MAX_PAGES);
    Inventory_Show(playerid);
    gsLastPreviewRotX[playerid] = TEXTDRAW_DEFAULT_X_ROT;
    gsLastPreviewRotZ[playerid] = TEXTDRAW_DEFAULT_Z_ROT;
    gsSwapItemsSlots[playerid] = false;
    gsJoinItems[playerid] = false;
    if (!IsPlayerInAnyVehicle(playerid))
    {
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_2Idle", 4.1, false, true, true, false, 0);
    }
    new string[47];
    format(string, sizeof(string), "* %s abriu o invent�rio.", GetPlayerNameCustom(playerid));
    SendMessageInRange(20.0, playerid, string, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU, COLOR_LIGHTPU);
    return 1;
}

stock ClosePlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� precisa estar logado para fechar o invent�rio.");
    }
    if (!Inventory_GetIsOpenedStatus(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: O invent�rio n�o est� aberto.");
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
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Esse item n�o existe.");
        return INVALID_VALUE;
    }
    if (quantity < 0)
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: N�o foi poss�vel adicionar o item, pois a quantidade n�o foi informada.");
        return INVALID_VALUE;
    }
    new freeSlot = GetInventoryFreeSlot(playerid);
    if (freeSlot == INVALID_VALUE)
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: N�o foi poss�vel adicionar o item, pois invent�rio est� cheio.");
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

stock Inventory_UpdateItemQuantity(playerid, slot, quantity)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: O slot informado � inv�lido.");
        return INVALID_VALUE;
    }
    if (quantity < 0)
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: N�o foi poss�vel atualizar o item, pois a quantidade n�o foi informada.");
        return INVALID_VALUE;
    }

    Inventory_SetItemQuantity(playerid, slot, quantity);

    new sqlString[70];
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "UPDATE %s SET %s = %d WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ITEM_QUANTITY, quantity, INVENTORY_FIELD_ID, Inventory_GetDbId(playerid, slot));
    mysql_tquery(Database_GetConnection(), sqlString);
    return 1;
}

stock Inventory_RemoveItem(playerid, itemDbId, slot)
{
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: O slot informado � inv�lido.");
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
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Slot antigo inv�lido.");
        return INVALID_VALUE;
    }
    if (newSlot < 0 || newSlot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Slot novo inv�lido.");
        return INVALID_VALUE;
    }
    if (Inventory_GetItemId(playerid, newSlot) != i_ITEM_INVALID)
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Esse espa�o est� ocupado por um item, escolha um espa�o vazio.");
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
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Slot para juntar inv�lido.");
        return INVALID_VALUE;
    }
    if (toRemoveSlot < 0 || toRemoveSlot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Slot a ser removido inv�lido.");
        return INVALID_VALUE;
    }
    if (Inventory_GetItemId(playerid, toJoinSlot) != Inventory_GetItemId(playerid, toRemoveSlot))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� s� pode juntar itens iguais.");
        return INVALID_VALUE;
    }

    new newQuantity = (Inventory_GetItemQuantity(playerid, toJoinSlot) + Inventory_GetItemQuantity(playerid, toRemoveSlot));
    Inventory_SetItemQuantity(playerid, toJoinSlot, newQuantity);
    UpdateInventoryTotalItens(playerid, (Inventory_GetTotalValidItems(playerid) - 1));
    
    new sqlString[71];
    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "UPDATE %s SET %s = %d WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ITEM_QUANTITY, newQuantity, INVENTORY_FIELD_ID, Inventory_GetDbId(playerid, toJoinSlot));
    mysql_tquery(Database_GetConnection(), sqlString);

    mysql_format(Database_GetConnection(), sqlString, sizeof(sqlString), "DELETE FROM %s WHERE %s = %d", INVENTORY_TABLE_NAME, INVENTORY_FIELD_ID, Inventory_GetDbId(playerid, toRemoveSlot));
    mysql_tquery(Database_GetConnection(), sqlString);

    ResetInventorySlot(playerid, toRemoveSlot);
    return 1;
}

stock Inventory_UseItem(playerid, i_ITEM_LIST:itemId, slot, quantity)
{
    if (!Inventory_ItemExists(itemId))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: O item selecionado n�o existe.");
        return INVALID_VALUE;
    }
    if (slot < 0 || slot > (INVENTORY_MAX_SLOTS - 1))
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� deve selecionar um espa�o com um item para usar.");
        return INVALID_VALUE;
    }
    if (Inventory_GetItemId(playerid, slot) == i_ITEM_INVALID)
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: N�o h� nenhum item para ser usado nesse espa�o.");
        return INVALID_VALUE;
    }
    new itemQuantity = Inventory_GetItemQuantity(playerid, slot);
    if (itemQuantity < quantity)
    {
        SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� n�o a quantidade necess�ria de itens.");
        return INVALID_VALUE;
    }

    new itemName[INVENTORY_MAX_ITEM_NAME];
    GetInventoryItemName(itemId, itemName);
    if (itemQuantity <= 1 || itemQuantity == quantity)
    {
        Inventory_RemoveItem(playerid, Inventory_GetDbId(playerid, slot), slot);
        ResetInventorySlot(playerid, slot);
        ResetInventoryBoxInfo(playerid);
        HidePreviewDescription(playerid, (Inventory_GetTextdrawSelected(playerid) + 36));
        UpdateInventoryItemPreview(playerid, Inventory_GetTextdrawSelected(playerid), GetInventoryItemObjectId(Inventory_GetItemId(playerid, slot)), Inventory_GetIsOpenedStatus(playerid));
        UnselectInventoryItem(playerid);
    }
    else
    {
        Inventory_UpdateItemQuantity(playerid, slot, (itemQuantity - quantity));
        UpdateInventoryBoxInfo(playerid, slot, GetInventoryItemObjectId(itemId), itemName, Inventory_GetItemQuantity(playerid, slot), GetInventoryItemRarity(itemId));
        UpdateInventoryPreviewDesc(playerid, (Inventory_GetTextdrawSelected(playerid) + 36), itemName, Inventory_GetItemQuantity(playerid, slot));
    }

    switch (GetItemCategory(itemId))
    {
        case i_ITEM_CATEGORY_FOOD:
        {
            new increaseHungry = (5 + random(5)), string[(58 + INVENTORY_MAX_ITEM_NAME)];
            if ((Player_GetHungry(playerid) + increaseHungry) > 100)
            {
                Player_SetHungry(playerid, 100);
                format(string, sizeof(string), "[Invent�rio]: Voc� comeu um(a): %s e ficou saciado.", itemName);
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                return 1;
            }

            Player_SetHungry(playerid, (Player_GetHungry(playerid) + increaseHungry));
            format(string, sizeof(string), "[Invent�rio]: Voc� comeu um(a): %s e recuperou [%d] de fome.", itemName, increaseHungry);
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            return 1;
        }
        case i_ITEM_CATEGORY_DRINK:
        {
            new increaseDrink = (5 + random(5)), string[(58 + INVENTORY_MAX_ITEM_NAME)];
            if ((Player_GetDrink(playerid) + increaseDrink) > 100)
            {
                Player_SetDrink(playerid, 100);
                format(string, sizeof(string), "[Invent�rio]: Voc� bebeu um(a): %s e ficou saciado.", itemName);
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
                return 1;
            }

            Player_SetDrink(playerid, (Player_GetDrink(playerid) + increaseDrink));
            format(string, sizeof(string), "[Invent�rio]: Voc� bebeu um(a): %s e recuperou [%d] de sede.", itemName, increaseDrink);
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            return 1;
        }
        default:
        {
            new string[(37 + INVENTORY_MAX_ITEM_NAME)];
            format(string, sizeof(string), "[Invent�rio]: Voc� utilizou o item: %s.", itemName);
            SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
            return 1;
        }
    }
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

                cache_get_value_name_int(i, INVENTORY_FIELD_ID, dbId);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_ID, itemId);
                cache_get_value_name_int(i, INVENTORY_FIELD_ITEM_QUANTITY, quantity);

                if (Inventory_ItemExists(itemId))
                {
                    Inventory_SetDbId(playerid, slot, dbId);
                    Inventory_SetItemId(playerid, slot, itemId);
                    Inventory_SetItemQuantity(playerid, slot, quantity);
                    Inventory_SetItemSlot(playerid, slot, slot);
                }
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
                    // Update New Slot Item
                    UpdateInventorySlot(playerid, index, slotSelected);

                    // Update Old Slot Item
                    UpdateInventorySlot(playerid, Inventory_GetTextdrawSelected(playerid), Inventory_GetSlotSelected(playerid));

                    ResetInventoryBoxInfo(playerid);
                    HideInventoryItemOptions(playerid);
                    UnselectInventoryItem(playerid);

                    gsSwapItemsSlots[playerid] = false;
                    gsJoinItems[playerid] = false;
                }
                return 1;
            }

            if (gsJoinItems[playerid])
            {
                if (Inventory_JoinItemSlot(playerid, slotSelected, Inventory_GetSlotSelected(playerid)) != INVALID_VALUE)
                {
                    // Update Joined Item
                    UpdateInventorySlot(playerid, index, slotSelected);

                    // Update Old Item Slot
                    UpdateInventorySlot(playerid, Inventory_GetTextdrawSelected(playerid), Inventory_GetSlotSelected(playerid));

                    ResetInventoryBoxInfo(playerid);
                    HideInventoryItemOptions(playerid);
                    UnselectInventoryItem(playerid);

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
            return 1;
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
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� j� est� na primeira p�gina.");
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
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� j� est� na �ltima p�gina");
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
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� deve selecionar um item para us�-lo.");
        }
        if (Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: N�o h� nenhum item para ser usado nesse espa�o.");
        }

        if (Inventory_UseItem(playerid, Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), Inventory_GetSlotSelected(playerid), 1) != INVALID_VALUE)
        {
            gsSwapItemsSlots[playerid] = false;
            gsJoinItems[playerid] = false;
        }
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
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Invent�rio]: Os itens foram organizados no seu invent�rio.");
        return 1;
    }

    // Remove Item
    if (playertextid == Inventory_GetTextdraw(playerid, 37))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� deve selecionar um item.");
        }
        if (Inventory_GetDbId(playerid, Inventory_GetSlotSelected(playerid)) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: N�o h� nenhum item para ser usado nesse espa�o.");
        }

        ShowPlayerDialog(playerid, DIALOG_INVENTORY_REMOVE_ITEM, DIALOG_STYLE_MSGBOX, "Descartar Item", "{FFFFFF}Voc� tem certeza que deseja descatar esse item?.\n\n{ff6347}OBS: {8C8C8C}O descarte de item � um processo irrevers�vel\ne n�o poder� ser recuperado.", "Descartar", "Cancelar");
        return 1;
    }

    // Swap Item Slot
    if (playertextid == Inventory_GetTextdraw(playerid, 41))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� deve selecionar um item primeiro.");
        }

        if (!gsSwapItemsSlots[playerid])
        {
            gsSwapItemsSlots[playerid] = true;
            SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Invent�rio]: Selecione um espa�o vazio para mudar o item de lugar.");
        }
        gsJoinItems[playerid] = false;
        return 1;
    }

    // Join Items
    if (playertextid == Inventory_GetTextdraw(playerid, 38))
    {
        if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
        {
            return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� deve selecionar um item primeiro.");
        }
        gsJoinItems[playerid] = true;
        gsSwapItemsSlots[playerid] = false;
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "[Invent�rio]: Selecione o item com o qual voc� deseja juntar.");
        return 1;
    }

    // Detach Items
    if (playertextid == Inventory_GetTextdraw(playerid, 39))
    {
        ShowPlayerDialog(playerid, DIALOG_INVENTORY_DETACH_ITEMS, DIALOG_STYLE_INPUT, "Separar Item", "{FFFFFF}Digite a quantidade que voc� deseja separar.\n\n{ff6347}OBS: {8C8C8C}O valor deve ser acima de zero.", "Separar", "Cancelar");
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

hook OnDialogResponse(playerid, dialogid, response, listitem, const inputtext[])
{
    #pragma unused listitem // need this directive, on account of YSI which shows warnings in case the parameter is not used.

    switch (dialogid)
    {
        case DIALOG_INVENTORY_REMOVE_ITEM:
        {
            if (!response)
            {
                gsSwapItemsSlots[playerid] = false;
                gsJoinItems[playerid] = false;
                return 1;
            }
            if (response)
            {
                new string[(55 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME];
                GetInventoryItemName(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), itemName);
            
                format(string, sizeof(string), "[Invent�rio]: Voc� descartou o item: %s (Unidades: %d).", itemName, Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)));
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

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
        }
        case DIALOG_INVENTORY_DETACH_ITEMS:
        {
            if (!response)
            {
                return 1;
            }
            if (response)
            {
                if (Inventory_GetSlotSelected(playerid) == INVALID_VALUE)
                {
                    return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� deve selecionar um item primeiramente.");
                }
                if (strval(inputtext) <= 0)
                {
                    SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Digite um valor acima de zero.");
                    ShowPlayerDialog(playerid, DIALOG_INVENTORY_DETACH_ITEMS, DIALOG_STYLE_INPUT, "Separando Item", "{FFFFFF}Digite a quantidade que voc� deseja separar.\n\n{ff6347}OBS: {8C8C8C}O valor deve ser acima de zero.", "Separar", "Cancelar");
                    return 1;
                }
                if (strval(inputtext) == Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)))
                {
                    return SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� n�o pode separar essa quantidade de itens.");
                }
                if (strval(inputtext) > Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)))
                {
                    SendClientMessage(playerid, COLOR_INVALID, "[Invent�rio]: Voc� n�o tem toda essa quantidade de itens.");
                    ShowPlayerDialog(playerid, DIALOG_INVENTORY_DETACH_ITEMS, DIALOG_STYLE_INPUT, "Separando Item", "{FFFFFF}Digite a quantidade que voc� deseja separar.\n\n{ff6347}OBS: {8C8C8C}O valor deve ser acima de zero.", "Separar", "Cancelar");
                    return 1;
                }

                new string[(53 + INVENTORY_MAX_ITEM_NAME)], itemName[INVENTORY_MAX_ITEM_NAME], quantity = strval(inputtext);

                Inventory_UpdateItemQuantity(playerid, Inventory_GetSlotSelected(playerid), (Inventory_GetItemQuantity(playerid, Inventory_GetSlotSelected(playerid)) - quantity));
                Inventory_AddItem(playerid, Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), quantity);
                
                GetInventoryItemName(Inventory_GetItemId(playerid, Inventory_GetSlotSelected(playerid)), itemName);
                format(string, sizeof(string), "[Invent�rio]: Voc� separou o item: %s (Unidades: %d).", itemName, quantity);
                SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

                ResetInventoryBoxInfo(playerid);
                HideInventoryItemOptions(playerid);
                UnselectInventoryItem(playerid);
                gsSwapItemsSlots[playerid] = false;
                gsJoinItems[playerid] = false;
                return 1;
            }
        }
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
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo trabalho. Use: /trabalhar.");
	}
	new i_ITEM_LIST:itemId, quantity;
	if (sscanf(params, "dd", itemId, quantity))
	{
		return SendClientMessage(playerid, COLOR_INVALID, "USE: /pegaritem [id do item] [quantidade]");
	}
    if (!Inventory_ItemExists(itemId))
    {
        return SendClientMessage(playerid, COLOR_GREY, "[Erro]: O item informado � inv�lido.");
    }
    if (quantity < 0)
    {
        return SendClientMessage(playerid, COLOR_GREY, "[Erro]: Voc� deve informar uma quantidade para o item.");
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
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� autorizado a usar esse comando.");
	}
	if (!Admin_GetWorkStatus(playerid) && Player_GetAdminLevel(playerid) < HELPER_OWNER)
	{
		return SendClientMessage(playerid, COLOR_INVALID, "[Erro]: Voc� n�o est� em modo trabalho. Use: /trabalhar.");
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
