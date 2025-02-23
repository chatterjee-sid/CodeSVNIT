#04. Create a dictionary and apply the following methods: 1. print dictionary, 2. access items, 3. use get, 4. change values, 5. use len()
A={'iocs':86,'iop':57,'ena':58,'epc':78,'foem':93}
while True:
    print("Menu")
    print("\t1. print")
    print("\t2. access")
    print("\t3. get")
    print("\t4. change value")
    print("\t5. Length")
    print("\t0. Exit")
    choice=int(input("Enter choice no. "))
    if choice==1:
        print(A)
    elif choice==2:
        print(A.items())
    elif choice==3:
        key=input("Enter key: ")
        print(A.get(key))
    elif choice==4:
        key=input("Enter key: ")
        A[key]=int(input("Enter value: "))
        print("Operation Successful")
    elif choice==5:
        print("Length:",len(A))
    elif choice==0:
        break
    else:
        print("Invalid choice")
print("Thank You!")