# 1 "data/maps/MossdeepCity/scripts.pory"

# 2 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_1, 10
# 3 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_2, 11
# 4 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_3, 12
# 5 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_4, 13
# 6 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_MAXIE, 14
# 7 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_SCOTT, 16
# 8 "data/maps/MossdeepCity/scripts.pory"

# 9 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts::
# 10 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 11 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_OnResume
# 12 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 13 "data/maps/MossdeepCity/scripts.pory"

# 14 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 15 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 16 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 17 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 18 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 19 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 20 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_RAN_JIRACHI, MossdeepCity_EventScript_RanFromJirachi
# 21 "data/maps/MossdeepCity/scripts.pory"
	end
# 22 "data/maps/MossdeepCity/scripts.pory"

# 23 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnResume:
# 24 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MossdeepCity_EventScript_TryRemoveJirachi
# 25 "data/maps/MossdeepCity/scripts.pory"
	end
# 26 "data/maps/MossdeepCity/scripts.pory"

# 27 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TryRemoveJirachi:
# 28 "data/maps/MossdeepCity/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/MossdeepCity/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 30 "data/maps/MossdeepCity/scripts.pory"
	removeobject 18
# 31 "data/maps/MossdeepCity/scripts.pory"
    return
# 32 "data/maps/MossdeepCity/scripts.pory"

# 33 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_RanFromJirachi:
# 34 "data/maps/MossdeepCity/scripts.pory"
	clearflag(FLAG_WHITE_ROCK)
# 35 "data/maps/MossdeepCity/scripts.pory"
	clearflag(FLAG_RAN_JIRACHI)
# 36 "data/maps/MossdeepCity/scripts.pory"
    return
# 37 "data/maps/MossdeepCity/scripts.pory"

# 38 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 39 "data/maps/MossdeepCity/scripts.pory"
	lock
# 40 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 41 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 42 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 43 "data/maps/MossdeepCity/scripts.pory"
	release
# 44 "data/maps/MossdeepCity/scripts.pory"
	end
# 45 "data/maps/MossdeepCity/scripts.pory"

# 46 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 47 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 48 "data/maps/MossdeepCity/scripts.pory"
	release
# 49 "data/maps/MossdeepCity/scripts.pory"
	end
# 50 "data/maps/MossdeepCity/scripts.pory"

# 51 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 52 "data/maps/MossdeepCity/scripts.pory"
	lock
# 53 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 54 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 55 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 56 "data/maps/MossdeepCity/scripts.pory"
	release
# 57 "data/maps/MossdeepCity/scripts.pory"
	end
# 58 "data/maps/MossdeepCity/scripts.pory"

# 59 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 60 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 61 "data/maps/MossdeepCity/scripts.pory"
	release
# 62 "data/maps/MossdeepCity/scripts.pory"
	end
# 63 "data/maps/MossdeepCity/scripts.pory"

# 64 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 65 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 66 "data/maps/MossdeepCity/scripts.pory"
	end
# 67 "data/maps/MossdeepCity/scripts.pory"

# 68 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 69 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 70 "data/maps/MossdeepCity/scripts.pory"
	end
# 71 "data/maps/MossdeepCity/scripts.pory"

# 72 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 73 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 74 "data/maps/MossdeepCity/scripts.pory"
	end
# 75 "data/maps/MossdeepCity/scripts.pory"

# 76 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 77 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 78 "data/maps/MossdeepCity/scripts.pory"
	end
# 79 "data/maps/MossdeepCity/scripts.pory"

# 80 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 81 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 82 "data/maps/MossdeepCity/scripts.pory"
	end
# 83 "data/maps/MossdeepCity/scripts.pory"

# 84 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 85 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 86 "data/maps/MossdeepCity/scripts.pory"
	end
# 87 "data/maps/MossdeepCity/scripts.pory"

# 88 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 89 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 90 "data/maps/MossdeepCity/scripts.pory"
	end
# 91 "data/maps/MossdeepCity/scripts.pory"

# 92 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 93 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 94 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 95 "data/maps/MossdeepCity/scripts.pory"
	end
# 96 "data/maps/MossdeepCity/scripts.pory"

# 97 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 98 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 99 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 100 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 101 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 102 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 103 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 104 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 105 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 106 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 107 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 108 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 109 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 110 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 111 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 112 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MAXIE
# 113 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 114 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 115 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 116 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 117 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 118 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 119 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 120 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 121 "data/maps/MossdeepCity/scripts.pory"
	end
# 122 "data/maps/MossdeepCity/scripts.pory"

# 123 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 124 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 125 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 126 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 127 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 128 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 129 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 130 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 131 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 132 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 133 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 134 "data/maps/MossdeepCity/scripts.pory"

# 135 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 136 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 137 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 138 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 139 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 140 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 141 "data/maps/MossdeepCity/scripts.pory"

# 142 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 143 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 144 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 145 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 146 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 147 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 148 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 149 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 156 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 157 "data/maps/MossdeepCity/scripts.pory"

# 158 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 159 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 160 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 161 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 162 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 163 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 164 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 165 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 166 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 167 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 168 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 169 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 170 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 177 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 178 "data/maps/MossdeepCity/scripts.pory"

# 179 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 180 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 181 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 182 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 183 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 184 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 185 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 186 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 187 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 188 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 189 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 190 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 196 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 197 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 198 "data/maps/MossdeepCity/scripts.pory"

# 199 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 200 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 201 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 202 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 203 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 204 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 205 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 206 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 207 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 208 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 209 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 214 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 215 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 216 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 217 "data/maps/MossdeepCity/scripts.pory"

# 218 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 219 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 220 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 221 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 222 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 223 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 224 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 225 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 226 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 227 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 228 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 229 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 230 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 231 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 232 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 233 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 234 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 235 "data/maps/MossdeepCity/scripts.pory"

# 236 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 237 "data/maps/MossdeepCity/scripts.pory"
	lock
# 238 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 239 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 240 "data/maps/MossdeepCity/scripts.pory"
	braillemsgbox MossdeepCity_Braille_WishMaker
# 241 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 242 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 243 "data/maps/MossdeepCity/scripts.pory"
	release
# 244 "data/maps/MossdeepCity/scripts.pory"
	end
# 245 "data/maps/MossdeepCity/scripts.pory"

# 246 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 247 "data/maps/MossdeepCity/scripts.pory"
	lock
# 248 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 249 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 250 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 251 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 252 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 253 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 254 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 255 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 256 "data/maps/MossdeepCity/scripts.pory"
	release
# 257 "data/maps/MossdeepCity/scripts.pory"
	end
# 258 "data/maps/MossdeepCity/scripts.pory"

# 259 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 260 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 261 "data/maps/MossdeepCity/scripts.pory"
	release
# 262 "data/maps/MossdeepCity/scripts.pory"
	end
# 263 "data/maps/MossdeepCity/scripts.pory"

# 264 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 265 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 266 "data/maps/MossdeepCity/scripts.pory"
	release
# 267 "data/maps/MossdeepCity/scripts.pory"
	end
# 268 "data/maps/MossdeepCity/scripts.pory"

# 269 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 270 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 271 "data/maps/MossdeepCity/scripts.pory"
	end
# 272 "data/maps/MossdeepCity/scripts.pory"

# 273 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 274 "data/maps/MossdeepCity/scripts.pory"
	lock
# 275 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 276 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 277 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 278 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 279 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 280 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 281 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 282 "data/maps/MossdeepCity/scripts.pory"
	release
# 283 "data/maps/MossdeepCity/scripts.pory"
	end
# 284 "data/maps/MossdeepCity/scripts.pory"

# 285 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 286 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 287 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 288 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 289 "data/maps/MossdeepCity/scripts.pory"
	return
# 290 "data/maps/MossdeepCity/scripts.pory"

# 291 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 292 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 293 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
# 294 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 295 "data/maps/MossdeepCity/scripts.pory"
	return
# 296 "data/maps/MossdeepCity/scripts.pory"

# 297 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 298 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 299 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 300 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 301 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 302 "data/maps/MossdeepCity/scripts.pory"

# 303 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
# 304 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 305 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 306 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 307 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 308 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 309 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 310 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 311 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 312 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 313 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 314 "data/maps/MossdeepCity/scripts.pory"

# 315 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 316 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 317 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 318 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 319 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 320 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 321 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 322 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 323 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 324 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 325 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 326 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 327 "data/maps/MossdeepCity/scripts.pory"

# 328 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 329 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from STEVEN, but I don't\n"
# 330 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called KING'S ROCK.\n"
# 332 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 333 "data/maps/MossdeepCity/scripts.pory"

# 334 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 335 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 336 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "from STEVEN.$"
# 339 "data/maps/MossdeepCity/scripts.pory"

# 340 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 341 "data/maps/MossdeepCity/scripts.pory"
	.string "STEVEN's house is right over there!$"
# 342 "data/maps/MossdeepCity/scripts.pory"

# 343 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 344 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 345 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 346 "data/maps/MossdeepCity/scripts.pory"

# 347 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 348 "data/maps/MossdeepCity/scripts.pory"
	.string "Around MOSSDEEP, you can see wild\n"
# 349 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER.\p"
# 350 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 351 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 352 "data/maps/MossdeepCity/scripts.pory"
	.string "WAI, WAI, WAI…\p"
# 353 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER watching!$"
# 354 "data/maps/MossdeepCity/scripts.pory"

# 355 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 359 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 360 "data/maps/MossdeepCity/scripts.pory"

# 361 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 362 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 363 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 364 "data/maps/MossdeepCity/scripts.pory"

# 365 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 366 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a SAILOR buddy that\n"
# 367 "data/maps/MossdeepCity/scripts.pory"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
# 368 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "But MOSSDEEP here's been targeted\n"
# 371 "data/maps/MossdeepCity/scripts.pory"
	.string "by that TEAM MAGMA.\p"
# 372 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 373 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the SPACE CENTER.$"
# 374 "data/maps/MossdeepCity/scripts.pory"

# 375 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 376 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a SAILOR, so the sea's obviously\n"
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 380 "data/maps/MossdeepCity/scripts.pory"

# 381 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 382 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 383 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 385 "data/maps/MossdeepCity/scripts.pory"

# 386 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 387 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 388 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 389 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 390 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 391 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 392 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 393 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 394 "data/maps/MossdeepCity/scripts.pory"

# 395 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "Near the coast I found this rock\n"
# 397 "data/maps/MossdeepCity/scripts.pory"
	.string "fragment, which has some strange\p"
# 398 "data/maps/MossdeepCity/scripts.pory"
	.string "symbols engraved on it.$"
# 399 "data/maps/MossdeepCity/scripts.pory"

# 400 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 401 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 402 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the SPACE CENTER.\p"
# 403 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 404 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 405 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 406 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 407 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 409 "data/maps/MossdeepCity/scripts.pory"

# 410 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 411 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 412 "data/maps/MossdeepCity/scripts.pory"

# 413 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 414 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\n"
# 415 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADERS: LIZA & TATE\p"
# 416 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 417 "data/maps/MossdeepCity/scripts.pory"

# 418 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 419 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY\n"
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish POKéMON!”$"
# 421 "data/maps/MossdeepCity/scripts.pory"

# 422 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP SPACE CENTER\n"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 425 "data/maps/MossdeepCity/scripts.pory"

# 426 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 427 "data/maps/MossdeepCity/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
# 428 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 429 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
# 430 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 431 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 432 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 433 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 434 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the SPACE CENTER…\p"
# 436 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 437 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 438 "data/maps/MossdeepCity/scripts.pory"

# 439 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 440 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 441 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 442 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 443 "data/maps/MossdeepCity/scripts.pory"
	.string "island city SOOTOPOLIS?\p"
# 444 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the GYM there had a new\n"
# 445 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADER come in.\p"
# 446 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new LEADER once\n"
# 447 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored WALLACE.$"

MossdeepCity_EventScript_WhiteRock::
# 453 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 454 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_WhiteRock_Text_0
# 455 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_WHITE_ROCK, MossdeepCity_EventScript_WhiteRock_2
# 459 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_WhiteRock_Text_1, MSGBOX_YESNO
# 460 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_EventScript_WhiteRock_4
# 512 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	return

MossdeepCity_EventScript_WhiteRock_2:
# 456 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

MossdeepCity_EventScript_WhiteRock_4:
# 461 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_WHITE_ROCK
# 462 "data/maps/MossdeepCity/scripts.pory"
	call Common_ShowEasyChatScreen
# 463 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_EventScript_WhiteRock_7
# 509 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	return

MossdeepCity_EventScript_WhiteRock_7:
# 464 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_0x8004, 3
	goto_if_eq MossdeepCity_EventScript_WhiteRock_10
# 505 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_WhiteRock_Text_2
# 506 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	return

MossdeepCity_EventScript_WhiteRock_10:
# 465 "data/maps/MossdeepCity/scripts.pory"
	applymovement 18, Movement_KecleonAppears
# 466 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 467 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, WhiteRock_PlayerMovement
# 468 "data/maps/MossdeepCity/scripts.pory"
	playse SE_PIN
# 469 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 470 "data/maps/MossdeepCity/scripts.pory"
	delay 60
# 471 "data/maps/MossdeepCity/scripts.pory"
	applymovement 18, WhiteRock_JirachiMovement
# 472 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 473 "data/maps/MossdeepCity/scripts.pory"
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
# 474 "data/maps/MossdeepCity/scripts.pory"
	waitmoncry
# 475 "data/maps/MossdeepCity/scripts.pory"
	setwildbattle SPECIES_JIRACHI, 30
# 476 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 477 "data/maps/MossdeepCity/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 478 "data/maps/MossdeepCity/scripts.pory"
	waitstate
# 479 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 480 "data/maps/MossdeepCity/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 481 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MossdeepCity_EventScript_WhiteRock_14
# 484 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MossdeepCity_EventScript_WhiteRock_15
# 494 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RAN_JIRACHI
# 495 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_JIRACHI
# 496 "data/maps/MossdeepCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 497 "data/maps/MossdeepCity/scripts.pory"
	removeobject 18
# 498 "data/maps/MossdeepCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 499 "data/maps/MossdeepCity/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 500 "data/maps/MossdeepCity/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
MossdeepCity_EventScript_WhiteRock_13:
# 502 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_WHITE_ROCK
# 503 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	return

MossdeepCity_EventScript_WhiteRock_14:
# 482 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_RAN_JIRACHI
	goto MossdeepCity_EventScript_WhiteRock_13

MossdeepCity_EventScript_WhiteRock_15:
# 485 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_RAN_JIRACHI
# 486 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_JIRACHI
# 487 "data/maps/MossdeepCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 488 "data/maps/MossdeepCity/scripts.pory"
	removeobject 18
# 489 "data/maps/MossdeepCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 490 "data/maps/MossdeepCity/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 491 "data/maps/MossdeepCity/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	goto MossdeepCity_EventScript_WhiteRock_13


# 516 "data/maps/MossdeepCity/scripts.pory"
WhiteRock_PlayerMovement:
# 517 "data/maps/MossdeepCity/scripts.pory"
	emote_exclamation_mark
	step_end

# 520 "data/maps/MossdeepCity/scripts.pory"
WhiteRock_JirachiMovement:
# 521 "data/maps/MossdeepCity/scripts.pory"
	walk_down
	step_end

MossdeepCity_EventScript_WhiteRock_Text_0:
# 454 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"

MossdeepCity_EventScript_WhiteRock_Text_1:
# 459 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want to make a wish?$"

MossdeepCity_EventScript_WhiteRock_Text_2:
# 505 "data/maps/MossdeepCity/scripts.pory"
	.string "You made a wish.$"
