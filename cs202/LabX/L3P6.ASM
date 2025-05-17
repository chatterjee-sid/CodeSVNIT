; delete by position

dosseg
.model small
.stack 100h

.data
    pos db 6
    msg1 db "Element deleted$"
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
    mov bl, 0
    mov si, offset arr
    mov ah, 0
    mov al, pos
    add si, ax
    sub cl, pos
nxtchar:
    mov al, [si+1]
    mov [si], al
    inc si
    loop nxtchar
    print msg1
    mov ax, 4c00h
    int 21h
end start
