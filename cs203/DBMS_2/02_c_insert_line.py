myfile = open("DBMS\\DBMS_2\\02_myfile.txt","r")
n = int(input("New record at line no.? "))
newrec = ["7", "Mark", "AI", "65"]
rollno = newrec[0]
name = newrec[1]
dept = newrec[2]
percent = newrec[3]
newrec = rollno+(' '*(10-len(rollno)))+name+(' '*(10-len(name)))+dept+(' '*(10-len(dept)))+percent+'%'+(' '*(9-len(percent)))+'\n'
A = myfile.read()
n = min(n,len(A)//41)
myfile.close()
myfile = open("DBMS\\DBMS_2\\02_myfile.txt","w")
myfile.write(A[:41])
for i in range(1,1+len(A)//41):
    if i<n:
        myfile.write(A[41*i:41*(i+1)])
    elif i>n:
        myfile.write(A[41*(i-1):41*i])
    else:
        myfile.write(newrec)
myfile.close()