; Transfer a block of data from one memory location to another

.model small
.stack 100h

.data
src dw 2000H
dst dw 2005H
cnt dw 16

.code
start:
    mov ax, @data
    mov ds, ax

    mov si, [src]
    mov di, [dst]
    mov cx, [cnt]

    ;Compare src and dst to check overlap
    mov ax, si
    cmp ax, di
    jnc front ;if src > dst, use front

    add si, cx
    add di, cx

back:
    dec si
    dec di
    mov al, [si]
    mov [di], al
    loop back
    jmp exit

front:
    mov al, [si]
    mov [di], al
    inc di
    inc si
    loop front

exit:
    mov ax, 4c00h
    int 21h

end start