.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts:: @ 81DF385
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition: @ 81DF38B
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym:: @ 81DF3A9
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_GyroBallTM::
	lock
	faceplayer
	checkitem ITEM_TM74_GYRO_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_EventScript_ReceivedTM74
	msgbox MauvilleCity_Text_GiveTM74, MSGBOX_DEFAULT
	giveitem ITEM_TM74_GYRO_BALL
	msgbox MauvilleCity_Text_HaveTM74, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedTM74::
	msgbox MauvilleCity_Text_HaveTM74, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_Boy:: @ 81DF3B3
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac:: @ 81DF3BC
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman:: @ 81DF3C5
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy:: @ 81DF3CE
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign:: @ 81DF3D7
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign:: @ 81DF3E0
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign:: @ 81DF3E9
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign:: @ 81DF3F2
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_MoveTutorSign::
	msgbox MauvilleCity_Text_MoveTutorSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM:: @ 81DF3FB
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained:: @ 81DF413
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle:: @ 81DF41D
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally:: @ 81DF43D
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally:: @ 81DF452
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt:: @ 81DF4AD
	compare VAR_RESULT, YES
	call_if_eq MauvilleCity_EventScript_BattleWally
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth:: @ 81DF4E0
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast:: @ 81DF53D
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally:: @ 81DF593
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	compare VAR_FACING, DIR_NORTH
	call_if_eq MauvilleCity_EventScript_ScottApproachPlayerNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	compare VAR_FACING, DIR_NORTH
	call_if_eq MauvilleCity_EventScript_ScottExitNorth
	compare VAR_FACING, DIR_EAST
	call_if_eq MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth:: @ 81DF5F3
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast:: @ 81DF601
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth:: @ 81DF616
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast:: @ 81DF628
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally:: @ 81DF63A
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle:: @ 81DF683
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain:: @ 81DF690
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1: @ 81DF6A8
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1: @ 81DF6AE
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2: @ 81DF6B4
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2: @ 81DF6C0
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2: @ 81DF6CC
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2: @ 81DF6D0
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth: @ 81DF6D5
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast: @ 81DF6D8
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1: @ 81DF6DC
	delay_16
	walk_in_place_fastest_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1: @ 81DF6DF
	delay_16
	walk_in_place_fastest_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1: @ 81DF6E2
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1: @ 81DF6E8
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth: @ 81DF6EE
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth: @ 81DF6F3
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast: @ 81DF6F7
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2: @ 81DF6FA
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2: @ 81DF703
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth: @ 81DF70D
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast: @ 81DF719
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth: @ 81DF725
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast: @ 81DF72F
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson:: @ 81DF73A
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	compare VAR_NEW_MAUVILLE_STATE, 6
	goto_if_eq MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville:: @ 81DF77A
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville:: @ 81DF784
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM24_THUNDERBOLT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM24_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt:: @ 81DF7B0
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall:: @ 81DF7BA
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy: @ 81DF7DC
	.string "Uncle: Basil how many times have\n"
	.string "I told you, you're not ready to\l"
	.string "face this Gym.$"

MauvilleCity_Text_WallyWantToChallengeGym: @ 81DF845
	.string "Basil: Aww come on, Uncle.\p"
	.string "I know my Maractus can overcome\n"
	.string "any challenge.\p"
	.string "Just let me try.$"

MauvilleCity_Text_UncleYourePushingIt: @ 81DF8B9
	.string "Uncle: Look, Basil.\p"
	.string "Its great you beleive in your partner,\n"
	.string "but its simply not what you think it is.\p"
	.string "He is pretty strong, but in a Gym like\n"
	.string "that... it's too much.$"

MauvilleCity_Text_WallyWeCanBeatAnyone: @ 81DF963
	.string "Basil: You just don't believe in my\n"
	.string "Maractus's power!\p"
	.string "We can beat anyone!$"

MauvilleCity_Text_WallyWillYouBattleMe: @ 81DF9B2
	.string "Basil: Oh! {PLAYER}!\p"
	.string "Perfect timing- I need to ask you a\n"
	.string "favor.\p"
	.string "I want you and my Uncle to see how\n"
	.string "strong Maractus and I really are.\p"
	.string "{PLAYER}, will you battle with me?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong: @ 81DFA4A
	.string "Basil: Aw… If you won't battle me,\n"
	.string "{PLAYER}, my Uncle won't know that we\l"
	.string "can do this.$"

MauvilleCity_Text_UncleCanYouBattleWally: @ 81DFAA5
	.string "Uncle: {PLAYER}{KUN}, was it?\n"
	.string "On Basil's behalf, can I ask you to\l"
	.string "battle with him just this once?\p"
	.string "I think you can show him that he's\n"
	.string "being too stubborn right now.$"

MauvilleCity_Text_WallyPleaseBattleMe: @ 81DFB42
	.string "Basil.: {PLAYER}, please!\n"
	.string "Just this one battle.$"

MauvilleCity_Text_WallyHereICome: @ 81DFB6D
	.string "Basil: {PLAYER}, thank you.\p"
	.string "Okay… Here I come!$"

MauvilleCity_Text_WallyDefeat: @ 81DFB96
	.string "Basil: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "We lost…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf: @ 81DFBC3
	.string "Basil: Uncle…\n"
	.string "I'll go back to Verdanturf…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle: @ 81DFBED
	.string "{PLAYER}, thank you.\n"
	.string "Being a Trainer is tough, isn't it?\p"
	.string "It's not enough just to have Pokémon\n"
	.string "and make them battle. That isn't what\l"
	.string "being a real Trainer is about.$"

MauvilleCity_Text_UncleNoNeedToBeDown: @ 81DFC8A
	.string "Uncle: Basil, there's no need to be so\n"
	.string "down on yourself.\p"
	.string "It's great that you have a partner,\n"
	.string "but he might not be suited for this.\p"
	.string "Come on, let's go home.\n"
	.string "Everyone's waiting for you.$"

MauvilleCity_Text_UncleVisitUsSometime: @ 81DFD34
	.string "Uncle: {PLAYER}{KUN}, it just dawned on me\n"
	.string "that you must be the Trainer who kept\l"
	.string "an eye out for Basil when he caught\l"
	.string "his Pokémon.\p"
	.string "Why don't you visit us in Verdanturf\n"
	.string "sometime?\l"
	.string "I'm sure Basil would enjoy it.$"


MauvilleCity_Text_WallyPokenavCall: @ 81DFDFB
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Basil: Oh, hi, {PLAYER}!\p"
	.string "I just wanted to tell you that\n"
	.string "my uncle bought me a PokéNav!\p"
	.string "Now I can get in touch with you\n"
	.string "anytime, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_RegisteredWally: @ 81DFEB4
	.string "Registered Basil\n"
	.string "in the PokéNav.$"

MauvilleCity_Text_ScottYouDidntHoldBack: @ 81DFED5
	.string "Scott: Hehe…\n"
	.string "I was watching that match!\p"
	.string "You're friends with that boy Basil,\n"
	.string "aren't you?\p"
	.string "But you didn't hold anything back\n"
	.string "and crushed his hopes and dreams!\p"
	.string "Yeah! That's what a real Pokémon\n"
	.string "battle is all about!\p"
	.string "I idolize Trainers like that!\p"
	.string "… … … … … …\n"
	.string "I'll be cheering for you!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey: @ 81DFFE4
	.string "Semi: Oh, {PLAYER}{KUN}!\n"
	.string "Perfect, I was just looking for someone\l"
	.string "to pawn some work onto.\p"
	.string "See, Mauville City has an underground\n"
	.string "sector called New Mauville.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the Generator.\p"
	.string "Its been acting up lately, and needs to be\n"
	.string "reset before it explodes or something.\p"
	.string "Here, this is the Key to get in.$"

MauvilleCity_Text_WattsonWontBeChallenge: @ 81E0154
	.string "Semi: ...What? Is it dangerous\n"
	.string "Yeah probably.\p"
	.string "Anyway, the entrance is just a short\n"
	.string "Surf away from Route 110.\p"
	.string "Good luck!$"

MauvilleCity_Text_WattsonThanksTakeTM: @ 81E020E
	.string "Semi: Oh you actually did it?\p"
	.string "I mean uh, I knew you could do it\n"
	.string "never doubted you for a second.\p"
	.string "Here if you don't tell anyone about this,\n"
	.string "you can have this--Thunderbolt!$"

MauvilleCity_Text_WattsonYoungTakeCharge: @ 81E02AA
	.string "Semi: Alright, we're done here.\p"
	.string "Good luck with the rest of your adventure.$"

MauvilleCity_Text_NurseHurtMonBackToHealth: @ 81E0301
	.string "You know, it's cool to have Pokémon\n"
	.string "battles and stuff…\p"
	.string "But if your Pokémon gets hurt,\n"
	.string "you have to nurse it back to health.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough: @ 81E037C
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"

MauvilleCity_Text_RydelVeryGenerous: @ 81E03FB
	.string "Have you been to Rydel's Cycles yet?\p"
	.string "Rydel, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike: @ 81E044A
	.string "Even if you're riding a Bike,\n"
	.string "wild Pokémon could jump you.$"

MauvilleCity_Text_CitySign: @ 81E0485
	.string "Mauville City\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_GymSign: @ 81E04B7
	.string "Mauville City Pokémon Gym\n"
	.string "Leader: Semi\l"
	.string "“Basking in the sun.”$"

MauvilleCity_Text_BikeShopSign: @ 81E0504
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "Rydel's Cycles$"

MauvilleCity_Text_GameCornerSign: @ 81E053C
	.string "“The play spot for all!”\n"
	.string "Mauville Game Corner$"

MauvilleCity_Text_MoveTutorSign:
	.string "Mauville Move Tutor\n"
	.string "“Special moves for Starter Pokémon!”$"

MauvilleCity_Text_ExplainTV: @ 81E056A
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_BeenCheckingOutTV: @ 81E0699
	.string "Hi, have you been checking out TVs?$"

MauvilleCity_Text_GiveTM74:
	.string "Did you know that you can go from\n"
	.string "here a long way in that direction\l"
	.string "without changing direction?\p"
	.string "I might even be able to roll\n"
	.string "that way.\p"
	.string "Do you think your Pokémon will\n"
	.string "want to roll, too?\p"
	.string "Here, let them try out this TM\n"
	.string "if you'd like.$"

MauvilleCity_Text_HaveTM74:
	.string "TM74 contains Gyro Ball, an attack\n"
	.string "that does more damage the slower the\l"
	.string "user is compared to the foe.$"
