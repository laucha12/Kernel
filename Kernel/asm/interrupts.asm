
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask
GLOBAL haltcpu
GLOBAL _hlt
GLOBAL movCero

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler
GLOBAL _irq06Handler

GLOBAL _exception0Handler

EXTERN int_21
EXTERN ncPrintFD0
EXTERN irqDispatcher
EXTERN exceptionDispatcher
EXTERN syscalls
EXTERN loadProces
EXTERN exitProces
EXTERN switchContext
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
%macro pushContext 1
	mov [%1], rax
	mov [%1+8], rbx
	mov [%1+16], rcx
	mov [%1+24], rdx
	mov [%1+32], rsi
	mov [%1+40], rdi
	mov [%1+48], rbp
	mov [%1+64], r8
	mov [%1+72], r9
	mov [%1+80], r10
	mov [%1+88], r11
	mov [%1+96], r12
	mov [%1+104], r13
	mov [%1+112], r14
	mov [%1+120], r15
	mov rax, [rsp+24]
	mov [%1+56], rax	        ; guardamos el valor del RSP
	mov rax, [rsp]				; guardamos la posicion del RIP
	mov [%1+128], rax	        ; lo guardamos en la posicion de memoria
	mov rax, [rsp+16]			; tomo del interrupt frame el valor de los flags
	mov [%1+136], rax	        ; lo guardo
%endmacro
%macro popContext 1
	mov rax, [%1+56]
	mov [rsp+24],rax
	mov rax, [%1+128]
	mov [rsp],rax
	mov rax, [%1+136]
	mov [rsp+16],rax
	mov  rax,[%1]
	mov  rbx,[%1+8]
	mov  rcx,[%1+16]
	mov  rdx,[%1+24]
	mov  rsi,[%1+32]
	mov  rdi,[%1+40]
	mov  rbp,[%1+48]
	mov  r8,[%1+64]
	mov  r9,[%1+72]
	mov  r10,[%1+80]
	mov  r11,[%1+88]
	mov  r12,[%1+96]
	mov  r13,[%1+104]
	mov  r14,[%1+112]
	mov  r15,[%1+120]
%endmacro
%macro loadTask 1
		
	mov [%1+40], rsi		; alamceno el int fd como primer parametro de mi funcion a loadear
	mov [%1+32], rdx		; alamceno el int argc como primer parametro de mi funcion a loadear
	mov [%1+24], rcx		; alamceno el char ** argv como primer parametro de mi funcion a loadear
	mov [%1+56],rax		    ; seteo donde va a arrancar el stack de mi funcion A CHEQUEAR
	mov [%1+128], rdi	 	; alamceno el puntero al comienzo de mi funcion.

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
	cmp rax,8
	je .loadtaskHandler
	cmp rax,99
	je .exitSyscall
	mov rcx,rax
	call syscalls
	jmp .fin

.loadtaskHandler:
	loadTask contextLoading ; asumimos que copio bien
	mov rdi, contextLoading
	call _cli
	call loadProces
	mov al, 20h
	out 20h, al
	popState
	popContext contextLoading
	call _sti
	iretq

; Maneja la interrupcion al sistema operativo de exit
.exitSyscall:
	mov rdi,contextHolder				; paso el primer parametro para copiar el siguiente contexto
										; al exitear el proceso actual
	mov rsi,contextOwner			    ; paso el segundo parametro para actualizar duenio del contexto
										; que estoy copiando al context holder
	call exitProces						; llamo a la funcion de C que maneja el exit
	mov al, 20h							; signal pic EOI
	out 20h, al							; signal pic EOI
	popContext contextHolder									; actualizo el contexto actual al del proximo proceso a ejecutar
	iretq								; desarmo el stack frame de la interrupcion y hago el ret al proximo proceso

.fin:
; signal pic EOI (End of Interrupt) ES NECESARIO CUANDO HAGO INTERRUPCIONES POR SOFTWARE
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
	call _cli
	pushContext contextHolder		; pusheo el contexto actual al contextHolder
	mov rdi, contextHolder			; pusheo como primer argumento el puntero al contexto actual
	mov rsi, contextOwner			; pusheo como segundo parametro el puntero 
	call switchContext				; llamo a la funcion de C que me va a guardar el contexto y copiar el siguiente
	mov al, 20h
	out 20h, al
	popContext contextHolder		; copio el context holder a mis registros
	call _sti
	iret
%endmacro
%macro teclado 1
	call int_21
	iretq
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
movCero:
	mov dword [contextOwner],0
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
    out		0A1h,al
    pop     rbp
    retn


;8254 Timer (Timer Tick)
_irq00Handler:
	scheduler 0

;Keyboard
_irq01Handler:
	teclado 1

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
	contextHolder resq 17			; Seccion donde se guarda el contexto para la comunicacion con el back
	contextOwner resq 1		; guardo el duenio del contexto
	contextLoading resq 17			; Seccion donde se guarda el contexto para la comunicacion con el back
	string db "HOLLAAA",0