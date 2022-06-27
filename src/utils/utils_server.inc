#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock DelayedKick(playerid)
{
    SetTimerEx("_KickTimer", 100, false, "i", playerid);
    return 1;
}

stock Server_PrintLog(const folder[], const string[], maxlength = sizeof(string))
{
    if (maxlength) return print("[Log Error]: Limite de caracteres atingido.");
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

stock Server_FormatToMoney(number)
{
    new real, mil, milhao, milhaor, bilhao, bilhaor, string[100];
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
        format(string, 100, "%d.%03d.%03d.%03d", bilhao, milhao, mil, real);
    }
    else if (number > 999999)
    {
        format(string, 100, "%d.%03d.%03d", milhao, mil, real);
    }
    else if (number > 999)
    {
        format(string, 100, "%d.%03d", mil, real);
    }
    else
    {
        format(string, 100, "%d", number);
    }
    return string;
}

stock Server_FormatTime(number)
{
    new hours = 0, mins = 0, secs = 0, string[100];
    hours = floatround(number / 3600);
    mins = floatround((number / 60) - (hours * 60));
    secs = floatround(number - ((hours * 3600) + (mins * 60)));
    new days = 0;
    if (hours >= 24)
    {
        days = floatround((hours/24), floatround_floor);
        hours = hours % 24;
    }
    if (days > 0)
    {
        format(string, 100, "%d dias, %02d:%02d:%02d", days, hours, mins, secs);
    }
    else if (hours > 0)
    {
        format(string, 100, "%02d:%02d:%02d", hours, mins, secs);
    }
    else
    {
        format(string, 100, "%02d:%02d:%02d", hours, mins, secs);
    }
    return string;
}

stock Server_GetWeaponName(gun)
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

stock Server_PlayersInSameIp(const test_ip[])
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

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
function:_KickTimer(playerid)
{
    Kick(playerid);
	return 1;
}
