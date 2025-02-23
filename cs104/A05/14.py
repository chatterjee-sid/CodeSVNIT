#14. Write a Python program to create a dictionary from a string and the count of the letters from the string.
A=input("Enter string: ")
D={}
for i in A:
    cnt=0
    for j in A:
        if i==j:
            cnt+=1
    D.update({i:cnt})
print(D)