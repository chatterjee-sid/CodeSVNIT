#3. Python Program to count the number of digits in a number.
num=int(input("Enter number: "))
digits=0
if num<0:
    num=-num
if num==0:
    digits=1
while num!=0:
    digits+=1
    num//=10
if(digits==1):
    print("There is 1 digit in this number.")
else:
    print("There are",digits,"digits in this number.")