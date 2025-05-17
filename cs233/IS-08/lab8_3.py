from PIL import Image
image = Image.open('short.png').convert('RGB')
stego = Image.open('short1.png').convert('RGB')
width,height = image.size
pixels = image.load()
pixels1 = stego.load()
squarediffsum = 0
cnt1 = cnt2 = 0
cn1 = cn2 = 0
for i in range(width):
    for j in range(height):
        r,g,b = pixels[i,j]
        r1,g1,b1 = pixels1[i,j]
        # error = r^r1 + g^g1 + b^b1
        # if error:
        #     cn1 += 1
        error1 = abs(r-r1) + abs(g-g1) + abs(b-b1)
        # if error1:
        #     cn2 += 1
        # cnt1 += error
        # cnt2 += error1
        squarediffsum += error1*error1
print(cnt1, cnt2)
print(cn1, cn2)
MSE = squarediffsum/width/height
print("MSE: {}".format(MSE))