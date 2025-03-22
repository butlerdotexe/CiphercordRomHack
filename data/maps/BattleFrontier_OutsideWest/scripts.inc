.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts:: @ 823D3E1
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition: @ 823D3E7
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant:: @ 823D3F0
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination:: @ 823D416
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket:: @ 823D44E
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport:: @ 823D458
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove:: @ 823D483
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination:: @ 823D4AE
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry:: @ 823D4BA
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect:: @ 823D4D8
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign:: @ 823D4E2
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign:: @ 823D4EB
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign:: @ 823D4F4
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1:: @ 823D50F
	trainerbattle_single TRAINER_BENJAMIN_4, BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, BattleFrontier_OutsideWest_Text_Llama_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Llama_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2:: @ 823D518
	trainerbattle_single TRAINER_CAMERON_5, BattleFrontier_OutsideWest_Text_Luna_Pre_Battle, BattleFrontier_OutsideWest_Text_Luna_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Luna_Post_Battle, MSGBOX_AUTOCLOSE
	end


BattleFrontier_OutsideWest_EventScript_Man1:: @ 823D52D
	msgbox BattleFrontier_OutsideWest_Text_Basil_Reflecting, MSGBOX_DEFAULT
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_Basil_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DYLAN_2, BattleFrontier_OutsideWest_Text_Basil_Post1
	trainerbattle_no_intro TRAINER_DYLAN_3, BattleFrontier_OutsideWest_Text_Basil_Post2
	trainerbattle_no_intro TRAINER_MARIA_3, BattleFrontier_OutsideWest_Text_Basil_Post3
	trainerbattle_no_intro TRAINER_MARIA_2, BattleFrontier_OutsideWest_Text_Basil_Post4
	trainerbattle_no_intro TRAINER_DYLAN_4, BattleFrontier_OutsideWest_Text_Basil_Defeat
	msgbox BattleFrontier_OutsideWest_Text_Basil_Post, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Maniac1:: @ 823D536
	trainerbattle_single TRAINER_ABIGAIL_2, BattleFrontier_OutsideWest_Text_Catmoon_Pre_Battle, BattleFrontier_OutsideWest_Text_Catmoon_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Catmoon_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Maniac2:: @ 823D53D
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BENJAMIN_2, BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons
	msgbox BattleFrontier_OutsideWest_Text_Arte_Transition, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BENJAMIN_3, BattleFrontier_OutsideWest_Text_Arte_Defeat
	msgbox BattleFrontier_OutsideWest_Text_Arte_Defeat, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk:: @ 823D544
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFastestUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper:: @ 823D57F
	trainerbattle_single TRAINER_ABIGAIL_3, BattleFrontier_OutsideWest_Text_Exalt_Pre_Battle, BattleFrontier_OutsideWest_Text_Exalt_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Exalt_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory:: @ 823D5BA
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory:: @ 823D5C5
	return

BattleFrontier_OutsideWest_EventScript_Girl:: @ 823D5C6
	trainerbattle_single TRAINER_PABLO_5, BattleFrontier_OutsideWest_Text_Fox_Pre_Battle, BattleFrontier_OutsideWest_Text_Fox_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Fox_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth:: @ 823D5FD
	trainerbattle_single TRAINER_CATHERINE_5, BattleFrontier_OutsideWest_Text_Poi_Pre_Battle, BattleFrontier_OutsideWest_Text_Poi_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Poi_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth:: @ 823D608
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest:: @ 823D613
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast:: @ 823D61E
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth: @ 823D629
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth: @ 823D62C
	walk_in_place_fastest_up
	walk_in_place_fastest_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest: @ 823D62F
	walk_in_place_fastest_right
	walk_in_place_fastest_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast: @ 823D632
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2:: @ 823D635
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_Playsalot_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PABLO_2, BattleFrontier_OutsideWest_Text_Playsalot_Post1
	trainerbattle_no_intro TRAINER_PABLO_3, BattleFrontier_OutsideWest_Text_Playsalot_Post2
	msgbox BattleFrontier_OutsideWest_Text_Playsalot_Post2, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors:: @ 823D653
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors:: @ 823D65D
	trainerbattle_single TRAINER_CORY_5, BattleFrontier_OutsideWest_Text_Gamma_Pre_Battle, BattleFrontier_OutsideWest_Text_Gamma_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Gamma_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1:: @ 823D667
	trainerbattle_single TRAINER_MARIA_4, BattleFrontier_OutsideWest_Text_Jay_Pre_Battle, BattleFrontier_OutsideWest_Text_Jay_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Jay_Post_Battle, MSGBOX_AUTOCLOSE
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3:: @ 823D670
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman:: @ 823D679
	trainerbattle_single TRAINER_WALTER_5, BattleFrontier_OutsideWest_Text_Flight_Pre_Battle, BattleFrontier_OutsideWest_Text_Flight_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Flight_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Lass:: @ 823D682
	trainerbattle_single TRAINER_ISAIAH_5, BattleFrontier_OutsideWest_Text_CM_Pre_Battle, BattleFrontier_OutsideWest_Text_CM_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_CM_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_ExpertM:: @ 823D68B
	trainerbattle_single TRAINER_JENNY_5, BattleFrontier_OutsideWest_Text_Rosa_Pre_Battle, BattleFrontier_OutsideWest_Text_Rosa_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Rosa_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Man2:: @ 823D694
	trainerbattle_single TRAINER_ABIGAIL_4, BattleFrontier_OutsideWest_Text_Luka_Pre_Battle, BattleFrontier_OutsideWest_Text_Luka_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Luka_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFontier_OutsideWest_EventScript_Woman1:: @ 823D69D
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_Playsalot_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PABLO_2, BattleFrontier_OutsideWest_Text_Playsalot_Post1
	trainerbattle_no_intro TRAINER_PABLO_3, BattleFrontier_OutsideWest_Text_Playsalot_Post2
	msgbox BattleFrontier_OutsideWest_Text_Playsalot_Post2, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_FatMan1:: @ 823D6A6
	trainerbattle_single TRAINER_ROXANNE_2, BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, BattleFrontier_OutsideWest_Text_Brain_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Brain_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_FatMan2:: @ 823D6AF
	trainerbattle_single TRAINER_PABLO_4, BattleFrontier_OutsideWest_Text_RNG_Pre_Battle, BattleFrontier_OutsideWest_Text_RNG_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_RNG_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Woman3:: @ 823D6B8
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_Yurtz_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROBERT_5, BattleFrontier_OutsideWest_Text_Yurtz_Post1
	trainerbattle_no_intro TRAINER_JACKSON_5, BattleFrontier_OutsideWest_Text_Yurtz_Post2
	msgbox BattleFrontier_OutsideWest_Text_Yurtz_Post2, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Boy2:: @ 823D6C3
	trainerbattle_single TRAINER_FERNANDO_5, BattleFrontier_OutsideWest_Text_Chi_Pre_Battle, BattleFrontier_OutsideWest_Text_Chi_Post_Battle_1
	msgbox BattleFrontier_OutsideWest_Text_Chi_Post_Battle_2, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_OldMan:: @ 823D6CE
	trainerbattle_single TRAINER_KOJI_5, BattleFrontier_OutsideWest_Text_Sonicite_Pre_Battle, BattleFrontier_OutsideWest_Text_Sonicite_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Sonicite_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_Man4:: @ 823D6D7
	trainerbattle_single TRAINER_ERNEST_5, BattleFrontier_OutsideWest_Text_Kase_Pre_Battle, BattleFrontier_OutsideWest_Text_Kase_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Kase_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_EventScript_PokefanF:: @ 823D6EE
	trainerbattle_single TRAINER_KATELYN_5, BattleFrontier_OutsideWest_Text_Sharp_Pre_Battle, BattleFrontier_OutsideWest_Text_Sharp_Post_Battle
	msgbox BattleFrontier_OutsideWest_Text_Sharp_Post_Battle, MSGBOX_AUTOCLOSE
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign: @ 823D6F7
	.string "This is the BATTLE DOME!\n"
	.string "Your path to the invincible superstar!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign: @ 823D737
	.string "This is the BATTLE FACTORY!\n"
	.string "Seek out the toughest Pokémon!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign: @ 823D772
	.string "This is the BATTLE PIKE!\n"
	.string "Choose one of three paths!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower: @ 823D7A6
	.string "This is the Battle Tower.\p"
	.string "Trainers bring their best-raised\n"
	.string "Pokémon for elimination-style matches.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket: @ 823D808
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your Ticket?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard: @ 823D842
	.string "{PLAYER} doesn't have the Ticket…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a Ticket to board\n"
	.string "the ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo: @ 823D89D
	.string "{PLAYER} flashed the Ticket.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

BattleFrontier_OutsideWest_Text_SlateportItIs: @ 823D8F2
	.string "Slateport City it is, then!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs: @ 823D90E
	.string "Lilycove City it is, then!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime: @ 823D929
	.string "Please sail with us another time!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry: @ 823D94B
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo: @ 823D97A
	.string "Then, where would you like to go?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends: @ 823D99C
	.string "So you also beat this hell that\n"
	.string "That the cursed duo cooked up?\p"
	.string "Well, the team I used is way\n"
	.string "better than yours!$"

BattleFrontier_OutsideWest_Text_Llama_Post_Battle:
	.string "That shit was worse than losing\n"
	.string "to a 10 support.$"

BattleFrontier_OutsideWest_Text_Catmoon_Pre_Battle:
	.string "This postgame took so long to come\n"
	.string "out, I came out before it did.$"

BattleFrontier_OutsideWest_Text_Catmoon_Post_Battle:
	.string "…Still a no on joining the Lissa\n"
	.string "fan club?$"

BattleFrontier_OutsideWest_Text_Exalt_Pre_Battle:
	.string "What do you want? I nerfed Team\n"
	.string "Aggro already- hell I fuckin'\l"
	.string "remade the whole hideout.\n"
	.string "You got a problem still?\p"
	.string "Come at me, bitch!$"

BattleFrontier_OutsideWest_Text_Exalt_Post_Battle:
	.string "…Well you have to admit, at\n"
	.string "least Team Aggro isn't a wet\l"
	.string "noodle like Team Stall.$"

BattleFrontier_OutsideWest_Text_Luka_Pre_Battle:
	.string "I played this game on actual\n"
	.string "hardware, so I didn't get any\l"
	.string "of the updates.\p"
	.string "Actually, if I want to see this\n"
	.string "fight, I have to redownload it\l"
	.string "and play through it all again…$"

BattleFrontier_OutsideWest_Text_Luka_Post_Battle:
	.string "Welp, back to Spara I go…$" 

BattleFrontier_OutsideWest_Text_Basil_Reflecting:
	.string "Man, I'm glad this is over.\p"
	.string "So much tedious work- collecting\n"
	.string "favorites, building teams with\p"
	.string "random bullshit, writing 300+\n"
	.string "fights worth of dialogue,\p"
	.string "dealing with Exalt and Brain\n"
	.string "arguing over everything…\p"
	.string "…But it was a lot of fun.$"

BattleFrontier_OutsideWest_Text_Basil_Intro:
	.string "So thanks for playing, and\n"
	.string "making it all the way here.\p"
	.string "Now if you'll indulge me a\n"
	.string "bit, there's this idea for\l"
	.string "a doubles lead I want to try.\p"
	.string "You beat the game, so if it\n"
	.string "beats you that's a good sign.$"

BattleFrontier_OutsideWest_Text_Basil_Post1:
	.string "Hm, that didn't quite work.\p"
	.string "Oh wait, let's try this!$"

BattleFrontier_OutsideWest_Text_Basil_Post2:
	.string "That's no good either…\p"
	.string "Okay, these two should\n"
	.string "DEFINITELY work!$"

BattleFrontier_OutsideWest_Text_Basil_Post3:
	.string "Damn. Well, you are the champ\n"
	.string "after all.\p"
	.string "Even my little tricks aren't\n"
	.string "enough…\p"
	.string "Well, you're up for a few\n"
	.string "more now, right?$"

BattleFrontier_OutsideWest_Text_Basil_Post4:
	.string "Jeez, you beat 4 doubles combos\n"
	.string "in a row. You've definitely\l"
	.string "earned your title.\p"
	.string "Alright, last one, I promise.$"

BattleFrontier_OutsideWest_Text_Basil_Defeat:
	.string "Alright, you got me.$"

BattleFrontier_OutsideWest_Text_Basil_Post:
	.string "Seriously though, thanks for\n"
	.string "playing the hack.\p"
	.string "Also, everyone else here is\n"
	.string "someone who's played through\l"
	.string "and beaten the game in the beta-\p"
	.string "so it would be cool if you\n"
	.string "checked out all of their teams\l"
	.string "too, if you don't mind.\p"
	.string "I did let them get a little…\n"
	.string "creative… with what they can\l"
	.string "do for this section…\p"
	.string "But I'm sure you'll be fine!$"

BattleFrontier_OutsideWest_Text_Jay_Pre_Battle:
	.string "True beauty lies in the heart!\n"
	.string "The heart that is capable of love!$"

BattleFrontier_OutsideWest_Text_Jay_Post_Battle:
	.string "You should really read Pokémon\n"
	.string "Special if you haven't yet.$"

BattleFrontier_OutsideWest_Text_Playsalot_Intro:
	.string "You may have beaten me before,\n"
	.string "but now I can have a double\l"
	.string "battle!$"

BattleFrontier_OutsideWest_Text_Playsalot_Post1:
	.string "You're lucky Room Service isn't\n"
	.string "in this game…\p"
	.string "Alright, back to singles!$"

BattleFrontier_OutsideWest_Text_Playsalot_Post2:
	.string "Well, guess I just have to\n"
	.string "play some more.$"

BattleFrontier_OutsideWest_Text_RNG_Pre_Battle:
	.string "TCG Pocket caps damage at 990,\n"
	.string "which is lame. TCG Live let\p"
	.string "someone do 700 MILLION, so it\n"
	.string "is clearly the superior game.$"

BattleFrontier_OutsideWest_Text_RNG_Post_Battle:
	.string "This game is worse than both\n"
	.string "of them though.$"

BattleFrontier_OutsideWest_Text_Fox_Pre_Battle:
	.string "Morning! Are you here for my daily\n"
	.string "daily fox post?\p"
	.string "… … …\p"
	.string "Oh, so it's a battle you want?\p"
	.string "Fiiine, but you still have to\n"
	.string "look at this fox!$"

BattleFrontier_OutsideWest_Text_Fox_Post_Battle:
	.string "Oh well, see you for tomorrow's\n"
	.string "fox!$"

BattleFrontier_OutsideWest_Text_Sharp_Pre_Battle:
	.string "Hope you brought Excadrill.$"

BattleFrontier_OutsideWest_Text_Sharp_Post_Battle:
	.string "Welp, guess I have to buff this\n"
	.string "team again.$"

BattleFrontier_OutsideWest_Text_CM_Pre_Battle:
	.string "I was going to throw myself into\n"
	.string "the ocean after seeing all of\l"
	.string "the bullshit in this game,\p"
	.string "but I suppose I could be talked\n"
	.string "into one last battle.$"

BattleFrontier_OutsideWest_Text_CM_Post_Battle:
	.string "Actually, you know what?\p"
	.string "I think I could cook up something\n"
	.string "much more interesting…\p"
	.string "The ocean will have to wait.$"

BattleFrontier_OutsideWest_Text_Sonicite_Pre_Battle:
	.string "Help, my team broke.$"

BattleFrontier_OutsideWest_Text_Sonicite_Post_Battle:
	.string "Thanks, figured it out now.$"

BattleFrontier_OutsideWest_Text_Kase_Pre_Battle:
	.string "Now that all of this is over,\n"
	.string "I can hit all the Gardevoir\l"
	.string "simps with the horny bat.$"

BattleFrontier_OutsideWest_Text_Kase_Post_Battle:
	.string "sophiabonk$"

BattleFrontier_OutsideWest_Text_Rosa_Pre_Battle:
	.string "Prepare for trouble!$"

BattleFrontier_OutsideWest_Text_Rosa_Post_Battle:
	.string "Damn, Basil should have\n"
	.string "let us have 6 Pokémon each.$"

BattleFrontier_OutsideWest_Text_Luna_Pre_Battle:
	.string "And make it double!$"

BattleFrontier_OutsideWest_Text_Luna_Post_Battle:
	.string "…I have no idea where I am,\n"
	.string "Rosa just dragged me here.$"

BattleFrontier_OutsideWest_Text_Chi_Pre_Battle:
	.string "I've been deep in the mines\n"
	.string "for Elysia's sake.\p"
	.string "This time?\p"
	.string "Behold the blessings of the\n"
	.string "devout!"

BattleFrontier_OutsideWest_Text_Chi_Post_Battle_1:
	.string "Enough. Well done, you've\n"
	.string "beaten my best.\p"
	.string "May Elysia guide me forevermore.$"

BattleFrontier_OutsideWest_Text_Chi_Post_Battle_2:
	.string "Elysia is my wife.$"

BattleFrontier_OutsideWest_Text_Flight_Pre_Battle:
	.string "If you bring damp you're\n"
	.string "lame.$"

BattleFrontier_OutsideWest_Text_Flight_Post_Battle:
	.string "Well, at least I went out\n"
	.string "with a bang.$"

BattleFrontier_OutsideWest_Text_Yurtz_Intro:
	.string "I made this team themed around\n"  
	.string "my First Fire Emblem Game!\p"
	.string "See if you can guess which one$"

BattleFrontier_OutsideWest_Text_Yurtz_Post1:
	.string "One more hint!/p"
	.string "You did well against the parents,\n"  
	.string "let's see how you do against\l"  
	.string "their kids.$"

BattleFrontier_OutsideWest_Text_Yurtz_Post2:
	.string "Thanks for playing!\p"
	.string "The game Awakening, did you\n"
	.string "guess right?$"

BattleFrontier_OutsideWest_Text_Poi_Pre_Battle:
	.string "I made it into post game!\p"
	.string "I did uh submit my team on the\n"
	.string "literal last day possible, but\l"
	.string "I made it!$"

BattleFrontier_OutsideWest_Text_Poi_Post_Battle:
	.string "Oh, I guess you made it here\n"
	.string "too.$"

BattleFrontier_OutsideWest_Text_Gamma_Pre_Battle:
	.string "I like to think this team is the\n"
	.string "equivalent of Matthis MC-\p"
	.string "It even has a Medeus!$"

BattleFrontier_OutsideWest_Text_Gamma_Post_Battle:
	.string "You only won because you counter-\n"
	.string "picked.$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower: @ 823D9DD
	.string "I want to go to the Battle Tower,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the Battle Frontier.\p"
	.string "This place is just too big!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere: @ 823DA60
	.string "I wanted to take a challenge as soon\n"
	.string "as I arrived here.\p"
	.string "But on the way, I got seasick…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere: @ 823DABF
	.string "It's not as if just anyone can come\n"
	.string "here, you know?\p"
	.string "Only those Trainers who've been\n"
	.string "recognized as tough are brought here.\p"
	.string "That's why many Trainers don't even\n"
	.string "know about the Battle Frontier.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons: @ 823DB7D
	.string "Ah… You're here too.\p"     
	.string "I must admit that before your unearned\n"
	.string "position, my new position as gym\l"
	.string "leader is quite unimpressive…\p"
	.string "But my dreams have not bent so easily,\n"
	.string "and I shall see that wrong put right!\p"	
	.string "You face a new woman, a greater woman…\n"
	.string "One worthy of the title of the\l"
	.string "strongest in the world!\p"
	.string "You face the glorious queen of all,\n"
	.string "Artemisia!$"	

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons: @ 823DBCE
	.string "I see… So even this was not enough\n"
	.string "to face you.$"

BattleFrontier_OutsideWest_Text_Arte_Transition:
	.string "That battle was… Enlightening. I\n"
	.string "understand now. I truly understand.\p"
	.string "To fight you as a trainer, to\n"
	.string "fight you as a gym leader, to\l"
	.string "to fight even as a queen…\p"
	.string "All are false.\p"
	.string "All are not my true will.\p"	
	.string "After all, what is a queen before\n"  
	.string "a goddess?\p"	
	.string "The goddess that has raged within\n"
	.string "my heart for all these years…\l"
	.string "Shall be let loose!$"

 BattleFrontier_OutsideWest_Text_Arte_Defeat:
	.string "No… More… I am done.\p"
	.string "My rage and my spirit have been\n"  
	.string "quelled.\p"	
	.string "I have reached the pinnacle of\n"
	.string "my strength, and you are stronger\l"
	.string "than me…\p"
	.string "I must slumber now…\n"  
	.string "Champion.$"	

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons: @ 823DC36
	.string "That's the BATTLE FACTORY.\n"
	.string "You can rent strong Pokémon there.\p"
	.string "But it makes me wonder.\n"
	.string "Who's raising those rental Pokémon?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper: @ 823DCB0
	.string "I'm scared of going into the BATTLE\n"
	.string "PIKE because of SEVIPER…\p"
	.string "B-but I came all the way here, so I will\n"
	.string "try to conquer everything!\l"
	.string "…Shudder…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors: @ 823DD3B
	.string "Let's play rock, paper, scissors!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge: @ 823DD7A
	.string "Yay! I won!\n"
	.string "I will take the BATTLE PIKE challenge!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge: @ 823DDAD
	.string "Oh, no…\n"
	.string "I lost.\p"
	.string "I guess I'm not very lucky today.\n"
	.string "I'll put off my BATTLE PIKE challenge\l"
	.string "until tomorrow.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling: @ 823DE15
	.string "I believe I'm the only person here who,\n"
	.string "for some unknown reason, would choose\l"
	.string "fishing over battling.\p"
	.string "Huh? You can't catch anything here?\n"
	.string "That's disappointing…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol: @ 823DEB4
	.string "Today, I'm going to keep battling, no\n"
	.string "matter what, until I get a Symbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome: @ 823DEFD
	.string "Oh? You're off to challenge\n"
	.string "the BATTLE DOME?\p"
	.string "I'll wish you the best of luck.\n"
	.string "Let us both win our way up and meet\l"
	.string "in challenges.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa: @ 823DF7D
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe: @ 823DFBF
	.string "Ah, so this here is the BATTLE DOME?\n"
	.string "I won't let GENTLEMEN beat me!\p"
	.string "But where is the entrance?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo: @ 823E01E
	.string "There used to be nothing here not all\n"
	.string "that long ago.\p"
	.string "But, now look at this place! Amazing!\n"
	.string "I'll bring my mother out to see this.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier: @ 823E09F
	.string "I've finally arrived at the BATTLE\n"
	.string "FRONTIER!\p"
	.string "I'm sure to grab attention with\n"
	.string "my looks and ability!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople: @ 823E102
	.string "So, you finally made it to post game.\n"
	.string "No one can bitch about my team here-\p"
	.string "It's finally time to take the kid gloves\n"
	.string "off!$"

BattleFrontier_OutsideWest_Text_Brain_Post_Battle:
	.string "Fucking really? Well, I guess you made\n"
	.string "it here for a reason.$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike: @ 823E154
	.string "Crunch, munch…\p"
	.string "A while back, I met this older girl\n"
	.string "at the BATTLE PIKE.\p"
	.string "She had these eyes that were scary\n"
	.string "in a real ornery way.\p"
	.string "Crunch, munch…\p"
	.string "She got all furious: “Will you quit\n"
	.string "eating!” Then she whaled on me.\p"
	.string "It was a hair-raising kind of\n"
	.string "scary experience, sure enough.\p"
	.string "Crunch, munch…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet: @ 823E273
	.string "Huh? Will you listen to yourself?\n"
	.string "That's nothing!\p"
	.string "Why, the last time I cheered for him,\n"
	.string "our eyes met and sparks flew!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering: @ 823E2E9
	.string "Whaaaaaat?!\n"
	.string "Pfft!\p"
	.string "That only happened because\n"
	.string "I happened to be sitting next to you!\p"
	.string "The DOME ACE only looked our way\n"
	.string "because my cheering was so loud!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine: @ 823E37E
	.string "Oh, shush!\n"
	.string "Keep that racket down!\p"
	.string "You fair-weather fans should stick\n"
	.string "to cheering for some Gym Leader!\p"
	.string "The DOME ACE is mine!\n"
	.string "The only idol for me!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers: @ 823E410
	.string "Those people squabbling over there…\p"
	.string "It's hard to believe, but they once\n"
	.string "were TRAINERS, and good ones, too.\p"
	.string "They used to be incredibly tough,\n"
	.string "and they were famous, too.\p"
	.string "But they were obliterated by this\n"
	.string "certain Trainer at a tournament.\p"
	.string "They were so thoroughly whipped,\n"
	.string "they became smitten by the Trainer.\p"
	.string "Now they're just fans of the Trainer.\n"
	.string "They go cheer for their idol at the\l"
	.string "BATTLE DOME every day now.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier: @ 823E5A5
	.string "I heard a rumor that someone saw\n"
	.string "a Pokémon with an unusually long tail\l"
	.string "somewhere in the Battle Frontier.\p"
	.string "It must be adorable. I'm sure of it…\p"
	.string "Oh, challenges can wait. I feel driven\n"
	.string "to find the delightful creature!$"

