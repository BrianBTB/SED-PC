#pragma once

#include <cstring>
#include "sceKernel.h"
#include "CommonTypes.h"
#include "sceChnnlsv.h"

extern u8 *base;

enum {
    // This may be adjusted by remaster games.
    RAM_NORMAL_SIZE = 0x02000000,
    RAM_NORMAL_MASK = RAM_NORMAL_SIZE - 1,

    // Used if the PSP model is PSP-2000 (Slim).
    RAM_DOUBLE_SIZE = RAM_NORMAL_SIZE * 2,

    VRAM_SIZE			 = 0x200000,
    VRAM_MASK			 = VRAM_SIZE - 1,

    SCRATCHPAD_SIZE = 0x4000,
    SCRATCHPAD_MASK = SCRATCHPAD_SIZE - 1,

#if defined(_M_IX86) || defined(_M_ARM32) || defined (_XBOX)
    // This wraparound should work for PSP too.
    MEMVIEW32_MASK	= 0x3FFFFFFF,
#endif
};

class Memory
{
public:
    static void Init();
    static void Dispose();
    static void ReadStruct(u32 address, pspChnnlsvContext1 *ptr);
    static void WriteStruct(u32 address, pspChnnlsvContext1 *ptr);
    static void ReadStruct(u32 address, pspChnnlsvContext2 *ptr);
    static void WriteStruct(u32 address, pspChnnlsvContext2 *ptr);
    static u8* GetPointer(const u32 address);
};