;count vowel and consonant
lxi h, 02h
mov e, m
mov b, m
mvi c, 0
inx h
loop: mov a, m
call vowelchecker
inx h
dcr e
jnz loop
mov a, b
sta 00h
mov a, c
sta 01h
hlt

vowelchecker: nop
cpi 65
rz
cpi 69
rz
cpi 73
rz
cpi 79
rz
cpi 85
rz
cpi 97
rz
cpi 101
rz
cpi 105
rz
cpi 111
rz
cpi 117
rz
dcr b
inr c
ret