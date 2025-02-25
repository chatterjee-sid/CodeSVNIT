import datetime
def bubblesort(arr):
    n = len(A)
    for i in range(n - 1, 0, -1):
        swapped = False
        for j in range(i):
            if A[j]>A[j+1]:
                swapped = True
                A[j] = A[j+1] + A[j]
                A[j+1] = A[j] - A[j+1]
                A[j] = A[j] - A[j+1]
        if not swapped:
            return

print("Best Case: Array is sorted")
for i in range(1,11):
    print("File",i)
    file = open("..\\..\\Files\\File "+str(i)+".txt","r")
    A = list(map(int,file.read().split()))
    file.close()
    A.sort()
    start = datetime.datetime.now()
    bubblesort(A)
    end = datetime.datetime.now()
    # for i in A:
    #     print(i,end = ' ')
    Ttime = float((end-start).total_seconds()*1000)
    print("Best case time:",Ttime,"milliseconds")