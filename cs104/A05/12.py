#12. Write a Python program to remove a key from a dictionary.
D=eval(input("Enter your dictionary: "))
key=int(input("Enter key to remove: "))
D.pop(key)
print(D)