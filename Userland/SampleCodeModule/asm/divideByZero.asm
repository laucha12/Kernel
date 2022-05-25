GLOBAL divideByZeroAsm


section .text

divideByZeroAsm:
    
    push rsp 
    push rbp
    push rbx
    push r12
    push r13
    push 15

    mov rax, 0
    mov rbx, 2
    mov rcx, 3
    mov rdx, 4
    mov rsi, 5
    mov rdi, 6
    ;mov rbp, 1
    ;mov rsp, 1
    mov r8, 8
    mov r9, 9
    mov r10, 10
    mov r11, 11
    mov r12, 12
    mov r13, 13
    mov r14, 14
    mov r15, 15
    
    div rax
    
    pop r12
    pop r13
    pop r15
    pop rbx
    pop rbp
    pop rsp

    ret
