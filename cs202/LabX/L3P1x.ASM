; Transfer a block of data from one memory location to another

.model small
.stack 100h

.data
msg1 db "Enter 4 digit hex src address (all caps): $"
msg2 db 0ah, 0dh, "Enter 4 digit hex dst address (all caps): $"
msg3 db 0ah, 0dh, "Enter number of bytes to transfer (max 65535): $"
rcv db 6
rcv_len db 5 dup(?)

print macro msg
    mov ah, 09h
    lea dx, msg
    int 21h
endm

.code
start:
    mov ax, @data
    mov ds, ax

    print msg1
    call scan
    call cnvhex
    mov si, ax 

    print msg2
    call scan
    call cnvhex
    mov di, ax

    print msg3
    call scan
    call cnvdec
    mov cx, ax

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

scan proc
    mov ah, 0ah
    lea dx, rcv
    int 21h
    ret
scan endp

cnvhex proc
    push cx
    push dx
    push si
    mov si, offset rcv + 2  ; input starts after first two bytes
    mov ax, 0
    mov cx, 4
readhex:
    mov dl, [si]
    cmp dl, '$'
    jz endhex
    cmp dl, 'A'
    jc lessthanA
    sub dl, 37h
    jmp updateax
lessthanA:
    sub dl, 30h
updateax:
    push cx
    mov cl, 4
    shl ax, cl
    pop cx
    add al, dl
    inc si
    loop readhex
endhex:
    pop si
    pop dx
    pop cx
    ret
cnvhex endp

cnvdec proc
    push cx
    push dx
    push si
    mov si, offset rcv + 2  ; input starts after first two bytes
    mov ax, 0
    mov cx, 5
readdec:
    mov dl, [si]
    cmp dl, '$'
    jz enddec
    sub dl, 30h
    mov bx, ax
    mov ax, 10
    mul bx
    add ax, dx
    inc si
    loop readdec
enddec:
    pop si
    pop dx
    pop cx
    ret
cnvdec endp

end start
