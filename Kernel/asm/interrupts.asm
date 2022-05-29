
GLOBAL _cli
GLOBAL _sti
GLOBAL _hlt

GLOBAL initialiseContextSchedluer

GLOBAL picMasterMask
GLOBAL picSlaveMask
GLOBAL movCero

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler
GLOBAL _irq06Handler

GLOBAL _exception0Handler
GLOBAL _exception06Handler

EXTERN int_21
EXTERN ncPrintFD0
EXTERN irqDispatcher
EXTERN exceptionDispatcher
EXTERN syscalls
EXTERN loadProces
EXTERN exitProces
EXTERN switchContext
EXTERN initialiseContextSchedluerEngine

SECTION .text

initialiseContextSchedluer:
	mov byte [contextOwner],0
	call initialiseContextSchedluerEngine
	ret

;-------------------------------------------------------------------------------
; Almaceno el contexto del proceso actual (definido como todos los registros 
; generales, asi como el RIP y los registros de flag) a la posicion de memoria
;-------------------------------------------------------------------------------
; Argumento: posicion de memoria a donde copiar el contexto
;-------------------------------------------------------------------------------
%macro pushContext 1

	;pusheo los registros generales a la posicion pasada como argumentos
	mov [%1], rax
	mov [%1+8], rbx
	mov [%1+16], rcx
	mov [%1+24], rdx
	mov [%1+32], rsi
	mov [%1+40], rdi
	mov [%1+48], rbp
	; un hueco de un registro 
	mov [%1+64], r8
	mov [%1+72], r9
	mov [%1+80], r10
	mov [%1+88], r11
	mov [%1+96], r12
	mov [%1+104], r13
	mov [%1+112], r14
	mov [%1+120], r15

	;-----------------------------------------------------------------------
	; pusheo los registros especiales, al entrar aca voy a tener el rsp
	; -------------------------------------
	;  error code   						 
	; -------------------------------------
	;  Instruction Pointer (RIP - 8 bytes)      <= rsp
	; -------------------------------------
	;  Code Segment (CS - 2 bytes)        
	; -------------------------------------
	;  Register Flags (RFLAGS - 8 bytes) 
	; -------------------------------------
	;  Stack Pointer (RSP - 8 bytes)       
	; -------------------------------------
	;  Stack Segment (SS - )
	; -------------------------------------

	mov rax, [rsp+18]			; almaceno el valor del RSP de la interrupcion en rax
	mov [%1+56], rax	        ; guardamos el valor del RSP en la tabla de contexto 
	mov rax, [rsp]				; guardamos la posicion del RIP
	mov [%1+128], rax	        ; lo guardamos en la posicion de memoria
	mov rax, [rsp+10]			; tomo del interrupt frame el valor de los flags
	mov [%1+136], rax	        ; lo guardo
%endmacro

;-------------------------------------------------------------------------------
; Recupero el contexto del proceso (definido como todos los registros 
; generales, asi como el RIP y los registros de flag)cuyo contexto almacene  a
; la posicion de memoria recibida como parametro
;-------------------------------------------------------------------------------
; Argumento: posicion de memoria a donde copiar el contexto
;-------------------------------------------------------------------------------
%macro popContext 1
	
	;popeo los registros especiales
	mov rax, [%1+56]					; almaceno en rax el valor que almacene de RSP de la interrupcion
	mov [rsp+18],rax					; piso la posicion del 
	mov rax, [%1+128]
	mov [rsp],rax
	mov rax, [%1+136]
	mov [rsp+10],rax

	;popeo los registros generales
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

;-------------------------------------------------------------------------------
; Recibe una posicion de memoria desde la cual va a comenzar el stack frame de mi 
; funcion
;-------------------------------------------------------------------------------
%macro loadTask 1
	
	; ---- REGISTROS PUSHEADOS 			<= rsp
	; ---- STACK INTERRUPCION
	; ebp
	; ret
	; donde REGISTROS PUSHEADOS son 15 registros de 8 bytes, por lo tanto ocupan 120 bytes en mi stack
	; Por lo tanto rsp + 120 apunta al principio de mi stack de interrupcion
	; por ultimo, rsp + 120 + 10 apunta al registro de flags

	mov [%1+40], rsi		; alamceno el int fd como primer parametro de mi funcion a loadear
	mov [%1+32], rdx		; alamceno el int argc como primer parametro de mi funcion a loadear
	mov [%1+24], rcx		; alamceno el char ** argv como primer parametro de mi funcion a loadear
	mov [%1+56], rax		; seteo donde va a arrancar el stack de mi funcion A CHEQUEAR
	mov [%1+128], rdi	 	; alamceno el puntero al comienzo de mi funcion.
	mov r15, [rsp + 130]	; almaceno el registro de flags
	mov [%1+136], r15 		; lo copio a la posicion donde despues pusheo mi context
%endmacro

;-------------------------------------------------------------------------------
; Hace una copia de todos los registros generales en el stack frame donde es llamada,
; para preservarlos.
;-------------------------------------------------------------------------------
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

;-------------------------------------------------------------------------------
; Recupera todos los registros generales pusheados anteriormente al stack
;-------------------------------------------------------------------------------
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


;-------------------------------------------------------------------------------
; exitSyscall - ejecuta el borrado del proceso desde donde se llamo de la tabla
; de procesos para el context switching
;-------------------------------------------------------------------------------
; @argumentos:  
;-------------------------------------------------------------------------------
exitSyscall:
	mov rdi,contextHolder				; paso el primer parametro para copiar el siguiente contexto
										; al exitear el proceso actual
	mov rsi,contextOwner			    ; paso el segundo parametro para actualizar duenio del contexto
										; que estoy copiando al context holder
	call exitProces						; llamo a la funcion de C que maneja el exit
	mov al, 20h							; signal pic EOI
	out 20h, al							; signal pic EOI
	popContext contextHolder			; actualizo el contexto actual al del proximo proceso a ejecutar
	call _sti
	iretq								; desarmo el stack frame de la interrupcion y hago el ret al proximo proceso

;-------------------------------------------------------------------------------
; loadtaskHandler - ejecuta el borrado del proceso desde donde se llamo de la tabla
; de procesos para el context switching
;-------------------------------------------------------------------------------
; @argumentos:  
;-------------------------------------------------------------------------
loadtaskHandler:
	loadTask contextLoading 	; rsp+16 estan los 
	mov rdi, contextLoading
	call loadProces
	popState
	popContext contextLoading
	call _sti
	iretq

;-------------------------------------------------------------------------------
; Recibe un numero que determina el numero de interrupcion por hardware y mapea
; a la funcion que maneja esa interrupcion
;-------------------------------------------------------------------------------
%macro irqHandlerMaster 1
	call _cli					; desactivamos las interrupciones
	pushState					; pusheamos todos los registros para preservarlos
    mov r8,%1					; almaceno el numero de la interrupcion 
	cmp  r8,6					; comparo 6 a ver si es una interrupcion de software
	je .syscallsJump			; 
	mov rdi,r8
	call irqDispatcher
	endHardwareInterrupt

.syscallsJump:
	cmp rax,8					; ahora comienzo el switch de las syscalls, 
	je loadtaskHandler			; si es 8 es la de loadTask
	cmp rax,99					; si es 99 es la de exit
	je exitSyscall
	mov rcx,rax					; si es otro entonces voy al switch de C
	call syscalls						
	endSoftwareInterrupt						
	
%endmacro

;-------------------------------------------------------------------------------
;  endInterrupt - recupero los registros pusheados al stack, 
; habilita interrupciones y desarma el stack de interrupcion 
;-------------------------------------------------------------------------------
%macro endInterrupt 0
	popState
	call _sti
	iretq
%endmacro

;-------------------------------------------------------------------------------
;  endHardwareInterrupt - comunico al PIC termino la interrupcion de hardware a
;  traves el I/0  los registros pusheados al stack, 
;  habilita interrupciones y desarma el stack de interrupcion 
;-------------------------------------------------------------------------------
%macro endHardwareInterrupt 0
	mov al, 20h
	out 20h, al
	endInterrupt
%endmacro

;--------------------------------------------------------
;
;--------------------------------------------------------
; Argumentos 
;--------------------------------------------------------
%macro exceptionHandler 1
	
	;pushState

	call copyRegs				; Llamo a la macro que me copia los registros en regsArray
	mov rdi, %1 				; Pasaje de 1 parametro -> Tipo de excepciom
	mov rsi, regsArray			; Pasaje de 2 parametro - > Arreglo de registros asi los imprimo desde C
	call exceptionDispatcher	; Llamo al que maneja la excepcion en particular

	;popState


	; !! Esto esta mal, hay que sentarse a ver como implementamos la vuelta al proceso/shell
	;mov rax, [rsp]					; Paso a RAX la copia del RIP donde ocurrio la excepcion
	;inc rax							; Incremento el RIP en uno, para que continue con la ejecuccion del programa
	;mov [rsp], rax					; Actualizo el RIP en el stack (Donde se saltara)
	
;-------------------------------------------------------------------------------
;  endSoftwareInterrupt - recupero los registros pusheados al stack, 
; habilita interrupciones y desarma el stack de interrupcion 
;-------------------------------------------------------------------------------
%macro endSoftwareInterrupt 0
	endInterrupt
%endmacro

;--------------------------------------------------------
; 
;--------------------------------------------------------
; Argumentos: -
;--------------------------------------------------------
;%macro exceptionHandler 1
;	pushState							; preservo los registros
;	mov rdi, %1 					
;	call exceptionDispatcher
;	popState							; preservo los registros
;	iretq
;%endmacro

;-------------------------------------------
; 
;--------------------------------------------------------
; Argumentos: -
;--------------------------------------------------------
%macro timerTickHandler 1
	call _cli						; desactivo interrupciones
	pushContext contextHolder		; pusheo el contexto actual al contextHolder
	mov rdi, contextHolder			; pusheo como primer argumento el puntero al contexto actual
	mov rsi, contextOwner			; pusheo como segundo parametro el puntero 
	call switchContext				; llamo a la funcion de C que me va a guardar el contexto y copiar el siguiente
	mov al, 20h						; Indicamos al PIC que termino la interrupcion
	out 20h, al						; Indicamos al PIC que termino la interrupcion
	popContext contextHolder		; copio el context holder a mis registros
	call _sti						; activo interrupciones
	iretq

%endmacro


;--------------------------------------------------------
; keyBoardHandler - Esta funcion seteo en 0 el flag de responder a interrupciones
; maskeables y luego hace un hlt -> hace un sleep del micro
;--------------------------------------------------------
;	Argumentos: No recibe, pues solo se utiliza para una 
;	interrupcion.
;--------------------------------------------------------
%macro keyBoardHandler 1
	cli
	call int_21
	sti
	mov al, 20h
	out 20h, al
	iretq
%endmacro

;--------------------------------------------------------
;	DEBUGGING
;--------------------------------------------------------
%macro nothing 1
	mov al, 20h
	out 20h, al
	iretq
%endmacro

;--------------------------------------------------------
; Esta funcion seteo en 0 el flag de responder a interrupciones
; maskeables y luego hace un hlt -> hace un sleep del micro
;--------------------------------------------------------
; Argumentos: -
;--------------------------------------------------------
_hlt:
	cli
	hlt
	ret

;--------------------------------------------------------
; Desabilita las interrupciones (setea el flag
; de interrupciones de hardware en cero)
; "External interrupts disabled at the end of the cli instruction 
; or from that point on until the interrupt flag is set."
;--------------------------------------------------------
; Argumentos: -
;--------------------------------------------------------
_cli:
	cli
	ret

;--------------------------------------------------------
; Habilita las interrupciones (setea el flag
; de interrupciones de hardware en cero)
;--------------------------------------------------------
; Argumentos: -
;--------------------------------------------------------
_sti:
	sti
	ret

;--------------------------------------------------------
; Esta funcion seteo la mascara del pic de interrupciones
; en base a su argumento
;--------------------------------------------------------
; Argumentos: un numero de 8 bits donde el n-esimo bit representa
; si el pin n del pic responde o no a interrupciones (0 si responder
; 1 sino)
;--------------------------------------------------------
picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h, al
    pop rbp
    retn

;--------------------------------------------------------
; Esta funcion seteo la mascara del pic en cascada con el pic master
;--------------------------------------------------------
; Argumentos: un numero de 8 bits donde el n-esimo bit representa
; si el pin n del pic responde o no a interrupciones (0 si responder
; 1 sino)
;--------------------------------------------------------
picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn


;--------------------------------------------------------------------
; FUNCIONES GLOBALES
;--------------------------------------------------------------------

; -----------------------------------------------------
; 8254 Timer (Timer Tick)
; -----------------------------------------------------
_irq00Handler:
	timerTickHandler 0

; -----------------------------------------------------
; Keyboard
; -----------------------------------------------------
_irq01Handler:
	keyBoardHandler 1
; -----------------------------------------------------
; Syscalls
; -----------------------------------------------------
_irq06Handler:
	irqHandlerMaster 6

;--------------------------------------------------------------------
;Cascade pic never called
;-----------------------------------------------------
_irq02Handler:
	irqHandlerMaster 2

;-----------------------------------------------------
;Serial Port 2 and 4
;-----------------------------------------------------
_irq03Handler:
	irqHandlerMaster 3

;-----------------------------------------------------
;Serial Port 1 and 3	
;-----------------------------------------------------
_irq04Handler:
	irqHandlerMaster 4

;-----------------------------------------------------
;	USB
;-----------------------------------------------------
_irq05Handler:
	irqHandlerMaster 5

;-----------------------------------------------------
;	Zero Division Exception
;-----------------------------------------------------
_exception0Handler:
	exceptionHandler 0

;Zero Division Exception
_exception06Handler:
	exceptionHandler 6


;-----------------------------------------------------
;	BSS
;-----------------------------------------------------
SECTION .bss
	aux resq 1
	;-----------------------------------------------------
	;	Seccion donde se guarda el contexto para la comunicacion con el back
	;-----------------------------------------------------
	contextHolder resq 17			
	;----------------------------------------------------
	;	Guardo el duenio del contexto
	;-----------------------------------------------------
	contextOwner db 0		
	;-----------------------------------------------------
	;	Seccion donde se guarda el contexto para la comunicacion con el back
	;-----------------------------------------------------
	contextLoading resq 17			
	;-----------------------------------------------------
	;	*DEBUGGING*
	;-----------------------------------------------------
	string db "HOLLAAA",0
