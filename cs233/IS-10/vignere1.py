message = input("Enter message w/o spaces: ")
key = input("Enter key: ")
m,n = len(message),len(key)
lockpick = ""
for i in range(m):
    lockpick += key[i%n]
cipher = ""
for i in range(m):
    shift = 0
    change = ord(' ')
    if 64<ord(lockpick[i])<=90:
        shift = (ord(lockpick[i]) - 65)
    elif 96<ord(lockpick[i])<=122:
        shift = (ord(lockpick[i]) - 97)
    if 64<ord(message[i])<=90:
        change = 65 + (ord(message[i]) + shift - 65)%26
    elif 96<ord(message[i])<=122:
        change = 97 + (ord(message[i]) + shift - 97)%26
    cipher += chr(change)
print("Cipher:",cipher)