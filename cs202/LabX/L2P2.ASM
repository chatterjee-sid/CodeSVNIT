; detect if given number is in open interval or not
; detect if given number is in close interval or not (given in comments)

dosseg
.model small
.stack 100h

.data
    lownum dw 2000h
    highnum dw 3000h
    num dw 1500h
    msg db "Result: $"
    yes db "INSIDE$"
    no db "OUTSIDE$"

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
greater:
    mov ax, num
    cmp ax, highnum
    jae ifnot ; use "ja ifnot" for closed interval
lesser:
    cmp ax, lownum
    jbe ifnot ; use "jb ifnot" for closed interval
    print msg
    print yes
    jmp exit
ifnot:
    print msg
    print no
exit:
    mov ax, 4c00h
    int 21h
end start