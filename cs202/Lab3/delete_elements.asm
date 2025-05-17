
;delete by position

jmp start

;data
;0001h: position
;0002h: no.of elements
;000ah: base address

;code
start: nop
lda 1h
mov b,a
lda 2h
sui 1h
sta 2h
adi 1h
sub b
mov c,a
lxi h,0ah
search: nop
dcr b
inx h
jnz search
replace: nop
inx h
mov a,m
dcx h
mov m,a
inx h
dcr c
jnz replace
hlt