lda 0h
mov b,a
mvi c,0h
mvi e,8h
nextbit: nop
call left
call right
dcr e
jnz nextbit

lxi h,1h
mov m,c
hlt

left: ral
mov b,a
mov a,c
ret

right: rar
mov c,a
mov a,b
ret

;2E -0010 1110
;74 -0111 0100