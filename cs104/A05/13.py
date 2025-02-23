#13. Write a Python program to create and display all combinations of letters, selecting each letter from a different key in a dictionary.
D={}
for i in range(1,3):
    A=input("Enter elements under key "+str(i)+": ").split(',')
    D.update({i:A})
for i in D[1]:
    for j in D[2]:
        print(i+j)