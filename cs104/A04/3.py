#03. Create a list & perform the following: 1. insert(), 2. remove(), 3. append(), 4. len(), 5. pop(), 6. clear()
A=[3,8,7,1,6,4]
while True:
    print(A)
    print("Menu")
    print("\t1. Insert")
    print("\t2. Remove")
    print("\t3. Append")
    print("\t4. Length")
    print("\t5. Pop")
    print("\t6. Clear")
    print("\t0. Exit")
    choice=int(input("Enter choice no. "))
    if choice==1:
        ele=int(input("Enter element to insert: "))
        pos=int(input("Enter index of insertion: "))
        if pos<=len(A) or pos>=-len(A):
            A.insert(pos,ele)
            print("Operation Successful")
        else:
            print("Index out of bound")
    elif choice==2:
        ele=int(input("Enter element to remove: "))
        if ele in A:
            A.remove(ele)
            print("Operation Successful")
        else:
            print("Element does not exist")
    elif choice==3:
        ele=int(input("Enter element to append: "))
        A.append(ele)
        print("Operation Successful")
    elif choice==4:
        print("Length:",len(A))
    elif choice==5:
        pos=int(input("Enter index of removal: "))
        if pos<len(A) or pos>=-len(A):
            A.pop(pos)
            print("Operation Successful")
        else:
            print("Index out of bound")
    elif choice==6:
        A.clear()
        print("Operation Successful")
    elif choice==0:
        break
    else:
        print("Invalid choice")
print("Thank You!")