FallarborTown_MapScripts:: @ 81EB1FA
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition: @ 81EB200
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	end

FallarborTown_EventScript_ExpertM:: @ 81EB20C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal:: @ 81EB221
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl:: @ 81EB22B
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman:: @ 81EB234
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill:: @ 81EB23D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign:: @ 81EB250
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign:: @ 81EB259
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign:: @ 81EB262
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_RivalTrigger1::
	setvar VAR_0x8004, 1
	goto FallarborTown_EventScript_RivalScene
	end

FallarborTown_EventScript_RivalTrigger2::
	setvar VAR_0x8004, 2
	goto FallarborTown_EventScript_RivalScene
	end

FallarborTown_EventScript_RivalTrigger3::
	setvar VAR_0x8004, 3
	goto FallarborTown_EventScript_RivalScene
	end

FallarborTown_EventScript_RivalTrigger4::
	setvar VAR_0x8004, 4
	goto FallarborTown_EventScript_RivalScene
	end
	
FallarborTown_EventScript_RivalTrigger5::
	setvar VAR_0x8004, 5
	goto FallarborTown_EventScript_RivalScene
	end

FallarborTown_EventScript_RivalScene::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq FallarborTown_EventScript_MayScene
	compare VAR_RESULT, FEMALE
	goto_if_eq FallarborTown_EventScript_BrendanScene

FallarborTown_EventScript_MayScene::
	playbgm MUS_ENCOUNTER_MAY, 1
	msgbox FallarborTown_Text_MayDisaster, MSGBOX_DEFAULT
	closemessage
	call FallarborTown_EventScript_MoveToPlayer
	msgbox FallarborTown_Text_MayWeirdos, MSGBOX_DEFAULT
	closemessage
	goto FallarborTown_EventScript_RivalExit

FallarborTown_EventScript_BrendanScene::
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	msgbox FallarborTown_Text_BrendanComeHere, MSGBOX_DEFAULT
	closemessage
	call FallarborTown_EventScript_MoveToPlayer
	msgbox FallarborTown_Text_BrendanNuts, MSGBOX_DEFAULT
	closemessage
	goto FallarborTown_EventScript_RivalExit

FallarborTown_EventScript_RivalExit::
	setobjectxyperm 6, 12, 10
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	removeobject 5
	addobject 6
	delay 45
	applymovement 6, FallarborTown_Movement_RivalExit
	waitmovement 0
	removeobject 6
	setvar VAR_FALLARBOR_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

FallarborTown_EventScript_MoveToPlayer::
	compare VAR_0x8004, 1
	call_if_eq FallarborTown_EventScript_PlayerApproach1
	compare VAR_0x8004, 2
	call_if_eq FallarborTown_EventScript_PlayerApproach2
	compare VAR_0x8004, 3
	call_if_eq FallarborTown_EventScript_PlayerApproach3
	compare VAR_0x8004, 4
	call_if_eq FallarborTown_EventScript_PlayerApproach4
	compare VAR_0x8004, 5
	call_if_eq FallarborTown_EventScript_PlayerApproach5
	return

FallarborTown_EventScript_PlayerApproach1::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach1
	applymovement 5, FallarborTown_Movement_RivalApproach
	waitmovement 0
	return

FallarborTown_EventScript_PlayerApproach2::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach2
	applymovement 5, FallarborTown_Movement_RivalApproach
	waitmovement 0
	return

FallarborTown_EventScript_PlayerApproach3::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach3
	applymovement 5, FallarborTown_Movement_RivalApproach
	waitmovement 0
	return

FallarborTown_EventScript_PlayerApproach4::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach4
	applymovement 5, FallarborTown_Movement_RivalApproach
	waitmovement 0
	return

FallarborTown_EventScript_PlayerApproach5::
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_Movement_PlayerApproach5
	applymovement 5, FallarborTown_Movement_RivalApproach
	waitmovement 0
	return

FallarborTown_Movement_PlayerApproach1:
	walk_down
	walk_down
	face_left
	step_end

FallarborTown_Movement_PlayerApproach2:
	walk_down
	face_left
	step_end

FallarborTown_Movement_PlayerApproach3:
	face_left
	step_end

FallarborTown_Movement_PlayerApproach4:
	walk_up
	face_left
	step_end

FallarborTown_Movement_PlayerApproach5:
	walk_up
	walk_up
	face_left
	step_end

FallarborTown_Movement_RivalApproach:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

FallarborTown_Movement_RivalExit:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

FallarborTown_Text_MayDisaster:
	.string "Sauce: Yo! {PLAYER}{KUN}! C'mere!$"

FallarborTown_Text_BrendanComeHere:
	.string "Sauce: Yo! {PLAYER}{KUN}! C'mere!$"

FallarborTown_Text_MayWeirdos:
	.string "Sauce: You'll never believe this.\p"
	.string "It's ridiculous…\n"
	.string "Professor Cozmo…\p"
	.string "They say that he was just up and\n"
	.string "kidnapped by some nuts calling\l"
	.string "themselves Team Aggro!\p"
	.string "Like, they just took a grown ass\n"
	.string "man in the middle of the day.\p"
	.string "I'm gonna see what's going on\n"
	.string "at Meteor Falls, come meet up\l"
	.string "with me there.$"

FallarborTown_Text_BrendanNuts:
	.string "Sauce: You'll never believe this.\p"
	.string "It's ridiculous…\n"
	.string "Professor Cozmo…\p"
	.string "They say that he was just up and\n"
	.string "kidnapped by some nuts calling\l"
	.string "themselves Team Aggro!\p"
	.string "Like, they just took a grown ass\n"
	.string "man in the middle of the day.\p"
	.string "I'm gonna see what's going on\n"
	.string "at Meteor Falls, come meet up\l"
	.string "with me there.$"

FallarborTown_Text_ShadyCharactersCozmosHome: @ 81EB26B
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of Prof. Cozmo's home…$"

FallarborTown_Text_RegionKnownForMeteors: @ 81EB2DE
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say Meteor Falls was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_MyPreciousAzurill: @ 81EB35F
	.string "See! Take a look!\n"
	.string "This is my precious Azurill!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_Azurill: @ 81EB3B5
	.string "Azurill: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery: @ 81EB3CA
	.string "Have you already challenged Tibarn,\n"
	.string "the Leader of Lavaridge Gym?\p"
	.string "He took over from Flannery a while\n"
	.string "back, using his powerful legendary\l"
	.string "bird Pokémon.$"

FallarborTown_Text_BattleTentSign: @ 81EB4C2
	.string "Battle Tent Fallarbor Site\n"
	.string "“May the Greatest Teams Gather!”$"

FallarborTown_Text_TownSign: @ 81EB4FE
	.string "Fallarbor Town\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign: @ 81EB534
	.string "Ivy and Evie's House\n"
	.string "“Special training for Pokémon.”$"

