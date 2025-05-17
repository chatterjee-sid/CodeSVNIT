lda 0h
mov b,a
rlc
rlc
rlc
rlc
sta 1h
lxi h,2h
cmp b
jnz neq
mvi m,1h
hlt
neq: mvi m,0h
hlt