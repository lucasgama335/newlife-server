#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------
static const gscVehicleNames[212][] =
{
	{"Landstalker"}, {"Bravura"}, {"Buffalo"}, {"Linerunner"}, {"Perrenial"}, {"Sentinel"}, {"Dumper"},
    {"Firetruck"}, {"Trashmaster"}, {"Stretch"}, {"Manana"}, {"Infernus"}, {"Voodoo"}, {"Pony"}, {"Mule"},
    {"Cheetah"}, {"Ambulancia"}, {"Leviathan"}, {"Moonbeam"}, {"Esperanto"}, {"Taxi"}, {"Washington"},
    {"Bobcat"}, {"Mr Whoopee"}, {"BF Injection"}, {"Hunter"}, {"Premier"}, {"Enforcer"}, {"Securicar"},
    {"Banshee"}, {"Predator"}, {"Bus"}, {"Rhino"}, {"Barracks"}, {"Hotknife"}, {"Trailer 1"}, {"Previon"},
    {"Onibus"}, {"Cabbie"}, {"Stallion"}, {"Rumpo"}, {"RC Bandit"}, {"Romero"}, {"Packer"}, {"Monster"},
    {"Admiral"}, {"Squalo"}, {"Seasparrow"}, {"Pizzaboy"}, {"Tram"}, {"Trailer 2"}, {"Turismo"},
    {"Speeder"}, {"Reefer"}, {"Tropic"}, {"Flatbed"}, {"Yankee"}, {"Caddy"}, {"Solair"}, {"Berkley's RC Van"},
    {"Skimmer"}, {"PCJ-600"}, {"Vespa"}, {"Freeway"}, {"RC Baron"}, {"RC Raider"}, {"Glendale"}, {"Oceanic"},
    {"Sanchez"}, {"Sparrow"}, {"Patriot"}, {"Quad"}, {"Coastguard"}, {"Dinghy"}, {"Hermes"}, {"Sabre"},
    {"Rustler"}, {"ZR-350"}, {"Walton"}, {"Regina"}, {"Comet"}, {"BMX"}, {"Burrito"}, {"Kombi"}, {"Marquis"},
    {"Baggage"}, {"Dozer"}, {"Helicoptero"}, {"News Chopper"}, {"Rancher"}, {"FBI Rancher"}, {"Virgo"}, {"Greenwood"},
    {"Jetmax"}, {"Hotring"}, {"Sandking"}, {"Blista Compact"}, {"Helicoptero Policial"}, {"Boxville"}, {"Benson"},
    {"Mesa"}, {"RC Goblin"}, {"Hotring Racer A"}, {"Hotring Racer B"}, {"Bloodring Banger"}, {"Rancher"},
    {"Super GT"}, {"Elegant"}, {"Journey"}, {"Bike"}, {"Mountain Bike"}, {"Beagle"}, {"Cropdust"}, {"Stunt"},
    {"Tanker"}, {"Roadtrain"}, {"Nebula"}, {"Majestic"}, {"Buccaneer"}, {"Shamal"}, {"Hydra"}, {"FCR-900"},
    {"R1"}, {"HPV1000"}, {"Cement Truck"}, {"Guincho"}, {"Fortune"}, {"Cadrona"}, {"FBI Truck"},
    {"Willard"}, {"Forklift"}, {"Trator"}, {"Combine"}, {"Feltzer"}, {"Remington"}, {"Slamvan"},
    {"Blade"}, {"Freight"}, {"Streak"}, {"Vortex"}, {"Vincent"}, {"Bullet"}, {"Clover"}, {"Sadler"},
    {"Firetruck LA"}, {"Hustler"}, {"Intruder"}, {"Primo"}, {"Cargobob"}, {"Tampa"}, {"Sunrise"}, {"Merit"},
    {"Utility"}, {"Nevada"}, {"Yosemite"}, {"Windsor"}, {"Monster A"}, {"Monster B"}, {"Uranus"}, {"Jester"},
    {"Subaru"}, {"Stratum"}, {"Elegy"}, {"Raindance"}, {"RC Tiger"}, {"Flash"}, {"Tahoma"}, {"Savanna"},
    {"Bandito"}, {"Freight Flat"}, {"Streak Carriage"}, {"Kart"}, {"Mower"}, {"Duneride"}, {"Sweeper"},
    {"Broadway"}, {"Tornado"}, {"AT-400"}, {"DFT-30"}, {"Huntley"}, {"Stafford"}, {"BF-400"}, {"Newsvan"},
    {"Tug"}, {"Trailer 3"}, {"Emperor"}, {"Wayfarer"}, {"Euros"}, {"Hotdog"}, {"Club"}, {"Freight Carriage"},
    {"Trailer 3"}, {"Andromada"}, {"Dodo"}, {"RC Cam"}, {"Launch"}, {"Viatura LS"}, {"Viatura SF"},
    {"Viatura LV"}, {"Police Ranger"}, {"Picador"}, {"S.W.A.T. Van"}, {"Alpha"}, {"Phoenix"}, {"Glendale"},
    {"Sadler"}, {"Luggage Trailer A"}, {"Luggage Trailer B"}, {"Stair Trailer"}, {"Boxville"}, {"Farm Plow"},
    {"Utility Trailer"}
};

enum e_VEHICLE_FLAGS
{
    e_VEHICLE_FLAGS_CAT_Unknown,
	e_VEHICLE_FLAGS_CAT_Airplane,
	e_VEHICLE_FLAGS_CAT_Helicopter,
	e_VEHICLE_FLAGS_CAT_Bike,
	e_VEHICLE_FLAGS_CAT_Convertible,
	e_VEHICLE_FLAGS_CAT_Industrial,
	e_VEHICLE_FLAGS_CAT_Lowrider,
	e_VEHICLE_FLAGS_CAT_OffRoad,
	e_VEHICLE_FLAGS_CAT_Public,
	e_VEHICLE_FLAGS_CAT_Saloon,
	e_VEHICLE_FLAGS_CAT_Sport,
	e_VEHICLE_FLAGS_CAT_Station,
	e_VEHICLE_FLAGS_CAT_Boat,
	e_VEHICLE_FLAGS_CAT_Trailer,
	e_VEHICLE_FLAGS_CAT_Unique,
	e_VEHICLE_FLAGS_CAT_RC,
	e_VEHICLE_FLAGS_CATEGORY,
	e_VEHICLE_FLAGS_Car,
	e_VEHICLE_FLAGS_Truck,
	e_VEHICLE_FLAGS_Van,
	e_VEHICLE_FLAGS_Fire,
	e_VEHICLE_FLAGS_Police,
	e_VEHICLE_FLAGS_FBI,
	e_VEHICLE_FLAGS_SWAT,
	e_VEHICLE_FLAGS_Military,
	e_VEHICLE_FLAGS_Weaponised,
	e_VEHICLE_FLAGS_Helicopter,
	e_VEHICLE_FLAGS_Boat,
	e_VEHICLE_FLAGS_Plane,
	e_VEHICLE_FLAGS_Bike,
	e_VEHICLE_FLAGS_Manual,
	e_VEHICLE_FLAGS_Ambulance,
	e_VEHICLE_FLAGS_Taxi,
	e_VEHICLE_FLAGS_OnWater,
	e_VEHICLE_FLAGS_Coastguard,
	e_VEHICLE_FLAGS_Train,
	e_VEHICLE_FLAGS_LS,
	e_VEHICLE_FLAGS_SF,
	e_VEHICLE_FLAGS_LV,
	e_VEHICLE_FLAGS_Tank,
	e_VEHICLE_FLAGS_Flowerpot,
	e_VEHICLE_FLAGS_Transport,
	e_VEHICLE_FLAGS_Armed
};


//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------
stock GetVehicleName(model, vehicleString[], lenght = sizeof(vehicleString))
{
    if (model < 400 || model > 611)
	{
        format(vehicleString, lenght, "Nenhum");
        return 1;
    }
    format(vehicleString, lenght, "%s", gscVehicleNames[model - 400]);
    return 1;
}

stock GetVehicleSpeed(vehicleid)
{
    static 
		Float:Vx = 0.0,
		Float:Vy = 0.0,
		Float:Vz = 0.0
	;
	GetVehicleVelocity(vehicleid, Vx, Vy, Vz);
	return floatround(VectorSize(Vx, Vy, Vz) * 136.666667);
}

stock bool:IsPlayerNearVehicle(Float:radi, playerid, vehicleid)
{
	new Float:PX, Float:PY, Float:PZ, Float:X, Float:Y, Float:Z;
    GetPlayerPos(playerid, PX, PY, PZ);
    GetVehiclePos(vehicleid, X, Y, Z);
    new Float:DistanceP = (X - PX) * (X - PX) + (Y - PY) * (Y - PY) + (Z - PZ) * (Z - PZ);
    if (DistanceP <= radi*radi)
    {
        return true;
    }
	return false;
}

// stock bool:IsVehicleOccupied(vehicleid)
// {
//     foreach(new i: Player)
//     {
//         if (!IsValidPlayer(i)) 
//         {
//             continue;
//         }
//         if (GetPlayerVehicleID(i) == vehicleid)
//         { 
//             return true;
//         }
//     }
//     return false;
// }

stock RepairVehicleCustom(vehicleid)
{
    if (IsValidVehicle(vehicleid))
    {
        Vehicle_SetHealth(vehicleid, 1000.0);
        SetVehicleHealth(vehicleid, 1000.0);
        RepairVehicle(vehicleid);
    }
    return 1;
}

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
