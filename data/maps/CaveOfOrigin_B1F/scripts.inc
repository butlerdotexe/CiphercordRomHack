.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts:: @ 82357A8
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace:: @ 82357A9
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza:: @ 82357F0
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin:: @ 823582C
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre:: @ 8235837
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember:: @ 8235842
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar:: @ 823584D
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory: @ 823586E
	.string "Who the fuck are you?\n"
	.string "…{PLAYER}{KUN}\p"
	.string "Huh, I don't actually care.\p"
	.string "Why the hell are you here bothering me?\n"
	.string "Answer fast or I'll ban you.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "So you're saying two idiots awakened\n"
	.string "legendary Pokémon, and are now fighting,\l"
	.string "which is going to end the world?\p"
	.string "Can't I fuckin live on in peace?\n"
	.string "God dammit.\p"
	.string "Alright, since you're here, surely\n"
	.string "you know what we have to do now.\p"
	.string "There's another Pokémon called Rayquaza\n"
	.string "that keeps those other two in line.\p"
	.string "We find him, wake him up, and then I\n"
	.string "can get back to planning my retirement.$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza: @ 8235ACE
	.string "Vance: You know where it is, right?$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin: @ 8235B23
	.string "Vance: Are you a fucking idiot?\n"
	.string "We're in the Cave of Origin right now!$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat: @ 8235BBF
	.string "Vance: Mt. Pyre?\p"
	.string "That's a cemetary dumbass.$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow: @ 8235C99
	.string "Vance: Are you a fucking idiot?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar: @ 8235CEE
	.string "Vance: Yeah of course its Sky Pillar.\p"
	.string "I'm going there now, you better be there\n"
	.string "or I'll beat your ass.$"

