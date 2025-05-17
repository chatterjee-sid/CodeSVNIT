; count set bits

dosseg
.model small
.stack 100h

.data
    val dw 0ffffh
    msg1 db "Set bits: $"

print macro msg
    push ax
    push dx
    mov ah, 09h
    lea dx, msg
    int 21h
    pop dx
    pop ax
endm

printchar macro char
    push ax
    push dx
    mov ah, 02h
    mov dl, char
    int 21h
    pop dx
    pop ax
endm

.code
start:
    mov ax, @data
    mov ds, ax
    mov bl, 0
    mov ax, val
    mov cx, 16
thisbit:
    shl ax, 1
    jnc skipadd
    inc bl
skipadd:
    loop thisbit
    print msg1
    mov bh, 0
    cmp bl, 10
    jc skip
    inc bh
    sub bl, 10
skip:
    add bh, 30H
    add bl, 30H
    printchar bh
    printchar bl
    mov ax, 4c00h
    int 21h
end start