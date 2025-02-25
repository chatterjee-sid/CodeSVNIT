import datetime

def findval(A,val):
    n = len(A)
    for i in range(n):
        if A[i]==val:
            return i
    return -1

print("Worst Case: Element does not exist in array")
for i in range(1,11):
    print("File",i)
    file = open("..\\..\\Files\\File "+str(i)+".txt","r")
    A = list(map(int,file.read().split()))
    file.close()
    Ttime = 0
    for i in range(100):
        start = datetime.datetime.now()
        X = findval(A,-1)
        # if X!=-1:
        #     print("Element found at index",X)
        # else:
        #     print("Element not found in given array")
        end = datetime.datetime.now()
        Ttime += float((end-start).total_seconds()*1000)
    print("Worst case average time:",Ttime/100,"milliseconds")