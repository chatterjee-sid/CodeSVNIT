#5. Python Program to find the power of a number using recursion.
def power(base,exp):
    if(exp==0):
        return 1
    elif(exp>0):
        return base*power(base,exp-1)
    else:
        return power(base,exp+1)/base
base=int(input("Enter Base: "))
exp=int(input("Enter Exponent: "))
print(base,"^",exp,"=",power(base,exp))