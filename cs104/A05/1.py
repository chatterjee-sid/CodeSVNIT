# 01. Write a Python program to sum all the items in a list.
# a. Write a Python program to multiply all the items in a list.
# b. Write a Python program to get the largest number from a list.
# c. Write a Python program to get the smallest number from a list.
L=[3,8,7,1,6,4,2,10,9,5]
sum=0
prod=1
max=L[0]
min=L[0]
for i in L:
    sum+=i
    prod*=i
    if i>max:
        max=i
    elif i<min:
        min=i
print("Sum:",sum)
print("Product:",prod)
print("Max:",max)
print("Min:",min)