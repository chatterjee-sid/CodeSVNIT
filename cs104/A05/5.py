# 05. Write a Python program to replace the last value of tuples in a list.
def replace_last(L,val):
    for T in range(len(L)):
        Lx=list(L[T])
        Lx[-1]=val
        L[T]=tuple(Lx)
    return L
List = [(10,20,40),(40,50,60),(70,80,90)]
value = 100
print(List)
print(replace_last(List,value))