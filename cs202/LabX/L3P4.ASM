; insert value if not exist

dosseg
.model small
.stack 100h

.data
    val db 15
    msg1 db "Element introduced$"
    msg2 db "Element exists$"
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
nxtchar:
    mov al, [si]
    cmp al, val
    jz exit
    inc si
    loop nxtchar
    mov al, val
    mov [si], al
    print msg1
    mov ax, 4c00h
    int 21h
exit:
    print msg2
    mov ax, 4c00h
    int 21h
end start
