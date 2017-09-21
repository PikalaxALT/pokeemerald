//
// Created by scott on 9/21/2017.
//

#include "global.h"
#include "event_data.h"
#include "rom4.h"

extern u16 gTrainerBattleOpponent_A;

extern void (*const gUnknown_0860D090[])(void);
extern const u32 gUnknown_0860D0EC[][2];

void sub_818E9AC(void)
{
    gUnknown_0860D090[gSpecialVar_0x8004]();
}


void sub_818E9CC(void)
{
    u8 level;
    u16 var_40ce;
    
    level = gSaveBlock2Ptr->frontierChosenLvl;
    var_40ce = VarGet(VAR_0x40CE);
    gSaveBlock2Ptr->unk_ca8 = 0;
    gSaveBlock2Ptr->unk_cb2 = 0;
    gSaveBlock2Ptr->field_CA9_a = FALSE;
    gSaveBlock2Ptr->field_CA9_b = FALSE;
    if ((gSaveBlock2Ptr->unk_cdc & gUnknown_0860D0EC[var_40ce][level]) == 0)
    {
        gSaveBlock2Ptr->unk_d0c[var_40ce][level] = 0;
    }
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}