
// Exception ISRs 0-31
extern void isr0_handler();   // Divide-by-zero
extern void isr1_handler();   // Debug
extern void isr2_handler();   // Non-maskable Interrupt
extern void isr3_handler();   // Breakpoint
extern void isr4_handler();   // Overflow
extern void isr5_handler();   // Bound Range Exceeded
extern void isr6_handler();   // Invalid Opcode
extern void isr7_handler();   // Device Not Available
extern void isr8_handler();   // Double Fault
extern void isr9_handler();   // Coprocessor Segment Overrun (reserved)
extern void isr10_handler();  // Invalid TSS
extern void isr11_handler();  // Segment Not Present
extern void isr12_handler();  // Stack-Segment Fault
extern void isr13_handler();  // General Protection Fault
extern void isr14_handler();  // Page Fault
extern void isr15_handler();  // Reserved
extern void isr16_handler();  // x87 Floating-Point Exception
extern void isr17_handler();  // Alignment Check
extern void isr18_handler();  // Machine Check
extern void isr19_handler();  // SIMD Floating-Point Exception
extern void isr20_handler();  // Virtualization Exception
extern void isr21_handler();  // Control Protection Exception
extern void isr22_handler();  // Reserved
extern void isr23_handler();  // Reserved
extern void isr24_handler();  // Reserved
extern void isr25_handler();  // Reserved
extern void isr26_handler();  // Reserved
extern void isr27_handler();  // Reserved
extern void isr28_handler();  // Hypervisor Injection Exception
extern void isr29_handler();  // VMM Communication Exception
extern void isr30_handler();  // Security Exception
extern void isr31_handler();  // Reserved



extern void isr80_handler();

char* exception_messages[] = {
    // 0
    "Division by Zero",
    "Debug",
    "Non-Maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bat TSS",
    "Segment not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved" // 31
};
