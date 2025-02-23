#8.03. Write a Python program to create a class Vehicle, Twowheeler and Fourwheeler. Then, derive classes Car and Scooter from it to illustrate the multiple inheritance.
class Vehicle:
    def __init__(self,brand="",capacity=0,seats=0,gear=1):
        self.brand=brand
        self.capacity=capacity
        self.seats=seats
        self.gear=gear
    def geartype(self):
        if self.gear==1:
            return f"gearless"
        else:
            return f"geared"
    def gearshow(self):
        if self.gear>1:
            return f" with {self.gear} gears"
        else:
            return ""
class TwoWheeler(Vehicle):
    wheel=2
    def __init__(self,brand="",capacity=0,seats=0,gear=1):
        super().__init__(brand,capacity,seats,gear)
class FourWheeler(Vehicle):
    wheel=4
    def __init__(self,brand="",capacity=0,seats=0,gear=1):
        super().__init__(brand,capacity,seats,gear)
class Scooter(TwoWheeler):
    fueltype="Petrol"
    def __init__(self,brand="",capacity=0,seats=0,engine=0,gear=1):
        super().__init__(brand,capacity,seats,gear)
        self.engine=engine
    def show(self):
        print(f"Scooter from {self.brand}: {self.wheel} wheels, {self.fueltype} with capacity {self.capacity} units, {self.engine}cc engine, {self.geartype()}{self.gearshow()},
    {self.seats} seats.")
class Car(FourWheeler):
    def __init__(self,brand="",capacity=0,seats=0,gear=1,fueltype=""):
        super().__init__(brand,capacity,seats,gear)
        self.fueltype=fueltype
    def show(self):
        print(f"Car from {self.brand}: {self.wheel} wheels, {self.fueltype} with capacity
        {self.capacity} units, {self.geartype()}{self.gearshow()}, {self.seats} seats.")
V1 = Car("Toyota",36,5,6,"Diesel")
V2 = Scooter("Bajaj",4,2,125)
V1.show()
V2.show()