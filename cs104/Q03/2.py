#2. Create a module Calculator having functions areaofcircle(), areaofsquare(),areaoftraingle()
import module_2 as Calc
r = float(input("Enter radius of circle: "))
print("Area of circle: %.3f" %Calc.areaofcircle(r))
s = float(input("Enter side of square: "))
print("Area of square: %.3f" %Calc.areaofsquare(s))
h = float(input("Enter height of triangle: "))
b = float(input("Enter base length of triangle: "))
print("Area of triangle: %.3f" %Calc.areaoftriangle(h,b))