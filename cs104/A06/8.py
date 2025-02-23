#8. Define a function in python that accepts 3 values and returns the maximum of three numbers.
def maxof(a,b,c):
    max=a
    if(b>a):
        max=b
    if(c>max):
        max=c
    return max
A=int(input("Enter first number: "))
B=int(input("Enter second number: "))
C=int(input("Enter third number: "))
print("Maximum of given numbers is",maxof(A,B,C))