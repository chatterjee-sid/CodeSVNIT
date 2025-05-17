message = ''.join(input("Enter message: ").upper().split())
key = ''.join(input("Enter key: ").upper().split())
columns = []
for i in key:
    columns.append([i,""])
j = 0
m,n = len(message),len(columns)
while j<m:
    columns[j%n][1] += message[j]
    j += 1
while j%n:
    columns[j%n][1] += 'X'
    j += 1
columns.sort(key = lambda e: [e[0],0])
final = ""
for i,j in columns:
    final += j
print("Cipher:",final)