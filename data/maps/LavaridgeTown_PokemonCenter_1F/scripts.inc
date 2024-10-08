.set LOCALID_NURSE, 1
.set LOCALID_LUCY, 8

LavaridgeTown_PokemonCenter_1F_MapScripts:: @ 81FFAFA
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition: @ 81FFB05
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FFB0E
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster:: @ 81FFB1C
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman:: @ 81FFB25
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FFB2E
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_MoomooMilk::
	lock
	faceplayer
	showmoneybox 0, 0, 0
	msgbox LavaridgeTown_PokemonCenter_1F_Text_WantToBuyMoomooMilk, MSGBOX_DEFAULT
	multichoice 16, 0, MULTI_MOOMOO_MILK, 0
	switch VAR_RESULT
	case 0, LavaridgeTown_PokemonCenter_1F_EventScript_Buy1MoomooMilk
	case 1, LavaridgeTown_PokemonCenter_1F_EventScript_Buy12MoomooMilk
	case 2, LavaridgeTown_PokemonCenter_1F_EventScript_ExitWithoutBuying
	case 127, LavaridgeTown_PokemonCenter_1F_EventScript_ExitWithoutBuying
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Buy1MoomooMilk::
	checkmoney 500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughMoney
	checkitemspace ITEM_MOOMOO_MILK, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughSpace
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 500, 0
	updatemoneybox 0, 0
	giveitem ITEM_MOOMOO_MILK
	hidemoneybox
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Buy12MoomooMilk::
	checkmoney 6000, 0
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughMoney
	checkitemspace ITEM_MOOMOO_MILK, 12
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughSpace
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 6000, 0
	updatemoneybox 0, 0
	giveitem ITEM_MOOMOO_MILK, 12
	hidemoneybox
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_ExitWithoutBuying::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_LucyTrigger::
	lock
	addobject LOCALID_LUCY
	setvar VAR_LAVARIDGE_LUCY_STATE, 1
	clearflag FLAG_HIDE_LAVARIDGE_POKECENTER_LUCY
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyYouThere, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyEnter
	waitmovement 0
	msgbox LavaridgeTown_PokemonCenter_1F_Text_ScottSaid, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_LucyRefuse
LavaridgeTown_PokemonCenter_1F_EventScript_LucyBattle::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LUCY_LAVARIDGE, LavaridgeTown_PokemonCenter_1F_Text_LucyDefeat
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LUCY, LavaridgeTown_PokemonCenter_1F_Text_LucyDefeat
	setvar VAR_LAVARIDGE_LUCY_STATE, 2
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyGiveChoiceBand, MSGBOX_DEFAULT
	giveitem ITEM_CHOICE_BAND
	giveitem ITEM_BOTTLE_CAP, 3
	msgbox LavaridgeTown_PokemonCenter_1F_Text_LucyGoodbye, MSGBOX_AUTOCLOSE
	waitmessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 2
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitFromSprings
	switch VAR_FACING
	case DIR_NORTH, LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitNorth
	case DIR_WEST, LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitWest
	case DIR_EAST, LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitEast
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Lucy::
	applymovement LOCALID_LUCY, Common_Movement_FacePlayer
	waitmovement 0
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyBattle

LavaridgeTown_PokemonCenter_1F_EventScript_LucyRefuse::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_VeryWell, MSGBOX_AUTOCLOSE	
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyGoWait
	waitmovement 0
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitFromSprings::
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitFromSprings
	waitmovement 0
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave

LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitNorth:
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitNorth
	waitmovement 0
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave

LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitWest:
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitNorth
	waitmovement 0
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave

LavaridgeTown_PokemonCenter_1F_EventScript_LucyExitEast:
	applymovement LOCALID_LUCY, LavaridgeTown_PokemonCenter_1F_Movement_LucyExitEast
	waitmovement 0
	goto LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave

LavaridgeTown_PokemonCenter_1F_EventScript_LucyLeave::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LUCY
	release
	end

LavaridgeTown_PokemonCenter_1F_Text_LucyYouThere:
	.string "???: Hold on a sec.$"

LavaridgeTown_PokemonCenter_1F_Text_ScottSaid:
	.string "???: I heard a strong trainer has been\n"
	.string "making their way through here.\p"
	.string "My name's Sylveon, an expert in the\n"
	.string "Eeveelutions. We should battle.$"

LavaridgeTown_PokemonCenter_1F_Text_VeryWell:
	.string "Sylveon: Really? …\n"
	.string "Well, I'll be by the PC.\p"
	.string "Don't keep me waiting…$"

LavaridgeTown_PokemonCenter_1F_Text_LucyDefeat:
	.string "Urk…$"

LavaridgeTown_PokemonCenter_1F_Text_LucyBattle:
	.string "Sylveon: Ready? Sick.\n"
	.string "Let's make this quick.$"

LavaridgeTown_PokemonCenter_1F_Text_LucyGiveChoiceBand:
	.string "Sylveon: You were lucky, this time…\n"
	.string "Here. Take these.$"

LavaridgeTown_PokemonCenter_1F_Text_LucyGoodbye:
	.string "Sylveon: I'll see you around!$"

LavaridgeTown_PokemonCenter_1F_Text_WantToBuyMoomooMilk:
	.string "Moomoo Milk?\p"
	.string "It's great before entering the\n"
	.string "hot spring!\p"
	.string "And even better afterward.\n"
	.string "How about some?$"

LavaridgeTown_PokemonCenter_1F_Text_ThatsTooBad:
	.string "Well, now I feel udder-ly useless!$"

LavaridgeTown_PokemonCenter_1F_Text_HereYouGo:
	.string "Here's your Moomoo Milk. Drink up!$"

LavaridgeTown_PokemonCenter_1F_Text_NotEnoughMoney:
	.string "You don't have enough money.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether: @ 81FFB37
	.string "I think Pokémon get closer to their\n"
	.string "Trainers if they spend time together.\p"
	.string "The longer the better.\n"
	.string "That's what I think.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate: @ 81FFBAD
	.string "It's sort of magical how just sitting\n"
	.string "in a hot-spring pool can invigorate.\p"
	.string "I wish I could let my Pokémon\n"
	.string "soak, too.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo: @ 81FFC21
	.string "Hohoho! Hey, kid, you can reach\n"
	.string "the hot springs from here.\p"
	.string "If Pokémon are getting rest, so too\n"
	.string "should their Trainers.$"

LavaridgeTown_PokemonCenter_1F_Movement_LucyEnter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_PokemonCenter_1F_Movement_LucyGoWait:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

LavaridgeTown_PokemonCenter_1F_Movement_LucyExitFromSprings:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

LavaridgeTown_PokemonCenter_1F_Movement_LucyExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

LavaridgeTown_PokemonCenter_1F_Movement_LucyExitEast:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	step_end
