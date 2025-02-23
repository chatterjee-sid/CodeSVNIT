#08. WAP to find the largest of three numbers
L=[]
for i in range(3):
    A=int(input("Enter number "+str(i+1)+": "))
    L.append(A)
max=L[0]
if L[1]>max:
    max=L[1]
if L[2]>max:
    max=L[2]
print("Max:",max)