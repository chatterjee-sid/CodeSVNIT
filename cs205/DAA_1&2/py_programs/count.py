for i in range(1,11):
    file = open("..\\..\\Files\\File "+str(i)+".txt","r")
    A = list(map(int,file.read().split()))
    file.close()
    print("No. of entries in File",i,"=",len(A))