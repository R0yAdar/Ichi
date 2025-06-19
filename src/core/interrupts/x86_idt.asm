[bits 64]
align 16

%macro pushall 0
    push rax
    push rcx
    push rdx
    push rsi
    push rdi
    push r8
    push r9
    push r10
    push r11
%endmacro

%macro popall 0
    pop r11
    pop r10
    pop r9
    pop r8
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rax
%endmacro

%macro define_isr_handler 2
    global %1
    %1:

    pushall

    cld

    mov rdi, rax
    mov rsi, rcx

    extern %2
    call %2

    popall

    iretq
%endmacro

%macro define_exception_handler 3
    global %1
    %1:

    mov rax, %3

    pushall

    cld

    mov rdi, rax
    mov rsi, rcx

    extern %2
    call %2

    popall

    iretq
%endmacro

define_exception_handler isr0_handler, general_exception_handler, 0

define_isr_handler isr80_handler, sysCallC
