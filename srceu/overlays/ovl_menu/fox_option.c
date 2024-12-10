#include "common.h"

// difference from US: there's a call to func_menu_8019626C after setting gVIsPerFrame
// sOptionCardList setup is missing from this function, perhaps it was moved to func_menu_8019626C?
#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Setup.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Main.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Entry_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Entry_Draw.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019626C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Entry_Setup.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801964EC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019668C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Map_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Training_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80196944.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_MainMenu_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_MainMenu_Draw.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80197C78.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Versus_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80198700.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80198888.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Sound_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Sound_SetSoundMode.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Sound_SetVolumeLevels.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80198F04.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801996C0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80199CFC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_ExpertSound_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_80199F94.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019A69C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Language_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019A790.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019A930.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019AAC8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019AC74.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019B274.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019B490.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Data_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Data_Select.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019B970.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019BFF0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Ranking_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019C138.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Ranking_Select.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019C210.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019C2F8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019C55C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019C6E8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019CAD0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019CBF8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019CF60.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D20.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D24.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D28.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D2C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D30.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D34.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D38.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D3C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D40.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D44.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D48.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D4C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D50.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D54.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D58.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D5C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D60.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D64.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D68.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D6C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D74.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D84.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D90.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9D9C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DA0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019D014.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019D2D8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019D4C8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019D614.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019D834.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019D96C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019DB98.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019DCD8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019E504.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019E5F0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019E630.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_VersusMenu_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019E808.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019EAF8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019EB8C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019F278.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019F378.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019F450.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_VersusStage_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Vs_PointMatch_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Vs_BattleRoyal_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Vs_TimeTrial_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019F65C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019F6A4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019F8A0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019FAA0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019FD18.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019FE78.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_8019FEF4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A01AC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A04CC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0710.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0944.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0B70.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0C9C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0D98.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0EBC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0EE4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A0FE4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A10E4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A11D0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1270.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A141C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A14A8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1560.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1678.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A174C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Input_MoveCursor_Y.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1BCC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1C98.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1E54.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A1EF4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_NameEntry_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A21F0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A2388.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A275C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A2C80.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A317C.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A3344.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Score_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A34E8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A35D8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/Option_Invoice_Update.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/func_menu_801A38F0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DBC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DC4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DCC.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DD4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DE0.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DE8.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9DF4.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9E04.s")

#pragma GLOBAL_ASM("asm/eu/rev0/nonmatchings/overlays/ovl_menu/fox_option/D_menu_801B9E14.s")
