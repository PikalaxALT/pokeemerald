//
// Created by scott on 9/21/2017.
//

#include "global.h"
#include "event_data.h"
#include "party_menu.h"
#include "rom4.h"

extern u16 gTrainerBattleOpponent_A;
extern u8 gUnknown_0203CEF8[2];

extern void (*const gUnknown_0860D090[])(void);
extern const u32 gUnknown_0860D0EC[2][2];

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

void sub_818EA84(void)
{
    u8 level;
    u16 var_40ce;

    level = gSaveBlock2Ptr->frontierChosenLvl;
    var_40ce = VarGet(VAR_0x40CE);
    switch (gSpecialVar_0x8005)
    {
        case 0:
            gScriptResult = gSaveBlock2Ptr->unk_d0c[var_40ce][level];
            break;
        case 1:
            gScriptResult = gSaveBlock2Ptr->unk_cdc & gUnknown_0860D0EC[var_40ce][level] ? TRUE : FALSE;
            break;
        case 2:
            gScriptResult = gSaveBlock2Ptr->unk_d08_0;
            break;
        case 3:
            gScriptResult = gSaveBlock2Ptr->unk_d08_1;
            break;
        case 4:
            gScriptResult = gSaveBlock2Ptr->unk_d08_2;
            break;
        case 5:
            gScriptResult = gSaveBlock2Ptr->unk_d08_3;
            break;
        case 6:
            if (VarGet(VAR_0x40CE) == 1)
            {
                if (level)
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_5;
                }
                else
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_4;
                }
            }
            else
            {
                if (level)
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_1;
                }
                else
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_0;
                }
            }
            break;
        case 7:
            if (VarGet(VAR_0x40CE) == 1)
            {
                if (level)
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_7;
                }
                else
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_6;
                }
            }
            else
            {
                if (level)
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_3;
                }
                else
                {
                    gScriptResult = gSaveBlock2Ptr->unk_d08_2;
                }
            }
            break;
        case 8:
            sub_81B8558();
            gUnknown_0203CEF8[0] = gSaveBlock2Ptr->unk_cb0;
            gUnknown_0203CEF8[1] = gSaveBlock2Ptr->unk_cb0 >> 8;
            break;
        case 9:
            gScriptResult = gSaveBlock2Ptr->unk_d0a * 2 - 3 + gSaveBlock2Ptr->unk_d0b;
            break;
    }
}