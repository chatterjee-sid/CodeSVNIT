;8b x 8b multiplication
lxi h, 00h
lda 01h
mov c, m
mvi e, 08h
shiftandadd: rlc ;8bit leftshift
jnc skipadd
dad b ;ifvalid-add
skipadd: dcr e
jz stop
dad h ;16bit leftshift
jnc shiftandadd
push psw ;addifcarry
mov a, l
adi 1
mov l, a
pop psw
jmp shiftandadd
stop: shld 02h
hlt

;8bitleftshift
;ifvalid-add
;16bitleftshift
;addifcarry

;00001101
;00001100
;00001000 00000000

;000 111
;001 110
;010 101