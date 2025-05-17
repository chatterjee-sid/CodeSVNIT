cipher = input("Enter cipher: ")
key = input("Enter key: ")
lockpick = ""
m,n = len(cipher),len(key)
for i in range(m):
    lockpick += key[i%n]
message = ""
for i in range(m):
    shift = 0
    change = ord(' ')
    if 64<ord(lockpick[i])<=90:
        shift = (ord(lockpick[i]) - 65)
    elif 96<ord(lockpick[i])<=122:
        shift = (ord(lockpick[i]) - 97)
    if 64<ord(cipher[i])<=90:
        change = 65 + (ord(cipher[i]) - shift - 65)%26
    elif 96<ord(cipher[i])<=122:
        change = 97 + (ord(cipher[i]) - shift - 97)%26
    message += chr(change)
print("Message:",message)