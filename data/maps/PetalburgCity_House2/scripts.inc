PetalburgCity_House2_MapScripts:: @ 82078F2
	.byte 0

PetalburgCity_House2_EventScript_Woman:: @ 82078F3
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid:: @ 82078FC
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader: @ 8207905
	.string "Racc became our town's new\n"
	.string "Gym Leader.\p"
	.string "It used to be this guy, Norman, who\n"
	.string "used all normal types.\p"
	.string "But then Racc sent out 2 Pokémon at once\n"
	.string "and overwhelmed him.$"

PetalburgCity_House2_Text_BattledNormanOnce: @ 8207969
	.string "I battled Racc once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for double battles.$"

