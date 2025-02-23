#10. Write a Python program to remove all duplicates from a given list of strings and return a list of unique strings. Use the Python set data type.
L=input("Enter list of strings: ").split(',')
L=list(set(L))
print(L)