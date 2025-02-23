'''
8.02. Write a python program calculates the percentage of a student using multilevel
inheritance.
a. Enter Marks for 5 Subject: Maths:--, Chem:--, Phy:--, WP:--, DS:-- ,
b. Percentage of a student : —
'''
class student:
    def __init__(self,name="",year=0,rollno=""):
        self.name=name
        self.year=year
        self.rollno=rollno
class examinee(student):
    def __init__(self,name="",year=0,rollno="",Math=0,Phy=0,Chem=0,DS=0,WPP=0):
        student.__init__(self,name,year,rollno)
        self.Math=Math
        self.Phy=Phy
        self.Chem=Chem
        self.DS=DS
        self.WPP=WPP
class percentage(examinee):
    def __init__(self,name="",year=0,rollno="",Math=0,Phy=0,Chem=0,DS=0,WPP=0):
        examinee.__init__(self,name,year,rollno,Math,Phy,Chem,DS,WPP)
    def calc(self):
        sum = self.Math + self.Phy +self.Chem + self.DS + self.WPP
        return sum/5
Name = input("Student Name: ")
Year= int(input("Year: "))
Rollno = input("Roll no. ")
Math=int(input("Math score: "))
Phy=int(input("Phy score: "))
Chem=int(input("Chem score: "))
DS=int(input("DS score: "))
WPP=int(input("WPP score: "))
X = percentage(Name,Year,Rollno,Math,Phy,Chem,DS,WPP)
print(f"Score of student {X.rollno} ({X.name}) of Year {X.year} is {X.calc()}%")