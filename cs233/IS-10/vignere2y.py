def shifter(char):
    if 64<ord(char)<=90:
        return ord(char)-65
    elif 96<ord(char)<=122:
        return ord(char)-71
    elif char==' ':
        return 52
def backshifter(num):
    if num<26:
        return chr(num+65)
    elif num<52:
        return chr(num+71)
    else:
        return ' '
cipher = input("Enter cipher: ")
key = input("Enter key: ")
m,n = len(cipher),len(key)
message = ""
for i in range(m):
    p = shifter(cipher[i])
    q = shifter(key[i%n])
    change = p-q
    x = backshifter(change%53)
    message += x
print("message:",message)