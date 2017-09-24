//
// Created by scott on 9/23/2017.
//

#include "global.h"
#include "util.h"
#include "sprite.h"
#include "battle.h"

void PlayerPartnerBufferRunCommand(void);
void PlayerPartnerBufferExecCompleted(void);
void dp01t_00_3_getattr(void);
void sub_81BC484(void);
void sub_81BC490(void);
void sub_81BCEE4(void);
void sub_81BCF58(void);
void sub_81BD074(void);
void sub_81BD260(void);
void sub_81BD37C(void);
void sub_81BD5BC(void);
void sub_81BD5C8(void);
void sub_81BD674(void);
void sub_81BD760(void);
void sub_81BD76C(void);
void sub_81BD778(void);
void sub_81BD784(void);
void sub_81BD790(void);
void sub_81BDA4C(void);
void sub_81BDAA0(void);
void sub_81BDAAC(void);
void sub_81BDABC(void);
void sub_81BDAC8(void);
void sub_81BDB70(void);
void sub_81BDB7C(void);
void sub_81BDC04(void);
void sub_81BDC10(void);
void sub_81BDD00(void);
void sub_81BDD9C(void);
void sub_81BDE14(void);
void sub_81BDE7C(void);
void sub_81BDE88(void);
void sub_81BDE94(void);
void sub_81BDEA0(void);
void sub_81BDEAC(void);
void sub_81BDEB8(void);
void sub_81BDEC4(void);
void sub_81BDED0(void);
void sub_81BDEDC(void);
void sub_81BDEE8(void);
void sub_81BDF04(void);
void sub_81BDF3C(void);
void sub_81BDF54(void);
void dp01t_29_3_blink(void);
void sub_81BDFEC(void);
void sub_81BDFF8(void);
void sub_81BE03C(void);
void sub_81BE098(void);
void dp01t_2E_3_battle_intro(void);
void sub_81BE10C(void);
void dp01t_30_3_80EB11C(void);
void sub_81BE4E0(void);
void sub_81BE530(void);
void sub_81BE53C(void);
void sub_81BE59C(void);
void sub_81BE604(void);
void sub_81BE610(void);
void sub_81BE61C(void);
void nullsub_128(void);

extern const u16 gUnknown_08DD87C0[];
extern const u16 gUnknown_08DD8EE0[];
extern const u16 gUnknown_08DD8780[];
extern const u16 gUnknown_08DD90E0[];
extern const u16 gUnknown_08DD9718[];
extern const u16 gUnknown_08DD9080[];
extern const u16 gUnknown_08DD98B4[];
extern const u16 gUnknown_08DD9E58[];
extern const u16 gUnknown_08DD9874[];
extern const u16 gUnknown_08DDA02C[];
extern const u16 gUnknown_08DDA63C[];
extern const u16 gUnknown_08DD9FEC[];
extern const u16 gUnknown_08DDA840[];
extern const u16 gUnknown_08DDAE40[];
extern const u16 gUnknown_08DDA800[];
extern const u16 gUnknown_08DDB020[];
extern const u16 gUnknown_08DDB2C4[];
extern const u16 gUnknown_08DDAFE0[];

static const void *const gUnknown_08617128[][3] = {
    {gUnknown_08DD87C0, gUnknown_08DD8EE0, gUnknown_08DD8780},
    {gUnknown_08DD90E0, gUnknown_08DD9718, gUnknown_08DD9080},
    {gUnknown_08DD98B4, gUnknown_08DD9E58, gUnknown_08DD9874},
    {gUnknown_08DDA02C, gUnknown_08DDA63C, gUnknown_08DD9FEC},
    {gUnknown_08DDA840, gUnknown_08DDAE40, gUnknown_08DDA800},
    {gUnknown_08DDB020, gUnknown_08DDB2C4, gUnknown_08DDAFE0}
};

static void (*const gPlayerPartnerBufferCommands[])(void) = {
    dp01t_00_3_getattr,
    sub_81BC484,
    sub_81BC490,
    sub_81BCEE4,
    sub_81BCF58,
    sub_81BD074,
    sub_81BD260,
    sub_81BD37C,
    sub_81BD5BC,
    sub_81BD5C8,
    sub_81BD674,
    sub_81BD760,
    sub_81BD76C,
    sub_81BD778,
    sub_81BD784,
    sub_81BD790,
    sub_81BDA4C,
    sub_81BDAA0,
    sub_81BDAAC,
    sub_81BDABC,
    sub_81BDAC8,
    sub_81BDB70,
    sub_81BDB7C,
    sub_81BDC04,
    sub_81BDC10,
    sub_81BDD00,
    sub_81BDD9C,
    sub_81BDE14,
    sub_81BDE7C,
    sub_81BDE88,
    sub_81BDE94,
    sub_81BDEA0,
    sub_81BDEAC,
    sub_81BDEB8,
    sub_81BDEC4,
    sub_81BDED0,
    sub_81BDEDC,
    sub_81BDEE8,
    sub_81BDF04,
    sub_81BDF3C,
    sub_81BDF54,
    dp01t_29_3_blink,
    sub_81BDFEC,
    sub_81BDFF8,
    sub_81BE03C,
    sub_81BE098,
    dp01t_2E_3_battle_intro,
    sub_81BE10C,
    dp01t_30_3_80EB11C,
    sub_81BE4E0,
    sub_81BE530,
    sub_81BE53C,
    sub_81BE59C,
    sub_81BE604,
    sub_81BE610,
    sub_81BE61C,
    nullsub_128
};

void sub_81BAD84(u32 idx)
{
    REG_DISPCNT = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BLDCNT = 0;
    LZ77UnCompVram(gUnknown_08617128[idx][0], (void *)BG_CHAR_ADDR(0));
    LZ77UnCompVram(gUnknown_08617128[idx][1], (void *)BG_SCREEN_ADDR(31));
    CpuCopy16(gUnknown_08617128[idx][2], (void *)BG_PLTT, 0x200);
    REG_BG0CNT = 0x1F00;
    REG_DISPCNT = DISPCNT_BG0_ON;
}

void nullsub_77(void) {}

void SetBankFuncToPlayerPartnerBufferRunCommand(void)
{
    gBattleBankFunc[gActiveBank] = PlayerPartnerBufferRunCommand;
}

void PlayerPartnerBufferRunCommand(void)
{
    if (gBattleExecBuffer[0] & gBitTable[gActiveBank])
    {
        if (gBattleBufferA[gActiveBank][0] <= 0x38)
        {
            gPlayerPartnerBufferCommands[gBattleBufferA[gActiveBank][0]]();
        }
        else
        {
            PlayerPartnerBufferExecCompleted();
        }
    }
}

void sub_81BAE60(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        PlayerPartnerBufferExecCompleted();
    }
}

void sub_81BAE98(void)
{
    if (gSprites[gBankSpriteIds[gActiveBank]].callback == SpriteCallbackDummy)
    {
        nullsub_25(0);
        FreeSpriteOamMatrix(&gSprites[gBankSpriteIds[gActiveBank]]);
        DestroySprite(&gSprites[gBankSpriteIds[gActiveBank]]);
        PlayerPartnerBufferExecCompleted();
    }
}

void sub_81BAF00(void)
{
    if (--gUnknown_020244D0[1][gActiveBank].unk9 == 0xFF)
    {
        gUnknown_020244D0[1][gActiveBank].unk9 = 0;
        PlayerPartnerBufferExecCompleted();
    }
}
