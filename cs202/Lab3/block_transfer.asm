
;Lab3 - Data Block Transfer

jmp start

;data


;code
start: nop
lda 0h
mvi b,0h
mov c,a
lhld 1h
xchg
lhld 3h
push d
push h
;find (de) - (hl)
mov a,e
sub l
mov a,d
sbb h
jp back
dad b
dcx h
xchg
dad b
dcx h
xchg
front: nop
ldax d
mov m,a
dcx d
dcx h
dcr c
jnz front
hlt
back: nop
ldax d
mov m,a
inx d
inx h
dcr c
jnz back
hlt