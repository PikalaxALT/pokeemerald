//
// Created by scott on 9/21/2017.
//

#include "global.h"
#include "malloc.h"
#include "event_data.h"
#include "party_menu.h"
#include "battle.h"
#include "rom4.h"

extern u16 gTrainerBattleOpponent_A;
extern u8 gUnknown_0203CEF8[2];

extern void (*const gUnknown_0860D090[])(void);
extern const u32 gUnknown_0860D0EC[2][2];
extern const u32 gUnknown_0860D0FC[2][2];

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

void sub_818ED28(void)
{
    u8 level;
    u16 var_40ce;

    level = gSaveBlock2Ptr->frontierChosenLvl;
    var_40ce = VarGet(VAR_0x40CE);
    switch (gSpecialVar_0x8005)
    {
        case 0:
            gSaveBlock2Ptr->unk_d0c[var_40ce][level] = gSpecialVar_0x8006;
            break;
        case 1:
            if (gSpecialVar_0x8006)
            {
                gSaveBlock2Ptr->unk_cdc |= gUnknown_0860D0EC[var_40ce][level];
            }
            else
            {
                gSaveBlock2Ptr->unk_cdc &= gUnknown_0860D0FC[var_40ce][level];
            }
            break;
        case 2:
            gSaveBlock2Ptr->unk_d08_0 = gSpecialVar_0x8006;
            break;
        case 3:
            gSaveBlock2Ptr->unk_d08_1 = gSpecialVar_0x8006;
            break;
        case 4:
            gSaveBlock2Ptr->unk_d08_2 = gSpecialVar_0x8006;
            break;
        case 5:
            gSaveBlock2Ptr->unk_d08_3 = gSpecialVar_0x8006;
            break;
        case 6:
            if (VarGet(VAR_0x40CE) == 1)
            {
                if (level)
                {
                    gSaveBlock2Ptr->unk_d08_5 = gSpecialVar_0x8006;
                }
                else
                {
                    gSaveBlock2Ptr->unk_d08_4 = gSpecialVar_0x8006;
                }
            }
            else
            {
                if (level)
                {
                    gSaveBlock2Ptr->unk_d08_1 = gSpecialVar_0x8006;
                }
                else
                {
                    gSaveBlock2Ptr->unk_d08_0 = gSpecialVar_0x8006;
                }
            }
            break;
        case 7:
            if (VarGet(VAR_0x40CE) == 1)
            {
                if (level)
                {
                    gSaveBlock2Ptr->unk_d08_7 = gSpecialVar_0x8006;
                }
                else
                {
                    gSaveBlock2Ptr->unk_d08_6 = gSpecialVar_0x8006;
                }
            }
            else
            {
                if (level)
                {
                    gSaveBlock2Ptr->unk_d08_3 = gSpecialVar_0x8006;
                }
                else
                {
                    gSaveBlock2Ptr->unk_d08_2 = gSpecialVar_0x8006;
                }
            }
            break;
        case 8:
            gSaveBlock2Ptr->unk_cb0 = gUnknown_0203CEF8[0] | (gUnknown_0203CEF8[1] << 8);
            break;
    }
}

//void sub_818F02C(void)
//{
//    int i;
//    int j;
//    u32 sp08[3] = {};
//    void *sp18 = AllocZeroed(0x20);
//    void *sp1c = AllocZeroed(0x18);
//    u16 unk_r4;
//
//    gSaveBlock2Ptr->unk_d0a = gSaveBlock2Ptr->frontierChosenLvl + 1;
//    gSaveBlock2Ptr->unk_d0b = VarGet(VAR_0x40CE) + 1;
//    gSaveBlock2Ptr->unk_d24_0 = -1;
//    gSaveBlock2Ptr->unk_d24_A = FALSE;
//    gSaveBlock2Ptr->unk_d24_B = 0;
//    gSaveBlock2Ptr->unk_d24_D = 0;
//#define bfParty ((struct Pokemon *)(&gBattleScripting.atk49_state))
//    for (i = 0; i < 3; i ++)
//    {
//        gSaveBlock2Ptr->unk_d64[i] = GetMonData(&bfParty[gSaveBlock2Ptr->unk_caa[i]], MON_DATA_SPECIES, NULL);
//        for (j = 0; j < 4; j ++)
//        {
//            gSaveBlock2Ptr->frontier_efc[i].moves[j] = GetMonData(&bfParty[gSaveBlock2Ptr->unk_caa[i]], MON_DATA_MOVE1 + j, NULL);
//        }
//        for (j = 0; j < 6; j ++)
//        {
//            gSaveBlock2Ptr->frontier_efc[i].evs[j] = GetMonData(&bfParty[gSaveBlock2Ptr->unk_caa[i]], MON_DATA_HP_EV + j, NULL);
//        }
//        gSaveBlock2Ptr->frontier_efc[i].nature = GetNature(&bfParty[gSaveBlock2Ptr->unk_caa[i]]);
//    }
//    for (i = 1; i < 16; i ++)
//    {
//        if (i > 5)
//        {
//            unk_r4 = sub_8162548(sub_81A39C4(), 0);
//            if (1 < i)
//            {
//                while (gSaveBlock2Ptr->unk_d24_0 != unk_r4)
//                {
//
//                }
//            }
//        }
//    }
//#undef bfParty
//}
