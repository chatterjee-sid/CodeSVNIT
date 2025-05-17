; palindrome in hex

dosseg
.model small
.stack 100h

.data
    val db 55h
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
    mov al, val
    mov cl, 4
    ror al, cl
    cmp al, val
    jz pal
    print msg2
pal:
    print msg1
    mov ax, 4c00h
    int 21h
end start