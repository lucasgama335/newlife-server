#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_INVENTORY_SLOTS         80

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
static gsLastItemSelect[MAX_PLAYERS];

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
static stock ShowPlayerInventory(playerid)
{
    if (!IsValidPlayer(playerid))
    {
        return SendClientMessage(playerid, COLOR_INVALID, "Você precisa estar logado para abrir o inventário.");
    }

    HidePlayerHud(playerid);
    Inventory_UpdateBoxInfo(playerid);
    Inventory_Show(playerid);
    return 1;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Inventory_ResetAllSlots(playerid)
{
    // Reset Inventory Data
    static const scEmptyData[MAX_INVENTORY_SLOTS][i_INVENTORY_DATA];
    gsPlayerInventory[playerid] = scEmptyData;

    // Reset All Textdraw Item Preview
    for (new i = 11; i < 31; i++)
    {
        Inventory_UpdateItemPreview(playerid, i, gsPlayerInventory[playerid][i][i_INVENTORY_ITEM_ID]);
    }
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnPlayerConnect(playerid)
{
    Inventory_ResetAllSlots(playerid);
    gsItemSelect[playerid] = INVALID_VALUE;
    gsLastItemSelect[playerid] = INVALID_VALUE;
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Close Button
    if (playertextid == Inventory_GetTextdraw(playerid, 41))
    {
        // Reset Box Color of last item select
        if (gsLastItemSelect[playerid] != INVALID_VALUE)
        {
            Inventory_ChangeItemBoxColor(playerid, gsLastItemSelect[playerid], 1296911746);
        }
        Inventory_Hide(playerid);
        ShowPlayerHud(playerid);
        CancelSelectTextDraw(playerid);
        return 1;
    }

    // Reset Button
    if (playertextid == Inventory_GetTextdraw(playerid, 9))
    {
        Inventory_ChangeItemBoxColor(playerid, gsLastItemSelect[playerid], 1296911746);
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
        new index = Inventory_GetTextdrawIndex(playerid, playertextid);
        if (index != INVALID_VALUE)
        {
            // Reset Box Color of last item select
            if (gsLastItemSelect[playerid] != INVALID_VALUE)
            {
                Inventory_ChangeItemBoxColor(playerid, gsLastItemSelect[playerid], 1296911746);
            }
            gsLastItemSelect[playerid] = index;
            Inventory_ChangeItemBoxColor(playerid, gsLastItemSelect[playerid], -764862721);
            Inventory_UpdateBoxInfoItem(playerid, index, gsPlayerInventory[playerid][index][i_INVENTORY_ID], "Desconhecido", 0, "Desconhecida");
            Inventory_ShowItemOptions(playerid);
            return 1;
        }
    }
    return 1;
}

hook OnPlayerPressY(playerid)
{
    ShowPlayerInventory(playerid);
    return 1;
}

//------------------------- Commands (Module related commands) -------------------------
YCMD:inventario(playerid, params[], help)
{
    ShowPlayerInventory(playerid);
    return 1;
}