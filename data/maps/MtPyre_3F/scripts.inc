MtPyre_3F_MapScripts:: @ 8231752
	.byte 0

MtPyre_3F_EventScript_William:: @ 8231753
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla:: @ 823176A
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle:: @ 8231781
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle:: @ 82317AD
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle:: @ 82317CC
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro: @ 82317E3
	.string "Oh its you again. You know, I've\n"
	.string "been thinking of trying a new deck.\p"
	.string "How do you feel about deckout Sophia?$"

MtPyre_3F_Text_WilliamDefeat: @ 8231853
	.string "Look if my opponent is having fun,\n"
	.string "then I'm not.$"

MtPyre_3F_Text_WilliamPostBattle: @ 8231869
	.string "Look if my opponent is having fun,\n"
	.string "then I'm not.$"

MtPyre_3F_Text_KaylaIntro: @ 82318A1
	.string "I saw someone playing brown the other\n"
	.string "day. Did no one have the heart to tell\l"
	.string "the Byleth player that Byleth sucks?$"

MtPyre_3F_Text_KaylaDefeat: @ 82318DD
	.string "Oh never mind, they're Sauce's AMA.$"

MtPyre_3F_Text_KaylaPostBattle: @ 82318F2
	.string "Oh never mind, they're Sauce's AMA.$"

MtPyre_3F_Text_GabrielleIntro: @ 8231952
	.string "Why have you come here?$"

MtPyre_3F_Text_GabrielleDefeat: @ 823196A
	.string "That was amazing!\n"
	.string "You're a very special Trainer.$"

MtPyre_3F_Text_GabriellePostBattle: @ 823199B
	.string "Pokémon no longer of this world.\n"
	.string "Pokémon that are with you now.\p"
	.string "And the Pokémon that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "Please remember that.$"

MtPyre_3F_Text_GabrielleRegister: @ 8231A49
	.string "I would like to see your Pokémon\n"
	.string "when they grow up some more…\p"
	.string "Please, I need to see your PokéNav.$"

MtPyre_3F_Text_GabrielleRematchIntro: @ 8231AAB
	.string "Oh, it's you…\p"
	.string "Have you come to show me your grown\n"
	.string "Pokémon?$"

MtPyre_3F_Text_GabrielleRematchDefeat: @ 8231AE6
	.string "How amazing!\n"
	.string "You are a special person.$"

MtPyre_3F_Text_GabriellePostRematch: @ 8231B0D
	.string "Pokémon no longer of this world.\n"
	.string "Pokémon that are with you now.\p"
	.string "And the Pokémon that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "I see that you've remembered that.$"

