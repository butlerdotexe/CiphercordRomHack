.set LOCALID_HIDEOUT_GUARD, 5
.set LOCALID_CHANSEY, 8

JaggedPass_MapScripts:: @ 8230656
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume: @ 8230666
	setstepcallback STEP_CB_ASH
	compare VAR_JAGGED_PASS_STATE, 0
	call_if_eq JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem:: @ 8230674
	checkitem ITEM_MAGMA_EMBLEM, 1
	compare VAR_RESULT, TRUE
	goto_if_eq JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout:: @ 8230685
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition: @ 823068B
	compare VAR_JAGGED_PASS_ASH_WEATHER, 1
	call_if_eq JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh:: @ 8230697
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad: @ 823069C
	compare VAR_JAGGED_PASS_STATE, 1
	goto_if_le JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance:: @ 82306A8
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, 1
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, 1
	end

JaggedPass_EventScript_OpenMagmaHideout:: @ 82306BB
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, 1
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, 0
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard:: @ 8230718
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated:: @ 8230766
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Chansey::
	lockall
	applymovement LOCALID_CHANSEY, Common_Movement_FacePlayer
	waitmovement 0
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 11
	goto_if_eq JaggedPass_EventScript_ChanseyShove
	applymovement LOCALID_CHANSEY, JaggedPass_Movement_ChanseyJumpRight
	waitmovement 0
	waitse
	playmoncry SPECIES_CHANSEY, 0
	delay 40
	waitmoncry
	applymovement LOCALID_CHANSEY, JaggedPass_Movement_ChanseyEscape
	waitmovement 0
	removeObject LOCALID_CHANSEY
	setvar VAR_CHANSEY_NURSE_STATE, 3
	releaseall
	end

JaggedPass_EventScript_ChanseyShove::
	applymovement LOCALID_CHANSEY, JaggedPass_Movement_ChanseyJumpLeft
	waitmovement 0
	waitse
	playmoncry SPECIES_CHANSEY, 0
	delay 40
	waitmoncry
	applymovement LOCALID_CHANSEY, JaggedPass_Movement_ChanseyShove
	applymovement OBJ_EVENT_ID_PLAYER, JaggedPass_Movement_PlayerShove
	waitmovement 0
	applymovement LOCALID_CHANSEY, JaggedPass_Movement_ChanseyEscape
	waitmovement 0
	removeObject LOCALID_CHANSEY
	setvar VAR_CHANSEY_NURSE_STATE, 3
	releaseall
	end

JaggedPass_Movement_ChanseyJumpRight:
	jump_in_place_right
	delay_4
	jump_in_place_right
	step_end

JaggedPass_Movement_ChanseyJumpLeft:
	jump_in_place_left
	delay_4
	jump_in_place_left
	step_end

JaggedPass_Movement_ChanseyEscape:
	walk_left
	walk_left
	walk_left
	walk_left
	jump_left
	walk_up
	delay_4
	step_end

JaggedPass_Movement_ChanseyShove:
	walk_left
	jump_in_place_down
	walk_left
	walk_left
	walk_left
	jump_left
	walk_up
	delay_4
	step_end

JaggedPass_Movement_PlayerShove:
 	walk_in_place_fastest_up
    lock_facing_direction
	walk_down
	jump_down
	unlock_facing_direction
	step_end

JaggedPass_EventScript_Eric:: @ 8230785
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana:: @ 823079C
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_RegisterDiana:: @ 82307C8
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch:: @ 82307E4
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan:: @ 82307FB
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_AUTOCLOSE
	release
	end

JaggedPass_EventScript_RegisterEthan:: @ 8230827
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch:: @ 8230843
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio:: @ 823085A
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn:: @ 8230871
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro: @ 8230888
	.string "I've played Yugioh for over 11 years.\p"
	.string "I don't know what that says about me\n"
	.string "but it definitely says something.$"

JaggedPass_Text_EricDefeat: @ 82308FF
	.string "I miss 2018 Yugioh…$"

JaggedPass_Text_EricPostBattle: @ 8230916
	.string "I miss 2018 Yugioh…$"

JaggedPass_Text_DianaIntro: @ 8230974
	.string "A new Fire Emblem figure is coming\n"
	.string "out, so I need this money.$"

JaggedPass_Text_DianaDefeat: @ 82309B5
	.string "Well, guess I can not eat instead.$"

JaggedPass_Text_DianaPostBattle: @ 82309D8
	.string "Well, guess I can not eat instead.$"

JaggedPass_Text_DianaRegister: @ 8230A2C
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"

JaggedPass_Text_DianaRematchIntro: @ 8230A76
	.string "Picnics are fun wherever you go.\n"
	.string "Just like Pokémon!$"

JaggedPass_Text_DianaRematchDefeat: @ 8230AAA
	.string "I only lost because the ground is\n"
	.string "too bumpy!$"

JaggedPass_Text_DianaPostRematch: @ 8230AD7
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"

JaggedPass_Text_EthanIntro: @ 8230B10
	.string "Dude, you have to see the clip I\n"
	.string "just posted on Twitter.$"

JaggedPass_Text_EthanDefeat: @ 8230B50
	.string "What? Cipher? I'm here for the\n"
	.string "fighting games channel.$"

JaggedPass_Text_EthanPostBattle: @ 8230B93
	.string "What? Cipher? I'm here for the\n"
	.string "fighting games channel.$"

JaggedPass_Text_EthanRegister: @ 8230BC6
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your PokéNav?$"

JaggedPass_Text_EthanRematchIntro: @ 8230C28
	.string "I got used to this bumpiness.\n"
	.string "I sing while I climb now.$"

JaggedPass_Text_EthanRematchDefeat: @ 8230C60
	.string "It's still not easy to battle on this\n"
	.string "bumpy ground…$"

JaggedPass_Text_EthanPostRematch: @ 8230C94
	.string "I should get an Acro Bike from RYDEL\n"
	.string "in Mauville City…$"

JaggedPass_Text_GruntIntro: @ 8230CCB
	.string "Wah!\n"
	.string "What are you doing here?\p"
	.string "What am I doing in a place like this?\p"
	.string "What business is it of yours?$"

JaggedPass_Text_GruntDefeat: @ 8230D2D
	.string "Urrrgh…\p"
	.string "I should've ducked into our Hideout\n"
	.string "right away…$"

JaggedPass_Text_GoWhereverYouWant: @ 8230D65
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem: @ 8230DBA
	.string "Oh! This boulder is shaking in response\n"
	.string "to the Magma Emblem!$"

JaggedPass_Text_JulioIntro: @ 8230DF7
	.string "I refuse to acknowledge any deck that\n"
	.string "loses to Mono Chrom.$"

JaggedPass_Text_JulioDefeat: @ 8230E38
	.string "This means nothing…\n"
	.string "Chrom is still the best C lord!$"

JaggedPass_Text_JulioPostBattle: @ 8230E57
	.string "This means nothing…\n"
	.string "Chrom is still the best C lord!$"

JaggedPass_Text_AutumnIntro: @ 8230E8E
	.string "I've been working on an autograph\n"
	.string "collection- I've got Jeralt, M Byleth,\p"
	.string "Hubert, Linhardt, Caspar…$"

JaggedPass_Text_AutumnDefeat: @ 8230ECD
	.string "Oh yeah, and a steelcase signed by Alear!$"

JaggedPass_Text_AutumnPostBattle: @ 8230EE3
	.string "Oh yeah, and a steelcase signed by Alear!$"

