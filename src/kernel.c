#include "core/graphics/vga.h"
#include "core/interrupts/idt.h"
#include "core/interrupts/x86_pic.h"
#include "core/interrupts/x86_pit.h"


#define ARRAY_SIZE(arr) ((int)sizeof(arr) / (int)sizeof((arr)[0]))

/*
0xA0000 - 0xBFFFF Video Memory used for graphics modes
0xB0000 - 0xB7777 Monochrome Text mode
0xB8000 - 0xBFFFF Color text mode and CGA compatible graphics modes
*/

void _start_kernel(void) {
	vga_clear_screen();

	const char loading_message[] = "Ichi kernel loading...";
	const char configured_pic_message[] = "Ichi kernel enabled PIC...";
	const char enabled_pit_message[] = "Ichi kernel enabled PIT...";

	vga_text_input input  = {0, 0, loading_message, 0x09};
	vga_put(&input);

	input.text = configured_pic_message;
	++input.y;
	vga_put(&input);

	init_idt();

	systemCall(0, 0);

	volatile int a = 5;

	// int b = a / 0;

	init_pic();
	init_pit();
	
	asm volatile ("sti" ::: "memory");

	input.text = enabled_pit_message;
	++input.y;
	vga_put(&input);

}