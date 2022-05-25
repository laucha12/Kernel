GLOBAL generateInvalidOpCode


section .text

generateInvalidOpCode:
    push rbp        ; Stack frame
    mov rbp, rsp    ; Stack frame
    

    push rbx        ; Preservar RBX

    UD2

    pop rbx         ; Preservar RBX

    mov rsp, rbp    ; Stack frame
    pop rbp         ; Stack frame
    
    ret