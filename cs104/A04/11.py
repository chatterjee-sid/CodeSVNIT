#11. WAP to check if a number is perfect or not
num=int(input("Enter number: "))
sum=0
for i in range(1,num):
    if num%i==0:
        sum+=i
if num==sum:
    print("Perfect")
else:
    print("Not perfect")