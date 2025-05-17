; perform sorting via bubble sort

dosseg
.model small
.stack 100h

.data
    msg db "Sorted$"

print macro msg
    push ax
    push dx
    mov ah, 09h
    lea dx, msg
    int 21h
    pop dx
    pop ax
endm

.code
start:
    mov ax, @data
    mov ds, ax
    mov cx, 0070H
    mov si, 0010H
outerloop:
    mov bx, cx
innerloop:
    mov ax, word ptr [si]
    cmp ah, al
    jnc nextele
    mov [si], ah
    mov [si+1], al
nextele:
    inc si
    dec bx
    jnz innerloop
    mov si, 0010H
    loop outerloop
    print msg
    mov ax, 4c00h
    int 21h
end start