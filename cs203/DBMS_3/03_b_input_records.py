index = open("DBMS\\DBMS_3\\03_index.txt","w")
data = open("DBMS\\DBMS_3\\03_data.txt","w")
data.write("Index"+(" "*5)+"Name"+(" "*11)+"Dept Hostel"+(' '*4)+"Room \n")
i = 0
mydata = [
    ["U23AI017","Miten","AI","ABVB","338"],
    ["U23EE030","Ankush","EE","ABVB","338"],
    ["U23ME018","Akhil","ME","ABVB","240"],
    ["U23ME019","Onkit","ME","ABVB","240"],
    ["U23AI035","Jaival","AI","ABVB","332"],
    ["U23CH004","Meet","ChE","ABVB","337"],
    ["U23EC002","Dhruv","EcE","ABVB","315"],
    ["U23CS012","Kahaan","CSE","ABVB","537"],
    ["U23EE024","Parth","EE","ABVB","203"],
    ["U23EE063","Jaitra","EE","SVB","A302"],
    ["U23EE005","Yash","EE","SVB","A504"],
    ["U23CS024","Parth","CSE","ABVB","337"],
    ["U23AI030","Vatsal","AI","ABVB","315"],
    ["U23CS028","Siddhartha","CSE","ABVB","307"],
    ["U23CS030","Sujeet","CSE","ABVB","307"],
    ["I23CY001","Dhruv","Chem","ABVB","309"],
    ["U23ME025","Kartik","ME","ABVB","306"],
    ["U23AI034","Vikram","AI","ABVB","332"],
    ["U23ME020","Harsh","ME","ABVB","306"],
    ["U23CH030","Lalit","ChE","SVB","B211"],
    ["U23EE029","Madhav","EE","--","--"]
]
index.write("Index\tLocation\n")
for i in range(len(mydata)):
    idx = mydata[i][0]
    name = mydata[i][1]
    dept = mydata[i][2]
    hostel = mydata[i][3]
    room = mydata[i][4]
    index.write(idx+'\t'+str(i+1)+'\n')
    data.write(idx+(' '*2)+name+(' '*(15-len(name)))+dept+(' '*(5-len(dept)))+hostel+(' '*(10-len(hostel)))+room+(' '*(5-len(room)))+'\n')
index.close()
data.close()
index = open("DBMS\\DBMS_3\\03_index.txt","r")
A = index.read().strip().split('\n')
A[1:]=sorted(A[1:])
index.close()
index = open("DBMS\\DBMS_3\\03_index.txt","w")
index.write('\n'.join(A))