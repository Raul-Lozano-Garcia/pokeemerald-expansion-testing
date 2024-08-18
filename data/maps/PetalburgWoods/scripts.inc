# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"

# 5 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 6 "data/maps/PetalburgWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
# 7 "data/maps/PetalburgWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PetalburgWoods_OnResume
# 8 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 9 "data/maps/PetalburgWoods/scripts.pory"

# 10 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_OnTransition:
# 11 "data/maps/PetalburgWoods/scripts.pory"
	call_if_set FLAG_RAN_CELEBI, PetalburgWoods_EventScript_RanFromCelebi
# 12 "data/maps/PetalburgWoods/scripts.pory"
	end
# 13 "data/maps/PetalburgWoods/scripts.pory"

# 14 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_OnResume:
# 15 "data/maps/PetalburgWoods/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PetalburgWoods_EventScript_TryRemoveCelebi
# 16 "data/maps/PetalburgWoods/scripts.pory"
	end
# 17 "data/maps/PetalburgWoods/scripts.pory"

# 18 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RanFromCelebi:
# 19 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_GS_BALL
# 20 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_RAN_CELEBI
# 21 "data/maps/PetalburgWoods/scripts.pory"
    return
# 22 "data/maps/PetalburgWoods/scripts.pory"

# 23 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRemoveCelebi:
# 24 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 25 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 26 "data/maps/PetalburgWoods/scripts.pory"
	removeobject 14
# 27 "data/maps/PetalburgWoods/scripts.pory"
    return
# 28 "data/maps/PetalburgWoods/scripts.pory"

# 29 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 30 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 31 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 32 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 33 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 34 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 35 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 36 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 37 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 38 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 39 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 40 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 41 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 42 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 43 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 44 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 45 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 46 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 47 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 48 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 49 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 50 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 51 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 52 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 53 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 54 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 55 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 56 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 57 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 58 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 59 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 60 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 61 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 62 "data/maps/PetalburgWoods/scripts.pory"
	end
# 63 "data/maps/PetalburgWoods/scripts.pory"

# 64 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 65 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 66 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 67 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 68 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 69 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 70 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 71 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 72 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 73 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 74 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 75 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 76 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 77 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 78 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 79 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 80 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 81 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 82 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 83 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 84 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 85 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 86 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 87 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 88 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 89 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 90 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 91 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 92 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 93 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 94 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 95 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 96 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 97 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 98 "data/maps/PetalburgWoods/scripts.pory"
	end
# 99 "data/maps/PetalburgWoods/scripts.pory"

# 100 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 101 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 102 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 103 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 104 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 105 "data/maps/PetalburgWoods/scripts.pory"
	return
# 106 "data/maps/PetalburgWoods/scripts.pory"

# 107 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 108 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 109 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 110 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 111 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 112 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 113 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 114 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 115 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 116 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 117 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 118 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 119 "data/maps/PetalburgWoods/scripts.pory"
	end
# 120 "data/maps/PetalburgWoods/scripts.pory"

# 121 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 122 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 123 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 124 "data/maps/PetalburgWoods/scripts.pory"
	end
# 125 "data/maps/PetalburgWoods/scripts.pory"

# 126 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 127 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 128 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 129 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 130 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 131 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 132 "data/maps/PetalburgWoods/scripts.pory"
	return
# 133 "data/maps/PetalburgWoods/scripts.pory"

# 134 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 135 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 136 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 137 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 138 "data/maps/PetalburgWoods/scripts.pory"
	end
# 139 "data/maps/PetalburgWoods/scripts.pory"

# 140 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 141 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 142 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 143 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 144 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 145 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 146 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 147 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 148 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 149 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 150 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 151 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 152 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 153 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 154 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 155 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 156 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 157 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 158 "data/maps/PetalburgWoods/scripts.pory"

# 159 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 160 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 161 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 162 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 164 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 165 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 166 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 167 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 168 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 169 "data/maps/PetalburgWoods/scripts.pory"

# 170 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 171 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 172 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 173 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 174 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 175 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 176 "data/maps/PetalburgWoods/scripts.pory"

# 177 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 178 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 179 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 180 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 181 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 182 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 183 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 184 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 185 "data/maps/PetalburgWoods/scripts.pory"

# 186 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 187 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 188 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 189 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 190 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 191 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 192 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 193 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 195 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 196 "data/maps/PetalburgWoods/scripts.pory"

# 197 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 198 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 199 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 201 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 202 "data/maps/PetalburgWoods/scripts.pory"

# 203 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 204 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 205 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 206 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 207 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 208 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 209 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 210 "data/maps/PetalburgWoods/scripts.pory"

# 211 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 212 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 213 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 214 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 215 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 216 "data/maps/PetalburgWoods/scripts.pory"

# 217 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 218 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 219 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 220 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 221 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 222 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 223 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 224 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 225 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 226 "data/maps/PetalburgWoods/scripts.pory"

# 227 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 228 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 229 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 230 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 231 "data/maps/PetalburgWoods/scripts.pory"

# 232 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 233 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 234 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 235 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 236 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 237 "data/maps/PetalburgWoods/scripts.pory"

# 238 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 240 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 241 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 242 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 244 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 245 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 246 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 247 "data/maps/PetalburgWoods/scripts.pory"

# 248 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 249 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 250 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 251 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 252 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 253 "data/maps/PetalburgWoods/scripts.pory"

# 254 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 255 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 256 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 257 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 258 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 259 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 260 "data/maps/PetalburgWoods/scripts.pory"

# 261 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 262 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 263 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 264 "data/maps/PetalburgWoods/scripts.pory"

# 265 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 266 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 267 "data/maps/PetalburgWoods/scripts.pory"
	end
# 268 "data/maps/PetalburgWoods/scripts.pory"

# 269 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 270 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 271 "data/maps/PetalburgWoods/scripts.pory"
	end
# 272 "data/maps/PetalburgWoods/scripts.pory"

# 273 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 274 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 275 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 276 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 277 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 278 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 279 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 280 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 281 "data/maps/PetalburgWoods/scripts.pory"
	release
# 282 "data/maps/PetalburgWoods/scripts.pory"
	end
# 283 "data/maps/PetalburgWoods/scripts.pory"

# 284 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 285 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 286 "data/maps/PetalburgWoods/scripts.pory"
	release
# 287 "data/maps/PetalburgWoods/scripts.pory"
	end
# 288 "data/maps/PetalburgWoods/scripts.pory"

# 289 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 290 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 291 "data/maps/PetalburgWoods/scripts.pory"
	end
# 292 "data/maps/PetalburgWoods/scripts.pory"

# 293 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 294 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 295 "data/maps/PetalburgWoods/scripts.pory"
	end
# 296 "data/maps/PetalburgWoods/scripts.pory"

# 297 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 298 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 299 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 300 "data/maps/PetalburgWoods/scripts.pory"
	end
# 301 "data/maps/PetalburgWoods/scripts.pory"

# 302 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 303 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 304 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 305 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 306 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 307 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 308 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 309 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 310 "data/maps/PetalburgWoods/scripts.pory"
	release
# 311 "data/maps/PetalburgWoods/scripts.pory"
	end
# 312 "data/maps/PetalburgWoods/scripts.pory"

# 313 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 314 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 315 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 316 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 317 "data/maps/PetalburgWoods/scripts.pory"
	release
# 318 "data/maps/PetalburgWoods/scripts.pory"
	end
# 319 "data/maps/PetalburgWoods/scripts.pory"

# 320 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 321 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 322 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 323 "data/maps/PetalburgWoods/scripts.pory"
	release
# 324 "data/maps/PetalburgWoods/scripts.pory"
	end
# 325 "data/maps/PetalburgWoods/scripts.pory"

# 326 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 327 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 328 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 329 "data/maps/PetalburgWoods/scripts.pory"
	release
# 330 "data/maps/PetalburgWoods/scripts.pory"
	end
# 331 "data/maps/PetalburgWoods/scripts.pory"

# 332 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 333 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 334 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 335 "data/maps/PetalburgWoods/scripts.pory"
	release
# 336 "data/maps/PetalburgWoods/scripts.pory"
	end
# 337 "data/maps/PetalburgWoods/scripts.pory"

# 338 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 339 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 340 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 341 "data/maps/PetalburgWoods/scripts.pory"
	end
# 342 "data/maps/PetalburgWoods/scripts.pory"

# 343 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 344 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 345 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 346 "data/maps/PetalburgWoods/scripts.pory"

# 347 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 348 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 349 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 350 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 351 "data/maps/PetalburgWoods/scripts.pory"

# 352 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 353 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 355 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 356 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 357 "data/maps/PetalburgWoods/scripts.pory"

# 358 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 359 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 361 "data/maps/PetalburgWoods/scripts.pory"

# 362 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 363 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 366 "data/maps/PetalburgWoods/scripts.pory"

# 367 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 369 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 370 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 373 "data/maps/PetalburgWoods/scripts.pory"

# 374 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 375 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 376 "data/maps/PetalburgWoods/scripts.pory"

# 377 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 378 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 379 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 380 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 382 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 383 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 384 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 385 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 386 "data/maps/PetalburgWoods/scripts.pory"

# 387 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 388 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 389 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 390 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 391 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 392 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 393 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 394 "data/maps/PetalburgWoods/scripts.pory"

# 395 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 396 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 397 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 398 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 399 "data/maps/PetalburgWoods/scripts.pory"

# 400 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 401 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 402 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 403 "data/maps/PetalburgWoods/scripts.pory"

# 404 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 405 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 406 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 407 "data/maps/PetalburgWoods/scripts.pory"

# 408 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 409 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 410 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 411 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 412 "data/maps/PetalburgWoods/scripts.pory"

# 413 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 414 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 415 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 416 "data/maps/PetalburgWoods/scripts.pory"

# 417 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 418 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 420 "data/maps/PetalburgWoods/scripts.pory"

# 421 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 422 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 424 "data/maps/PetalburgWoods/scripts.pory"

# 425 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 426 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 427 "data/maps/PetalburgWoods/scripts.pory"

# 428 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 429 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 430 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 431 "data/maps/PetalburgWoods/scripts.pory"

# 432 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 433 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 435 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 436 "data/maps/PetalburgWoods/scripts.pory"

# 437 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 441 "data/maps/PetalburgWoods/scripts.pory"

# 442 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 443 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 445 "data/maps/PetalburgWoods/scripts.pory"

# 446 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 448 "data/maps/PetalburgWoods/scripts.pory"

# 449 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 451 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 452 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 453 "data/maps/PetalburgWoods/scripts.pory"

# 454 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 455 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 456 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 460 "data/maps/PetalburgWoods/scripts.pory"

# 461 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 462 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 466 "data/maps/PetalburgWoods/scripts.pory"

# 467 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 469 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 470 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 472 "data/maps/PetalburgWoods/scripts.pory"

# 473 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 474 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 478 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 479 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 480 "data/maps/PetalburgWoods/scripts.pory"

# 481 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 482 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 483 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 484 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 485 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 486 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 487 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 488 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 489 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 490 "data/maps/PetalburgWoods/scripts.pory"

# 491 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 492 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 493 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 494 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 495 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 496 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 497 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

PetalburgWoods_EventScript_Celebi::
# 501 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 502 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Celebi_Text_0
# 504 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_unset FLAG_RECEIVED_GS_BALL, PetalburgWoods_EventScript_Celebi_2
# 508 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Celebi_Text_1, MSGBOX_YESNO
# 510 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PetalburgWoods_EventScript_Celebi_4
# 558 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	return

PetalburgWoods_EventScript_Celebi_2:
# 505 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

PetalburgWoods_EventScript_Celebi_4:
# 511 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_Celebi_Text_2
# 512 "data/maps/PetalburgWoods/scripts.pory"
	release
# 513 "data/maps/PetalburgWoods/scripts.pory"
	showobjectat 15, MAP_PETALBURG_WOODS
# 514 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_BALL
# 515 "data/maps/PetalburgWoods/scripts.pory"
	delay 60
# 516 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 517 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_MUGSHOT
# 518 "data/maps/PetalburgWoods/scripts.pory"
	delay 150
# 519 "data/maps/PetalburgWoods/scripts.pory"
	showobjectat 14, MAP_PETALBURG_WOODS
# 520 "data/maps/PetalburgWoods/scripts.pory"
	hideobjectat 15, MAP_PETALBURG_WOODS
# 521 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 522 "data/maps/PetalburgWoods/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Celebi_PlayerMovement
# 523 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_PIN
# 524 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 525 "data/maps/PetalburgWoods/scripts.pory"
	delay 60
# 526 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 527 "data/maps/PetalburgWoods/scripts.pory"
	waitmoncry
# 528 "data/maps/PetalburgWoods/scripts.pory"
	setwildbattle SPECIES_CELEBI, 30
# 529 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 530 "data/maps/PetalburgWoods/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 531 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 532 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 533 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 534 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PetalburgWoods_EventScript_Celebi_8
# 537 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PetalburgWoods_EventScript_Celebi_9
# 547 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RAN_CELEBI
# 548 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_RECEIVED_GS_BALL
# 549 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, SPECIES_CELEBI
# 550 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 551 "data/maps/PetalburgWoods/scripts.pory"
	removeobject 14
# 552 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 553 "data/maps/PetalburgWoods/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 554 "data/maps/PetalburgWoods/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
PetalburgWoods_EventScript_Celebi_7:
# 556 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	return

PetalburgWoods_EventScript_Celebi_8:
# 535 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_RECEIVED_GS_BALL
	goto PetalburgWoods_EventScript_Celebi_7

PetalburgWoods_EventScript_Celebi_9:
# 538 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_RECEIVED_GS_BALL
# 539 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, SPECIES_CELEBI
# 540 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 541 "data/maps/PetalburgWoods/scripts.pory"
	removeobject 14
# 542 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 543 "data/maps/PetalburgWoods/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 544 "data/maps/PetalburgWoods/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_Celebi_7


# 562 "data/maps/PetalburgWoods/scripts.pory"
Celebi_PlayerMovement:
# 563 "data/maps/PetalburgWoods/scripts.pory"
	emote_exclamation_mark
	step_end

PetalburgWoods_EventScript_Celebi_Text_0:
# 502 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's an altar in honor of\n"
	.string "someone. It has a hole.$"

PetalburgWoods_EventScript_Celebi_Text_1:
# 508 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's look like the GS BALL would fit on\n"
	.string "it. Want to put the GS BALL here?$"

PetalburgWoods_EventScript_Celebi_Text_2:
# 511 "data/maps/PetalburgWoods/scripts.pory"
	.string "{PLAYER} put in the GS BALL.$"
