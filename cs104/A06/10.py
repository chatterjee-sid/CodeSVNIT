#10. A movie theater charges different ticket prices depending on a person’s age. If a person is under the age of 3, the ticket is free; if they are between 3 and 12, the ticket is $10; and if they are over age 12, the ticket is $15. Write a loop in which you ask users their age, and then tell them the cost of their movie ticket
audience=int(input("Enter number of people: "))
cost=0
for i in range(audience):
    age=int(input("Enter age of person "+str(i+1)+": "))
    if age>12:
        cost+=15
    elif age>3:
        cost+=10
print("The total cost is",cost,"dollars")