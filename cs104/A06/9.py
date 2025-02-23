#9. Define a function that accepts radius and returns the area of a circle.
from math import pi
def cir_area(r):
    return r*r*pi
radius=float(input("Enter radius of circle: "))
print("The area of circle of radius",radius,"units is %.2f square units." %cir_area(radius))