lda 0h
sui 1
mov b,a
outerloop: mov c,b
lxi h,1h
innerloop: mov d,m
inx h
mov a,m
cmp d
jnc skip
dcx h
mov m,a
inx h
mov m,d
skip: dcr c
jnz innerloop
dcr b
jnz outerloop
hlt