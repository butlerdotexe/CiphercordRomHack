SootopolisCity_Gym_1F_MapScripts:: @ 8224E4C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition: @ 8224E61
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume: @ 8224E67
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad: @ 8224E6A
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles:: @ 8224E73
	compare VAR_ICE_STEP_COUNT, 8
	goto_if_lt SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	compare VAR_ICE_STEP_COUNT, 28
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	compare VAR_ICE_STEP_COUNT, 67
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs:: @ 8224EA6
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs:: @ 8224EB8
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, 0
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, 0
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs:: @ 8224ECA
	return

SootopolisCity_Gym_1F_OnFrame: @ 8224ECB
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs:: @ 8224EED
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs:: @ 8224F01
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs:: @ 8224F15
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce:: @ 8224F29
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce: @ 8224F42
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan:: @ 8224F44
	goto_if_set FLAG_DAILY_REMATCH_JUAN, SootopolisCity_Gym_1F_EventScript_AlreadyRematched
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_Gym_1F_EventScript_JuanRematch
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_Gym_1F_EventScript_GiveScald2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated:: @ 8224F82
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredKabutops, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	msgbox SootopolisCity_Gym_1F_Text_TakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveScald
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveScald:: @ 8224FD4
	giveitem ITEM_TM55_SCALD
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainScald, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_Gym_1F_EventScript_GiveScald2:: @ 8224FF7
	giveitem ITEM_TM55_SCALD
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainScald, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge:: @ 822501B
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	message SootopolisCity_Gym_1F_Text_JuanChooseFormat
	waitmessage
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, SootopolisCity_Gym_1F_EventScript_SetSingles
	case 1, SootopolisCity_Gym_1F_EventScript_SetDoubles
	case 2, SootopolisCity_Gym_1F_EventScript_Exit
	case 127, SootopolisCity_Gym_1F_EventScript_Exit
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_SetSingles::
	msgbox SootopolisCity_Gym_1F_Text_JuanAllowLegends, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_Gym_1F_EventScript_JuanSinglesRematch
	trainerbattle_no_intro TRAINER_JUAN_4, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	setflag FLAG_DAILY_REMATCH_JUAN
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_SetDoubles::
	msgbox SootopolisCity_Gym_1F_Text_JuanAllowLegends, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_Gym_1F_EventScript_JuanDoublesRematch
	trainerbattle_no_intro TRAINER_JUAN_5, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	setflag FLAG_DAILY_REMATCH_JUAN
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_JuanSinglesRematch::
	trainerbattle_no_intro TRAINER_JUAN_2, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	setflag FLAG_DAILY_REMATCH_JUAN
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_JuanDoublesRematch::
	trainerbattle_no_intro TRAINER_JUAN_3, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	setflag FLAG_DAILY_REMATCH_JUAN
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_AlreadyRematched::
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_Exit::
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymGuide:: @ 8225040
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory:: @ 8225055
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue:: @ 822505F
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue:: @ 822506F
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified:: @ 822507F
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue:: @ 8225089
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice: @ 8225093
	.string "Yo! How's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Sootopolis's Gym Leader Vance is\n"
	.string "a master of some of the most powerful\l"
	.string "pokemon you can get, Pseudo-Legends.\p"
	.string "If you fail the puzzle, each trainer\n"
	.string "below has a team built around one.\p"
	.string "Vance himself has a multiple, so make\n"
	.string "sure you have a winning strategy!\p"
	.string "Now get in there and proove you've\n"
	.string "got what it takes!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory: @ 82251AF
	.string "Yow! You've beaten even Juan, who\n"
	.string "was supposedly the best in all Hoenn!\p"
	.string "Okay! Check out your Trainer Card.\p"
	.string "If you've gotten all the Badges, you're\n"
	.string "set for the Pokémon League challenge!$"

SootopolisCity_Gym_1F_Text_JuanIntro: @ 8225268
	.string "WHO DARES DISTURB M-\p"
	.string "Oh. It's you.\p"
	.string "Did you have to show up now? I'm kind\n"
	.string "of in the middle of something here.\p"
	.string "Oh well. Let's just get this over with.$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat: @ 8225432
	.string "Alright cool take this.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge: @ 8225598
	.string "{PLAYER} received the Rain Badge\n"
	.string "from Vance.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis: @ 82255BE
	.string "That Badge grants you the power and\n"
	.string "authority of Lord Vance, forcing all\l"
	.string "Pokémon to obey your every command.\p"
	.string "It also lets you use the HM Waterfall.\n"
	.string "This Pokémon can do it for you though.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredKabutops:
	.string "Registered Kabutops in the\n"
	.string "PokéNav.$"

SootopolisCity_Gym_1F_Text_TakeThis:
	.string "You also get this TM.$"

SootopolisCity_Gym_1F_Text_ExplainScald: @ 82256C1
	.string "It's a good one, just use it…\p"
	.string "You know, I'm getting a bit too\n"
	.string "old for this.\p"
	.string "Maybe I should step down, and let\n"
	.string "let someone younger take my spot.\p"
	.string "… … … … … …/p"
	.string "But then we'd get someone like Comic…\n"
	.string "Maybe not.$"

SootopolisCity_Gym_1F_Text_RegisteredJuan: @ 822574D
	.string "Registered Gym Leader Vance\n"
	.string "in the PokéNav.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle: @ 8225778
	.string "… Why are you still here?\n"
	.string "Go beat the game already.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge: @ 8225865
	.string "There remains but one Badge to\n"
	.string "obtain in Hoenn.\p"
	.string "If you wish to challenge the Pokémon\n"
	.string "League, you must obtain the last\l"
	.string "Badge from the Gym in Fortree.$"

SootopolisCity_Gym_1F_Text_GymStatue: @ 82258FA
	.string "Sootopolis City Pokémon Gym$"

SootopolisCity_Gym_1F_Text_GymStatueCertified: @ 8225916
	.string "Sootopolis City Pokémon Gym\p"
	.string "Vance's Certified Trainers:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch: @ 8225950
	.string "Juan: Very Good!\n"
	.string "Let the dance begin!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat: @ 8225A2E
	.string "Ahahaha, you are the winner!\n"
	.string "You have defeated me again!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch: @ 8225A67
	.string "Juan: If I told you to become my\n"
	.string "apprentice, you will refuse, I am sure.\p"
	.string "I would like to make a gift of my coat\n"
	.string "to you.\p"
	.string "But again, you will refuse.\n"
	.string "I imagine that to be so.\p"
	.string "And that, my friend, is a certain sign\n"
	.string "of nobility!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons: @ 8225B48
	.string "Juan: Ah, no, no, no.\n"
	.string "You have with you but one Pokémon.\p"
	.string "I wish that you would return with\n"
	.string "two, perhaps more, Pokémon, please.$"

SootopolisCity_Gym_1F_Text_JuanChooseFormat:
	.string "Juan: Ah, this Gym had returned to its\n"
	.string "usual state of serenity…\p"
	.string "But our young typhoon has returned\n"
	.string "to put us to the test again!\p"
	.string "Well, my friend, most certainly!\p"
	.string "I shall be delighted to dance with you\n"
	.string "as often as you wish!\p"
	.string "So, how shall we do this?$"

SootopolisCity_Gym_1F_Text_JuanAllowLegends:
	.string "And would you allow me to dance with\n"
	.string "Legendary Pokémon?$"
