#2. Write a python program to check whether the given color is part of RAINBOW
'''
Input : Green
Output : YES
Input: White
Output : NO
'''
Rainbow = ["violet","indigo","blue","green","yellow","orange","red"]
Colour = input("Enter colour: ")
if Colour.lower() in Rainbow:
    print("YES")
else:
    print("NO")