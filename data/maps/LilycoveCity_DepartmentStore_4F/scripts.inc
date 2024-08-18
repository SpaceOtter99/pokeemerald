LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM51
	.2byte ITEM_TM52
	.2byte ITEM_TM53
	.2byte ITEM_TM54
	.2byte ITEM_TM55
	.2byte ITEM_TM56
	.2byte ITEM_TM57
	.2byte ITEM_TM58
	.2byte ITEM_TM59
	.2byte ITEM_TM60
	.2byte ITEM_TM61
	.2byte ITEM_TM62
	.2byte ITEM_TM63
	.2byte ITEM_TM64
	.2byte ITEM_TM65
	.2byte ITEM_TM66
	.2byte ITEM_TM67
	.2byte ITEM_TM68
	.2byte ITEM_TM69
	.2byte ITEM_TM70
	.2byte ITEM_TM71
	.2byte ITEM_TM72
	.2byte ITEM_TM73
	.2byte ITEM_TM74
	.2byte ITEM_TM75
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM76
	.2byte ITEM_TM77
	.2byte ITEM_TM78
	.2byte ITEM_TM79
	.2byte ITEM_TM80
	.2byte ITEM_TM81
	.2byte ITEM_TM82
	.2byte ITEM_TM83
	.2byte ITEM_TM84
	.2byte ITEM_TM85
	.2byte ITEM_TM86
	.2byte ITEM_TM87
	.2byte ITEM_TM88
	.2byte ITEM_TM89
	.2byte ITEM_TM90
	.2byte ITEM_TM91
	.2byte ITEM_TM92
	.2byte ITEM_TM93
	.2byte ITEM_TM94
	.2byte ITEM_TM95
	.2byte ITEM_TM96
	.2byte ITEM_TM97
	.2byte ITEM_TM98
	.2byte ITEM_TM99
	.2byte ITEM_TM100
	.2byte ITEM_NONE
	release
	end

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to POKéMON…$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "There are so many different kinds of\n"
	.string "TM moves.\p"
	.string "A catalog I read said there are fifty\n"
	.string "different kinds.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "I'd like to get all the different TMs,\n"
	.string "but a POKéMON learns only four moves.$"

