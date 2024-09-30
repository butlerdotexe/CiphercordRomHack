.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	call Common_EventScript_SetupRivalGfxId
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave:: @ 822BD3A
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene:: @ 822BD5F
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_Brendan
MeteorFalls_1F_1R_EventScript_MagmaAfterBattle::
	applymovement 6, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 11, Common_Movement_WalkInPlaceFastestLeft
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement 11, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement 5, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement 6, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 11, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WatchAquaLeave
	applymovement 11, MeteorFalls_1F_1R_Movement_WatchAquaLeave
	waitmovement 0
	fadedefaultbgm
	removeobject 7
	removeobject 8
	removeobject 9
	special RemoveCameraObject
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_EventScript_May::
	msgbox MeteorFalls_1F_1R_Text_MayBozos, MSGBOX_DEFAULT
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_Brat, MSGBOX_DEFAULT
	closemessage
MeteorFalls_1F_1R_EventScript_MayAfterCancel::
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_MayPlayerHere, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MeteorFalls_1F_1R_EventScript_CancelMultiBattle
	case YES, MeteorFalls_1F_1R_EventScript_MultiMay
	end

MeteorFalls_1F_1R_EventScript_Brendan::
	msgbox MeteorFalls_1F_1R_Text_BrendanJerks, MSGBOX_DEFAULT
	closemessage
	applymovement 6, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_Brat, MSGBOX_DEFAULT
	closemessage
MeteorFalls_1F_1R_EventScript_BrendanAfterCancel::
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BrendanPlayerHere, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MeteorFalls_1F_1R_EventScript_CancelMultiBattle
	case YES, MeteorFalls_1F_1R_EventScript_MultiBrendan
	end

MeteorFalls_1F_1R_EventScript_MultiMay::
	msgbox MeteorFalls_1F_1R_Text_MayLetsBattle, MSGBOX_DEFAULT
	applymovement 5, MeteorFalls_1F_1R_Movement_WalkRight1
	applymovement 11, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_CourtneyLetsBattle, MSGBOX_DEFAULT
	choose_mons
    compare VAR_RESULT, 0
    call_if_eq MeteorFalls_1F_1R_EventScript_ChooseMons
	switch VAR_STARTER_MON
	case 0, MeteorFalls_1F_1R_EventScript_MayBattleTreecko
	case 1, MeteorFalls_1F_1R_EventScript_MayBattleTorchic
	case 2, MeteorFalls_1F_1R_EventScript_MayBattleMudkip
	end

MeteorFalls_1F_1R_EventScript_MultiBrendan::
	msgbox MeteorFalls_1F_1R_Text_BrendayLetsBattle, MSGBOX_DEFAULT
	applymovement 5, MeteorFalls_1F_1R_Movement_WalkRight1
	applymovement 11, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_CourtneyLetsBattle, MSGBOX_DEFAULT
	choose_mons
    compare VAR_RESULT, 0
    call_if_eq MeteorFalls_1F_1R_EventScript_ChooseMons
	switch VAR_STARTER_MON
	case 0, MeteorFalls_1F_1R_EventScript_BrendanBattleTreecko
	case 1, MeteorFalls_1F_1R_EventScript_BrendanBattleTorchic
	case 2, MeteorFalls_1F_1R_EventScript_BrendanBattleMudkip
	end

MeteorFalls_1F_1R_EventScript_MayBattleTreecko::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_TREECKO_METEOR_FALLS, TRAINER_BACK_PIC_MAY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_MayBattleTorchic::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_TORCHIC_METEOR_FALLS, TRAINER_BACK_PIC_MAY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_MayBattleMudkip::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_MUDKIP_METEOR_FALLS, TRAINER_BACK_PIC_MAY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_BrendanBattleTreecko::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_TREECKO_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_BrendanBattleTorchic::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_TORCHIC_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_BrendanBattleMudkip::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_MUDKIP_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_ChooseMons::
    msgbox MeteorFalls_1F_1R_Text_ChooseMons, MSGBOX_DEFAULT
    choose_mons
    compare VAR_RESULT, 0
    goto_if_eq MeteorFalls_1F_1R_EventScript_CancelMultiBattle
    return

MeteorFalls_1F_1R_EventScript_CancelMultiBattle::
    msgbox MeteorFalls_1F_1R_Text_CancelMultiBattle, MSGBOX_DEFAULT
	setvar VAR_METEOR_FALLS_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_Camera2
	waitmovement 0
	special RemoveCameraObject
	fadedefaultbgm
    releaseall
    end

MeteorFalls_1F_1R_EventScript_Lost::
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

MeteorFalls_1F_1R_EventScript_MultiCancelled::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_MayAfterCancel
	compare VAR_RESULT, FEMALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_BrendanAfterCancel

MeteorFalls_1F_1R_EventScript_RivalTalkAfterBattle::
	lock
	faceplayer
	msgbox MeteorFalls_1F_1R_Text_RivalAfterBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Movement_WalkDown2:
	walk_down
	walk_down
	step_end

MeteorFalls_1F_1R_Movement_Camera2:
	walk_up
	walk_up
	step_end

MeteorFalls_1F_1R_Movement_WalkRight1:
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit: @ 822BEC4
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit: @ 822BECE
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive: @ 822BED9
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive: @ 822BEE0
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive: @ 822BEE8
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit: @ 822BEF0
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer: @ 822BEF8
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit: @ 822BEFE
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie: @ 822BF08
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit: @ 822BF0D
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie: @ 822BF18
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_fastest_left
	delay_4
	walk_in_place_fastest_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_Movement_WatchAquaLeave:
	delay_16
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_MayBozos:
	.string "Sauce: Hey! You bastards!\n"
	.string "Let Professor Cozmo go!$"

MeteorFalls_1F_1R_Text_BrendanJerks:
	.string "Sauce: Hey! You bastards!\n"
	.string "I'll teach you a lesson!$"

MeteorFalls_1F_1R_Text_Brat:
	.string "Ha! There's two of us and only\n"
	.string "one of you.\p"
	.string "Oh wait who is that?$"

MeteorFalls_1F_1R_Text_MayPlayerHere:
	.string "Sauce: {PLAYER}! You finally made\n" 
	.string "it, huh!\p"
	.string "These guys are the guys who took\n"
	.string "the professor! They're also just\l"
	.string "massive pricks.\p"
	.string "Let's team up and show them what's\p"
	.string "good! Let's tag team them!$"

MeteorFalls_1F_1R_Text_BrendanPlayerHere:
	.string "Sauce: {PLAYER}! You finally made\n" 
	.string "it, huh!\p"
	.string "These guys are the guys who took\n"
	.string "the professor! They're also just\l"
	.string "massive pricks.\p"
	.string "Let's team up and show them what's\p"
	.string "good! Let's tag team them!\n"
	.string "DEVNOTE: Seriously save before this,\n"
	.string "it can soft lock.$"

MeteorFalls_1F_1R_Text_MayLetsBattle:
	.string "Thanks, bro!$"

MeteorFalls_1F_1R_Text_BrendayLetsBattle:
	.string "Thanks, bro!$"

MeteorFalls_1F_1R_Text_CourtneyLetsBattle:
	.string "Ahahaha!\p"
	.string "You think you can stand up to the\n"
	.string "king of sac?\p"
	.string "I'll beat you before you can blink!$"

MeteorFalls_1F_1R_Text_CourtneyLose:
	.string "What?! How did I end up sacked?$"

MeteorFalls_1F_1R_Text_GruntLose:
	.string "Are you telling me you're that strong\n"
	.string "and still just kids?!$"

MeteorFalls_1F_1R_Text_ChooseMons:
	.string "Choose which Pokémon will battle.$"

MeteorFalls_1F_1R_Text_CancelMultiBattle:
	.string "Oh, you've got to get ready first?\n"
	.string "OK, but please hurry!$"

MeteorFalls_1F_1R_Text_WithThisMeteorite: @ 822BF47
	.string "Well, that's embarrasing, after the\n"
	.string "whole 'king of sac' thing.\p"
	.string "Oh well, I'l still taking this meteor,\n"
	.string "and then Mt. Chimney will…$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma: @ 822BFE4
	.string "Hold it right there, Team Aggro!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can run around our turf!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua: @ 822C04E
	.string "Ooooh noooo!\n"
	.string "It's Team Stall! Whatever shall we do?\n"
	.string "It would be a shame if I just started"
	.string "casusally jogging away…$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore: @ 822C11C
	.string "Rosa: Damn! My one weakness, going fast.\n"
	.string "That guy is pretty good.\p"
	.string "Oh, you again. You're not with them\n"
	.string "are you?\p"
	.string "They're a pain, running around doing\n"
	.string "crazy shit, winning as soon as possible.\p"
	.string "They're not like us, who savor battles\n"
	.string "to the fullest!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma: @ 822C268
	.string "Boss, we should give chase to\n"
	.string "Team Stall…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo: @ 822C292
	.string "Rosa: Yes, as fast as we can!\n"
	.string "Which isn't that fast but still.\p"
	.string "There's no telling what Team Aggro\n"
	.string "will do at Mt. Chimney!$"

MeteorFalls_1F_1R_Text_ArchieFarewell: @ 822C2FC
	.string "Rosa: {PLAYER}, you should keep\n"
	.string "an eye out for Team Aggro, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo: @ 822C342
	.string "I… I'm Cozmo…\n"
	.string "I'm a Professor\p"
	.string "Team Aggro asked me to guide them\n"
	.string "to Meteor Falls…\p"
	.string "But they tricked me.\n"
	.string "They even took my Meteorite away…\p"
	.string "And then another similar bunch,\n"
	.string "Team Stall showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that Team Aggro…\p"
	.string "What are they going to do with that\n"
	.string "Meteorite at Mt. Chimney?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney: @ 822C47D
	.string "Prof. Cozmo: But that Team Aggro…\p"
	.string "What are they going to do with that\n"
	.string "Meteorite at Mt. Chimney?$"

MeteorFalls_1F_1R_Text_RivalAfterBattle:
	.string "Never mind what's happened!\p"
	.string "I've got to get the professor back to\n"
	.string "his lab in Fallarbor!$"
