.set LOCALID_GRUNT, 1

SeafloorCavern_Entrance_MapScripts:: @ 823446E
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume: @ 8234474
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 255, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt:: @ 8234485
	lockall
	compare VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	goto_if_eq SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort:: @ 82344ED
	compare VAR_FACING, DIR_WEST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	compare VAR_FACING, DIR_EAST
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast:: @ 8234523
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest:: @ 823452E
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth:: @ 8234539
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep: @ 8234544
	.string "AHAHAHAHAHA!\n"
	.string "YOU FOOL!\p"
	.string "I can't beleive you surfed all the\n"
	.string "way here, dove down, and got here-\p"
	.string "But totally forgot about Team Aggro\n"
	.string "at Mossdeep Space Center!\p"
	.string "And now you need to dive back out,\n"
	.string "fly back, deal with that, and then\l"
	.string "make the same trip you JUST did again!$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort: @ 82346C8
	.string "AHAHAHAHAHA!\n"
	.string "You're so dumb!$"

