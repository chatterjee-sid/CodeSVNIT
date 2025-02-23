#7.03. Write a Python program to count the number of lines in a given CSV file.
import csv
f1=open("2_file.csv","r")
creader=csv.reader(f1)
cnt=0
for row in creader:
    cnt+=1
f1.close()
print("No. of lines:",cnt)