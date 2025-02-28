MeteorFalls_1F_2R_MapScripts:: @ 822C4DD
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas:: @ 822C4DE
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas:: @ 822C50A
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas:: @ 822C529
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John:: @ 822C540
	trainerbattle_single TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn:: @ 822C570
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn:: @ 822C589
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay:: @ 822C5A4
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay:: @ 822C5D4
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay:: @ 822C5ED
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

Meteor_Falls1F_2R_EventScript_DragonAscentTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DragonAscentTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DragonAscentDeclined
	call Meteor_Falls1F_2R_EventScript_RayquazaCheck
	msgbox MoveTutor_Text_DragonAscentWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DRAGON_ASCENT
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DragonAscentDeclined
	goto MoveTutor_EventScript_DragonAscentTaught
	end

Meteor_Falls1F_2R_EventScript_RayquazaCheck::
	checkPartyHasSpecies SPECIES_RAYQUAZA
	compare VAR_RESULT, FALSE
	goto_if_eq Meteor_Falls1F_2R_EventScript_DragonAscentNoFug
	return

Meteor_Falls1F_2R_EventScript_DragonAscentNoFug::
	msgbox MoveTutor_Text_DragonAscentNoFug, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DragonAscentDeclined::
	msgbox MoveTutor_Text_DragonAscentDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DragonAscentTaught::
	msgbox MoveTutor_Text_DragonAscentTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MeteorFalls_1F_2R_Text_NicolasIntro: @ 822C608
	.string "This is where we Dragon users do our\n"
	.string "training.\p"
	.string "The Champion even visits.\n"
	.string "Now do you see how special it is here?$"

MeteorFalls_1F_2R_Text_NicolasDefeat: @ 822C678
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle: @ 822C6A3
	.string "The road ahead remains long and harsh.\p"
	.string "When will my Pokémon and I become\n"
	.string "the best?$"

MeteorFalls_1F_2R_Text_NicolasRegister: @ 822C6F6
	.string "I want to know more about your power.\n"
	.string "Let me register you in my PokéNav.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro: @ 822C73F
	.string "Since we met, we have trained hard\n"
	.string "with our sights on number one.\p"
	.string "Help us see how much stronger we've\n"
	.string "become!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat: @ 822C7AD
	.string "Urgh!\n"
	.string "I didn't expect you to be so strong!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch: @ 822C7D8
	.string "You've obviously kept up your\n"
	.string "Pokémon training.\p"
	.string "So long as you remain strong, I, too,\n"
	.string "can become stronger!$"

MeteorFalls_1F_2R_Text_JohnIntro: @ 822C843
	.string "When I was in AMAs, I learned Zephiel,\n"
	.string "and then when I was collecting, I got\l"
	.string "Henry since he was cheap.\p"
	.string "Now both of them are banned…$"

MeteorFalls_1F_2R_Text_JohnDefeat: @ 822C89C
	.string "I guess I could queue with Brown, if\n"
	.string "there was a playable Brown deck.$"

MeteorFalls_1F_2R_Text_JohnPostBattle: @ 822C8C1
	.string "I guess I could queue with Brown, if\n"
	.string "there was a playable Brown deck.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons: @ 822C92B
	.string "John: Well, well, what a young Trainer!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRegister: @ 822C99C
	.string "John: Young Trainer, if the chance\n"
	.string "arises, will you battle with us again?$"

MeteorFalls_1F_2R_Text_JayIntro: @ 822C9E6
	.string "Jay: We've been married for\n"
	.string "fifty years.\p"
	.string "The bond we share as a couple could\n"
	.string "never be broken.$"

MeteorFalls_1F_2R_Text_JayDefeat: @ 822CA44
	.string "Jay: Oh, dear.\n"
	.string "We've lost, my dear husband.$"

MeteorFalls_1F_2R_Text_JayPostBattle: @ 822CA70
	.string "Jay: Fifty years of marriage…\p"
	.string "If we ever argued, we always settled\n"
	.string "it with a Pokémon battle…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons: @ 822CACD
	.string "Jay: Well, well, aren't you a young\n"
	.string "Trainer?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro: @ 822CB47
	.string "John: We've always battled Pokémon\n"
	.string "together as a twosome.\l"
	.string "We've confidence in ourselves.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat: @ 822CBA0
	.string "John: Oh, my.\n"
	.string "We've lost, dear wife.$"

MeteorFalls_1F_2R_Text_JohnPostRematch: @ 822CBC5
	.string "John: Married for fifty years…\p"
	.string "On reflection, the dear wife and I,\n"
	.string "we battled day in and day out…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons: @ 822CC27
	.string "John: Well, well, what a young Trainer!\p"
	.string "Will you battle with us? If so, you'll\n"
	.string "have to return with more Pokémon.$"

MeteorFalls_1F_2R_Text_JayRematchIntro: @ 822CC98
	.string "Jay: We've been married for\n"
	.string "fifty years.\p"
	.string "We've supported each other all that\n"
	.string "time. We've made ourselves strong.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat: @ 822CD08
	.string "Jay: Oh, dear.\n"
	.string "We've lost, my dear husband.$"

MeteorFalls_1F_2R_Text_JayPostRematch: @ 822CD34
	.string "Jay: Fifty years of marriage…\n"
	.string "Many things have happened.\p"
	.string "I hope that we will continue to make\n"
	.string "happy memories together.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons: @ 822CDAB
	.string "Jay: Well, well, aren't you a young\n"
	.string "Trainer?\p"
	.string "If you'd care to battle with us, you'll\n"
	.string "have to come back with more Pokémon.$"

MoveTutor_Text_DragonAscentTeach:
	.string "Hmm… Do you want me to teach\n"
	.string "Dragon Ascent to your Pokémon?$"

MoveTutor_Text_DragonAscentWhichMon:
	.string "Which Pokémon do you want me to teach\n"
	.string "the move?$"

MoveTutor_Text_DragonAscentNoFug:
	.string "Hmm… Only Rayquaza can learn\n"
	.string "Dragon Ascent.\l"
	.string "You don't seem to have one.$"

MoveTutor_Text_DragonAscentDeclined:
	.string "Hmm… I see.\n"
	.string "Come back anytime you need my help.$"

MoveTutor_Text_DragonAscentTaught:
	.string "Dragon Ascent is a powerful move that\n"
	.string "only Rayquaza can use.\p"
	.string "They say its power is so strong that\n"
	.string "even a huge meteoroid can be broken\l"
	.string "into pieces with one attack.$"
