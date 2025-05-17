; delete by value

dosseg
.model small
.stack 100h

.data
    val db 25
    msg1 db "Element deleted$"
    msg2 db "Element does not exist$"
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
    print msg2
    mov ax, 4c00h
    int 21h
exit:
    mov al, [si+1]
    mov [si], al
    inc si
    loop exit
    print msg1
    mov ax, 4c00h
    int 21h
end start
