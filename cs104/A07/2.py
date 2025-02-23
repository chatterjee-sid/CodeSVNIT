#7.02. Write a Python program to read and display the content of a CSV file having student details.
import csv
f1=open("2_file.csv","r")
creader=csv.reader(f1)
print("%-5s"%"R.no.","%-10s"%"Name","%-6s"%"Club","Score")
for row in creader:
    print("%-5s"%row[0],"%-10s"%row[1],"%-6s"%row[2],row[3])
f1.close()