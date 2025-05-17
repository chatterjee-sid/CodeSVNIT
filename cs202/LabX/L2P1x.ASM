; Find maximum and minimum number from a set of n numbers

dosseg
.model small
.stack 100h

.data
	min db 0FFH
	max db 00H
    arrlen db 00H
	cr equ 0dh
	lf equ 0ah
    msg1 db "Enter number of elements: $"
	msg991 db "Max Element: $"
	res991 db 4 dup('$')
	msg992 db cr,lf,"Min Element: $"
	res992 db 4 dup('$')

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
	mov cx, 13
	mov si, offset arr

check:
	mov al, [si]
	cmp al, min
	jnc maxcheck
	mov min, al
maxcheck:
	mov al, [si]
	cmp al, max
	jc loopend
	mov max, al
loopend:
	inc si
	loop check

	mov ah, 00h
	mov al, max
	mov si, offset res1
	call convert
	mov al, min
	mov si, offset res2
	call convert

	print msg1
	print res1
	print msg2
	print res2

	mov ax, 4c00h
	int 21h

convert proc
	push bx
	push cx
	push dx

	mov bx, 10
	mov cx, 0

storedigit:
	mov dx, 0
	div bx
	push dx
	inc cx
	cmp ax, 0
	jnz storedigit

writedigit:
	pop dx
	add dl, '0'
	mov [si], dl
	inc si
	loop writedigit

	pop dx
	pop cx
	pop bx
	ret
convert endp

end start
