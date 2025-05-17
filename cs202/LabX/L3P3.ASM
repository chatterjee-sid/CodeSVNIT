; insert at position

dosseg
.model small
.stack 100h

.data
    msg db "Element introduced$"
    val db 15
    pos db 6
    arr db 22, 17, 45, 25, 13, 30, 35, 24, 39, 38

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
    mov cx, 10
    sub cl, pos
    mov bl, 0
    mov si, offset arr
    add si, 10
    cmp cx, 0
    jz stop
nxtchar:
    mov al, [si-1]
    mov [si], al
    dec si
    loop nxtchar
stop:
    mov al, val
    mov [si], al
    print msg
    mov ax, 4c00h
    int 21h
end start
