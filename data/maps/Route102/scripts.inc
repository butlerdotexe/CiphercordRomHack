Route102_MapScripts:: @ 81EC0E0
	.byte 0

Route102_EventScript_LittleBoy:: @ 81EC0E1
	trainerbattle_single TRAINER_CALVIN_2, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_RouteSignOldale:: @ 81EC0EA
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg:: @ 81EC0F3
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy:: @ 81EC0FC
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle:: @ 81EC146
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall:: @ 81EC157
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_CalvinRegister:: @ 81EC183
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 81EC1F8
	.string "Basil: {PLAYER}…\n"
	.string "I've been searching all this time,\l"
	.string "for the pokémon that will complete me.\p"
	.string "With you here, I think I can finally\n"
	.string "find it.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt: @ 81EC271
	.string "Basil: I did it… It's my…\n"
	.string "My Pokémon!$"

Route102_Text_LetsGoBack: @ 81EC297
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the Gym!$"

Route102_Text_ImNotVeryTall: @ 81EC2C0
	.string "I'm… not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon: @ 81EC32E
	.string "I'm going to catch a whole bunch of\n"
	.string "Pokémon!$"

Route102_Text_RouteSignOldale: @ 81EC35B
	.string "Route 102\n"
	.string "{RIGHT_ARROW} Oldale Town$"

Route102_Text_RouteSignPetalburg: @ 81EC373
	.string "Route 102\n"
	.string "{LEFT_ARROW} Petalburg City$"
