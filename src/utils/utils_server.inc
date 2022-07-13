#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define MAX_ZONE_NAME       28

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- Timers (Timers used in the module.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock PrintLog(const folder[], const string[], maxlength = sizeof(string))
{
    #if DEV_MODE
        printf("[Server Log]: %s", string);
    #endif
    
	if (!fexist(folder))
	{
	    new File: logFile = fopen(folder, io_write);
		fclose(logFile);
	}
    new yearlog, monthlog, daylog, hourlog, minutelog, stringLog[144];
	getdate(yearlog, monthlog, daylog);
	gettime(hourlog, minutelog);
	format(stringLog, (maxlength + 26), "[%02d/%02d/%d - %02d:%02d] %s\r\n", daylog, monthlog, yearlog, hourlog, minutelog, string);
	
    new File: logFile = fopen(folder, io_append);
    fwrite(logFile, stringLog);
    fclose(logFile);
    return 1;
}

stock FormatMoneyString(number, moneyString[], lenght = sizeof(moneyString))
{
    new real, mil, milhao, milhaor, bilhao, bilhaor;
    if (number > 999999999)
    {
        bilhao = number / 1000000000;
        bilhaor = number % 1000000000;
        milhao =  bilhaor / 1000000;
        milhaor = bilhaor % 1000000;
        mil = milhaor / 1000;
        real = milhaor % 1000;
    }
    else if (number > 999999)
    {
        milhao = number / 1000000;
        milhaor = number % 1000000;
        mil = milhaor / 1000;
        real = milhaor % 1000;
    }
    else if (number > 999)
    {
        mil = number / 1000;
        real = number % 1000;
    }
    
    if (number > 999999999)
    {
        format(moneyString, lenght, "%d.%03d.%03d.%03d", bilhao, milhao, mil, real);
    }
    else if (number > 999999)
    {
        format(moneyString, lenght, "%d.%03d.%03d", milhao, mil, real);
    }
    else if (number > 999)
    {
        format(moneyString, lenght, "%d.%03d", mil, real);
    }
    else
    {
        format(moneyString, lenght, "%d", number);
    }
    return 1;
}

stock GetPlayerWeaponName(gun)
{
    static armatext[90];
    switch (gun)
    {
 		case 0: armatext = "Soco Normal";
	    case 1: armatext = "Soqueira";
	    case 2: armatext = "Taco de Golf";
	    case 3: armatext = "Cacetete";
	    case 4: armatext = "Faca";
	    case 5: armatext = "Bastao";
	    case 6: armatext = "Pá";
	    case 7: armatext = "Taco";
	    case 8: armatext = "Katana";
	    case 9: armatext = "Serra Elétrica";
	    case 10: armatext = "Vibrador";
	    case 11: armatext = "Vibrador";
	    case 12: armatext = "Vibrador";
	    case 13: armatext = "Vibrador";
	    case 14: armatext = "Flores";
	    case 15: armatext = "Pé de Cabra";
	    case 16: armatext = "Granada";
	    case 18: armatext = "Molotov";
	    case 22: armatext = "Usp 2 Mãos";
	    case 23: armatext = "Pistola Silenciosa";
	    case 24: armatext = "Desert Eagle";
	    case 25: armatext = "Shotgun";
	    case 26: armatext = "Shotgun";
	    case 27: armatext = "Shotgun";
        case 28: armatext = "Sub-Metralhadora";
        case 29: armatext = "MP5";
        case 30: armatext = "Ak-47";
        case 31: armatext = "M4";
        case 32: armatext = "Tec-9";
        case 33: armatext = "Rifle";
        case 34: armatext = "Sniper";
        case 35: armatext = "Bazuca";
        case 36: armatext = "Foguete";
        case 37: armatext = "Lança Chamas";
        case 38: armatext = "Minigun";
        case 39: armatext = "Bomba";
        case 41: armatext = "Spray";
        case 42: armatext = "Extintor";
        default: armatext = "Não reconhecida";
    }
    return armatext;
}

stock GetPlayerWeaponAmmo(playerid, weaponid)
{
    new wd[2][13];
    for(new i; i<13; i++)
    {
        GetPlayerWeaponData(playerid, i, wd[0][i], wd[1][i]);
    }
    for(new i; i<13; i++)
    {
        if (weaponid == wd[0][i]) 
        {
            return wd[1][i];
        }
    }
    return 0;
}

stock GetPlayersInSameIp(const test_ip[])
{
	new against_ip[32+1];
    new ip_count = 0;
    foreach(new i: Player)
	{
        GetPlayerIp(i, against_ip, 32);
        if (!strcmp(against_ip, test_ip))
	   	{
	    	ip_count++;
		}
    }
    return ip_count;
}

stock CheckInvalidWords(const string[])
{
	new x = 0;
	for (new i = 0, j = strlen(string); i <= j; i++)
	{
		if (string[i] >= 46 && string[i] <= 58)
		{
		    x += 1;
		}
	}
	if (x >= 8) return 1;
	if (strfind(string, "189.", true) != -1 || strfind(string, "201.", true) != -1 || strfind(string, "200.", true) != -1 || strfind(string, "75.", true) != -1 || strfind(string, "91.", true) != -1 || strfind(string, "67.", true) != -1 || strfind(string, "69.", true) != -1 || strfind(string, "205.", true) != -1 || strfind(string, ":7717", true) != -1 || strfind(string, ":7777", true) != -1 || strfind(string, ":1122", true) != -1 ||
	strfind(string, "168.", true) != -1 || strfind(string, "1 8 9", true) != -1 || strfind(string, "2 0 1", true) != -1 || strfind(string, "192.", true) != -1 || strfind(string, "254.", true) != -1 || strfind(string, "7 7 7 7.", true) != -1 || strfind(string, "169.", true) != -1 || strfind(string, ":8780", true) != -1 ||
    strfind(string, "2 0 0", true) != -1 || strfind(string, "1 6 9", true) != -1 || strfind(string, "63.", true) != -1 || strfind(string, "1 6 8", true) != -1 || strfind(string, ":7779", true) != -1 || strfind(string, "64.120.47.79:3700", true) != -1 || strfind(string, "@hotmail.com", true) != -1  || strfind(string, "@yahoo.com.br", true) != -1 || strfind(string, "Play Games", true) != -1 ||
	strfind(string, "B P G", true) != -1 || strfind(string, "Forever", true) != -1 || strfind(string, "Brasil Play Vício", true) != -1 || strfind(string, "2 0 0 . 2 5 5 . 1 6 6 . 1 9 9 : 2 7 7 7 8", true) != -1 || strfind(string, "Play Facil", true) != -1 || strfind(string, "Play ", true) != -1 || strfind(string, "BPG", true) != -1  || strfind(string, "Hot mail", true) != -1 ||
	strfind(string, "BSG", true) != -1 || strfind(string, "BPG", true) != -1 || strfind(string, "Play Online", true) != -1 || strfind(string, ".com", true) != -1 || strfind(string, "BPO", true) != -1 || strfind(string, "BPV", true) != -1 || strfind(string, "Brasil Play Vicio", true) != -1 || strfind(string, "Play Vicio", true) != -1 ||
    strfind(string, "BP G", true) != -1  || strfind(string, "BP V", true) != -1 || strfind(string, "BP O", true) != -1 || strfind(string, "bp-g", true) != -1 || strfind(string, "bp.g", true) != -1)
    {
	     return 1;
	}
	else if (strfind(string, ".", true) != -1 && strfind(string, ":", true) != -1)
	{
		return 1;
	}
	return 0;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------

//------------------------- Commands (Module related commands) -------------------------
