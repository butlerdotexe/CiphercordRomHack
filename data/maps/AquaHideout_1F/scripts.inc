AquaHideout_1F_MapScripts:: @ 8233493
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1:: @ 8233494
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1:: @ 82334B2
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1:: @ 82334BC
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2:: @ 82334C6
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2:: @ 82334E4
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2:: @ 82334EE
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1:: @ 82334F8
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated:: @ 8233513
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething: @ 823351D
	.string "Huh? You're not supposed to be in this\n"
	.string "part of the game yet.\p"
	.string "So I'm here to stop you from getting in\n"
	.string "and messing up the story\p"
	.string "… …\n"
	.string "Where are you supposed to go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe: @ 82335E3
	.string "Hahahahaha!\n"
	.string "You're still not supposed to be here!\p"
	.string "Have you not played these games before?\p"
	.string "I'm still not gonna tell you where to go!$"

AquaHideout_1F_Text_BossWentToJackASubmarine: @ 823367D
	.string "Alright, this part is kinda hard to tell\n"
	.string "where you're supposed to go.\p"
	.string "I won't blame you for this one.\p"
	.string "… …\n"
	.string "What? I'm still not gonna help you.$"

AquaHideout_1F_Text_BossIsOnRoute122: @ 8233739
	.string "Look man, I'll just tell you where\n"
	.string "you're supposed to go.\p"
	.string "You gotta go to route 122 and go up\n"
	.string "Mt. Pyre.\p"
	.string "… …\n"
	.string "Why am I telling you?\p"
	.string "Look you can just Google it, why\n"
	.string "bother holding you up?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney: @ 82337FA
	.string "Oh, its you. Yeah you gotta go\n"
	.string "Stop team Aggro now.\p"
	.string "Their hideout is on Mt. Chimney, on\n"
	.string "the pass heading down to Lavaridge.\p"
	.string "Go beat them up.$"

AquaHideout_1F_Text_BossIsInSlateportCity: @ 8233884
	.string "Yeahhh I don't blame you for not\n"
	.string "remembering this part.\p"
	.string "You gotta go find our Boss in Slateport\n"
	.string "City, and THEN come here.\p"
	.string "… …\p"
	.string "Yeah I don't know, we could have just\n"
	.string "had our own submarine here.\n"
	.string "But we have to follow the story script.$"

AquaHideout_1F_Text_Grunt1Intro: @ 823393D
	.string "Ayiyiyi!\n"
	.string "Suspicious character spotted!$"

AquaHideout_1F_Text_Grunt1Defeat: @ 8233964
	.string "Grrrrr…\n"
	.string "I lost it!$"

AquaHideout_1F_Text_Grunt1PostBattle: @ 8233977
	.string "I took the loss for the Team,\n"
	.string "but I did my job…$"

