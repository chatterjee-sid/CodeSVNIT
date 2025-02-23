# 04. Write a Python program to create a tuple.
# a. To create a tuple of numbers and print one item.
# b. To create a tuple with different data types.
# c. Write a Python program to add an item to a tuple.
from random import randrange
Tuple1=(1,2,3,4,5,6)
print("Part a")
print(Tuple1)
print(Tuple1[randrange(len(Tuple1))])
print("Part b")
Tuple2=(1,3.14,"Hello")
print(Tuple2)
print("Part c")
List=list(Tuple1)
item=int(input("Enter new element to add: "))
List.append(item)
Tuple1=tuple(List)
print(Tuple1)