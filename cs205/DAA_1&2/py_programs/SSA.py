import datetime
def selectionsort(A):
    n = len(A)
    for i in range(n-1):
        for j in range(i+1,n):
            if A[i]>A[j]:
                A[i] = A[i] + A[j]
                A[j] = A[i] - A[j]
                A[i] = A[i] - A[j]

print("Average Case")
for i in range(1,11):
    print("File",i)
    file = open("..\\..\\Files\\File "+str(i)+".txt","r")
    A = list(map(int,file.read().split()))
    file.close()
    start = datetime.datetime.now()
    selectionsort(A)
    end = datetime.datetime.now()
    # for i in A:
    #     print(i,end = ' ')
    Ttime = float((end-start).total_seconds()*1000)
    print("Average case time:",Ttime,"milliseconds")