AbandonedShip_Corridors_1F_MapScripts:: @ 82379A4
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster:: @ 82379A5
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie:: @ 82379AE
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro: @ 82379C5
	.string "I guess I can take a break from the\n"
	.string "artifact grind to battle.$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat: @ 8237A01
	.string "OUAGH\p"
	.string "Oh, not you. The artifact I got just\n"
	.string "leveled like shit.$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle: @ 8237A1B
	.string "OUAGH\p"
	.string "Oh, not you. The artifact I got just\n"
	.string "leveled like shit.$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere: @ 8237A60
	.string "Isn't it fun here?\n"
	.string "I get excited just being here!$"
