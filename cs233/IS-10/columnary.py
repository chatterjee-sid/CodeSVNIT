from collections import deque
cipher = input("Enter cipher: ").upper()
key = ''.join(input("Enter key: ").upper().split())
m,n = len(cipher),len(key)
per_letter = m//n
sortedkey = sorted(list(key))
column = {}
j = 0
for i in sortedkey:
    if i not in column:
        column[i] = deque()
    column[i].append(cipher[j:j+per_letter])
    j += per_letter
oldcol = []
for i in key:
    oldcol.append([i,column[i].popleft()])
message = ""
j = 0
for i in range(m):
    message += oldcol[j%n][1][j//n]
    j += 1
possible = [message.rstrip('X')]
xs = m - len(possible[0])
for i in range(xs):
    possible.append(possible[-1]+'X')
print(possible)