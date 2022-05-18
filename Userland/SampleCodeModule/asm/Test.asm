GLOBAL chau
section .data
    hola db "hola como va",0
section .text

chau:
    mov rax,4
    mov rdi,2
    mov rsi,hola
    mov rdx,4
    int 80h
    ret
