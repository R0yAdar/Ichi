#pragma once

/* PIT Ports */
#define PIT_CHANNEL0_PORT 0x40
#define PIT_CHANNEL1_PORT 0x41
#define PIT_CHANNEL2_PORT 0x42
#define PIT_COMMAND_PORT 0x43

/* Magic values */ 
#define PIT_OSCILLATOR_SIGNAL_HZ 1193182

void init_pit();

void pit_handler();
