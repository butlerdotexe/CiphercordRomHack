MtPyre_2F_MapScripts:: @ 82310FB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp: @ 823110B
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F, 255, 0, 0
	end

MtPyre_2F_EventScript_Woman:: @ 8231116
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM:: @ 823111F
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark:: @ 8231128
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke:: @ 823113F
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez:: @ 823115A
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah:: @ 8231175
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander:: @ 823118C
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty: @ 82311A3
	.string "Memories of my darling Skitty…\n"
	.string "My eyes overflow thinking about it.$"

MtPyre_2F_Text_TumbledFromFloorAbove: @ 82311E6
	.string "Ooch, ouch… There are holes in the\n"
	.string "ground here and there.\p"
	.string "I didn't notice and took a tumble from\n"
	.string "the floor above.$"

MtPyre_2F_Text_MarkIntro: @ 8231258
	.string "Let us dance with the shadows.\n"
	.string "Show me your spirit!$"

MtPyre_2F_Text_MarkDefeat: @ 82312A2
	.string "It seems the spirits favored you\n"
	.string "this time.$"

MtPyre_2F_Text_MarkPostBattle: @ 82312CB
	.string "It seems the spirits favored you\n"
	.string "this time.$"

MtPyre_2F_Text_LukeIntro: @ 823130F
	.string "Luke: We're here on a dare.\p"
	.string "Heheh, if I show her how cool I am,\n"
	.string "she'll fall for me. I know it!\p"
	.string "I know! I'll cream you and show her\n"
	.string "how cool I am!$"

MtPyre_2F_Text_LukeDefeat: @ 82313A1
	.string "Luke: Whoopsie!$"

MtPyre_2F_Text_LukePostBattle: @ 82313B1
	.string "Luke: Well, we lost but that's okay!\n"
	.string "I'm right here by your side.\l"
	.string "We'll make it through this dare!$"

MtPyre_2F_Text_LukeNotEnoughMons: @ 8231414
	.string "Luke: If you want to take me on,\n"
	.string "bring some more Pokémon.\p"
	.string "If you don't, I won't be able to show\n"
	.string "off to my girl how cool I am!$"

MtPyre_2F_Text_DezIntro: @ 8231492
	.string "Dez: I came here on a dare with my\n"
	.string "boyfriend.\p"
	.string "It's really scary, but I'm with my\n"
	.string "boyfriend. It's okay.\p"
	.string "I know! I'll get my boyfriend to look\n"
	.string "cool by beating you!$"

MtPyre_2F_Text_DezDefeat: @ 8231534
	.string "Dez: Waaaah! I'm scared!$"

MtPyre_2F_Text_DezPostBattle: @ 823154D
	.string "Dez: We're lovey-dovey, so we don't\n"
	.string "care if we lose!$"

MtPyre_2F_Text_DezNotEnoughMons: @ 8231582
	.string "Dez: If you want to challenge us, you\n"
	.string "should bring at least two Pokémon.\p"
	.string "My boyfriend's strong.\n"
	.string "Just one Pokémon won't do at all.$"

MtPyre_2F_Text_LeahIntro: @ 8231604
	.string "Following meta is cringe- I bring\n"
	.string "RU pokemon to standard and nat dex.$"

MtPyre_2F_Text_LeahDefeat: @ 8231645
	.string "Well, most Pokemon have been buffed\n"
	.string "in this game, so RU doesn't exist.$"

MtPyre_2F_Text_LeahPostBattle: @ 823165A
	.string "Well, most Pokemon have been buffed\n"
	.string "in this game, so RU doesn't exist.$"

MtPyre_2F_Text_ZanderIntro: @ 82316C7
	.string "I've played Yugioh for over 11 years.\p"
	.string "I don't know what that says about me\n"
	.string "but it definitely says something.$"

MtPyre_2F_Text_ZanderDefeat: @ 82316E1
	.string "I miss 2018 Yugioh…$"

MtPyre_2F_Text_ZanderPostBattle: @ 82316FB
	.string "I miss 2018 Yugioh…$"

