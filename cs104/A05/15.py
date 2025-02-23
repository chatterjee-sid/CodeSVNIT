#15. Write a Python program to get the top three items in a shop.
D={'item1':45.50,'item2':35,'item3':41.30,'item4':55,'item5':24}
L=[]
for i in D:
    L.append((D[i],i))
L.sort(reverse=True)
for i in range(3):
    print(L[i][1],L[i][0])