#pragma once

#include "stdint.h"

#pragma pack (push, 1)

typedef struct
{
    uint16_t offset_low16;
    uint16_t segment_selector; // point to valid GDT segment
    
    uint8_t ist;
    uint8_t flags;

    uint16_t offset_upper16;
    uint32_t offset_upper32;
    uint32_t reserved;
} idt_descriptor;
 

idt_descriptor create_descriptor(void* handler) {
    idt_descriptor desc;

    desc.segment_selector = 0x8;

    desc.flags = 0x8E;

    desc.ist = 0;

    desc.offset_low16 = (uint64_t)handler & 0xffff;
    desc.offset_upper16 = ((uint64_t)handler >> 16) & 0xffff;
    desc.offset_upper32 = (uint32_t)((uint64_t)handler >> 32);

    desc.reserved = 0;

    return desc;
}

#pragma pack (pop)