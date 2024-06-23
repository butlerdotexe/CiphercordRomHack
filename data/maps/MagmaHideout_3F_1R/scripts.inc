MagmaHideout_3F_1R_MapScripts:: @ 823A1B2
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9:: @ 823A1B3
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16:: @ 823A1CA
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro: @ 823A1E1
	.string "Ha! You think you'll get a break?\n"
	.string "This is Team Aggro!\p"
	.string "Ganging up and rushing in is our\n"
	.string "specialty!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat: @ 823A229
	.string "I'm getting heat exhaustion…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle: @ 823A246
	.string "Do you think it's odd that we're wearing\n"
	.string "hoods in this magma-filled volcano?$"

MagmaHideout_3F_1R_Text_Grunt16Intro: @ 823A293
	.string "Let's see if you can handle our blitz-\n"
	.string "style fighting!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat: @ 823A353
	.string "Fuck!\n"
	.string "Wait this is a kids game. Damnit!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle: @ 823A37C
	.string "Listen to me.\n"
	.string "Team Aggro is right!\p"
	.string "Don't listen to Team Stall.\n"
	.string "Don't believe their lies!$"

