#include "graphics/vga.h"
#include "idt.h"

#define ARRAY_SIZE(arr) ((int)sizeof(arr) / (int)sizeof((arr)[0]))

/*
0xA0000 - 0xBFFFF Video Memory used for graphics modes
0xB0000 - 0xB7777 Monochrome Text mode
0xB8000 - 0xBFFFF Color text mode and CGA compatible graphics modes
*/

void _start_kernel(void) {
	const char msg[] = "Hello from Ichi!!!!";


	vga_clear_screen();
	vga_text_input input  = {0, 0, msg, 0x09};
	vga_put(&input);
	
	input.y = 10;
	input.x = 2;
	input.color = 0x17;
 
	vga_put(&input);
	setup_idt();
}