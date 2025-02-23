#7.05. Create a module badic_maths having following functions:
# (i) round(): To give precision upto 3 position
# (ii) floor()
# (iii) ceil()
# (iv) hello(user): To greet user
# Import this function in Python file and calculate area of circle.
import math_7 as one
name = input("Your name please? ")
one.hello(name)
N = float(input("Enter a float value: "))
print("round(N) =",one.round(N))
print("floor(N) =",one.floor(N))
print("ceil(N) =",one.ceil(N))
r = float(input("Enter circle radius: "))
area = 3.14 * r * r
print("Area:",one.round(area))