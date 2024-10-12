VictoryRoad_B2F_MapScripts:: @ 82368D4
	.byte 0

VictoryRoad_B2F_EventScript_Vito:: @ 82368D5
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen:: @ 82368EC
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline:: @ 8236903
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie:: @ 823691A
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix:: @ 8236931
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne:: @ 8236948
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro: @ 823695F
	.string "Finally I get to use my favorites-\n"
	.string "Let's go Dragonite! Victini!$"

VictoryRoad_B2F_Text_VitoDefeat: @ 82369B3
	.string "They lost, but they're still my\n"
	.string "favortie Pokémon.$"

VictoryRoad_B2F_Text_VitoPostBattle: @ 82369DE
	.string "They lost, but they're still my\n"
	.string "favortie Pokémon.$"

VictoryRoad_B2F_Text_OwenIntro: @ 8236A4C
	.string "I am Dimitri's number one fan, but even\n"
	.string "I'll admit he is ass.$"

VictoryRoad_B2F_Text_OwenDefeat: @ 8236A92
	.string "Its just compared to the rest of Brown,\n"
	.string "he's the least ass.$"

VictoryRoad_B2F_Text_OwenPostBattle: @ 8236AAE
	.string "Its just compared to the rest of Brown,\n"
	.string "he's the least ass.$"

VictoryRoad_B2F_Text_CarolineIntro: @ 8236AF0
	.string "I need to win so I can have money for\n"
	.string "gacha pulls.$"

VictoryRoad_B2F_Text_CarolineDefeat: @ 8236B14
	.string "I hate my lack of control when using\n"
	.string "gacha currency…$"

VictoryRoad_B2F_Text_CarolinePostBattle: @ 8236B2F
	.string "I hate my lack of control when using\n"
	.string "gacha currency…$"

VictoryRoad_B2F_Text_JulieIntro: @ 8236B88
	.string "I'm a based Roy abuser and I'm proud\n"
	.string "of it! $"

VictoryRoad_B2F_Text_JulieDefeat: @ 8236C0A
	.string "I am THE Roy guy!$"

VictoryRoad_B2F_Text_JuliePostBattle: @ 8236C21
	.string "I am THE Roy guy!$"

VictoryRoad_B2F_Text_FelixIntro: @ 8236C67
	.string "Opened one of my B20s and got a Vallui\n"
	.string "SR+, so guess I picked the right one.$"

VictoryRoad_B2F_Text_FelixDefeat: @ 8236CAB
	.string "If only I was that lucky in our battle…$"

VictoryRoad_B2F_Text_FelixPostBattle: @ 8236CBA
	.string "If only I was that lucky in our battle…$"

VictoryRoad_B2F_Text_DianneIntro: @ 8236D27
	.string "I'm so sad Shez M got wrecked in like a\n"
	.string "week, when Fjorm came out with far save.$"

VictoryRoad_B2F_Text_DianneDefeat: @ 8236D6E
	.string "Maybe they'll make him a legendary unit…$"

VictoryRoad_B2F_Text_DiannePostBattle: @ 8236D8C
	.string "Maybe they'll make him a legendary unit…$"

