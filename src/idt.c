#include "../include/stdint.h"
#include "../include/hal.h"
#include "graphics/vga.h"

#pragma pack (push, 1)

typedef struct
{
    uint16_t limit;
    uint64_t base;
} idtr;
 

#pragma pack (pop)

static idt_descriptor _idt[256];

static idtr _idtr;

static void idt_install() {
    asm volatile (
        "lidt %0"
        :
        : "m"(_idtr)
    );
}

void default_handler()  {
	const char msg[] = "DEFAULT INTERRUPT HANDLER";

}

void get_interrupt() {    
    asm volatile( "int $0xc0");
}

void sysCallC(uint64_t syscall_no, void* ptr) {
	const char msg[] = "DEFAULT INTERRUPT HANDLER";

    vga_text_input input;

    input.x = 10;
    input.y = 10;

    input.text = msg;

    input.color = 0x19;

    vga_put(&input);
}

int i86_install_ir(uint8_t index, idt_descriptor descriptor){
    _idt[index] = descriptor;
    return 0;
}

extern void irqCallHandler();

int setup_idt(){
    _idtr.limit = sizeof(idt_descriptor) * 256 -1;
    _idtr.base = (uint64_t)&_idt[0];

    for (int i = 0; i < 256; i++){
         i86_install_ir(i, create_descriptor(irqCallHandler));
    }

    idt_install();
    get_interrupt();

    return 0;    
}