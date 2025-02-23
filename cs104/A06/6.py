#6. Python Program to find the sum of series: 1 + 1/2 + 1/3 + ..... + 1/N.
N=int(input("Enter value of N: "))
sum=0
for i in range(1,N+1):
    sum+= (1/i)
print("The sum is %.3f" %sum)