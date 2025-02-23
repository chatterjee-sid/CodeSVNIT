#1. Given a number N, and we have to generate a dictionary that contains numbers and their squares (i, i*i) using Python.
N = int(input("Enter number N: "))
D={}
for i in range(1,N+1):
    D.update({i:i*i})
print(D)