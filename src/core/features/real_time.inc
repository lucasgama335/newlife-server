#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define 	TXT_CLIMA1   	 "[Previsão do Tempo]: Dia Limpo, Mínima de 22°C, Máxima de 26°C."
#define 	TXT_CLIMA2   	 "[Previsão do Tempo]: Clima Seco, Mínima de 24°C, Máxima de 28°C."
#define 	TXT_CLIMA3   	 "[Previsão do Tempo]: Ventos Fortes, Mínima de 19°C, Máxima de 22°C."
#define 	TXT_CLIMA4   	 "[Previsão do Tempo]: Tempo Nublado com Ventos fortes, Mínima de 15°C, Máxima de 18°C."
#define 	TXT_CLIMA5   	 "[Previsão do Tempo]: Tempo Chuvoso com Ventos fortes, Mínima de 12°C, Máxima de 15°C."
#define 	TXT_CLIMA6   	 "[Previsão do Tempo]: Neblina forte, Mínima de 2°C, Máxima de 5°C."
#define 	TXT_CLIMA7   	 "[Previsão do Tempo]: Céu Limpo, Mínima de 22°C, Máxima de 26°C."
#define 	TXT_CLIMA8   	 "[Previsão do Tempo]: Nublado com Ventos fracos, Mínima de 15°C, Máxima de 18°C."
#define 	TXT_CLIMA9   	 "[Previsão do Tempo]: Céu amarelado, Mínima de 19°C, Máxima de 21°C."
#define 	TXT_CLIMA10  	 "[Previsão do Tempo]: Tempo Nublado, Mínima de 12°C, Máxima de 15°C."
#define 	TXT_CLIMA11  	 "[Previsão do Tempo]: Chuva Forte, Cuidado com a pista escorregadia, Mínima de 4°C{FFFFAF}, Máxima de {F80303}7°C{FFFFAF}."
#define 	TXT_CLIMA12  	 "[Previsão do Tempo]: Céu Alaranjado, Mínima de 11°C, Máxima de 14°C."
#define 	TXT_CLIMA13  	 "[Previsão do Tempo]: Neblina Densa com Vento forte, Mínima de -2°C, Máxima de 1°C."

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static changedWeather = 7200; // this is for change weather each 2 hour
static bool:weatherForecastActive;

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Server_SetWeatherForecast(bool:status)
{
	weatherForecastActive = status;
	return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
task SyncRealTime[1000]()
{
    new Timestamp:timeNow = Server_GetTimeNow();
    static clock_string[9];
    format(clock_string, sizeof(clock_string), "%s", Server_FormatHour(timeNow));
	UpdateClockScreen(clock_string);
    
    new minutes = Server_FormatMinuteDigit(timeNow), seconds = Server_FormatSecondDigit(timeNow);
    if (changedWeather > 0) changedWeather--;
    if (minutes == 0 && seconds == 0) ChangeWorldTime(timeNow);
}

static stock Server_UpdateTimeString()
{
    new Timestamp:time_now = Server_GetTimeNow(), time_string[16];
    format(time_string, sizeof(time_string), "%s de %s", Server_FormatDay(time_now), Server_FormatMonth(time_now));
	UpdateDateScreen(time_string);
    return 1;
}

static stock ChangeWorldTime(Timestamp:time)
{
    new hour = Server_FormatHourDigit(time);
    switch (hour)
    {
        case 0: SetWorldTime(0);
        case 1: SetWorldTime(1);
        case 2: SetWorldTime(2);
        case 3: SetWorldTime(3);
        case 4: SetWorldTime(4);
        case 5: SetWorldTime(5);
        case 6: SetWorldTime(6);
        case 7: SetWorldTime(6);
        case 8: SetWorldTime(6);
        case 9: SetWorldTime(7);
        case 10: SetWorldTime(10);
        case 11: SetWorldTime(11);
        case 12: SetWorldTime(12);
        case 13: SetWorldTime(13);
        case 14: SetWorldTime(14);
        case 15: SetWorldTime(15);
        case 16: SetWorldTime(16);
        case 17: SetWorldTime(20);
        case 18: SetWorldTime(21);
        case 19: SetWorldTime(0);
        case 20: SetWorldTime(0);
        case 21: SetWorldTime(0);
        case 22: SetWorldTime(0);
        case 23: SetWorldTime(0);
    }
    if (changedWeather <= 0) 
    { 
        if (weatherForecastActive) WeatherForecast();
        changedWeather = 7200;
    }
    return 1;
}

static stock WeatherForecast()
{
    new random_weather = random(12);
    switch (random_weather)
    {
        case 0:
	    {
	        SetWeather(0);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA1); 
	    }
	    case 1:
	    {
	        SetWeather(1);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA2);
	    }
	    case 2:
	    {
	        SetWeather(3);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA3);
	    }
	    case 3:
	    {
	        SetWeather(7);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA4);
	    }
	    case 4:
	    {
	        SetWeather(8);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA5);
	    }
	    case 5:
	    {
	        SetWeather(9);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA6);
	    }
	    case 6:
	    {
	        SetWeather(11);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA7);
	    }
	    case 7:
	    {
	        SetWeather(12);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA8);
	    }
	    case 8:
	    {
	        SetWeather(13);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA9);
	    }
	    case 9:
	    {
	        SetWeather(15);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA10);
	    }
	    case 10:
	    {
	        SetWeather(16);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA11);
	    }
	    case 11:
	    {
	        SetWeather(17);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA12);
	    }
	    case 12:
	    {
	        SetWeather(19);
	        SendClientMessageToAll(COLOR_ORANGE2, TXT_CLIMA13);
	    }
    }
    return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
    weatherForecastActive = true;
    Server_UpdateTimeString();
    ChangeWorldTime(Server_GetTimeNow());
    SetWeather(0);
    return 1;
}
