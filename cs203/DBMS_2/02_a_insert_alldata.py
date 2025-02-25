myfile = open("DBMS\\DBMS_2\\02_myfile.txt","w")
myfile.write("Roll_No   Stu_Name  Dept.     Percentage\n")
prewritten_records = [
    ['1','Bob','CSE','58'],
    ['2','Maria','AI','87'],
    ['3','Mili','CSE','75'],
    ['4','Neel','Elec','90'],
    ['5','Heli','CSE','79'],
    ['6','Jack','AI','71']
]
for i in range(len(prewritten_records)):
    rollno = prewritten_records[i][0]
    name = prewritten_records[i][1]
    dept = prewritten_records[i][2]
    percentage = prewritten_records[i][3]
    myfile.write(rollno+(' '*(10-len(rollno)))+name+(' '*(10-len(name)))+dept+(' '*(10-len(dept)))+percentage+'%'+(' '*(9-len(percentage)))+'\n')
myfile.close()