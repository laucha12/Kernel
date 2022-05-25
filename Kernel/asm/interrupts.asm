
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask
GLOBAL haltcpu
GLOBAL _hlt

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler
GLOBAL _irq06Handler

GLOBAL _exception0Handler

EXTERN irqDispatcher
EXTERN exceptionDispatcher
EXTERN syscalls
SECTION .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

%macro irqHandlerMaster 1

	pushState
    mov r8,%1
	cmp  r8,6
	je .syscallsJump
	mov rdi,r8
	call irqDispatcher
	jmp .fin
.syscallsJump:
	mov rcx,rax
	cmp rax,8
	;je .loadtask
	call syscalls
	jmp .fin
	
;loadtask: ; esto esta bien
;	cmp rsi,2
;	je .loadTask2
;	mov [context_Prim+40],rdi
;	mov [context_Prim+32], rsi
;	mov [context_Prim+24], rdx
;	mov [context_Prim+16], rcx
;	mov  [context_Prim+56],rsp
;	mov rax, [rsp]				 ; guardamos la posicion del RIP del interruptFrame
;	mov [context_Prim+128], rax	 ; lo guardamos en la posicion de memoria 
;	mov rax, [rsp+8]			; tomo del interrupt frame el valor de los flags
;	mov [context_Prim+136], rax	; lo guardo
; void loadTask(int fd, CommandPtr func, int argc, char ** argv)
; rdi: fd / rsi: function pointer / rdx: argc / rcx: argv
.fin:
; signal pic EOI (End of Interrupt)
	mov al, 20h
	out 20h, al
	popState
	iretq
%endmacro



%macro exceptionHandler 1
	pushState

	mov rdi, %1 ; pasaje de parametro
	call exceptionDispatcher

	popState
	iretq
%endmacro

%macro scheduler 1
	cmp byte[cantProcesos],1
	je .fin
	cmp byte [last],2
	je .pushSegunda
	mov [context_Prim], rax
	mov [context_Prim+8], rbx
	mov [context_Prim+16], rcx
	mov [context_Prim+24], rdx
	mov [context_Prim+32], rsi
	mov [context_Prim+40], rdi
	mov [context_Prim+48], rbp
	mov [context_Prim+64], r8
	mov [context_Prim+72], r9
	mov [context_Prim+80], r10
	mov [context_Prim+88], r11
	mov [context_Prim+96], r12
	mov [context_Prim+104], r13
	mov [context_Prim+112], r14
	mov [context_Prim+120], r15
	mov rax, rsp 
	add rax, 0x28				; subimos 0x28 pues debemos subir las posiciones que pusheo antes del la interrupt
	mov [context_Prim+56], rax	; guardamos el valor del RSP
	mov rax, [rsp]				; guardamos la posicion del RIP
	mov [context_Prim+128], rax	; lo guardamos en la posicion de memoria
	mov rax, [rsp+8]			; tomo del interrupt frame el valor de los flags
	mov [context_Prim+136], rax	; lo guardo
	; Recupero el contexto del otro proceso
	mov rax,2
	mov [last],rax
	mov rax, [context_Seg+56]
	mov [rsp+24],rax
	mov rax, [context_Seg+128]
	mov [rsp],rax
	mov rax, [context_Seg+136]
	mov [rsp+8],rax
	mov  rax,[context_Seg]
	mov  rbx,[context_Seg+8]
	mov  rcx,[context_Seg+16]
	mov  rdx,[context_Seg+24]
	mov  rsi,[context_Seg+32]
	mov  rdi,[context_Seg+40]
	mov  rbp,[context_Seg+48]
	mov  r8,[context_Seg+64]
	mov  r9,[context_Seg+72]
	mov  r10,[context_Seg+80]
	mov  r11,[context_Seg+88]
	mov  r12,[context_Seg+96]
	mov  r13,[context_Seg+104]
	mov  r14,[context_Seg+112]
	mov  r15,[context_Seg+120]
	iret
.pushSegunda:
	mov [context_Seg], rax
	mov [context_Seg+8], rbx
	mov [context_Seg+16], rcx
	mov [context_Seg+24], rdx
	mov [context_Seg+32], rsi
	mov [context_Seg+40], rdi
	mov [context_Seg+48], rbp
	mov [context_Seg+64], r8
	mov [context_Seg+72], r9
	mov [context_Seg+80], r10
	mov [context_Seg+88], r11
	mov [context_Seg+96], r12
	mov [context_Seg+104], r13
	mov [context_Seg+112], r14
	mov [context_Seg+120], r15
	mov rax, rsp 
	add rax, 0x28				; subimos 0x28 pues debemos subir las posiciones que pusheo antes del la interrupt
	mov [context_Seg+56], rax	; guardamos el valor del RSP
	mov rax, [rsp]				; guardamos la posicion del RIP
	mov [context_Seg+128], rax	; lo guardamos en la posicion de memoria
	mov rax, [rsp+8]			; tomo del interrupt frame el valor de los flags
	mov [context_Seg+136], rax	; lo guardo
	; Recupero el contexto del otro proceso
	mov rax,1
	mov [last],rax
	mov rax, [context_Prim+56]
	mov [rsp+24],rax
	mov rax, [context_Prim+128]
	mov [rsp],rax
	mov rax, [context_Prim+136]
	mov [rsp+8],rax
	mov  rax,[context_Prim]
	mov  rbx,[context_Prim+8]
	mov  rcx,[context_Prim+16]
	mov  rdx,[context_Prim+24]
	mov  rsi,[context_Prim+32]
	mov  rdi,[context_Prim+40]
	mov  rbp,[context_Prim+48]
	mov  r8,[context_Prim+64]
	mov  r9,[context_Prim+72]
	mov  r10,[context_Prim+80]
	mov  r11,[context_Prim+88]
	mov  r12,[context_Prim+96]
	mov  r13,[context_Prim+104]
	mov  r14,[context_Prim+112]
	mov  r15,[context_Prim+120]
.fin:
	iret
%endmacro


; esta funcion lo que hace es no hacer nada que reciba una interrupt
; esto viene bien para el sleep
_hlt:
	sti
	hlt
	ret

_cli:
	cli
	ret


_sti:
	sti
	ret

picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn


;8254 Timer (Timer Tick)
_irq00Handler:
	irqHandlerMaster 0

;Keyboard
_irq01Handler:
	irqHandlerMaster 1

;Cascade pic never called
_irq02Handler:
	irqHandlerMaster 2

;Serial Port 2 and 4
_irq03Handler:
	irqHandlerMaster 3

;Serial Port 1 and 3
_irq04Handler:
	irqHandlerMaster 4

;USB
_irq05Handler:
	irqHandlerMaster 5
;syscalls
_irq06Handler:
	irqHandlerMaster 6

;Zero Division Exception
_exception0Handler:
	exceptionHandler 0

haltcpu:
	cli
	hlt
	ret



SECTION .bss
	aux resq 1
	last resq 1				; Guardamos el ultimo que fue guardado
	context_Prim resq 17	; Seccion donde se guarda el contexto del primer programa
	context_Seg  resq 17	; Seccion donde se guarda el contexto del segundo programa
	cantProcesos resq 1