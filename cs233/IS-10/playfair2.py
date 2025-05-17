message = "".join(input("Enter message: ").upper().split())
pairs = []
modified = ""
j = 0
m = len(message)
while j<m:
    if modified and modified[-1]==message[j]:
        modified += 'X'
        continue
    modified += message[j]
    j += 1
m = len(modified)
if m&1:
    modified += 'X'
    m += 1
for i in range(0,m,2):
    pairs.append(modified[i:i+2])
key = input("Enter key: ").upper()
myset = set()
for i in range(65,91):
    if i==74:
        continue
    myset.add(chr(i))
matrix = [[0,0,0,0,0] for _ in range(5)]
j = 0
for i in key:
    if i in myset:
        matrix[j//5][j%5] = i
        myset.remove(i)
        j += 1
for i in range(65,91):
    if chr(i) in myset:
        matrix[j//5][j%5] = chr(i)
        myset.remove(chr(i))
        j += 1
reverse_indices = {}
for i in range(5):
    for j in range(5):
        reverse_indices[matrix[i][j]] = (i,j)
reverse_indices['J'] = reverse_indices['I']
final = ""
for i,j in pairs:
    i1,i2 = reverse_indices[i]
    j1,j2 = reverse_indices[j]
    if i1==j1:
        final += matrix[i1][(i2+1)%5]
        final += matrix[j1][(j2+1)%5]
    elif i2==j2:
        final += matrix[(i1+1)%5][i2]
        final += matrix[(j1+1)%5][j2]
    else:
        final += matrix[j1][i2]
        final += matrix[i1][j2]
print(final)

'''
H E Y D A
R L I N G
B C F K M
O P Q S T
U V W X Z

ANIMPORTANTMESSAGE
AN IM PO RT AN TM ES XS AG EX
GD FG QP OG GD ZT PD DX GM VD
ANIMPORTANTMESXSAGEX
ANIMPORTANTMESSAGEX
ANIMPORTANTMESXSAGE
ANIMPORTANTMESSAGE
'''