#Decoding message
from PIL import Image

image = Image.open("short1.png").convert('RGB')
pixels = image.load()

length_bin = ""
for i in range(2):
    r, g, b = pixels[0, i]
    length_bin += str(r & 1)
    length_bin += str(g & 1)
    length_bin += str(b & 1)

length = int(length_bin, 2)

message_bin = ""
index = 0
for i in range(image.size[0]):
    for j in range(image.size[1]):
        if index >= 2:
            r, g, b = pixels[i, j]
            message_bin += str(r & 1)
            message_bin += str(g & 1)
            message_bin += str(b & 1)
        index += 1
        if len(message_bin) >= length * 8:
            break

message_bin = message_bin[:length * 8]
message = ''.join([chr(int(message_bin[i:i + 8], 2)) for i in range(0, length * 8, 8)])

print(message)
