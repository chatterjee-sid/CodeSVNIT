'''
8.01. Write a python programs that illustrate how the following forms of inheritance are
supported:
a. Single inheritance
b. Multilevel inheritance
c. Hierarchical inheritance
d. Multiple inheritance
'''
#8.01b. Multilevel inheritance
class person:
    def __init__(self,name="",age=0):
        self.name=name
        self.age=age
    def showPerson(self):
        print(f"{self.name} is {self.age} years old.")
class student(person):
    def __init__(self,name="",age=0,rollno=""):
        person.__init__(self,name,age)
        self.rollno=rollno
    def showStudent(self):
        print(f"{self.name}'s studentID is {self.rollno} and they are {self.age} years old.")
class year1(student):
    def __init__(self,name="",age=0,rollno="",absence=0):
        student.__init__(self,name,age,rollno)
        self.absence=absence
    def showYear1(self):
        print(f"{self.name} is a fresher with studentID {self.rollno} and they are {self.age} years old. They have taken {self.absence} absences from classes till now.")
name = input("Enter name: ")
age = int(input("Enter age: "))
rollno = input("Enter Roll no. ")
absence = int(input("Enter number of absences: "))
S1 = year1(name,age,rollno,absence)
print("Using showPerson(): ")
S1.showPerson()
print("Using showStudent(): ")
S1.showStudent()
print("Using showYear1(): ")
S1.showYear1()