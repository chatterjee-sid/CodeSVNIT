#Encoding message
from PIL import Image 
#Assuming that secret message is of max 63 characters
image = Image.open('short.png').convert('RGB')
image.save('short1.png')
image.close()

image = Image.open('short1.png').convert('RGB')
pixels = image.load()
width, height = image.size

secret = input("Enter message, only first 63 characters to be considered: ")[:63]
length = len(secret)

binfication = bin(length)[2:].zfill(6)

for i in secret:
    d = ord(i)
    binfication += bin(d)[2:].zfill(8)

q = len(binfication)
if q % 3 == 1:
    binfication += '00'
elif q % 3 == 2:
    binfication += '0'

q = len(binfication)
index = 0
for i in range(width):
    for j in range(height):
        if index >= q:
            break
        r, g, b = pixels[i, j]
        print(r, g, b)
        r = (r & 254) | int(binfication[index])
        g = (g & 254) | int(binfication[index + 1])
        b = (b & 254) | int(binfication[index + 2])
        pixels[i, j] = (r, g, b)
        index += 3

image.save('short1.png')
image.close()
