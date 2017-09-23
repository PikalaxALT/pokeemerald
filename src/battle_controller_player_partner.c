//
// Created by scott on 9/23/2017.
//

#include "global.h"

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

const void *const gUnknown_08617128[][3] = {
    {gUnknown_08DD87C0, gUnknown_08DD8EE0, gUnknown_08DD8780},
    {gUnknown_08DD90E0, gUnknown_08DD9718, gUnknown_08DD9080},
    {gUnknown_08DD98B4, gUnknown_08DD9E58, gUnknown_08DD9874},
    {gUnknown_08DDA02C, gUnknown_08DDA63C, gUnknown_08DD9FEC},
    {gUnknown_08DDA840, gUnknown_08DDAE40, gUnknown_08DDA800},
    {gUnknown_08DDB020, gUnknown_08DDB2C4, gUnknown_08DDAFE0}
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
