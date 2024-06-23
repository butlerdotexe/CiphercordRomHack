EverGrandeCity_PhoebesRoom_MapScripts:: @ 8228174
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp: @ 8228184
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth:: @ 822818E
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame: @ 8228193
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor:: @ 822819D
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad: @ 82281AA
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 2
	call_if_eq EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82281BF
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor:: @ 82281C5
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe:: @ 82281CB
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch::
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeechRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
	switch VAR_ELITE_4_MODE
	case 0, EverGrandeCity_PhoebesRoom_EventScript_PhoebeSingles
	case 1, EverGrandeCity_PhoebesRoom_EventScript_PhoebeSinglesLegends
	case 2, EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoubles
	case 3, EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoublesLegends

EverGrandeCity_PhoebesRoom_EventScript_PhoebeSingles::
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeSinglesLegends::
	trainerbattle_no_intro TRAINER_PHOEBE_3, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoubles::
	trainerbattle_no_intro TRAINER_PHOEBE_2, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeDoublesLegends::
	trainerbattle_no_intro TRAINER_PHOEBE_4, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech:: @ 82281F2
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeechRematch::
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated:: @ 82281FC
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_DefeatedRematch::
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech: @ 822820E
	.string "Are you the guy that Penta's been\n"
	.string "nagging me about?\p"
	.string "You don't look too special. Let me see\n"
	.string "your team.\p"
	.string "… … …\p"
	.string "That's it? Where are the legendaries?\p"
	.string "You're telling me you made it this far\n"
	.string "with so few legendaries?\p"
	.string "Whatever dude. Let's just get this over\n"
	.string "with so I can go back to Genshin.$"

EverGrandeCity_PhoebesRoom_Text_Defeat: @ 8228325
	.string "WTF.$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech: @ 8228343
	.string "You actually sacced the shit out of me.\p"
	.string "It's ok. You have to fight Dovah next.\n"
	.string "And after him is Zelfie, and then Llew.\p"
	.string "In other words, it's up to Dovah and\p"
	.string "Llewellyn to gatekeep you from now on.$"

EverGrandeCity_PhoebesRoom_Text_IntroSpeechRematch:
	.string "Ahaha! I've been waiting for you!\p"
	.string "I'm bringing a little something\n"
	.string "new to the table this time!\p"
	.string "Prepare yourself and bring it on!$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeechRematch:
	.string "Hmmp, what a shame.\n"
	.string "I lost again, huh?\p"
	.string "But on the bright side…\n"
	.string "We fought together, so the bonds\l"
	.string "between my Pokémon and me got even\l" 
	.string "deeper!\p"
	.string "I look forward to being able to\n"
	.string "battle you again sometime!$"
