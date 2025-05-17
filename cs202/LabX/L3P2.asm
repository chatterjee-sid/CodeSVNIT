; Count number of occurances of a number in an array range, and replace each occurance of it with a given number

dosseg
.model small
.stack 100h

.data
    matchnum db 5
    replaced db 3
    arr db 2,5,1,5,4,5,5,4,1,1
    msg db "Count of nums matched: $"

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
nextchar:
    mov al, [si]
    cmp al, matchnum
    jne skip
    mov al, replaced
    mov [si], al
    inc bl
skip:
    inc si
    loop nextchar
    add bl, 30H
    print msg
    mov ah, 02h
    mov dl, bl
    int 21h
    mov ax, 4c00h
    int 21h
end start