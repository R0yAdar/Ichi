global irqCallHandler
[bits 64]
align 16

irqCallHandler:

    push rax
    push rcx
    push rdx
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11

    cld

    mov rdi, rax
    mov rsi, rcx

    extern sysCallC
    call sysCallC

    pop r11
    pop r10
    pop r9
    pop r8
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rax

    iretq
