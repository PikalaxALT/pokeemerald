#ifndef GUARD_POKEDEX_CRY_SCREEN_H
#define GUARD_POKEDEX_CRY_SCREEN_H

#include <gba/gba.h>

struct CryRelatedStruct
{
    u16 unk0;
    u8 unk2;
    u8 paletteNo;
    u8 xPos;
    u8 yPos;
};

bool8 sub_8145354(struct CryRelatedStruct*, u8);
void sub_814545C(u8);
void sub_8145534(u16);
void sub_8145914(void);
bool8 sub_8145850(struct CryRelatedStruct*, u8);

#endif
