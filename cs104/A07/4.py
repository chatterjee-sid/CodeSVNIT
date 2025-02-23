#7.04. Write a Python program to write dictionaries and a list of dictionaries to a given CSV file.
import csv
f1 = open("4_file.csv","w",newline="")
fields = ["R.no","Name","Club","Score"]
stud = [
    {"R.no":"U01","Name":"Luffy","Club":"OP","Score":35},
    {"R.no":"U02","Name":"Light","Club":"DN","Score":70},
    {"R.no":"U03","Name":"Jotaro","Club":"JBA","Score":55},
    {"R.no":"U04","Name":"Tanjiro","Club":"KY","Score":50},
    {"R.no":"U05","Name":"Yuji","Club":"JJK","Score":45},
    {"R.no":"U06","Name":"Kiyotaka","Club":"CrE","Score":65}
]
cwriter=csv.DictWriter(f1,fieldnames=fields)
cwriter.writeheader()
cwriter.writerows(stud)
f1.close()
print("Done")