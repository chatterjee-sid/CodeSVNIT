#7. Define a function that accepts roll number and returns whether the student is present or absent.
def presenceof(roll):
    Attendance={1:'P',2:'P',3:'A',4:'P',5:'A',6:'P',7:'A',8:'A',9:'P',10:'A'}
    if(Attendance[roll]=='P'):
        return True
    else:
        return False
roll=int(input("Enter student roll number: "))
if presenceof(roll):
    print("Roll no.",roll,"was present.")
else:
    print("Roll no.",roll,"was absent.")