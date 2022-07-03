#include <YSI_Coding\y_hooks>

//------------------------- Definitions and constants -------------------------

//------------------------- Data (This section is for module-internal data. Make sure to make the accessor variable 'static') -------------------------

//------------------------- External API (Functions accessible from other modules. Use 'stock' and PascalCase.) -------------------------

//------------------------- Internal API (Functions to be used only inside of this module. Use 'static (stock)' and camelCase) -------------------------
stock ShowPlayerAnims(playerid)
{
    SendClientMessage(playerid, COLOR_WHITE, "Lista de Animações:");
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "/sentar /dance /animcopa /strip /gang /animdance /animcrack /animfood");
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "/animcolt /robman /creu /handsup(/hd) /angry /deitar(/relaxar) /fumar /hide(/hi)");
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "/vomitar /wave /taichi /getarrested /punheta /mijar /chat /gro");
	SendClientMessage(playerid, COLOR_LIGHTBLUE, "Para parar uma animação digite /stop ou aperte 'F'.");
	SendClientMessage(playerid, COLOR_LIGHTBLUE,"|__________________________________________________________|");
	return 1;
}

//------------------------- Implementation (This section contains the concrete implementation for this module inside of the callbacks) -------------------------
YCMD:animes(playerid, params[], help) = animslist;
YCMD:animslist(playerid, params[], help) 
{
    return ShowPlayerAnims(playerid);
}

YCMD:sentar(playerid, params[], help)
{
    if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

    ApplyAnimation(playerid, "PED", "SEAT_idle", 1.0, true, false, false, false, 0);
    Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:dance(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new danceStyle;
	if (sscanf(params, "d", danceStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /dance [1-4]");
	}
	if (danceStyle < 1 || danceStyle > 4)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /dance [1-4]");
	}

	switch(danceStyle)
	{
	    case 1: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE1);
	    case 2: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE2);
	    case 3: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE3);
	    case 4: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE4);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:animcopa(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animcopa [1-12]");
	}
	if (animStyle < 1 || animStyle > 12)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animcopa [1-12]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_in",4.1,false,true,true,true,1);
	    case 2: ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_loop",4.1,false,true,true,true,1);
	    case 3: ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_nod",4.1,false,true,true,true,1);
	    case 4: ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_out",4.1,false,true,true,true,1);
	    case 5: ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_shake",4.1,false,true,true,true,1);
	    case 6: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_in",4.1,false,true,true,true,1);
	    case 7: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_loop",4.1,false,true,true,true,1);
	    case 8: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_nod",4.1,false,true,true,true,1);
	    case 9: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_out",4.1,false,true,true,true,1);
	    case 10: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_shake",4.1,false,true,true,true,1);
	    case 11: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_think",4.1,false,true,true,true,1);
	    case 12: ApplyAnimation(playerid,"COP_AMBIENT","Coplook_watch",4.1,false,true,true,true,1);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:strip(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /strip [1-7]");
	}
	if (animStyle < 1 || animStyle > 7)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /strip [1-7]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"STRIP","strip_A",4.0,true,true,true,true,0);
	    case 2: ApplyAnimation(playerid,"STRIP","strip_B",4.0,true,true,true,true,0);
	    case 3: ApplyAnimation(playerid,"STRIP","strip_C",4.0,true,true,true,true,0);
	    case 4: ApplyAnimation(playerid,"STRIP","strip_D",4.0,true,true,true,true,0);
	    case 5: ApplyAnimation(playerid,"STRIP","strip_E",4.0,true,true,true,true,0);
	    case 6: ApplyAnimation(playerid,"STRIP","strip_F",4.0,true,true,true,true,0);
	    case 7: ApplyAnimation(playerid,"STRIP","strip_G",4.0,true,true,true,true,0);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:gang(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /gang [1-7]");
	}
	if (animStyle < 1 || animStyle > 7)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /gang [1-7]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"GANGS","hndshkaa",4.0,false,false,false,false,0);
	    case 2: ApplyAnimation(playerid,"GANGS","hndshkba",4.0,false,false,false,false,0);
	    case 3: ApplyAnimation(playerid,"GANGS","hndshkca",4.0,false,false,false,false,0);
	    case 4: ApplyAnimation(playerid,"GANGS","hndshkda",4.0,false,false,false,false,0);
	    case 5: ApplyAnimation(playerid,"GANGS","hndshkea",4.0,false,false,false,false,0);
	    case 6: ApplyAnimation(playerid,"GANGS","hndshkfa",4.0,false,false,false,false,0);
	    case 7: ApplyAnimation(playerid,"GANGS","hndshkga",4.0,false,false,false,false,0);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:animdance(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animdance [1-13]");
	}
	if (animStyle < 1 || animStyle > 13)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animdance [1-13]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"DANCING","bd_clap",4.1,false,true,true,true,1);
	    case 2: ApplyAnimation(playerid,"DANCING","bd_clap1",4.1,false,true,true,true,1);
	    case 3: ApplyAnimation(playerid,"DANCING","dance_loop",4.1,false,true,true,true,1);
	    case 4: ApplyAnimation(playerid,"DANCING","DAN_Down_A",4.1,false,true,true,true,1);
	    case 5: ApplyAnimation(playerid,"DANCING","DAN_Left_A",4.1,false,true,true,true,1);
	    case 6: ApplyAnimation(playerid,"DANCING","DAN_Loop_A",4.1,false,true,true,true,1);
	    case 7: ApplyAnimation(playerid,"DANCING","DAN_Right_A",4.1,false,true,true,true,1);
	    case 8: ApplyAnimation(playerid,"DANCING","DAN_Up_A",4.1,false,true,true,true,1);
	    case 9: ApplyAnimation(playerid,"DANCING","dnce_M_a",4.1,false,true,true,true,1);
	    case 10: ApplyAnimation(playerid,"DANCING","dnce_M_b",4.1,false,true,true,true,1);
	    case 11: ApplyAnimation(playerid,"DANCING","dnce_M_c",4.1,false,true,true,true,1);
	    case 12: ApplyAnimation(playerid,"DANCING","dnce_M_d",4.1,false,true,true,true,1);
	    case 13: ApplyAnimation(playerid,"DANCING","dnce_M_e",4.1,false,true,true,true,1);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:animcrack(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animcrack [1-9]");
	}
	if (animStyle < 1 || animStyle > 9)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animcrack [1-9]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_01",4.1,false,true,true,true,1);
		case 2: ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_02",4.1,false,true,true,true,1);
		case 3: ApplyAnimation(playerid,"CRACK","crckdeth1",4.1,false,true,true,true,1);
		case 4: ApplyAnimation(playerid,"CRACK","crckdeth2",4.1,false,true,true,true,1);
		case 5: ApplyAnimation(playerid,"CRACK","crckdeth3",4.1,false,true,true,true,1);
		case 6: ApplyAnimation(playerid,"CRACK","crckdeth4",4.1,false,true,true,true,1);
		case 7: ApplyAnimation(playerid,"CRACK","crckidle1",4.1,false,true,true,true,1);
		case 8: ApplyAnimation(playerid,"CRACK","crckidle2",4.1,false,true,true,true,1);
		case 9: ApplyAnimation(playerid,"CRACK","crckidle3",4.1,false,true,true,true,1);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:animfood(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animfood [1-33]");
	}
	if (animStyle < 1 || animStyle > 33)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animfood [1-33]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"FOOD","EAT_Burger",4.1,false,true,true,true,1);
		case 2: ApplyAnimation(playerid,"FOOD","EAT_Chicken",4.1,false,true,true,true,1);
		case 3: ApplyAnimation(playerid,"FOOD","EAT_Pizza",4.1,false,true,true,true,1);
		case 4: ApplyAnimation(playerid,"FOOD","EAT_Vomit_P",4.1,false,true,true,true,1);
		case 5: ApplyAnimation(playerid,"FOOD","EAT_Vomit_SK",4.1,false,true,true,true,1);
		case 6: ApplyAnimation(playerid,"FOOD","FF_Dam_Bkw",4.1,false,true,true,true,1);
		case 7: ApplyAnimation(playerid,"FOOD","FF_Dam_Fwd",4.1,false,true,true,true,1);
		case 8: ApplyAnimation(playerid,"FOOD","FF_Dam_Left",4.1,false,true,true,true,1);
		case 9: ApplyAnimation(playerid,"FOOD","FF_Dam_Right",4.1,false,true,true,true,1);
		case 10: ApplyAnimation(playerid,"FOOD","FF_Die_Bkw",4.1,false,true,true,true,1);
		case 11: ApplyAnimation(playerid,"FOOD","FF_Die_Fwd",4.1,false,true,true,true,1);
		case 12: ApplyAnimation(playerid,"FOOD","FF_Die_Left",4.1,false,true,true,true,1);
		case 13: ApplyAnimation(playerid,"FOOD","FF_Die_Right",4.1,false,true,true,true,1);
		case 14: ApplyAnimation(playerid,"FOOD","FF_Sit_Eat1",4.1,false,true,true,true,1);
		case 15: ApplyAnimation(playerid,"FOOD","FF_Sit_Eat2",4.1,false,true,true,true,1);
		case 16: ApplyAnimation(playerid,"FOOD","FF_Sit_Eat3",4.1,false,true,true,true,1);
		case 17: ApplyAnimation(playerid,"FOOD","FF_Sit_In",4.1,false,true,true,true,1);
		case 18: ApplyAnimation(playerid,"FOOD","FF_Sit_In_L",4.1,false,true,true,true,1);
		case 19: ApplyAnimation(playerid,"FOOD","FF_Sit_In_R",4.1,false,true,true,true,1);
		case 20: ApplyAnimation(playerid,"FOOD","FF_Sit_Look",4.1,false,true,true,true,1);
		case 21: ApplyAnimation(playerid,"FOOD","FF_Sit_Loop",4.1,false,true,true,true,1);
		case 22: ApplyAnimation(playerid,"FOOD","FF_Sit_Out_180",4.1,false,true,true,true,1);
		case 23: ApplyAnimation(playerid,"FOOD","FF_Sit_Out_L_180",4.1,false,true,true,true,1);
		case 24: ApplyAnimation(playerid,"FOOD","FF_Sit_Out_R_180",4.1,false,true,true,true,1);
		case 25: ApplyAnimation(playerid,"FOOD","SHP_Thank",4.1,false,true,true,true,1);
		case 26: ApplyAnimation(playerid,"FOOD","SHP_Tray_In",4.1,false,true,true,true,1);
		case 27: ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift",4.1,false,true,true,true,1);
		case 28: ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_In",4.1,false,true,true,true,1);
		case 29: ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_Loop",4.1,false,true,true,true,1);
		case 30: ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_Out",4.1,false,true,true,true,1);
		case 31: ApplyAnimation(playerid,"FOOD","SHP_Tray_Out",4.1,false,true,true,true,1);
		case 32: ApplyAnimation(playerid,"FOOD","SHP_Tray_Pose",4.1,false,true,true,true,1);
		case 33: ApplyAnimation(playerid,"FOOD","SHP_Tray_Return",4.1,false,true,true,true,1);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:animcolt(playerid, params[], help)
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
	    return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
	new animStyle;
	if (sscanf(params, "d", animStyle))
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animcolt [1-7]");
	}
	if (animStyle < 1 || animStyle > 7)
	{
		return SendClientMessage(playerid, 0xFF0000FF, "> USE /animcolt [1-7]");
	}

	switch(animStyle)
	{
	    case 1: ApplyAnimation(playerid,"COLT45","2guns_crouchfire",4.1,false,true,true,true,1);
		case 2: ApplyAnimation(playerid,"COLT45","colt45_crouchfire",4.1,false,true,true,true,1);
		case 3: ApplyAnimation(playerid,"COLT45","colt45_crouchreload",4.1,false,true,true,true,1);
		case 4: ApplyAnimation(playerid,"COLT45","colt45_fire",4.1,false,true,true,true,1);
		case 5: ApplyAnimation(playerid,"COLT45","colt45_fire_2hands",4.1,false,true,true,true,1);
		case 6: ApplyAnimation(playerid,"COLT45","colt45_reload",4.1,false,true,true,true,1);
		case 7: ApplyAnimation(playerid,"COLT45","sawnoff_reload",4.1,false,true,true,true,1);
	}
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:robman(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, true, false, false, false, 0); // Rob
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:creu(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid,"CHOPPA","CHOPPA_back",4.1,true, true, true, true,1);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:handsup(playerid, params[], help)
{
	// Verificações
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}
    if (Player_GetWantedLevel(playerid) == 0)
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você só pode usar este comando procurado, use /hide em outras situações!");
	}

	// Execução do Comando
	new string[150];
	format(string, sizeof(string), "* Suspeito %s digitou: /handsup com: Vida[%.0f] Colete[%.0f].", GetPlayerNameCustom(playerid), GetPlayerHealthCustom(playerid), GetPlayerArmourCustom(playerid));
	SendMessageInRange(30.0, playerid, string, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE, COLOR_LIGHTBLUE);
	SetPlayerSpecialAction(playerid, 10);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}



YCMD:angry(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid,"RIOT","RIOT_ANGRY",4.0,false,false,false,false,0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:deitar(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "BEACH", "bather", 4.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:fumar(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "SMOKING", "F_smklean_loop", 4.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:hi(playerid, params[], help) = hide;
YCMD:hide(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "ped", "cower", 3.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:vomitar(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, false, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:wave(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:taichi(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:getarrested(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid,"ped", "ARRESTgun", 4.0, false, true, true, true, -1);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:punheta(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid,"PAULNMAC", "wank_loop", 1.800001, true, false, false, true, 600);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:mijar(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	SetPlayerSpecialAction(playerid, 68);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:chat(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:gro(playerid, params[], help)
{
	if (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
	{
		return SendClientMessage(playerid, COLOR_GRAD1, "Você não pode usar este comando dentro de um veículo!");
	}

	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, true, false, false, false, 0);
	Player_SetAnimationStatus(playerid, true);
	return 1;
}

YCMD:stopanim(playerid, params[], help) = pararanim;
YCMD:pararanim(playerid, params[], help)
{
	if (!IsValidPlayer(playerid))
	{
	    return 1;
	}

	Player_SetAnimationStatus(playerid, false);
	ClearAnimations(playerid);
	return 1;
}

