cipher = input("Enter cipher: ").upper()
pairs = []
j = 0
m = len(cipher)
for i in range(0,m,2):
    pairs.append(cipher[i:i+2])
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
raw = ""
for i,j in pairs:
    i1,i2 = reverse_indices[i]
    j1,j2 = reverse_indices[j]
    if i1==j1:
        raw += matrix[i1][(i2-1)%5]
        raw += matrix[j1][(j2-1)%5]
    elif i2==j2:
        raw += matrix[(i1-1)%5][i2]
        raw += matrix[(j1-1)%5][j2]
    else:
        raw += matrix[j1][i2]
        raw += matrix[i1][j2]
print(raw)
possible = [""]
words = 1
Xist = False
if raw[-1]=='X':
    Xist = True
for c in raw:
    if c=='I':
        np = possible.copy()
        for i in range(words):
            np[i] += 'J'
            possible[i] += 'I'
        possible.extend(np)
        words<<=1
    else:
        for i in range(words):
            possible[i] += c
if Xist:
    np = []
    for i in possible:
        np.append(i[:-1])
    possible.extend(np)
print(possible)