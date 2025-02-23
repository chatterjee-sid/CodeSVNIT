'''
8.01. Write a python programs that illustrate how the following forms of inheritance are
supported:
a. Single inheritance
b. Multilevel inheritance
c. Hierarchical inheritance
d. Multiple inheritance
'''
#8.01d Multiple inheritance
class AquaticAnimal:
    def __init__(self, name):
        self.name = name
    def swim(self):
        print(f"{self.name} is swimming.")
    def breathe_underwater(self):
        print(f"{self.name} is breathing underwater.")
class LandAnimal:
    def __init__(self, name):
        self.name = name
    def walk(self):
        print(f"{self.name} is walking.")
    def breathe_air(self):
        print(f"{self.name} is breathing air.")
class Amphibian(AquaticAnimal, LandAnimal):
    def __init__(self, name):
        AquaticAnimal.__init__(self, name)
        LandAnimal.__init__(self, name)
    def environment(self, environment):
        if environment == "land":
            print(f"{self.name} is now on land.")
            self.walk()
            self.breathe_air()
        elif environment == "water":
            print(f"{self.name} is now in water.")
            self.swim()
            self.breathe_underwater()
        else:
            print("Unknown environment. Amphibians can live on land or in water.")

fish = AquaticAnimal("Goldfish")
fish.swim()
fish.breathe_underwater()
dog = LandAnimal("Dog")
dog.walk()
dog.breathe_air()
frog = Amphibian("Frog")
frog.environment("land")
frog.environment("water")