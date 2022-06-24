#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static adminRole[MAX_ADMIN_ROLES][] = { "Nenhum", "Estagi�rio", "Ajudante", "Moderador", "Supervisor", "Master", "Master +", "Master ++", "Gerente", "Sub-Dono", "Dono" };

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Admin_GetRole(role)
{
    new string[11];
    format(string, sizeof(string), "%s", adminRole[role]);
    return string;
}
//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
