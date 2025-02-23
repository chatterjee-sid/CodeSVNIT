#1. Python Program to count the number of vowels in a string.
string=input("Enter string: ")
count=0
for letter in string:
    if letter in "AEIOUaeiou":
        count+=1
print("There are",count,"vowels in this string.")