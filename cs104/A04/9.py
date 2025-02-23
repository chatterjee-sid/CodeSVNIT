#09. WAP to find factorial of a number
A=int(input("Enter number: "))
fact=1
for i in range(1,A+1):
    fact*=i
print(str(A)+"! =",fact)