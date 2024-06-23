EverGrandeCity_DrakesRoom_MapScripts:: @ 822869C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp: @ 82286AC
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth:: @ 82286B6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame: @ 82286BB
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor:: @ 82286C5
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setweather WEATHER_SANDSTORM
	doweather
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad: @ 82286D2
	setweather WEATHER_SANDSTORM
	doweather
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 4
	call_if_eq EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82286E7
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor:: @ 82286ED
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake:: @ 82286F3
	setweather WEATHER_SANDSTORM
	doweather
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_DrakesRoom_EventScript_DrakeRematch
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeRematch::
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeechRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeechRematch, MSGBOX_DEFAULT
	switch VAR_ELITE_4_MODE
	case 0, EverGrandeCity_DrakesRoom_EventScript_DrakeSingles
	case 1, EverGrandeCity_DrakesRoom_EventScript_DrakeSinglesLegends
	case 2, EverGrandeCity_DrakesRoom_EventScript_DrakeDoubles
	case 3, EverGrandeCity_DrakesRoom_EventScript_DrakeDoublesLegends
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeSingles::
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeSinglesLegends::
	trainerbattle_no_intro TRAINER_DRAKE_3, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeDoubles::
	trainerbattle_no_intro TRAINER_DRAKE_2, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeDoublesLegends::
	trainerbattle_no_intro TRAINER_DRAKE_4, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech:: @ 822871A
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeechRematch::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated:: @ 8228724
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_DefeatedRematch::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech: @ 822873E
	.string "Do you know who I am?\p"
	.string "Yeah, I'm a Zephiel main. I'm a rude\n"
	.string "ass pimp motherfucker. As a Zephiel\p"
	.string "main I'm extremely talented in.\n"
	.string "either solitaire or jacking off\p"
	.string "because I ALWAYS play the game my\n"
	.string "own way. It may not matter if my Roy\p"
	.string "1's get dodged because as a pimp\n"
	.string "lord Zephiel main, I always hit that\p"
	.string "manakete regardless.\p"
	.string "While these bitch ass knock off\n"
	.string "Armads MCs promote on turn 4 I'm\p"
	.string "already boning people with cost 1\n"
	.string "Al. Speaking of these clearance bin\p"
	.string "Armads, they don't realized that my\n"
	.string "roots as a Zephiel play come from\p"
	.string "killing the real virgin Armads user,\n"
	.string "they can't even stand a chance to my\p"
	.string "power. And why stop there? Before the\n"
	.string "turn that your opponent will promote,\p"
	.string "you will flip 2 cards, grab your\n"
	.string "opponents hand IRL and shuffle it for\p"
	.string "them before giving it back and ripping\n"
	.string "their main promotion out of their hand.\p"
	.string "We Zephiel mains don't give a fuck if\n"
	.string "you mulligan for promotion because you\p"
	.string "still ain't gonna have it. Ike mains\n"
	.string "cower in fear, the Byleth's cower in\p"
	.string "fear, and the Oboro mains don't give\n"
	.string "a fuck but that's not important.\p"
	.string "You should watch out for us Zephiel\n"
	.string "mains unless you want to receive...\p"
	.string "THE MAD DICKENING!$"

EverGrandeCity_DrakesRoom_Text_Defeat: @ 8228895
	.string "That was rad.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech: @ 82288B0
	.string "You know, I don't even feel bad losing\n"
	.string "that. It was a good game.\p"
	.string "But you better fuck the Champion up,\n"
	.string "because if you do then I won't be\l"
	.string "second anymore.\p"
	.string "At this point I'll take third if those\n"
	.string "bastards stop the second place jokes.$"

EverGrandeCity_DrakesRoom_Text_IntroSpeechRematch:
	.string "Oh, I've been waitin' for you!\p"
	.string "My Pokémon and I are going to\n"
	.string "show you everything we've got!\p"
	.string "Well then, you had better\n"
	.string "get ready to try and stop me!$"



EverGrandeCity_DrakesRoom_Text_PostBattleSpeechRematch:
	.string "I got a glimpse inside your heart!\n"
	.string "There's nothing for me to say to you!\p"
	.string "Go forth, Trainer!\p"
	.string "Go on to your next challenge\n"
	.string "with your head held high!$"
