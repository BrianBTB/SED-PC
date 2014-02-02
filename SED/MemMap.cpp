#include "MemMap.h"

u8* base;

void Memory::Init()
{
    base = (u8*)malloc(33554432);
}

void Memory::Dispose()
{
    free((void*)base);
}

inline u8* Memory::GetPointer(const u32 address)
{
#if defined(_M_IX86) || defined(_M_ARM32)
    return (u8 *)(base + (address & MEMVIEW32_MASK));
#else
    return (u8 *)(base + address);
#endif
}

void Memory::ReadStruct(u32 address, pspChnnlsvContext1 *ptr)
{
    size_t sz = sizeof(*ptr);
    memcpy(ptr, GetPointer(address), sz);
}

void Memory::WriteStruct(u32 address, pspChnnlsvContext1 *ptr)
{
    size_t sz = sizeof(*ptr);
    memcpy(GetPointer(address), ptr, sz);
}

void Memory::ReadStruct(u32 address, pspChnnlsvContext2 *ptr)
{
    size_t sz = sizeof(*ptr);
    memcpy(ptr, GetPointer(address), sz);
}

void Memory::WriteStruct(u32 address, pspChnnlsvContext2 *ptr)
{
    size_t sz = sizeof(*ptr);
    memcpy(GetPointer(address), ptr, sz);
}