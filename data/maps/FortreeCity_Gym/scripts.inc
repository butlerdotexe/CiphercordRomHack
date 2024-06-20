FortreeCity_Gym_MapScripts:: @ 82165AB
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition: @ 82165B6
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp: @ 82165BA
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates:: @ 82165C4
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona:: @ 82165C8
	goto_if_set FLAG_DAILY_REMATCH_WINONA, FortreeCity_Gym_EventScript_AlreadyRematched
	goto_if_set FLAG_SYS_GAME_CLEAR, FortreeCity_Gym_EventScript_WinonaRematch
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM51, FortreeCity_Gym_EventScript_GiveRoost2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated:: @ 82165FD
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveRoost
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveRoost2:: @ 8216646
	giveitem ITEM_TM51_ROOST
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainRoost, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM51
	release
	end

FortreeCity_Gym_EventScript_GiveRoost:: @ 821666A
	giveitem ITEM_TM51_ROOST
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainRoost, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM51
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	message FortreeCity_Gym_Text_WinonaChooseFormat
	waitmessage
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, FortreeCity_Gym_EventScript_SetSingles
	case 1, FortreeCity_Gym_EventScript_SetDoubles
	case 2, FortreeCity_Gym_EventScript_Exit
	case 127, FortreeCity_Gym_EventScript_Exit
	releaseall
	end

FortreeCity_Gym_EventScript_SetSingles::
	msgbox FortreeCity_Gym_Text_WinonaAllowLegends, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FortreeCity_Gym_EventScript_WinonaSinglesRematch
	trainerbattle_no_intro TRAINER_WINONA_4, FortreeCity_Gym_Text_WinonaRematchDefeat
	setflag FLAG_DAILY_REMATCH_WINONA
	releaseall
	end

FortreeCity_Gym_EventScript_SetDoubles::
	msgbox FortreeCity_Gym_Text_WinonaAllowLegends, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FortreeCity_Gym_EventScript_WinonaDoublesRematch
	trainerbattle_no_intro TRAINER_WINONA_5, FortreeCity_Gym_Text_WinonaRematchDefeat
	setflag FLAG_DAILY_REMATCH_WINONA
	releaseall
	end

FortreeCity_Gym_EventScript_WinonaSinglesRematch::
	trainerbattle_no_intro TRAINER_WINONA_2, FortreeCity_Gym_Text_WinonaRematchDefeat
	setflag FLAG_DAILY_REMATCH_WINONA
	releaseall
	end

FortreeCity_Gym_EventScript_WinonaDoublesRematch::
	trainerbattle_no_intro TRAINER_WINONA_3, FortreeCity_Gym_Text_WinonaRematchDefeat
	setflag FLAG_DAILY_REMATCH_WINONA
	releaseall
	end

FortreeCity_Gym_EventScript_AlreadyRematched::
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	releaseall
	end

FortreeCity_Gym_EventScript_Exit::
	releaseall
	end

FortreeCity_Gym_EventScript_Jared:: @ 82166A8
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo:: @ 82166BF
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint:: @ 82166D6
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley:: @ 82166ED
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto:: @ 8216704
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius:: @ 821671B
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide:: @ 8216732
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	goto_if_set FLAG_MOVE_FORTREE_GYM_ENERGY_ROOT, FortreeCity_GymGuide_2
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	giveitem ITEM_ENERGY_ROOT, 10
	setflag FLAG_MOVE_FORTREE_GYM_ENERGY_ROOT
	msgbox FortreeCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	release
	end

FortreeCity_GymGuide_2::
	msgbox FortreeCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory:: @ 8216747
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue:: @ 8216751
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue:: @ 8216761
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified:: @ 8216771
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue:: @ 821677B
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice: @ 8216785
	.string "Yo, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Please, take these Energy Roots to\n"
	.string "help with your challenge!$"


FortreeCity_Gym_Text_GymGuideAdvice2:
	.string "Fortree Gym Leader Brainiac is a\n"
	.string "master of 'balanced' teams.\p"
	.string "Everyone here has a Fire, Water,\n"
	.string "and Grass type to achieve balance.\p"
	.string "The leader himself is no different,\n"
	.string "though be prepared, he's got a lot\l"
	.string "more than just that up his sleeve!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory: @ 821687D
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_JaredIntro: @ 82168A2
	.string "Behold the elegant battle style of\n"
	.string "a perfectly balanced team!$"

FortreeCity_Gym_Text_JaredDefeat: @ 82168D3
	.string "You…\n"
	.string "You're strong…$"

FortreeCity_Gym_Text_JaredPostBattle: @ 82168E7
	.string "A Trainer has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our Leader?$"

FortreeCity_Gym_Text_EdwardoIntro: @ 821695A
	.string "The lovers of fair Pokémon aspire\n"
	.string "to join this Gym.\p"
	.string "As a member of the Fortree Gym,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_EdwardoDefeat: @ 82169C7
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_EdwardoPostBattle: @ 82169F1
	.string "The world is huge, and there are\n"
	.string "countless tough Trainers.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_FlintIntro: @ 8216A66
	.string "There's no need for Brainiac, our Gym\n"
	.string "Leader, to deal with you!\p"
	.string "I'm plenty good enough for you!$"

FortreeCity_Gym_Text_FlintDefeat: @ 8216AC4
	.string "Brainiac, I…\n"
	.string "I lost!$"

FortreeCity_Gym_Text_FlintPostBattle: @ 8216AD7
	.string "Brainiac is cute and he's strong.\n"
	.string "He's the ultimate Leader!\p"
	.string "Blush…$"

FortreeCity_Gym_Text_AshleyIntro: @ 8216B1A
	.string "Brainiac taught me personally!\n"
	.string "You can't beat me easily!$"

FortreeCity_Gym_Text_AshleyDefeat: @ 8216B51
	.string "I was beaten…$"

FortreeCity_Gym_Text_AshleyPostBattle: @ 8216B5F
	.string "Thanks to Winona, the people of\n"
	.string "Fortree can live without fear.$"

FortreeCity_Gym_Text_HumbertoIntro: @ 8216B9E
	.string "When Brainiac takes to battle, he\n"
	.string "crushes everything before him…\p"
	.string "I will spare you from that fate!$"

FortreeCity_Gym_Text_HumbertoDefeat: @ 8216C18
	.string "Urk!\n"
	.string "I couldn't stop you.$"

FortreeCity_Gym_Text_HumbertoPostBattle: @ 8216C32
	.string "You'd better watch it!\n"
	.string "Brainiac will seriously mess you up\l"
	.string "if you're not prepared!$"

FortreeCity_Gym_Text_DariusIntro: @ 8216C96
	.string "If you've come this far, I probably\n"
	.string "can't stop you from fighting Brainiac.\p"
	.string "But as a trainer, I must battle you.$"

FortreeCity_Gym_Text_DariusDefeat: @ 8216CF2
	.string "As I thought.$"

FortreeCity_Gym_Text_DariusPostBattle: @ 8216D0F
	.string "You should be as prepared as you can be.\p"
	.string "Go forward, have no regrets, and battle\n"
	.string "like your life depends on it.$"

FortreeCity_Gym_Text_WinonaIntro: @ 8216D75
	.string "Finally, someone made it up here.\p"
	.string "You're the first challenger since the\n"
	.string "intervention.\p"
	.string "Apparently I'm being 'too hard' on\n"
	.string "on challengers or something.\p"
	.string "I mean, I'm not even allowed to have a mega!\p"
	.string "Tibarn has a goddamn Iron Valiant but\n"
	.string "I can't have a Mega Absol?\p"
	.string "Can you believe that?\p"
	.string "Anyways, either I beat your ass here, or I\n"
	.string "gain an excuse to ramp up this challenge\l"
	.string "again.\p"
	.string "It's a win-win for me!$"

FortreeCity_Gym_Text_WinonaDefeat: @ 8216E60
	.string "Fuc- I mean darn. Gotta keep the\n"
	.string "PG13 rating for my Gym.\p"
	.string "Well, in spite of the bullshit you\n"
	.string "pulled to win, a dub is a dub.\p"
	.string "Here.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge: @ 8216EEC
	.string "{PLAYER} received the Feather Badge\n"
	.string "from Brainiac.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis: @ 8216F17
	.string "You know, I'm almost glad that you beat me.\p"
	.string "I was getting sick and tired of people telling\n"
	.string "me I was overdoing it.\p"
	.string "'Braaaaaaain why do you have 3 mythicals.'\n"
	.string "'Braaaaaaaain this fight is so unfair.'\l"
	.string "Blah blah blah.\p"
	.string "The only takeaway that I got from this is\n"
	.string "that Exalt's a bitch.\p"
	.string "Anyways, here's the Roost TM. You earned it.$"

FortreeCity_Gym_Text_ExplainRoost: @ 8216FEC
	.string "Roost is a healing move.\p"
	.string "…What, you need more explanation?\p"
	.string "Google it yourself, lazy bastard.$"

FortreeCity_Gym_Text_RegisteredWinona: @ 8217044
	.string "Registered Gym Leader Brainiac\n"
	.string "in the PokéNav.$"

FortreeCity_Gym_Text_WinonaPostBattle: @ 8217071
	.string "Just because I lost here doesn't mean\n"
	.string "I can't cook something up to beat you.$"

FortreeCity_Gym_Text_GymStatue: @ 82170AE
	.string "Fortree City Pokémon Gym$"

FortreeCity_Gym_Text_GymStatueCertified: @ 82170C7
	.string "Fortree City Pokémon Gym\p"
	.string "Brainiac's Certified Trainers:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch: @ 8217100
	.string "Winona: Please, allow me to see your\n"
	.string "power at full flight!$"

FortreeCity_Gym_Text_WinonaRematchDefeat: @ 82171E6
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_WinonaPostRematch: @ 821720B
	.string "Winona: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons: @ 8217292
	.string "Oh, no… Do you have but one\n"
	.string "Pokémon with you?\p"
	.string "Please return with two Pokémon\n"
	.string "at the very least.$"

FortreeCity_Gym_Text_WinonaChooseFormat:
	.string "Winona: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning Champion.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Now, please tell me - how would you\n"
	.string "like to battle?$"

FortreeCity_Gym_Text_WinonaAllowLegends:
	.string "Winona: and would you like to challenge\n"
	.string "my Legendary Pokémon?$"
