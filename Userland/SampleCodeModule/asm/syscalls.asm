GLOBAL sysWrite
GLOBAL sysRead
GLOBAL sysTime

section .text

;------------------------------
;   Rutina de asm que realiza 
;   la syscall write
;------------------------------
sysWrite:
    push rbp        ; Stack frame
    mov rbp, rsp    ; Stack frame

    push rbx        ; Preservar rbx

    push rdi        ; buffer
    push rsi        ; fd

    
    ;mov rsi, [2 argumento]     ; buffer
    mov rax,1       ; Numero de syscall
    ;mov rdi,0 [1 argumento]    ; fd
    mov rdx,4       ; Longitud (not supported)
    int 80h         ; "Che kernel"
    
    pop rbx         ; Preservar rbx

    mov rsp, rbp    ; Stack frame
    pop rbp         ; Stack frame

    ret    


;------------------------------
; Rutina de asm que realiza 
; la syscall read
;------------------------------
; Parametro: un char* buffer, que toma solo un caracter de la lectura.
;------------------------------
sysRead:
    push rbp        ; Stack frame
    mov rbp, rsp    ; Stack frame

    push rbx        ; Preservar rbx

    ;mov rsi,[2 argumento]  ; buffer
    mov rax,0       ; Numero de syscall
    ;mov rdi,[1 argumento]  ; fd
    mov rdx,4       ; Longitud (not supported)
    int 80h         ; "Che Kernel"
    
    pop rbx         ; Preservar rbx

    mov rsp, rbp    ; Stack frame
    pop rbp         ; Stack frame
    
    ret


;------------------------------
;   Rutina de asm que realiza 
;   la syscall de obtener la fecha en string buffer
;------------------------------
sysTime:
    push rbp        ; Stack frame
    mov rbp, rsp    ; Stack frame

    push rbx        ; Preservar rbx

    mov rsi, rdi    ; El primer parametro de la funcion lo paso por rsi
    mov rax, 120    ; Numero de syscall
    
    pop rbx         ; Preservar rbx

    mov rsp, rbp    ; Stack frame
    pop rbp         ; Stack frame
    
    ret

