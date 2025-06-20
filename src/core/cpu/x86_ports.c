#include "ports.h"

char port_inb(char port){
    char result;
    __asm__ volatile ("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}


void port_outb(char port, char data){
    __asm__ volatile ("out %%al, %%dx" : : "a" (data), "d" (port));
}