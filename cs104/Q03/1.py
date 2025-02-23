#1. Create a base class called Person with attributes name and age. Derive a class Employee from Person with an additional attribute employee_id. Implement a method display_info() in both classes to display the information of a person and an employee
class Person:
    def __init__(self,name="",age=0):
        self.name = name
        self.age = age
    def display_info(self):
        print(f"Name: {self.name}, Age: {self.age}")
class Employee(Person):
    def __init__(self,name="",age=0,employee_id=""):
        super().__init__(name,age)
        self.employee_id = employee_id
    def display_info(self):
        print(f"Name: {self.name}, Age: {self.age}, Employee ID: {self.employee_id}")
P = Person("Ace",18)
E = Employee("Roger",40,"18BCS014")
P.display_info()
E.display_info()