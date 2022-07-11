#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static stock Timestamp:CorrectTimezone(&Timestamp:time)
{
	// Timezone correction
	new Hours:tzCorrection = Hours:3;
	time -= tzCorrection;
}

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock Timestamp:Chrono_ConvertToTimestamp(ts)
{
	new Timestamp:timestamp = Timestamp:ts;
	return timestamp;
}

stock Chrono_ConvertToInt(Timestamp:ts)
{
	return _:ts;
}

stock Timestamp:Chrono_GetTimeNow()
{
	new Timestamp:now = Now();

	return now;
}

stock Timestamp:Chrono_AddDays(Timestamp:ts, days)
{
	new Days:addDays = Days:days;
	ts += addDays;
	return ts;
}

stock Timestamp:Chrono_SubtractDays(Timestamp:ts, days)
{
	new Days:addDays = Days:days;
	ts -= addDays;
	return ts;
}

stock Chrono_GetFullDate(Timestamp:tsTimezone, timeString[], lenght = sizeof(timeString))
{
	CorrectTimezone(tsTimezone);

	TimeFormat(tsTimezone, "%d/%m/%Y %H:%M:%S", timeString, lenght);
	return 1;
}

stock Chrono_GetDayName(Timestamp:tsTimezone, dayString[], lenght = sizeof(dayString))
{
	CorrectTimezone(tsTimezone);

	TimeFormat(tsTimezone, WEEKDAY_NAME, dayString, lenght);
	if (!strcmp("Monday", dayString, true)) format(dayString, lenght, "Segunda-Feira");
	else if (!strcmp("Tuesday", dayString, true)) format(dayString, lenght, "Terça-Feira");
	else if (!strcmp("Wednesday", dayString, true)) format(dayString, lenght, "Quarta-Feira");
	else if (!strcmp("Thursday", dayString, true)) format(dayString, lenght, "Quinta-Feira");
	else if (!strcmp("Friday", dayString, true)) format(dayString, lenght, "Sexta-Feira");
	else if (!strcmp("Saturday", dayString, true)) format(dayString, lenght, "Sabado");
	else if (!strcmp("Sunday", dayString, true)) format(dayString, lenght, "Domingo");
	return 1;
}

stock Chrono_GetDate(Timestamp:tsTimezone, dateString[], lenght = sizeof(dateString))
{
	CorrectTimezone(tsTimezone);

	TimeFormat(tsTimezone, HUMAN_DATE, dateString, lenght);
	return 1;
}

stock Chrono_GetDay(Timestamp:tsTimezone, dayString[], lenght = sizeof(dayString))
{
	CorrectTimezone(tsTimezone);

	TimeFormat(tsTimezone, "%d", dayString, lenght);
	return 1;
}

stock Chrono_GetHour(Timestamp:tsTimezone, hourString[], lenght = sizeof(hourString))
{
	CorrectTimezone(tsTimezone);

	TimeFormat(tsTimezone, "%H:%M:%S", hourString, lenght);
	return 1;
}

stock Chrono_GetMonth(Timestamp:tsTimezone, monthString[], lenght = sizeof(monthString))
{
	CorrectTimezone(tsTimezone);

	TimeFormat(tsTimezone, "%B", monthString, lenght);
	if (!strcmp("January", monthString, true)) format(output, lenght, "Janeiro");
	else if (!strcmp("February", monthString, true)) format(output, lenght, "Fevereiro");
	else if (!strcmp("March", monthString, true)) format(output, lenght, "Março");
	else if (!strcmp("April", monthString, true)) format(output, lenght, "Abril");
	else if (!strcmp("May", monthString, true)) format(output, lenght, "Maio");
	else if (!strcmp("June", monthString, true)) format(output, lenght, "Junho");
	else if (!strcmp("July", monthString, true)) format(output, lenght, "Julho");
	else if (!strcmp("August", monthString, true)) format(output, lenght, "Agosto");
	else if (!strcmp("September", monthString, true)) format(output, lenght, "Setembro");
	else if (!strcmp("October", monthString, true)) format(output, lenght, "Outubro");
	else if (!strcmp("November", monthString, true)) format(output, lenght, "Novembro");
	else if (!strcmp("December", monthString, true)) format(output, lenght, "Dezembro");
	return 1;
}

stock Chrono_GetHourDigit(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[3];
	TimeFormat(tsTimezone, "%H", output);
	return strval(output);
}

stock Server_FormatMinuteDigit(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[3];
	TimeFormat(tsTimezone, "%M", output);
	return strval(output);
}

stock Server_FormatSecondDigit(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[3];
	TimeFormat(tsTimezone, "%S", output);
	return strval(output);
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
