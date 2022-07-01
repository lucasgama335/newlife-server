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

stock Chrono_GetFullDate(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new fullOutput[20];
	TimeFormat(tsTimezone, "%d/%m/%Y %H:%M:%S", fullOutput);
	return fullOutput;
}

stock Chrono_GetDate(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[9];
	TimeFormat(tsTimezone, HUMAN_DATE, output);
	return output;
}

stock Chrono_GetDay(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[3];
	TimeFormat(tsTimezone, "%d", output);
	return output;
}

stock Chrono_GetHour(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[9];
	TimeFormat(tsTimezone, "%H:%M:%S", output);
	return output;
}

stock Chrono_GetMonth(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[10];
	TimeFormat(tsTimezone, "%B", output);
	if (!strcmp("January", output, true)) format(output, sizeof(output), "Janeiro");
	else if (!strcmp("February", output, true)) format(output, sizeof(output), "Fevereiro");
	else if (!strcmp("March", output, true)) format(output, sizeof(output), "Março");
	else if (!strcmp("April", output, true)) format(output, sizeof(output), "Abril");
	else if (!strcmp("May", output, true)) format(output, sizeof(output), "Maio");
	else if (!strcmp("June", output, true)) format(output, sizeof(output), "Junho");
	else if (!strcmp("July", output, true)) format(output, sizeof(output), "Julho");
	else if (!strcmp("August", output, true)) format(output, sizeof(output), "Agosto");
	else if (!strcmp("September", output, true)) format(output, sizeof(output), "Setembro");
	else if (!strcmp("October", output, true)) format(output, sizeof(output), "Outubro");
	else if (!strcmp("November", output, true)) format(output, sizeof(output), "Novembro");
	else if (!strcmp("December", output, true)) format(output, sizeof(output), "Dezembro");
	return output;
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
