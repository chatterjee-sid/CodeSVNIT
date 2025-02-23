#4. Python Program to find the factorial of a number with and without using recursion.
#With Recursion
def factorial(a):
    if a==1:
        return 1
    else:
        return a*factorial(a-1)
num=int(input("Enter number: "))
print("Factorial of",num,"is",factorial(num))