#include "../stdint.h"
#include "../hal.h"
#include "../graphics/vga.h"
#include "x86_idt.h"

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

void systemCall(int sysCallNo, void* ptr)
{
    asm volatile( "int $0xc0" :: "a"(sysCallNo), "c"(ptr) : "memory" );
}

void general_exception_handler(uint64_t exception_no, void* ptr) {
	const char msg[] = "DEFAULT Exception HANDLER!!";

    vga_text_input input;

    input.x = 5;
    input.y = 5;

    input.text = msg;

    input.color = 0x37;

    vga_put(&input);
}

void sysCallC(uint64_t syscall_no, void* ptr) {
	const char msg[] = "DEFAULT INTERRUPT HANDLER!!";

    vga_text_input input;

    input.x = 10;
    input.y = 10;

    input.text = msg;

    input.color = 0x19;

    vga_put(&input);
}

void i86_install_ir(uint8_t index, idt_descriptor descriptor){
    _idt[index] = descriptor;
}

int init_idt(){
    _idtr.limit = sizeof(idt_descriptor) * 256 -1;
    _idtr.base = (uint64_t)&_idt[0];

    i86_install_ir(0, create_descriptor(isr0_handler));


    for (int i = 1; i < 256; i++){
        i86_install_ir(i, create_descriptor(isr80_handler));
    }

    idt_install();
    
    return 0;    
}