; check if a string is a substring of another string, strings in memory

lxi h,0000h
lxi d,0050h
mov c,m
xchg
mov b,m
xchg
inx h
inx d

search: ldax d
cmp m
jz next
lxi d,0050h
ldax d
mov b,a
inr b
next: dcr c
jz notfound
dcr b
inx d
inx h
jnz search
lxi d,0050h
ldax d
add c
mov c,a
lxi h,0000h
mov a,m
sub c
sta 00A0h
hlt

notfound: mvi a,0ffh
sta 00A0h
hlt