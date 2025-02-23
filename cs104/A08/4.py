'''
8.04. Write a python program to illustrate polymorphism using this example.
1. Details: Car x1 Red 20000
Car max speed is 240
Car change 7 gear
2. Details: Truck x1 white 75000
Vehicle max speed is 150
Vehicle change 6 gear
'''
class Vehicle:
    def __init__(self,type="",num=0,colour="",price=0):
        self.type=type
        self.num=num
        self.colour=colour
        self.price=price
class Car(Vehicle):
    def __init__(self,type="",num=0,colour="",price=0):
        super().__init__(type,num,colour,price)
    maxspeed=240
    change_gear=7
class Truck(Vehicle):
    def __init__(self,type="",num=0,colour="",price=0):
        super().__init__(type,num,colour,price)
    maxspeed=150
    change_gear=6
C1 = Car("Car",1,"Red",20000)
T1 = Truck("Truck",1,"White",75000)
for i in [C1,T1]:
    print(f"Type: {i.type}")
    print(f"Num: {i.num}")
    print(f"Color: {i.colour}")
    print(f"Price: {i.price}")
    print(f"Max Speed: {i.maxspeed}")
    print(f"Gear shift: {i.change_gear}")
    print()