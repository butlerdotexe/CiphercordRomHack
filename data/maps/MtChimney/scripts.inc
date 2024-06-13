.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts:: @ 822EDC1
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition: @ 822EDCC
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume: @ 822EDD2
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie:: @ 822EDD5
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma:: @ 822EDF9
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting:: @ 822EE02
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie:: @ 822EE0B
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_ArchieExitEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast:: @ 822EEC7
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth:: @ 822EED2
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast:: @ 822EEDD
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth:: @ 822EEE8
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady:: @ 822EEF3
	lock
	faceplayer
	showmoneybox 0, 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE, 1
	compare VAR_RESULT, TRUE
	call_if_eq MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	compare VAR_RESULT, FALSE
	goto_if_eq MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull:: @ 822EF51
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney:: @ 822EF5E
	removemoney 200, 0
	updatemoneybox 0, 0
	return

MtChimney_EventScript_DeclineLavaCookie:: @ 822EF69
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney:: @ 822EF76
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast: @ 822EF83
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast: @ 822EF8B
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth: @ 822EF94
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth: @ 822EF9C
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1: @ 822EFA6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2: @ 822EFB8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3: @ 822EFC1
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4: @ 822EFD0
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5: @ 822EFE9
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6: @ 822EFF4
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7: @ 822F004
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8: @ 822F015
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

MtChimney_Movement_Unused9: @ 822F01D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10: @ 822F02B
	walk_down
	step_end

MtChimney_Movement_Unused11: @ 822F02D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12: @ 822F035
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13: @ 822F03F
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14: @ 822F04A
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15: @ 822F04F
	walk_left
	walk_in_place_fastest_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1:: @ 822F053
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2:: @ 822F05C
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3:: @ 822F065
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha:: @ 822F06E
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2:: @ 822F085
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1:: @ 822F09C
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2:: @ 822F0A5
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3:: @ 822F0AE
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4:: @ 822F0B7
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5:: @ 822F0C0
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6:: @ 822F0C9
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena:: @ 822F0D2
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena:: @ 822F0DB
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine:: @ 822F0E4
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone:: @ 822F123
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff:: @ 822F12D
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn:: @ 822F137
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign:: @ 822F141
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby:: @ 822F14A
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby:: @ 822F176
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby:: @ 822F195
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa:: @ 822F1AC
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila:: @ 822F1C3
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley:: @ 822F1DA
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1:: @ 822F1F1
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer:: @ 822F208
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated:: @ 822F234
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch:: @ 822F253
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano: @ 822F26A
	.string "If that nerd is right, this meteorite\n"
	.string "and this machine will cause a lot of\l"
	.string "chaos…\p"
	.string "Let's see what this thing can do.$"

MtChimney_Text_MaxieIntro: @ 822F32E
	.string "Fallen: Huh?\n"
	.string "Who the hell are you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh you're the kid who's been giving\n"
	.string "Rosa and Team Stall hell?\p"
	.string "Nice!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "You're here to stop me?\p"
	.string "Do you know who I am?\p"
	.string "Looks like I'll have to sac the\n"
	.string "shit out of you to remind you.\p"
	.string "Try to make this a little interesting\n"
	.string "for me, will you?$"

MtChimney_Text_MaxieDefeat: @ 822F5CF
	.string "What?!\p"
	.string "How could YOU possibly have won?$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma: @ 822F5F7
	.string "Fallen: Well, everyone gets lucky\n"
	.string "every once in a while.\p"
	.string "I'm still gonna push this button and\n"
	.string "see this shit explode though.\p"
	.string "Click!..."
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "What, nothing? Damn nerd was wrong.\n"
	.string "Guess I got unlucky twice today.$"

MtChimney_Text_TabithaIntro: @ 822F6AA
	.string "Oh uh hi.\p"
	.string "I'm Hochweisse, but you can call\n"
	.string "me Hoch.\p"
	.string "The boss is working on something so\n"
	.string "I've gotta hold you here for a sec.\p"
	.string "Nothing personal.$"

MtChimney_Text_TabithaDefeat: @ 822F72C
	.string "Wait did I just try to stall you…\p"
	.string "I feel weird about this plan…$"

MtChimney_Text_TabithaPostBattle: @ 822F76D
	.string "We are Team Aggro, but I was asked\n"
	.string "to stall whoever comes up here…$"

MtChimney_Text_Grunt2Intro: @ 822F7A2
	.string "We of Team Aggro are working hard for\n"
	.string "everyone's sake.\p"
	.string "Like, imagine if every Pokémon battle\n"
	.string "lasted for hours!\p"
	.string "That would suck!$"

MtChimney_Text_Grunt2Defeat: @ 822F83A
	.string "Hunh?\n"
	.string "What do you mean I lost?$"

MtChimney_Text_Grunt2PostBattle: @ 822F859
	.string "Our Boss says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"

MtChimney_Text_Grunt1Intro: @ 822F8B6
	.string "The boss is looking to cause chaos\n"
	.string "and enforce a rapid style of battle!\p"
	.string "…How are they related? Shut up!$"

MtChimney_Text_Grunt1Defeat: @ 822F921
	.string "You know, now that I think about it…$"

MtChimney_Text_Grunt1PostBattle: @ 822F93A
	.string "It doesn't really make sense…$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans: @ 822F978
	.string "That annoying Team Stall…\n"
	.string "They always take so long on their turn!$"

MtChimney_Text_MeteoritesPackAmazingPower: @ 822F9B2
	.string "Meteorites pack amazing power!$"

MtChimney_Text_YouBetterNotMessWithUs: @ 822F9D1
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"

MtChimney_Text_AquasNameSimilar: @ 822FA2F
	.string "We're Team Aggro!\p"
	.string "They're Team Stall!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"

MtChimney_Text_DouseThemInFire: @ 822FA8B
	.string "Yeah!\n"
	.string "Douse them in fire!$"

MtChimney_Text_KeepMakingMoreLand: @ 822FAA5
	.string "We're going to keep making more land!$"

MtChimney_Text_Bufoh: @ 822FACB
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma: @ 822FAD2
	.string "Rosa: {PLAYER}!\n"
	.string "How did it take you even longer than\l"
	.string "us, Team Stall, to show up??\n"
	.string "Whatever, do you see what I mean\n"
	.string "about these guys?\p"
	.string "Their leader is going to use the\p"
	.string "Meteorite to cause the volcano\l"
	.string "to errupt!$"

MtChimney_Text_ArchieIHaveMyHandsFull: @ 822FBC7
	.string "Rosa: I would stop Fallen myself,\n"
	.string "but three of them rushed me!\p"
	.string "You go ahead! I need to figure out\n"
	.string "what move I'm going to use…\p"
	.string "…Why should you help me? Bro I know\n"
	.string "we stole some stuff, but these guys\l"
	.string "are straight up committing terrorism\l"
	.string "right now!$"

MtChimney_Text_ArchieThankYou: @ 822FC3D
	.string "Rosa: {PLAYER}!\n"
	.string "Nice work!\p"
	.string "But uh…\n"
	.string "Whose side are you on?\p"
	.string "Ah well, doesn't really matter.\p"
	.string "Good job taking out those Team Aggro\n"
	.string "tools.\p"
	.string "{PLAYER}, we shall meet again!$"

MtChimney_Text_MagmaOutnumbersUs: @ 822FD1F
	.string "Darn… Team Aggro outnumbers us!\n"
	.string "And why do they keep yelling\l"
	.string "'Sac him! Sac him!'$"

MtChimney_Text_LessHabitatForWaterPokemon: @ 822FD5B
	.string "If they have their way, there won't\n"
	.string "be any thinking in battles!$"

MtChimney_Text_MagmasNameSimilar: @ 822FDA1
	.string "We're Team Stall!\p"
	.string "They're Team Aggro!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"

MtChimney_Text_Bushaa: @ 822FDFC
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200: @ 822FE04
	.string "Lava Cookies are Mt. Chimney's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"

MtChimney_Text_ThankYouDear: @ 822FE4D
	.string "Thank you, dear!$"

MtChimney_Text_YouveNotGotTheMoney: @ 822FE5E
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"

MtChimney_Text_OhFineThen: @ 822FE9B
	.string "Oh, fine then.$"

MtChimney_Text_MetoriteFittedOnMachine: @ 822FEAA
	.string "A Meteorite is fitted on a mysterious\n"
	.string "machine…\p"
	.string "The machine seems to be storing\n"
	.string "energy in the Meteorite.$"

MtChimney_Text_RemoveTheMeteorite: @ 822FF12
	.string "A Meteorite is fitted on a mysterious\n"
	.string "machine…\p"
	.string "Do you want to remove the Meteorite?$"

MtChimney_Text_PlayerRemovedMeteorite: @ 822FF66
	.string "{PLAYER} removed the Meteorite from\n"
	.string "the mysterious machine.$"

MtChimney_Text_PlayerLeftMeteorite: @ 822FF9C
	.string "{PLAYER} left the Meteorite where\n"
	.string "it was.$"

MtChimney_Text_MachineMakesNoResponse: @ 822FFC0
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"

MtChimney_Text_RouteSign: @ 822FFFA
	.string "{DOWN_ARROW} Jagged Pass\n"
	.string "Lavaridge Town Ahead$"

MtChimney_Text_ShelbyIntro: @ 823001D
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"

MtChimney_Text_ShelbyDefeat: @ 8230076
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostBattle: @ 82300A2
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an Expert now, can I?$"

MtChimney_Text_ShelbyRegister: @ 82300E3
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"

MtChimney_Text_ShelbyRematchIntro: @ 8230153
	.string "If you can mesh your heart with those\n"
	.string "of your Pokémon, why, you should be\l"
	.string "able to achieve great things.$"

MtChimney_Text_ShelbyRematchDefeat: @ 82301BB
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostRematch: @ 82301E7
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your Pokémon.$"

MtChimney_Text_MelissaIntro: @ 823022A
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"

MtChimney_Text_MelissaDefeat: @ 823026D
	.string "Ooh, that was a scorching-hot match!$"

MtChimney_Text_MelissaPostBattle: @ 8230292
	.string "The heat of Mt. Chimney warms\n"
	.string "me up, baby!$"

MtChimney_Text_SheilaIntro: @ 82302BD
	.string "I've finally made it to Mt. Chimney.\n"
	.string "I want to make my Pokémon battle!$"

MtChimney_Text_SheilaDefeat: @ 8230304
	.string "The way you battle…\n"
	.string "It's like a Mt. Chimney eruption!$"

MtChimney_Text_SheilaPostBattle: @ 823033A
	.string "Like I said, I've finally made it to\n"
	.string "Mt. Chimney. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "Cookies as souvenirs.$"

MtChimney_Text_ShirleyIntro: @ 82303DF
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"

MtChimney_Text_ShirleyDefeat: @ 8230436
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"

MtChimney_Text_ShirleyPostBattle: @ 8230463
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"

MtChimney_Text_SawyerIntro: @ 82304B3
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"

MtChimney_Text_SawyerDefeat: @ 82304F7
	.string "Oh, you're a real firebrand, too!$"

MtChimney_Text_SawyerPostBattle: @ 8230519
	.string "I think I need a dip in Lavaridge\n"
	.string "Hot Spring with the locals!$"

MtChimney_Text_SawyerRegister: @ 8230557
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my PokéNav.$"

MtChimney_Text_SawyerRematchIntro: @ 823059C
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"

MtChimney_Text_SawyerRematchDefeat: @ 82305E3
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"

MtChimney_Text_SawyerPostRematch: @ 8230614
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"
