myfile = open("DBMS\\DBMS_2\\02_myfile.txt","r")
csfile = open("DBMS\\DBMS_2\\02_csfile.txt","w")
A = myfile.read()
myfile.close()
csfile.write(A[:41])
dep = 'CSE'
for i in range(1,len(A)//41):
    idx = 41*i+20
    if A[idx:idx+10]==dep+' '*(10-len(dep)):
        csfile.write(A[41*i:41*(i+1)])
csfile.close()