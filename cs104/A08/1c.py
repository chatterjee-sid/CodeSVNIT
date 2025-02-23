'''
8.01. Write a python programs that illustrate how the following forms of inheritance are
supported:
a. Single inheritance
b. Multilevel inheritance
c. Hierarchical inheritance
d. Multiple inheritance
'''
#8.01c. Heirarchial inheritance
class person:
    def __init__(self,name="",age=0):
        self.name=name
        self.age=age
    def showPerson(self):
        print(f"The name of the person is {self.name} and they are {self.age} years old.")
class student(person):
    def __init__(self,name="",age=0,rollno=""):
        person.__init__(self,name,age)
        self.rollno=rollno
    def showStudent(self):
        print(f"The name of student {self.rollno} is {self.name} and they are {self.age} years old.")
class teacher(person):
    def __init__(self,name="",age="",teachid=""):
        person.__init__(self,name,age)
        self.teachid=teachid
    def showTeacher(self):
        print(f"The name of teacher {self.teachid} is {self.name} and they are {self.age} years old.")
Sname = input("Enter student name: ")
Sage = int(input("Enter student age: "))
rollno = input("Enter Roll no. ")
S1 = student(Sname,Sage,rollno)
Tname = input("Enter teacher name: ")
Tage = int(input("Enter teacher age: "))
teachid = input("Enter Teacher ID: ")
T1 = teacher(Tname,Tage,teachid)
print("Using showPerson(): ")
S1.showPerson()
T1.showPerson()
print("Using showStudent(): ")
S1.showStudent()
print("Using showTeacher(): ")
T1.showTeacher()