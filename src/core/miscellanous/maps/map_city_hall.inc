#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------
#define	CITY_HALL_ENTRANCE		1481.0397,-1772.3135,18.7958
#define	CITY_HALL_EXIT			390.7694,173.8226,1008.3828

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static gsCityHallActor[3];

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
hook OnGameModeInit()
{
	//=====================================[ 3DTEXT ]====================================||
    Create3DTextLabel("Prefeitura de {FFFFFF}Los Santos{B4B5B7}\nPara Entrar\nAperte '{FFFFFF}F{B4B5B7}'", COLOR_GRAD1, CITY_HALL_ENTRANCE, 20.0, 0);

    //=====================================[ PICKUPS ]====================================||
    AddStaticPickup(1318, 23, CITY_HALL_ENTRANCE);
    AddStaticPickup(1318, 23, CITY_HALL_EXIT);

	//=====================================[ OBJECTS ]====================================||
    CreateDynamicObject(1231, 1483.80566, -1750.43030, 17.18440,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1231, 1478.46570, -1750.43030, 17.18440,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(3471, 1489.41077, -1750.04102, 15.69700,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(3471, 1472.99084, -1750.04102, 15.69700,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19121, 1478.53674, -1748.43298, 15.01520,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19121, 1483.83667, -1748.43298, 15.01520,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1521.71875, -1749.95215, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1516.91772, -1747.19971, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1516.51782, -1750.33862, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1518.74133, -1746.95728, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1519.43823, -1749.93835, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1520.97449, -1746.97351, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1523.94263, -1750.06848, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1524.94543, -1747.95215, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1523.06897, -1746.87390, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1517.56714, -1748.56885, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1515.18335, -1746.69287, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19325, 1478.44531, -1758.15002, 17.76180,   90.00000, 0.10000, 0.00000);
	new prefTexture;
	prefTexture = CreateDynamicObject(18762, 1478.28430, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1473.18433, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1473.18433, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1475.73584, -1751.12854, 24.55590,   90.00000, 0.10000, 90.00000);
	prefTexture = CreateDynamicObject(18762, 1475.69507, -1751.52539, 14.15130,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1470.21960, -1751.52441, 23.60850,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1467.83960, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1472.75964, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1470.21960, -1751.12854, 17.94180,   90.00000, 0.10000, 90.00000);
	prefTexture = CreateDynamicObject(18762, 1467.83960, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1472.75964, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1470.21960, -1751.52539, 14.15130,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1470.21960, -1751.12854, 24.55590,   90.00000, 0.10000, 90.00000);
	prefTexture = CreateDynamicObject(18762, 1486.61963, -1751.52478, 23.60850,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1492.21960, -1751.52441, 23.60850,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1484.06445, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.16443, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.66443, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1494.68445, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1484.06445, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.66443, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1494.68445, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.16443, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1486.63965, -1751.52539, 14.15130,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1492.21960, -1751.52539, 14.15130,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1486.73486, -1760.09583, 20.04160,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1492.21960, -1751.12854, 17.94180,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1492.21960, -1751.12854, 24.55590,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1486.61963, -1751.12854, 24.55590,   90.00000, 0.10000, 90.00000);
	prefTexture = CreateDynamicObject(18762, 1478.28430, -1751.52441, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1475.69507, -1751.52441, 23.60850,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(18764, 1501.58130, -1748.14087, 11.94320,   0.00000, 0.00000, 269.88589);
	CreateDynamicObject(18764, 1481.15308, -1748.13452, 11.92320,   0.00000, 0.00000, 269.88589);
	CreateDynamicObject(18764, 1460.80774, -1748.14087, 11.94320,   0.00000, 0.00000, 269.88589);
	prefTexture = CreateDynamicObject(18762, 1480.90027, -1751.52441, 18.61690,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.64807, -1751.52441, 16.92450,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.70764, -1751.52441, 16.92450,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1481.18030, -1751.12854, 22.20990,   90.00000, 0.10000, 90.00000);
	prefTexture = CreateDynamicObject(18762, 1478.70764, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.64807, -1751.52441, 21.90800,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1480.90027, -1751.52441, 23.60850,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.45801, -1752.09265, 26.86130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.86560, -1752.31824, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.45801, -1752.09265, 21.88620,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1475.73584, -1751.12854, 17.94180,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1478.44531, -1754.05420, 24.39160,   90.00000, 0.10000, 0.00000);
	CreateDynamicObject(19325, 1483.80737, -1754.13391, 17.76180,   90.00000, 0.10000, 0.00000);
	CreateDynamicObject(19325, 1478.44531, -1758.15015, 24.39160,   90.00000, 0.10000, 0.00000);
	prefTexture = CreateDynamicObject(18762, 1472.73792, -1759.80212, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1473.16589, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1484.15906, -1759.80017, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.24426, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.24426, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1473.16589, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1473.16589, -1759.80017, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1472.73792, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1467.57886, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1470.11536, -1759.79333, 16.25189,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1472.73792, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1467.57886, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1467.57886, -1759.80212, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1470.11536, -1759.79333, 28.68930,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1475.69507, -1759.79333, 28.68930,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1475.69507, -1759.75366, 16.25190,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.45764, -1754.50403, 28.21720,   0.00000, 90.00000, 90.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.45764, -1756.74402, 28.21720,   0.00000, 90.00000, 90.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1478.24426, -1759.80017, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1484.15906, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1484.15906, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.59839, -1759.80017, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.18445, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.18445, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1494.68445, -1759.80017, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1494.68445, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1494.68445, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1486.61963, -1759.80017, 28.68930,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1492.21960, -1759.80017, 28.68930,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1486.61963, -1759.80017, 16.25190,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1492.21960, -1759.80017, 16.25190,   0.00000, 90.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1486.59998, -1751.16333, 17.94180,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1486.73486, -1760.09583, 26.66650,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1492.11963, -1760.11560, 26.66650,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1492.11963, -1760.09583, 20.04160,   90.00000, 0.10000, 90.00000);
	prefTexture = CreateDynamicObject(18762, 1489.18445, -1759.80017, 19.02130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.59839, -1759.80017, 24.02160,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1489.59839, -1759.80017, 28.98670,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(19325, 1475.69507, -1760.09583, 20.04160,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1470.17542, -1760.09583, 20.04160,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1470.17407, -1760.13586, 26.66650,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1475.69507, -1760.09583, 26.66650,   90.00000, 0.10000, 90.00000);
	CreateDynamicObject(19325, 1478.44531, -1754.05420, 17.76180,   90.00000, 0.10000, 0.00000);
	CreateDynamicObject(19325, 1483.80737, -1754.05420, 24.39160,   90.00000, 0.10000, 0.00000);
	CreateDynamicObject(19325, 1483.80737, -1758.23828, 17.76180,   90.00000, 0.10000, 0.00000);
	CreateDynamicObject(19325, 1483.80737, -1758.16992, 24.39160,   90.00000, 0.10000, 0.00000);
	prefTexture = CreateDynamicObject(18762, 1478.45801, -1752.09265, 16.94130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.86560, -1752.09265, 21.88620,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.86560, -1752.09265, 26.86130,   0.00000, 0.00000, 0.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.86560, -1756.74402, 28.21720,   0.00000, 90.00000, 90.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	prefTexture = CreateDynamicObject(18762, 1483.86560, -1754.50403, 28.21720,   0.00000, 90.00000, 90.00000);
	SetDynamicObjectMaterial(prefTexture, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	CreateDynamicObject(870, 1517.56714, -1748.56885, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1439.00244, -1749.93140, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1445.55090, -1747.16748, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1444.06970, -1748.91138, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1442.54614, -1750.12952, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1442.62231, -1746.85486, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1440.61353, -1748.87268, 13.03996,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(870, 1439.38538, -1746.89441, 13.03996,   0.00000, 0.00000, 0.00000);

    //=====================================[ ACTORS ]====================================||
    gsCityHallActor[0] = CreateDynamicActor(163, 358.3519,169.2911,1008.3828, 273.3107);
    gsCityHallActor[1] = CreateDynamicActor(164, 358.2496,177.5590,1008.3828, 267.0439);
	gsCityHallActor[2] = CreateDynamicActor(191, 356.2973, 184.6096, 1008.3762, 266.0688);
	for (new i; i < (sizeof(gsCityHallActor) - 1); i++)
	{
		ApplyDynamicActorAnimation(gsCityHallActor[i], "COP_AMBIENT", "Coplook_loop", 4.1, true, false, false, false, 0);
	}
    return 1;
}

hook OnPlayerConnect(playerid)
{
    //=====================================[ REMOVE WORLD OBJECTS ]====================================||

    //=====================================[ MAP ICONS ]====================================||
    SetPlayerMapIcon(playerid, 1, 1480.9403,-1770.8481,18.7958, 44 , 0xE6E6E6E6);
	return 1;
    
}

hook OnPlayerPressF(playerid)
{
	// Entrance
	if (IsPlayerInRangeOfPoint(playerid, 3.0, CITY_HALL_ENTRANCE))
	{
	    PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/53d0kb63zneqa1i/playstory%20PREFEITURA.mp3?dl=1");
        GameTextForPlayer(playerid, "~w~bem vindo a prefeitura ls !", 3000, 1);
		TeleportPlayer(playerid, CITY_HALL_EXIT, 3, 0, CITY_HALL_INTERIOR);
		return 1;
   	}
	// Exit
	if (IsPlayerInRangeOfPoint(playerid, 3.0, CITY_HALL_EXIT))
	{
	    StopAudioStreamForPlayer(playerid);
		TeleportPlayer(playerid, CITY_HALL_ENTRANCE, 0, 0, NO_INTERIOR);
		return 1;
	}
	return 1;
}
