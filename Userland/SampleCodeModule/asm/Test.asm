GLOBAL sysWriteTest
GLOBAL sysReadTest
GLOBAL sysTimeTest
GLOBAL sysOpenTest
GLOBAL sysExit
section .data
    hola db "hola como va",0
section .text
;-----------------------------
;   Funcion para testear la syscalls de write
;-----------------------------
;   Argumentos: char [] buffer
;   Return: void
;-----------------------------
sysWriteTest:
    mov rax,1
    mov rdx,4
    int 80h
    ret
;----------------------------
;   Funcion para testear la syscall de read
;----------------------------
;   Argumentos: Putero a char
;   Retorno: void
;----------------------------
sysReadTest:
    mov rsi,rdi
    mov rax,0
    mov rdi,2
    mov rdx,4
    int 80h
    ret
sysOpenTest:
    mov rax,2
    int 80h
    ret
sysExit:
    mov rax,3
    int 80h
    ret
sysTimeTest:
   mov rsi,rdi
    mov rax,120
;    mov rdi,2
;    mov rdx,4
    int 80h
    ret