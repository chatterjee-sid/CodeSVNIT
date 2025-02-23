'''
8.01. Write a python programs that illustrate how the following forms of inheritance are
supported:
a. Single inheritance
b. Multilevel inheritance
c. Hierarchical inheritance
d. Multiple inheritance
'''
#8.01a. Single inheritance
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
name = input("Enter name: ")
age = int(input("Enter age: "))
rollno = input("Enter Roll no. ")
S1 = student(name,age,rollno)
print("Using showPerson(): ")
S1.showPerson()
print("Using showStudent(): ")
S1.showStudent()