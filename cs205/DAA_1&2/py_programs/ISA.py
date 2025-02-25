import datetime
def insertionsort(arr):
    n = len(A)
    for i in range(1, n):
        key = A[i]
        j = i
        while j>0 and A[j-1]>key:
            A[j] = A[j-1]
            j = j-1
        A[j] = key

print("Worst Case: Array is reverse-sorted")
for i in range(1,11):
    print("File",i)
    file = open("..\\..\\Files\\File "+str(i)+".txt","r")
    A = list(map(int,file.read().split()))
    file.close()
    start = datetime.datetime.now()
    insertionsort(A)
    end = datetime.datetime.now()
    # for i in A:
    #     print(i,end = ' ')
    Ttime = float((end-start).total_seconds()*1000)
    print("Worst case time:",Ttime,"milliseconds")