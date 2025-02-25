import datetime
for i in range(1,11):
    print("File",i)
    file = open("..\\..\\Files\\File "+str(i)+".txt","r")
    A = list(map(int,file.read().split()))
    file.close()
    Ttime = 0
    start = datetime.datetime.now()
    A.sort()
    end = datetime.datetime.now()
    Ttime += float((end-start).total_seconds()*1000)
    print("Average case average time:",Ttime/100,"milliseconds")
    Ttime = 0
    start = datetime.datetime.now()
    A.sort()
    end = datetime.datetime.now()
    Ttime += float((end-start).total_seconds()*1000)
    print("Best case average time:",Ttime/100,"milliseconds")
    A.sort(reverse=True)
    Ttime = 0
    start = datetime.datetime.now()
    A.sort()
    end = datetime.datetime.now()
    Ttime += float((end-start).total_seconds()*1000)
    print("Worst case average time:",Ttime/100,"milliseconds")
