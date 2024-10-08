.set LOCALID_STEVEN, 1
.set LOCALID_MELTAN_BALL, 2

MossdeepCity_StevensHouse_MapScripts:: @ 8222784
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad: @ 8222794
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote:: @ 822279E
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, 1
	return

MossdeepCity_StevensHouse_OnTransition: @ 82227A8
	compare VAR_STEVENS_HOUSE_STATE, 2
	call_if_eq MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos:: @ 82227B4
	setobjectxyperm LOCALID_STEVEN, 6, 5
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame: @ 82227C0
	map_script_2 VAR_STEVENS_HOUSE_STATE, 1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive:: @ 82227CA
	lockall
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM08_DIVE
	setflag FLAG_RECEIVED_HM08
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer: @ 8222833
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn: @ 822283B
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MossdeepCity_StevensHouse_EventScript_MeltanPokeball:: @ 8222841
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingMeltan, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_StevensHouse_EventScript_LeaveMeltan
	goto MossdeepCity_StevensHouse_EventScript_GiveMeltan
	end

MossdeepCity_StevensHouse_EventScript_LeaveMeltan:: @ 822285B
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveMeltan:: @ 8222865
	setvar VAR_TEMP_1, SPECIES_MELTAN
	givemon SPECIES_MELTAN, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_StevensHouse_EventScript_SendMeltanParty
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_StevensHouse_EventScript_SendMeltanPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendMeltanParty:: @ 8222895
	call MossdeepCity_StevensHouse_EventScript_ReceivedMeltanFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_StevensHouse_EventScript_ReceivedMeltan
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedMeltan
	end

MossdeepCity_StevensHouse_EventScript_SendMeltanPC:: @ 82228BD
	call MossdeepCity_StevensHouse_EventScript_ReceivedMeltanFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_StevensHouse_EventScript_MeltanTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_MeltanTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_MeltanTransferredToPC:: @ 82228E0
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedMeltan
	end

MossdeepCity_StevensHouse_EventScript_ReceivedMeltanFanfare:: @ 82228EB
	bufferspeciesname 1, SPECIES_MELTAN
	removeobject LOCALID_MELTAN_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedMeltan
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MELTAN
	return

MossdeepCity_StevensHouse_EventScript_ReceivedMeltan:: @ 8222901
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_MELTAN_POKEBALL
	setflag FLAG_RECEIVED_MELTAN
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay:: @ 8222909
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven:: @ 8222912
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter:: @ 822291B
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_StevensHouse_EventScript_DiveItemBall:: @ 8222926
	finditem ITEM_HM08_DIVE
	setflag FLAG_RECEIVED_HM08
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive: @ 8222936
	.string "Penta: Hey, welcome.\p"
	.string "Don't have much since I'm always out,\n"
	.string "but this is my place.\p"
	.string "Anyway, thanks again for helping me.\p"
	.string "You're gonna need this.\n"
	.string "It's the Hidden Machine Dive.$"

MossdeepCity_StevensHouse_Text_ExplainDive: @ 8222A0E
	.string "Penta: While you're using Surf, you\n"
	.string "should notice dark patches of water.\p"
	.string "Use Dive if you come to deep water\n"
	.string "like it. You'll drop to the seafloor.\p"
	.string "When you want to come back up, use\n"
	.string "Dive again.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis: @ 8222B11
	.string "Penta: Apparently, there's a huge\n"
	.string "underwater cavern between\l"
	.string "Mossdeep and Sootopolis.\p"
	.string "You should go check that out, for no\n"
	.string "particular reason.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingMeltan: @ 8222B9E
	.string "{PLAYER} checked the Poké Ball.\p"
	.string "It contained the Pokémon\n"
	.string "Meltan.\p"
	.string "Take the Poké Ball?$"

MossdeepCity_StevensHouse_Text_ObtainedMeltan: @ 8222BED
	.string "{PLAYER} obtained a Meltan.$"

@ Unused
MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon: @ 8222C03
	.string "There is no space for another Pokémon.$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas: @ 8222C2A
	.string "{PLAYER} left the Poké Ball where\n"
	.string "it was.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven: @ 8222C4E
	.string "It's a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I've decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don't plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the Poké Ball on\n"
	.string "the desk.\p"
	.string "Inside it is a Meltan, one of my\n"
	.string "favorite Pokémon.\p"
	.string "I'm counting on you.\p"
	.string "May our paths cross someday.\p"
	.string "Steven Stone$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks: @ 8222D97
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by Steven.$"

