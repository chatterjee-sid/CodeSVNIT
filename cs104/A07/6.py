#7.06. Your local university's CSE club maintains a register of its active members on a .txt document. Every month they update the file by removing the members who are not active.
#Given the file currentMember, Remove each member with a 'no' in their Active column. Keep track of each of the removed members and append them to the exMember file. Make sure that the format of the original files in preserved.
import os
f1=open("6_file.txt","r")
f2=open("6_file1.txt","w")
header=f1.readline()
f2.write(header)
read=f1.readlines()
for row in read:
    if row[40:]=="Yes\n":
        f2.write(row)
f1.close()
f2.close()
print("Done")
os.remove("6_file.txt")
os.rename("6_file1.txt","6_file.txt")