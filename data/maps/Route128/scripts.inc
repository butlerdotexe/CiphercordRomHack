.set LOCALID_STEVEN, 3
.set LOCALID_ARCHIE, 4
.set LOCALID_MAXIE, 5

Route128_MapScripts:: @ 81F6B38
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_OnFrame
	.byte 0

Route128_OnTransition: @ 81F6B43
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route128_OnFrame: @ 81F6B4D
	map_script_2 VAR_ROUTE128_STATE, 1, Route128_EventScript_KyogreAwakenedScene
	.2byte 0

Route128_EventScript_KyogreAwakenedScene:: @ 81F6B57
	lockall
	delay 20
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieLookAround
	waitmovement 0
	msgbox Route128_Text_ArchieWhatHappened, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieBackUp
	waitmovement 0
	msgbox Route128_Text_ArchieIOnlyWanted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachArchie
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_MaxieDoYouUnderstandNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_MaxieResposibilityFallsToArchieAndMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieRunLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieWalkLeft
	waitmovement 0
	msgbox Route128_Text_MaxieThisDefiesBelief, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieExit
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieExit
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_ARCHIE
	delay 100
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject LOCALID_STEVEN
	applymovement LOCALID_STEVEN, Route128_Movement_StevenApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route128_Text_StevenWhatIsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route128_Movement_StevenWalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_StevenWholeWorldWillDrown, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route128_Text_StevenImGoingToSootopolis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE128_STATE, 2
	releaseall
	end

Route128_Movement_Unused1: @ 81F6C76
	walk_fast_left
	step_end

Route128_Movement_Unused2: @ 81F6C78
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route128_Movement_StevenWalkUp: @ 81F6C85
	walk_up
	step_end

Route128_Movement_StevenApproachPlayer: @ 81F6C87
	walk_fast_left
	step_end

Route128_Movement_ArchieLookAround: @ 81F6C89
	walk_fast_down
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

Route128_Movement_ArchieBackUp: @ 81F6C91
	lock_facing_direction
	walk_slow_up
	delay_16
	unlock_facing_direction
	step_end

Route128_Movement_ArchieRunLeft: @ 81F6C96
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_right
	step_end

Route128_Movement_ArchieExit: @ 81F6C9B
	delay_16
	delay_16
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieWalkLeft: @ 81F6CA8
	walk_left
	walk_left
	delay_8
	delay_4
	step_end

Route128_Movement_MaxieApproachArchie: @ 81F6CAD
	walk_left
	walk_in_place_fastest_down
	step_end

Route128_Movement_MaxieExit: @ 81F6CB0
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieApproachPlayer: @ 81F6CBB
	walk_right
	walk_in_place_fastest_down
	step_end

Route128_EventScript_Isaiah:: @ 81F6CBE
	trainerbattle_single TRAINER_ISAIAH_1, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat
	msgbox Route128_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_RegisterIsaiah:: @ 81F6CEA
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route128_Text_IsaiahRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAIAH_1
	release
	end

Route128_EventScript_RematchIsaiah:: @ 81F6D09
	trainerbattle_rematch TRAINER_ISAIAH_1, Route128_Text_IsaiahRematchIntro, Route128_Text_IsaiahRematchDefeat
	msgbox Route128_Text_IsaiahPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Katelyn:: @ 81F6D20
	trainerbattle_single TRAINER_KATELYN_1, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat
	msgbox Route128_Text_KatelynPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_RegisterKatelyn:: @ 81F6D4C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route128_Text_KatelynRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KATELYN_1
	release
	end

Route128_EventScript_RematchKatelyn:: @ 81F6D6B
	trainerbattle_rematch TRAINER_KATELYN_1, Route128_Text_KatelynRematchIntro, Route128_Text_KatelynRematchDefeat
	msgbox Route128_Text_KatelynPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Alexa:: @ 81F6D82
	trainerbattle_single TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat
	msgbox Route128_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Ruben:: @ 81F6D99
	trainerbattle_single TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat
	msgbox Route128_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Wayne:: @ 81F6DB0
	trainerbattle_single TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat
	msgbox Route128_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Harrison:: @ 81F6DC7
	trainerbattle_single TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat
	msgbox Route128_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Carlee:: @ 81F6DDE
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat
	msgbox Route128_Text_CarleePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_Text_ArchieWhatHappened: @ 81F6DF5
	.string "Rosa: Ooooh shiiit…\n"
	.string "This is not good…$"

Route128_Text_ArchieIOnlyWanted: @ 81F6E48
	.string "I…\n"
	.string "I only wanted to stall…$"

Route128_Text_MaxieDoYouUnderstandNow: @ 81F6E5A
	.string "Fallen: AHAHAHA!\n"
	.string "Gottem!\p"
	.string "Hey nice job kid, making two\n"
	.string "legendary Pokémon go wild!\p"
	.string "It's only fair that you ruin Team\n"
	.string "Stall's plan since you ruined\l"
	.string "ours first!$"

Route128_Text_MaxieResposibilityFallsToArchieAndMe: @ 81F6F1E
	.string "Fallen: Man this is gonna be brutal.\p"
	.string "You called what I was doing terrorism?\n"
	.string "Well this…\p"
	.string "This is gonna be a REAL shitshow!\p"
	.string "Two legendary Pokémon beating the shit\n"
	.string "out of each other is gonna do way\l"
	.string "more damage than I ever could!$"

Route128_Text_MaxieThisDefiesBelief: @ 81F704F
	.string "Fallen: Even when I lose, I win!$"

Route128_Text_StevenWhatIsHappening: @ 81F70C9
	.string "Penta: {PLAYER}{KUN}!\n"
	.string "What the hell is going on?$"

Route128_Text_StevenWholeWorldWillDrown: @ 81F70EA
	.string "This huge rain cloud is spreading\n"
	.string "from above Sootopolis…\p"
	.string "What in the world is taking place there?\p"
	.string "There's no point arguing here…\n"
	.string "Sootopolis might provide answers…$"

Route128_Text_StevenImGoingToSootopolis: @ 81F721B
	.string "{PLAYER}{KUN}…\n"
	.string "I'm going to Sootopolis.$"

