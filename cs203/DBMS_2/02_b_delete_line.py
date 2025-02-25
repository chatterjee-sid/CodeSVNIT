myfile = open("DBMS\\DBMS_2\\02_myfile.txt","r")
n = int(input("Delete record where roll_no =? "))
A = myfile.read()
myfile.close()
myfile = open("DBMS\\DBMS_2\\02_myfile.txt","w")
myfile.write(A[:41])
for i in range(41,len(A),41):
    if A[i]==str(n):
        continue
    myfile.write(A[i:i+41])
myfile.close()