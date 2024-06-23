SeafloorCavern_Room3_MapScripts:: @ 8234937
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly:: @ 8234938
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5:: @ 823494F
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro: @ 8234966
	.string "Heyyy what's up?\p"
	.string "Man I hope you didn't solve that\n"
	.string "little puzzle to try to avoid me.\p"
	.string "I have really good eyesight.\p"
	.string "Anyway, as per usual, I have to STALL\n"
	.string "you here. Heh.\p"
	.string "I actually got some pretty sick\n"
	.string "Pokémon since last time, wanna see?$"

SeafloorCavern_Room3_Text_ShellyDefeat: @ 8234A79
	.string "Oof, yeah, you got me.\p"
	.string "Oh well.$"

SeafloorCavern_Room3_Text_ShellyPostBattle: @ 8234A8A
	.string "Man I don't know about you, but I think\n"
	.string "that went really well.\p"
	.string "I know you're not all about the Stall\n"
	.string "stuff like us, but you should join!\p"
	.string "You can make friends, rob people, and\n"
	.string "we have great benefits.\p"
	.string "You should think about it!$"

SeafloorCavern_Room3_Text_Grunt5Intro: @ 8234B3A
	.string "For our dream to become real, we need\n"
	.string "the power of Pokémon.\p"
	.string "But meddlers like you use the power of\n"
	.string "Pokémon to mess with us even at\l"
	.string "a place like this!\p"
	.string "Life just doesn't work the way we\n"
	.string "need it to!$"

SeafloorCavern_Room3_Text_Grunt5Defeat: @ 8234BFE
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle: @ 8234C04
	.string "You know, we don't dare question\n"
	.string "the motives of our leader.\p"
	.string "But here you are, just some punk,\n"
	.string "going up against our Boss.\p"
	.string "Maybe…\n"
	.string "You must be something…$"

