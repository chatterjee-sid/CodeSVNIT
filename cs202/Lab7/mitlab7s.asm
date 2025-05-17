; check if a string is a substring of another string, strings taken via I/O
in 80h
mov c,a
mov e,a
lxi h,100h
substring: in 80h
mov m,a
inx h
dcr c
jnz substring

in 80h
mov b,a
mov d,a
mov c,e
lxi h,100h

search: in 80h
cmp m
jz next
lxi h,100h
mov c,e
inr c
next: dcr b
jz notfound
dcr c
jnz search
mov a,e
add b
mov b,a
mov a,d
sub b
out 81h
hlt

not found: mvi a,0ffh
out 81h
hlt