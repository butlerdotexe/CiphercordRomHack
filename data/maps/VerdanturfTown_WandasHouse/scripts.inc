VerdanturfTown_WandasHouse_MapScripts:: @ 82028BE
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally:: @ 82028BF
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech:: @ 82028D7
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle:: @ 82028E1
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff:: @ 82028FF
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande:: @ 8202909
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend:: @ 8202913
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HM04, VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HM04, VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite::
	goto_if_set FLAG_WANDA_GARDEVOIRITE, VerdanturfTown_WandasHouse_EventScript_WandaGaveStone
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox VerdanturfTown_WandasHouse_Text_ReceiveGardevoirite, MSGBOX_DEFAULT
	giveitem ITEM_GARDEVOIRITE
	setflag FLAG_WANDA_GARDEVOIRITE
	msgbox VerdanturfTown_WandasHouse_Text_PrettyStone, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaGaveStone::
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen:: @ 8202975
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened:: @ 820297F
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande:: @ 8202989
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech: @ 8202993
	.string "Basil: ... Ever since I lost to you, {PLAYER},\n"
	.string "I've been thinking.\p"
	.string "This whole time I was thinking if I loved\n"
	.string "my Pokémon enough and we worked together,\l"
	.string "we could overcome anything together.\p"
	.string "But now I know the truth.\n"
	.string "There are weak Pokémon, and strong ones.\p"
	.string "My Maractus is weak, so I shouldn't force\n"
	.string "it to be something it isn't.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort: @ 8202ABE
	.string "Basil: I will find even stronger\n"
	.string "Pokémon and defeat you.\p"
	.string "Maractus can stay on the side\n"
	.string "and cheer me on!$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor: @ 8202B37
	.string "Uncle: Oh! {PLAYER}{KUN}!\n"
	.string "Basil's next door.\p"
	.string "But, boy, there's something I have to\n"
	.string "tell you.\p"
	.string "This natural environment is doing\n"
	.string "wonders for Wally's health.\p"
	.string "Maybe it's not just the environment.\n"
	.string "It could be Pokémon that are giving\l"
	.string "the boy hope.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff: @ 8202C20
	.string "Basil's gone away…\n"
	.string "He slipped off on his own…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar: @ 8202C4E
	.string "Uncle: Is that right?\n"
	.string "Basil's gone away that far all by\l"
	.string "himself…\p"
	.string "Well, I have to give him credit--he is\n"
	.string "my little brother's son.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "Wanda: You are?\n"
	.string "Oh, right, I get it!\p"
	.string "You're the {PLAYER} who Basil was\n"
	.string "telling me about.\p"
	.string "I'm Basil's cousin.\n"
	.string "Glad to meet you!\p"
	.string "I think Basil's become a lot more lively\n"
	.string "and healthy since he came here.$"

VerdanturfTown_WandasHouse_Text_ReceiveGardevoirite:
	.string "I didn't really thank you properly when\n"
	.string "you helped smash those rocks in the\l"
	.string "tunnel.\p"
	.string "I was thinking that I wanted to give\n"
	.string "this to you…$"

VerdanturfTown_WandasHouse_Text_PrettyStone:
	.string "It's a pretty stone, and I'm sure your\n"
	.string "Pokémon would be delighted if you let\l"
	.string "one of them hold it!$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally: @ 8202D91
	.string "Wanda: Don't worry about Basil.\n"
	.string "He'll be just fine.\p"
	.string "I know my little cousin, and he has\n"
	.string "Pokémon with him, too.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay: @ 8202E00
	.string "Thanks to you, I can see my girlfriend\n"
	.string "every day.\l"
	.string "Happy? You bet I am!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven: @ 8202E47
	.string "My daughter's boyfriend is a very\n"
	.string "driven and passionate sort of person.\p"
	.string "He's been digging a tunnel nonstop\n"
	.string "just so he can see my daughter.\p"
	.string "My daughter's a little concerned,\n"
	.string "so she goes out to the tunnel a lot.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging: @ 8202F19
	.string "It's amazing. My daughter's boyfriend\n"
	.string "was digging the tunnel by hand!\p"
	.string "It's so incredible!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally: @ 8202F73
	.string "If anything were to happen to Basil,\n"
	.string "I would never be able to look his\l"
	.string "parents in Petalburg in the eye…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande: @ 8202FDB
	.string "Basil was in Ever Grande?\p"
	.string "His parents in Petalburg would be\n"
	.string "astonished to hear that!$"

