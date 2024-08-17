# 1 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 2 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ProfCozmo::
# 3 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 4 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 5 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
# 6 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	checkitem ITEM_METEORITE
# 7 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
# 8 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 9 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 10 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 11 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 12 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
# 13 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
# 14 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
# 15 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
# 16 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
# 17 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_TM_RETURN
# 18 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 19 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setvar VAR_0x8004, ITEM_METEORITE
# 20 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 21 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM_RETURN
# 22 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 23 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 24 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 25 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 26 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
# 27 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 28 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
# 29 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 30 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 31 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
# 32 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
# 33 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 34 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 35 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
# 36 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 37 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
# 38 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 39 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 40 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 41 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
# 42 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_GIVE_AURORA_TICKET, FallarborTown_CozmosHouse_EventScript_GiveAuroraTicket
# 43 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 44 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 45 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 46 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 47 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GiveAuroraTicket::
# 48 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, FallarborTown_CozmosHouse_EventScript_GaveAuroraTicket
# 49 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_GiveAuroraTicket, MSGBOX_DEFAULT
# 50 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 51 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 52 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 53 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_GaveAuroraTicket, MSGBOX_DEFAULT
# 54 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 55 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 56 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 57 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GaveAuroraTicket::
# 58 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_GaveAuroraTicket, MSGBOX_DEFAULT
# 59 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 60 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 61 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 62 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmosWife::
# 63 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 64 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 65 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
# 66 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
# 67 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
# 68 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 69 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 70 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 71 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
# 72 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
# 73 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 74 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 75 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 76 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
# 77 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
# 78 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 79 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 80 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 81 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
# 82 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh…\n"
# 83 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I never should have let myself be\l"
# 84 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "conned into telling TEAM MAGMA where\l"
# 85 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "you can find METEORITES…\p"
# 86 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That METEORITE from METEOR FALLS…\n"
# 87 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "It's never going to be mine now…$"
# 88 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 89 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
# 90 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Oh!\n"
# 91 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Hah?\p"
# 92 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That item…\p"
# 93 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Could it be?\p"
# 94 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Is it the METEORITE that TEAM MAGMA\n"
# 95 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "took from METEOR FALLS?\p"
# 96 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please, may I have it?\p"
# 97 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 98 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 99 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 100 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
# 101 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: This TM, it represents\n"
# 102 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "my feeling of gratitude.\l"
# 103 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please use it!$"
# 104 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 105 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
# 106 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, I can't believe it.\n"
# 107 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really, really great!\p"
# 108 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really going to help my research!$"
# 109 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 110 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
# 111 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, but…\n"
# 112 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm crushed with disappointment…$"
# 113 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 114 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
# 115 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Please, may I have that\n"
# 116 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "METEORITE?\p"
# 117 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 118 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 119 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 120 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
# 121 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO went off to METEOR FALLS\n"
# 122 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "on ROUTE 114 with some people from\l"
# 123 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "TEAM MAGMA.$"
# 124 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 125 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
# 126 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Poor PROF. COZMO…\n"
# 127 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so depressed… I feel sorry for him.$"
# 128 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 129 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
# 130 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Look at PROF. COZMO…\n"
# 131 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so happy! I think it's cute.$"
# 132 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 133 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_GiveAuroraTicket:
# 134 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Hey, it's you! You'll be happy to know\n"
# 135 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "that I've made a great discovery about\p"
# 136 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "the METEORITE you gave me. It seems to\n"
# 137 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "contain remnants of what appears to be\p"
# 138 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "a space virus that emits waves very\n" 
# 139 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "similar to those of the meteorite that\p"
# 140 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "fell some time ago on BIRTH ISLAND.\n"
# 141 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Would you mind taking a look at it?$"
# 142 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 143 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_GaveAuroraTicket:
# 144 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: I hope all our efforts have\n"
# 145 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "not been in vain!$"

FallarborTown_CozmosHouse_MapScripts::
# 149 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_CozmosHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

FallarborTown_CozmosHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 150 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

FallarborTown_CozmosHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 151 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_GIVE_AURORA_TICKET
	return

FallarborTown_CozmosHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 150 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, FallarborTown_CozmosHouse_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

