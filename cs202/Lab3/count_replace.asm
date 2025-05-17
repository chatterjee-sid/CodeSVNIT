
;Lab3 -occurance and replace

jmp start

;data


;code
start: nop
lda 0h
mov b,a
lda 1h
mov c,a
lda 2h
mov d,a
mvi e,0h
lxi h,0ah
loop: nop
mov a,m
cmp b
jnz nochange
mov m,c
inr e
nochange: nop
inx h
dcr d
jnz loop
mov a,e
sta 3h
hlt