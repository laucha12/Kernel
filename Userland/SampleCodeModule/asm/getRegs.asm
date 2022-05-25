GLOBAL getRegs

section .text

getRegs:
    mov qword [array], rax          ;
    mov qword [array + 8], rbx      ;
    mov [array + 16], rcx     ;
    mov [array + 24], rdx     ;
    mov [array + 32], rsi     ;
    mov [array + 40], rdi     ;
    
    dec rsp                     ; Decremento el valor de rsp para tener el valor 
    mov [array + 48], rsp     ; previo al llamado de esta rutina
    inc rsp                 ; Restauro su valor

    mov [array + 56], rbp     ;
    mov [array + 64], r8      ;
    mov [array + 72], r9      ;
    mov [array + 80], r10     ;
    mov [array + 88], r11     ;
    mov [array + 96], r12     ;
    mov [array + 104], r13    ;
    mov [array + 112], r14    ;
    mov [array + 120], r15    ;

    mov rax, [rsp + 5]      ; La idea es que accedamos al rip del momento en el que se llama al comando infoReg, el cual esta disponible en stack
    mov [array + 128], rax    ;

    mov rax, array          ; Retorno el puntero al arreglo
    ret


section .bss
array resq 17
