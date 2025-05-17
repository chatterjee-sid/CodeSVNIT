
;insert value at position

jmp start

;data
;0000h: value
;0001h: index
;0002h: no.of elements
;000Ah: base of list

;code
start: nop
lda 0h
mov b,a
lda 1h
mov c,a
lda 2h
mov d,a
lxi h,0ah
push d
reach_end: nop
inx h
dcr d
jnz reach_end
pop d
mov a,d
sub c
adi 1h
mov d,a
shift: nop
dcx h
mov a,m
inx h
mov m,a
dcx h
dcr d
jnz shift
mov m,b
lda 2h
adi 1h
sta 2h
hlt