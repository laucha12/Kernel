GLOBAL cpuVendor
GLOBAL readKey
section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret
;------------------------------------------------
;	Funcion la cual lee de la memoria de teclado
;	la tecla por la cual se interrumpio
;------------------------------------------------
;	Argumentos:
;------------------------------------------------
;	Retorno: numero hexa que representa la tecla
;------------------------------------------------
readKey:
	push rbp
	mov rbp,rsp
	xor rax,rax
.loop:
	in al,64h		 ; preguntar la diferencia de poner 64 h y 0x64
	and al, 0x01     ; Output register 60h should only be read IIF Bit 0 of status port is set to 1.
	cmp al, 0
	je .loop
	in al,60h
	mov rsp,rbp
	pop rbp
	ret