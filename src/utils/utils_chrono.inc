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
stock Timestamp:Server_ConvertIntToChrono(ts)
{
	new Timestamp:timestamp = Timestamp:ts;
	return timestamp;
}

stock Server_ConvertChronoToInt(Timestamp:ts)
{
	return _:ts;
}

stock Timestamp:Server_GetTimeNow()
{
	new Timestamp:now = Now();

	return now;
}

stock Timestamp:Server_TimeAddDays(Timestamp:ts, days)
{
	new Days:addDays = Days:days;
	ts += addDays;
	return ts;
}

stock Timestamp:Server_TimeSubtractDays(Timestamp:ts, days)
{
	new Days:addDays = Days:days;
	ts -= addDays;
	return ts;
}

stock Server_FormatFullDate(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new fullOutput[20];
	TimeFormat(tsTimezone, "%d/%m/%Y %H:%M:%S", fullOutput);
	return fullOutput;
}

stock Server_FormatDate(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[9];
	TimeFormat(tsTimezone, HUMAN_DATE, output);
	return output;
}

stock Server_FormatHour(Timestamp:tsTimezone)
{
	CorrectTimezone(tsTimezone);

	new output[9];
	TimeFormat(tsTimezone, "%H:%M:%S", output);
	return output;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
