#7.01. Write a Python program that generates random alphabetical characters, alphabetical strings, and alphabetical strings of a fixed length in store it in a text file.
from random import choice
N=int(input("Enter number of characters: "))
alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
s=""
for i in range(N):
    s+=choice(alpha)
f1 = open("1_file.txt","w")
f1.write(s)
print(s,"written in 1_file.txt")
f1.close()