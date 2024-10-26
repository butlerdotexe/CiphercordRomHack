VictoryRoad_B1F_MapScripts:: @ 82364E4
	.byte 0

VictoryRoad_B1F_EventScript_Samuel:: @ 82364E5
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon:: @ 82364FC
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle:: @ 8236513
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell:: @ 823652A
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle:: @ 8236541
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro: @ 8236558
	.string "I can't believe I had one laptop that\n"
	.string "might explode, and suddenly I'm a terrorist.$"

VictoryRoad_B1F_Text_SamuelDefeat: @ 82365AD
	.string "Its not like I use it anymore!\p"
	.string "People at the laptop parts recycler lost\n"
	.string "their shit when they saw it annd wouldn't\l"
	.string "take it.$"

VictoryRoad_B1F_Text_SamuelPostBattle: @ 82365C4
	.string "Its not like I use it anymore!\p"
	.string "people at the laptop parts recycler lost\n"
	.string "their shit when they saw it annd wouldn't\l"
	.string "take it.$"

VictoryRoad_B1F_Text_ShannonIntro: @ 82365FD
	.string "It doesn't matter how many cards you\n"
	.string "run in your deck- no need for consistency\l"
	.string "if you can will your topdeck to be good.$"

VictoryRoad_B1F_Text_ShannonDefeat: @ 823664D
	.string "I should have willed my Pokémon to be\n"
	.string "good too…$"

VictoryRoad_B1F_Text_ShannonPostBattle: @ 8236678
	.string "I should have willed my Pokémon to be\n"
	.string "good too…$"

VictoryRoad_B1F_Text_MichelleIntro: @ 82366C2
	.string "You may have noticed my teams are a\n"
	.string "bit more fleshed out than most others.\p"
	.string "I made movesets for dozens of fights,\n"
	.string "made all the fights for Team Aggro,\l"
	.string "and played through this hack 4 times.\p"
	.string "I EARNED this.$"

VictoryRoad_B1F_Text_MichelleDefeat: @ 823670B
	.string "And you were able to beat me just fine.$"

VictoryRoad_B1F_Text_MichellePostBattle: @ 823671B
	.string "And you were able to beat me just fine.$"

VictoryRoad_B1F_Text_MitchellIntro: @ 8236757
	.string "You'll never guess what Pokémon type I\n"
	.string "like based off of my name.$"

VictoryRoad_B1F_Text_MitchellDefeat: @ 8236780
	.string "Shocking, right? Heh.$"

VictoryRoad_B1F_Text_MitchellPostBattle: @ 82367A7
	.string "Shocking, right? Heh.$"

VictoryRoad_B1F_Text_HalleIntro: @ 82367FD
	.string "I know I've got a lot of jank Marth\n"
	.string "lists, but Yellow Marth actually has legs.$"

VictoryRoad_B1F_Text_HalleDefeat: @ 823683B
	.string "It beat Oboro! At least once! That's\n"
	.string "gotta count for something.$"

VictoryRoad_B1F_Text_HallePostBattle: @ 823684C
	.string "It beat Oboro! At least once! That's\n"
	.string "gotta count for something.$"

