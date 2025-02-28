.set LOCALID_RIVAL, 2

Route103_MapScripts:: @ 81EC38E
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad: @ 81EC3A4
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave:: @ 81EC3AE
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

Route103_EventScript_Rival:: @ 81EC3C1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_RivalMay
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay:: @ 81EC3DA
	goto_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_RivalMayRematch
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end

Route103_EventScript_RivalBrendan:: @ 81EC434
	goto_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_RivalBrendanRematch
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_RivalMayRematch::
	goto_if_set FLAG_DAILY_REMATCH_RIVAL, Route103_EventScript_AfterMayRematch
	playbgm MUS_ENCOUNTER_MAY, 1
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayRematch, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayRematchTreecko
	case 1, Route103_EventScript_StartMayRematchTorchic
	case 2, Route103_EventScript_StartMayRematchMudkip
	end

Route103_EventScript_RivalBrendanRematch:: @ 81EC434
	goto_if_set FLAG_DAILY_REMATCH_RIVAL, Route103_EventScript_AfterBrendanRematch
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanRematch, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanRematchTreecko
	case 1, Route103_EventScript_StartBrendanRematchTorchic
	case 2, Route103_EventScript_StartBrendanRematchMudkip
	end

Route103_EventScript_StartMayBattleTreecko:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko:: @ 81EC4BE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic:: @ 81EC4CE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip:: @ 81EC4DE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

@@@@@@@@@@@@@@@@@@@@@@@@ Rematch teams @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Route103_EventScript_StartMayRematchTreecko:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, Route103_Text_MayRematchDefeated
	goto Route103_EventScript_AfterMayRematch
	end

Route103_EventScript_StartMayRematchTorchic:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, Route103_Text_MayRematchDefeated
	goto Route103_EventScript_AfterMayRematch
	end

Route103_EventScript_StartMayRematchMudkip:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, Route103_Text_MayRematchDefeated
	goto Route103_EventScript_AfterMayRematch
	end

Route103_EventScript_StartBrendanRematchTreecko:: @ 81EC4BE
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, Route103_Text_BrendanRematchDefeated
	goto Route103_EventScript_AfterBrendanRematch
	end

Route103_EventScript_StartBrendanRematchTorchic:: @ 81EC4CE
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, Route103_Text_BrendanRematchDefeated
	goto Route103_EventScript_AfterBrendanRematch
	end

Route103_EventScript_StartBrendanRematchMudkip:: @ 81EC4DE
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, Route103_Text_BrendanRematchDefeated
	goto Route103_EventScript_AfterBrendanRematch
	end

Route103_EventScript_AfterMayBattle:: @ 81EC4EE
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle:: @ 81EC4FC
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterMayRematch:: @ 81EC4EE
	msgbox Route103_Text_MayPostRematch, MSGBOX_DEFAULT
	setflag FLAG_DAILY_REMATCH_RIVAL
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Route103_EventScript_MayGiveEonTicket
	releaseall
	end

Route103_EventScript_AfterBrendanRematch:: @ 81EC4FC
	msgbox Route103_Text_BrendanPostRematch, MSGBOX_DEFAULT
	setflag FLAG_DAILY_REMATCH_RIVAL
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Route103_EventScript_BrendanGiveEonTicket
	releaseall
	end

Route103_EventScript_BrendanGiveEonTicket::
	msgbox Route103_Text_BrendanGiveEonTicket, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	giveitem ITEM_EON_TICKET
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_EventScript_MayGiveEonTicket::
	msgbox Route103_Text_MayGiveEonTicket, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	giveitem ITEM_EON_TICKET
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_EventScript_RivalExit:: @ 81EC50A
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth:: @ 81EC53D
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_EventScript_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest:: @ 81EC561
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth:: @ 81EC585
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd:: @ 81EC5A2
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1: @ 81EC5BE
	walk_left
	walk_down
	step_end

Route103_EventScript_RivalExitFacingNorth2: @ 81EC5C1
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth: @ 81EC5C8
	delay_16
	delay_4
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_Movement_RivalExit1: @ 81EC5CE
	walk_down
	step_end

Route103_Movement_RivalExit2: @ 81EC5D0
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest: @ 81EC5D6
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_EventScript_Boy:: @ 81EC5D9
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man:: @ 81EC5E2
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign:: @ 81EC5EB
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy:: @ 81EC5F4
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy:: @ 81EC60B
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle:: @ 81EC63A
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch:: @ 81EC653
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv:: @ 81EC66E
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle:: @ 81EC69D
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch:: @ 81EC6B6
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew:: @ 81EC6D1
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel:: @ 81EC6E8
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle:: @ 81EC714
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch:: @ 81EC733
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos:: @ 81EC74A
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett:: @ 81EC761
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete:: @ 81EC778
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon: @ 81EC7A6
	.string "Let's see… The Pokémon found\n"
	.string "on Route 103 include…$"

Route103_Text_MayLetsBattle: @ 81EC7DE
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, you think you're a big shot\n"
	.string "since Foodies gave you a Pokémon?\p"
	.string "Well then tough guy, let's see what\n"
	.string "you've got.\p"
	.string "I'll give you a taste of what being\n"
	.string "a Trainer is like.$"

Route103_Text_MayDefeated: @ 81EC881
	.string "Damn. You actually kinda got hands.\n"
	.string "Not bad, {PLAYER}{KUN}.$"

Route103_Text_MayTimeToHeadBack: @ 81EC8AE
	.string "I think I know why Foodies has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got a Pokémon,\n"
	.string "and you're fighting like a pro.\p"
	.string "Aight, time to head back to the\n"
	.string "Lab.$"

Route103_Text_BrendanRoute103Pokemon: @ 81EC989
	.string "Sauce: Okay, so it's this one and\n"
	.string "that one that live on Route 103…$"

Route103_Text_BrendanLetsBattle: @ 81EC9CE
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, you think you're a big shot\n"
	.string "since Foodies gave you a Pokémon?\p"
	.string "Well then tough guy, let's see what\n"
	.string "you've got.\p"
	.string "I'll give you a taste of what being\n"
	.string "a Trainer is like.$"

Route103_Text_BrendanDefeated: @ 81ECA59
	.string "Damn. You actually kinda got hands.\n"
	.string "Not bad, {PLAYER}{KUN}.$"

Route103_Text_BrendanTimeToHeadBack: @ 81ECA79
	.string "I think I know why Foodies has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got a Pokémon,\n"
	.string "and you're fighting like a pro.\p"
	.string "Aight, time to head back to the\n"
	.string "Lab.$"

Route103_Text_ShouldHaveBroughtPotion: @ 81ECB73
	.string "My Pokémon is staggeringly tired…\n"
	.string "I should have brought a Potion…$"

Route103_Text_ShortcutToOldale: @ 81ECBB5
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to Oldale Town.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign: @ 81ECC1A
	.string "Route 103\n"
	.string "{DOWN_ARROW} Oldale Town$"

Route103_Text_MayRematch:
	.string "May: Here we are on Route 103 again!\n"
	.string "Wow, it's so nostalgic, you know?\p"
	.string "This is where we first battled,\n"
	.string "isn't it?\p"
	.string "… {PLAYER}!\n"
	.string "Could you do something for me?\p"
	.string "Come on!\n"
	.string "Let's battle one more time!\p"
	.string "I wanna know what you saw on\n"
	.string "your journey, how you felt,\l"
	.string "and what you experienced out there.\p"
	.string "I want to understand everything about\n"
	.string "you and your Pokémon, {PLAYER}!\p"
	.string "And then…\p"
	.string "I want you to understand everything\l"
	.string "about me and mine!$"

Route103_Text_MayRematchDefeated:
	.string "…\p"
	.string "Thanks, {PLAYER}!\n"
	.string "You really are a Champion!$"

Route103_Text_MayPostRematch:
	.string "May: Meeting so many different people…\n"
	.string "And encountering so many Pokémon…\p"
	.string "It's just really…\n"
	.string "It's been really, really fun!$"

Route103_Text_BrendanRematch:
	.string "Brendan: Man, this is nostalgic.\n"
	.string "Back on Route 103, huh?\p"
	.string "This is where we battled the first\n"
	.string "time, huh?\p"
	.string "Hey, {PLAYER}…\n"
	.string "Do me a favor?\p"
	.string "Come on!\n"
	.string "Let's battle one more time!\p"
	.string "I wanna know about what you saw on\n"
	.string "your journey, how you felt,\l"
	.string "and what you experienced out there.\p"
	.string "I want to know all about you\n"
	.string "and your Pokémon, {PLAYER}.\p"
	.string "But that's not all…\p"
	.string "I want you to know all about\n"
	.string "me and mine!$"

Route103_Text_BrendanRematchDefeated:
	.string "…\p"
	.string "Thanks, {PLAYER}!\n"
	.string "Just what I'd expect from a Champion!$"

Route103_Text_BrendanPostRematch:
	.string "Brendan: Getting to meet so many\n"
	.string "different people…\p"
	.string "And so many different Pokémon…\p"
	.string "It's like… I don't know…\n"
	.string "It's been really, really fun!$"

Route103_Text_BrendanGiveEonTicket:
	.string "Brendan: One more thing, {PLAYER}.\n"
	.string "Take this as thanks for a great battle!$"

Route103_Text_MayGiveEonTicket:
	.string "May: Oh, by the way, {PLAYER}.\n"
	.string "I've got something for you!\p"
	.string "Please take this Ticket!$"
