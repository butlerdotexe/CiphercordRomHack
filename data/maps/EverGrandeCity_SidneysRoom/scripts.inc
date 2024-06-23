EverGrandeCity_SidneysRoom_MapScripts:: @ 8227F01
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition: @ 8227F16
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad: @ 8227F1D
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 1
	call_if_eq EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom:: @ 8227F32
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor:: @ 8227F38
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp: @ 8227F3E
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth:: @ 8227F48
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame: @ 8227F4D
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor:: @ 8227F57
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney:: @ 8227F64
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_SidneysRoom_EventScript_SidneyRematch
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	setweather WEATHER_RAIN
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_SidneyRematch::
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeechRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
	switch VAR_ELITE_4_MODE
	case 0, EverGrandeCity_SidneysRoom_EventScript_SidneySingles
	case 1, EverGrandeCity_SidneysRoom_EventScript_SidneySinglesLegends
	case 2, EverGrandeCity_SidneysRoom_EventScript_SidneyDoubles
	case 3, EverGrandeCity_SidneysRoom_EventScript_SidneyDoublesLegends

EverGrandeCity_SidneysRoom_EventScript_SidneySingles::
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_SidneysRoom_EventScript_SidneySinglesLegends::
	trainerbattle_no_intro TRAINER_SIDNEY_3, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_SidneysRoom_EventScript_SidneyDoubles::
	trainerbattle_no_intro TRAINER_SIDNEY_2, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_SidneysRoom_EventScript_SidneyDoublesLegends::
	trainerbattle_no_intro TRAINER_SIDNEY_4, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech:: @ 8227F8B
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeechRematch::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated:: @ 8227F95
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	release
	end

EverGrandeCity_SidneysRoom_EventScript_DefeatedRematch::
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech: @ 8227FA7
	.string "fight now$"

EverGrandeCity_SidneysRoom_Text_Defeat: @ 82280A2
	.string "Wait. You beat me?$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech: @ 82280EC
	.string "But rain was supposed to be unbeatable.\n"
	.string "Like you have these broken water types…\p"
	.string "And you beat all of your counters with\n"
	.string "other mons…\p"
	.string "Must've gotten sacced.$"

EverGrandeCity_SidneysRoom_Text_IntroSpeechRematch:
	.string "I was waiting for you, Champion.\n"
	.string "No matter who wins, no hard feelings!\p"
	.string "Let's get our most excellent\n"
	.string "battle underway!$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeechRematch:
	.string "Heh…\n"
	.string "I knew you really were the strongest…\p"
	.string "Well, hurry up and get out of here!\n"
	.string "Everybody else is still waiting\l"
	.string "for you!$"
