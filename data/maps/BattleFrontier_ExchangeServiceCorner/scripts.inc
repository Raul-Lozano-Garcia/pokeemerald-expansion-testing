# 1 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 2 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_MapScripts::
# 3 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 5 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
# 6 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
# 7 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowBattlePointsWindow
# 8 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	return
# 9 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 10 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
# 11 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
# 12 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 13 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 14 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 16 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
# 17 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 18 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
# 19 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
# 20 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 21 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 22 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 23 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 24 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 25 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 26 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
# 27 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
# 28 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
# 29 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
# 30 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 32 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
# 33 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	checkdecorspace VAR_0x8009
# 34 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
# 35 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 36 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special TakeFrontierBattlePoints
# 37 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	adddecoration VAR_0x8009
# 38 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special UpdateBattlePointsWindow
# 39 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	playse SE_SHOP
# 40 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
# 41 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 42 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 43 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 45 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
# 46 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
# 47 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 48 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 49 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 50 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 51 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
# 52 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	checkitemspace VAR_0x8009
# 53 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
# 54 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 55 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special TakeFrontierBattlePoints
# 56 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	additem VAR_0x8009
# 57 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special UpdateBattlePointsWindow
# 58 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	playse SE_SHOP
# 59 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
# 60 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 61 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 62 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 63 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 64 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
# 65 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
# 66 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 67 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 68 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 69 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 70 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
# 71 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 72 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 73 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
# 74 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 75 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 76 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 77 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 78 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
# 79 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
# 80 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 81 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 82 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 83 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 84 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 85 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
# 86 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
# 87 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
# 88 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
# 89 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
# 90 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
# 91 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
# 92 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
# 93 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
# 94 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
# 95 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 96 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 97 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 99 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
# 100 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
# 101 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 102 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 103 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_KISS_POSTER
# 104 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 105 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 106 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 107 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
# 108 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
# 109 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 110 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 111 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_KISS_CUSHION
# 112 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 113 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 114 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 115 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
# 116 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
# 117 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 118 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 119 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
# 120 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 121 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 122 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 123 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
# 124 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
# 125 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 126 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 127 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
# 128 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 129 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 130 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 131 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
# 132 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
# 133 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 134 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 135 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
# 136 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 137 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 138 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 139 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
# 140 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
# 141 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 142 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 143 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
# 144 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 145 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 146 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 147 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
# 148 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
# 149 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 150 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 151 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_DITTO_DOLL
# 152 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 153 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 154 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 155 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
# 156 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
# 157 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 158 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 159 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
# 160 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 161 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 162 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 163 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
# 164 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
# 165 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 166 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 167 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
# 168 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 169 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 170 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 171 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
# 172 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
# 173 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 174 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 175 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
# 176 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 177 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 178 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 179 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
# 180 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 181 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 182 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
# 183 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 184 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 185 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 186 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 187 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
# 188 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
# 189 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 190 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 191 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 192 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 193 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 194 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
# 195 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
# 196 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
# 197 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
# 198 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
# 199 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 200 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 201 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 202 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 203 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
# 204 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
# 205 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 206 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 207 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
# 208 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 209 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 210 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 211 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
# 212 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
# 213 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 214 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 215 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
# 216 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 217 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 218 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 219 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
# 220 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
# 221 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 222 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 223 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
# 224 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 225 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 226 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 227 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
# 228 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
# 229 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 230 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 231 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
# 232 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 233 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 234 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 235 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
# 236 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
# 237 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 238 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 239 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
# 240 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 241 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 242 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 243 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
# 244 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 245 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 246 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
# 247 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 248 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 249 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 250 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 251 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
# 252 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
# 253 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 254 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 255 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 256 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 257 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_AbilityCapsule
# 259 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_BottleCap
# 260 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_GoldBottleCap
# 261 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_HealthMochi
# 262 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MuscleMochi
# 263 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ResistMochi
# 264 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_GeniusMochi
# 265 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CleverMochi
# 266 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_SwiftMochi
# 267 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_FreshStartMochi
# 268 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_LonelyMint
# 269 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_AdamantMint
# 270 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_NaughtyMint
# 271 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_BraveMint
# 272 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_BoldMint
# 273 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_ImpishMint
# 274 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_LaxMint
# 275 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_RelaxedMint
# 276 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_ModestMint
# 277 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_MildMint
# 278 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_RashMint
# 279 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_QuietMint
# 280 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_CalmMint
# 281 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_GentleMint
# 282 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_CarefulMint
# 283 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_SassyMint
# 284 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_TimidMint
# 285 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_HastyMint
# 286 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_JollyMint
# 287 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_NaiveMint
# 288 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_SeriousMint
# 289 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 290 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 291 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 292 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 293 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_HealthMochi::
# 294 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHealthMochi, MSGBOX_YESNO
# 295 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 296 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 297 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_HEALTH_MOCHI
# 298 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 299 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 300 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 301 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MuscleMochi::
# 302 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMuscleMochi, MSGBOX_YESNO
# 303 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 304 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 305 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_MUSCLE_MOCHI
# 306 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 307 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 308 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 309 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ResistMochi::
# 310 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmResistMochi, MSGBOX_YESNO
# 311 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 312 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 313 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_RESIST_MOCHI
# 314 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 315 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 316 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 317 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_GeniusMochi::
# 318 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmGeniusMochi, MSGBOX_YESNO
# 319 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 320 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 321 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_GENIUS_MOCHI
# 322 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 323 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 324 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 325 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CleverMochi::
# 326 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCleverMochi, MSGBOX_YESNO
# 327 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 328 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 329 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CLEVER_MOCHI
# 330 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 331 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 332 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 333 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SwiftMochi::
# 334 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSwiftMochi, MSGBOX_YESNO
# 335 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 336 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 337 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_SWIFT_MOCHI
# 338 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 339 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 340 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 341 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_FreshStartMochi::
# 342 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFreshStartMochi, MSGBOX_YESNO
# 343 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 344 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 345 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_FRESH_START_MOCHI
# 346 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 347 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 348 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 349 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BottleCap::
# 350 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBottleCap, MSGBOX_YESNO
# 351 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 352 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 5
# 353 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_BOTTLE_CAP
# 354 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 355 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 356 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 357 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_GoldBottleCap::
# 358 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmGoldBottleCap, MSGBOX_YESNO
# 359 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 360 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 15
# 361 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_GOLD_BOTTLE_CAP
# 362 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 363 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 364 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 365 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_AbilityCapsule::
# 366 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityCapsule, MSGBOX_YESNO
# 367 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 368 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 369 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_ABILITY_CAPSULE
# 370 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 371 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 372 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 373 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_LonelyMint::
# 374 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLonelyMint, MSGBOX_YESNO
# 375 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 376 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 377 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_LONELY_MINT
# 378 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 379 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 380 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 381 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_AdamantMint::
# 382 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAdamantMint, MSGBOX_YESNO
# 383 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 384 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 385 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_ADAMANT_MINT
# 386 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 387 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 388 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 389 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_NaughtyMint::
# 390 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaughtyMint, MSGBOX_YESNO
# 391 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 392 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 393 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_NAUGHTY_MINT
# 394 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 395 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 396 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 397 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BraveMint::
# 398 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBraveMint, MSGBOX_YESNO
# 399 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 400 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 401 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_BRAVE_MINT
# 402 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 403 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 404 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 405 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BoldMint::
# 406 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBoldMint, MSGBOX_YESNO
# 407 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 408 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 409 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_BOLD_MINT
# 410 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 411 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 412 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 413 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ImpishMint::
# 414 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmImpishMint, MSGBOX_YESNO
# 415 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 416 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 417 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_IMPISH_MINT
# 418 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 419 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 420 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 421 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_LaxMint::
# 422 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxMint, MSGBOX_YESNO
# 423 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 424 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 425 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_LAX_MINT
# 426 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 427 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 428 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 429 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_RelaxedMint::
# 430 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRelaxedMint, MSGBOX_YESNO
# 431 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 432 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 433 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_RELAXED_MINT
# 434 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 435 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 436 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 437 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ModestMint::
# 438 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmModestMint, MSGBOX_YESNO
# 439 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 440 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 441 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_MODEST_MINT
# 442 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 443 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 444 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 445 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MildMint::
# 446 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMildMint, MSGBOX_YESNO
# 447 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 448 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 449 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_MILD_MINT
# 450 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 451 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 452 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 453 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_RashMint::
# 454 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRashMint, MSGBOX_YESNO
# 455 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 456 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 457 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_RASH_MINT
# 458 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 459 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 460 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 461 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_QuietMint::
# 462 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuietMint, MSGBOX_YESNO
# 463 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 464 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 465 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_QUIET_MINT
# 466 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 467 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 468 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 469 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CalmMint::
# 470 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalmMint, MSGBOX_YESNO
# 471 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 472 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 473 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CALM_MINT
# 474 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 475 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 476 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 477 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_GentleMint::
# 478 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmGentleMint, MSGBOX_YESNO
# 479 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 480 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 481 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_GENTLE_MINT
# 482 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 483 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 484 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 485 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CarefulMint::
# 486 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarefulMint, MSGBOX_YESNO
# 487 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 488 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 489 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CAREFUL_MINT
# 490 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 491 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 492 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 493 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SassyMint::
# 494 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSassyMint, MSGBOX_YESNO
# 495 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 496 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 497 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_SASSY_MINT
# 498 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 499 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 500 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 501 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TimidMint::
# 502 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTimidMint, MSGBOX_YESNO
# 503 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 504 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 505 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_TIMID_MINT
# 506 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 507 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 508 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 509 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_HastyMint::
# 510 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHastyMint, MSGBOX_YESNO
# 511 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 512 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 513 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_HASTY_MINT
# 514 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 515 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 516 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 517 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_JollyMint::
# 518 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmJollyMint, MSGBOX_YESNO
# 519 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 520 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 521 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_JOLLY_MINT
# 522 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 523 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 524 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 525 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_NaiveMint::
# 526 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaiveMint, MSGBOX_YESNO
# 527 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 528 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 529 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_NAIVE_MINT
# 530 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 531 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 532 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 533 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SeriousMint::
# 534 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeriousMint, MSGBOX_YESNO
# 535 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 536 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 537 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_SERIOUS_MINT
# 538 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 539 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 540 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 541 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
# 542 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 543 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 544 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
# 545 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 546 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 547 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 548 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 549 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
# 550 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
# 551 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 552 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 553 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 554 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 555 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 556 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
# 557 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
# 558 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
# 559 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
# 560 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
# 561 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
# 562 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs
# 563 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
# 564 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
# 565 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
# 566 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_DestinyKnot
# 567 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_MirrorHerb
# 568 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 569 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 570 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 571 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 572 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
# 573 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
# 574 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 575 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 576 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_LEFTOVERS
# 577 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 578 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 579 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 580 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
# 581 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
# 582 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 583 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 584 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_WHITE_HERB
# 585 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 586 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 587 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 588 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
# 589 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
# 590 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 591 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 592 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_QUICK_CLAW
# 593 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 594 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 595 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 596 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
# 597 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
# 598 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 599 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 600 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_MENTAL_HERB
# 601 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 602 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 603 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 604 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
# 605 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
# 606 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 607 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 608 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
# 609 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 610 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 611 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 612 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
# 613 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
# 614 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 615 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 616 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CHOICE_BAND
# 617 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 618 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 619 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 620 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs::
# 621 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceSpecs, MSGBOX_YESNO
# 622 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 623 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 624 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CHOICE_SPECS
# 625 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 626 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 627 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 628 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
# 629 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
# 630 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 631 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 632 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_KINGS_ROCK
# 633 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 634 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 635 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 636 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
# 637 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
# 638 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 639 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 640 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_FOCUS_BAND
# 641 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 642 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 643 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 644 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
# 645 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
# 646 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 647 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 648 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_SCOPE_LENS
# 649 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 650 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 651 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 652 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DestinyKnot::
# 653 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDestinyKnot, MSGBOX_YESNO
# 654 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 655 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 656 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_DESTINY_KNOT
# 657 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 658 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 659 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 660 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MirrorHerb::
# 661 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMirrorHerb, MSGBOX_YESNO
# 662 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 663 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 10
# 664 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_MIRROR_HERB
# 665 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 666 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 667 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 668 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Man::
# 669 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
# 670 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 671 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 672 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
# 673 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
# 674 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 675 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 676 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
# 677 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 678 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
# 679 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 680 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 681 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 682 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
# 683 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
# 684 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 685 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 686 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
# 687 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
# 688 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 689 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 690 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
# 691 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hello, this is the EXCHANGE SERVICE\n"
# 692 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "CORNER.\p"
# 693 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We exchange the Battle Points you\n"
# 694 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "have collected for lovely prizes.\p"
# 695 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please choose a prize from this list.$"
# 696 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 697 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
@ Unused
# 698 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
# 699 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please choose a prize from this list.$"
# 700 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 701 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
# 702 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the KISS POSTER.\n"
# 703 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 704 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 705 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
# 706 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the KISS CUSHION.\n"
# 707 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 708 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 709 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
# 710 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SMOOCHUM DOLL.\n"
# 711 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 712 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 713 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
# 714 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the TOGEPI DOLL.\n"
# 715 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 716 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 717 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
# 718 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MEOWTH DOLL.\n"
# 719 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 720 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 721 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
# 722 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CLEFAIRY DOLL.\n"
# 723 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 724 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 725 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
# 726 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the DITTO DOLL.\n"
# 727 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 728 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 729 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
# 730 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CYNDAQUIL DOLL.\n"
# 731 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 732 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 733 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
# 734 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHIKORITA DOLL.\n"
# 735 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 736 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 737 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
# 738 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the TOTODILE DOLL.\n"
# 739 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 740 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 741 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
# 742 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the LAPRAS DOLL.\n"
# 743 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 744 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 745 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
# 746 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SNORLAX DOLL.\n"
# 747 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 748 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 749 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
# 750 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the VENUSAUR DOLL.\n"
# 751 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 752 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 753 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
# 754 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHARIZARD DOLL.\n"
# 755 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 756 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 757 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
# 758 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BLASTOISE DOLL.\n"
# 759 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 760 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 761 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmHealthMochi:
# 762 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the HEALTH MOCHI.\n"
# 763 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 764 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 765 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMuscleMochi:
# 766 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MUSCLE MOCHI.\n"
# 767 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 768 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 769 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmResistMochi:
# 770 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the RESIST MOCHI.\n"
# 771 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 772 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 773 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmGeniusMochi:
# 774 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the GENIUS MOCHI.\n"
# 775 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 776 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 777 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCleverMochi:
# 778 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CLEVER MOCHI.\n"
# 779 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 780 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 781 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSwiftMochi:
# 782 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SWIFT MOCHI.\n"
# 783 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 784 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 785 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmFreshStartMochi:
# 786 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the FRESH START MOCHI.\n"
# 787 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 788 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 789 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBottleCap:
# 790 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BOTTLE CAP.\n"
# 791 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 792 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 793 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmGoldBottleCap:
# 794 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the GOLD BOTTLE CAP.\n"
# 795 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 796 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 797 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityCapsule:
# 798 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the ABILITY CAPSULE.\n"
# 799 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 800 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 801 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmLonelyMint:
# 802 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the LONELY MINT.\n"
# 803 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 804 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 805 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmAdamantMint:
# 806 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the ADAMANT MINT.\n"
# 807 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 808 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 809 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaughtyMint:
# 810 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the NAUGHTY MINT.\n"
# 811 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 812 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 813 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBraveMint:
# 814 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BRAVE MINT.\n"
# 815 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 816 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 817 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBoldMint:
# 818 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BOLD MINT.\n"
# 819 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 820 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 821 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmImpishMint:
# 822 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the IMPISH MINT.\n"
# 823 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 824 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 825 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxMint:
# 826 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the LAX MINT.\n"
# 827 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 828 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 829 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmRelaxedMint:
# 830 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the RELAXED MINT.\n"
# 831 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 832 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 833 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmModestMint:
# 834 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MODEST MINT.\n"
# 835 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 836 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 837 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMildMint:
# 838 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MILD MINT.\n"
# 839 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 840 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 841 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmRashMint:
# 842 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the RASH MINT.\n"
# 843 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 844 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 845 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuietMint:
# 846 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the QUIET MINT.\n"
# 847 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 848 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 849 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalmMint:
# 850 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CALM MINT.\n"
# 851 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 852 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 853 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmGentleMint:
# 854 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the GENTLE MINT.\n"
# 855 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 856 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 857 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarefulMint:
# 858 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CAREFUL MINT.\n"
# 859 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 860 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 861 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSassyMint:
# 862 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SASSY MINT.\n"
# 863 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 864 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 865 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmTimidMint:
# 866 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the TIMID MINT.\n"
# 867 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 868 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 869 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmHastyMint:
# 870 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the HASTY MINT.\n"
# 871 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 872 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 873 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmJollyMint:
# 874 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the Jolly MINT.\n"
# 875 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 876 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 877 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaiveMint:
# 878 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the NAIVE MINT.\n"
# 879 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 880 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 881 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeriousMint:
# 882 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SERIOUS MINT.\n"
# 883 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 884 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 885 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
# 886 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BRIGHTPOWDER.\n"
# 887 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 888 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 889 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
# 890 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the WHITE HERB.\n"
# 891 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 892 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 893 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
# 894 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the QUICK CLAW.\n"
# 895 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 896 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 897 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
# 898 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MENTAL HERB.\n"
# 899 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 900 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 901 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
# 902 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHOICE BAND.\n"
# 903 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 904 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 905 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceSpecs:
# 906 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHOICE SPECS.\n"
# 907 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 908 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 909 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
# 910 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the KING'S ROCK.\n"
# 911 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 912 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 913 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
# 914 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the FOCUS BAND.\n"
# 915 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 916 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 917 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
# 918 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SCOPE LENS.\n"
# 919 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 920 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 921 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
# 922 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the LEFTOVERS.\n"
# 923 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 924 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 925 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmDestinyKnot:
# 926 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the DESTINY KNOT.\n"
# 927 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 928 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 929 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMirrorHerb:
# 930 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MIRROR HERB.\n"
# 931 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 932 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 933 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
# 934 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you!\n"
# 935 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 936 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 937 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
# 938 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Here is your prize!$"
# 939 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 940 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
# 941 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 942 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have enough Battle Points…$"
# 943 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 944 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
# 945 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 946 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your PC appears to be full…$"
# 947 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 948 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
# 949 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 950 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have space to hold it…$"
# 951 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 952 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
# 953 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you very much.\p"
# 954 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please visit us when you have\n"
# 955 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "saved up Battle Points.$"
# 956 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 957 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
# 958 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Oh, they're so nice!\n"
# 959 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them!\l"
# 960 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Cute cushions!\l"
# 961 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Big plush DOLLS!\l"
# 962 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Little plush DOLLS!\l"
# 963 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them all!$"
# 964 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 965 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
# 966 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Leave it to your mommy!\p"
# 967 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If it's anything you want, I'll go\n"
# 968 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "through anything to get it, honey!$"
# 969 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 970 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
# 971 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If I can get hold of the items here,\n"
# 972 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "my POKéMON will get tougher.\p"
# 973 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You bet they will!\n"
# 974 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "No question about it!$"
# 975 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 976 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
# 977 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hah?\n"
# 978 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "What are you gawking at?\p"
# 979 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I don't like you staring at my plush\n"
# 980 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "doll like that.\p"
# 981 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you want it, go get one yourself!\n"
# 982 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Isn't that right, SMOOCHUM?$"
# 983 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 984 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
# 985 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Did you know?\p"
# 986 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you stretch your record at any of\n"
# 987 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the BATTLE facilities, they start\l"
# 988 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "giving you more and more Battle Points.$"
# 989 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 990 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
# 991 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large poster with a SMOOCHUM print.$"
# 992 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 993 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
# 994 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM cushion.\n"
# 995 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 996 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 997 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
# 998 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM DOLL.\n"
# 999 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1000 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1001 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
# 1002 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOGEPI DOLL.\n"
# 1003 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1004 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1005 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
# 1006 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A MEOWTH DOLL.\n"
# 1007 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1008 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1009 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
# 1010 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CLEFAIRY DOLL.\n"
# 1011 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1012 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1013 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
# 1014 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A DITTO DOLL.\n"
# 1015 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1016 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1017 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
# 1018 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CYNDAQUIL DOLL.\n"
# 1019 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1020 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1021 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
# 1022 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CHIKORITA DOLL.\n"
# 1023 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1024 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1025 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
# 1026 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOTODILE DOLL.\n"
# 1027 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1028 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1029 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
# 1030 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large DOLL.\n"
# 1031 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 1032 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1033 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HealthMochiDesc::
# 1034 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat HP of one\n"
# 1035 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON to maximum.$"
# 1036 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1037 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MuscleMochiDesc::
# 1038 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat ATTACK of one\n"
# 1039 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON to maximum.$"
# 1040 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1041 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ResistMochiDesc::
# 1042 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat DEFENSE of one\n"
# 1043 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON to maximum.$"
# 1044 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1045 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GeniusMochiDesc::
# 1046 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SP. ATK of one\n"
# 1047 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON to maximum.$"
# 1048 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1049 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CleverMochiDesc::
# 1050 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SP. DEF of one\n"
# 1051 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON to maximum.$"
# 1052 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1053 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SwiftMochiDesc::
# 1054 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SPEED of one\n"
# 1055 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "POKéMON to maximum.$"
# 1056 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1057 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_FreshStartMochiDesc::
# 1058 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Resets all base points of\n"
# 1059 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "a POKéMON.$"
# 1060 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1061 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BottleCapDesc::
# 1062 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be redeemable for hypertraining\n"
# 1063 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "(maximizes one stat).$"
# 1064 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1065 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GoldBottleCapDesc::
# 1066 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be redeemable for hypertraining\n"
# 1067 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "(maximizes all stats).$"
# 1068 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1069 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_AbilityCapsuleDesc::
# 1070 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Switches a POKéMON's ability.$"
# 1071 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1072 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LonelyMintDesc::
# 1073 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups ATTACK,\n"
# 1074 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces DEFENSE.$"
# 1075 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1076 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_AdamantMintDesc::
# 1077 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups ATTACK,\n"
# 1078 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. ATK.$"
# 1079 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1080 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_NaughtyMintDesc::
# 1081 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups ATTACK,\n"
# 1082 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. DEF.$"
# 1083 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1084 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BraveMintDesc::
# 1085 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups ATTACK,\n"
# 1086 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SPEED.$"
# 1087 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1088 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BoldMintDesc::
# 1089 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups DEFENSE,\n"
# 1090 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces ATTACK.$"
# 1091 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1092 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ImpishMintDesc::
# 1093 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups DEFENSE,\n"
# 1094 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. ATK.$"
# 1095 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1096 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LaxMintDesc::
# 1097 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups DEFENSE,\n"
# 1098 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. DEF.$"
# 1099 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1100 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_RelaxedMintDesc::
# 1101 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups DEFENSE,\n"
# 1102 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SPEED.$"
# 1103 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1104 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ModestMintDesc::
# 1105 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. ATK,\n"
# 1106 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces ATTACK.$"
# 1107 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1108 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MildMintDesc::
# 1109 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. ATK,\n"
# 1110 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces DEFENSE.$"
# 1111 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1112 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_RashMintDesc::
# 1113 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. ATK,\n"
# 1114 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. DEF.$"
# 1115 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1116 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_QuietMintDesc::
# 1117 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. ATK,\n"
# 1118 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SPEED.$"
# 1119 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1120 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CalmMintDesc::
# 1121 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. DEF,\n"
# 1122 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces ATTACK.$"
# 1123 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1124 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GentleMintDesc::
# 1125 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. DEF,\n"
# 1126 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces DEFENSE.$"
# 1127 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1128 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CarefulMintDesc::
# 1129 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. DEF,\n"
# 1130 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. ATK.$"
# 1131 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1132 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SassyMintDesc::
# 1133 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SP. DEF,\n"
# 1134 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SPEED.$"
# 1135 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1136 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TimidMintDesc::
# 1137 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SPEED,\n"
# 1138 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces ATTACK.$"
# 1139 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1140 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HastyMintDesc::
# 1141 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SPEED,\n"
# 1142 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces DEFENSE.$"
# 1143 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1144 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_JollyMintDesc::
# 1145 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SPEED,\n"
# 1146 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. ATK.$"
# 1147 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1148 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_NaiveMintDesc::
# 1149 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. It ups SPEED,\n"
# 1150 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "but reduces SP. DEF.$"
# 1151 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1152 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SeriousMintDesc::
# 1153 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Can be smelled. makes each\n"
# 1154 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "stat grow equally.$"
# 1155 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1156 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
# 1157 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that gradually restores\n"
# 1158 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "HP in battle.$"
# 1159 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1160 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
# 1161 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that restores any\n"
# 1162 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "lowered stat.$"
# 1163 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1164 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
# 1165 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally allows\n"
# 1166 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the first strike.$"
# 1167 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1168 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
# 1169 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that snaps POKéMON out\n"
# 1170 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "of infatuation.$"
# 1171 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1172 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
# 1173 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that casts a glare to\n"
# 1174 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "reduce accuracy.$"
# 1175 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1176 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
# 1177 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Boosts Attack, but permits\n"
# 1178 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "only one move.$"
# 1179 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1180 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChoiceSpecsDesc::
# 1181 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Boosts Sp. Atk, but permits\n"
# 1182 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "only one move.$"
# 1183 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1184 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
# 1185 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that may cause flinching\n"
# 1186 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "when the foe is hit.$"
# 1187 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1188 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
# 1189 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally\n"
# 1190 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "prevents fainting.$"
# 1191 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1192 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
# 1193 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that raises the\n"
# 1194 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "critical-hit rate.$"
# 1195 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1196 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DestinyKnotDesc::
# 1197 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If the holder falls in love,\n"
# 1198 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the foe does too.$"
# 1199 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 1200 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MirrorHerbDesc::
# 1201 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Mirrors an enemy's stat\n"
# 1202 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "increases but only once.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining::
# 1206 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 1207 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 1208 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_0, MSGBOX_YESNO
# 1209 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_2
# 1364 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_21
BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1:
# 1366 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	releaseall
	return

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_2:
# 1210 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	message BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_1
# 1211 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	multichoice 25, 8, MULTI_HYPERTRAINING, 0
# 1212 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	closemessage
# 1213 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_5
# 1281 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	checkitem ITEM_GOLD_BOTTLE_CAP
# 1282 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_11
# 1360 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_20
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_5:
# 1214 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	checkitem ITEM_BOTTLE_CAP
# 1215 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_8
# 1278 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_8:
# 1216 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_2
# 1217 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ChoosePartyMon
# 1218 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 1219 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	message BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_3
# 1220 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	multichoice 25, 0, MULTI_HYPERTRAINING_STAT, 0
# 1221 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	closemessage
# 1222 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_14
# 1231 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_15
# 1240 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_16
# 1249 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_17
# 1258 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_18
# 1268 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 3, VAR_0x8004
# 1269 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_43
# 1274 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_15
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_11:
# 1283 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_17
# 1284 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ChoosePartyMon
# 1285 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 1286 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 0, VAR_0x8004
# 1287 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_25
# 1297 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 1, VAR_0x8004
# 1298 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_46
# 1308 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 2, VAR_0x8004
# 1309 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_49
# 1319 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 3, VAR_0x8004
# 1320 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_52
# 1330 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 4, VAR_0x8004
# 1331 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_55
# 1341 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 5, VAR_0x8004
# 1342 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_58
# 1352 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_19
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_14:
# 1223 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 0, VAR_0x8004
# 1224 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_28
# 1229 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_5
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_15:
# 1232 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 1, VAR_0x8004
# 1233 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_31
# 1238 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_7
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_16:
# 1241 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 2, VAR_0x8004
# 1242 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_34
# 1247 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_9
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_17:
# 1250 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 4, VAR_0x8004
# 1251 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_37
# 1256 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_11
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_18:
# 1259 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canhypertrain 5, VAR_0x8004
# 1260 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_40
# 1265 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_13
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_25:
# 1288 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 1289 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1290 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1291 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1292 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1293 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1294 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1295 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_28:
# 1225 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 1226 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1227 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_4
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_31:
# 1234 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 1235 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1236 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_6
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_34:
# 1243 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 1244 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1245 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_8
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_37:
# 1252 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 1253 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1254 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_10
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_40:
# 1261 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 1262 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1263 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_12
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_43:
# 1270 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 1271 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1272 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_14
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_46:
# 1299 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 1300 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1301 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1302 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1303 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1304 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1305 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1306 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_49:
# 1310 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 1311 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1312 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1313 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1314 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1315 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1316 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1317 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_52:
# 1321 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 1322 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1323 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1324 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1325 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1326 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1327 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1328 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_55:
# 1332 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 1333 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1334 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1335 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1336 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1337 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1338 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1339 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_58:
# 1343 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 1344 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_HP, VAR_0x8004
# 1345 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_ATK, VAR_0x8004
# 1346 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_DEF, VAR_0x8004
# 1347 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPATK, VAR_0x8004
# 1348 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPDEF, VAR_0x8004
# 1349 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	hypertrain STAT_SPEED, VAR_0x8004
# 1350 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18
	goto BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_1


BattleFrontier_ExchangeServiceCorner_EventScript_Candies::
# 1370 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 1371 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 1372 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_0, MSGBOX_YESNO
# 1373 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_2
# 1421 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_3
BattleFrontier_ExchangeServiceCorner_EventScript_Candies_1:
# 1423 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	releaseall
	return

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_2:
# 1374 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	message BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_1
# 1375 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	multichoice 25, 0, MULTI_CANDIES, 0
# 1376 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	closemessage
# 1377 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_6
BattleFrontier_ExchangeServiceCorner_EventScript_Candies_5:
# 1384 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_9
BattleFrontier_ExchangeServiceCorner_EventScript_Candies_8:
# 1391 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_15
BattleFrontier_ExchangeServiceCorner_EventScript_Candies_14:
# 1398 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_21
BattleFrontier_ExchangeServiceCorner_EventScript_Candies_20:
# 1405 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_26
# 1413 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	giveitem ITEM_EXP_CANDY_MAX, 99
# 1414 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_35
# 1417 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_1

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_6:
# 1378 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	giveitem ITEM_RARE_CANDY, 99
# 1379 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_11
# 1382 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_5

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_9:
# 1385 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	giveitem ITEM_EXP_CANDY_S, 99
# 1386 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_17
# 1389 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_8

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_11:
# 1380 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_5

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_15:
# 1392 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	giveitem ITEM_EXP_CANDY_M, 99
# 1393 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_23
# 1396 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_14

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_17:
# 1387 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_8

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_21:
# 1399 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	giveitem ITEM_EXP_CANDY_L, 99
# 1400 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_29
# 1403 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_20

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_23:
# 1394 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_14

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_26:
# 1406 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	giveitem ITEM_EXP_CANDY_XL, 99
# 1407 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_Candies_32
# 1410 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_1

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_29:
# 1401 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_20

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_32:
# 1408 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_1

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_35:
# 1415 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto BattleFrontier_ExchangeServiceCorner_EventScript_Candies_1


BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship::
# 1427 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 1428 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 1429 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_0, MSGBOX_YESNO
# 1430 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_2
# 1442 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_4
BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_1:
# 1444 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	releaseall
	return

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_2:
# 1431 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_1
# 1432 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ChoosePartyMon
# 1433 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 1434 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	canmaxfriendship VAR_0x8004
# 1435 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_5
# 1439 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_3
	goto BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_1

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_5:
# 1436 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	maxfriendship VAR_0x8004
# 1437 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_1


BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_0:
# 1208 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hello! I can hypertraining your POKéMON\n"
	.string "in exchange for BOTTLE CAPS. Do you\l"
	.string "want to?$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_1:
# 1210 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Which kind of BOTTLE CAP do you want to\n"
	.string "use?$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_2:
# 1216 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Choose a POKéMON to hypertrain.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_3:
# 1219 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Which stat do you want to hypertrain?$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_4:
# 1227 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been hypertrained in\n"
	.string "HP!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_5:
# 1229 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "HP stat of your POKéMON can no longer\n"
	.string "be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_6:
# 1236 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been hypertrained in\n"
	.string "ATTACK!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_7:
# 1238 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "ATTACK stat of your POKéMON can no\n"
	.string "longer be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_8:
# 1245 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been hypertrained in\n"
	.string "DEFENSE!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_9:
# 1247 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "DEFENSE stat of your POKéMON can no\n"
	.string "longer be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_10:
# 1254 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been hypertrained in\n"
	.string "SP. ATK!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_11:
# 1256 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "SP. ATK stat of your POKéMON can no\n"
	.string "longer be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_12:
# 1263 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been hypertrained in\n"
	.string "SP. DEF!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_13:
# 1265 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "SP. DEF stat of your POKéMON can no\n"
	.string "longer be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_14:
# 1272 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been hypertrained in\n"
	.string "SPEED!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_15:
# 1274 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "SPEED stat of your POKéMON can no\n"
	.string "longer be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_16:
# 1278 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have any BOTTLE CAP.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_17:
# 1283 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Choose a POKéMON to fully hypertrain.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_18:
# 1295 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON has been fully\n"
	.string "hypertrained!$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_19:
# 1352 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your POKéMON can no longer be trained.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_20:
# 1360 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have any GOLD BOTTLE CAP.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HyperTraining_Text_21:
# 1364 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Ok. I'll be here if you need me. Bye!$"

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_0:
# 1372 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Psst...psst! Over here! Do you want some\n"
	.string "candies for free?$"

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_1:
# 1374 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Take as many as you want.$"

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_2:
# 1382 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Come back for more whenever you want.$"

BattleFrontier_ExchangeServiceCorner_EventScript_Candies_Text_3:
# 1421 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Ok, never mind.$"

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_0:
# 1429 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm known as the best POKéMON masseuse\n"
	.string "in the world. I can make your POKéMON\l"
	.string "increase their friendship to the\l"
	.string "maximum with just one massage. And it's\l"
	.string "totally free! Do you want to try?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_1:
# 1431 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Choose a POKéMON give it the masseuse.$"

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_2:
# 1437 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "The friendship of this POKéMON is now\n"
	.string "maximized! Don't thank me.$"

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_3:
# 1439 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "The friendship of this POKéMON is\n"
	.string "already at its peak. My massages won't\l"
	.string "do much good.$"

BattleFrontier_ExchangeServiceCorner_EventScript_MaxFriendship_Text_4:
# 1442 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Come back when you want one of my\n"
	.string "amazing massages. See you!$"
