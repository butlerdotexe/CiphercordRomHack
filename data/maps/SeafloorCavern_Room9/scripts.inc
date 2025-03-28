.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts:: @ 8234DC8
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre:: @ 8234DC9
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_BlueOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	playmoncry SPECIES_KYOGRE, 2
	waitmoncry
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisBlueOrb, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 255, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer: @ 823502A
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1: @ 8235032
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage: @ 8235035
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2: @ 8235038
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit: @ 823503A
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_fastest_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach: @ 8235040
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit: @ 823504B
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive: @ 823504E
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit: @ 8235054
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive: @ 8235057
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32: @ 823505C
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere: @ 823505F
	.string "Rosa: Hold it right there.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou: @ 823507C
	.string "Rosa: Oh.\n"
	.string "So it was you.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre: @ 82350A6
	.string "Rosa: Well, here it is.\p"
	.string "Kyogre, a Pokémon powerful enough\n"
	.string "to make any strategy possible.$"

SeafloorCavern_Room9_Text_BlueOrbShinesByItself: @ 8235279
	.string "Rosa: Time to wake up, bae!\p"
	.string "You and me, we're gonna put Stall\n"
	.string "back on the menu!$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear: @ 823512C
	.string "Rosa: Ha…\n"
	.string "Now that I have Kyogre, nothing can\n"
	.string "defeat my Stall gameplan!\p"
	.string "And to prove it, how about I show you\n"
	.string "the true potential of Stall!$"

SeafloorCavern_Room9_Text_ArchieDefeat: @ 82351BC
	.string "What?!\n"
	.string "How on earth did you break through?$"

SeafloorCavern_Room9_Text_ArchieWithThisBlueOrb: @ 82351E5
	.string "Rosa: Well…\p"
	.string "I'll admit, I did not expect you to\n"
	.string "actually win there.\p"
	.string "But!\n"
	.string "I still have the Blue Orb!\p"
	.string "As long as I have it, Kyogre will-$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo: @ 82352A7
	.string "Rosa: What?!\p"
	.string "I didn't do anything.\n"
	.string "Where did Kyogre go?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside: @ 82352F6
	.string "Rosa: Hm? It's a message from our\n"
	.string "members outside…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard: @ 823532B
	.string "Rosa: What is it?\p"
	.string "Hm…\n"
	.string "It's raining heavily?\p"
	.string "The sea level is rising, and if\n"
	.string "it continues, the world will be\l"
	.string "flooded??\p"
	.string "Oh no. No no no.$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear: @ 823546F
	.string "Rosa: How did this happen?\p"
	.string "The Blue Orb is supposed to awaken\n"
	.string "and control Kyogre!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought: @ 82354F0
	.string "Fallen: AHAHAHAHA!\p"
	.string "You fucking idiot. Legendary Pokémon\n"
	.string "aren't interested in losers like us.\p"
	.string "When we lost to this kid, they go on\n"
	.string "their own and fuck shit up.$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty: @ 82355C2
	.string "Rosa: W-what?!\n"
	.string "No! No no no no!\p"
	.string "I just wanted to make my Stall\n"
	.string "team better, not become a terrorist!$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue: @ 8235692
	.string "Fallen: Oh its too late for that!\p"
	.string "Come on, let's see how you Stall team\n"
	.string "member is doing up there.$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer: @ 8235723
	.string "Fallen: {PLAYER}, you should come too.\n"
	.string "After all, you played a part in this!$"
