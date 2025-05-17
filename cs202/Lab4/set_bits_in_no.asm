lda 0h
mvi e,8
mvi b,0
mvi c,0
nextbit: nop
call bitcheck
dcr e
jnz nextbit
lxi h,1h
mov m,b
inx h
mov m,c
hlt

bitcheck: nop
rlc
jnc reset
inr c
ret
reset: inr b
ret

;0011 1000