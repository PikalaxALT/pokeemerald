#include "global.h"
#include "blit.h"

void BlitBitmapRect4BitWithoutColorKey(struct Bitmap *src, struct Bitmap *dest, u16 srcX, u16 srcY, u16 destX, u16 destY, u16 width, u16 height)
{
    BlitBitmapRect4Bit(src, dest, srcX, srcY, destX, destY, width, height, 0xFF);
}
