#8.05. Write a python program to create two classes CAT and DOG . They share a similar structure and have the same method names Info() and Make_sound().
class CAT:
    def __init__(self,name,breed):
        self.name=name
        self.breed=breed
    def info(self):
        print(f"My cat's name is {self.name} and it is {'an' if self.breed[0] in "AEIOUaeiou" else 'a'} {self.breed}.")
    def make_sound(self):
        print("Meow!")
class DOG:
    def __init__(self,name,breed):
        self.name=name
        self.breed=breed
    def info(self):
        print(f"My dog's name is {self.name} and it is {'an' if self.breed[0] in "AEIOUaeiou" else 'a'} {self.breed}.")
    def make_sound(self):
        print("Bow-wow!")
C = CAT("Neko","American Shorthair")
D = DOG("Inu","Labrador Retriever")
C.info()
C.make_sound()
D.info()
D.make_sound()