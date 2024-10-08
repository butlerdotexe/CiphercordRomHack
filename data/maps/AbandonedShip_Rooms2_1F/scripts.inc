AbandonedShip_Rooms2_1F_MapScripts:: @ 82380A6
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan:: @ 82380A7
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan:: @ 82380D7
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch:: @ 82380F0
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira:: @ 823810B
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira:: @ 823813B
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch:: @ 8238154
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani:: @ 823816F
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison:: @ 8238186
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro: @ 823819D
	.string "Dan: While searching for treasures,\n"
	.string "we discovered a Trainer!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat: @ 82381DA
	.string "Dan: We couldn't win even though\n"
	.string "we worked together…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle: @ 823820F
	.string "Dan: We can't find any treasures…\n"
	.string "I wonder if someone got them already?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons: @ 8238257
	.string "Dan: You don't even have two Pokémon.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro: @ 82382A4
	.string "Kira: Oh?\n"
	.string "We were searching for treasures.\l"
	.string "But we discovered a Trainer instead!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat: @ 82382F4
	.string "Kira: Ooh, so strong!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle: @ 823830A
	.string "Kira: Where could the treasures be?\p"
	.string "I've already decided what I'm buying\n"
	.string "when we find the treasures!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons: @ 823836F
	.string "Kira: Oh, you don't have two Pokémon?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister: @ 82383BB
	.string "Kira: Oh, you make me so angry!\n"
	.string "I'm going to register you for that!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro: @ 82383FF
	.string "Dan: We've been searching for\n"
	.string "treasures all this time.\p"
	.string "Our Pokémon have grown stronger, too.\n"
	.string "Let us show you, okay?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat: @ 8238473
	.string "Dan: You're strong, as usual!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch: @ 8238491
	.string "Dan: We can't find any treasures,\n"
	.string "we lose at Pokémon…\p"
	.string "I want to go home… But if I say that,\n"
	.string "she gets all angry with me…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons: @ 8238509
	.string "Dan: You don't even have two Pokémon.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro: @ 8238556
	.string "Kira: Oh? We meet again!\p"
	.string "Just like us, you still haven't given up\n"
	.string "searching for treasures, have you?\p"
	.string "Want to make it so the loser has\n"
	.string "to give up searching?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat: @ 82385F2
	.string "Kira: Oh, we lost again…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch: @ 823860B
	.string "Kira: We're not leaving until we raise\n"
	.string "our Pokémon some more and we find\l"
	.string "the treasures here!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons: @ 8238668
	.string "Kira: Oh, you don't have two Pokémon?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro: @ 82386B4
	.string "Hmph, and who are you? …\p"
	.string "Well, I may be on vacation, but I\n"
	.string "suppose I can make time for a battle.$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat: @ 82386E8
	.string "My, my. Were we in my region, you\n"
	.string "might have earned yourself a badge.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle: @ 8238708
	.string "Too bad we're not.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro: @ 823873F
	.string "I wonder if my legacy on Ciphercord\n"
	.string "is just that one 7 hour set I played\l"
	.string "in AMAs…$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat: @ 8238779
	.string "Either way, I'm never voluntarily\n"
	.string "playing a yellow mirror again.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle: @ 82387A9
	.string "Either way, I'm never voluntarily\n"
	.string "playing a yellow mirror again.$"
