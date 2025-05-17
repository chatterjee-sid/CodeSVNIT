
;delete by value

jmp start

;data
;0000h: value
;0002h: no.of elements
;000ah: base address

;code
start: nop
lda 0h
mov b,a
lda 2h
mov c,a
lxi h,0ah
xchg
lxi h,0ah
loop: nop
mov a,m
cmp b
jz skipping
inx d
jmp no_skip
skipping: nop
lda 2h
sui 1h
sta 2h
no_skip: inx h
mov a,m
xchg
mov m,a
xchg
dcr c
jnz loop
hlt