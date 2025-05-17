; binary palindrome check

dosseg
.model small
.stack 100h

.data
    val dw 35ach
    msg1 db "Palindrome$"
    msg2 db "Not $"

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
    mov bx, 0000h
    mov ax, val
    mov cx, 16
    mov bx, 0
thisbit:
    shl bx, 1
    ror ax, 1
    jnc skipadd
    inc bx
skipadd:
    loop thisbit
    cmp bx, val
    jz match
    print msg2
match:
    print msg1
    mov ax, 4c00h
    int 21h
end start