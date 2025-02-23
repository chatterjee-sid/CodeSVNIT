#09. Write a Python program to check if a given value is present in a set or not.
S=set(eval(input("Enter elements: ")))
V=int(input("Enter value: "))
if V in S:
    print("Element exists")
else:
    print("Element does not exist")