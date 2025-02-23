# 03. Write a Python function that takes two lists and returns True if they have at least one common member.
def ismemcom(L1,L2):
    S1=set(L1)
    S2=set(L2)
    X = S1 & S2
    if len(X)>0:
        return True
    else:
        return False
A=eval(input("Enter List A: "))
B=eval(input("Enter List B: "))
if(ismemcom(A,B)):
    print("Common member exist(s)")
else:
    print("There is no common member")